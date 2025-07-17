#ifndef STM32_SYSCFG_CFG_H
#define STM32_SYSCFG_CFG_H

#include "stm32l433_ll_gpio.h"
#include "stm32l433_ll_gpio_cfg.h"
void Gpio_Interrupts_Configure(gpioport_t port , pinnumber_t pin);

#endif