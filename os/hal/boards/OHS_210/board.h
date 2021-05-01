/*
    ChibiOS - Copyright (C) 2006..2020 Giovanni Di Sirio

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

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for Open Home Security STM32H743-2.1.0 board.
 */

/*
 * Board identifier.
 */
#define BOARD_OHS_210
#define BOARD_NAME                  "Open Home Security STM32H743-2.1.0"

/*
 * Ethernet PHY type.
 */
#define BOARD_PHY_ID                MII_LAN8720_ID
#define BOARD_PHY_RMII

/*
 * Board oscillators-related settings.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                32768U
#endif

#define STM32_LSEDRV                (3U << 3U)

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                8000000U
#endif

/*
 * MCU type as defined in the ST header.
 */
#define STM32H743xx

/*
 * IO pins assignments.
 */
#define GPIOA_ADC1_IN0              0U
#define GPIOA_ETH_RMII_REF_CLK      1U
#define GPIOA_ETH_RMII_MDIO         2U
#define GPIOA_ADC1_IN3              3U
#define GPIOA_ADC1_IN4              4U
#define GPIOA_ADC1_IN5              5U
#define GPIOA_ADC1_IN6              6U
#define GPIOA_ETH_RMII_CRS_DV       7U
#define GPIOA_PIN8                  8U
#define GPIOA_VBUS_FS               9U
#define GPIOA_OTG_FS_ID             10U
#define GPIOA_OTG_FS_DM             11U
#define GPIOA_OTG_FS_DP             12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_RADIO_RESET           15U

#define GPIOB_ADC1_IN8              0U
#define GPIOB_ADC1_IN9              1U
#define GPIOB_ETH_RMII_INT          2U
#define GPIOB_SPI1_SCK              3U
#define GPIOB_SPI1_MISO             4U
#define GPIOB_SPI1_MOSI             5U
#define GPIOB_TX1                   6U
#define GPIOB_RX1                   7U
#define GPIOB_RELAY_2               8U
#define GPIOB_RELAY_1               9U
#define GPIOB_PIN10                 10U
#define GPIOB_ETH_RMII_TXEN         11U
#define GPIOB_ETH_RMII_TXD0         12U
#define GPIOB_ETH_RMII_TXD1         13U
#define GPIOB_PIN14                 14U
#define GPIOB_PIN15                 15U

#define GPIOC_ADC1_IN10             0U
#define GPIOC_ETH_RMII_MDC          1U
#define GPIOC_ADC1_IN12             2U
#define GPIOC_ADC1_IN13             3U
#define GPIOC_ETH_RMII_RXD0         4U
#define GPIOC_ETH_RMII_RXD1         5U
#define GPIOC_TX6                   6U
#define GPIOC_RX6                   7U
#define GPIOC_HEARTBEAT             8U
#define GPIOC_PIN9                  9U
#define GPIOC_SPI3_SCK              10U
#define GPIOC_SPI3_MISO             11U
#define GPIOC_SPI3_MOSI             12U
#define GPIOC_BUTTON_PC13           13U
#define GPIOC_PIN14                 14U
#define GPIOC_PIN15                 15U

#define GPIOD_SPI3_CS               0U
#define GPIOD_PIN1                  1U
#define GPIOD_PIN2                  2U
#define GPIOD_RADIO_IRQ             3U
#define GPIOD_USART2_DE             4U
#define GPIOD_TX2                   5U
#define GPIOD_RX2                   6U
#define GPIOD_SPI1_CS               7U
#define GPIOD_TX3                   8U
#define GPIOD_RX3                   9U
#define GPIOD_AC_OFF                10U
#define GPIOD_BAT_OK                11U
#define GPIOD_PIN12                 12U
#define GPIOD_GSM_STATUS            13U
#define GPIOD_GSM_PWRKEY            14U
#define GPIOD_PIN15                 15U

#define GPIOE_PIN0                  0U
#define GPIOE_PIN1                  1U
#define GPIOE_UART1                 2U
#define GPIOE_BLUE_LED              3U
#define GPIOE_PIN4                  4U
#define GPIOE_PIN5                  5U
#define GPIOE_PIN6                  6U
#define GPIOE_PIN7                  7U
#define GPIOE_PIN8                  8U
#define GPIOE_DIN_BOX               9U
#define GPIOE_PIN10                 10U
#define GPIOE_PIN11                 11U
#define GPIOE_ETH_RESET             12U
#define GPIOE_PIN13                 13U
#define GPIOE_PIN14                 14U
#define GPIOE_PIN15                 15U

#define GPIOF_PIN0                  0U
#define GPIOF_PIN1                  1U
#define GPIOF_PIN2                  2U
#define GPIOF_PIN3                  3U
#define GPIOF_PIN4                  4U
#define GPIOF_PIN5                  5U
#define GPIOF_PIN6                  6U
#define GPIOF_PIN7                  7U
#define GPIOF_PIN8                  8U
#define GPIOF_PIN9                  9U
#define GPIOF_PIN10                 10U
#define GPIOF_PIN11                 11U
#define GPIOF_PIN12                 12U
#define GPIOF_PIN13                 13U
#define GPIOF_PIN14                 14U
#define GPIOF_PIN15                 15U

#define GPIOG_PIN0                  0U
#define GPIOG_PIN1                  1U
#define GPIOG_PIN2                  2U
#define GPIOG_PIN3                  3U
#define GPIOG_PIN4                  4U
#define GPIOG_PIN5                  5U
#define GPIOG_PIN6                  6U
#define GPIOG_PIN7                  7U
#define GPIOG_PIN8                  8U
#define GPIOG_PIN9                  9U
#define GPIOG_PIN10                 10U
#define GPIOG_PIN11                 11U
#define GPIOG_PIN12                 12U
#define GPIOG_PIN13                 13U
#define GPIOG_PIN14                 14U
#define GPIOG_PIN15                 15U

#define GPIOH_OSC_IN                0U
#define GPIOH_OSC_OUT               1U
#define GPIOH_PIN2                  2U
#define GPIOH_PIN3                  3U
#define GPIOH_PIN4                  4U
#define GPIOH_PIN5                  5U
#define GPIOH_PIN6                  6U
#define GPIOH_PIN7                  7U
#define GPIOH_PIN8                  8U
#define GPIOH_PIN9                  9U
#define GPIOH_PIN10                 10U
#define GPIOH_PIN11                 11U
#define GPIOH_PIN12                 12U
#define GPIOH_PIN13                 13U
#define GPIOH_PIN14                 14U
#define GPIOH_PIN15                 15U

#define GPIOI_PIN0                  0U
#define GPIOI_PIN1                  1U
#define GPIOI_PIN2                  2U
#define GPIOI_PIN3                  3U
#define GPIOI_PIN4                  4U
#define GPIOI_PIN5                  5U
#define GPIOI_PIN6                  6U
#define GPIOI_PIN7                  7U
#define GPIOI_PIN8                  8U
#define GPIOI_PIN9                  9U
#define GPIOI_PIN10                 10U
#define GPIOI_PIN11                 11U
#define GPIOI_PIN12                 12U
#define GPIOI_PIN13                 13U
#define GPIOI_PIN14                 14U
#define GPIOI_PIN15                 15U

