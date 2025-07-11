#ifndef STM32L433_LL_RCC_H
#define STM32L433_LL_RCC_H

#include <stm32l433xx.h> // Device-specific header for register definitions

#include <stdbool.h>

#define MAX_FREQUENCY_AHB   80000000UL
#define MAX_FREQUENCY_APB1   80000000UL
#define MAX_FREQUENCY_APB2   80000000UL

typedef enum
{
    ERR_FAILED,
    ERR_SUCCESS,
    ERR_TIMEOUT,
}Error_t;

typedef enum
{
    MSI_RC,
    HSI_RC,
    HSE_RC,
    PLL_RC
}Osc_t;

typedef enum
{
    SYSCLK_MSI,
    SYSCLK_HSI16,
    SYSCLK_HSE,
    SYSCLL_PLL_CLK,
    
}RCCSysClkSource_t;

typedef enum
{
    APB1_HCLK_NODIV=0x03,
    APB1_HCLK_DIV2=0x04,
    APB1_HCLK_DIV4 = 0x05,
    APB1_HCLK_DIV8 = 0x06,
    APB1_HCLK_DIV16 = 0x07,
}Apb1Prescaler_t;

typedef enum
{
    APB2_HCLK_NODIV=0x03,
    APB2_HCLK_DIV2=0x04,
    APB2_HCLK_DIV4 = 0x05,
    APB2_HCLK_DIV8 = 0x06,
    APB2_HCLK_DIV16 = 0x07,
}Apb2Prescaler_t;

typedef enum
{
    AHB_SYSCLK_NODIV = 0x07,
    AHB_SYSCLK_DIV2,
    AHB_SYSCLK_DIV4,
    AHB_SYSCLK_DIV8,
    AHB_SYSCLK_DIV16,
    AHB_SYSCLK_DIV32,
    AHB_SYSCLK_DIV64,
    AHB_SYSCLK_DIV128,
    AHB_SYSCLK_DIV256,
    AHB_SYSCLK_DIV512,  
}AhbPrescaler_t;


typedef enum
{
    ADC_SYSCLK,
    ADC_PLLADC1CLK,
}RccAdcClockSource_t;

typedef enum
{
    USART_SYSCLK,
    USART_HSI16CLK,
    USART_LSECLK,
    USART_APB1CLK,
    USART_APB2CLK,
}RccUsartClockSource_t;

typedef enum
{
  I2C_SYSCLK,
  I2C_HSI16CLK,
  I2C_APB1CLK,  
}RccI2cClockSource_t;

typedef enum
{
    PLL_NOCLK,
    PLLSAICLK,
    PLLSAICLK_MAIN,
    PLLHSI16,
}RccPllClockSource_t;

typedef enum
{
    SWPMI_HSI16,
    SWPMI_APB1CLK,
}RccSwpmiClockSource_t;

typedef enum
{
    LPTIM_LSI,
    LPTIM_LSE,
    LPTIM_HSI16,
    LPTIM_APB1CLK,
    LPTIM_EXTCLK,
}RccLpTimClockSources_t;

typedef enum
{
   RTC_LSE,
   RTC_LSI,
   RTC_HSE,
}RccRtcClockSources;

typedef enum
{
    IWDG_LSICLK,
}RccIwdgClockSources_t;

typedef enum
{
    USBFS_PLL48M1CLK,
    USBFS_PLL48M2CLK,
    USBFS_MSICLK,
    USBFS_HSI48CLK,
}RccUsbFsClockSources_t;

typedef enum
{
    RNG_PLL48M1CLK,
    RNG_PLL48M2CLK,
    RNG_MSICLK,
    RNG_HSI48CLK,
}RccRngClockSources_t;

typedef enum
{
    SDMMC_PLL48M1CLK,
    SDMMC_PLL48M2CLK,
    SDMMC_MSICLK,
    SDMMC_HSI48CLK,
}RccSdmmcClockSources_t;

