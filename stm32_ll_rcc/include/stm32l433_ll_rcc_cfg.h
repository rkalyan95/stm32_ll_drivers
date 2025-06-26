#ifndef STM32L433_LL_CFG_H
#define STM32L433_LL_CFG_H

#include <stdint.h>
#include <stm32l433xx.h>

enum 
{
    CLK_DISABLED=0,
    SYSCLK,
    MSICLK,
    HSI16CLK,
    HSECLK,
    MAINPLL,
    LSICLK,
    LSECLK,
    HSI48,
    INVALID,
};

enum
{
    DIV1=0,
    DIV2,
    DIV4,
    DIV8,
    DIV16,
};

// --- RCC_CR (Clock Control Register) ---
typedef struct
{
    uint32_t MSION:1;
    uint32_t MSIRDY:1;
    uint32_t MSIPLLEN:1;
    uint32_t MSIRGSEL:1;
    uint32_t MSIRANGE:4;
    uint32_t HSION:1;
    uint32_t HSIKERON:1;
    uint32_t HSIRDY:1;
    uint32_t HSIASFS:1;
    uint32_t res_1:4;
    uint32_t HSEON:1;
    uint32_t HSERDY:1;
    uint32_t HSEBYP:1;
    uint32_t CSSON:1;
    uint32_t res_2:4;
    uint32_t PLL_ON:1;
    uint32_t PLL_RDY:1;
    uint32_t PLLSAI1ON:1;
    uint32_t PLLSAI1RDY:1;
    uint32_t res_3 : 4;
} RCC_CR_B_t;

typedef union
{
    RCC_CR_B_t B;
    uint32_t U;
} RCC_CR_Reg_t;

extern volatile RCC_CR_Reg_t RCC_CR_Reg;


// --- RCC_ICSCR (Internal Clock Source Calibration Register) ---
typedef struct
{
    uint32_t MSICAL:8;
    uint32_t MSITRIM:8;
    uint32_t HSICAL:8;
    uint32_t HSITRIM:7;
    uint32_t res:1;
} RCC_ICSCR_B_t;

typedef union
{
    RCC_ICSCR_B_t B;
    uint32_t U;
} RCC_ICSCR_Reg_t;

extern volatile RCC_ICSCR_Reg_t RCC_ICSCR_Reg;


// --- RCC_CFGR (Clock Configuration Register) ---
typedef struct
{
    uint32_t SW:2;
    uint32_t SWS:2;
    uint32_t HPRE:4;
    uint32_t PPRE1 : 3;
    uint32_t PPRE2:3;
    uint32_t res_1 : 1;
    uint32_t STOPWUCK:1;
    uint32_t res_2:8;
    uint32_t MCOSEL : 4;
    uint32_t MCOPRE : 3;
    uint32_t res_3:1;
} RCC_CFGR_B_t;

typedef union
{
    RCC_CFGR_B_t B;
    uint32_t U;
} RCC_CFGR_Reg_t;

extern volatile RCC_CFGR_Reg_t RCC_CFGR_Reg;


// --- RCC_PLLCFGR (PLL Configuration Register) ---
typedef struct
{
    uint32_t PLLSRC:2;
    uint32_t res_1:2;
    uint32_t PLLM : 3;
    uint32_t res_2:1;
    uint32_t PLLN : 8;
    uint32_t res_3:1;
    uint32_t PLLEN : 1;
    uint32_t PLLP:1;
    uint32_t res_4 : 2;
    uint32_t PLLQEN:1;
    uint32_t PLLQ : 2;
    uint32_t res_5:1;
    uint32_t PLL_REN:1;
    uint32_t PLLR : 2;
    uint32_t PLLDIV:5;
} RCC_PLLCFGR_B_t;

typedef union
{
    RCC_PLLCFGR_B_t B;
    uint32_t U;
} RCC_PLLCFGR_Reg_t;

extern volatile RCC_PLLCFGR_Reg_t RCC_PLLCFGR_Reg;


// --- RCC_PLLSAI1CFGR (PLLSAI1 Configuration Register) ---
typedef struct
{
    uint32_t RES_1:8;
    uint32_t PLLSA1N : 7;
    uint32_t RES_2:1;
    uint32_t PLLSA1PEN : 1;
    uint32_t PLLSA1P:2;
    uint32_t RES_3 : 2;
    uint32_t PLLSA1QEN:1;
    uint32_t PLLSA1Q:2;
    uint32_t RES_4 : 1;
    uint32_t PLLSA1REN:1;
    uint32_t PLLSA1R:2;
    uint32_t PLLSA1PDIV:5;
} RCC_PLLSAI1CFGR_B_t;

