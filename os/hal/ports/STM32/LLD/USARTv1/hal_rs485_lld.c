/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    USARTv1/hal_serial_lld.c
 * @brief   STM32 low level serial driver code.
 *
 * @addtogroup SERIAL
 * @{
 */

#include <string.h>
#include "hal.h"

#if HAL_USE_RS485 || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief USART1 serial driver identifier.*/
#if STM32_RS485_USE_USART1 || defined(__DOXYGEN__)
RS485Driver RS485D1;
#endif

/** @brief USART2 serial driver identifier.*/
#if STM32_RS485_USE_USART2 || defined(__DOXYGEN__)
RS485Driver RS485D2;
#endif

/** @brief USART3 serial driver identifier.*/
#if STM32_RS485_USE_USART3 || defined(__DOXYGEN__)
RS485Driver RS485D3;
#endif

/** @brief UART4 serial driver identifier.*/
#if STM32_RS485_USE_UART4 || defined(__DOXYGEN__)
RS485Driver RS485D4;
#endif

/** @brief UART5 serial driver identifier.*/
#if STM32_RS485_USE_UART5 || defined(__DOXYGEN__)
RS485Driver RS485D5;
#endif

/** @brief USART6 serial driver identifier.*/
#if STM32_RS485_USE_USART6 || defined(__DOXYGEN__)
RS485Driver RS485D6;
#endif

/** @brief UART7 serial driver identifier.*/
#if STM32_RS485_USE_UART7 || defined(__DOXYGEN__)
RS485Driver RS485D7;
#endif

/** @brief UART8 serial driver identifier.*/
#if STM32_RS485_USE_UART8 || defined(__DOXYGEN__)
RS485Driver RS485D8;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

static const uint16_t ccitt_crc16_table[256] = {
   0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7, 0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
   0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6, 0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
   0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485, 0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
   0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4, 0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
   0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823, 0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
   0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12, 0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
   0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41, 0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
   0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70, 0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
   0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F, 0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
   0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E, 0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
   0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D, 0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
   0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C, 0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
   0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB, 0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
   0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A, 0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
   0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9, 0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
   0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8, 0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};


/** @brief Driver default configuration.*/
static const RS485Config default_config =
{
  RS485_DEFAULT_BITRATE,
  0,  // address
  0,  // port
  0   // pad
};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   USART initialization.
 * @details This function must be invoked with interrupts disabled.
 *
 * @param[in] rs485p       pointer to a @p RS485Driver object
 * @param[in] config    the architecture-dependent serial driver configuration
 */
static void usart_init(RS485Driver *rs485p, const RS485Config *config) {
  USART_TypeDef *u = rs485p->usart;

  /* Baud rate setting.*/
#if STM32_HAS_USART6
  if ((rs485p->usart == USART1) || (rs485p->usart == USART6))
#else
  if (rs485p->usart == USART1)
#endif
    u->BRR = STM32_PCLK2 / config->speed;
  else
    u->BRR = STM32_PCLK1 / config->speed;

  /* Note that some bits are enforced.*/
  u->CR1 = ( USART_CR1_UE | USART_CR1_PEIE | USART_CR1_RWU |
             USART_CR1_RXNEIE | USART_CR1_TE |
             USART_CR1_M | USART_CR1_WAKE |
             USART_CR1_RE) & ~USART_CR1_TCIE;
  // * Adam added: USART_CR1_M | USART_CR1_WAKE |
  // * Adam removed: u->CR2 = config->cr2 | USART_CR2_LBDIE;
  u->CR2 = config->address & USART_CR2_ADD; // Address at ADD[0:3] masked by 0b1111
  u->CR3 = USART_CR3_EIE;

  u->SR = 0;
  (void)u->SR;  /* SR reset step 1.*/
  (void)u->DR;  /* SR reset step 2.*/

}

/**
 * @brief   USART de-initialization.
 * @details This function must be invoked with interrupts disabled.
 *
 * @param[in] u         pointer to an USART I/O block
 */
static void usart_deinit(USART_TypeDef *u) {

  u->CR1 = 0;
  u->CR2 = 0;
  u->CR3 = 0;
}

/**
 * @brief   Error handling routine.
 *
 * @param[in] rs485p       pointer to a @p RS485Driver object
 * @param[in] sr        USART SR register value
 */
static void set_error(RS485Driver *rs485p, uint16_t sr) {
  eventflags_t sts = 0;

  if (sr & USART_SR_ORE)
    sts |= SD_OVERRUN_ERROR;
  if (sr & USART_SR_PE)
    sts |= SD_PARITY_ERROR;
  if (sr & USART_SR_FE)
    sts |= SD_FRAMING_ERROR;
  if (sr & USART_SR_NE)
    sts |= SD_NOISE_ERROR;
  //chnAddFlagsI(rs485p, sts);
  osalEventBroadcastFlagsI(&rs485p->event, sts);
}

/**
 * @brief   Common IRQ handler.
 *
 * @param[in] rs485p       communication channel associated to the USART
 */
static void serve_interrupt(RS485Driver *rs485p) {
  USART_TypeDef *u = rs485p->usart;
  uint16_t cr1 = u->CR1;
  uint16_t sr = u->SR;

  /* Special case, LIN break detection.*/
  if (sr & USART_SR_LBD) {
    osalSysLockFromISR();
    //chnAddFlagsI(rs485p, SD_BREAK_DETECTED);
    // * Not interested in LIN BREAKS * osalEventBroadcastFlagsI(&rs485p->event, SD_BREAK_DETECTED);
    u->SR = ~USART_SR_LBD;
    osalSysUnlockFromISR();
  }

  /* Data available.*/
  osalSysLockFromISR();
  while (sr & (USART_SR_RXNE | USART_SR_ORE | USART_SR_NE | USART_SR_FE |
               USART_SR_PE)) {
    uint8_t b;

    /* Error condition detection.*/
    if (sr & (USART_SR_ORE | USART_SR_NE | USART_SR_FE  | USART_SR_PE)) set_error(rs485p, sr);

    b = (uint8_t)u->DR & 0xFF; // RX Mask
    if (sr & USART_SR_RXNE) {
      rs485IncomingDataI(rs485p, b);
      sr = u->SR;
    }
  }
  osalSysUnlockFromISR();


  /* Transmission buffer empty.*/
  if ((cr1 & USART_CR1_TXEIE) && (sr & USART_SR_TXE)) {
    osalSysLockFromISR();
    if (rs485p->obTail == rs485p->obHead) {
      // * not needed  chnAddFlagsI(rs485p, CHN_OUTPUT_EMPTY);
      u->CR1 = (cr1 & ~USART_CR1_TXEIE) | USART_CR1_TCIE;
    }
    else {
      // Mark address byte
      if (rs485p->obHead == 0) u->DR = (0b1 << 8) | rs485p->ob[rs485p->obHead++];
      else                     u->DR = (0b0 << 8) | rs485p->ob[rs485p->obHead++];
    }
    osalSysUnlockFromISR();
  }

  /* Physical transmission end.*/
  if (sr & USART_SR_TC) {
    u->CR1 = cr1 & ~USART_CR1_TCIE;
    u->SR = ~USART_SR_TC;

    osalSysLockFromISR();
    // State change
    if (rs485p->trcState == TRC_SENDING) rs485p->trcState = TRC_READY;
    if (rs485p->trcState == TRC_SENDING_WITH_ACK) rs485p->trcState = TRC_WAITING_ACK;
    if (rs485p->trcState == TRC_ACKING) {
      rs485p->trcState = TRC_RECEIVED;
      //chnAddFlagsI(rs485p, RS485_MSG_RECEIVED);
      osalEventBroadcastFlagsI(&rs485p->event, RS485_MSG_RECEIVED);
    }
    osalSysUnlockFromISR();

    palClearPad(rs485p->config->deport, rs485p->config->depad);  // Release DE

    // * not needed osalSysLockFromISR();
    // * not needed if (oqIsEmptyI(&rs485p->oqueue))
    // * not needed  chnAddFlagsI(rs485p, CHN_TRANSMISSION_END);
    // * not needed osalSysUnlockFromISR();
  }
}

/*
 * CRC16 CCITT AVR compatible version with lookup table
 */
static uint16_t crc16(const uint8_t *data, uint8_t n) {
  uint16_t crc = 0xFFFF;
  while (n > 0) {
    crc = ccitt_crc16_table[(crc >> 8 ^ (uint8_t)*data) & 0xffU] ^ (crc << 8);
    data++;
    n--;
  }
  return crc;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if STM32_RS485_USE_USART1 || defined(__DOXYGEN__)
#if !defined(STM32_USART1_HANDLER)
#error "STM32_USART1_HANDLER not defined"
#endif
/**
 * @brief   USART1 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(STM32_USART1_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_interrupt(&RS485D1);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if STM32_RS485_USE_USART2 || defined(__DOXYGEN__)
#if !defined(STM32_USART2_HANDLER)
#error "STM32_USART2_HANDLER not defined"
#endif
/**
 * @brief   USART2 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(STM32_USART2_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_interrupt(&RS485D2);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if STM32_RS485_USE_USART3 || defined(__DOXYGEN__)
#if !defined(STM32_USART3_HANDLER)
#error "STM32_USART3_HANDLER not defined"
#endif
/**
 * @brief   USART3 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(STM32_USART3_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_interrupt(&RS485D3);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if STM32_RS485_USE_UART4 || defined(__DOXYGEN__)
#if !defined(STM32_UART4_HANDLER)
#error "STM32_UART4_HANDLER not defined"
#endif
/**
 * @brief   UART4 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(STM32_UART4_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_interrupt(&RS485D4);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if STM32_RS485_USE_UART5 || defined(__DOXYGEN__)
#if !defined(STM32_UART5_HANDLER)
#error "STM32_UART5_HANDLER not defined"
#endif
/**
 * @brief   UART5 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(STM32_UART5_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_interrupt(&RS485D5);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if STM32_RS485_USE_USART6 || defined(__DOXYGEN__)
#if !defined(STM32_USART6_HANDLER)
#error "STM32_USART6_HANDLER not defined"
#endif
/**
 * @brief   USART6 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(STM32_USART6_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_interrupt(&RS485D6);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if STM32_RS485_USE_UART7 || defined(__DOXYGEN__)
#if !defined(STM32_UART7_HANDLER)
#error "STM32_UART7_HANDLER not defined"
#endif
/**
 * @brief   UART7 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(STM32_UART7_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_interrupt(&RS485D7);

  OSAL_IRQ_EPILOGUE();
}
#endif

#if STM32_RS485_USE_UART8 || defined(__DOXYGEN__)
#if !defined(STM32_UART8_HANDLER)
#error "STM32_UART8_HANDLER not defined"
#endif
/**
 * @brief   UART8 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(STM32_UART8_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  serve_interrupt(&RS485D8);

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level serial driver initialization.
 *
 * @notapi
 */
void rs485_lld_init(void) {

#if STM32_RS485_USE_USART1
  rs485ObjectInit(&RS485D1);
  RS485D1.usart = USART1;
#endif

#if STM32_RS485_USE_USART2
  rs485ObjectInit(&RS485D2);
  RS485D2.usart = USART2;
#endif

#if STM32_RS485_USE_USART3
  rs485ObjectInit(&RS485D3);
  RS485D3.usart = USART3;
#endif

#if STM32_RS485_USE_UART4
  rs485ObjectInit(&RS485D4);
  RS485D4.usart = UART4;
#endif

#if STM32_RS485_USE_UART5
  rs485ObjectInit(&RS485D5);
  RS485D5.usart = UART5;
#endif

#if STM32_RS485_USE_USART6
  rs485ObjectInit(&RS485D6);
  RS485D6.usart = USART6;
#endif

#if STM32_RS485_USE_UART7
  rs485ObjectInit(&RS485D7);
  RS485D7.usart = UART7;
#endif

#if STM32_RS485_USE_UART8
  rs485ObjectInit(&RS485D8);
  RS485D8.usart = UART8;
#endif
}


/**
 * @brief   Low level serial driver .
 * @details De-initializes the USART, stops the associated clock, resets the
 *          interrupt vector.
 *
 * @param[in] rs485p       pointer to a @p RS485Driver object
 *
 */
void rs485_lld_SetTRCReady(RS485Driver *rs485p){
  rs485p->ibExpLen = 0;
  rs485p->ibHead = 0;
  rs485p->trcState = TRC_READY;
  rs485p->usart->CR1 |= USART_CR1_WAKE;
  rs485p->usart->CR1 |= USART_CR1_RWU; // Set receiver to mute mode
}

/**
 * @brief   Low level serial driver configuration and (re)start.
 *
 * @param[in] rs485p       pointer to a @p RS485Driver object
 * @param[in] config    the architecture-dependent serial driver configuration.
 *                      If this parameter is set to @p NULL then a default
 *                      configuration is used.
 *
 * @notapi
 */
void rs485_lld_start(RS485Driver *rs485p, const RS485Config *config) {

  if (config == NULL)
    config = &default_config;

  rs485p->config = config;

  if (rs485p->state == RS485_STOP) {
#if STM32_RS485_USE_USART1
    if (&RS485D1 == rs485p) {
      rccEnableUSART1(FALSE);
      nvicEnableVector(STM32_USART1_NUMBER, STM32_RS485_USART1_PRIORITY);
    }
#endif
#if STM32_RS485_USE_USART2
    if (&RS485D2 == rs485p) {
      rccEnableUSART2(FALSE);
      nvicEnableVector(STM32_USART2_NUMBER, STM32_RS485_USART2_PRIORITY);
    }
#endif
#if STM32_RS485_USE_USART3
    if (&RS485D3 == rs485p) {
      rccEnableUSART3(FALSE);
      nvicEnableVector(STM32_USART3_NUMBER, STM32_RS485_USART3_PRIORITY);
    }
#endif
#if STM32_RS485_USE_UART4
    if (&RS485D4 == rs485p) {
      rccEnableUART4(FALSE);
      nvicEnableVector(STM32_UART4_NUMBER, STM32_RS485_UART4_PRIORITY);
    }
#endif
#if STM32_RS485_USE_UART5
    if (&RS485D5 == rs485p) {
      rccEnableUART5(FALSE);
      nvicEnableVector(STM32_UART5_NUMBER, STM32_RS485_UART5_PRIORITY);
    }
#endif
#if STM32_RS485_USE_USART6
    if (&RS485D6 == rs485p) {
      rccEnableUSART6(FALSE);
      nvicEnableVector(STM32_USART6_NUMBER, STM32_RS485_USART6_PRIORITY);
    }
#endif
#if STM32_RS485_USE_UART7
    if (&RS485D7 == rs485p) {
      rccEnableUART7(FALSE);
      nvicEnableVector(STM32_UART7_NUMBER, STM32_RS485_UART7_PRIORITY);
    }
#endif
#if STM32_RS485_USE_UART8
    if (&RS485D8 == rs485p) {
      rccEnableUART8(FALSE);
      nvicEnableVector(STM32_UART8_NUMBER, STM32_RS485_UART8_PRIORITY);
    }
#endif
  }
  usart_init(rs485p, config);
}

/**
 * @brief   Low level serial driver stop.
 * @details De-initializes the USART, stops the associated clock, resets the
 *          interrupt vector.
 *
 * @param[in] rs485p       pointer to a @p RS485Driver object
 *
 * @notapi
 */
void rs485_lld_stop(RS485Driver *rs485p) {

  if (rs485p->state == RS485_READY) {
    usart_deinit(rs485p->usart);
#if STM32_RS485_USE_USART1
    if (&RS485D1 == rs485p) {
      rccDisableUSART1();
      nvicDisableVector(STM32_USART1_NUMBER);
      return;
    }
#endif
#if STM32_RS485_USE_USART2
    if (&RS485D2 == rs485p) {
      rccDisableUSART2();
      nvicDisableVector(STM32_USART2_NUMBER);
      return;
    }
#endif
#if STM32_RS485_USE_USART3
    if (&RS485D3 == rs485p) {
      rccDisableUSART3();
      nvicDisableVector(STM32_USART3_NUMBER);
      return;
    }
#endif
#if STM32_RS485_USE_UART4
    if (&RS485D4 == rs485p) {
      rccDisableUART4();
      nvicDisableVector(STM32_UART4_NUMBER);
      return;
    }
#endif
#if STM32_RS485_USE_UART5
    if (&RS485D5 == rs485p) {
      rccDisableUART5();
      nvicDisableVector(STM32_UART5_NUMBER);
      return;
    }
#endif
#if STM32_RS485_USE_USART6
    if (&RS485D6 == rs485p) {
      rccDisableUSART6();
      nvicDisableVector(STM32_USART6_NUMBER);
      return;
    }
#endif
#if STM32_RS485_USE_UART7
    if (&RS485D7 == rs485p) {
      rccDisableUART7();
      nvicDisableVector(STM32_UART7_NUMBER);
      return;
    }
#endif
#if STM32_RS485_USE_UART8
    if (&RS485D8 == rs485p) {
      rccDisableUART8();
      nvicDisableVector(STM32_UART8_NUMBER);
      return;
    }
#endif
  }
}
/**
 * @brief   Low level serial driver .
 * @details De-initializes the USART, stops the associated clock, resets the
 *          interrupt vector.
 *
 * @param[in] rs485p       pointer to a @p RS485Driver object
 *
 */
msg_t rs485_lld_SendMsgWithACK(RS485Driver *rs485p, RS485Msg_t *datap, uint8_t repeat, uint8_t ackFlag){
  uint16_t crc;
  uint8_t wait = 0, count = 0;
  msg_t reply;

  // Checks for address, length, ctrl
  osalDbgCheck(datap->address < RS485_MAX_ADDRESS); // To address allowed
  osalDbgCheck(datap->length < RS485_MSG_SIZE);     // Length is allowed
  osalDbgCheck(datap->ctrl < RS485_MAX_CTRL);       // Ctrl is allowed
  osalDbgCheck(ackFlag < RS485_MAX_CTRL);           // ACK is allowed
  osalDbgCheck(!((ackFlag == RS485_FLAG_ACK) && (datap->length == 0))); // Not allowed to send ACK directly

  while (count != repeat) {
    // Wait for READY, max time is whole packet + send ACK
    while ((rs485p->trcState != TRC_READY) && (wait != RS485_PACKET_SIZE + RS485_HEADER_SIZE)) {
      chThdSleepMicroseconds(rs485p->oneByteTimeUS);
      wait++;
    }

    if (rs485p->trcState == TRC_READY) {
      // Set DE before start to block receiving
      palSetPad(rs485p->config->deport, rs485p->config->depad);
      //// Force NACK for broadcast packets and for commands
      //if ((datap->address == 15) || ( datap->ctrl == RS485_FLAG_CMD)) ackFlag = RS485_FLAG_NACK;
      // Force NACK for broadcast packets
      if (datap->address == 15) ackFlag = RS485_FLAG_NACK;
      // Set state
      if (ackFlag == RS485_FLAG_ACK) rs485p->trcState = TRC_SENDING_WITH_ACK;
      else                           rs485p->trcState = TRC_SENDING;
      // Reset Transmission Complete
      rs485p->usart->SR= ~USART_SR_TC;
      // Force flag
      datap->ack = ackFlag;

      // Copy header to buffer
      rs485p->ob[0] = (rs485p->config->address << 4) | ((datap->address) & 0b1111);
      rs485p->ob[1] = (datap->ack << 7) | (datap->ctrl << 6) | ((datap->length) & 0b111111);
      rs485p->ob[2] = rs485p->ob[0] ^ rs485p->ob[1];

      // Set head start and output tail size
      rs485p->obHead = 0;
      rs485p->obTail = RS485_HEADER_SIZE;

      // Copy data to buffer
      if (datap->ctrl == RS485_FLAG_DTA) {
        memcpy(&rs485p->ob[RS485_HEADER_SIZE], &datap->data[0], datap->length);
        crc = crc16(datap->data, datap->length);
        rs485p->ob[RS485_HEADER_SIZE + datap->length] = (crc >> 8);
        rs485p->ob[RS485_HEADER_SIZE + datap->length + 1] = (crc & 0b11111111);
        // Add output tail size
        rs485p->obTail += datap->length + RS485_CRC_SIZE;
      }

      // Enable TX
      RS485D2.usart->CR1|= USART_CR1_TXEIE;

      // ACK handling
      if (ackFlag == RS485_FLAG_ACK) {
        /*// Wait while TRC_SENDING_WITH_ACK
        while (rs485p->trcState == TRC_SENDING_WITH_ACK){
          chThdSleepMicroseconds(rs485p->oneByteTimeUS);
        }*/
        // Wait approximate time to send a packet
        chThdSleepMicroseconds(rs485p->oneByteTimeUS * rs485p->obTail);
        // Wait for ACK
        wait = 0;
        do {
          chThdSleepMicroseconds(rs485p->oneByteTimeUS * RS485_ACK_SIZE);
          reply = rs485p->trcState;
          wait++;
        } while ((reply != TRC_READY) && (reply != TRC_ACKED) && (wait < RS485_ACK_WAIT));
        // Reset TRC state
        rs485_lld_SetTRCReady(rs485p);
        if (reply == TRC_ACKED) return MSG_OK;
      } else {
        return MSG_OK; // No ACK requested then we are done.
      }
    } // TRC_READY
    count++;
  } // while repeat
  return MSG_TIMEOUT;
}


/**
 * @brief   Low level serial driver .
 * @details De-initializes the USART, stops the associated clock, resets the
 *          interrupt vector.
 *
 * @param[in] rs485p       pointer to a @p RS485Driver object
 *
 */
msg_t rs485_lld_GetMsg(RS485Driver *rs485p, RS485Msg_t *datap){
  uint16_t crc;

  if (rs485p->trcState == TRC_RECEIVED) {
    // Copy header to buffer
    datap->address = rs485p->ib[0] >> 4;
    datap->ctrl    = (rs485p->ib[1] >> 6) & 0b1;
    datap->ack     = (rs485p->ib[1] >> 7) & 0b1;
    datap->length  = rs485p->ib[1] & 0b111111;

    // Stand alone ACK reply message is invalid
    if (((datap->ack & 0b1) == RS485_FLAG_DTA) && (datap->length == 0)) {
      rs485_lld_SetTRCReady(rs485p);
      return MSG_RESET;
    }

    if ((datap->ctrl & 0b1) == RS485_FLAG_DTA) {
      // Copy data to buffer
      memcpy(&datap->data[0], &rs485p->ib[RS485_HEADER_SIZE], datap->length);
      // Do CRC
      crc = crc16(datap->data, datap->length);
      // Verify received CRC
      if ((rs485p->ib[rs485p->ibHead - 2] != (crc >> 8)) || (rs485p->ib[rs485p->ibHead - 1] != (crc & 0b11111111))) {
        rs485_lld_SetTRCReady(rs485p);
        return MSG_RESET;
      }
    }

    rs485_lld_SetTRCReady(rs485p);
    return MSG_OK;
  }
  else {
    // Reset header
    datap->address = 0;
    datap->ctrl    = 0;
    datap->ack     = 0;
    datap->length  = 0;
  }
  return MSG_TIMEOUT;
}

#endif /* HAL_USE_RS485 */

/** @} */
