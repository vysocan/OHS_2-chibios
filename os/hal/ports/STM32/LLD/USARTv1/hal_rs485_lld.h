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
 * @file    USARTv1/hal_RS485_lld.h
 * @brief   STM32 low level RS485 driver header.
 *
 * @addtogroup RS485
 * @{
 */

#ifndef HAL_RS485_LLD_H
#define HAL_RS485_LLD_H

#if HAL_USE_RS485 || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   USART1 driver enable switch.
 * @details If set to @p TRUE the support for USART1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_RS485_USE_USART1) || defined(__DOXYGEN__)
#define STM32_RS485_USE_USART1             FALSE
#endif

/**
 * @brief   USART2 driver enable switch.
 * @details If set to @p TRUE the support for USART2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_RS485_USE_USART2) || defined(__DOXYGEN__)
#define STM32_RS485_USE_USART2             FALSE
#endif

/**
 * @brief   USART3 driver enable switch.
 * @details If set to @p TRUE the support for USART3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_RS485_USE_USART3) || defined(__DOXYGEN__)
#define STM32_RS485_USE_USART3             FALSE
#endif

/**
 * @brief   UART4 driver enable switch.
 * @details If set to @p TRUE the support for UART4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_RS485_USE_UART4) || defined(__DOXYGEN__)
#define STM32_RS485_USE_UART4              FALSE
#endif

/**
 * @brief   UART5 driver enable switch.
 * @details If set to @p TRUE the support for UART5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_RS485_USE_UART5) || defined(__DOXYGEN__)
#define STM32_RS485_USE_UART5              FALSE
#endif

/**
 * @brief   USART6 driver enable switch.
 * @details If set to @p TRUE the support for USART6 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_RS485_USE_USART6) || defined(__DOXYGEN__)
#define STM32_RS485_USE_USART6             FALSE
#endif

/**
 * @brief   UART7 driver enable switch.
 * @details If set to @p TRUE the support for UART7 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_RS485_USE_UART7) || defined(__DOXYGEN__)
#define STM32_RS485_USE_UART7              FALSE
#endif

/**
 * @brief   UART8 driver enable switch.
 * @details If set to @p TRUE the support for UART8 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_RS485_USE_UART8) || defined(__DOXYGEN__)
#define STM32_RS485_USE_UART8              FALSE
#endif

/**
 * @brief   USART1 interrupt priority level setting.
 */
#if !defined(STM32_RS485_USART1_PRIORITY) || defined(__DOXYGEN__)
#define STM32_RS485_USART1_PRIORITY        12
#endif

/**
 * @brief   USART2 interrupt priority level setting.
 */
#if !defined(STM32_RS485_USART2_PRIORITY) || defined(__DOXYGEN__)
#define STM32_RS485_USART2_PRIORITY        12
#endif

/**
 * @brief   USART3 interrupt priority level setting.
 */
#if !defined(STM32_RS485_USART3_PRIORITY) || defined(__DOXYGEN__)
#define STM32_RS485_USART3_PRIORITY        12
#endif

/**
 * @brief   UART4 interrupt priority level setting.
 */
#if !defined(STM32_RS485_UART4_PRIORITY) || defined(__DOXYGEN__)
#define STM32_RS485_UART4_PRIORITY         12
#endif

/**
 * @brief   UART5 interrupt priority level setting.
 */
#if !defined(STM32_RS485_UART5_PRIORITY) || defined(__DOXYGEN__)
#define STM32_RS485_UART5_PRIORITY         12
#endif

/**
 * @brief   USART6 interrupt priority level setting.
 */
#if !defined(STM32_RS485_USART6_PRIORITY) || defined(__DOXYGEN__)
#define STM32_RS485_USART6_PRIORITY        12
#endif

/**
 * @brief   UART7 interrupt priority level setting.
 */
#if !defined(STM32_RS485_UART7_PRIORITY) || defined(__DOXYGEN__)
#define STM32_RS485_UART7_PRIORITY         12
#endif