#define GPIOJ_PIN0                  0U
#define GPIOJ_PIN1                  1U
#define GPIOJ_PIN2                  2U
#define GPIOJ_PIN3                  3U
#define GPIOJ_PIN4                  4U
#define GPIOJ_PIN5                  5U
#define GPIOJ_PIN6                  6U
#define GPIOJ_PIN7                  7U
#define GPIOJ_PIN8                  8U
#define GPIOJ_PIN9                  9U
#define GPIOJ_PIN10                 10U
#define GPIOJ_PIN11                 11U
#define GPIOJ_PIN12                 12U
#define GPIOJ_PIN13                 13U
#define GPIOJ_PIN14                 14U
#define GPIOJ_PIN15                 15U

#define GPIOK_PIN0                  0U
#define GPIOK_PIN1                  1U
#define GPIOK_PIN2                  2U
#define GPIOK_PIN3                  3U
#define GPIOK_PIN4                  4U
#define GPIOK_PIN5                  5U
#define GPIOK_PIN6                  6U
#define GPIOK_PIN7                  7U
#define GPIOK_PIN8                  8U
#define GPIOK_PIN9                  9U
#define GPIOK_PIN10                 10U
#define GPIOK_PIN11                 11U
#define GPIOK_PIN12                 12U
#define GPIOK_PIN13                 13U
#define GPIOK_PIN14                 14U
#define GPIOK_PIN15                 15U

/*
 * IO lines assignments.
 */
#define LINE_ADC1_IN0               PAL_LINE(GPIOA, 0U)
#define LINE_ETH_RMII_REF_CLK       PAL_LINE(GPIOA, 1U)
#define LINE_ETH_RMII_MDIO          PAL_LINE(GPIOA, 2U)
#define LINE_ADC1_IN3               PAL_LINE(GPIOA, 3U)
#define LINE_ADC1_IN4               PAL_LINE(GPIOA, 4U)
#define LINE_ADC1_IN5               PAL_LINE(GPIOA, 5U)
#define LINE_ADC1_IN6               PAL_LINE(GPIOA, 6U)
#define LINE_ETH_RMII_CRS_DV        PAL_LINE(GPIOA, 7U)
#define LINE_VBUS_FS                PAL_LINE(GPIOA, 9U)
#define LINE_OTG_FS_ID              PAL_LINE(GPIOA, 10U)
#define LINE_OTG_FS_DM              PAL_LINE(GPIOA, 11U)
#define LINE_OTG_FS_DP              PAL_LINE(GPIOA, 12U)
#define LINE_SWDIO                  PAL_LINE(GPIOA, 13U)
#define LINE_SWCLK                  PAL_LINE(GPIOA, 14U)
#define LINE_RADIO_RESET            PAL_LINE(GPIOA, 15U)
#define LINE_ADC1_IN8               PAL_LINE(GPIOB, 0U)
#define LINE_ADC1_IN9               PAL_LINE(GPIOB, 1U)
#define LINE_ETH_RMII_INT           PAL_LINE(GPIOB, 2U)
#define LINE_SPI1_SCK               PAL_LINE(GPIOB, 3U)
#define LINE_SPI1_MISO              PAL_LINE(GPIOB, 4U)
#define LINE_SPI1_MOSI              PAL_LINE(GPIOB, 5U)
#define LINE_TX1                    PAL_LINE(GPIOB, 6U)
#define LINE_RX1                    PAL_LINE(GPIOB, 7U)
#define LINE_RELAY_2                PAL_LINE(GPIOB, 8U)
#define LINE_RELAY_1                PAL_LINE(GPIOB, 9U)
#define LINE_ETH_RMII_TXEN          PAL_LINE(GPIOB, 11U)
#define LINE_ETH_RMII_TXD0          PAL_LINE(GPIOB, 12U)
#define LINE_ETH_RMII_TXD1          PAL_LINE(GPIOB, 13U)
#define LINE_ADC1_IN10              PAL_LINE(GPIOC, 0U)
#define LINE_ETH_RMII_MDC           PAL_LINE(GPIOC, 1U)
#define LINE_ADC1_IN12              PAL_LINE(GPIOC, 2U)
#define LINE_ADC1_IN13              PAL_LINE(GPIOC, 3U)
#define LINE_ETH_RMII_RXD0          PAL_LINE(GPIOC, 4U)
#define LINE_ETH_RMII_RXD1          PAL_LINE(GPIOC, 5U)
#define LINE_TX6                    PAL_LINE(GPIOC, 6U)
#define LINE_RX6                    PAL_LINE(GPIOC, 7U)
#define LINE_HEARTBEAT              PAL_LINE(GPIOC, 8U)
#define LINE_SPI3_SCK               PAL_LINE(GPIOC, 10U)
#define LINE_SPI3_MISO              PAL_LINE(GPIOC, 11U)
#define LINE_SPI3_MOSI              PAL_LINE(GPIOC, 12U)
#define LINE_BUTTON_PC13            PAL_LINE(GPIOC, 13U)
#define LINE_SPI3_CS                PAL_LINE(GPIOD, 0U)
#define LINE_RADIO_IRQ              PAL_LINE(GPIOD, 3U)
#define LINE_USART2_DE              PAL_LINE(GPIOD, 4U)
#define LINE_TX2                    PAL_LINE(GPIOD, 5U)
#define LINE_RX2                    PAL_LINE(GPIOD, 6U)
#define LINE_SPI1_CS                PAL_LINE(GPIOD, 7U)
#define LINE_TX3                    PAL_LINE(GPIOD, 8U)
#define LINE_RX3                    PAL_LINE(GPIOD, 9U)
#define LINE_AC_OFF                 PAL_LINE(GPIOD, 10U)
#define LINE_BAT_OK                 PAL_LINE(GPIOD, 11U)
#define LINE_GSM_STATUS             PAL_LINE(GPIOD, 13U)
#define LINE_GSM_PWRKEY             PAL_LINE(GPIOD, 14U)
#define LINE_UART1                  PAL_LINE(GPIOE, 2U)
#define LINE_BLUE_LED               PAL_LINE(GPIOE, 3U)
#define LINE_DIN_BOX                PAL_LINE(GPIOE, 9U)
#define LINE_ETH_RESET              PAL_LINE(GPIOE, 12U)
#define LINE_OSC_IN                 PAL_LINE(GPIOH, 0U)
#define LINE_OSC_OUT                PAL_LINE(GPIOH, 1U)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))

