
#include "stm32l433_ll_rcc_cfg.h"


volatile RCC_CR_Reg_t RCC_CR_Reg = {
                                .B.MSION=RCC_CR_SETTING_MSION_ON_SETTING,
                                .B.MSIPLLEN=RCC_CR_SETTING_MSIPLLEN_ON_SETTING,
                                .B.MSIRGSEL=RCC_CR_SETTING_MSIRGSEL_CR_SETTING,
                                .B.MSIRANGE=RCC_CR_SETTING_MSIRANGE_4M_SETTING, // 100KHz
                                .B.HSION=RCC_CR_SETTING_HSION_ON_SETTING,
                                .B.HSIKERON=RCC_CR_SETTING_HSIKERON_OFF_SETTING,
                                .B.HSIASFS=RCC_CR_SETTING_HSIASFS_ON_SETTING,
                                .B.HSEON=RCC_CR_SETTING_HSEOSC_ON_SETTING,
                                .B.HSEBYP=RCC_CR_SETTING_HSEBYP_OFF_SETTING,
                                .B.CSSON=RCC_CR_SETTING_CSSON_OFF_SETTING,
                                .B.PLL_ON=RCC_CR_SETTING_PLL_ON_SETTING,
                                .B.PLLSAI1ON=RCC_CR_SETTING_PLLSAI1_ON_SETTING,
                                
};

volatile RCC_CFGR_Reg_t RCC_CFGR_Reg = {
                .B.SW = SW_MSI_SETTING, // Select MSI as system clock
                .B.HPRE = RCC_CFGR_HPRE_DIV1_SETTING, // AHB prescaler set to 1
                .B.PPRE1 = RCC_CFGR_PPRE1_DIV1_SETTING, // AP
                .B.PPRE2 = RCC_CFGR_PPRE2_DIV1_SETTING, // APB2 prescaler set to 1
                .B.STOPWUCK = RCC_CFGR_STOPWUCK_DISABLE_SETTING, // Stop
                .B.MCOSEL = RCC_CFGR_MCOSEL_SYSCLK_SETTING,
                .B.MCOPRE = RCC_CFGR_MCOPRE_DIV1_SETTING,
};

volatile RCC_PLLSAI1CFGR_Reg_t RCC_PLLSAI1CFGR_Reg = {
                .B.PLLSA1N = 8, // PLL multiplication factor set to 8
                .B.PLLSA1PEN = RCC_PLLSAI1CFGR_PLLSAI1PEN_ENABLE_SETTING, // PLL division factor for the main system clock enabled
                .B.PLLSA1P = 1, // PLL division factor for the main system clock set to 2
                .B.PLLSA1QEN = RCC_PLLSAI1CFGR_PLLSAI1QEN_ON_SETTING, // PLL division factor for USB clock enabled
                .B.PLLSA1Q = RCC_PLLSAI1CFGR_PLLSAI1Q_DIV2_SETTING, // PLL division factor for USB clock set to 2
                .B.PLLSA1REN = RCC_PLLSAI1CFGR_PLLSAI1REN_ON_SETTING, // PLL division factor for the main system clock enabled
                .B.PLLSA1R = RCC_PLLSAI1CFGR_PLLSAI1R_DIV2_SETTING, // PLL division factor for the main system clock set to 2
                .B.PLLSA1PDIV = 1, // PLL division factor set to 1
};

volatile RCC_CIER_Reg_t RCC_CIER_Reg = {
                .B.LSIRDYIE = RCC_CIER_LSIRDYIE_DISABLE_SETTING, // LSI ready interrupt disabled
                .B.LSERDYIE = RCC_CIER_LSERDYIE_DISABLE_SETTING, // LSE ready interrupt disabled
                .B.MSIRDYIE = RCC_CIER_MSIRDYIE_DISABLE_SETTING, // MSI ready interrupt disabled
                .B.HSIRDYIE = RCC_CIER_HSIRDYIE_DISABLE_SETTING, // HSI16 ready interrupt disabled
                .B.HSERDYIE = RCC_CIER_HSERDYIE_DISABLE_SETTING, // HSE ready interrupt disabled
                .B.PLLRDYIE = RCC_CIER_PLLRDYIE_DISABLE_SETTING, // PLL ready interrupt disabled
                .B.PLLSAI1RDYIE = RCC_CIER_PLLSAI1RDYIE_DISABLE_SETTING, // PLLSAI1 ready interrupt disabled
                .B.LSECSSIE = RCC_CIER_LSECSSIE_DISABLE_SETTING, // LSE clock security system interrupt disabled
                .B.HSI48RDYIE = RCC_CIER_HSI48RDYIE_DISABLE_SETTING, // HSI48 ready interrupt disabled
};

