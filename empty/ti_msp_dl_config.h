/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_SERVO */
#define PWM_SERVO_INST                                                     TIMG6
#define PWM_SERVO_INST_IRQHandler                               TIMG6_IRQHandler
#define PWM_SERVO_INST_INT_IRQN                                 (TIMG6_INT_IRQn)
#define PWM_SERVO_INST_CLK_FREQ                                           100000
/* GPIO defines for channel 0 */
#define GPIO_PWM_SERVO_C0_PORT                                             GPIOA
#define GPIO_PWM_SERVO_C0_PIN                                     DL_GPIO_PIN_21
#define GPIO_PWM_SERVO_C0_IOMUX                                  (IOMUX_PINCM46)
#define GPIO_PWM_SERVO_C0_IOMUX_FUNC                 IOMUX_PINCM46_PF_TIMG6_CCP0
#define GPIO_PWM_SERVO_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_SERVO_C1_PORT                                             GPIOA
#define GPIO_PWM_SERVO_C1_PIN                                     DL_GPIO_PIN_22
#define GPIO_PWM_SERVO_C1_IOMUX                                  (IOMUX_PINCM47)
#define GPIO_PWM_SERVO_C1_IOMUX_FUNC                 IOMUX_PINCM47_PF_TIMG6_CCP1
#define GPIO_PWM_SERVO_C1_IDX                                DL_TIMER_CC_1_INDEX

/* Defines for PWM_MOTOR */
#define PWM_MOTOR_INST                                                     TIMG0
#define PWM_MOTOR_INST_IRQHandler                               TIMG0_IRQHandler
#define PWM_MOTOR_INST_INT_IRQN                                 (TIMG0_INT_IRQn)
#define PWM_MOTOR_INST_CLK_FREQ                                         32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTOR_C0_PORT                                             GPIOA
#define GPIO_PWM_MOTOR_C0_PIN                                     DL_GPIO_PIN_12
#define GPIO_PWM_MOTOR_C0_IOMUX                                  (IOMUX_PINCM34)
#define GPIO_PWM_MOTOR_C0_IOMUX_FUNC                 IOMUX_PINCM34_PF_TIMG0_CCP0
#define GPIO_PWM_MOTOR_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTOR_C1_PORT                                             GPIOA
#define GPIO_PWM_MOTOR_C1_PIN                                     DL_GPIO_PIN_13
#define GPIO_PWM_MOTOR_C1_IOMUX                                  (IOMUX_PINCM35)
#define GPIO_PWM_MOTOR_C1_IOMUX_FUNC                 IOMUX_PINCM35_PF_TIMG0_CCP1
#define GPIO_PWM_MOTOR_C1_IDX                                DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG7)
#define TIMER_0_INST_IRQHandler                                 TIMG7_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG7_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                          (1249U)




/* Defines for I2C_0 */
#define I2C_0_INST                                                          I2C0
#define I2C_0_INST_IRQHandler                                    I2C0_IRQHandler
#define I2C_0_INST_INT_IRQN                                        I2C0_INT_IRQn
#define I2C_0_BUS_SPEED_HZ                                                400000
#define GPIO_I2C_0_SDA_PORT                                                GPIOA
#define GPIO_I2C_0_SDA_PIN                                         DL_GPIO_PIN_0
#define GPIO_I2C_0_IOMUX_SDA                                      (IOMUX_PINCM1)
#define GPIO_I2C_0_IOMUX_SDA_FUNC                       IOMUX_PINCM1_PF_I2C0_SDA
#define GPIO_I2C_0_SCL_PORT                                                GPIOA
#define GPIO_I2C_0_SCL_PIN                                         DL_GPIO_PIN_1
#define GPIO_I2C_0_IOMUX_SCL                                      (IOMUX_PINCM2)
#define GPIO_I2C_0_IOMUX_SCL_FUNC                       IOMUX_PINCM2_PF_I2C0_SCL


/* Defines for UART_BLUETOOTH */
#define UART_BLUETOOTH_INST                                                UART2
#define UART_BLUETOOTH_INST_IRQHandler                          UART2_IRQHandler
#define UART_BLUETOOTH_INST_INT_IRQN                              UART2_INT_IRQn
#define GPIO_UART_BLUETOOTH_RX_PORT                                        GPIOB
#define GPIO_UART_BLUETOOTH_TX_PORT                                        GPIOB
#define GPIO_UART_BLUETOOTH_RX_PIN                                DL_GPIO_PIN_16
#define GPIO_UART_BLUETOOTH_TX_PIN                                DL_GPIO_PIN_17
#define GPIO_UART_BLUETOOTH_IOMUX_RX                             (IOMUX_PINCM33)
#define GPIO_UART_BLUETOOTH_IOMUX_TX                             (IOMUX_PINCM43)
#define GPIO_UART_BLUETOOTH_IOMUX_RX_FUNC               IOMUX_PINCM33_PF_UART2_RX
#define GPIO_UART_BLUETOOTH_IOMUX_TX_FUNC               IOMUX_PINCM43_PF_UART2_TX
#define UART_BLUETOOTH_BAUD_RATE                                          (9600)
#define UART_BLUETOOTH_IBRD_32_MHZ_9600_BAUD                               (208)
#define UART_BLUETOOTH_FBRD_32_MHZ_9600_BAUD                                (21)
/* Defines for UART_VISION */
#define UART_VISION_INST                                                   UART0
#define UART_VISION_INST_IRQHandler                             UART0_IRQHandler
#define UART_VISION_INST_INT_IRQN                                 UART0_INT_IRQn
#define GPIO_UART_VISION_RX_PORT                                           GPIOA
#define GPIO_UART_VISION_TX_PORT                                           GPIOA
#define GPIO_UART_VISION_RX_PIN                                   DL_GPIO_PIN_11
#define GPIO_UART_VISION_TX_PIN                                   DL_GPIO_PIN_10
#define GPIO_UART_VISION_IOMUX_RX                                (IOMUX_PINCM22)
#define GPIO_UART_VISION_IOMUX_TX                                (IOMUX_PINCM21)
#define GPIO_UART_VISION_IOMUX_RX_FUNC                 IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_VISION_IOMUX_TX_FUNC                 IOMUX_PINCM21_PF_UART0_TX
#define UART_VISION_BAUD_RATE                                           (115200)
#define UART_VISION_IBRD_32_MHZ_115200_BAUD                                 (17)
#define UART_VISION_FBRD_32_MHZ_115200_BAUD                                 (23)





