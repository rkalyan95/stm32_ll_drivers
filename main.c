/*led is on pb13*/
#include <stdint.h>

#include <stm32l433xx.h>
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"

#define LED_PIN 13


GPIO_TypeDef *Gpio_Configs = ((GPIO_TypeDef *) GPIOB_BASE);


void main(void)
{

    Rcc_Init();

    Gpio_Configs->MODER &= ~(1<<27);
    Gpio_Configs->MODER |= (1<<26);

    while(1)
    {
        Gpio_Configs->ODR ^= (1<<LED_PIN);
        for(uint32_t i=0;i<100000;i++);
    }


}
