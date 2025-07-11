
#include <stm32l433_ll_rcc.h>
#include <stdbool.h>
#define GET(x,pos)   ((x & 1UL<<pos) >> pos)
#define SET(x,pos)   (x |= (1UL<<pos))
#define CLEAR(x,pos)   (x &= ~(1UL<<pos))
#define TOGGLE(x,pos) (x ^= 1UL<<pos)
#define SET_BITS(v, p, n, new_val) \
  ((v) = ((v) & ~(((1UL << (n)) - 1) << (p))) | (((new_val) & ((1UL << (n)) - 1)) << (p)))

#define GET_BITS(v, p, n) \
  (((v) >> (p)) & ((1UL << (n)) - 1))

RCC_TypeDef *RCC_ClockConfigs = ((RCC_TypeDef *) RCC_BASE);


/* RCC_CR Register Starts */
void RCC_EnableMSI(RccMsiRng_t range,bool En)
{
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_MSIRANGE_Pos,4,range);
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_MSION_Pos,1,En);
    while(GET(RCC_ClockConfigs->CR,RCC_CR_MSIRDY_Pos)!=1);
    /*Will put a whle loop here to check if its enabled?*/

}

void RCC_MsiRangeSelect(RccMsiRngSel_t RangeSrc)
{
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_MSIRGSEL_Pos,1,RangeSrc);
}


void RCC_EnableHSI(bool kernelClock, bool autoStartStop,bool En)
{
    
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_HSIKERON_Pos,1,kernelClock);
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_HSIASFS_Pos,1,autoStartStop);
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_HSION_Pos,1,En);
    while(GET(RCC_ClockConfigs->CR,RCC_CR_HSIRDY_Pos)!=1);
}

void RCC_EnableHSE(RccHseByPass_t ByPassSetting,bool ClkSecuSet,bool En)
{
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_HSEBYP_Pos,1,ByPassSetting);
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_CSSON_Pos,1,ClkSecuSet);
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_HSEON_Pos,1,En);
    while(GET(RCC_ClockConfigs->CR,RCC_CR_HSERDY_Pos)!=1);
}

void RCC_EnableMainPLL(bool En)
{
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_PLLON_Pos,1,En);

    while(GET(RCC_ClockConfigs->CR,RCC_CR_PLLRDY_Pos)!=1);
}

void RCC_EnablePLLSAI1(bool En)
{
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_PLLSAI1ON_Pos,1,En);
    while(GET(RCC_ClockConfigs->CR,RCC_CR_PLLSAI1RDY_Pos)!=1);
}


/*RCC_CR Register Ends*/

/* RCC_CFGR Register Starts */

void RCC_SetSystemClockSource(RCCSysClkSource_t source)
{
    SET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_SW_Pos,2,source);

    while(GET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_SW_Pos,2) != source);
}

void RCC_SetAHBPrescaler(AhbPrescaler_t prescaler)
{
    SET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_HPRE_Pos,4,prescaler);
}

void RCC_SetAPB1Prescaler(Apb1Prescaler_t prescaler)
{
    SET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_PPRE1_Pos,3,prescaler);
}

void RCC_SetAPB2Prescaler(Apb1Prescaler_t prescaler)
{
    SET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_PPRE2_Pos,3,prescaler);
}

 void RCC_ConfigureMCO(RccMcoSource_t source, RccMcoPrescaler_t prescaler)
 {
    SET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_MCOSEL_Pos,4,source);
    SET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_MCOPRE_Pos,3,prescaler);
 }
 
/* RCC_CFGR Register Ends */

/* RCC_PLLCFGR Register Starts */

void RCC_ConfigurePllSrc(RccPllSrc_t PllSrc)
{
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLSRC_Pos,2,PllSrc);
}

void RCC_ConfigurePllSettings(RccPllM_t RccPllM,RccPllP_t RccPllP ,RccPllQ_t RccPllQ,RccPllR_t RccPllR,uint8_t RccPllN,uint8_t RccPllDiv)
{
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLM_Pos,3,RccPllM);
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLN_Pos,7,RccPllN);
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLP_Pos,1,RccPllP);
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLQ_Pos,2,RccPllQ);
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLR_Pos,2,RccPllR);
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLPDIV_Pos,5,RccPllDiv);
}

void RCC_EnablePllR(bool En)
{
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLREN_Pos,1,En);
}