/*
 * GPIOA setup:
 *
 * PA0  - ADC1_IN0                  (analog).
 * PA1  - ETH_RMII_REF_CLK          (alternate 11).
 * PA2  - ETH_RMII_MDIO             (alternate 11).
 * PA3  - ADC1_IN3                  (analog).
 * PA4  - ADC1_IN4                  (analog).
 * PA5  - ADC1_IN5                  (analog).
 * PA6  - ADC1_IN6                  (analog).
 * PA7  - ETH_RMII_CRS_DV           (alternate 11).
 * PA8  - PIN8                      (input pullup).
 * PA9  - VBUS_FS                   (input floating).
 * PA10 - OTG_FS_ID                 (alternate 10).
 * PA11 - OTG_FS_DM                 (alternate 10).
 * PA12 - OTG_FS_DP                 (alternate 10).
 * PA13 - SWDIO                     (alternate 0).
 * PA14 - SWCLK                     (alternate 0).
 * PA15 - RADIO_RESET               (output pushpull maximum).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_ANALOG(GPIOA_ADC1_IN0) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_ETH_RMII_REF_CLK) |\
                                     PIN_MODE_ALTERNATE(GPIOA_ETH_RMII_MDIO) |\
                                     PIN_MODE_ANALOG(GPIOA_ADC1_IN3) |      \
                                     PIN_MODE_ANALOG(GPIOA_ADC1_IN4) |      \
                                     PIN_MODE_ANALOG(GPIOA_ADC1_IN5) |      \
                                     PIN_MODE_ANALOG(GPIOA_ADC1_IN6) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_ETH_RMII_CRS_DV) |\
                                     PIN_MODE_INPUT(GPIOA_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOA_VBUS_FS) |        \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_ID) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_DM) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_DP) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK) |      \
                                     PIN_MODE_OUTPUT(GPIOA_RADIO_RESET))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_ADC1_IN0) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_ETH_RMII_REF_CLK) |\
                                     PIN_OTYPE_PUSHPULL(GPIOA_ETH_RMII_MDIO) |\
                                     PIN_OTYPE_PUSHPULL(GPIOA_ADC1_IN3) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_ADC1_IN4) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_ADC1_IN5) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_ADC1_IN6) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_ETH_RMII_CRS_DV) |\
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_VBUS_FS) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOA_OTG_FS_ID) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_OTG_FS_DM) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_OTG_FS_DP) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_RADIO_RESET))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_HIGH(GPIOA_ADC1_IN0) |      \
                                     PIN_OSPEED_HIGH(GPIOA_ETH_RMII_REF_CLK) |\
                                     PIN_OSPEED_HIGH(GPIOA_ETH_RMII_MDIO) | \
                                     PIN_OSPEED_HIGH(GPIOA_ADC1_IN3) |      \
                                     PIN_OSPEED_HIGH(GPIOA_ADC1_IN4) |      \
                                     PIN_OSPEED_HIGH(GPIOA_ADC1_IN5) |      \
                                     PIN_OSPEED_HIGH(GPIOA_ADC1_IN6) |      \
                                     PIN_OSPEED_HIGH(GPIOA_ETH_RMII_CRS_DV) |\
                                     PIN_OSPEED_HIGH(GPIOA_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOA_VBUS_FS) |       \
                                     PIN_OSPEED_HIGH(GPIOA_OTG_FS_ID) |     \
                                     PIN_OSPEED_HIGH(GPIOA_OTG_FS_DM) |     \
                                     PIN_OSPEED_HIGH(GPIOA_OTG_FS_DP) |     \
                                     PIN_OSPEED_HIGH(GPIOA_SWDIO) |         \
                                     PIN_OSPEED_HIGH(GPIOA_SWCLK) |         \
                                     PIN_OSPEED_HIGH(GPIOA_RADIO_RESET))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_FLOATING(GPIOA_ADC1_IN0) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_ETH_RMII_REF_CLK) |\
                                     PIN_PUPDR_FLOATING(GPIOA_ETH_RMII_MDIO) |\
                                     PIN_PUPDR_FLOATING(GPIOA_ADC1_IN3) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_ADC1_IN4) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_ADC1_IN5) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_ADC1_IN6) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_ETH_RMII_CRS_DV) |\
                                     PIN_PUPDR_PULLUP(GPIOA_PIN8) |         \
                                     PIN_PUPDR_FLOATING(GPIOA_VBUS_FS) |    \
                                     PIN_PUPDR_FLOATING(GPIOA_OTG_FS_ID) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_OTG_FS_DM) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_OTG_FS_DP) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_SWDIO) |      \
                                     PIN_PUPDR_FLOATING(GPIOA_SWCLK) |      \
                                     PIN_PUPDR_FLOATING(GPIOA_RADIO_RESET))
#define VAL_GPIOA_ODR               (PIN_ODR_HIGH(GPIOA_ADC1_IN0) |         \
                                     PIN_ODR_HIGH(GPIOA_ETH_RMII_REF_CLK) | \
                                     PIN_ODR_HIGH(GPIOA_ETH_RMII_MDIO) |    \
                                     PIN_ODR_HIGH(GPIOA_ADC1_IN3) |         \
                                     PIN_ODR_HIGH(GPIOA_ADC1_IN4) |         \
                                     PIN_ODR_HIGH(GPIOA_ADC1_IN5) |         \
                                     PIN_ODR_HIGH(GPIOA_ADC1_IN6) |         \
                                     PIN_ODR_HIGH(GPIOA_ETH_RMII_CRS_DV) |  \
                                     PIN_ODR_HIGH(GPIOA_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOA_VBUS_FS) |          \
                                     PIN_ODR_HIGH(GPIOA_OTG_FS_ID) |        \
                                     PIN_ODR_HIGH(GPIOA_OTG_FS_DM) |        \
                                     PIN_ODR_HIGH(GPIOA_OTG_FS_DP) |        \
                                     PIN_ODR_HIGH(GPIOA_SWDIO) |            \
                                     PIN_ODR_HIGH(GPIOA_SWCLK) |            \
                                     PIN_ODR_LOW(GPIOA_RADIO_RESET))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_ADC1_IN0, 0U) |      \
                                     PIN_AFIO_AF(GPIOA_ETH_RMII_REF_CLK, 11U) |\
                                     PIN_AFIO_AF(GPIOA_ETH_RMII_MDIO, 11U) |\
                                     PIN_AFIO_AF(GPIOA_ADC1_IN3, 0U) |      \
                                     PIN_AFIO_AF(GPIOA_ADC1_IN4, 0U) |      \
                                     PIN_AFIO_AF(GPIOA_ADC1_IN5, 0U) |      \
                                     PIN_AFIO_AF(GPIOA_ADC1_IN6, 0U) |      \
                                     PIN_AFIO_AF(GPIOA_ETH_RMII_CRS_DV, 11U))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_VBUS_FS, 0U) |       \
                                     PIN_AFIO_AF(GPIOA_OTG_FS_ID, 10U) |    \
                                     PIN_AFIO_AF(GPIOA_OTG_FS_DM, 10U) |    \
                                     PIN_AFIO_AF(GPIOA_OTG_FS_DP, 10U) |    \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_RADIO_RESET, 0U))

/*
 * GPIOB setup:
 *
 * PB0  - ADC1_IN8                  (analog).
 * PB1  - ADC1_IN9                  (analog).
 * PB2  - ETH_RMII_INT              (input floating).
 * PB3  - SPI1_SCK                  (alternate 5).
 * PB4  - SPI1_MISO                 (alternate 5).
 * PB5  - SPI1_MOSI                 (alternate 5).
 * PB6  - TX1                       (alternate 7).
 * PB7  - RX1                       (alternate 7).
 * PB8  - RELAY_2                   (output pushpull maximum).
 * PB9  - RELAY_1                   (output pushpull maximum).
 * PB10 - PIN10                     (input floating).
 * PB11 - ETH_RMII_TXEN             (alternate 11).
 * PB12 - ETH_RMII_TXD0             (alternate 11).
 * PB13 - ETH_RMII_TXD1             (alternate 11).
 * PB14 - PIN14                     (input floating).
 * PB15 - PIN15                     (input pullup).
 */