volatile RCC_CICR_Reg_t RCC_CICR_Reg = {
                .B.LSIRDYC = RCC_CICR_LSIRDYC_NOCLR_SETTING, // LSI ready interrupt not cleared
                .B.LSERDYC = RCC_CICR_LSERDYC_NOCLR_SETTING, // LSE ready interrupt not cleared
                .B.MSIRDYC = RCC_CICR_MSIRDYC_NOCLR_SETTING, // MSI ready interrupt not cleared
                .B.HSIRDYC = RCC_CICR_HSIRDYC_NOCLR_SETTING, // HSI16 ready interrupt not cleared
                .B.HSERDYC = RCC_CICR_HSERDYC_NOCLR_SETTING, // HSE ready interrupt not cleared
                .B.PLLRDYC = RCC_CICR_PLLRDYC_NOCLR_SETTING, // PLL ready interrupt not cleared
                .B.PLLSAI1RDYC = RCC_CICR_PLLSAI1RDYC_NOCLR_SETTING, // PLLSAI1 ready interrupt not cleared
                .B.CSSC = RCC_CICR_CSSC_NOCLR_SETTING, // Clock security system interrupt not cleared
                .B.LSECSSC = RCC_CICR_LSECSSC_NOCLR_SETTING, // LSE clock security system interrupt not cleared
                .B.HSI48RDYC = RCC_CICR_HSI48RDYC_NOCLR_SETTING, // HSI48 ready interrupt not cleared
};

volatile RCC_PLLCFGR_Reg_t RCC_PLLCFGR_Reg = {
                .B.PLLSRC = RCC_PLLCFGR_PLLSRC_MSI_SETTING, // MSI clock selected as PLL source
                .B.PLLM = RCC_PLLCFGR_PLLM_DIV1_SETTING, // Division factor for the main PLL input clock set to 1
                .B.PLLN = 8, // Main PLL multiplication factor set to 8
                .B.PLLEN = RCC_PLLCFGR_PLLEN_ON, // Main PLL enabled
                .B.PLLP = 1, // Main PLL division factor for the main system clock set to 2
                .B.PLLQEN = RCC_PLLCFGR_PLLQEN_ON, // Main PLL division factor for USB clock enabled
                .B.PLLQ = RCC_PLLCFGR_PLLQ_DIV2_SETTING, // Main PLL division factor for USB clock set to 2
                .B.PLL_REN = RCC_PLLCFGR_PLL_REN_ON, // Main PLL division factor for the main system clock enabled
                .B.PLLR = RCC_PLLCFGR_PLLR_DIV2_SETTING, // Main PLL division factor for the main system clock set to 2
                .B.PLLDIV = 1, // Main PLL division factor set to 1
};

volatile RCC_AHB1RSTR_Reg_t RCC_AHB1RSTR_Reg = {
        .B.DMA1RST = RCC_AHB1RSTR_DMA1RST_NO_SETTING, // DMA1 reset not set
        .B.DMA2RST = RCC_AHB1RSTR_DMA2RST_NO_SETTING, // DMA2 reset not set
        .B.FLASHRST = RCC_AHB1RSTR_FLASHRST_NO_SETTING, // Flash memory interface reset not set
        .B.CRCRST = RCC_AHB1RSTR_CRCRST_NO_SETTING, // CRC reset not set
        .B.TSCRST = RCC_AHB1RSTR_TSCRST_NO_SETTING, // Touch sensing controller reset not set
};