void RCC_EnablePllQ(bool En)
{
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLQEN_Pos,1,En);
}

void RCC_EnablePllP(bool En)
{
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLPEN_Pos,1,En);
}
/* RCC_PLLCFGR Register Ends */

/* RCC_PLLSAI1CFGR Register Starts */
void RCC_ConfigurePllSai1Settings(RccPllM_t RccPllM,RccPllP_t RccPllP ,RccPllQ_t RccPllQ,RccPllR_t RccPllR,uint8_t RccPllSai1N,uint8_t RccPllSai1Div)
{
    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1N_Pos,7,RccPllSai1N);
    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1P_Pos,1,RccPllP);
    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1Q_Pos,2,RccPllQ);
    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1R_Pos,2,RccPllR);
    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos,5,RccPllSai1Div);
}

void RCC_EnablePllSai1R(bool En)
{
    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1REN_Pos,1,En);
}

void RCC_EnablePllSai1Q(bool En)
{
    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1QEN_Pos,1,En);
}

void RCC_EnablePllSai1P(bool En)
{
    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1PEN_Pos,1,En);
}

/* RCC_PLLSAI1CFGR Register Ends */

/* RCC_CIER Register Starts */

void RCC_EnableInterrupt(Rcc_InterruptClock_t ClockType)
{

    switch(ClockType)
    {
        case RCC_LSIINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_LSIRDYIE_Pos,1,1);
            break;
        case RCC_LSEINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_LSERDYIE_Pos,1,1);
            break;
        case RCC_MSIINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_MSIRDYIE_Pos,1,1);
            break;
        case RCC_HSIINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_HSIRDYIE_Pos,1,1);
            break;
        case RCC_HSEINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_HSERDYIE_Pos,1,1);
            break;
        case RCC_PLLINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_PLLRDYIE_Pos,1,1);
            break;
        case RCC_PLLSAI1INTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_PLLSAI1RDYIE_Pos,1,1);
            break;
        case RCC_LSECSSINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_LSECSSIE_Pos,1,1);
            break;
        case RCC_HSI48INTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_HSI48RDYIE_Pos,1,1);
            break;
        default:
            return;
    }
}

/* RCC_CIER Register Ends */

/* RCC_CIFR Register Starts */
bool RCC_GetClockInterrupt(Rcc_InterruptClock_t ClockType)
{

    switch(ClockType)
    {
        case RCC_LSIINTR:
            return GET(RCC_ClockConfigs->CIFR,RCC_CIFR_LSIRDYF_Pos);
        case RCC_LSEINTR:
            return GET(RCC_ClockConfigs->CIFR,RCC_CIFR_LSERDYF_Pos);
        case RCC_MSIINTR:
            return GET(RCC_ClockConfigs->CIFR,RCC_CIFR_MSIRDYF_Pos);
        case RCC_HSIINTR:
            return GET(RCC_ClockConfigs->CIFR,RCC_CIFR_HSIRDYF_Pos);
        case RCC_HSEINTR:
            return GET(RCC_ClockConfigs->CIFR,RCC_CIFR_HSERDYF_Pos);
        case RCC_PLLINTR:
            return GET(RCC_ClockConfigs->CIFR,RCC_CIFR_PLLRDYF_Pos);
        case RCC_PLLSAI1INTR:
            return GET(RCC_ClockConfigs->CIFR,RCC_CIFR_PLLSAI1RDYF_Pos);
        case RCC_LSECSSINTR:
            return GET(RCC_ClockConfigs->CIFR,RCC_CIFR_LSECSSF_Pos);
        case RCC_HSI48INTR:
            return GET(RCC_ClockConfigs->CIFR,RCC_CIFR_HSI48RDYF_Pos);
        default:
            return 0;
    }
}
/* RCC_CIFR Register Ends */

/* RCC_CICSR Register Starts */
void RCC_ClearClockInterrupt(Rcc_InterruptClock_t ClockType)
{

    switch(ClockType)
    {
        case RCC_LSIINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_LSIRDYC_Pos);
            break;
        case RCC_LSEINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_LSERDYC_Pos);
            break;
        case RCC_MSIINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_MSIRDYC_Pos);
            break;
        case RCC_HSIINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_HSIRDYC_Pos);
            break;
        case RCC_HSEINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_HSERDYC_Pos);
            break;
        case RCC_PLLINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_PLLRDYC_Pos);
            break;
        case RCC_PLLSAI1INTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_PLLSAI1RDYC_Pos);
            break;
        case RCC_LSECSSINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_LSECSSC_Pos);
            break;
        case RCC_HSI48INTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_HSI48RDYC_Pos);
            break;
        default:
            return;
    }
}
/* RCC_CICR Register Ends */

