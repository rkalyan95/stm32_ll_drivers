/*led is on pb13*/
#include <stdint.h>

#include <stm32l433xx.h>
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"
#include "stm32l433_ll_gpio_cfg.h"
#include "stm32l433_ll_gpio.h"


GPIO_TypeDef *GpioB_Configs = ((GPIO_TypeDef *) GPIOB_BASE);
GPIO_TypeDef *GpioA_Configs = ((GPIO_TypeDef *) GPIOA_BASE);


void main(void)
{

   Rcc_Init();
   Gpio_Init();
   while(1)
    {
        Gpio_TogglePin();
        for(uint32_t i=0;i<100000;i++);
    }


}