/**
 * @brief   UART8 interrupt priority level setting.
 */
#if !defined(STM32_RS485_UART8_PRIORITY) || defined(__DOXYGEN__)
#define STM32_RS485_UART8_PRIORITY         12
#endif

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if STM32_RS485_USE_USART1 && !STM32_HAS_USART1
#error "USART1 not present in the selected device"
#endif

#if STM32_RS485_USE_USART2 && !STM32_HAS_USART2
#error "USART2 not present in the selected device"
#endif

#if STM32_RS485_USE_USART3 && !STM32_HAS_USART3
#error "USART3 not present in the selected device"
#endif

#if STM32_RS485_USE_UART4 && !STM32_HAS_UART4
#error "UART4 not present in the selected device"
#endif

#if STM32_RS485_USE_UART5 && !STM32_HAS_UART5
#error "UART5 not present in the selected device"
#endif

#if STM32_RS485_USE_USART6 && !STM32_HAS_USART6
#error "USART6 not present in the selected device"
#endif

#if STM32_RS485_USE_UART7 && !STM32_HAS_UART7
#error "UART7 not present in the selected device"
#endif

#if STM32_RS485_USE_UART8 && !STM32_HAS_UART8
#error "UART8 not present in the selected device"
#endif

#if !STM32_RS485_USE_USART1 && !STM32_RS485_USE_USART2 &&                 \
    !STM32_RS485_USE_USART3 && !STM32_RS485_USE_UART4  &&                 \
    !STM32_RS485_USE_UART5  && !STM32_RS485_USE_USART6 &&                 \
    !STM32_RS485_USE_UART7  && !STM32_RS485_USE_UART8
#error "RS485 driver activated but no USART/UART peripheral assigned"
#endif

#if STM32_RS485_USE_USART1 &&                                              \
    !OSAL_IRQ_IS_VALID_PRIORITY(STM32_RS485_USART1_PRIORITY)
#error "Invalid IRQ priority assigned to USART1"
#endif

#if STM32_RS485_USE_USART2 &&                                              \
    !OSAL_IRQ_IS_VALID_PRIORITY(STM32_RS485_USART2_PRIORITY)
#error "Invalid IRQ priority assigned to USART2"
#endif

#if STM32_RS485_USE_USART3 &&                                              \
    !OSAL_IRQ_IS_VALID_PRIORITY(STM32_RS485_USART3_PRIORITY)
#error "Invalid IRQ priority assigned to USART3"
#endif

#if STM32_RS485_USE_UART4 &&                                               \
    !OSAL_IRQ_IS_VALID_PRIORITY(STM32_RS485_UART4_PRIORITY)
#error "Invalid IRQ priority assigned to UART4"
#endif

#if STM32_RS485_USE_UART5 &&                                               \
    !OSAL_IRQ_IS_VALID_PRIORITY(STM32_RS485_UART5_PRIORITY)
#error "Invalid IRQ priority assigned to UART5"
#endif

#if STM32_RS485_USE_USART6 &&                                              \
    !OSAL_IRQ_IS_VALID_PRIORITY(STM32_RS485_USART6_PRIORITY)
#error "Invalid IRQ priority assigned to USART6"
#endif

#if STM32_RS485_USE_UART7 &&                                               \
    !OSAL_IRQ_IS_VALID_PRIORITY(STM32_RS485_UART7_PRIORITY)
#error "Invalid IRQ priority assigned to UART7"
#endif

#if STM32_RS485_USE_UART8 &&                                               \
    !OSAL_IRQ_IS_VALID_PRIORITY(STM32_RS485_UART8_PRIORITY)
#error "Invalid IRQ priority assigned to UART8"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   STM32 RS485 Driver configuration structure.
 * @details An instance of this structure must be passed to @p sdStart()
 *          in order to configure and start a RS485 driver operations.
 * @note    This structure content is architecture dependent, each driver
 *          implementation defines its own version and the custom static
 *          initializers.
 */