/*RCC AHB1RSTR Register starts*/

void RCC_ResetAhb1Peripheral(Rcc_Ahb1Peripheral_t peripheral)
{
    switch (peripheral)
    {
        case AHB1_DMA1:
            SET(RCC_ClockConfigs->AHB1RSTR,RCC_AHB1RSTR_DMA1RST_Pos);
            CLEAR(RCC_ClockConfigs->AHB1RSTR,RCC_AHB1RSTR_DMA1RST_Pos);
            break;
        case AHB1_DMA2:
            SET(RCC_ClockConfigs->AHB1RSTR,RCC_AHB1RSTR_DMA2RST_Pos);
            CLEAR(RCC_ClockConfigs->AHB1RSTR,RCC_AHB1RSTR_DMA2RST_Pos);
            break;
        case AHB1_FLASH:
            SET(RCC_ClockConfigs->AHB1RSTR,RCC_AHB1RSTR_FLASHRST_Pos);
            CLEAR(RCC_ClockConfigs->AHB1RSTR,RCC_AHB1RSTR_FLASHRST_Pos);
            break;
        case AHB1_CRC:
            SET(RCC_ClockConfigs->AHB1RSTR,RCC_AHB1RSTR_CRCRST_Pos);
            CLEAR(RCC_ClockConfigs->AHB1RSTR,RCC_AHB1RSTR_CRCRST_Pos);
            break;
        case AHB1_TSC:
            SET(RCC_ClockConfigs->AHB1RSTR,RCC_AHB1RSTR_TSCRST_Pos);
            CLEAR(RCC_ClockConfigs->AHB1RSTR,RCC_AHB1RSTR_TSCRST_Pos);
            break;
        default:
            return;
    }   
}
/*RCC AHB1RSTR Register ends*/

/*RCC AHB2RSTR Register starts*/

void RCC_ResetAhb2Peripheral(Rcc_Ahb2Peripheral_t peripheral)
{
    switch (peripheral)
    {
        case AHB2_GPIOA:
            SET(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_GPIOARST_Pos);
            CLEAR(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_GPIOARST_Pos);
            break;
        case AHB2_GPIOB:
            SET(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_GPIOBRST_Pos);
            CLEAR(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_GPIOBRST_Pos);
            break;
        case AHB2_GPIOC:
            SET(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_GPIOCRST_Pos);
            CLEAR(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_GPIOCRST_Pos);
            break;
        case AHB2_GPIOD:
            SET(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_GPIODRST_Pos);
            CLEAR(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_GPIODRST_Pos);
            break;
        case AHB2_GPIOE:
            SET(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_GPIOERST_Pos);
            CLEAR(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_GPIOERST_Pos);
            break;
        case AHB2_GPIOH:
            SET(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_GPIOHRST_Pos);
            CLEAR(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_GPIOHRST_Pos);
            break;
        case AHB2_ADC:
            SET(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_ADCRST_Pos);
            CLEAR(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_ADCRST_Pos);
            break;
        case AHB2_RNG:
            SET(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_RNGRST_Pos);
            CLEAR(RCC_ClockConfigs->AHB2RSTR,RCC_AHB2RSTR_RNGRST_Pos);
            break;
        default:
    } 
}
void RCC_ResetAhb3Peripheral(Rcc_Ahb3Peripheral_t peripheral)
{
    switch (peripheral)
    {
        case AHB3_QSPI:
            SET(RCC_ClockConfigs->AHB3RSTR,RCC_AHB3RSTR_QSPIRST_Pos);
            CLEAR(RCC_ClockConfigs->AHB3RSTR,RCC_AHB3RSTR_QSPIRST_Pos);
            break;
        default:
    }    
}

/*RCC AHB2RSTR Register ends*/

/*RCC APB1RSTR1 Register starts*/