typedef union
{
    RCC_PLLSAI1CFGR_B_t B;
    uint32_t U;
} RCC_PLLSAI1CFGR_Reg_t;

extern volatile RCC_PLLSAI1CFGR_Reg_t RCC_PLLSAI1CFGR_Reg;


// --- RCC_CIER (Clock Interrupt Enable Register) ---
typedef struct
{
    uint32_t LSIRDYIE:1;
    uint32_t LSERDYIE:1;
    uint32_t MSIRDYIE:1;
    uint32_t HSIRDYIE:1;
    uint32_t HSERDYIE:1;
    uint32_t PLLRDYIE:1;
    uint32_t PLLSAI1RDYIE:1;
    uint32_t RES_1:2;
    uint32_t LSECSSIE:1;
    uint32_t HSI48RDYIE : 1;
    uint32_t RES_2:21;
} RCC_CIER_B_t;

typedef union
{
    RCC_CIER_B_t B;
    uint32_t U;
} RCC_CIER_Reg_t;

extern volatile RCC_CIER_Reg_t RCC_CIER_Reg;

// --- RCC_CICR (Clock Interrupt Clear Register) ---
typedef struct
{
    uint32_t LSIRDYC:1;
    uint32_t LSERDYC:1;
    uint32_t MSIRDYC:1;
    uint32_t HSIRDYC:1;
    uint32_t HSERDYC:1;
    uint32_t PLLRDYC:1;
    uint32_t PLLSAI1RDYC:1;
    uint32_t RES_1:1;
    uint32_t CSSC:1;
    uint32_t LSECSSC:1;
    uint32_t HSI48RDYC:1;         
    uint32_t RES_2 : 21;
} RCC_CICR_B_t;

typedef union
{
    RCC_CICR_B_t B;
    uint32_t U;
} RCC_CICR_Reg_t;

extern volatile RCC_CICR_Reg_t RCC_CICR_Reg;

// --- RCC_AHB1RSTR (AHB1 Peripheral Reset Register) ---
typedef struct
{
    uint32_t DMA1RST:1;
    uint32_t DMA2RST:1;
    uint32_t RES_1 : 6;
    uint32_t FLASHRST:1;
    uint32_t RES2 : 3;
    uint32_t CRCRST:1;
    uint32_t RES3 : 3;
    uint32_t TSCRST:1;
    uint32_t RES4 : 14;
} RCC_AHB1RSTR_B_t;

typedef union
{
    RCC_AHB1RSTR_B_t B;
    uint32_t U;
} RCC_AHB1RSTR_Reg_t;

extern volatile RCC_AHB1RSTR_Reg_t RCC_AHB1RSTR_Reg;


// --- RCC_AHB2RSTR (AHB2 Peripheral Reset Register) ---
typedef struct
{
    uint32_t GPIOARST:1;
    uint32_t GPIOBRST:1;
    uint32_t GPIOCRST:1;
    uint32_t GPIODRST:1;
    uint32_t GPOIERST:1;
    uint32_t res1 : 2;
    uint32_t GPIOHRST:1;
    uint32_t res2 : 5;
    uint32_t ADCRST:1;
    uint32_t res3 : 2;
    uint32_t AESRST:1;
    uint32_t res4 : 1;
    uint32_t RNGRST:1;
    uint32_t res5 : 13;
} RCC_AHB2RSTR_B_t;

typedef union
{
    RCC_AHB2RSTR_B_t B;
    uint32_t U;
} RCC_AHB2RSTR_Reg_t;

extern volatile RCC_AHB2RSTR_Reg_t RCC_AHB2RSTR_Reg;


// --- RCC_AHB3RSTR (AHB3 Peripheral Reset Register) ---
typedef struct
{
    uint32_t res1 : 8;
    uint32_t QSPIRST:1;
    uint32_t res2 : 23;
} RCC_AHB3RSTR_B_t;

typedef union
{
    RCC_AHB3RSTR_B_t B;
    uint32_t U;
} RCC_AHB3RSTR_Reg_t;

