/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define TARGET_BOARD_IDENTIFIER "MOTO" // MotoLab
#define USE_CLI

#define CONFIG_FASTLOOP_PREFERRED_ACC 0
 
#define LED0    PB5 // Blue LEDs - PB5
//#define LED1    PB9 // Green LEDs - PB9

#define BEEPER      PA0
#define BEEPER_INVERTED

#define USABLE_TIMER_CHANNEL_COUNT 9

// MPU6050 interrupts
#define USE_EXTI
#define MPU_INT_EXTI PA15
#define EXTI15_10_CALLBACK_HANDLER_COUNT 1 // MPU data ready
#define USE_MPU_DATA_READY_SIGNAL
//#define ENSURE_MPU_DATA_READY_IS_LOW

#define GYRO
#define ACC

#define USE_GYRO_MPU6050
#define GYRO_MPU6050_ALIGN CW180_DEG

#define USE_ACC_MPU6050

#define ACC_MPU6050_ALIGN CW180_DEG

#define USE_GYRO_SPI_MPU6000
#define GYRO_MPU6000_ALIGN CW180_DEG
#define USE_ACC_SPI_MPU6000
#define ACC_MPU6000_ALIGN CW180_DEG

#define MPU6000_CS_GPIO GPIOB
#define MPU6000_CS_PIN PB12
#define MPU6000_SPI_INSTANCE SPI2

//#define BARO
//#define USE_BARO_MS5611

//#define MAG
//#define USE_MAG_HMC5883

#define USE_VCP
#define USE_USART1
#define USE_USART2
#define USE_USART3
#define SERIAL_PORT_COUNT 4

#define UART1_TX_PIN        GPIO_Pin_6 // PB6
#define UART1_RX_PIN        GPIO_Pin_7 // PB7
#define UART1_GPIO          GPIOB
#define UART1_GPIO_AF       GPIO_AF_7
#define UART1_TX_PINSOURCE  GPIO_PinSource6
#define UART1_RX_PINSOURCE  GPIO_PinSource7

#define UART2_TX_PIN        GPIO_Pin_3 // PB3
#define UART2_RX_PIN        GPIO_Pin_4 // PB4
#define UART2_GPIO          GPIOB
#define UART2_GPIO_AF       GPIO_AF_7
#define UART2_TX_PINSOURCE  GPIO_PinSource3
#define UART2_RX_PINSOURCE  GPIO_PinSource4

#define UART3_TX_PIN        GPIO_Pin_10 // PB10 (AF7)
#define UART3_RX_PIN        GPIO_Pin_11 // PB11 (AF7)
#define UART3_GPIO_AF       GPIO_AF_7
#define UART3_GPIO          GPIOB
#define UART3_TX_PINSOURCE  GPIO_PinSource10
#define UART3_RX_PINSOURCE  GPIO_PinSource11

#define USE_I2C
#define I2C_DEVICE (I2CDEV_2) // SDA (PA10/AF4), SCL (PA9/AF4)

#define I2C2_SCL_GPIO        GPIOA
#define I2C2_SCL_GPIO_AF     GPIO_AF_4
#define I2C2_SCL_PIN         PA9
#define I2C2_SCL_PIN_SOURCE  GPIO_PinSource9
#define I2C2_SCL_CLK_SOURCE  RCC_AHBPeriph_GPIOA
#define I2C2_SDA_GPIO        GPIOA
#define I2C2_SDA_GPIO_AF     GPIO_AF_4
#define I2C2_SDA_PIN         PA10
#define I2C2_SDA_PIN_SOURCE  GPIO_PinSource10
#define I2C2_SDA_CLK_SOURCE  RCC_AHBPeriph_GPIOA

#define USE_SPI
#define USE_SPI_DEVICE_2

#define M25P16_CS_PIN         PB12
#define M25P16_SPI_INSTANCE   SPI2

//#define SENSORS_SET (SENSOR_ACC | SENSOR_BARO | SENSOR_GPS | SENSOR_MAG)
#define SENSORS_SET (SENSOR_ACC)

