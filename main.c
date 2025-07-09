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
   /*
   RCC_EnableAhb2Peripheral(AHB2_GPIOA);
   RCC_EnableAhb2Peripheral(AHB2_GPIOB);
   RCC_EnableAhb2Peripheral(AHB2_GPIOC);
   RCC_EnableAhb2Peripheral(AHB2_GPIOD);
   RCC_EnableAhb2Peripheral(AHB2_GPIOE);
   RCC_EnableAhb2Peripheral(AHB2_GPIOH);
*/
   InitializeAllPeripheralsClocks();

   RCC_SetSystemClockSource(SYSCLK_MSI);
   RCC_MsiRangeSelect(MSI_RANGESRC_CR);
   RCC_ConfigureMCO(MCO_MSI,MCO_DIV1);
   RCC_EnableMSI(RCC_MSISRANGE_4MHZ_SETTING);

    Gpio_ConfigAllPorts();
   while(1)
    {
        Gpio_SetLevel(led_pin.port,led_pin.pin,HIGH);
        delayrndom();
        Gpio_SetLevel(led_pin.port,led_pin.pin,LOW);
        delayrndom();
    }


}