#define VAL_GPIOB_MODER             (PIN_MODE_ANALOG(GPIOB_ADC1_IN8) |      \
                                     PIN_MODE_ANALOG(GPIOB_ADC1_IN9) |      \
                                     PIN_MODE_INPUT(GPIOB_ETH_RMII_INT) |   \
                                     PIN_MODE_ALTERNATE(GPIOB_SPI1_SCK) |   \
                                     PIN_MODE_ALTERNATE(GPIOB_SPI1_MISO) |  \
                                     PIN_MODE_ALTERNATE(GPIOB_SPI1_MOSI) |  \
                                     PIN_MODE_ALTERNATE(GPIOB_TX1) |        \
                                     PIN_MODE_ALTERNATE(GPIOB_RX1) |        \
                                     PIN_MODE_OUTPUT(GPIOB_RELAY_2) |       \
                                     PIN_MODE_OUTPUT(GPIOB_RELAY_1) |       \
                                     PIN_MODE_INPUT(GPIOB_PIN10) |          \
                                     PIN_MODE_ALTERNATE(GPIOB_ETH_RMII_TXEN) |\
                                     PIN_MODE_ALTERNATE(GPIOB_ETH_RMII_TXD0) |\
                                     PIN_MODE_ALTERNATE(GPIOB_ETH_RMII_TXD1) |\
                                     PIN_MODE_INPUT(GPIOB_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOB_PIN15))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_ADC1_IN8) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOB_ADC1_IN9) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOB_ETH_RMII_INT) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_SPI1_SCK) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SPI1_MISO) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SPI1_MOSI) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOB_TX1) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_RX1) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_RELAY_2) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOB_RELAY_1) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_ETH_RMII_TXEN) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_ETH_RMII_TXD0) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_ETH_RMII_TXD1) |\
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN15))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_HIGH(GPIOB_ADC1_IN8) |      \
                                     PIN_OSPEED_HIGH(GPIOB_ADC1_IN9) |      \
                                     PIN_OSPEED_HIGH(GPIOB_ETH_RMII_INT) |  \
                                     PIN_OSPEED_HIGH(GPIOB_SPI1_SCK) |      \
                                     PIN_OSPEED_HIGH(GPIOB_SPI1_MISO) |     \
                                     PIN_OSPEED_HIGH(GPIOB_SPI1_MOSI) |     \
                                     PIN_OSPEED_HIGH(GPIOB_TX1) |           \
                                     PIN_OSPEED_HIGH(GPIOB_RX1) |           \
                                     PIN_OSPEED_HIGH(GPIOB_RELAY_2) |       \
                                     PIN_OSPEED_HIGH(GPIOB_RELAY_1) |       \
                                     PIN_OSPEED_HIGH(GPIOB_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOB_ETH_RMII_TXEN) | \
                                     PIN_OSPEED_HIGH(GPIOB_ETH_RMII_TXD0) | \
                                     PIN_OSPEED_HIGH(GPIOB_ETH_RMII_TXD1) | \
                                     PIN_OSPEED_HIGH(GPIOB_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOB_PIN15))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_FLOATING(GPIOB_ADC1_IN8) |   \
                                     PIN_PUPDR_FLOATING(GPIOB_ADC1_IN9) |   \
                                     PIN_PUPDR_FLOATING(GPIOB_ETH_RMII_INT) |\
                                     PIN_PUPDR_FLOATING(GPIOB_SPI1_SCK) |   \
                                     PIN_PUPDR_FLOATING(GPIOB_SPI1_MISO) |  \
                                     PIN_PUPDR_FLOATING(GPIOB_SPI1_MOSI) |  \
                                     PIN_PUPDR_PULLUP(GPIOB_TX1) |          \
                                     PIN_PUPDR_PULLUP(GPIOB_RX1) |          \
                                     PIN_PUPDR_FLOATING(GPIOB_RELAY_2) |    \
                                     PIN_PUPDR_FLOATING(GPIOB_RELAY_1) |    \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOB_ETH_RMII_TXEN) |\
                                     PIN_PUPDR_FLOATING(GPIOB_ETH_RMII_TXD0) |\
                                     PIN_PUPDR_FLOATING(GPIOB_ETH_RMII_TXD1) |\
                                     PIN_PUPDR_FLOATING(GPIOB_PIN14) |      \
                                     PIN_PUPDR_PULLUP(GPIOB_PIN15))
#define VAL_GPIOB_ODR               (PIN_ODR_HIGH(GPIOB_ADC1_IN8) |         \
                                     PIN_ODR_HIGH(GPIOB_ADC1_IN9) |         \
                                     PIN_ODR_HIGH(GPIOB_ETH_RMII_INT) |     \
                                     PIN_ODR_HIGH(GPIOB_SPI1_SCK) |         \
                                     PIN_ODR_HIGH(GPIOB_SPI1_MISO) |        \
                                     PIN_ODR_HIGH(GPIOB_SPI1_MOSI) |        \
                                     PIN_ODR_HIGH(GPIOB_TX1) |              \
                                     PIN_ODR_HIGH(GPIOB_RX1) |              \
                                     PIN_ODR_LOW(GPIOB_RELAY_2) |           \
                                     PIN_ODR_LOW(GPIOB_RELAY_1) |           \
                                     PIN_ODR_HIGH(GPIOB_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOB_ETH_RMII_TXEN) |    \
                                     PIN_ODR_HIGH(GPIOB_ETH_RMII_TXD0) |    \
                                     PIN_ODR_HIGH(GPIOB_ETH_RMII_TXD1) |    \
                                     PIN_ODR_HIGH(GPIOB_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOB_PIN15))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_ADC1_IN8, 0U) |      \
                                     PIN_AFIO_AF(GPIOB_ADC1_IN9, 0U) |      \
                                     PIN_AFIO_AF(GPIOB_ETH_RMII_INT, 0U) |  \
                                     PIN_AFIO_AF(GPIOB_SPI1_SCK, 5U) |      \
                                     PIN_AFIO_AF(GPIOB_SPI1_MISO, 5U) |     \
                                     PIN_AFIO_AF(GPIOB_SPI1_MOSI, 5U) |     \
                                     PIN_AFIO_AF(GPIOB_TX1, 7U) |           \
                                     PIN_AFIO_AF(GPIOB_RX1, 7U))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_RELAY_2, 0U) |       \
                                     PIN_AFIO_AF(GPIOB_RELAY_1, 0U) |       \
                                     PIN_AFIO_AF(GPIOB_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_ETH_RMII_TXEN, 11U) |\
                                     PIN_AFIO_AF(GPIOB_ETH_RMII_TXD0, 11U) |\
                                     PIN_AFIO_AF(GPIOB_ETH_RMII_TXD1, 11U) |\
                                     PIN_AFIO_AF(GPIOB_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_PIN15, 0U))

/*
 * GPIOC setup:
 *
 * PC0  - ADC1_IN10                 (analog).
 * PC1  - ETH_RMII_MDC              (alternate 11).
 * PC2  - ADC1_IN12                 (analog).
 * PC3  - ADC1_IN13                 (analog).
 * PC4  - ETH_RMII_RXD0             (alternate 11).
 * PC5  - ETH_RMII_RXD1             (alternate 11).
 * PC6  - TX6                       (alternate 8).
 * PC7  - RX6                       (alternate 8).
 * PC8  - HEARTBEAT                 (output pushpull maximum).
 * PC9  - PIN9                      (input floating).
 * PC10 - SPI3_SCK                  (alternate 6).
 * PC11 - SPI3_MISO                 (alternate 6).
 * PC12 - SPI3_MOSI                 (alternate 6).
 * PC13 - BUTTON_PC13               (input pulldown).
 * PC14 - PIN14                     (input pullup).
 * PC15 - PIN15                     (input pullup).
 */