extern volatile RCC_AHB3RSTR_Reg_t RCC_AHB3RSTR_Reg;


// --- RCC_APB1RSTR1 (APB1 Peripheral Reset Register 1) ---
typedef struct
{
    uint32_t TIM2RST:1;
    uint32_t TIM3RST:1;
    uint32_t RES_1:2;
    uint32_t TIM6RST:1;
    uint32_t TIM7RST:1;
    uint32_t RES_2:3;
    uint32_t LCDRST : 1;
    uint32_t RES_3:4;
    uint32_t SPI2RST:1;
    uint32_t SPI3RST:1;
    uint32_t res3 : 1;
    uint32_t USART2RST:1;
    uint32_t USART3RST:1;
    uint32_t UART4RST:1;
    uint32_t RES_4:1;
    uint32_t I2C1RST:1;
    uint32_t I2C2RST:1;
    uint32_t I2C3RST:1;
    uint32_t CRSRST:1;
    uint32_t CANRST : 1;
    uint32_t USBFSRST:1;
    uint32_t RES_5:1;
    uint32_t PWRRST : 1;
    uint32_t DACRST:1;
    uint32_t OPAMPRST : 1;
    uint32_t LPTIM1RST : 1;
} RCC_APB1RSTR1_B_t;

typedef union
{
    RCC_APB1RSTR1_B_t B;
    uint32_t U;
} RCC_APB1RSTR1_Reg_t;

extern volatile RCC_APB1RSTR1_Reg_t RCC_APB1RSTR1_Reg;


// --- RCC_APB1RSTR2 (APB1 Peripheral Reset Register 2) ---
typedef struct
{
    uint32_t LPUART1RST : 1;
    uint32_t I2C4RST:1;
    uint32_t SWPMI1RST : 1;
    uint32_t RES_1:2;
    uint32_t LPTIM2RST : 1;
    uint32_t RES_2:26;
} RCC_APB1RSTR2_B_t;

typedef union
{
    RCC_APB1RSTR2_B_t B;
    uint32_t U;
} RCC_APB1RSTR2_Reg_t;

extern volatile RCC_APB1RSTR2_Reg_t RCC_APB1RSTR2_Reg;


// --- RCC_APB2RSTR (APB2 Peripheral Reset Register) ---
typedef struct
{
    uint32_t SYSCFGRST:1;
    uint32_t RES_1 : 9;
    uint32_t SDMMCRST:1;
    uint32_t TIM1RST:1;
    uint32_t SPI1RST : 1;
    uint32_t RES_2:1;
    uint32_t UART1RST : 1;
    uint32_t RES_3:1;
    uint32_t TIM15RST : 1;
    uint32_t TIM16RST:1;
    uint32_t RES_4:3;
    uint32_t SA1RST : 1;
    uint32_t RES_5:2;
    uint32_t DFSDM1RST:1;
    uint32_t RES_6 : 7;
} RCC_APB2RSTR_B_t;

typedef union
{
    RCC_APB2RSTR_B_t B;
    uint32_t U;
} RCC_APB2RSTR_Reg_t;

extern volatile RCC_APB2RSTR_Reg_t RCC_APB2RSTR_Reg;


// --- RCC_AHB1ENR (AHB1 Peripheral Clock Enable Register) ---
typedef struct
{
    uint32_t DMA1_EN:1;
    uint32_t DMA2_EN:1;
    uint32_t res2 : 6;
    uint32_t FLASH_EN:1;
    uint32_t res3 : 3;
    uint32_t CRC_EN:1;
    uint32_t res4 : 3;
    uint32_t TSC_EN:1;
    uint32_t res5 : 15;
} RCC_AHB1ENR_B_t;

typedef union
{
    RCC_AHB1ENR_B_t B;
    uint32_t U;
} RCC_AHB1ENR_Reg_t;

extern volatile RCC_AHB1ENR_Reg_t RCC_AHB1ENR_Reg;


// --- RCC_AHB2ENR (AHB2 Peripheral Clock Enable Register) ---
// (Your original example, included for completeness)
typedef struct
{
    uint32_t GPIOA_EN:1;
    uint32_t GPIOB_EN:1;
    uint32_t GPIOC_EN:1;
    uint32_t GPIOD_EN:1;
    uint32_t GPIOE_EN:1;
    uint32_t res1 : 2;
    uint32_t GPIOH_EN:1;
    uint32_t res2 : 5;
    uint32_t ADC_EN:1;
    uint32_t res3 : 2;
    uint32_t AES_EN:1;
    uint32_t res4 : 1;
    uint32_t RNG_B:1; 
    uint32_t res5 : 13;
}RCC_AHB2ENR_B_t;

