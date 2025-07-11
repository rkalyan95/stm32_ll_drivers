
#include <stm32l433_ll_rcc.h>
#include <stdbool.h>

typedef uint8_t (*register_readfunction_t)(void);

#define MAX_TIMEOUTVALUE 10000

#define GET(x,pos)   ((x & 1UL<<pos) >> pos)
#define SET(x,pos)   (x |= (1UL<<pos))
#define CLEAR(x,pos)   (x &= ~(1UL<<pos))
#define TOGGLE(x,pos) (x ^= 1UL<<pos)
#define SET_BITS(v, p, n, new_val) \
  ((v) = ((v) & ~(((1UL << (n)) - 1) << (p))) | (((new_val) & ((1UL << (n)) - 1)) << (p)))

#define GET_BITS(v, p, n) \
  (((v) >> (p)) & ((1UL << (n)) - 1))

static RCC_TypeDef *RCC_ClockConfigs = ((RCC_TypeDef *) RCC_BASE);

static Error_t TimeoutHandler(register_readfunction_t rdy_func,uint8_t expected_value,uint32_t timeout)
{
    uint8_t currentvalue;
    do
    {
        currentvalue = rdy_func();
        timeout--;

    }while((currentvalue!=expected_value) && (timeout>0));

    if(timeout == 0)
    {
        return ERR_TIMEOUT;
    }
    else 
    {
        return ERR_SUCCESS;
    }
    
}

static uint8_t get_msirdy(void)
{
    return GET(RCC_ClockConfigs->CR,RCC_CR_MSIRDY_Pos);
}

static uint8_t get_hsirdy(void)
{
    return GET(RCC_ClockConfigs->CR,RCC_CR_HSIRDY_Pos);
}

static uint8_t get_hserdy(void)
{
    return GET(RCC_ClockConfigs->CR,RCC_CR_HSERDY_Pos);
}

static uint8_t get_pllrdy(void)
{
    return GET(RCC_ClockConfigs->CR,RCC_CR_PLLRDY_Pos);
}

static uint8_t get_pllsai1rdy(void)
{
    return GET(RCC_ClockConfigs->CR,RCC_CR_PLLSAI1RDY_Pos);
}


/* RCC_CR Register Starts */
Error_t RCC_EnableMSI(RccMsiRng_t range,bool En)
{
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_MSIRANGE_Pos,4,range);
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_MSION_Pos,1,En);
    return TimeoutHandler(get_msirdy, En ,MAX_TIMEOUTVALUE);
}

Error_t RCC_MsiRangeSelect(RccMsiRngSel_t RangeSrc)
{
    Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_MSIRGSEL_Pos,1,RangeSrc);
    RetCode = (GET_BITS(RCC_ClockConfigs->CR,RCC_CR_MSIRGSEL_Pos,1)==RangeSrc);
    return RetCode;
}


Error_t RCC_EnableHSI(bool kernelClock, bool autoStartStop,bool En)
{
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_HSIKERON_Pos,1,kernelClock);
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_HSIASFS_Pos,1,autoStartStop);
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_HSION_Pos,1,En);
    return TimeoutHandler(get_hsirdy,En,MAX_TIMEOUTVALUE);
}

Error_t RCC_EnableHSE(RccHseByPass_t ByPassSetting,bool ClkSecuSet,bool En)
{

    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_HSEBYP_Pos,1,ByPassSetting);
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_CSSON_Pos,1,ClkSecuSet);
    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_HSEON_Pos,1,En);
    return TimeoutHandler(get_hserdy,En,MAX_TIMEOUTVALUE);

}

Error_t RCC_EnableMainPLL(bool En)
{
    Error_t RetCode=ERR_FAILED;

    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_PLLON_Pos,1,En);

    return TimeoutHandler(get_pllrdy,En,MAX_TIMEOUTVALUE);

}

Error_t RCC_EnablePLLSAI1(bool En)
{
    Error_t RetCode=ERR_FAILED;

    SET_BITS(RCC_ClockConfigs->CR,RCC_CR_PLLSAI1ON_Pos,1,En);

    return TimeoutHandler(get_pllsai1rdy,En,MAX_TIMEOUTVALUE);

}


/*RCC_CR Register Ends*/

/* RCC_CFGR Register Starts */

Error_t RCC_SetSystemClockSource(RCCSysClkSource_t source)
{

    SET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_SW_Pos,2,source);
    return (GET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_SW_Pos,2)==source);

}

