
#include "stm32l433_ll_rcc_cfg.h"

RCC_TypeDef *RCC_ClockConfigs = ((RCC_TypeDef *) RCC_BASE);

volatile RCC_AHB2ENR_Reg_t RCC_AHB2ENR_Reg = {
                                     .B.GPIOA_EN = 0,
                                     .B.GPIOB_EN = 1,
                                     .B.GPIOC_EN = 0,
                                     .B.GPIOD_EN = 0,
                                     .B.GPIOE_EN = 0,
                                     .B.ADC_EN = 0,
                                     .B.AES_EN = 0,
                                     .B.RNG_B = 0
                                    };
volatile RCC_CR_Reg_t RCC_CR_Reg = {
                                .B.MSION=1,
                                .B.MSIPLLEN=1,
                                .B.MSIRGSEL=1,
                                .B.HSION=1,
                                .B.HSIKERON=0,
                                .B.HSIASFS=1,
                                
};
void Rcc_Init(void)
{
        RCC_ClockConfigs->AHB2ENR = RCC_AHB2ENR_Reg.U;
}