#define VAL_GPIOC_MODER             (PIN_MODE_ANALOG(GPIOC_ADC1_IN10) |     \
                                     PIN_MODE_ALTERNATE(GPIOC_ETH_RMII_MDC) |\
                                     PIN_MODE_ANALOG(GPIOC_ADC1_IN12) |     \
                                     PIN_MODE_ANALOG(GPIOC_ADC1_IN13) |     \
                                     PIN_MODE_ALTERNATE(GPIOC_ETH_RMII_RXD0) |\
                                     PIN_MODE_ALTERNATE(GPIOC_ETH_RMII_RXD1) |\
                                     PIN_MODE_ALTERNATE(GPIOC_TX6) |        \
                                     PIN_MODE_ALTERNATE(GPIOC_RX6) |        \
                                     PIN_MODE_OUTPUT(GPIOC_HEARTBEAT) |     \
                                     PIN_MODE_INPUT(GPIOC_PIN9) |           \
                                     PIN_MODE_ALTERNATE(GPIOC_SPI3_SCK) |   \
                                     PIN_MODE_ALTERNATE(GPIOC_SPI3_MISO) |  \
                                     PIN_MODE_ALTERNATE(GPIOC_SPI3_MOSI) |  \
                                     PIN_MODE_INPUT(GPIOC_BUTTON_PC13) |    \
                                     PIN_MODE_INPUT(GPIOC_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOC_PIN15))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOC_ADC1_IN10) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_ETH_RMII_MDC) |\
                                     PIN_OTYPE_PUSHPULL(GPIOC_ADC1_IN12) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_ADC1_IN13) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_ETH_RMII_RXD0) |\
                                     PIN_OTYPE_PUSHPULL(GPIOC_ETH_RMII_RXD1) |\
                                     PIN_OTYPE_PUSHPULL(GPIOC_TX6) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOC_RX6) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOC_HEARTBEAT) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SPI3_SCK) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SPI3_MISO) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SPI3_MOSI) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_BUTTON_PC13) |\
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN15))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_HIGH(GPIOC_ADC1_IN10) |     \
                                     PIN_OSPEED_HIGH(GPIOC_ETH_RMII_MDC) |  \
                                     PIN_OSPEED_HIGH(GPIOC_ADC1_IN12) |     \
                                     PIN_OSPEED_HIGH(GPIOC_ADC1_IN13) |     \
                                     PIN_OSPEED_HIGH(GPIOC_ETH_RMII_RXD0) | \
                                     PIN_OSPEED_HIGH(GPIOC_ETH_RMII_RXD1) | \
                                     PIN_OSPEED_HIGH(GPIOC_TX6) |           \
                                     PIN_OSPEED_HIGH(GPIOC_RX6) |           \
                                     PIN_OSPEED_HIGH(GPIOC_HEARTBEAT) |     \
                                     PIN_OSPEED_HIGH(GPIOC_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOC_SPI3_SCK) |      \
                                     PIN_OSPEED_HIGH(GPIOC_SPI3_MISO) |     \
                                     PIN_OSPEED_HIGH(GPIOC_SPI3_MOSI) |     \
                                     PIN_OSPEED_HIGH(GPIOC_BUTTON_PC13) |   \
                                     PIN_OSPEED_HIGH(GPIOC_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOC_PIN15))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_FLOATING(GPIOC_ADC1_IN10) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_ETH_RMII_MDC) |\
                                     PIN_PUPDR_FLOATING(GPIOC_ADC1_IN12) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_ADC1_IN13) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_ETH_RMII_RXD0) |\
                                     PIN_PUPDR_FLOATING(GPIOC_ETH_RMII_RXD1) |\
                                     PIN_PUPDR_PULLUP(GPIOC_TX6) |          \
                                     PIN_PUPDR_FLOATING(GPIOC_RX6) |        \
                                     PIN_PUPDR_FLOATING(GPIOC_HEARTBEAT) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOC_SPI3_SCK) |   \
                                     PIN_PUPDR_FLOATING(GPIOC_SPI3_MISO) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_SPI3_MOSI) |  \
                                     PIN_PUPDR_PULLDOWN(GPIOC_BUTTON_PC13) |\
                                     PIN_PUPDR_PULLUP(GPIOC_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN15))
#define VAL_GPIOC_ODR               (PIN_ODR_HIGH(GPIOC_ADC1_IN10) |        \
                                     PIN_ODR_HIGH(GPIOC_ETH_RMII_MDC) |     \
                                     PIN_ODR_HIGH(GPIOC_ADC1_IN12) |        \
                                     PIN_ODR_HIGH(GPIOC_ADC1_IN13) |        \
                                     PIN_ODR_HIGH(GPIOC_ETH_RMII_RXD0) |    \
                                     PIN_ODR_HIGH(GPIOC_ETH_RMII_RXD1) |    \
                                     PIN_ODR_HIGH(GPIOC_TX6) |              \
                                     PIN_ODR_HIGH(GPIOC_RX6) |              \
                                     PIN_ODR_LOW(GPIOC_HEARTBEAT) |         \
                                     PIN_ODR_HIGH(GPIOC_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOC_SPI3_SCK) |         \
                                     PIN_ODR_HIGH(GPIOC_SPI3_MISO) |        \
                                     PIN_ODR_HIGH(GPIOC_SPI3_MOSI) |        \
                                     PIN_ODR_HIGH(GPIOC_BUTTON_PC13) |      \
                                     PIN_ODR_HIGH(GPIOC_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOC_PIN15))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOC_ADC1_IN10, 0U) |     \
                                     PIN_AFIO_AF(GPIOC_ETH_RMII_MDC, 11U) | \
                                     PIN_AFIO_AF(GPIOC_ADC1_IN12, 0U) |     \
                                     PIN_AFIO_AF(GPIOC_ADC1_IN13, 0U) |     \
                                     PIN_AFIO_AF(GPIOC_ETH_RMII_RXD0, 11U) |\
                                     PIN_AFIO_AF(GPIOC_ETH_RMII_RXD1, 11U) |\
                                     PIN_AFIO_AF(GPIOC_TX6, 8U) |           \
                                     PIN_AFIO_AF(GPIOC_RX6, 8U))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_HEARTBEAT, 0U) |     \
                                     PIN_AFIO_AF(GPIOC_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_SPI3_SCK, 6U) |      \
                                     PIN_AFIO_AF(GPIOC_SPI3_MISO, 6U) |     \
                                     PIN_AFIO_AF(GPIOC_SPI3_MOSI, 6U) |     \
                                     PIN_AFIO_AF(GPIOC_BUTTON_PC13, 0U) |   \
                                     PIN_AFIO_AF(GPIOC_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_PIN15, 0U))

