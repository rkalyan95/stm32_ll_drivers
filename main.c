/*led is on pb13*/
#include <stdint.h>

#include <stm32l433xx.h>
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"
#include "stm32l433_ll_gpio_cfg.h"
#include "stm32l433_ll_gpio.h"


portpintconfigs_t led_pin = {
    .port = GPIO_PORT_B,
    .pin = 13,
    .pinType = GPIO_OUTPUT,
    .pullconfig = GPIO_PULL_DOWN,
    .outputpushpull = GPIO_OTYPE_PUSHPULL,
    .alternate_functionality = AF_NONE,
};



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

   Gpio_ConfigPin(&led_pin);

   while(1)
    {
        Gpio_TogglePin(led_pin.port,led_pin.pin);

        for(uint32_t i=0;i<100000;i++);
    }


}