/* Port definition for Pin Group LED */
#define LED_PORT                                                         (GPIOA)

/* Defines for PIN_16: GPIOA.16 with pinCMx 38 on package pin 9 */
#define LED_PIN_16_PIN                                          (DL_GPIO_PIN_16)
#define LED_PIN_16_IOMUX                                         (IOMUX_PINCM38)
/* Defines for AIN1: GPIOA.25 with pinCMx 55 on package pin 26 */
#define MOTOR_AIN1_PORT                                                  (GPIOA)
#define MOTOR_AIN1_PIN                                          (DL_GPIO_PIN_25)
#define MOTOR_AIN1_IOMUX                                         (IOMUX_PINCM55)
/* Defines for AIN2: GPIOA.26 with pinCMx 59 on package pin 30 */
#define MOTOR_AIN2_PORT                                                  (GPIOA)
#define MOTOR_AIN2_PIN                                          (DL_GPIO_PIN_26)
#define MOTOR_AIN2_IOMUX                                         (IOMUX_PINCM59)
/* Defines for BIN1: GPIOA.23 with pinCMx 53 on package pin 24 */
#define MOTOR_BIN1_PORT                                                  (GPIOA)
#define MOTOR_BIN1_PIN                                          (DL_GPIO_PIN_23)
#define MOTOR_BIN1_IOMUX                                         (IOMUX_PINCM53)
/* Defines for BIN2: GPIOB.24 with pinCMx 52 on package pin 23 */
#define MOTOR_BIN2_PORT                                                  (GPIOB)
#define MOTOR_BIN2_PIN                                          (DL_GPIO_PIN_24)
#define MOTOR_BIN2_IOMUX                                         (IOMUX_PINCM52)
/* Defines for STBY: GPIOA.24 with pinCMx 54 on package pin 25 */
#define MOTOR_STBY_PORT                                                  (GPIOA)
#define MOTOR_STBY_PIN                                          (DL_GPIO_PIN_24)
#define MOTOR_STBY_IOMUX                                         (IOMUX_PINCM54)
/* Port definition for Pin Group Grayscale_Sensor */
#define Grayscale_Sensor_PORT                                            (GPIOB)

/* Defines for L1: GPIOB.8 with pinCMx 25 on package pin 60 */
#define Grayscale_Sensor_L1_PIN                                  (DL_GPIO_PIN_8)
#define Grayscale_Sensor_L1_IOMUX                                (IOMUX_PINCM25)
/* Defines for M: GPIOB.7 with pinCMx 24 on package pin 59 */
#define Grayscale_Sensor_M_PIN                                   (DL_GPIO_PIN_7)
#define Grayscale_Sensor_M_IOMUX                                 (IOMUX_PINCM24)
/* Defines for R1: GPIOB.15 with pinCMx 32 on package pin 3 */
#define Grayscale_Sensor_R1_PIN                                 (DL_GPIO_PIN_15)
#define Grayscale_Sensor_R1_IOMUX                                (IOMUX_PINCM32)
/* Port definition for Pin Group GPIO_MOTOR */
#define GPIO_MOTOR_PORT                                                  (GPIOA)

/* Defines for PIN_1: GPIOA.17 with pinCMx 39 on package pin 10 */
// pins affected by this interrupt request:["PIN_1","PIN_0"]
#define GPIO_MOTOR_INT_IRQN                                     (GPIOA_INT_IRQn)
#define GPIO_MOTOR_INT_IIDX                     (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_MOTOR_PIN_1_IIDX                               (DL_GPIO_IIDX_DIO17)
#define GPIO_MOTOR_PIN_1_PIN                                    (DL_GPIO_PIN_17)
#define GPIO_MOTOR_PIN_1_IOMUX                                   (IOMUX_PINCM39)
/* Defines for PIN_0: GPIOA.8 with pinCMx 19 on package pin 54 */
#define GPIO_MOTOR_PIN_0_IIDX                                (DL_GPIO_IIDX_DIO8)
#define GPIO_MOTOR_PIN_0_PIN                                     (DL_GPIO_PIN_8)
#define GPIO_MOTOR_PIN_0_IOMUX                                   (IOMUX_PINCM19)
/* Port definition for Pin Group GPIO_GRP_0 */
#define GPIO_GRP_0_PORT                                                  (GPIOA)

/* Defines for PIN_2: GPIOA.7 with pinCMx 14 on package pin 49 */
#define GPIO_GRP_0_PIN_2_PIN                                     (DL_GPIO_PIN_7)
#define GPIO_GRP_0_PIN_2_IOMUX                                   (IOMUX_PINCM14)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_SERVO_init(void);
void SYSCFG_DL_PWM_MOTOR_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_I2C_0_init(void);
void SYSCFG_DL_UART_BLUETOOTH_init(void);
void SYSCFG_DL_UART_VISION_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