typedef enum
{
    RCC_MSISRANGE_100KHZ_SETTING  = 0x0,
    RCC_MSISRANGE_200KHZ_SETTING  = 0x1,
    RCC_MSISRANGE_400KHZ_SETTING  = 0x2,
    RCC_MSISRANGE_800KHZ_SETTING  = 0x3,
    RCC_MSISRANGE_1MHZ_SETTING    = 0x4,
    RCC_MSISRANGE_2MHZ_SETTING    = 0x5,
    RCC_MSISRANGE_4MHZ_SETTING    = 0x6,
    RCC_MSISRANGE_8MHZ_SETTING    = 0x7,
    RCC_MSISRANGE_16MHZ_SETTING   = 0x8,
    RCC_MSISRANGE_24MHZ_SETTING   = 0x9,
    RCC_MSISRANGE_32MHZ_SETTING   = 0xA,
    RCC_MSISRANGE_48MHZ_SETTING   = 0xB
}RccMsiRng_t;

typedef enum
{
    MSI_RANGESRC_CSR,
    MSI_RANGESRC_CR
}RccMsiRngSel_t;
typedef enum
{
    RCC_HSE_BYPASS_DISABLED,
    RCC_HSE_BYPASS_ENABLED,
}RccHseByPass_t;

typedef enum
{
    MCO_DISABLED=0x00,
    MCO_SYSCLK,
    MCO_MSI,
    MCO_HSI16,
    MCO_HSE,
    MCO_MAINPLL,
    MCO_LSI,
    MCO_LSE,
    MCO_HSI48,

}RccMcoSource_t;

typedef enum
{
    MCO_DIV1=0x00,
    MCO_DIV2,
    MCO_DIV4,
    MCO_DIV8,
    MCO_DIV16,
}RccMcoPrescaler_t;

typedef enum
{
    PLL_PLL_NOCLK=0x00,
    PLL_PLL_MSICLK,
    PLL_PLL_HSI16,
    PLL_PLL_HSE,
}RccPllSrc_t;

typedef enum
{
    RCC_PLL_M_1=0x00,
    RCC_PLL_M_2,
    RCC_PLL_M_3,
    RCC_PLL_M_4,
    RCC_PLL_M_5,
    RCC_PLL_M_6,
    RCC_PLL_M_7,
    RCC_PLL_M_8,
}RccPllM_t;

typedef enum
{
   RCC_PLLP_7=0x00,
   RCC_PLLP_17,    
}RccPllP_t;

typedef enum
{
   RCC_PLLQ_2=0x00,
   RCC_PLLQ_4,
   RCC_PLLQ_6,
   RCC_PLLQ_8    
}RccPllQ_t;

typedef enum
{
   RCC_PLLR_2=0x00,
   RCC_PLLR_4,
   RCC_PLLR_6,
   RCC_PLLR_8 
}RccPllR_t;

typedef enum
{
    RCC_LSIINTR,
    RCC_LSEINTR,
    RCC_MSIINTR,
    RCC_HSIINTR,
    RCC_HSEINTR,
    RCC_PLLINTR,
    RCC_PLLSAI1INTR,
    RCC_LSECSSINTR,
    RCC_HSI48INTR,
}Rcc_InterruptClock_t;

typedef enum
{
    AHB1_DMA1,
    AHB1_DMA2,
    AHB1_FLASH,
    AHB1_CRC,
    AHB1_TSC,

}Rcc_Ahb1Peripheral_t;

typedef enum
{
    AHB2_GPIOA,
    AHB2_GPIOB,
    AHB2_GPIOC,
    AHB2_GPIOD,
    AHB2_GPIOE,
    AHB2_GPIOH,
    AHB2_ADC,
    AHB2_AES,
    AHB2_RNG,
}Rcc_Ahb2Peripheral_t;

typedef enum
{
    AHB3_QSPI,
}Rcc_Ahb3Peripheral_t;

