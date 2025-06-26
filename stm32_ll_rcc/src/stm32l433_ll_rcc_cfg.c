
#include "stm32l433_ll_rcc_cfg.h"

volatile RCC_CR_Reg_t RCC_CR_Reg = {
                                .B.MSION=RCC_CR_SETTING_MSION_ON,
                                .B.MSIPLLEN=RCC_CR_SETTING_MSIPLLEN_ON,
                                .B.MSIRGSEL=RCC_CR_SETTING_MSIRGSEL_CR,
                                .B.HSION=RCC_CR_SETTING_HSION_ON,
                                .B.HSIKERON=RCC_CR_SETTING_HSIKERON_OFF,
                                .B.HSIASFS=RCC_CR_SETTING_HSIASFS_ON
                                
};

volatile RCC_CFGR_Reg_t RCC_CFGR_Reg = {
        .B.MCOSEL = RCC_CFGR_MCOSEL_SYSCLK_SETTING,
        .B.MCOPRE = RCC_CFGR_MCOPRE_DIV1_SETTING,
};

volatile RCC_AHB2ENR_Reg_t RCC_AHB2ENR_Reg = {
                                     .B.GPIOA_EN = RCC_AHB2ENR_GPIOA_EN_ON,
                                     .B.GPIOB_EN = RCC_AHB2ENR_GPIOB_EN_ON,
                                     .B.GPIOC_EN = RCC_AHB2ENR_GPIOC_EN_OFF,
                                     .B.GPIOD_EN = RCC_AHB2ENR_GPIOD_EN_OFF,
                                     .B.GPIOE_EN = RCC_AHB2ENR_GPIOE_EN_OFF,
                                     .B.ADC_EN = RCC_AHB2ENR_ADC_EN_OFF,
                                     .B.AES_EN = RCC_AHB2ENR_AES_EN_OFF,
                                     .B.RNG_B = RCC_AHB2ENR_RNG_B_OFF
                                    };

volatile RCC_BDCR_Reg_t RCC_BDCR_Reg = {
        .B.LSEON = RCC_BDCR_LSEON_ON,
        .B.LSCOSEL = RCC_BDCR_LSCOSEL_LSE,
        .B.LSCOEN = RCC_BDCR_LSECSSON_ON,
};