/*
 * GPIOD setup:
 *
 * PD0  - SPI3_CS                   (output pushpull maximum).
 * PD1  - PIN1                      (input pullup).
 * PD2  - PIN2                      (input pullup).
 * PD3  - RADIO_IRQ                 (input floating).
 * PD4  - USART2_DE                 (output pushpull maximum).
 * PD5  - TX2                       (alternate 7).
 * PD6  - RX2                       (alternate 7).
 * PD7  - SPI1_CS                   (output pushpull maximum).
 * PD8  - TX3                       (alternate 7).
 * PD9  - RX3                       (alternate 7).
 * PD10 - AC_OFF                    (input floating).
 * PD11 - BAT_OK                    (input floating).
 * PD12 - PIN12                     (input floating).
 * PD13 - GSM_STATUS                (input floating).
 * PD14 - GSM_PWRKEY                (output pushpull maximum).
 * PD15 - PIN15                     (input floating).
 */
#define VAL_GPIOD_MODER             (PIN_MODE_OUTPUT(GPIOD_SPI3_CS) |       \
                                     PIN_MODE_INPUT(GPIOD_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOD_RADIO_IRQ) |      \
                                     PIN_MODE_OUTPUT(GPIOD_USART2_DE) |     \
                                     PIN_MODE_ALTERNATE(GPIOD_TX2) |        \
                                     PIN_MODE_ALTERNATE(GPIOD_RX2) |        \
                                     PIN_MODE_OUTPUT(GPIOD_SPI1_CS) |       \
                                     PIN_MODE_ALTERNATE(GPIOD_TX3) |        \
                                     PIN_MODE_ALTERNATE(GPIOD_RX3) |        \
                                     PIN_MODE_INPUT(GPIOD_AC_OFF) |         \
                                     PIN_MODE_INPUT(GPIOD_BAT_OK) |         \
                                     PIN_MODE_INPUT(GPIOD_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOD_GSM_STATUS) |     \
                                     PIN_MODE_OUTPUT(GPIOD_GSM_PWRKEY) |    \
                                     PIN_MODE_INPUT(GPIOD_PIN15))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOD_SPI3_CS) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_RADIO_IRQ) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOD_USART2_DE) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOD_TX2) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOD_RX2) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOD_SPI1_CS) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOD_TX3) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOD_RX3) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOD_AC_OFF) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOD_BAT_OK) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_GSM_STATUS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_GSM_PWRKEY) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN15))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_HIGH(GPIOD_SPI3_CS) |       \
                                     PIN_OSPEED_HIGH(GPIOD_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOD_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOD_RADIO_IRQ) |     \
                                     PIN_OSPEED_HIGH(GPIOD_USART2_DE) |     \
                                     PIN_OSPEED_HIGH(GPIOD_TX2) |           \
                                     PIN_OSPEED_HIGH(GPIOD_RX2) |           \
                                     PIN_OSPEED_HIGH(GPIOD_SPI1_CS) |       \
                                     PIN_OSPEED_HIGH(GPIOD_TX3) |           \
                                     PIN_OSPEED_HIGH(GPIOD_RX3) |           \
                                     PIN_OSPEED_HIGH(GPIOD_AC_OFF) |        \
                                     PIN_OSPEED_HIGH(GPIOD_BAT_OK) |        \
                                     PIN_OSPEED_HIGH(GPIOD_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOD_GSM_STATUS) |    \
                                     PIN_OSPEED_HIGH(GPIOD_GSM_PWRKEY) |    \
                                     PIN_OSPEED_HIGH(GPIOD_PIN15))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_FLOATING(GPIOD_SPI3_CS) |    \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN1) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN2) |         \
                                     PIN_PUPDR_FLOATING(GPIOD_RADIO_IRQ) |  \
                                     PIN_PUPDR_FLOATING(GPIOD_USART2_DE) |  \
                                     PIN_PUPDR_PULLUP(GPIOD_TX2) |          \
                                     PIN_PUPDR_PULLUP(GPIOD_RX2) |          \
                                     PIN_PUPDR_FLOATING(GPIOD_SPI1_CS) |    \
                                     PIN_PUPDR_PULLUP(GPIOD_TX3) |          \
                                     PIN_PUPDR_PULLUP(GPIOD_RX3) |          \
                                     PIN_PUPDR_FLOATING(GPIOD_AC_OFF) |     \
                                     PIN_PUPDR_FLOATING(GPIOD_BAT_OK) |     \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOD_GSM_STATUS) | \
                                     PIN_PUPDR_FLOATING(GPIOD_GSM_PWRKEY) | \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN15))
#define VAL_GPIOD_ODR               (PIN_ODR_HIGH(GPIOD_SPI3_CS) |          \
                                     PIN_ODR_HIGH(GPIOD_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOD_RADIO_IRQ) |        \
                                     PIN_ODR_LOW(GPIOD_USART2_DE) |         \
                                     PIN_ODR_HIGH(GPIOD_TX2) |              \
                                     PIN_ODR_HIGH(GPIOD_RX2) |              \
                                     PIN_ODR_HIGH(GPIOD_SPI1_CS) |          \
                                     PIN_ODR_HIGH(GPIOD_TX3) |              \
                                     PIN_ODR_HIGH(GPIOD_RX3) |              \
                                     PIN_ODR_HIGH(GPIOD_AC_OFF) |           \
                                     PIN_ODR_HIGH(GPIOD_BAT_OK) |           \
                                     PIN_ODR_LOW(GPIOD_PIN12) |             \
                                     PIN_ODR_LOW(GPIOD_GSM_STATUS) |        \
                                     PIN_ODR_LOW(GPIOD_GSM_PWRKEY) |        \
                                     PIN_ODR_LOW(GPIOD_PIN15))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIOD_SPI3_CS, 0U) |       \
                                     PIN_AFIO_AF(GPIOD_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_RADIO_IRQ, 0U) |     \
                                     PIN_AFIO_AF(GPIOD_USART2_DE, 0U) |     \
                                     PIN_AFIO_AF(GPIOD_TX2, 7U) |           \
                                     PIN_AFIO_AF(GPIOD_RX2, 7U) |           \
                                     PIN_AFIO_AF(GPIOD_SPI1_CS, 0U))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIOD_TX3, 7U) |           \
                                     PIN_AFIO_AF(GPIOD_RX3, 7U) |           \
                                     PIN_AFIO_AF(GPIOD_AC_OFF, 0U) |        \
                                     PIN_AFIO_AF(GPIOD_BAT_OK, 0U) |        \
                                     PIN_AFIO_AF(GPIOD_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_GSM_STATUS, 0U) |    \
                                     PIN_AFIO_AF(GPIOD_GSM_PWRKEY, 0U) |    \
                                     PIN_AFIO_AF(GPIOD_PIN15, 0U))

/*
 * GPIOE setup:
 *
 * PE0  - PIN0                      (input floating).
 * PE1  - PIN1                      (input floating).
 * PE2  - UART1                     (input floating).
 * PE3  - BLUE_LED                  (output pushpull maximum).
 * PE4  - PIN4                      (input floating).
 * PE5  - PIN5                      (input floating).
 * PE6  - PIN6                      (input floating).
 * PE7  - PIN7                      (input floating).
 * PE8  - PIN8                      (input floating).
 * PE9  - DIN_BOX                   (input floating).
 * PE10 - PIN10                     (input floating).
 * PE11 - PIN11                     (input floating).
 * PE12 - ETH_RESET                 (output pushpull maximum).
 * PE13 - PIN13                     (input floating).
 * PE14 - PIN14                     (input floating).
 * PE15 - PIN15                     (input floating).
 */