Error_t RCC_SetAHBPrescaler(AhbPrescaler_t prescaler)
{

    SET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_HPRE_Pos,4,prescaler);
    return (GET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_HPRE_Pos,4)==prescaler);

}

Error_t RCC_SetAPB1Prescaler(Apb1Prescaler_t prescaler)
{
    SET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_PPRE1_Pos,3,prescaler);
    return (GET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_PPRE1_Pos,3)==prescaler);
}

Error_t RCC_SetAPB2Prescaler(Apb1Prescaler_t prescaler)
{
    SET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_PPRE2_Pos,3,prescaler);
    return (GET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_PPRE2_Pos,3)==prescaler);
}

 Error_t RCC_ConfigureMCO(RccMcoSource_t source, RccMcoPrescaler_t prescaler)
 {

    SET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_MCOSEL_Pos,4,source);
    SET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_MCOPRE_Pos,3,prescaler);

    return (GET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_MCOPRE_Pos,3)==prescaler && GET_BITS(RCC_ClockConfigs->CFGR,RCC_CFGR_MCOSEL_Pos,4)==source);

 }
 
/* RCC_CFGR Register Ends */

/* RCC_PLLCFGR Register Starts */

Error_t RCC_ConfigurePllSrc(RccPllSrc_t PllSrc)
{

    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLSRC_Pos,2,PllSrc);

    return (GET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLSRC_Pos,2)==PllSrc);
}

Error_t RCC_ConfigurePllSettings(RccPllM_t RccPllM,RccPllP_t RccPllP ,RccPllQ_t RccPllQ,RccPllR_t RccPllR,uint8_t RccPllN,uint8_t RccPllDiv)
{
    Error_t RetCode=ERR_FAILED;

    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLM_Pos,3,RccPllM);
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLN_Pos,7,RccPllN);
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLP_Pos,1,RccPllP);
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLQ_Pos,2,RccPllQ);
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLR_Pos,2,RccPllR);
    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLPDIV_Pos,5,RccPllDiv);

    RetCode =     ((GET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLM_Pos,3)==RccPllM) 
                                    && (GET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLN_Pos,7)==RccPllN)
                                    && (GET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLP_Pos,1)==RccPllP)
                                    && (GET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLQ_Pos,2)==RccPllQ)
                                    && (GET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLR_Pos,2)==RccPllR)
                                    && (GET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLPDIV_Pos,5)==RccPllDiv));

    return RetCode;
}

Error_t RCC_EnablePllR(bool En)
{

    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLREN_Pos,1,En);

    return (GET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLREN_Pos,1)==En);
}

Error_t RCC_EnablePllQ(bool En)
{

    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLQEN_Pos,1,En);

    return (GET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLQEN_Pos,1)==En);
}

Error_t RCC_EnablePllP(bool En)
{

    SET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLPEN_Pos,1,En);
   
    return (GET_BITS(RCC_ClockConfigs->PLLCFGR,RCC_PLLCFGR_PLLPEN_Pos,1)==En);
}
/* RCC_PLLCFGR Register Ends */

/* RCC_PLLSAI1CFGR Register Starts */
Error_t RCC_ConfigurePllSai1Settings(RccPllM_t RccPllM,RccPllP_t RccPllP ,RccPllQ_t RccPllQ,RccPllR_t RccPllR,uint8_t RccPllSai1N,uint8_t RccPllSai1Div)
{
    Error_t RetCode=ERR_FAILED;

    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1N_Pos,7,RccPllSai1N);
    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1P_Pos,1,RccPllP);
    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1Q_Pos,2,RccPllQ);
    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1R_Pos,2,RccPllR);
    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos,5,RccPllSai1Div);

    RetCode =   ((GET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1N_Pos,7)==RccPllSai1N)
                    && (GET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1P_Pos,1)==RccPllP)
                    && (GET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1Q_Pos,2)==RccPllQ)
                    && (GET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1R_Pos,2)==RccPllR)
                    && (GET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos,5)==RccPllSai1Div));
    return RetCode;
}

Error_t RCC_EnablePllSai1R(bool En)
{
    Error_t RetCode=ERR_FAILED;

    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1REN_Pos,1,En);

    return (GET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1REN_Pos,1)==En);
}

Error_t RCC_EnablePllSai1Q(bool En)
{
    Error_t RetCode=ERR_FAILED;

    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1QEN_Pos,1,En);

    return (GET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1QEN_Pos,1)==En);
}