typedef union
{
    RCC_AHB2ENR_B_t B;
    uint32_t U;
}RCC_AHB2ENR_Reg_t;

extern volatile RCC_AHB2ENR_Reg_t RCC_AHB2ENR_Reg;


// --- RCC_AHB3ENR (AHB3 Peripheral Clock Enable Register) ---
typedef struct
{
    uint32_t res1 : 8;
    uint32_t QSPI_EN:1;
    uint32_t res2 : 23;
} RCC_AHB3ENR_B_t;

typedef union
{
    RCC_AHB3ENR_B_t B;
    uint32_t U;
} RCC_AHB3ENR_Reg_t;

extern volatile RCC_AHB3ENR_Reg_t RCC_AHB3ENR_Reg;


// --- RCC_APB1ENR1 (APB1 Peripheral Clock Enable Register 1) ---
typedef struct
{
    uint32_t TIM2_EN:1;
    uint32_t TIM3_EN:1;
    uint32_t RES_1:2;
    uint32_t TIM6_EN:1;
    uint32_t TIM7_EN:1;
    uint32_t RES_2:3;
    uint32_t LCDEN : 5;
    uint32_t RTCAPBEM:1;
    uint32_t WWDGEN : 2;
    uint32_t RES_3:2;
    uint32_t SPI2_EN:1;
    uint32_t SPI3_EN : 1;
    uint32_t RES_4:1;
    uint32_t USART2_EN:1;
    uint32_t USART3_EN:1;
    uint32_t UART4_EN:1;
    uint32_t RES_5:1;
    uint32_t I2C1_EN:1;
    uint32_t I2C2_EN:1;
    uint32_t I2C3_EN : 1;
    uint32_t CRS_EN:1;
    uint32_t CAN1EN : 1;
    uint32_t USBFSEN:1;
    uint32_t RES_6:1;
    uint32_t PWREN : 1;
    uint32_t DACEN:1;
    uint32_t OPAMPEN : 1;
    uint32_t LPTIM1EN : 1;
} RCC_APB1ENR1_B_t;

typedef union
{
    RCC_APB1ENR1_B_t B;
    uint32_t U;
} RCC_APB1ENR1_Reg_t;

extern volatile RCC_APB1ENR1_Reg_t RCC_APB1ENR1_Reg;


// --- RCC_APB1ENR2 (APB1 Peripheral Clock Enable Register 2) ---
typedef struct
{
    uint32_t LPUART1EN : 1;
    uint32_t I2C4EN:1;
    uint32_t SWPMI1_EN:1;
    uint32_t res3 : 2;
    uint32_t LPTIM2EN:1;
    uint32_t res4 : 26;
} RCC_APB1ENR2_B_t;

typedef union
{
    RCC_APB1ENR2_B_t B;
    uint32_t U;
} RCC_APB1ENR2_Reg_t;

extern volatile RCC_APB1ENR2_Reg_t RCC_APB1ENR2_Reg;


// --- RCC_APB2ENR (APB2 Peripheral Clock Enable Register) ---
typedef struct
{
    uint32_t SYSCFG_EN:1;
    uint32_t res1 : 6;
    uint32_t FW_EN:1;
    uint32_t RES2:2;
    uint32_t SDMMC1EN : 1;
    uint32_t TIM1EN:1;
    uint32_t SPI1EN : 1;
    uint32_t RES:1;
    uint32_t USART1EN : 1;
    uint32_t RES_2:1;
    uint32_t TIM15EN:1;
    uint32_t TIME16EN : 1;
    uint32_t RES_3:3;
    uint32_t SAI1EN:1;
    uint32_t RES_4:2;
    uint32_t DFSDM1EN : 1;
    uint32_t res8 : 7;
} RCC_APB2ENR_B_t;

typedef union
{
    RCC_APB2ENR_B_t B;
    uint32_t U;
} RCC_APB2ENR_Reg_t;

extern volatile RCC_APB2ENR_Reg_t RCC_APB2ENR_Reg;


