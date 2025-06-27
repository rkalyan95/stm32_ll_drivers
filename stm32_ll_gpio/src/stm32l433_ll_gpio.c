#include "stm32l433_ll_gpio.h"
#include "stm32l433_ll_gpio_cfg.h"



void Gpio_Init(void)
{
    GPIO_TypeDef *GpioB_Configs = ((GPIO_TypeDef *) GPIOB_BASE);
    GPIO_TypeDef *GpioA_Configs = ((GPIO_TypeDef *) GPIOA_BASE);
    GpioA_Configs->MODER = GPIOA_MODER_Reg.U;
    GpioB_Configs->MODER = GPIOB_MODER_Reg.U;
}

void Gpio_TogglePin(void)
{
    GPIO_TypeDef *GpioB_Configs = ((GPIO_TypeDef *) GPIOB_BASE);
    GpioB_Configs->ODR ^= (1<<LED_PIN);
}