Error_t RCC_EnablePllSai1P(bool En)
{
    Error_t RetCode=ERR_FAILED;

    SET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1PEN_Pos,1,En);

    return (GET_BITS(RCC_ClockConfigs->PLLSAI1CFGR,RCC_PLLSAI1CFGR_PLLSAI1PEN_Pos,1)==En);
}

/* RCC_PLLSAI1CFGR Register Ends */

/* RCC_CIER Register Starts */

Error_t RCC_EnableInterrupt(Rcc_InterruptClock_t ClockType)
{
    Error_t RetCode=ERR_FAILED;

    switch(ClockType)
    {
        case RCC_LSIINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_LSIRDYIE_Pos,1,1);
            RetCode = (GET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_LSIRDYIE_Pos,1)==1);
            break;
        case RCC_LSEINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_LSERDYIE_Pos,1,1);
            RetCode = (GET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_LSERDYIE_Pos,1)==1);
            break;
        case RCC_MSIINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_MSIRDYIE_Pos,1,1);
            RetCode = (GET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_MSIRDYIE_Pos,1)==1);
            break;
        case RCC_HSIINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_HSIRDYIE_Pos,1,1);
            RetCode = (GET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_HSIRDYIE_Pos,1)==1);
            break;
        case RCC_HSEINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_HSERDYIE_Pos,1,1);
            RetCode = (GET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_HSERDYIE_Pos,1)==1);
            break;
        case RCC_PLLINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_PLLRDYIE_Pos,1,1);
            RetCode = (GET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_PLLRDYIE_Pos,1)==1);
            break;
        case RCC_PLLSAI1INTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_PLLSAI1RDYIE_Pos,1,1);
            RetCode = (GET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_PLLSAI1RDYIE_Pos,1)==1);
            break;
        case RCC_LSECSSINTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_LSECSSIE_Pos,1,1);
            RetCode = (GET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_LSECSSIE_Pos,1)==1);
            break;
        case RCC_HSI48INTR:
            SET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_HSI48RDYIE_Pos,1,1);
            RetCode = (GET_BITS(RCC_ClockConfigs->CIER,RCC_CIER_HSI48RDYIE_Pos,1)==1);
            break;
        default:
            return RetCode;
    }

    return RetCode;
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
Error_t RCC_ClearClockInterrupt(Rcc_InterruptClock_t ClockType)
{

    Error_t RetCode=ERR_FAILED;

    switch(ClockType)
    {
        case RCC_LSIINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_LSIRDYC_Pos);
            RetCode = GET(RCC_ClockConfigs->CICR,RCC_CICR_LSIRDYC_Pos);
            break;
        case RCC_LSEINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_LSERDYC_Pos);
            RetCode = GET(RCC_ClockConfigs->CICR,RCC_CICR_LSERDYC_Pos);
            break;
        case RCC_MSIINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_MSIRDYC_Pos);
            RetCode = GET(RCC_ClockConfigs->CICR,RCC_CICR_MSIRDYC_Pos);
            break;
        case RCC_HSIINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_HSIRDYC_Pos);
            RetCode = GET(RCC_ClockConfigs->CICR,RCC_CICR_HSIRDYC_Pos);
            break;
        case RCC_HSEINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_HSERDYC_Pos);
            RetCode = GET(RCC_ClockConfigs->CICR,RCC_CICR_HSERDYC_Pos);
            break;
        case RCC_PLLINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_PLLRDYC_Pos);
            RetCode = GET(RCC_ClockConfigs->CICR,RCC_CICR_PLLRDYC_Pos);
            break;
        case RCC_PLLSAI1INTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_PLLSAI1RDYC_Pos);
            RetCode = GET(RCC_ClockConfigs->CICR,RCC_CICR_PLLSAI1RDYC_Pos);
            break;
        case RCC_LSECSSINTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_LSECSSC_Pos);
            RetCode = GET(RCC_ClockConfigs->CICR,RCC_CICR_LSECSSC_Pos);
            break;
        case RCC_HSI48INTR:
            SET(RCC_ClockConfigs->CICR,RCC_CICR_HSI48RDYC_Pos);
            RetCode = GET(RCC_ClockConfigs->CICR,RCC_CICR_HSI48RDYC_Pos);
            break;
        default:
            return RetCode;
    }

    return RetCode;
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
            return;
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
            return;
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
Error_t RCC_EnableAhb1Peripheral(Rcc_Ahb1Peripheral_t peripheral)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case AHB1_DMA1:
            SET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_DMA1EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_DMA1EN_Pos);
            break;
        case AHB1_DMA2:
            SET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_DMA2EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_DMA2EN_Pos);            
            break;
        case AHB1_FLASH:
            SET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_FLASHEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_FLASHEN_Pos); 
            break;
        case AHB1_CRC:
            SET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_CRCEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_CRCEN_Pos);
            break;
        case AHB1_TSC:
            SET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_TSCEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB1ENR_TSCEN_Pos);
            break;
        default:
            return RetCode;
    }  
    
    return RetCode;
}
/*RCC AHB1ENR Ends*/
/*RCC AHB2ENR Starts*/
Error_t RCC_EnableAhb2Peripheral(Rcc_Ahb2Peripheral_t peripheral)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case AHB2_GPIOA:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_GPIOAEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB2ENR_GPIOAEN_Pos);
            break;
        case AHB2_GPIOB:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_GPIOBEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB2ENR_GPIOBEN_Pos);
            break;
        case AHB2_GPIOC:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_GPIOCEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB2ENR_GPIOCEN_Pos);
            break;
        case AHB2_GPIOD:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_GPIODEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB2ENR_GPIODEN_Pos);
            break;
        case AHB2_GPIOE:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_GPIOEEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB2ENR_GPIOEEN_Pos);
            break;
        case AHB2_GPIOH:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_GPIOHEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB2ENR_GPIOHEN_Pos);
            break;
        case AHB2_ADC:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_ADCEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB2ENR_ADCEN_Pos);
            break;
        case AHB2_RNG:
            SET(RCC_ClockConfigs->AHB2ENR,RCC_AHB2ENR_RNGEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB2ENR_RNGEN_Pos);
            break;
        default:
            return RetCode;
    } 

     return RetCode;
}