void RCC_ResetApb1Peripheral1(Rcc_Apb1Peripheral1_t peripheral)
{
        switch (peripheral)
    {
        case APB1_TIM2:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_TIM2RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_TIM2RST_Pos);
            break;
        case APB1_TIM6:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_TIM6RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_TIM6RST_Pos);
            break;
        case APB1_TIM7:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_TIM7RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_TIM7RST_Pos);
            break;
        case APB1_LCD:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_LCDRST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_LCDRST_Pos);
            break;
        case APB1_SPI2:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_SPI2RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_SPI2RST_Pos);
            break;
        case APB1_SPI3:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_SPI3RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_SPI3RST_Pos);
            break;
        case APB1_USART2:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_USART2RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_USART2RST_Pos);
            break;
        case APB1_USART3:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_USART3RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_USART3RST_Pos);
            break;
        case APB1_I2C1:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_I2C1RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_I2C1RST_Pos);
            break;
        case APB1_I2C2:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_I2C2RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_I2C2RST_Pos);
            break;
        case APB1_I2C3:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_I2C3RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_I2C3RST_Pos);
            break;
        case APB1_CRS:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_CRSRST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_CRSRST_Pos);
            break;
        case APB1_CAN1:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_CAN1RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_CAN1RST_Pos);
            break;
        case APB1_USBFS:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_USBFSRST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_USBFSRST_Pos);
            break;
        case APB1_PWR:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_PWRRST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_PWRRST_Pos);
            break;
        case APB1_DAC1:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_DAC1RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_DAC1RST_Pos);
            break;
        case APB1_OPAMP:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_OPAMPRST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_OPAMPRST_Pos);
            break;
        case APB1_LPTIM1:
            SET(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_LPTIM1RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR1,RCC_APB1RSTR1_LPTIM1RST_Pos);
            break;
        default:
            return;
    }
}
/*RCC APB1RSTR1 Register ends*/

/*RCC APB1RSTR2 Register starts*/
void RCC_ResetApb1Peripheral2(Rcc_Apb1Peripheral2_t peripheral)
{
        switch (peripheral)
    {
        case APB1P2_LPUART1:
            SET(RCC_ClockConfigs->APB1RSTR2,RCC_APB1RSTR2_LPUART1RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR2,RCC_APB1RSTR2_LPUART1RST_Pos);
            break;
        case APB1P2_SWPMI1:
            SET(RCC_ClockConfigs->APB1RSTR2,RCC_APB1RSTR2_SWPMI1RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR2,RCC_APB1RSTR2_SWPMI1RST_Pos);
            break;
        case APB1P2_LPTIM2:
            SET(RCC_ClockConfigs->APB1RSTR2,RCC_APB1RSTR2_LPTIM2RST_Pos);
            CLEAR(RCC_ClockConfigs->APB1RSTR2,RCC_APB1RSTR2_LPTIM2RST_Pos);
            break;
        default:
            return;
    }

}
/*RCC APB1RSTR2 Register ends*/
/*RCC APB2RSTR Register starts*/

void RCC_ResetApb2Peripheral(Rcc_Apb2Peripheral_t peripheral)
{
    switch (peripheral)
    {
        case APB2_SYSCFG:
            SET(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_SYSCFGRST_Pos);
            CLEAR(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_SYSCFGRST_Pos);
            break;
        case APB2_SDMMC:
            SET(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_SDMMC1RST_Pos);
            CLEAR(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_SDMMC1RST_Pos);
            break;
        case APB2_TIM1:
            SET(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_TIM1RST_Pos);
            CLEAR(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_TIM1RST_Pos);
            break;
        case APB2_SPI1:
            SET(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_SPI1RST_Pos);
            CLEAR(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_SPI1RST_Pos);
            break;
        case APB2_USART1:
            SET(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_USART1RST_Pos);
            CLEAR(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_USART1RST_Pos);
            break;
        case APB2_TIM15:
            SET(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_TIM15RST_Pos);
            CLEAR(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_TIM15RST_Pos);
            break;
        case APB2_TIM16:
            SET(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_TIM16RST_Pos);
            CLEAR(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_TIM16RST_Pos);
            break;
        case APB2_SAI1:
            SET(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_SAI1RST_Pos);
            CLEAR(RCC_ClockConfigs->APB2RSTR,RCC_APB2RSTR_SAI1RST_Pos);
            break;
        default:
            return;
    }
}


/*RCC APB2RSTR Register ends*/