typedef enum
{
    APB1_TIM2,
    APB1_TIM3,
    APB1_TIM6,
    APB1_TIM7,
    APB1_LCD,
    APB1_SPI2,
    APB1_SPI3,
    APB1_USART2,
    APB1_USART3,
    APB1_UART4,
    APB1_I2C1,
    APB1_I2C2,
    APB1_I2C3,
    APB1_CRS,
    APB1_CAN1,
    APB1_USBFS,
    APB1_PWR,
    APB1_DAC1,
    APB1_OPAMP,
    APB1_LPTIM1

}Rcc_Apb1Peripheral1_t;

typedef enum
{
    APB1P2_LPUART1,
    APB1P2_I2C4,
    APB1P2_SWPMI1,
    APB1P2_LPTIM2,
}Rcc_Apb1Peripheral2_t;

typedef enum
{
    APB2_SYSCFG,
    APB2_SDMMC,
    APB2_TIM1,
    APB2_SPI1,
    APB2_USART1,
    APB2_TIM15,
    APB2_TIM16,
    APB2_SAI1,

}Rcc_Apb2Peripheral_t;

typedef enum
{
    CCIPR_PCLK,
    CCIPR_SYSCLK,
    CCIPR_HSI16CLK,
    CCIPR_LSECLk,
    CCIPR_CLKSRCNONE,
}Rcc_Ccipr_ClockSrc_t;

typedef enum
{
    CCIPR_USART1SEL,
    CCIPR_USART2SEL,
    CCIPR_USART3SEL,
    CCIPR_LPUART1SEL,
    CCIPR_I2C1SEL,
    CCIPR_I2C2SEL,
    CCIPR_I2C3SEL,
    CCIPR_LPTIM1SEL,
    CCIPR_LPTIM2SEL,
    CCIPR_SAISEL,
    CCIPR_CLK48SEL,
    CCIPR_ADCSEL,
    CCIPR_SWPMI1,
}Rcc_CciprPeripheral_t;

typedef enum
{
    BDCR_RTC_NO_CLK,
    BDCR_LSECLK,
    BDCR_LSICLK,
    BDCR_HSECLK,

}Rcc_Bdcr_RtcSource_t;

typedef enum
{
    BDCR_LSEDRV_LOW,
    BDCR_LSEDRV_MEDIUMLOW,
    BDCR_LSEDRV_MEDIUMHIGH,
    BDCR_LSEDRV_HIGH,
}Rcc_Bdcr_LseSpeed_t;


typedef enum
{
    CSR_MSI_RANGE1MHz = 0x04,
    CSR_MSI_RANGE2MHz = 0x05,
    CSR_MSI_RANGE4MHz = 0x06,
    CSR_MSI_RANGE8MHz = 0x07,

}Rcc_CsrMsiRng_t;