/*RCC AHB2ENR Ends*/

/*RCC AHB3ENR Starts*/
Error_t RCC_EnableAhb3Peripheral(Rcc_Ahb3Peripheral_t peripheral)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case AHB3_QSPI:
            SET(RCC_ClockConfigs->AHB3ENR,RCC_AHB3ENR_QSPIEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_AHB3ENR_QSPIEN_Pos);
            break;
        default:
            return RetCode;
    }
    
    return RetCode;
}
/*RCC AHB3ENR Ends*/

/*RCC APB1ENR Register starts*/

Error_t RCC_EnableApb1Peripheral1(Rcc_Apb1Peripheral1_t peripheral)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case APB1_TIM2:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_TIM2EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_TIM2EN_Pos);
            break;
        case APB1_TIM6:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_TIM6EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_TIM6EN_Pos);
            break;
        case APB1_TIM7:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_TIM7EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_TIM7EN_Pos);
            break;
        case APB1_LCD:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_LCDEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_LCDEN_Pos);
            break;
        case APB1_SPI2:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_SPI2EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_SPI2EN_Pos);
            break;
        case APB1_SPI3:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_SPI3EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_SPI3EN_Pos);
            break;
        case APB1_USART2:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_USART2EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_USART2EN_Pos);
            break;
        case APB1_USART3:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_USART3EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_USART3EN_Pos);
            break;
        case APB1_I2C1:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_I2C1EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_I2C1EN_Pos);
            break;
        case APB1_I2C2:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_I2C2EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_I2C2EN_Pos);
            break;
        case APB1_I2C3:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_I2C3EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_I2C3EN_Pos);
            break;
        case APB1_CRS:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_CRSEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_CRSEN_Pos);
            break;
        case APB1_CAN1:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_CAN1EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_CAN1EN_Pos);
            break;
        case APB1_USBFS:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_USBFSEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_USBFSEN_Pos);
            break;
        case APB1_PWR:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_PWREN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_PWREN_Pos);
            break;
        case APB1_DAC1:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_DAC1EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_DAC1EN_Pos);
            break;
        case APB1_OPAMP:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_OPAMPEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_OPAMPEN_Pos);
            break;
        case APB1_LPTIM1:
            SET(RCC_ClockConfigs->APB1ENR1,RCC_APB1ENR1_LPTIM1EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR1_LPTIM1EN_Pos);
            break;
        default:
            return RetCode;
    }

    return RetCode;
}
/*RCC APB1ENR Register ends*/