/*RCC AHB1ENR Starts*/
void RCC_EnableAhb1Peripheral(Rcc_Ahb1Peripheral_t peripheral)
{
    switch (peripheral)
    {
        case AHB1_DMA1:
            SET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_DMA1EN_Pos);
            break;
        case AHB1_DMA2:
            SET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_DMA2EN_Pos);
            break;
        case AHB1_FLASH:
            SET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_FLASHEN_Pos);
            break;
        case AHB1_CRC:
            SET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_CRCEN_Pos);
            break;
        case AHB1_TSC:
            SET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_TSCEN_Pos);
            break;
        default:
            return;
    }   
}
/*RCC AHB1ENR Ends*/
/*RCC AHB2ENR Starts*/
void RCC_EnableAhb2Peripheral(Rcc_Ahb2Peripheral_t peripheral)
{
    switch (peripheral)
    {
        case AHB2_GPIOA:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_GPIOAEN_Pos);
            break;
        case AHB2_GPIOB:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_GPIOBEN_Pos);
            break;
        case AHB2_GPIOC:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_GPIOCEN_Pos);
            break;
        case AHB2_GPIOD:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_GPIODEN_Pos);
            break;
        case AHB2_GPIOE:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_GPIOEEN_Pos);
            break;
        case AHB2_GPIOH:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_GPIOHEN_Pos);
            break;
        case AHB2_ADC:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_ADCEN_Pos);
            break;
        case AHB2_RNG:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_RNGEN_Pos);
            break;
        default:
            return;
    } 
}

/*RCC AHB2ENR Ends*/

/*RCC AHB3ENR Starts*/
void RCC_EnableAhb3Peripheral(Rcc_Ahb3Peripheral_t peripheral)
{
    switch (peripheral)
    {
        case AHB3_QSPI:
            SET(RCC_ClockConfigs->AHB3ENR,RCC_AHB3ENR_QSPIEN_Pos);
            break;
        default:
    }    
}
/*RCC AHB3ENR Ends*/

/*RCC APB1ENR Register starts*/

void RCC_EnableApb1Peripheral1(Rcc_Apb1Peripheral1_t peripheral)
{
        switch (peripheral)
    {
        case APB1_TIM2:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_TIM2EN_Pos);
            break;
        case APB1_TIM6:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_TIM6EN_Pos);
            break;
        case APB1_TIM7:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_TIM7EN_Pos);
            break;
        case APB1_LCD:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_LCDEN_Pos);
            break;
        case APB1_SPI2:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_SPI2EN_Pos);
            break;
        case APB1_SPI3:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_SPI3EN_Pos);
            break;
        case APB1_USART2:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_USART2EN_Pos);
            break;
        case APB1_USART3:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_USART3EN_Pos);
            break;
        case APB1_I2C1:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_I2C1EN_Pos);
            break;
        case APB1_I2C2:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_I2C2EN_Pos);
            break;
        case APB1_I2C3:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_I2C3EN_Pos);
            break;
        case APB1_CRS:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_CRSEN_Pos);
            break;
        case APB1_CAN1:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_CAN1EN_Pos);
            break;
        case APB1_USBFS:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_USBFSEN_Pos);
            break;
        case APB1_PWR:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_PWREN_Pos);
            break;
        case APB1_DAC1:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_DAC1EN_Pos);
            break;
        case APB1_OPAMP:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_OPAMPEN_Pos);
            break;
        case APB1_LPTIM1:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_LPTIM1EN_Pos);
            break;
        default:
            return;
    }
}
/*RCC APB1ENR Register ends*/

/*RCC APB1RSTR2 Register starts*/
void RCC_EnableApb1Peripheral2(Rcc_Apb1Peripheral2_t peripheral)
{
    switch (peripheral)
    {
        case APB1P2_LPUART1:
            SET(RCC_ClockConfigs->APB1ENR2,RCC_APB1ENR2_LPUART1EN_Pos);
            break;
        case APB1P2_SWPMI1:
            SET(RCC_ClockConfigs->APB1ENR2,RCC_APB1ENR2_SWPMI1EN_Pos);
            break;
        case APB1P2_LPTIM2:
            SET(RCC_ClockConfigs->APB1ENR2,RCC_APB1ENR2_LPTIM2EN_Pos);
            break;
        default:
            return;
    }

}
/*RCC APB1RSTR2 Register ends*/


/*RCC APB2ENR Register starts*/

