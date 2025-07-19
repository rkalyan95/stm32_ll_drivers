#ifndef STM32_LL_EXTI_H
#define STM32_LL_EXTI_H

#include <stdbool.h>
#include <stdint.h>
#include <stm32l433xx.h>

typedef enum
{
    EXTI_GPIO_0,
    EXTI_GPIO_1,
    EXTI_GPIO_2,
    EXTI_GPIO_3,
    EXTI_GPIO_4,
    EXTI_GPIO_5,
    EXTI_GPIO_6,
    EXTI_GPIO_7,
    EXTI_GPIO_8,
    EXTI_GPIO_9,
    EXTI_GPIO_10,
    EXTI_GPIO_11,
    EXTI_GPIO_12,
    EXTI_GPIO_13,
    EXTI_GPIO_14,
    EXTI_GPIO_15,
    EXTI_PVD_16,
    EXTI_USB_FS_WAKEUP_17,
    EXTI_RTC_ALARMS_18,
    EXTI_RTC_TAMPER_TS_CSS_19,
    EXTI_RTC_WAKEUP_20,
    EXTI_COMP1_OUT_21,
    EXTI_COMP2_OUT_22,
    EXTI_I2C1_WAKEUP_23,
    EXTI_I2C2_WAKEUP_24,
    EXTI_I2C3_WAKEUP_25,
    EXTI_USART1_WAKEUP_26,
    EXTI_USART2_WAKEUP_27,
    EXTI_USART3_WAKEUP_28,
    EXTI_UART4_WAKEUP_29,
    EXTI_LPUART1_WAKEUP_31,
    EXTI_LPTIM1_32,
    EXTI_LPTIM2_33,
    EXTI_SWPMI1_WAKEUP_34,
    EXTI_PVM1_WAKEUP_35,
    EXTI_PVM3_WAKEUP_37,
    EXTI_PVM4_WAKEUP_38,
    EXTI_LCD_WAKEUP_39,
    EXTI_I2C4_WAKEUP_40,
} Exti_lines_t;

typedef enum
{
    EXTI_FAILED,
   EXTI_SUCCESS
}ErrorExti_t;


ErrorExti_t ConfigureInterruptMask(Exti_lines_t exti_line, bool En);
ErrorExti_t ConfigureEventMask(Exti_lines_t exti_line, bool En);
ErrorExti_t ConfigureRisingEdgeInterrupt(Exti_lines_t exti_line, bool En);
ErrorExti_t ConfigureFallingEdgeInterrupt(Exti_lines_t exti_line, bool En);
ErrorExti_t ConfigureSoftwareInterrupt(Exti_lines_t exti_line, bool En);
ErrorExti_t ClearPendingInterrupt(Exti_lines_t exti_line);
uint8_t IsInterruptServiced(Exti_lines_t exti_line);


#endif