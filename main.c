/*led is on pb13*/
#include <stdint.h>

#include <stm32l433xx.h>
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"
#include "stm32l433_ll_gpio_cfg.h"
#include "stm32l433_ll_gpio.h"


GPIO_TypeDef *GpioB_Configs = ((GPIO_TypeDef *) GPIOB_BASE);
GPIO_TypeDef *GpioA_Configs = ((GPIO_TypeDef *) GPIOA_BASE);

/* Implement Rcc_Init with argument pointer to something that contains the data
   regarding which clocks to initialise 
   example Rcc_Init(const Rcc_t *Rcc_Config)

   This will help end users to configure the RCC as per their needs
   similarly for Gpio_Init
   example Gpio_Init(const Gpio_t *Gpio_Config)
   */
void main(void)
{

   Rcc_InitSystemClocks();
   Gpio_Init();
   while(1)
    {
        Gpio_TogglePin();
        for(uint32_t i=0;i<100000;i++);
    }


}
