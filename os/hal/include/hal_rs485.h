

/**
 * @file    hal_rs485.h
 * @brief   RS485 Serial Driver macros and structures.
 *
 * @addtogroup RS485
 * @{
 */

#ifndef HAL_RS485_H
#define HAL_RS485_H

#if (HAL_USE_RS485 == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    RS485 constants
 */
#define RS485_MSG_SIZE    64
#define RS485_HEADER_SIZE 3
#define RS485_CRC_SIZE    2
#define RS485_PACKET_SIZE (RS485_MSG_SIZE + RS485_HEADER_SIZE + RS485_CRC_SIZE)
#define RS485_ACK_SIZE    (RS485_HEADER_SIZE + RS485_CRC_SIZE)
#define RS485_ACK_WAIT    6 // Wait # of time it takes to receive whole ACK

#define RS485_MAX_ADDRESS 16 // 0 - 15
#define RS485_MAX_CTRL    2  // 0b0 - 0b1

/**
 * @name    RS485 header flags
 */
#define RS485_FLAG_ACK    0b1
#define RS485_FLAG_NACK   0b0
#define RS485_FLAG_CMD    0b1
#define RS485_FLAG_DTA    0b0

/**
 * @name    Serial status flags
 * @{
 */
#define SD_PARITY_ERROR              (eventflags_t)32    /**< @brief Parity.     */
#define SD_FRAMING_ERROR             (eventflags_t)64    /**< @brief Framing.    */
#define SD_OVERRUN_ERROR             (eventflags_t)128   /**< @brief Overflow.   */
#define SD_NOISE_ERROR               (eventflags_t)256   /**< @brief Line noise. */
#define SD_BREAK_DETECTED            (eventflags_t)512   /**< @brief LIN Break.  */
/* We do not use queues  #define SD_QUEUE_FULL_ERROR (eventflags_t)1024  Queue full. */
#define RS485_MSG_RECEIVED           (eventflags_t)1024  /**< @brief Incoming message */
#define RS485_MSG_RECEIVED_WA        (eventflags_t)2048  /**< @brief Incoming message with ACK */
#define RS485_MSG_XOR_ERROR          (eventflags_t)4096  /**< @brief Incoming message has faulty XOR */
#define RS485_MSG_INVALID            (eventflags_t)8192  /**< @brief Incoming message is invalid */
#define RS485_RECEIVING_NOT_CONTINUE (eventflags_t)16384  /**< @brief Receiving interrupted, not finished */
#define RS485_ACK_ERROR              (eventflags_t)32468  /**< @brief ACK error on addresses*/
#define RS485_ACK_ERROR_CRC          (eventflags_t)65535  /**< @brief ACK error on CRC */
#define RS485_ACK_ERROR_CMD          (eventflags_t)131072  /**< @brief ACK error on CMD */
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    RS485 configuration options
 * @{
 */
/**
 * @brief   Default bit rate.
 * @details Configuration parameter, this is the baud rate selected for the
 *          default configuration.
 */
#if !defined(RS485_DEFAULT_BITRATE) || defined(__DOXYGEN__)
#define RS485_DEFAULT_BITRATE      19200
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief RS485 message structure
 */
typedef struct {
  uint8_t address;
  uint8_t length;
  uint8_t ctrl;
  uint8_t ack;
  uint8_t data[RS485_MSG_SIZE];
} RS485Msg_t;

typedef struct {
  uint8_t address;
  uint8_t length;
  uint8_t ctrl;
  uint8_t ack;
} RS485Cmd_t;

/**
 * @brief Driver state machine possible states.
 */
typedef enum {
  RS485_UNINIT = 0,                    /**< Not initialized.                   */
  RS485_STOP = 1,                      /**< Stopped.                           */
  RS485_READY = 2                      /**< Ready.                             */
} rs485state_t;

/**
 * @brief Tranciever state machine possible states.
 */
typedef enum {
  TRC_UNINIT            = 0,
  TRC_STOP              = 1,
  TRC_READY             = 2,
  TRC_SENDING           = 3,
  TRC_SENDING_WITH_ACK  = 4,
  TRC_WAITING_ACK       = 5,
  TRC_RECEIVING         = 6,
  TRC_ACKING            = 7,
  TRC_RECEIVED          = 8,
  TRC_ACKED             = 9
} rs485transceiver_t;

/**
 * @brief   Structure representing a RS485 driver.
 */
typedef struct RS485Driver RS485Driver;

#include "hal_rs485_lld.h"

/**
 * @extends BaseAsynchronousChannel
 *
 * @brief   Full duplex RS485 driver class.
 * @details This class extends @p BaseAsynchronousChannel by adding physical
 *          I/O queues.
 */
struct RS485Driver {
  /** @brief Virtual Methods Table.*/
  //const struct RS485DriverVMT *vmt;
  _rs485_driver_data
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/


/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void rs485Init(void);
  void rs485ObjectInit(RS485Driver *rs485p);
  void rs485Start(RS485Driver *rs485p, const RS485Config *config);
  void rs485Stop(RS485Driver *rs485p);
  void rs485IncomingDataI(RS485Driver *rs485p, uint8_t b);

  msg_t rs485SendMsg(RS485Driver *rs485p, RS485Msg_t *datap);
  msg_t rs485SendCmd(RS485Driver *rs485p, RS485Cmd_t *datap);
  msg_t rs485SendMsgWithACK(RS485Driver *rs485p, RS485Msg_t *datap, uint8_t repeat);
  msg_t rs485SendCmdWithACK(RS485Driver *rs485p, RS485Cmd_t *datap, uint8_t repeat);
  msg_t rs485GetMsg(RS485Driver *rs485p, RS485Msg_t *datap);

#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_RS485 == TRUE */

#endif /* HAL_RS485_H */

/** @} */