/*RCC APB1RSTR2 Register starts*/
Error_t RCC_EnableApb1Peripheral2(Rcc_Apb1Peripheral2_t peripheral)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case APB1P2_LPUART1:
            SET(RCC_ClockConfigs->APB1ENR2,RCC_APB1ENR2_LPUART1EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR2_LPUART1EN_Pos);
            break;
        case APB1P2_SWPMI1:
            SET(RCC_ClockConfigs->APB1ENR2,RCC_APB1ENR2_SWPMI1EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR2_SWPMI1EN_Pos);
            break;
        case APB1P2_LPTIM2:
            SET(RCC_ClockConfigs->APB1ENR2,RCC_APB1ENR2_LPTIM2EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB1ENR2_LPTIM2EN_Pos);
            break;
        default:
           return RetCode;
    }

    return RetCode;
}
/*RCC APB1RSTR2 Register ends*/


/*RCC APB2ENR Register starts*/

Error_t RCC_EnableApb2Peripheral(Rcc_Apb2Peripheral_t peripheral)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case APB2_SYSCFG:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_SYSCFGEN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB2ENR_SYSCFGEN_Pos);
            break;
        case APB2_SDMMC:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_SDMMC1EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB2ENR_SDMMC1EN_Pos);
            break;
        case APB2_TIM1:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_TIM1EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB2ENR_TIM1EN_Pos);
            break;
        case APB2_SPI1:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_SPI1EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB2ENR_SPI1EN_Pos);
            break;
        case APB2_USART1:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_USART1EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB2ENR_USART1EN_Pos);
            break;
        case APB2_TIM15:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_TIM15EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB2ENR_TIM15EN_Pos);
            break;
        case APB2_TIM16:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_TIM16EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB2ENR_TIM16EN_Pos);
            break;
        case APB2_SAI1:
            SET(RCC_ClockConfigs->APB2ENR,RCC_APB2ENR_SAI1EN_Pos);
            RetCode = GET(RCC_ClockConfigs->AHB1ENR,RCC_APB2ENR_SAI1EN_Pos);
            break;
        default:
            return RetCode;
    }
}


/*RCC APB2ENR Register ends*/ 

/*RCC AHB1ENR Starts*/
Error_t RCC_EnableDuringSleepAhb1Peripheral(Rcc_Ahb1Peripheral_t peripheral,bool SleepEn)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case AHB1_DMA1:
            SET_BITS(RCC_ClockConfigs->AHB1SMENR,RCC_AHB1SMENR_DMA1SMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB1SMENR,RCC_AHB1SMENR_DMA1SMEN_Pos,1)==SleepEn);
            break;
        case AHB1_DMA2:
            SET_BITS(RCC_ClockConfigs->AHB1SMENR,RCC_AHB1SMENR_DMA2SMEN_Pos,1,SleepEn);
             RetCode = (GET_BITS(RCC_ClockConfigs->AHB1SMENR, RCC_AHB1SMENR_DMA2SMEN_Pos, 1) == SleepEn);
            break;
        case AHB1_FLASH:
            SET_BITS(RCC_ClockConfigs->AHB1SMENR,RCC_AHB1SMENR_FLASHSMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB1SMENR, RCC_AHB1SMENR_FLASHSMEN_Pos, 1) == SleepEn);
            break;
        case AHB1_CRC:
            SET_BITS(RCC_ClockConfigs->AHB1SMENR,RCC_AHB1SMENR_CRCSMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB1SMENR, RCC_AHB1SMENR_CRCSMEN_Pos, 1) == SleepEn);
            break;
        case AHB1_TSC:
            SET_BITS(RCC_ClockConfigs->AHB1SMENR,RCC_AHB1SMENR_TSCSMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB1SMENR, RCC_AHB1SMENR_TSCSMEN_Pos, 1) == SleepEn);
            break;
        default:
            return RetCode;
    }  
    
    return RetCode;
}
/*RCC AHB1ENR Ends*/
/*RCC AHB2ENR Starts*/
Error_t RCC_EnableDuringSleepAhb2Peripheral(Rcc_Ahb2Peripheral_t peripheral,bool SleepEn)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case AHB2_GPIOA:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_GPIOASMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB2SMENR, RCC_AHB2SMENR_GPIOASMEN_Pos, 1) == SleepEn);
            break;
        case AHB2_GPIOB:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_GPIOBSMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB2SMENR, RCC_AHB2SMENR_GPIOBSMEN_Pos, 1) == SleepEn);
            break;
        case AHB2_GPIOC:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_GPIOCSMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB2SMENR, RCC_AHB2SMENR_GPIOCSMEN_Pos, 1) == SleepEn);
            break;
        case AHB2_GPIOD:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_GPIODSMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB2SMENR, RCC_AHB2SMENR_GPIODSMEN_Pos, 1) == SleepEn);
            break;
        case AHB2_GPIOE:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_GPIOESMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB2SMENR, RCC_AHB2SMENR_GPIOESMEN_Pos, 1) == SleepEn);
            break;
        case AHB2_GPIOH:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_GPIOHSMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB2SMENR, RCC_AHB2SMENR_GPIOHSMEN_Pos, 1) == SleepEn);
            break;
        case AHB2_ADC:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_ADCSMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB2SMENR, RCC_AHB2SMENR_ADCSMEN_Pos, 1) == SleepEn);
            break;
        case AHB2_RNG:
            SET_BITS(RCC_ClockConfigs->AHB2SMENR,RCC_AHB2SMENR_RNGSMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB2SMENR, RCC_AHB2SMENR_RNGSMEN_Pos, 1) == SleepEn);
            break;
        default:
            return RetCode;
    } 

    return RetCode;
}

