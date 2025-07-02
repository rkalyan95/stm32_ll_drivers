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

   Gpio_ConfigPin(&Stm32NucleoConfigsPortB[0]);
   Gpio_ConfigPin(&Stm32NucleoConfigsPortB[1]);

   Gpio_ClearPin(Stm32NucleoConfigsPortB[0].port,Stm32NucleoConfigsPortB[0].pin);
   Gpio_ClearPin(Stm32NucleoConfigsPortB[1].port,Stm32NucleoConfigsPortB[1].pin);
    
   while(1)
    {
        Gpio_TogglePin(Stm32NucleoConfigsPortB[0].port,Stm32NucleoConfigsPortB[0].pin);
        Gpio_TogglePin(Stm32NucleoConfigsPortB[1].port,Stm32NucleoConfigsPortB[1].pin);
        for(uint32_t i=0;i<100000;i++);
    }


}