void RCC_EnableApb2Peripheral(Rcc_Apb2Peripheral_t peripheral)
{
    switch (peripheral)
    {
        case APB2_SYSCFG:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_SYSCFGEN_Pos);
            break;
        case APB2_SDMMC:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_SDMMC1EN_Pos);
            break;
        case APB2_TIM1:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_TIM1EN_Pos);
            break;
        case APB2_SPI1:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_SPI1EN_Pos);
            break;
        case APB2_USART1:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_USART1EN_Pos);
            break;
        case APB2_TIM15:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_TIM15EN_Pos);
            break;
        case APB2_TIM16:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_TIM16EN_Pos);
            break;
        case APB2_SAI1:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_SAI1EN_Pos);
            break;
        default:
            return;
    }
}


/*RCC APB2ENR Register ends*/ 

/*RCC AHB1ENR Starts*/
void RCC_EnableDuringSleepAhb1Peripheral(Rcc_Ahb1Peripheral_t peripheral,bool SleepEn)
{
    switch (peripheral)
    {
        case AHB1_DMA1:
            SET_BITS(RCC_ClockConfigs->AHB1SMENR,RCC_AHB1SMENR_DMA1SMEN_Pos,1,SleepEn);
            break;
        case AHB1_DMA2:
            SET_BITS(RCC_ClockConfigs->AHB1SMENR,RCC_AHB1SMENR_DMA2SMEN_Pos,1,SleepEn);
            break;
        case AHB1_FLASH:
            SET_BITS(RCC_ClockConfigs->AHB1SMENR,RCC_AHB1SMENR_FLASHSMEN_Pos,1,SleepEn);
            break;
        case AHB1_CRC:
            SET_BITS(RCC_ClockConfigs->AHB1SMENR,RCC_AHB1SMENR_CRCSMEN_Pos,1,SleepEn);
            break;
        case AHB1_TSC:
            SET_BITS(RCC_ClockConfigs->AHB1SMENR,RCC_AHB1SMENR_TSCSMEN_Pos,1,SleepEn);
            break;
        default:
            return;
    }   
}
/*RCC AHB1ENR Ends*/
/*RCC AHB2ENR Starts*/
void RCC_EnableDuringSleepAhb2Peripheral(Rcc_Ahb2Peripheral_t peripheral,bool SleepEn)
{
    switch (peripheral)
    {
        case AHB2_GPIOA:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_GPIOASMEN_Pos,1,SleepEn);
            break;
        case AHB2_GPIOB:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_GPIOBSMEN_Pos,1,SleepEn);
            break;
        case AHB2_GPIOC:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_GPIOCSMEN_Pos,1,SleepEn);
            break;
        case AHB2_GPIOD:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_GPIODSMEN_Pos,1,SleepEn);
            break;
        case AHB2_GPIOE:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_GPIOESMEN_Pos,1,SleepEn);
            break;
        case AHB2_GPIOH:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_GPIOHSMEN_Pos,1,SleepEn);
            break;
        case AHB2_ADC:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_ADCSMEN_Pos,1,SleepEn);
            break;
        case AHB2_RNG:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_RNGSMEN_Pos,1,SleepEn);
            break;
    } 
}

/*RCC AHB2ENR Ends*/

/*RCC AHB3ENR Starts*/
void RCC_EnableDuringSleepAhb3Peripheral(Rcc_Ahb3Peripheral_t peripheral,bool SleepEn)
{
    switch (peripheral)
    {
        case AHB3_QSPI:
            SET_BITS(RCC_ClockConfigs->AHB3SMENR,RCC_AHB3SMENR_QSPISMEN_Pos,1,SleepEn);
            break;
        default:
    }    
}
/*RCC AHB3ENR Ends*/

/*RCC APB1ENR Register starts*/