/*RCC AHB2ENR Ends*/

/*RCC AHB3ENR Starts*/
Error_t RCC_EnableDuringSleepAhb3Peripheral(Rcc_Ahb3Peripheral_t peripheral,bool SleepEn)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case AHB3_QSPI:
            SET_BITS(RCC_ClockConfigs->AHB3SMENR,RCC_AHB3SMENR_QSPISMEN_Pos,1,SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->AHB3SMENR, RCC_AHB3SMENR_QSPISMEN_Pos, 1) == SleepEn);
            break;
        default:
            return RetCode;
    }    

    return RetCode;
}
/*RCC AHB3ENR Ends*/

/*RCC APB1ENR Register starts*/

Error_t RCC_EnableDuringSleepApb1Peripheral1(Rcc_Apb1Peripheral1_t peripheral,bool SleepEn)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case APB1_TIM2:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_TIM2SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_TIM2SMEN_Pos, 1) == SleepEn);
            break;
        case APB1_TIM6:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_TIM6SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_TIM6SMEN_Pos, 1) == SleepEn);
            break;
        case APB1_TIM7:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_TIM7SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_TIM7SMEN_Pos, 1) == SleepEn);
            break;
        case APB1_LCD:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_LCDSMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_LCDSMEN_Pos, 1) == SleepEn);
            break;
        case APB1_SPI2:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_SPI2SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_SPI2SMEN_Pos, 1) == SleepEn);
            break;
        case APB1_SPI3:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_SPI3SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_SPI3SMEN_Pos, 1) == SleepEn);
            break;
        case APB1_USART2:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_USART2SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_USART2SMEN_Pos, 1) == SleepEn);
            break;
        case APB1_USART3:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_USART3SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_USART3SMEN_Pos, 1) == SleepEn);
            break;
        case APB1_I2C1:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_I2C1SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_I2C1SMEN_Pos, 1) == SleepEn);
            break;
        case APB1_I2C2:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_I2C2SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_I2C2SMEN_Pos, 1) == SleepEn);
            break;
        case APB1_I2C3:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_I2C3SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_I2C3SMEN_Pos, 1) == SleepEn);
            break;
        case APB1_CRS:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_CRSSMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_CRSSMEN_Pos, 1) == SleepEn);
            break;
        case APB1_CAN1:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_CAN1SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_CAN1SMEN_Pos, 1) == SleepEn);
            break;
        case APB1_USBFS:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_USBFSSMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_USBFSSMEN_Pos, 1) == SleepEn);
            break;
        case APB1_PWR:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_PWRSMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_PWRSMEN_Pos, 1) == SleepEn);
            break;
        case APB1_DAC1:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_DAC1SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_DAC1SMEN_Pos, 1) == SleepEn);
            break;
        case APB1_OPAMP:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_OPAMPSMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_OPAMPSMEN_Pos, 1) == SleepEn);
            break;
        case APB1_LPTIM1:
            SET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_LPTIM1SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR1, RCC_APB1SMENR1_LPTIM1SMEN_Pos, 1) == SleepEn);
            break;
        default:
    }

    return RetCode;
}
/*RCC APB1ENR Register ends*/

