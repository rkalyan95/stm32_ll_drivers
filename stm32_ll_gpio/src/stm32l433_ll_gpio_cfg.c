#include "stm32l433_ll_gpio_cfg.h"

//Warning : DO not change the Pa13 and Pa14 configs please , because they are used for debugger.

volatile GPIOA_MODER_Reg_t GPIOA_MODER_Reg = {

    .B.GPIOA_MODE8 = GPIO_MODE_ALTERNATE, // Example: Set pin 8 as alternate function
    .B.GPIOA_MODE13 = GPIO_MODE_ALTERNATE,
    .B.GPIOA_MODE14 = GPIO_MODE_ALTERNATE,
};

volatile GPIOB_MODER_Reg_t GPIOB_MODER_Reg = {
    .B.GPIOB_MODE13 = GPIO_MODE_OUTPUT, // Example: Set pin 13 as output
};

volatile GPIOA_AFRH_Reg_t GPIOA_AFRH_Reg = {
    .B.GPIOA_AFRH5 = GPIOx_AFRH0,
    .B.GPIOA_AFRH6 = GPIOx_AFRH0, // Example: Set pin 13 and 14 to AF0
};