void RCC_EnableDuringSleepApb1Peripheral1(Rcc_Apb1Peripheral1_t peripheral,bool SleepEn)
{
    switch (peripheral)
    {
        case APB1_TIM2:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_TIM2SMEN_Pos,1,SleepEn);
            break;
        case APB1_TIM6:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_TIM6SMEN_Pos,1,SleepEn);
            break;
        case APB1_TIM7:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_TIM7SMEN_Pos,1,SleepEn);
            break;
        case APB1_LCD:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_LCDSMEN_Pos,1,SleepEn);
            break;
        case APB1_SPI2:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_SPI2SMEN_Pos,1,SleepEn);
            break;
        case APB1_SPI3:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_SPI3SMEN_Pos,1,SleepEn);
            break;
        case APB1_USART2:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_USART2SMEN_Pos,1,SleepEn);
            break;
        case APB1_USART3:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_USART3SMEN_Pos,1,SleepEn);
            break;
        case APB1_I2C1:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_I2C1SMEN_Pos,1,SleepEn);
            break;
        case APB1_I2C2:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_I2C2SMEN_Pos,1,SleepEn);
            break;
        case APB1_I2C3:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_I2C3SMEN_Pos,1,SleepEn);
            break;
        case APB1_CRS:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_CRSSMEN_Pos,1,SleepEn);
            break;
        case APB1_CAN1:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_CAN1SMEN_Pos,1,SleepEn);
            break;
        case APB1_USBFS:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_USBFSSMEN_Pos,1,SleepEn);
            break;
        case APB1_PWR:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_PWRSMEN_Pos,1,SleepEn);
            break;
        case APB1_DAC1:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_DAC1SMEN_Pos,1,SleepEn);
            break;
        case APB1_OPAMP:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_OPAMPSMEN_Pos,1,SleepEn);
            break;
        case APB1_LPTIM1:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1,RCC_APB1SMENR1_LPTIM1SMEN_Pos,1,SleepEn);
            break;
        default:
            return;
    }
}
/*RCC APB1ENR Register ends*/

/*RCC APB1RSTR2 Register starts*/
void RCC_EnableDuringSleepApb1Peripheral2(Rcc_Apb1Peripheral2_t peripheral,bool SleepEn)
{
    switch (peripheral)
    {
        case APB1P2_LPUART1:
            SET_BITS(RCC_ClockConfigs->APB1SMENR2,RCC_APB1SMENR2_LPUART1SMEN_Pos,1,SleepEn);
            break;
        case APB1P2_SWPMI1:
            SET_BITS(RCC_ClockConfigs->APB1SMENR2,RCC_APB1SMENR2_SWPMI1SMEN_Pos,1,SleepEn);
            break;
        case APB1P2_LPTIM2:
            SET_BITS(RCC_ClockConfigs->APB1SMENR2,RCC_APB1SMENR2_LPTIM2SMEN_Pos,1,SleepEn);
            break;
        default:
            return;
    }

}
/*RCC APB1RSTR2 Register ends*/


/*RCC APB2ENR Register starts*/

void RCC_EnableDuringSleepApb2Peripheral(Rcc_Apb2Peripheral_t peripheral,bool SleepEn)
{
    switch (peripheral)
    {
        case APB2_SYSCFG:
            SET_BITS(RCC_ClockConfigs->APB2SMENR,RCC_APB2SMENR_SYSCFGSMEN_Pos,1,SleepEn);
            break;
        case APB2_SDMMC:
            SET_BITS(RCC_ClockConfigs->APB2SMENR,RCC_APB2SMENR_SDMMC1SMEN_Pos,1,SleepEn);
            break;
        case APB2_TIM1:
            SET_BITS(RCC_ClockConfigs->APB2SMENR,RCC_APB2SMENR_TIM1SMEN_Pos,1,SleepEn);
            break;
        case APB2_SPI1:
            SET_BITS(RCC_ClockConfigs->APB2SMENR,RCC_APB2SMENR_SPI1SMEN_Pos,1,SleepEn);
            break;
        case APB2_USART1:
            SET_BITS(RCC_ClockConfigs->APB2SMENR,RCC_APB2SMENR_USART1SMEN_Pos,1,SleepEn);
            break;
        case APB2_TIM15:
            SET_BITS(RCC_ClockConfigs->APB2SMENR,RCC_APB2SMENR_TIM15SMEN_Pos,1,SleepEn);
            break;
        case APB2_TIM16:
            SET_BITS(RCC_ClockConfigs->APB2SMENR,RCC_APB2SMENR_TIM16SMEN_Pos,1,SleepEn);
            break;
        case APB2_SAI1:
            SET_BITS(RCC_ClockConfigs->APB2SMENR,RCC_APB2SMENR_SAI1SMEN_Pos,1,SleepEn);
            break;
        default:
            return;
    }
}

