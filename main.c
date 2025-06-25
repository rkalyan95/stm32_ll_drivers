/*led is on pb13*/
#include <stdint.h>

#include <stm32l433xx.h>
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"

#define LED_PIN 13


GPIO_TypeDef *GpioB_Configs = ((GPIO_TypeDef *) GPIOB_BASE);
GPIO_TypeDef *GpioA_Configs = ((GPIO_TypeDef *) GPIOA_BASE);

void main(void)
{

    Rcc_Init();

    GpioB_Configs->MODER &= ~(1<<27);
    GpioB_Configs->MODER |= (1<<26);

    GpioA_Configs->MODER &= ~(1<<16);
    GpioA_Configs->MODER |= (1<<17);
    while(1)
    {
        GpioB_Configs->ODR ^= (1<<LED_PIN);
        for(uint32_t i=0;i<100000;i++);
    }


}