volatile RCC_AHB2RSTR_Reg_t RCC_AHB2RSTR_Reg = {
        .B.GPIOARST = RCC_AHB2RSTR_GPIOARST_NO_SETTING, // GPIOA reset not set
        .B.GPIOBRST = RCC_AHB2RSTR_GPIOBRST_NO_SETTING, // GPIOB reset not set
        .B.GPIOCRST = RCC_AHB2RSTR_GPIOCRST_NO_SETTING, // GPIOC reset not set
        .B.GPIODRST = RCC_AHB2RSTR_GPIODRST_NO_SETTING, // GPIOD reset not set
        .B.GPIOERST = RCC_AHB2RSTR_GPIOERST_NO_SETTING, // GPIOE reset not set
        .B.GPIOHRST = RCC_AHB2RSTR_GPIOHRST_NO_SETTING, // GPIOH reset not set
        .B.AESRST = RCC_AHB2RSTR_AESRST_NO_SETTING, // AES reset not set
        .B.RNGRST = RCC_AHB2RSTR_RNGRST_NO_SETTING, // RNG reset not set
};

volatile RCC_AHB3RSTR_Reg_t RCC_AHB3RSTR_Reg = {
        .B.QSPIRST = RCC_AHB3RSTR_QSPIRST_NO_SETTING, // QSPI reset not set
};

volatile RCC_APB1RSTR1_Reg_t RCC_APB1RSTR1_Reg = {
        .B.TIM2RST = RCC_APB1RSTR1_TIM2RST_NO_SETTING, // TIM2 reset not set
        .B.TIM3RST = RCC_APB1RSTR1_TIM3RST_NO_SETTING, // TIM3 reset not set
        .B.TIM6RST = RCC_APB1RSTR1_TIM6RST_NO_SETTING, // TIM6 reset not set
        .B.TIM7RST = RCC_APB1RSTR1_TIM7RST_NO_SETTING, // TIM7 reset not set
        .B.SPI2RST = RCC_APB1RSTR1_SPI2RST_NO_SETTING, // SPI2 reset not set
        .B.SPI3RST = RCC_APB1RSTR1_SPI3RST_NO_SETTING, // SPI3 reset not set
        .B.USART2RST = RCC_APB1RSTR1_USART2RST_NO_SETTING, // USART2 reset not set
        .B.USART3RST = RCC_APB1RSTR1_USART3RST_NO_SETTING, // USART3 reset not set
        .B.UART4RST = RCC_APB1RSTR1_UART4RST_NO_SETTING, // UART4 reset not set
        .B.I2C1RST = RCC_APB1RSTR1_I2C1RST_NO_SETTING, // I2C1 reset not set
        .B.I2C2RST = RCC_APB1RSTR1_I2C2RST_NO_SETTING, // I2C2 reset not set
        .B.I2C3RST = RCC_APB1RSTR1_I2C3RST_NO_SETTING, // I2C3 reset not set
        .B.CRSRST = RCC_APB1RSTR1_CRSRST_NO_SETTING, // Clock recovery system reset not set
        .B.CAN1RST = RCC_APB1RSTR1_CAN1RST_NO_SETTING, // CAN1 reset not set
        .B.USBFSRST = RCC_APB1RSTR1_USBFSRST_NO_SETTING, // USBFS reset not set
        .B.PWRRST = RCC_APB1RSTR1_PWRRST_NO_SETTING, // Power control reset not set
        .B.DACRST = RCC_APB1RSTR1_DACRST_NO_SETTING, // DAC reset not set
        .B.OPAMP1RST = RCC_APB1RSTR1_OPAMP1RST_NO_SETTING, // OPAMP1 reset not set
        .B.LPTIM1RST = RCC_APB1RSTR1_LPTIM1RST_NO_SETTING, // LPTIM1 reset not set

};