/*RCC APB1RSTR2 Register starts*/
Error_t RCC_EnableDuringSleepApb1Peripheral2(Rcc_Apb1Peripheral2_t peripheral,bool SleepEn)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case APB1P2_LPUART1:
            SET_BITS(RCC_ClockConfigs->APB1SMENR2, RCC_APB1SMENR2_LPUART1SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR2, RCC_APB1SMENR2_LPUART1SMEN_Pos, 1) == SleepEn);
            break;
        case APB1P2_SWPMI1:
            SET_BITS(RCC_ClockConfigs->APB1SMENR2, RCC_APB1SMENR2_SWPMI1SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR2, RCC_APB1SMENR2_SWPMI1SMEN_Pos, 1) == SleepEn);
            break;
        case APB1P2_LPTIM2:
            SET_BITS(RCC_ClockConfigs->APB1SMENR2, RCC_APB1SMENR2_LPTIM2SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB1SMENR2, RCC_APB1SMENR2_LPTIM2SMEN_Pos, 1) == SleepEn);
            break;
        default:
            return RetCode;
    }
    return RetCode;
}
/*RCC APB1RSTR2 Register ends*/


/*RCC APB2ENR Register starts*/

Error_t RCC_EnableDuringSleepApb2Peripheral(Rcc_Apb2Peripheral_t peripheral,bool SleepEn)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case APB2_SYSCFG:
            SET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_SYSCFGSMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_SYSCFGSMEN_Pos, 1) == SleepEn);
            break;
        case APB2_SDMMC:
            SET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_SDMMC1SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_SDMMC1SMEN_Pos, 1) == SleepEn);
            break;
        case APB2_TIM1:
            SET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_TIM1SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_TIM1SMEN_Pos, 1) == SleepEn);
            break;
        case APB2_SPI1:
            SET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_SPI1SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_SPI1SMEN_Pos, 1) == SleepEn);
            break;
        case APB2_USART1:
            SET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_USART1SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_USART1SMEN_Pos, 1) == SleepEn);
            break;
        case APB2_TIM15:
            SET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_TIM15SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_TIM15SMEN_Pos, 1) == SleepEn);
            break;
        case APB2_TIM16:
            SET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_TIM16SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_TIM16SMEN_Pos, 1) == SleepEn);
            break;
        case APB2_SAI1:
            SET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_SAI1SMEN_Pos, 1, SleepEn);
            RetCode = (GET_BITS(RCC_ClockConfigs->APB2SMENR, RCC_APB2SMENR_SAI1SMEN_Pos, 1) == SleepEn);
            break;
        default:
            return RetCode;
    }
    return RetCode; 
}
Error_t RCC_ConfigureCciprClocks(Rcc_CciprPeripheral_t peripheral , Rcc_Ccipr_ClockSrc_t src)
{
    Error_t RetCode=ERR_FAILED;
    switch (peripheral)
    {
        case CCIPR_USART1SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_USART1SEL_Pos, 2, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_USART1SEL_Pos, 2) == src);
            break;
        case CCIPR_USART2SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_USART2SEL_Pos, 2, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_USART2SEL_Pos, 2) == src);
            break;
        case CCIPR_USART3SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_USART3SEL_Pos, 2, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_USART3SEL_Pos, 2) == src);
            break;
        case CCIPR_LPUART1SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_LPUART1SEL_Pos, 2, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_LPUART1SEL_Pos, 2) == src);
            break;
        case CCIPR_I2C1SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_I2C1SEL_Pos, 2, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_I2C1SEL_Pos, 2) == src);
            break;
        case CCIPR_I2C2SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_I2C2SEL_Pos, 2, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_I2C2SEL_Pos, 2) == src);
            break;
        case CCIPR_I2C3SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_I2C3SEL_Pos, 2, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_I2C3SEL_Pos, 2) == src);
            break;
        case CCIPR_LPTIM1SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_LPTIM1SEL_Pos, 2, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_LPTIM1SEL_Pos, 2) == src);
            break;
        case CCIPR_LPTIM2SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_LPTIM2SEL_Pos, 2, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_LPTIM2SEL_Pos, 2) == src);
            break;
        case CCIPR_SAISEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_SAI1SEL_Pos, 2, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_SAI1SEL_Pos, 2) == src);
            break;
        case CCIPR_CLK48SEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_CLK48SEL_Pos, 2, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_CLK48SEL_Pos, 2) == src);
            break;
        case CCIPR_ADCSEL:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_ADCSEL_Pos, 2, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_ADCSEL_Pos, 2) == src);
            break;
        case CCIPR_SWPMI1:
            SET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_SWPMI1SEL_Pos, 1, src);
            RetCode = (GET_BITS(RCC_ClockConfigs->CCIPR, RCC_CCIPR_SWPMI1SEL_Pos, 1) == src);
            break;
        default:
            // Handle unknown peripheral or error
            return RetCode;
    }
   return RetCode;  
}
/*RCC APB2ENR Register ends*/ 
/*RCC BDCR Starts */
Error_t RCC_BdcrEnableLse(bool BdcrLseEn)
{
    Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_LSEON_Pos, 1, BdcrLseEn);
    RetCode = (GET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_LSEON_Pos, 1) == BdcrLseEn);
    return RetCode;
}

