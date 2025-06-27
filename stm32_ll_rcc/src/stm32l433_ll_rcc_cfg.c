
#include "stm32l433_ll_rcc_cfg.h"

#if 0
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
#endif
volatile RCC_AHB2ENR_Reg_t RCC_AHB2ENR_Reg = {
                                     .B.GPIOB_EN = RCC_AHB2ENR_GPIOB_EN_ON,
                                    };

#if 0
volatile RCC_AHB1ENR_Reg_t RCC_AHB1ENR_Reg = {
        .B.DMA1_EN = RCC_AHB1ENR_DMA1_EN_OFF,
        .B.DMA2_EN = RCC_AHB1ENR_DMA2_EN_ON,
        .B.FLASH_EN = RCC_AHB1ENR_FLASH_EN_ON,
        .B.CRC_EN = RCC_AHB1ENR_CRC_EN_ON,
        .B.TSC_EN = RCC_AHB1ENR_TSC_EN_ON,

};


volatile RCC_BDCR_Reg_t RCC_BDCR_Reg = {
        .B.LSEON = RCC_BDCR_LSEON_ON,
        .B.LSCOSEL = RCC_BDCR_LSCOSEL_LSE,
        .B.LSCOEN = RCC_BDCR_LSECSSON_ON,
};
#endif