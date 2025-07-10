/*led is on pb13*/
#include <stdint.h>

#include <stm32l433xx.h>
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"
#include "stm32l433_ll_gpio_cfg.h"
#include "stm32l433_ll_gpio.h"

static void delayrndom(void)
{
    for(uint32_t i=0;i<100000;i++);
}


void main(void)
{

    InitAllClocks();
   Gpio_ConfigAllPorts();

   while(1)
    {
        Gpio_SetLevel(led_pin.port,led_pin.pin,HIGH);
        delayrndom();
        Gpio_SetLevel(led_pin.port,led_pin.pin,LOW);
        delayrndom();
    }


}

