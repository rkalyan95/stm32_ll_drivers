#include "stm32l433_ll_gpio_cfg.h"

volatile GPIOA_MODER_Reg_t GPIOA_MODER_Reg = {

    .B.GPIOA_MODE8 = GPIO_MODE_ALTERNATE, // Example: Set pin 8 as alternate function

};


volatile GPIOB_MODER_Reg_t GPIOB_MODER_Reg = {
    .B.GPIOB_MODE13 = GPIO_MODE_OUTPUT, // Example: Set pin 13 as output
};