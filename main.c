/*led is on pb13*/
#include <stdint.h>

#include <stm32l433xx.h>
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"
#include "stm32l433_ll_gpio_cfg.h"
#include "stm32l433_ll_gpio.h"


void main(void)
{

   Rcc_InitSystemClocks();

   Gpio_ConfigAllPorts();

   while(1)
    {
        Gpio_TogglePin(led_pin.port,led_pin.pin);
        Gpio_TogglePin(nucleo_pb0_pin.port,nucleo_pb0_pin.pin);
        Gpio_TogglePin(logic_pin.port,logic_pin.pin);
        for(uint32_t i=0;i<100000;i++);
    }


}

