#ifndef STM32L433_LL_GPIO_CFG_H
#define STM32L433_LL_GPIO_CFG_H

#include <stdint.h>
#include <stm32l433xx.h>
#include <stm32l433_ll_gpio.h>

#define MAX_PIN_CONFIGS    16

extern const portpintconfigs_t logic_pin;
extern const portpintconfigs_t nucleo_pb0_pin;
extern const portpintconfigs_t led_pin;

extern const portpintconfigs_t Stm32NucleoConfigsPortB[];

static void Gpio_InitialiseAllPinsPort(const portpintconfigs_t *configsgpio , uint32_t config_count);
void Gpio_ConfigAllPorts(void);
#endif // STM32L433_LL_GPIO_CFG_H