volatile RCC_APB1RSTR2_Reg_t RCC_APB1RSTR2_Reg = {
        .B.LPUART1RST = RCC_APB1RSTR2_LPUART1RST_NO_SETTING, // LPUART1 reset not set
        .B.I2C4RST = RCC_APB1RSTR2_I2C4RST_NO_SETTING, // I2C4 reset not set
        .B.SWPMI1RST = RCC_APB1RSTR2_SWPMI1RST_NO_SETTING, // SWPMI1 reset not set
        .B.LPTIM2RST = RCC_APB1RSTR2_LPTIM2RST_NO_SETTING, // LPTIM2 reset not set
};

volatile RCC_APB2RSTR_Reg_t RCC_APB2RSTR_Reg = {
        .B.SYSCFGRST = RCC_APB2RSTR_SYSCFGRST_NO_SETTING, // SYSCFG reset not set
        .B.SDMMCRST = RCC_APB2RSTR_SDMMCRST_NO_SETTING, // SDMMC reset not set
        .B.TIM1RST = RCC_APB2RSTR_TIM1RST_NO_SETTING, // TIM1 reset not set
        .B.SPI1RST = RCC_APB2RSTR_SPI1RST_NO_SETTING, // SPI1 reset not set
        .B.USART1RST = RCC_APB2RSTR_USART1RST_NO_SETTING, // USART1 reset not set
        .B.TIM15RST = RCC_APB2RSTR_TIM15RST_NO_SETTING, // TIM15 reset not set
        .B.TIM16RST = RCC_APB2RSTR_TIM16RST_NO_SETTING, // TIM16 reset not set
        .B.SAI1RST = RCC_APB2RSTR_SA1RST_NO_SETTING, // SAI1 reset not set
        .B.DFSDMRST = RCC_APB2RSTR_DFSDM1RST_NO_SETTING, // DFSDM reset not set

};

volatile RCC_AHB1ENR_Reg_t RCC_AHB1ENR_Reg = {
        .B.DMA1_EN = RCC_AHB1ENR_DMA1_EN_ON_SETTING,
        .B.DMA2_EN = RCC_AHB1ENR_DMA2_EN_ON_SETTING,
        .B.FLASH_EN = RCC_AHB1ENR_FLASH_EN_ON_SETTING,
        .B.CRC_EN = RCC_AHB1ENR_CRC_EN_ON_SETTING,
        .B.TSC_EN = RCC_AHB1ENR_TSC_EN_ON_SETTING,

};

volatile RCC_AHB2ENR_Reg_t RCC_AHB2ENR_Reg = {
                                     .B.GPIOA_EN = RCC_AHB2ENR_GPIOA_EN_ON_SETTING, // gpio A CLOCK DOES NOT WORK , NEED TO CHECK , bricks the sw
                                     .B.GPIOB_EN = RCC_AHB2ENR_GPIOB_EN_ON_SETTING,
                                     .B.GPIOC_EN = RCC_AHB2ENR_GPIOC_EN_ON_SETTING,
                                     .B.GPIOD_EN = RCC_AHB2ENR_GPIOD_EN_ON_SETTING,
                                     .B.GPIOE_EN = RCC_AHB2ENR_GPIOE_EN_ON_SETTING,
                                     .B.GPIOH_EN = RCC_AHB2ENR_GPIOH_EN_ON_SETTING,
                                     .B.ADC_EN = RCC_AHB2ENR_ADC_EN_ON_SETTING,
                                     .B.AES_EN = RCC_AHB2ENR_AES_EN_ON_SETTING,
                                     .B.RNG_B = RCC_AHB2ENR_RNG_B_ON_SETTING,
                                    };


volatile RCC_AHB3ENR_Reg_t RCC_AHB3ENR_Reg = {
        .B.QSPI_EN = RCC_AHB3ENR_QSPI_EN_ON_SETTING, //
};

