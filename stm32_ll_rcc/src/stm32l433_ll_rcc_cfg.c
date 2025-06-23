
#include "stm32l433_ll_rcc_cfg.h"

RCC_TypeDef *RCC_ClockConfigs = ((RCC_TypeDef *) RCC_BASE);

RCC_AHB2ENR_Reg_t RCC_AHB2ENR_Reg = {
                                     .B.GPIOA_EN = 0,
                                     .B.GPIOB_EN = 1,
                                     .B.GPIOC_EN = 0,
                                     .B.GPIOD_EN = 0,
                                     .B.GPIOE_EN = 0,
                                     .B.ADC_EN = 0,
                                     .B.AES_EN = 0,
                                     .B.RNG_B = 0
                                    };
void Rcc_Init(void)
{
        RCC_ClockConfigs->AHB2ENR = RCC_AHB2ENR_Reg.U;
}