typedef struct {
  /**
   * @brief Bit rate.
   */
  uint32_t                  speed;
  /**
   * @brief Our address.
   */
  uint8_t                   address;
  /**
   * @brief The DE port.
   */
  ioportid_t                deport;
  /**
   * @brief The DE pad number.
   */
  uint_fast8_t              depad;
  /* End of the mandatory fields.*/
} RS485Config;

/**
 * @brief   @p RS485Driver specific data.
 */
#define _rs485_driver_data                                                  \
  binary_semaphore_t        received;                                       \
  /* Driver state.*/                                                        \
  rs485state_t              state;                                          \
  /* Transceiver state.*/                                                   \
  rs485transceiver_t        trcState;                                       \
  /* Input buffer.*/                                                        \
  uint8_t                   ib[RS485_PACKET_SIZE];                          \
  uint8_t                   ibHead;                                         \
  uint8_t                   ibExpLen;                                       \
  uint8_t                   ibMsg;                                          \
  /* Output buffer.*/                                                       \
  uint8_t                   ob[RS485_PACKET_SIZE];                          \
  uint8_t                   obHead;                                         \
  uint8_t                   obTail;                                         \
  /*   Current configuration data.   */										\
  const RS485Config        *config;						     				\
  /* Pointer to the USART registers block.*/                                \
  USART_TypeDef             *usart;                                         \
  /* Receive timeout timer */                                               \
  virtual_timer_t           receiveVT;                                      \
  uint32_t                  oneByteTimeUS;                                  \
  uint32_t                  oneByteTimeI;                                   \
  event_source_t            event;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*
 * Extra USARTs definitions here (missing from the ST header file).
 */
#define USART_CR2_STOP1_BITS    (0 << 12)   /**< @brief CR2 1 stop bit value.*/
#define USART_CR2_STOP0P5_BITS  (1 << 12)   /**< @brief CR2 0.5 stop bit value.*/
#define USART_CR2_STOP2_BITS    (2 << 12)   /**< @brief CR2 2 stop bit value.*/
#define USART_CR2_STOP1P5_BITS  (3 << 12)   /**< @brief CR2 1.5 stop bit value.*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if STM32_RS485_USE_USART1 && !defined(__DOXYGEN__)
extern RS485Driver RS485D1;
#endif
#if STM32_RS485_USE_USART2 && !defined(__DOXYGEN__)
extern RS485Driver RS485D2;
#endif
#if STM32_RS485_USE_USART3 && !defined(__DOXYGEN__)
extern RS485Driver RS485D3;
#endif
#if STM32_RS485_USE_UART4 && !defined(__DOXYGEN__)
extern RS485Driver RS485D4;
#endif
#if STM32_RS485_USE_UART5 && !defined(__DOXYGEN__)
extern RS485Driver RS485D5;
#endif
#if STM32_RS485_USE_USART6 && !defined(__DOXYGEN__)
extern RS485Driver RS485D6;
#endif
#if STM32_RS485_USE_UART7 && !defined(__DOXYGEN__)
extern RS485Driver RS485D7;
#endif
#if STM32_RS485_USE_UART8 && !defined(__DOXYGEN__)
extern RS485Driver RS485D8;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void rs485_lld_init(void);
  void rs485_lld_start(RS485Driver *rs485p, const RS485Config *config);
  void rs485_lld_stop(RS485Driver *rs485p);

  void rs485_lld_SetTRCReady(RS485Driver *rs485p);
  //msg_t rs485_lld_SendMsg(RS485Driver *rs485p, RS485Msg_t *datap);
  msg_t rs485_lld_SendMsgWithACK(RS485Driver *rs485p, RS485Msg_t *datap, uint8_t repeat, uint8_t ackFlag);
  msg_t rs485_lld_GetMsg(RS485Driver *rs485p, RS485Msg_t *datap);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_RS485 */

#endif /* HAL_RS485_LLD_H */

/** @} */
