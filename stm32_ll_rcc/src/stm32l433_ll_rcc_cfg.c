
#include "stm32l433_ll_rcc_cfg.h"

RCC_TypeDef *RCC_ClockConfigs = ((RCC_TypeDef *) RCC_BASE);

volatile RCC_AHB2ENR_Reg_t RCC_AHB2ENR_Reg = {
                                     .B.GPIOA_EN = 1,
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
                                .B.HSIASFS=1
                                
};

volatile RCC_CFGR_Reg_t RCC_CFGR_Reg = {
        .B.MCOSEL = LSECLK,
        .B.MCOPRE = DIV1,
};

volatile RCC_BDCR_Reg_t RCC_BDCR_Reg = {
        .B.LSEON = 1,
        .B.LSCOSEL = 1,
        .B.LSCOEN = 1,
};

void Rcc_Init(void)
{
        RCC_ClockConfigs->AHB2ENR = RCC_AHB2ENR_Reg.U;
        RCC_ClockConfigs->CFGR = RCC_CFGR_Reg.U;
        RCC_ClockConfigs->BDCR = RCC_BDCR_Reg.U;
}