volatile RCC_APB1ENR1_Reg_t RCC_APB1ENR1_Reg = {
        .B.TIM2EN = RCC_APB1ENR1_TIM2EN_ON_SETTING,
        .B.TIM3EN = RCC_APB1ENR1_TIM3EN_ON_SETTING,
        .B.TIM6EN = RCC_APB1ENR1_TIM6EN_ON_SETTING,
        .B.TIM7EN = RCC_APB1ENR1_TIM7EN_ON_SETTING,
        .B.LCDEN = RCC_APB1ENR1_LCDEN_ON_SETTING,
        .B.RTCAPBEN = RCC_APB1ENR1_RTCAPBEN_ON_SETTING, // RTC APB clock enable
        .B.WWDGEN = RCC_APB1ENR1_WWDGEN_ON_SETTING, // Window watchdog clock enable
        .B.SPI2EN = RCC_APB1ENR1_SPI2EN_ON_SETTING,
        .B.SPI3EN = RCC_APB1ENR1_SPI3EN_ON_SETTING,
        .B.USART2EN = RCC_APB1ENR1_USART2EN_ON_SETTING,
        .B.USART3EN = RCC_APB1ENR1_USART3EN_ON_SETTING,
        .B.UART4EN = RCC_APB1ENR1_UART4EN_ON_SETTING,
        .B.I2C1EN = RCC_APB1ENR1_I2C1EN_ON_SETTING,
        .B.I2C2EN = RCC_APB1ENR1_I2C2EN_ON_SETTING,
        .B.I2C3EN = RCC_APB1ENR1_I2C3EN_ON_SETTING,
        .B.CRSEN = RCC_APB1ENR1_CRSEN_ON_SETTING, //
        .B.CAN1EN = RCC_APB1ENR1_CAN1EN_ON_SETTING, // CAN1 clock enable
        .B.USBFSEN = RCC_APB1ENR1_USBFSEN_ON_SETTING,
        .B.PWREN = RCC_APB1ENR1_PWREN_ON_SETTING, // Power control clock enable
        .B.DACEN = RCC_APB1ENR1_DACEN_ON_SETTING, //
        .B.OPAMPEN = RCC_APB1ENR1_OPAMPEN_ON_SETTING, // OPAMP1 clock enable
        .B.LPTIM1EN = RCC_APB1ENR1_LPTIM1EN_ON_SETTING, // LPTIM1 clock enable
        
};

volatile RCC_APB1ENR2_Reg_t RCC_APB1ENR2_Reg = {
        .B.LPUART1EN = RCC_APB1ENR2_LPUART1EN_ON_SETTING, // LPUART1 clock enable
        .B.I2C4EN = RCC_APB1ENR2_I2C4EN_ON_SETTING, // I2C4 clock enable
        .B.SWPMI1EN = RCC_APB1ENR2_SWPMI1EN_ON_SETTING, // SWPMI1 clock enable
        .B.LPTIM2EN = RCC_APB1ENR2_LPTIM2EN_ON_SETTING, // LPTIM2 clock enable
};
volatile RCC_APB2ENR_Reg_t RCC_APB2ENR_Reg = {
        .B.SYSCFGEN = RCC_APB2ENR_SYSCFGEN_ON_SETTING, // SYSCFG clock enable
        .B.SDMMCEN = RCC_APB2ENR_SDMMCEN_ON_SETTING, // SDMMC clock enable
        .B.TIM1EN = RCC_APB2ENR_TIM1EN_ON_SETTING, // TIM1 clock enable
        .B.SPI1EN = RCC_APB2ENR_SPI1EN_ON_SETTING, // SPI1 clock enable
        .B.USART1EN = RCC_APB2ENR_USART1EN_ON_SETTING, // USART1 clock enable
        .B.TIM15EN = RCC_APB2ENR_TIM15EN_ON_SETTING, // TIM15 clock enable
        .B.TIM16EN = RCC_APB2ENR_TIM16EN_ON_SETTING, // TIM16 clock enable
        .B.SAI1EN = RCC_APB2ENR_SAI1EN_ON_SETTING, // SAI1 clock enable
        .B.DFSDM1EN = RCC_APB2ENR_DFSDM1EN_ON_SETTING, // DFSDM clock enable
        
};