#undef GPS
#define DISPLAY
#define USE_FLASHFS
#define USE_FLASH_M25P16

#define USE_ADC
#define BOARD_HAS_VOLTAGE_DIVIDER

#define ADC_INSTANCE                ADC2
#define ADC_DMA_CHANNEL             DMA2_Channel1
#define ADC_AHB_PERIPHERAL          RCC_AHBPeriph_DMA2

#define VBAT_ADC_GPIO               GPIOA
#define VBAT_ADC_GPIO_PIN           GPIO_Pin_5
#define VBAT_ADC_CHANNEL            ADC_Channel_2

//#define CURRENT_METER_ADC_GPIO      GPIOA
//#define CURRENT_METER_ADC_GPIO_PIN  GPIO_Pin_5
//#define CURRENT_METER_ADC_CHANNEL   ADC_Channel_2

#define RSSI_ADC_GPIO               GPIOB
#define RSSI_ADC_GPIO_PIN           GPIO_Pin_2
#define RSSI_ADC_CHANNEL            ADC_Channel_12

#define LED_STRIP
#if 1
#define LED_STRIP_TIMER TIM16

#define USE_LED_STRIP_ON_DMA1_CHANNEL3
#define WS2811_GPIO                     GPIOB
#define WS2811_GPIO_AHB_PERIPHERAL      RCC_AHBPeriph_GPIOB
#define WS2811_GPIO_AF                  GPIO_AF_1
#define WS2811_PIN                      GPIO_Pin_8 // TIM16_CH1
#define WS2811_PIN_SOURCE               GPIO_PinSource8
#define WS2811_TIMER                    TIM16
#define WS2811_TIMER_APB2_PERIPHERAL    RCC_APB2Periph_TIM16
#define WS2811_DMA_CHANNEL              DMA1_Channel3
#define WS2811_IRQ                      DMA1_Channel3_IRQn
#define WS2811_DMA_TC_FLAG              DMA1_FLAG_TC3
#define WS2811_DMA_HANDLER_IDENTIFER    DMA1_CH3_HANDLER
#endif

#if 0
// Alternate LED strip pin
// FIXME DMA IRQ Transfer Complete is never called because the  TIM17_DMA_RMP needs to be set in SYSCFG_CFGR1
#define LED_STRIP_TIMER TIM17

#define USE_LED_STRIP_ON_DMA1_CHANNEL7
#define WS2811_GPIO                     GPIOA
#define WS2811_GPIO_AHB_PERIPHERAL      RCC_AHBPeriph_GPIOA
#define WS2811_GPIO_AF                  GPIO_AF_1
#define WS2811_PIN                      GPIO_Pin_7 // TIM17_CH1
#define WS2811_PIN_SOURCE               GPIO_PinSource7
#define WS2811_TIMER                    TIM17
#define WS2811_TIMER_APB2_PERIPHERAL    RCC_APB2Periph_TIM17
#define WS2811_DMA_CHANNEL              DMA1_Channel7
#define WS2811_IRQ                      DMA1_Channel7_IRQn
#endif


#define SPEKTRUM_BIND
// USART2, PB4
#define BIND_PIN PB4

#define USE_SERIAL_4WAY_BLHELI_INTERFACE

// IO - stm32f303cc in 48pin package
#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC (BIT(13)|BIT(14)|BIT(15))
// #define TARGET_IO_PORTF (BIT(0)|BIT(1))
// !!TODO - check the following line is correct
#define TARGET_IO_PORTF (BIT(0)|BIT(1)|BIT(3)|BIT(4))

#define USED_TIMERS  (TIM_N(1) | TIM_N(2) | TIM_N(3) | TIM_N(15) | TIM_N(17))

#define TIMER_APB2_PERIPHERALS (RCC_APB2Periph_TIM1 | RCC_APB2Periph_TIM15 | RCC_APB2Periph_TIM17)
#define TIMER_APB1_PERIPHERALS (RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3)
#define TIMER_AHB_PERIPHERALS (RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB)
