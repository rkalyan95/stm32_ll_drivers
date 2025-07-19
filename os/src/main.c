/*led is on pb13*/
#include <stdint.h>

#include <stm32l433xx.h>
#include "core_cm4.h"
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

    if(InitAllClocks()!=ERR_SUCCESS)
    {
        while(1);
    }

    Gpio_ConfigAllPorts();

     __enable_irq();
    NVIC_SetPriority(EXTI15_10_IRQn, 47);
    NVIC_EnableIRQ(EXTI15_10_IRQn);      // Enable the interrupt in the NVIC
    level =  false;
    Gpio_SetLevel(led_pin.port,led_pin.pin,HIGH);

    while(1)
    {
        Gpio_SetLevel(led_pin.port,led_pin.pin,level);
    }


}

