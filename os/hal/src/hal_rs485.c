
/**
 * @file    hal_rs485.c
 * @brief   RS485 RS485 Driver code.
 *
 * @addtogroup RS485
 * @{
 */

#include "hal.h"

#if (HAL_USE_RS485 == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void  rs485InvalidateReceiving(RS485Driver *rs485p, eventflags_t flag) {
  //osalSysLockFromISR();
  osalEventBroadcastFlagsI(&rs485p->event, flag);
  //osalSysUnlockFromISR();
  rs485_lld_SetTRCReady(rs485p);
};

/**
 * @brief   RS485 Receiver timeout callback
 * @note    This callback reset state if receiving does not continue.
 *
 *
 */
static void rs485ReceiveTimeutCB(void *p) {
  osalSysLockFromISR();
  rs485InvalidateReceiving((RS485Driver *)p, RS485_RECEIVING_NOT_CONTINUE);
  osalSysUnlockFromISR();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   RS485 Driver initialization.
 * @note    This function is implicitly invoked by @p halInit(), there is
 *          no need to explicitly initialize the driver.
 *
 * @init
 */
void rs485Init(void) {

  rs485_lld_init();
}

/**
 * @brief   Initializes a generic full duplex driver object.
 * @details The HW dependent part of the initialization has to be performed
 *          outside, usually in the hardware initialization code.
 *
 * @param[out] rs485p      pointer to a @p RS485Driver structure
 * @init
 */
void rs485ObjectInit(RS485Driver *rs485p) {

  //rs485p->vmt = &vmt;
  osalEventObjectInit(&rs485p->event);
  rs485p->state = RS485_STOP;
  rs485p->trcState = TRC_STOP;
  chVTObjectInit(&rs485p->receiveVT);
  chBSemObjectInit(&rs485p->received, true);
}

/**
 * @brief   Configures and starts the driver.
 *
 * @param[in] rs485p       pointer to a @p RS485Driver object
 * @param[in] config    the architecture-dependent RS485 driver configuration.
 *                      If this parameter is set to @p NULL then a default
 *                      configuration is used.
 *
 * @api
 */
void rs485Start(RS485Driver *rs485p, const RS485Config *config) {

  osalDbgCheck(rs485p != NULL);

  osalSysLock();
  osalDbgAssert((rs485p->state == RS485_STOP) || (rs485p->state == RS485_READY),
                "not initialized");
  rs485_lld_start(rs485p, config);
  rs485p->state = RS485_READY;
  rs485p->trcState = TRC_READY;
  rs485p->oneByteTimeUS = 20000000/rs485p->config->speed;  // 11 bits to send one byte + 9 to give it more time (1Sec/(speed/20bits))
  rs485p->oneByteTimeI = OSAL_US2I(rs485p->oneByteTimeUS); // In system ticks
  if (rs485p->oneByteTimeI < 1) rs485p->oneByteTimeI = 1;  // Make sure it's at least 1 tick
  palClearPad(rs485p->config->deport, rs485p->config->depad);  // Release DE
  osalSysUnlock();
}

/**
 * @brief   Stops the driver.
 * @details Any thread waiting on the driver's queues will be awakened with
 *          the message @p MSG_RESET.
 *
 * @param[in] rs485p       pointer to a @p RS485Driver object
 *
 * @api
 */
void rs485Stop(RS485Driver *rs485p) {

  osalDbgCheck(rs485p != NULL);

  osalSysLock();

  osalDbgAssert((rs485p->state == RS485_STOP) || (rs485p->state == RS485_READY),
                "invalid state");

  rs485_lld_stop(rs485p);
  rs485p->state = RS485_STOP;
  rs485p->trcState = TRC_STOP;
  osalOsRescheduleS();

  osalSysUnlock();
}

/**
 * @brief   Handles incoming data.
 * @details This function must be called from the input interrupt service
 *          routine in order to enqueue incoming data and generate the
 *          related events.
 * @note    The incoming data event is only generated when the input queue
 *          becomes non-empty.
 * @note    In order to gain some performance it is suggested to not use
 *          this function directly but copy this code directly into the
 *          interrupt service routine.
 *
 * @param[in] rs485p       pointer to a @p RS485Driver structure
 * @param[in] b         the byte to be written in the driver's Input Queue
 *
 * @iclass
 */
void rs485IncomingDataI(RS485Driver *rs485p, uint8_t b) {

  osalDbgCheckClassI();
  osalDbgCheck(rs485p != NULL);

  if ((rs485p->trcState == TRC_READY) ||
      (rs485p->trcState == TRC_RECEIVING) ||
      (rs485p->trcState == TRC_WAITING_ACK)) {
    rs485p->ib[rs485p->ibHead] = b;
    rs485p->ibHead++;
  }

  if (rs485p->ibHead == 1) {
    // For new msg change state
    if (rs485p->trcState == TRC_READY) rs485p->trcState = TRC_RECEIVING;
  }

  if (rs485p->ibHead == 2) {
    rs485p->ibExpLen = RS485_HEADER_SIZE; // CMD size
    // If data add length. Data ACK length is 0, but has CRC
    if (((b >> 6 ) & 0b1) == RS485_FLAG_DTA) {
      rs485p->ibExpLen += (b & 0b111111) + RS485_CRC_SIZE;
    }
  }

  // Check header XOR
  if ((rs485p->ibHead == 3) && (b != (rs485p->ib[0] ^ rs485p->ib[1]))) {
    rs485InvalidateReceiving(rs485p, RS485_MSG_XOR_ERROR);
    //osalEventBroadcastFlagsI(&rs485p->event, RS485_MSG_XOR_ERROR);
    return;
  }

  // We have whole msg
  if (rs485p->ibHead == rs485p->ibExpLen) {
    chVTResetI(&rs485p->receiveVT);  // Disable receiving timeout VT
    // New msg
    if (rs485p->trcState == TRC_RECEIVING) {
      // ACK requested, and message is not ACK itself (ACK length = 0)
      if ((((rs485p->ib[1] >> 7 ) & 0b1) == RS485_FLAG_ACK) &&
          ((rs485p->ib[1] & 0b111111) != 0)) {
        // Prepare ACK msg to send
        rs485p->trcState = TRC_ACKING;
        // Set DE
        palSetPad(rs485p->config->deport, rs485p->config->depad);
        // Reset Transmission Complete
        rs485p->usart->SR= ~USART_SR_TC;

        rs485p->obHead = 0;
        rs485p->obTail = RS485_HEADER_SIZE;
        if (((rs485p->ib[1] >> 6 ) & 0b1) == RS485_FLAG_DTA) {
          rs485p->obTail += RS485_CRC_SIZE; // Add CRC size
        }

        // Create header
        rs485p->ob[0] = (rs485p->config->address << 4) | (((rs485p->ib[0] >> 4)) & 0b1111);
        if (((rs485p->ib[1] >> 6 ) & 0b1) == RS485_FLAG_DTA) {
          rs485p->ob[1] = 0b10000000; // RS485_FLAG_ACK + RS485_FLAG_DTA + length(0)
        } else {
          rs485p->ob[1] = 0b11000000; // RS485_FLAG_ACK + RS485_FLAG_CMD + length(0)
        }
        rs485p->ob[2] = rs485p->ob[0] ^ rs485p->ob[1];  // Create XOR
        if (((rs485p->ib[1] >> 6 ) & 0b1) == RS485_FLAG_DTA) {
          rs485p->ob[3] = rs485p->ib[rs485p->ibExpLen-2]; // Copy CRC
          rs485p->ob[4] = rs485p->ib[rs485p->ibExpLen-1]; // Copy CRC
        }

        // Enable TX
        RS485D2.usart->CR1|= USART_CR1_TXEIE;
      } else { // ACK not requested
        rs485p->trcState = TRC_RECEIVED;
        osalEventBroadcastFlagsI(&rs485p->event, RS485_MSG_RECEIVED);
        chBSemSignalI(&rs485p->received);
      }
    }
    // ACK reply
    if (rs485p->trcState == TRC_WAITING_ACK) {
      // Sent to / Received from address mismatch
      if (((rs485p->ib[0] >> 4) & 0b1111) != (rs485p->ob[0] & 0b1111)) {
        rs485InvalidateReceiving(rs485p, RS485_ACK_ERROR);
        return;
      }
      // Data or CMD
      if (((rs485p->ob[1] >> 6 ) & 0b1) == RS485_FLAG_DTA) {
        // Compare CRC
        if ((rs485p->ob[rs485p->obTail-2]) != (rs485p->ib[rs485p->ibHead-2]) ||
            (rs485p->ob[rs485p->obTail-1]) != (rs485p->ib[rs485p->ibHead-1])) {
          rs485InvalidateReceiving(rs485p, RS485_ACK_ERROR_CRC);
          return;
        }
      } else {
        // CMD mismatch, CMD ACK is RS485_FLAG_ACK + RS485_FLAG_CMD + length(0)
        if (rs485p->ib[1] != 0b11000000) {
          rs485InvalidateReceiving(rs485p, RS485_ACK_ERROR_CMD);
          return;
        }
      }
      // All OK
      rs485p->trcState = TRC_ACKED;
    }
  } else { // else - We have whole msg
    // Enable receiving timeout VT
    chVTSetI(&rs485p->receiveVT, rs485p->oneByteTimeI, rs485ReceiveTimeutCB, rs485p);
  }
}

/**
 * @brief   Configures and starts the driver.
 *
 * @param[in] rs485p       pointer to a @p RS485Driver object
 * @param[in] config    the architecture-dependent RS485 driver configuration.
 *                      If this parameter is set to @p NULL then a default
 *                      configuration is used.
 *
 * @api
 */
msg_t rs485SendMsg(RS485Driver *rs485p, RS485Msg_t *datap) {

  osalDbgCheck(rs485p != NULL);
  osalDbgCheck(datap != NULL);
  datap->ctrl = RS485_FLAG_DTA; // Only Data are allowed

  return rs485_lld_SendMsgWithACK(rs485p, datap, 1, RS485_FLAG_NACK);
}

msg_t rs485SendCmd(RS485Driver *rs485p, RS485Cmd_t *datap) {

  osalDbgCheck(rs485p != NULL);
  osalDbgCheck(datap != NULL);
  datap->ctrl = RS485_FLAG_CMD; // Only CMD is allowed

  return rs485_lld_SendMsgWithACK(rs485p, (RS485Msg_t*) datap, 1, RS485_FLAG_ACK);
}

msg_t rs485SendMsgWithACK(RS485Driver *rs485p, RS485Msg_t *datap, uint8_t repeat) {

  osalDbgCheck(rs485p != NULL);
  osalDbgCheck(datap != NULL);
  datap->ctrl = RS485_FLAG_DTA; // Only Data are allowed

  return rs485_lld_SendMsgWithACK(rs485p, datap, repeat, RS485_FLAG_ACK);
}

msg_t rs485SendCmdWithACK(RS485Driver *rs485p, RS485Cmd_t *datap, uint8_t repeat) {

  osalDbgCheck(rs485p != NULL);
  osalDbgCheck(datap != NULL);
  datap->ctrl = RS485_FLAG_CMD; // Only CMD is allowed

  return rs485_lld_SendMsgWithACK(rs485p, (RS485Msg_t*) datap, repeat, RS485_FLAG_ACK);
}

/**
 * @brief   Configures and starts the driver.
 *
 * @param[in] rs485p       pointer to a @p RS485Driver object
 * @param[in] config    the architecture-dependent RS485 driver configuration.
 *                      If this parameter is set to @p NULL then a default
 *                      configuration is used.
 *
 * @api
 */
msg_t rs485GetMsg(RS485Driver *rs485p, RS485Msg_t *datap) {

  osalDbgCheck(rs485p != NULL);
  osalDbgCheck(datap != NULL);

  return rs485_lld_GetMsg(rs485p, datap);
}


#endif /* HAL_USE_RS485 == TRUE */

/** @} */