volatile RCC_AHB1SMENR_Reg_t RCC_AHB1SMENR_Reg = {
        .B.DMA1SMEN = RCC_AHB1SMENR_DMA1SMEN_ON_SETTING, // DMA1 clock enable in Sleep mode
        .B.DMA2SMEN = RCC_AHB1SMENR_DMA2SMEN_ON_SETTING, // DMA2 clock enable in Sleep mode
        .B.FLASHSMEN = RCC_AHB1SMENR_FLASHSMEN_ON_SETTING, // Flash memory interface clock enable in Sleep mode
        .B.CRCSMEN = RCC_AHB1SMENR_CRCSMEN_ON_SETTING, // CRC clock enable in Sleep mode
        .B.TSCSMEN = RCC_AHB1SMENR_TSCSMEN_ON_SETTING, // Touch sensing controller clock enable in Sleep mode
};

volatile RCC_AHB2SMENR_Reg_t RCC_AHB2SMENR_Reg = {
        .B.GPIOASMEN = RCC_AHB2SMENR_GPIOASMEN_ON_SETTING, // GPIOA clock enable in Sleep mode
        .B.GPIOBSMEN = RCC_AHB2SMENR_GPIOBSMEN_ON_SETTING, // GPIOB clock enable in Sleep mode
        .B.GPIOCSMEN = RCC_AHB2SMENR_GPIOCSMEN_ON_SETTING, // GPIOC clock enable in Sleep mode
        .B.GPIODSMEN = RCC_AHB2SMENR_GPIODSMEN_ON_SETTING, // GPIOD clock enable in Sleep mode
        .B.GPIOESMEN = RCC_AHB2SMENR_GPIOESMEN_ON_SETTING, // GPIOE clock enable in Sleep mode
        .B.GPIOHSMEN = RCC_AHB2SMENR_GPIOHSMEN_ON_SETTING, // GPIOH clock enable in Sleep mode
        .B.SRAM2SMEN = RCC_AHB2SMENR_SRAM2SMEN_ON_SETTING, // SRAM1 clock enable in Sleep mode
        .B.ADCSMEN = RCC_AHB2SMENR_ADCSMEN_ON_SETTING, // ADC clock enable in Sleep mod
        .B.AESMEN = RCC_AHB2SMENR_AESMEN_ON_SETTING, // AES clock enable in Sleep mode
        .B.RNGSMEN = RCC_AHB2SMENR_RNGSMEN_ON_SETTING, // RNG clock enable in Sleep mode
};

volatile RCC_AHB3SMENR_Reg_t RCC_AHB3SMENR_Reg = {
        .B.QSPISMEN = RCC_AHB3SMENR_QSPISMEN_ON_SETTING, // QSPI clock enable in Sleep mode
};

