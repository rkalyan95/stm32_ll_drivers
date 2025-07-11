/*led is on pb13*/
#include <stdint.h>

#include <stm32l433xx.h>
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"
#include "stm32l433_ll_gpio_cfg.h"
#include "stm32l433_ll_gpio.h"

static void delayrndom(uint32_t dly)
{
    for(uint32_t i=0;i<dly;i++)
    {
        __NOP();
    }
}


void main(void)
{

    if(InitAllClocks())
    {
        Gpio_ConfigAllPorts();
    }

   while(1)
    {
        if(Gpio_GetPin(button_pin.port,button_pin.pin))
        {
            Gpio_SetLevel(led_pin.port,led_pin.pin,HIGH);
        }
        else
        {
            Gpio_SetLevel(led_pin.port,led_pin.pin,LOW);
        }
       // delayrndom(80000);
        
       // delayrndom(80000);
    
    }


}