#define VAL_GPIOE_MODER             (PIN_MODE_INPUT(GPIOE_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOE_UART1) |          \
                                     PIN_MODE_OUTPUT(GPIOE_BLUE_LED) |      \
                                     PIN_MODE_INPUT(GPIOE_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOE_DIN_BOX) |        \
                                     PIN_MODE_INPUT(GPIOE_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOE_PIN11) |          \
                                     PIN_MODE_OUTPUT(GPIOE_ETH_RESET) |     \
                                     PIN_MODE_INPUT(GPIOE_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOE_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOE_PIN15))
#define VAL_GPIOE_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOE_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_UART1) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_BLUE_LED) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_DIN_BOX) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_ETH_RESET) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN15))
#define VAL_GPIOE_OSPEEDR           (PIN_OSPEED_HIGH(GPIOE_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOE_UART1) |         \
                                     PIN_OSPEED_HIGH(GPIOE_BLUE_LED) |      \
                                     PIN_OSPEED_HIGH(GPIOE_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOE_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOE_DIN_BOX) |       \
                                     PIN_OSPEED_HIGH(GPIOE_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOE_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOE_ETH_RESET) |     \
                                     PIN_OSPEED_HIGH(GPIOE_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOE_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOE_PIN15))
#define VAL_GPIOE_PUPDR             (PIN_PUPDR_FLOATING(GPIOE_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_UART1) |      \
                                     PIN_PUPDR_FLOATING(GPIOE_BLUE_LED) |   \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOE_DIN_BOX) |    \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOE_ETH_RESET) |  \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN15))
#define VAL_GPIOE_ODR               (PIN_ODR_HIGH(GPIOE_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOE_UART1) |            \
                                     PIN_ODR_HIGH(GPIOE_BLUE_LED) |         \
                                     PIN_ODR_HIGH(GPIOE_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOE_DIN_BOX) |          \
                                     PIN_ODR_HIGH(GPIOE_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOE_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOE_ETH_RESET) |        \
                                     PIN_ODR_HIGH(GPIOE_PIN13) |            \
                                     PIN_ODR_LOW(GPIOE_PIN14) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN15))
#define VAL_GPIOE_AFRL              (PIN_AFIO_AF(GPIOE_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_UART1, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_BLUE_LED, 0U) |      \
                                     PIN_AFIO_AF(GPIOE_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN7, 0U))
#define VAL_GPIOE_AFRH              (PIN_AFIO_AF(GPIOE_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_DIN_BOX, 0U) |       \
                                     PIN_AFIO_AF(GPIOE_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_ETH_RESET, 0U) |     \
                                     PIN_AFIO_AF(GPIOE_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN15, 0U))

/*
 * GPIOF setup:
 *
 * PF0  - PIN0                      (input floating).
 * PF1  - PIN1                      (input floating).
 * PF2  - PIN2                      (input floating).
 * PF3  - PIN3                      (input floating).
 * PF4  - PIN4                      (input floating).
 * PF5  - PIN5                      (input floating).
 * PF6  - PIN6                      (input floating).
 * PF7  - PIN7                      (input floating).
 * PF8  - PIN8                      (input floating).
 * PF9  - PIN9                      (input floating).
 * PF10 - PIN10                     (input floating).
 * PF11 - PIN11                     (input floating).
 * PF12 - PIN12                     (input floating).
 * PF13 - PIN13                     (input floating).
 * PF14 - PIN14                     (input floating).
 * PF15 - PIN15                     (input floating).
 */
#define VAL_GPIOF_MODER             (PIN_MODE_INPUT(GPIOF_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN15))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOF_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN15))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_HIGH(GPIOF_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOF_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOF_PIN15))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_FLOATING(GPIOF_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN15))
#define VAL_GPIOF_ODR               (PIN_ODR_HIGH(GPIOF_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN15))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIOF_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN7, 0U))
#define VAL_GPIOF_AFRH              (PIN_AFIO_AF(GPIOF_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN15, 0U))

/*
 * GPIOG setup:
 *
 * PG0  - PIN0                      (input floating).
 * PG1  - PIN1                      (input floating).
 * PG2  - PIN2                      (input floating).
 * PG3  - PIN3                      (input floating).
 * PG4  - PIN4                      (input floating).
 * PG5  - PIN5                      (input floating).
 * PG6  - PIN6                      (input floating).
 * PG7  - PIN7                      (input floating).
 * PG8  - PIN8                      (input floating).
 * PG9  - PIN9                      (input floating).
 * PG10 - PIN10                     (input floating).
 * PG11 - PIN11                     (input floating).
 * PG12 - PIN12                     (input floating).
 * PG13 - PIN13                     (input floating).
 * PG14 - PIN14                     (input floating).
 * PG15 - PIN15                     (input floating).
 */
#define VAL_GPIOG_MODER             (PIN_MODE_INPUT(GPIOG_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOG_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOG_PIN15))
#define VAL_GPIOG_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOG_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN15))
#define VAL_GPIOG_OSPEEDR           (PIN_OSPEED_HIGH(GPIOG_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOG_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOG_PIN15))
#define VAL_GPIOG_PUPDR             (PIN_PUPDR_FLOATING(GPIOG_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN15))
#define VAL_GPIOG_ODR               (PIN_ODR_HIGH(GPIOG_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOG_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOG_PIN15))
#define VAL_GPIOG_AFRL              (PIN_AFIO_AF(GPIOG_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN7, 0U))
#define VAL_GPIOG_AFRH              (PIN_AFIO_AF(GPIOG_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN15, 0U))

/*
 * GPIOH setup:
 *
 * PH0  - OSC_IN                    (input floating).
 * PH1  - OSC_OUT                   (input floating).
 * PH2  - PIN2                      (input floating).
 * PH3  - PIN3                      (input floating).
 * PH4  - PIN4                      (input floating).
 * PH5  - PIN5                      (input floating).
 * PH6  - PIN6                      (input floating).
 * PH7  - PIN7                      (input floating).
 * PH8  - PIN8                      (input floating).
 * PH9  - PIN9                      (input floating).
 * PH10 - PIN10                     (input floating).
 * PH11 - PIN11                     (input floating).
 * PH12 - PIN12                     (input floating).
 * PH13 - PIN13                     (input floating).
 * PH14 - PIN14                     (input floating).
 * PH15 - PIN15                     (input floating).
 */
#define VAL_GPIOH_MODER             (PIN_MODE_INPUT(GPIOH_OSC_IN) |         \
                                     PIN_MODE_INPUT(GPIOH_OSC_OUT) |        \
                                     PIN_MODE_INPUT(GPIOH_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOH_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOH_PIN15))
#define VAL_GPIOH_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOH_OSC_IN) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOH_OSC_OUT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN15))
#define VAL_GPIOH_OSPEEDR           (PIN_OSPEED_HIGH(GPIOH_OSC_IN) |        \
                                     PIN_OSPEED_HIGH(GPIOH_OSC_OUT) |       \
                                     PIN_OSPEED_HIGH(GPIOH_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOH_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOH_PIN15))
#define VAL_GPIOH_PUPDR             (PIN_PUPDR_FLOATING(GPIOH_OSC_IN) |     \
                                     PIN_PUPDR_FLOATING(GPIOH_OSC_OUT) |    \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN15))