void RCC_ConfigureCciprClocks(Rcc_CciprPeripheral_t peripheral , Rcc_Ccipr_ClockSrc_t src)
{
    switch (peripheral)
    {
        case CCIPR_USART1SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_USART1SEL_Pos, 2, src);
            break;
        case CCIPR_USART2SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_USART2SEL_Pos, 2, src);
            break;
        case CCIPR_USART3SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_USART3SEL_Pos, 2, src);
            break;
        case CCIPR_LPUART1SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_LPUART1SEL_Pos, 2, src); 
            break;
        case CCIPR_I2C1SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_I2C1SEL_Pos, 2, src);
            break;
        case CCIPR_I2C2SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_I2C2SEL_Pos, 2, src);
            break;
        case CCIPR_I2C3SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_I2C3SEL_Pos, 2, src);
            break;
        case CCIPR_LPTIM1SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_LPTIM1SEL_Pos, 2, src); 
            break;
        case CCIPR_LPTIM2SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_LPTIM2SEL_Pos, 2, src); 
            break;
        case CCIPR_SAISEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_SAI1SEL_Pos, 2, src); 
            break;
        case CCIPR_CLK48SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_CLK48SEL_Pos, 2, src);
            break;
        case CCIPR_ADCSEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_ADCSEL_Pos, 2, src); 
            break;
        case CCIPR_SWPMI1:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_SWPMI1SEL_Pos, 1, src); 
            break;
        default:
            // Handle unknown peripheral or error
            return;
    }
}
/*RCC APB2ENR Register ends*/ 
/*RCC BDCR Starts */
void RCC_BdcrEnableLse(bool BdcrLseEn)
{
    SET_BITS(RCC_ClockConfigs->BDCR,RCC_BDCR_LSEON_Pos,1,BdcrLseEn);
}

void RCC_BdcrConfigureLseByp(bool BypEn)
{
    SET_BITS(RCC_ClockConfigs->BDCR,RCC_BDCR_LSEBYP_Pos,1,BypEn);
}

void RCC_BdcrConfigureLseSpeed(Rcc_Bdcr_LseSpeed_t spd)
{
    SET_BITS(RCC_ClockConfigs->BDCR,RCC_BDCR_LSEDRV_Pos,2,spd);
}

void RCC_BdcrLseCssConfigure(bool LseCssEn)
{
    SET_BITS(RCC_ClockConfigs->BDCR,RCC_BDCR_LSECSSON_Pos,1,LseCssEn);
}


void Rcc_BdcrConfigureRtcSource(Rcc_Bdcr_RtcSource_t src)
{
    SET_BITS(RCC_ClockConfigs->BDCR,RCC_BDCR_RTCSEL_Pos,2,src);
}

void Rcc_BdcrConfigureRtcClk(bool RtcClkEn)
{
    SET_BITS(RCC_ClockConfigs->BDCR,RCC_BDCR_RTCEN_Pos,1,RtcClkEn);
}

void Rcc_BdcrConfigureBdRst(bool BdRst)
{
    SET_BITS(RCC_ClockConfigs->BDCR,RCC_BDCR_BDRST_Pos,1,BdRst);
}

void Rcc_ConfigureLscoEn(bool LscoEn)
{
    SET_BITS(RCC_ClockConfigs->BDCR,RCC_BDCR_LSCOEN_Pos,1,LscoEn);
}

void Rcc_ConfigureLseSel(bool LseSel)
{
    SET_BITS(RCC_ClockConfigs->BDCR,RCC_BDCR_LSCOSEL_Pos,1,LseSel);
}

/*RCC BDCR Ends*/

/*RCC CSR Starts*/

void Rcc_EnableLsiCsr(bool LsiCsrEn)
{
    SET_BITS(RCC_ClockConfigs->CSR,RCC_CSR_LSION_Pos,1,LsiCsrEn);
}
void Rcc_ConfigureMsiRangeCsr(Rcc_CsrMsiRng_t MsiRange)
{
    SET_BITS(RCC_ClockConfigs->CSR,RCC_CSR_MSISRANGE_Pos,4,MsiRange);
}

void Rcc_RmVfCsr(bool RmvfEn)
{
    SET_BITS(RCC_ClockConfigs->CSR,RCC_CSR_RMVF_Pos,1,RmvfEn);
}
/*RCC CSR Ends*/

/*RCC CRRCR Starts*/

void Rcc_CrrCrHsi48Enable(bool Hsi48En)
{
   SET_BITS(RCC_ClockConfigs->CRRCR,RCC_CRRCR_HSI48ON_Pos,1,Hsi48En); 
}

/*RCC CRRCR Ends*/