volatile RCC_APB1SMENR1_Reg_t RCC_APB1SMENR1_Reg = {
        .B.TIM2SMEN = RCC_APB1SMENR1_TIM2SMEN_ON_SETTING, // TIM2 clock enable in Sleep mode
        .B.TIM3SMEN = RCC_APB1SMENR1_TIM3SMEN_ON_SETTING, // TIM3 clock enable in Sleep mode
        .B.TIM6SMEN = RCC_APB1SMENR1_TIM6SMEN_ON_SETTING, // TIM6 clock enable in Sleep mode
        .B.TIM7SMEN = RCC_APB1SMENR1_TIM7SMEN_ON_SETTING, // TIM7 clock enable in Sleep mode
        .B.LCDSMEN = RCC_APB1SMENR1_LCDSMEN_ON_SETTING, // LCDART1 clock enable in Sleep mode
        .B.RTCAPBSMEN = RCC_APB1SMENR1_RTCAPBSMEN_ON_SETTING, // RTC APB clock enable in Sleep mode
        .B.WWDGSMEN = RCC_APB1SMENR1_WWDGSMEN_ON_SETTING, // Window watchdog clock enable in Sleep mode
        .B.SPI2SMEN = RCC_APB1SMENR1_SPI2SMEN_ON_SETTING, // SPI2 clock enable in Sleep mode
        .B.SPI3SMEN = RCC_APB1SMENR1_SPI3SMEN_ON_SETTING, // SPI3 clock enable in Sleep mode
        .B.USART2SMEN = RCC_APB1SMENR1_USART2SMEN_ON_SETTING, // USART2 clock enable in Sleep mode
        .B.USART3SMEN = RCC_APB1SMENR1_USART3SMEN_ON_SETTING, // USART3 clock enable in Sleep mode
        .B.UART4SMEN = RCC_APB1SMENR1_UART4SMEN_ON_SETTING, // UART4 clock enable in Sleep mode
        .B.I2C1SMEN = RCC_APB1SMENR1_I2C1SMEN_ON_SETTING, // I2C1 clock enable in Sleep mode
        .B.I2C2SMEN = RCC_APB1SMENR1_I2C2SMEN_ON_SETTING, // I2C2 clock enable in Sleep mode
        .B.I2C3SMEN = RCC_APB1SMENR1_I2C3SMEN_ON_SETTING, // I2C3 clock enable in Sleep mode
        .B.CRSSMEN = RCC_APB1SMENR1_CRSSMEN_ON_SETTING, // Clock recovery system clock enable in Sleep mode
        .B.CAN1SMEN = RCC_APB1SMENR1_CAN1SMEN_ON_SETTING, // CAN1 clock enable in Sleep mode
        .B.USBFSSMEN = RCC_APB1SMENR1_USBFSSMEN_ON_SETTING, // USBFS clock enable in Sleep mode
        .B.PWRSMEN = RCC_APB1SMENR1_PWRSEMEN_ON_SETTING, // Power control clock enable in Sleep mode
        .B.DAC1SMEN = RCC_APB1SMENR1_DAC1SMEN_ON_SETTING, // DAC clock enable in Sleep mode
        .B.OPAMPSMEN = RCC_APB1SMENR1_OPAMPSMEN_ON_SETTING, // OPAMP1 clock enable in Sleep mode
        .B.LPTIM1SMEN = RCC_APB1SMENR1_LPTIM1SMEN_ON_SETTING, // LPTIM1 clock enable in Sleep mode
};

volatile RCC_APB1SMENR2_Reg_t RCC_APB1SMENR2_Reg = {
        .B.LPUART1SMEN = RCC_APB1SMENR2_LPUART1SMEN_ON_SETTING, // LPUART1 clock enable in Sleep mode
        .B.SWPMI1SMEN = RCC_APB1SMENR2_SWPMI1SMEN_ON_SETTING, // SWPMI1 clock enable in Sleep mode
        .B.LPTIM2SMEN = RCC_APB1SMENR2_LPTIM2SMEN_ON_SETTING, // LPTIM2 clock enable in Sleep mode
};

volatile RCC_APB2SMENR_Reg_t RCC_APB2SMENR_Reg = {
        .B.SYSCFGSMEN = RCC_APB2SMENR_SYSCFGSMEN_ON_SETTING, // SYSCFG clock enable in Sleep mode
        .B.SDMMC1SMEN = RCC_APB2SMENR_SDMMC1SMEN_ON_SETTING, // SDMMC clock enable in Sleep mode
        .B.TIM1SMEN = RCC_APB2SMENR_TIM1SMEN_ON_SETTING, // TIM1 clock enable in Sleep mode
        .B.SPI1SMEN = RCC_APB2SMENR_SPI1SMEN_ON_SETTING, // SPI1 clock enable in Sleep mode
        .B.USART1SMEN = RCC_APB2SMENR_USART1SMEN_ON_SETTING, // USART1 clock enable in Sleep mode
        .B.TIM15SMEN = RCC_APB2SMENR_TIM15SMEN_ON_SETTING, // TIM15 clock enable in Sleep mode
        .B.TIM16SMEN = RCC_APB2SMENR_TIM16SMEN_ON_SETTING, // TIM16 clock enable in Sleep mode
        .B.SAI1SMEN = RCC_APB2SMENR_SAI1SMEN_ON_SETTING, // SAI1 clock enable in Sleep mode
};