#define VAL_GPIOH_ODR               (PIN_ODR_HIGH(GPIOH_OSC_IN) |           \
                                     PIN_ODR_HIGH(GPIOH_OSC_OUT) |          \
                                     PIN_ODR_HIGH(GPIOH_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOH_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOH_PIN15))
#define VAL_GPIOH_AFRL              (PIN_AFIO_AF(GPIOH_OSC_IN, 0U) |        \
                                     PIN_AFIO_AF(GPIOH_OSC_OUT, 0U) |       \
                                     PIN_AFIO_AF(GPIOH_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN7, 0U))
#define VAL_GPIOH_AFRH              (PIN_AFIO_AF(GPIOH_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN15, 0U))

/*
 * GPIOI setup:
 *
 * PI0  - PIN0                      (input floating).
 * PI1  - PIN1                      (input floating).
 * PI2  - PIN2                      (input floating).
 * PI3  - PIN3                      (input floating).
 * PI4  - PIN4                      (input floating).
 * PI5  - PIN5                      (input floating).
 * PI6  - PIN6                      (input floating).
 * PI7  - PIN7                      (input floating).
 * PI8  - PIN8                      (input floating).
 * PI9  - PIN9                      (input floating).
 * PI10 - PIN10                     (input floating).
 * PI11 - PIN11                     (input floating).
 * PI12 - PIN12                     (input floating).
 * PI13 - PIN13                     (input floating).
 * PI14 - PIN14                     (input floating).
 * PI15 - PIN15                     (input floating).
 */
#define VAL_GPIOI_MODER             (PIN_MODE_INPUT(GPIOI_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOI_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOI_PIN15))
#define VAL_GPIOI_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOI_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN15))
#define VAL_GPIOI_OSPEEDR           (PIN_OSPEED_HIGH(GPIOI_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOI_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOI_PIN15))
#define VAL_GPIOI_PUPDR             (PIN_PUPDR_FLOATING(GPIOI_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN15))
#define VAL_GPIOI_ODR               (PIN_ODR_HIGH(GPIOI_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOI_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOI_PIN15))
#define VAL_GPIOI_AFRL              (PIN_AFIO_AF(GPIOI_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN7, 0U))
#define VAL_GPIOI_AFRH              (PIN_AFIO_AF(GPIOI_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN15, 0U))

/*
 * GPIOJ setup:
 *
 * PJ0  - PIN0                      (input floating).
 * PJ1  - PIN1                      (input floating).
 * PJ2  - PIN2                      (input floating).
 * PJ3  - PIN3                      (input floating).
 * PJ4  - PIN4                      (input floating).
 * PJ5  - PIN5                      (input floating).
 * PJ6  - PIN6                      (input floating).
 * PJ7  - PIN7                      (input floating).
 * PJ8  - PIN8                      (input floating).
 * PJ9  - PIN9                      (input floating).
 * PJ10 - PIN10                     (input floating).
 * PJ11 - PIN11                     (input floating).
 * PJ12 - PIN12                     (input floating).
 * PJ13 - PIN13                     (input floating).
 * PJ14 - PIN14                     (input floating).
 * PJ15 - PIN15                     (input floating).
 */
#define VAL_GPIOJ_MODER             (PIN_MODE_INPUT(GPIOJ_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOJ_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOJ_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOJ_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOJ_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOJ_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOJ_PIN15))
#define VAL_GPIOJ_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOJ_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN15))
#define VAL_GPIOJ_OSPEEDR           (PIN_OSPEED_HIGH(GPIOJ_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOJ_PIN15))
#define VAL_GPIOJ_PUPDR             (PIN_PUPDR_FLOATING(GPIOJ_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN15))
#define VAL_GPIOJ_ODR               (PIN_ODR_HIGH(GPIOJ_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOJ_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOJ_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOJ_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOJ_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOJ_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOJ_PIN15))
#define VAL_GPIOJ_AFRL              (PIN_AFIO_AF(GPIOJ_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN7, 0U))
#define VAL_GPIOJ_AFRH              (PIN_AFIO_AF(GPIOJ_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN15, 0U))

/*
 * GPIOK setup:
 *
 * PK0  - PIN0                      (input floating).
 * PK1  - PIN1                      (input floating).
 * PK2  - PIN2                      (input floating).
 * PK3  - PIN3                      (input floating).
 * PK4  - PIN4                      (input floating).
 * PK5  - PIN5                      (input floating).
 * PK6  - PIN6                      (input floating).
 * PK7  - PIN7                      (input floating).
 * PK8  - PIN8                      (input floating).
 * PK9  - PIN9                      (input floating).
 * PK10 - PIN10                     (input floating).
 * PK11 - PIN11                     (input floating).
 * PK12 - PIN12                     (input floating).
 * PK13 - PIN13                     (input floating).
 * PK14 - PIN14                     (input floating).
 * PK15 - PIN15                     (input floating).
 */
#define VAL_GPIOK_MODER             (PIN_MODE_INPUT(GPIOK_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOK_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOK_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOK_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOK_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOK_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOK_PIN15))
#define VAL_GPIOK_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOK_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN15))
#define VAL_GPIOK_OSPEEDR           (PIN_OSPEED_HIGH(GPIOK_PIN0) |          \
                                     PIN_OSPEED_HIGH(GPIOK_PIN1) |          \
                                     PIN_OSPEED_HIGH(GPIOK_PIN2) |          \
                                     PIN_OSPEED_HIGH(GPIOK_PIN3) |          \
                                     PIN_OSPEED_HIGH(GPIOK_PIN4) |          \
                                     PIN_OSPEED_HIGH(GPIOK_PIN5) |          \
                                     PIN_OSPEED_HIGH(GPIOK_PIN6) |          \
                                     PIN_OSPEED_HIGH(GPIOK_PIN7) |          \
                                     PIN_OSPEED_HIGH(GPIOK_PIN8) |          \
                                     PIN_OSPEED_HIGH(GPIOK_PIN9) |          \
                                     PIN_OSPEED_HIGH(GPIOK_PIN10) |         \
                                     PIN_OSPEED_HIGH(GPIOK_PIN11) |         \
                                     PIN_OSPEED_HIGH(GPIOK_PIN12) |         \
                                     PIN_OSPEED_HIGH(GPIOK_PIN13) |         \
                                     PIN_OSPEED_HIGH(GPIOK_PIN14) |         \
                                     PIN_OSPEED_HIGH(GPIOK_PIN15))
#define VAL_GPIOK_PUPDR             (PIN_PUPDR_FLOATING(GPIOK_PIN0) |       \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN1) |       \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN2) |       \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN3) |       \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN4) |       \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN5) |       \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN6) |       \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN7) |       \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN8) |       \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN9) |       \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN10) |      \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN11) |      \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN12) |      \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN13) |      \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN14) |      \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN15))
#define VAL_GPIOK_ODR               (PIN_ODR_HIGH(GPIOK_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOK_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOK_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOK_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOK_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOK_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOK_PIN15))
#define VAL_GPIOK_AFRL              (PIN_AFIO_AF(GPIOK_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN7, 0U))
#define VAL_GPIOK_AFRH              (PIN_AFIO_AF(GPIOK_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN15, 0U))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