// --- RCC_AHB1SMENR (AHB1 Peripheral Clock Enable in Sleep Mode Register) ---
typedef struct
{
    uint32_t DMA1SMEN:1;
    uint32_t DMA2SMEN:1;
    uint32_t res2 : 6;
    uint32_t FLASHSMEN:1;
    uint32_t SRAM1EN : 1;
    uint32_t res3:2;
    uint32_t CRCSMEN : 1;
    uint32_t res4:3;
    uint32_t TSCSMEN : 1;
    uint32_t res5:15;
} RCC_AHB1SMENR_B_t;

typedef union
{
    RCC_AHB1SMENR_B_t B;
    uint32_t U;
} RCC_AHB1SMENR_Reg_t;

extern volatile RCC_AHB1SMENR_Reg_t RCC_AHB1SMENR_Reg;


// --- RCC_AHB2SMENR (AHB2 Peripheral Clock Enable in Sleep Mode Register) ---
typedef struct
{
    uint32_t GPIOASMEN:1;
    uint32_t GPIOBSMEN:1;
    uint32_t GPIOCSMEN:1;
    uint32_t GPIODSMEN:1;
    uint32_t GPOIESMEN:1;
    uint32_t res1 : 2;
    uint32_t GPIOHSMEN:1;
    uint32_t res2 : 1;
    uint32_t SRAM2SMEN:1;
    uint32_t res3 : 3;
    uint32_t ADCSMEN:1;
    uint32_t res4 : 2;
    uint32_t AESMEN:1;
    uint32_t res5 : 1;
    uint32_t RNGSMEN:1;
    uint32_t res6 : 13;
} RCC_AHB2SMENR_B_t;

typedef union
{
    RCC_AHB2SMENR_B_t B;
    uint32_t U;
} RCC_AHB2SMENR_Reg_t;

extern volatile RCC_AHB2SMENR_Reg_t RCC_AHB2SMENR_Reg;


// --- RCC_AHB3SMENR (AHB3 Peripheral Clock Enable in Sleep Mode Register) ---
typedef struct
{
    uint32_t res1 : 8;
    uint32_t QSPISMEN:1;
    uint32_t res2 : 23;
} RCC_AHB3SMENR_B_t;

typedef union
{
    RCC_AHB3SMENR_B_t B;
    uint32_t U;
} RCC_AHB3SMENR_Reg_t;

extern volatile RCC_AHB3SMENR_Reg_t RCC_AHB3SMENR_Reg;


// --- RCC_APB1SMENR1 (APB1 Peripheral Clock Enable in Sleep Mode Register 1) ---
typedef struct
{
    uint32_t TIM2SMEN:1;
    uint32_t TIM3SMEN:1;
    uint32_t res_0:2;
    uint32_t TIM6SMEN:1;
    uint32_t TIM7SMEN:1;
    uint32_t res_1:3;
    uint32_t LCDSMEN : 1;
    uint32_t RTCAPBSMEN:1;
    uint32_t WWDGSMEN : 1;
    uint32_t res_2:2;
    uint32_t SPI2SMEN:1;
    uint32_t SPI3SMEN : 1;
    uint32_t res_3:1;
    uint32_t USART2SMEN:1;
    uint32_t UART3SMEN:1;
    uint32_t UART4SMEN:1;
    uint32_t res_4:1;
    uint32_t I2C1SMEN:1;
    uint32_t I2C2SMEN:1;
    uint32_t I2C3SMEN : 1;
    uint32_t CRSSMEN:1;
    uint32_t CAN1SMEN : 1;
    uint32_t USBFSSMEN:1;
    uint32_t res_5:1;
    uint32_t PWRSEMEN:1;
    uint32_t DAC1SMEN : 1;
    uint32_t OPAMPSMEN:1;
    uint32_t LPTIM1SMEN : 1;
} RCC_APB1SMENR1_B_t; 

typedef union
{
    RCC_APB1SMENR1_B_t B;
    uint32_t U;
} RCC_APB1SMENR1_Reg_t;

extern volatile RCC_APB1SMENR1_Reg_t RCC_APB1SMENR1_Reg;


// --- RCC_APB1SMENR2 (APB1 Peripheral Clock Enable in Sleep Mode Register 2) ---
typedef struct
{
    uint32_t LPUART1SMEN : 1;
    uint32_t res0:1;
    uint32_t SWPMI1SMEN : 1;
    uint32_t res1:2;
    uint32_t LPTIM2SMEN : 1;
    uint32_t res2:26;
} RCC_APB1SMENR2_B_t;