volatile RCC_CCIPR_Reg_t RCC_CCIPR_Reg = {
        .B.USART1SEL = RCC_CCIPR_USART1SEL_PCLK2_SETTING, // USART1 clock source selection set to PCLK2
        .B.USART2SEL = RCC_CCIPR_USART2SEL_PCLK1_SETTING, // USART2 clock source selection set to PCLK1
        .B.USART3SEL = RCC_CCIPR_USART3SEL_PCLK1_SETTING, // USART3 clock source selection set to PCLK1
        .B.UART4SEL = RCC_CCIPR_UART4SEL_PCLK1_SETTING, // UART4 clock source selection set to PCLK1
        .B.LPUART1SEL = RCC_CCIPR_LPUART1SEL_PCLK1_SETTING, // LPUART1 clock source selection set to PCLK1
        .B.I2C1SEL = RCC_CCIPR_I2C1SEL_PCLK1_SETTING, // I2C1 clock source selection set to PCLK1
        .B.I2C2SEL = RCC_CCIPR_I2C2SEL_PCLK1_SETTING, // I2C2 clock source selection set to PCLK1
        .B.I2C3SEL = RCC_CCIPR_I2C3SEL_PCLK1_SETTING, // I2C3 clock source selection set to PCLK1
        .B.LPTIM1SEL = RCC_CCIPR_LPTIM1SEL_PCLK1_SETTING, // LPTIM1 clock source selection set to PCLK1
        .B.LPTIM2SEL = RCC_CCIPR_LPTIM2SEL_PCLK1_SETTING, // LPTIM2 clock source selection set to PCLK1
        .B.SAI1SEL = RCC_CCIPR_SAI1SEL_PLLSAI1_SETTING, // SAI1 clock source selection set to PLLSAI1
        .B.CLK48SEL = RCC_CCIPR_CLK48SEL_PLLSAI1_SETTING, // HSI48 clock source selection set to PLLSAI1
        .B.ADCSEL = RCC_CCIPR_ADCSEL_PLLSAI1_SETTING, // ADC clock source selection set to PLLSAI1
        .B.SWPMI1SEL = RCC_CCIPR_SWPMI1SEL_PCLK1_SETTING, // SWPMI1 clock source selection set to PCLK1

};

volatile RCC_BDCR_Reg_t RCC_BDCR_Reg = {
        .B.LSEON = RCC_BDCR_LSEON_ON_SETTING,
        .B.LSEBYP = RCC_BDCR_LSEBYP_OFF_SETTING,
        .B.LSEDRV = RCC_BDCR_LSEDRV_LOW_SETTING, // LSE drive capability set to low
        .B.LSECSSON = RCC_BDCR_LSECSSON_OFF_SETTING, // LSE clock security system disabled
        .B.LSESYSDIS = RCC_BDCR_LSESYSDIS_OFF_SETTING, // LSE system clock disabled
        .B.RTCSEL = RCC_BDCR_RTCSEL_LSE_SETTING, // RTC clock source selection set to LSE
        .B.RTCEN = RCC_BDCR_RTCEN_ON_SETTING, // RTC clock enable
        .B.BDRST = RCC_BDCR_BDRST_NO_SETTING, // Backup domain reset not set
        .B.LSCOEN = RCC_BDCR_LSECSSON_ON_SETTING,
        .B.LSCOSEL = RCC_BDCR_LSCOSEL_LSE_SETTING,
};

volatile RCC_CSR_Reg_t RCC_CSR_Reg = {
        .B.LSION = RCC_CSR_LSION_ON_SETTING, // LSI clock enable
        .B.LSIPREDIV = RCC_CSR_LSIPREDIV_DIV1_SETTING, // LSI prescaler set to 1
        .B.MSISRANGE = RCC_CSR_MSISRANGE_4MHZ_SETTING, // MSI range set to 100KHz
        .B.RMVF = RCC_CSR_RMVF_NO_SETTING, // Remove reset flag not set
};

volatile RCC_CRRCR_Reg_t RCC_CRRCR_Reg = {
        .B.HSI48ON = RCC_CRRCR_HSI48ON_ON_SETTING, // HSI48 clock enable
};

volatile RCC_CCIPR2_Reg_t RCC_CCIPR2_Reg = {
        .B.I2C4SEL = RCC_CCIPR2_I2C4SEL_PCLK1_SETTING, // I2C4 clock source selection set to PCLK1
};