Error_t RCC_EnableMSI(RccMsiRng_t range,bool En);
Error_t RCC_EnableHSI(bool kernelClock, bool autoStartStop,bool En);
Error_t RCC_EnableHSE(RccHseByPass_t ByPassSetting,bool ClkSecuSet,bool En);
Error_t RCC_EnableMainPLL(bool En);
Error_t RCC_EnablePLLSAI1(bool En);
Error_t RCC_SetSystemClockSource(RCCSysClkSource_t source);
Error_t RCC_SetAHBPrescaler(AhbPrescaler_t prescaler);
Error_t RCC_SetAPB1Prescaler(Apb1Prescaler_t prescaler);
Error_t RCC_SetAPB2Prescaler(Apb1Prescaler_t prescaler);
Error_t RCC_ConfigureMCO(RccMcoSource_t source, RccMcoPrescaler_t prescaler);
Error_t RCC_ConfigurePllSrc(RccPllSrc_t PllSrc);
Error_t RCC_ConfigurePllSettings(RccPllM_t RccPllM,RccPllP_t RccPllP ,RccPllQ_t RccPllQ,RccPllR_t RccPllR,uint8_t RccPllN, uint8_t RccPllDiv);
Error_t RCC_EnablePllR(bool En);
Error_t RCC_EnablePllQ(bool En);
Error_t RCC_EnablePllP(bool En);
Error_t RCC_ConfigurePllSai1Settings(RccPllM_t RccPllM,RccPllP_t RccPllP ,RccPllQ_t RccPllQ,RccPllR_t RccPllR,uint8_t RccPllSai1N, uint8_t RccPllSai1Div);
Error_t RCC_EnablePllSai1R(bool En);
Error_t RCC_EnablePllSai1Q(bool En);
Error_t RCC_EnablePllSai1P(bool En);
Error_t RCC_EnableInterrupt(Rcc_InterruptClock_t ClockType);
bool RCC_GetClockInterrupt(Rcc_InterruptClock_t ClockType);
Error_t RCC_ClearClockInterrupt(Rcc_InterruptClock_t ClockType);
void RCC_ResetAhb1Peripheral(Rcc_Ahb1Peripheral_t peripheral);
void RCC_ResetAhb2Peripheral(Rcc_Ahb2Peripheral_t peripheral);
void RCC_ResetAhb3Peripheral(Rcc_Ahb3Peripheral_t peripheral);
void RCC_ResetApb1Peripheral1(Rcc_Apb1Peripheral1_t peripheral);
void RCC_ResetApb1Peripheral2(Rcc_Apb1Peripheral2_t peripheral);
void RCC_ResetApb2Peripheral(Rcc_Apb2Peripheral_t peripheral);
Error_t RCC_EnableAhb1Peripheral(Rcc_Ahb1Peripheral_t peripheral);
Error_t RCC_EnableAhb2Peripheral(Rcc_Ahb2Peripheral_t peripheral);
Error_t RCC_EnableAhb3Peripheral(Rcc_Ahb3Peripheral_t peripheral);
Error_t RCC_EnableApb1Peripheral1(Rcc_Apb1Peripheral1_t peripheral);
Error_t RCC_EnableApb1Peripheral2(Rcc_Apb1Peripheral2_t peripheral);
Error_t RCC_EnableApb2Peripheral(Rcc_Apb2Peripheral_t peripheral);
Error_t RCC_EnableDuringSleepAhb1Peripheral(Rcc_Ahb1Peripheral_t peripheral,bool SleepEn);
Error_t RCC_EnableDuringSleepAhb2Peripheral(Rcc_Ahb2Peripheral_t peripheral,bool SleepEn);
Error_t RCC_EnableDuringSleepAhb3Peripheral(Rcc_Ahb3Peripheral_t peripheral,bool SleepEn);
Error_t RCC_EnableDuringSleepApb1Peripheral1(Rcc_Apb1Peripheral1_t peripheral,bool SleepEn);
Error_t RCC_EnableDuringSleepApb1Peripheral2(Rcc_Apb1Peripheral2_t peripheral,bool SleepEn);
Error_t RCC_EnableDuringSleepApb2Peripheral(Rcc_Apb2Peripheral_t peripheral,bool SleepEn);
Error_t RCC_ConfigureCciprClocks(Rcc_CciprPeripheral_t peripheral , Rcc_Ccipr_ClockSrc_t src);
Error_t RCC_BdcrEnableLse(bool BdcrLseEn);
Error_t RCC_BdcrConfigureLseByp(bool BypEn);
Error_t RCC_BdcrConfigureLseSpeed(Rcc_Bdcr_LseSpeed_t spd);
Error_t RCC_BdcrLseCssConfigure(bool LseCssEn);
Error_t Rcc_BdcrConfigureRtcSource(Rcc_Bdcr_RtcSource_t src);
Error_t Rcc_BdcrConfigureRtcClk(bool RtcClkEn);
Error_t Rcc_BdcrConfigureBdRst(bool BdRst);
Error_t Rcc_ConfigureLscoEn(bool LscoEn);
Error_t Rcc_ConfigureLseSel(bool LseSel);
Error_t Rcc_EnableLsiCsr(bool LsiCsrEn);
Error_t Rcc_ConfigureMsiRangeCsr(Rcc_CsrMsiRng_t MsiRange);
Error_t Rcc_RmVfCsr(bool RmvfEn);
Error_t Rcc_CrrCrHsi48Enable(bool Hsi48En);
Error_t RCC_MsiRangeSelect(RccMsiRngSel_t RangeSrc);
#endif