typedef union
{
    RCC_APB1SMENR2_B_t B;
    uint32_t U;
} RCC_APB1SMENR2_Reg_t;

extern volatile RCC_APB1SMENR2_Reg_t RCC_APB1SMENR2_Reg;


// --- RCC_APB2SMENR (APB2 Peripheral Clock Enable in Sleep Mode Register) ---
typedef struct
{
    uint32_t SYSCFGSMEEN:1;
    uint32_t res1 : 9;
    uint32_t SDMMC1SMEN:1;
    uint32_t TIM1SMEN:1;
    uint32_t SPI1SMEN : 1;
    uint32_t res2:1;
    uint32_t USART1SMEN : 1;
    uint32_t res3:1;
    uint32_t TIM15SMEN : 1;
    uint32_t TIM16SMEN:1;
    uint32_t res4:3;
    uint32_t SAI1SMEN : 1;
    uint32_t res5:10;
} RCC_APB2SMENR_B_t;

typedef union
{
    RCC_APB2SMENR_B_t B;
    uint32_t U;
} RCC_APB2SMENR_Reg_t;

extern volatile RCC_APB2SMENR_Reg_t RCC_APB2SMENR_Reg;


// --- RCC_CCIPR (Peripherals Independent Clock Configuration Register) ---
typedef struct
{
    uint32_t USART1SEL:2;
    uint32_t USART2SEL:2;
    uint32_t USART3SEL:2;
    uint32_t UART4SEL:2;
    uint32_t UART5SEL:2;
    uint32_t res0:2;
    uint32_t LPUART1SEL:2;
    uint32_t I2C1SEL:2;
    uint32_t I2C2SEL:2;
    uint32_t I2C3SEL : 2;
    uint32_t LPTIM1SEL:2;
    uint32_t LPTIM2SEL:2;
    uint32_t SAI1SEL:2;
    uint32_t res1:2;
    uint32_t CLK48SEL : 2;
    uint32_t ADCSEL:2;
    uint32_t SWPMI1SEL:1;
    uint32_t res3 : 1;
} RCC_CCIPR_B_t;

typedef union
{
    RCC_CCIPR_B_t B;
    uint32_t U;
} RCC_CCIPR_Reg_t;

extern volatile RCC_CCIPR_Reg_t RCC_CCIPR_Reg;


// --- RCC_BDCR (Backup Domain Control Register) ---
typedef struct
{
    uint32_t LSEON:1;
    uint32_t LSERDY:1;
    uint32_t LSEBYP:1;
    uint32_t LSEDRV:2;
    uint32_t LSECSSON : 1;
    uint32_t LSECSSD:1;
    uint32_t LSESYSDIS:1;
    uint32_t RTCSEL:2;
    uint32_t res0:5;
    uint32_t RTCEN:1;
    uint32_t BDRST : 1;
    uint32_t res1:7;
    uint32_t LSCOEN : 1;
    uint32_t LSCOSEL:1;
    uint32_t res2:6;
} RCC_BDCR_B_t;

typedef union
{
    RCC_BDCR_B_t B;
    uint32_t U;
} RCC_BDCR_Reg_t;

extern volatile RCC_BDCR_Reg_t RCC_BDCR_Reg;


// --- RCC_CSR (Clock Control and Status Register) ---
typedef struct
{
    uint32_t LSION:1;
    uint32_t LSIRDY:1;
    uint32_t res1 : 2;
    uint32_t LSIPREDIV:1;
    uint32_t res3:3;
    uint32_t MSISRANGE : 4;
    uint32_t res2:11;
    uint32_t RMVF:1;
    uint32_t FWRSTF:1;
    uint32_t OBLRSTF:1;
    uint32_t PINRSTF:1;
    uint32_t BORRSTF:1;
    uint32_t SFTRSTF:1;
    uint32_t IWWGRSTF : 1;
    uint32_t WWDGRSTF:1;
    uint32_t LPPWRRSTF:1;
} RCC_CSR_B_t;

typedef union
{
    RCC_CSR_B_t B;
    uint32_t U;
} RCC_CSR_Reg_t;

extern volatile RCC_CSR_Reg_t RCC_CSR_Reg;


#endif