Error_t RCC_BdcrConfigureLseByp(bool BypEn)
{
    Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_LSEBYP_Pos, 1, BypEn);
    RetCode = (GET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_LSEBYP_Pos, 1) == BypEn);
    return RetCode;
}

Error_t RCC_BdcrConfigureLseSpeed(Rcc_Bdcr_LseSpeed_t spd)
{
    Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_LSEDRV_Pos, 2, spd);
    RetCode = (GET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_LSEDRV_Pos, 2) == spd);
    return RetCode;
}

Error_t RCC_BdcrLseCssConfigure(bool LseCssEn)
{
    Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_LSECSSON_Pos, 1, LseCssEn);
    RetCode = (GET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_LSECSSON_Pos, 1) == LseCssEn);
    return RetCode;
}


Error_t Rcc_BdcrConfigureRtcSource(Rcc_Bdcr_RtcSource_t src)
{
    Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_RTCSEL_Pos, 2, src);
    RetCode = (GET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_RTCSEL_Pos, 2) == src);
    return RetCode;
}

Error_t Rcc_BdcrConfigureRtcClk(bool RtcClkEn)
{
	Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_RTCEN_Pos, 1, RtcClkEn);
    RetCode = (GET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_RTCEN_Pos, 1) == RtcClkEn);
    return RetCode;
}

Error_t Rcc_BdcrConfigureBdRst(bool BdRst)
{
	Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_BDRST_Pos, 1, BdRst);
    RetCode = (GET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_BDRST_Pos, 1) == BdRst);
    return RetCode;
}

Error_t Rcc_ConfigureLscoEn(bool LscoEn)
{
	Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_LSCOEN_Pos, 1, LscoEn);
    RetCode = (GET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_LSCOEN_Pos, 1) == LscoEn);
    return RetCode;
}

Error_t Rcc_ConfigureLseSel(bool LseSel)
{
	Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_LSCOSEL_Pos, 1, LseSel);
    RetCode = (GET_BITS(RCC_ClockConfigs->BDCR, RCC_BDCR_LSCOSEL_Pos, 1) == LseSel);
    return RetCode;
}

/*RCC BDCR Ends*/

/*RCC CSR Starts*/

Error_t Rcc_EnableLsiCsr(bool LsiCsrEn)
{
    Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->CSR,RCC_CSR_LSION_Pos,1,LsiCsrEn);
    return RetCode;
}
Error_t Rcc_ConfigureMsiRangeCsr(Rcc_CsrMsiRng_t MsiRange)
{
	Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->CSR,RCC_CSR_MSISRANGE_Pos,4,MsiRange);
    RetCode = (GET_BITS(RCC_ClockConfigs->CSR, RCC_CSR_MSISRANGE_Pos, 4) == MsiRange);
    return RetCode;
}

Error_t Rcc_RmVfCsr(bool RmvfEn)
{
	Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->CSR, RCC_CSR_RMVF_Pos, 1, RmvfEn);
    RetCode = (GET_BITS(RCC_ClockConfigs->CSR, RCC_CSR_RMVF_Pos, 1) == RmvfEn);
    return RetCode;
}
/*RCC CSR Ends*/

/*RCC CRRCR Starts*/

Error_t Rcc_CrrCrHsi48Enable(bool Hsi48En)
{
    Error_t RetCode=ERR_FAILED;
    SET_BITS(RCC_ClockConfigs->CRRCR, RCC_CRRCR_HSI48ON_Pos, 1, Hsi48En);
    RetCode = (GET_BITS(RCC_ClockConfigs->CRRCR, RCC_CRRCR_HSI48ON_Pos, 1) == Hsi48En);
    return RetCode;
}

/*RCC CRRCR Ends*/
