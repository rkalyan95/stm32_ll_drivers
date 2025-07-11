
#include "stm32l433_ll_rcc_cfg.h"

const system_clk_config systemclock = 
{
        .SysClkSrc = SYSCLK_MSI,

        .MsiSettings.MsiRngSelection = MSI_RANGESRC_CR,
        .MsiSettings.MsiRange = RCC_MSISRANGE_4MHZ_SETTING,
        .MsiSettings.msienabled = 1,

        .McoSettings.McoPreScaler = MCO_DIV1,
        .McoSettings.McoOutClk = MCO_SYSCLK,

        .HseSettings.hsebypassenl = 1,
        .HseSettings.hsecssenl = 1,
        .HseSettings.hseenabled = 0,

        .HsiSettings.hsiautostart = 1,
        .HsiSettings.hsikernelon = 1,
        .HsiSettings.hsienabled = 0,

        .PllSettings.pllsrc = PLL_PLL_MSICLK,
        .PllSettings.pllenabled = 0,
        .PllSettings.pllpenabled = 1,
        .PllSettings.pllqenabled = 1,
        .PllSettings.pllrenabled = 1,
        .PllSettings.plldiv = 0,
        .PllSettings.pllr = RCC_PLLR_2,
        .PllSettings.pllq = RCC_PLLQ_2,
        .PllSettings.pllp = RCC_PLLP_7,
        .PllSettings.plln = 8,
        .PllSettings.pllm = RCC_PLL_M_1,


        .PllSai1Settings.pllsai1enabled = 0,
        .PllSai1Settings.pllsai1penabled = 1,
        .PllSai1Settings.pllsai1qenabled = 1,
        .PllSai1Settings.pllsai1renabled = 1,
        .PllSai1Settings.pllsai1div = 0,
        .PllSai1Settings.pllsai1r = RCC_PLLR_2,
        .PllSai1Settings.pllsai1q = RCC_PLLQ_2,
        .PllSai1Settings.pllsai1p = RCC_PLLP_7,
        .PllSai1Settings.pllsai1n = 8,
        .PllSai1Settings.pllsai1m = RCC_PLL_M_1,

};

const peripheral_clk_settings peripheralclk=
{

    .AhbDiv = AHB_SYSCLK_NODIV,
    .Apb1Div = APB1_HCLK_NODIV,
    .Apb2Div = APB2_HCLK_NODIV

};

 const peripheral_clock_cfg_t peripheral_configs[] = {
    {
        .peripheral_cat = PERIPHERAL_CAT_AHB2,
        .peripheral_id.ahb2_id = AHB2_GPIOA,
        .peripheral_clksrc = CCIPR_CLKSRCNONE,
    },
    {
        .peripheral_cat = PERIPHERAL_CAT_AHB2,
        .peripheral_id.ahb2_id = AHB2_GPIOB,
        .peripheral_clksrc = CCIPR_CLKSRCNONE,
    },
    {
        .peripheral_cat = PERIPHERAL_CAT_AHB2,
        .peripheral_id.ahb2_id = AHB2_GPIOC,
        .peripheral_clksrc = CCIPR_CLKSRCNONE,
    },
    {
        .peripheral_cat = PERIPHERAL_CAT_AHB2,
        .peripheral_id.ahb2_id = AHB2_GPIOD,
        .peripheral_clksrc = CCIPR_CLKSRCNONE,
    },
    {
        .peripheral_cat = PERIPHERAL_CAT_AHB2,
        .peripheral_id.ahb2_id = AHB2_GPIOE,
        .peripheral_clksrc = CCIPR_CLKSRCNONE,
    },
    {
        .peripheral_cat = PERIPHERAL_CAT_AHB2,
        .peripheral_id.ahb2_id = AHB2_GPIOH,
        .peripheral_clksrc = CCIPR_CLKSRCNONE,
    },

};

#define CLOCK_CONFIG_CNT      (sizeof(peripheral_configs)/sizeof(peripheral_configs[0]))



static Error_t ApplyClockConfiguration(const peripheral_clock_cfg_t* config)
{
    Error_t RetCode;

    switch (config->peripheral_cat)
    {
        case PERIPHERAL_CAT_AHB1:
            RetCode = RCC_EnableAhb1Peripheral(config->peripheral_id.ahb1_id);
            break;
        case PERIPHERAL_CAT_AHB2:
            RetCode = RCC_EnableAhb2Peripheral(config->peripheral_id.ahb2_id);
            break;
        case PERIPHERAL_CAT_AHB3:
            RetCode = RCC_EnableAhb3Peripheral(config->peripheral_id.ahb3_id);
            break;
        case PERIPHERAL_CAT_APB1P1:
            RetCode = RCC_EnableApb1Peripheral1(config->peripheral_id.apb1p1_id);
            break;
        case PERIPHERAL_CAT_APB1P2:
            RetCode = RCC_EnableApb1Peripheral2(config->peripheral_id.apb1p2_id);
            break;
        case PERIPHERAL_CAT_APB2:
            RetCode = RCC_EnableApb2Peripheral(config->peripheral_id.apb2_id);
            break;
        case PERIPHERAL_CAT_CCIPR:
            RetCode = RCC_ConfigureCciprClocks(config->peripheral_id.ccipr_id, config->peripheral_clksrc);
            break;
        case PERIPHERAL_CAT_NONE:
            // This category can be used to mark ignored entries or end of a list if needed.
            break;
        default:
            // Handle unknown or uninitialized category (e.g., log an error, assert, or do nothing)
            // Consider adding a robust error handling mechanism here for production code.
            break;
    }

    return RetCode;
}



static Error_t InitSysClockConfigurtion(const system_clk_config *sysclockconfig)
{
    Error_t RetCode;
    RetCode = RCC_SetSystemClockSource(sysclockconfig->SysClkSrc);
    if(sysclockconfig->MsiSettings.msienabled)
    {
        RetCode = RCC_MsiRangeSelect(sysclockconfig->MsiSettings.MsiRngSelection);
        RetCode = RCC_EnableMSI(sysclockconfig->MsiSettings.MsiRange,sysclockconfig->MsiSettings.msienabled);    
    }
    else
    {
        /* Do nothing or log if needed */
    }

    if(sysclockconfig->HsiSettings.hsienabled)
    {
        RetCode = RCC_EnableHSI(sysclockconfig->HsiSettings.hsikernelon,sysclockconfig->HsiSettings.hsiautostart,sysclockconfig->HsiSettings.hsienabled);
    }
    else
    {
        /*Do nothing*/
    }

    if(sysclockconfig->HseSettings.hseenabled)
    {
        RetCode = RCC_EnableHSE(sysclockconfig->HseSettings.hsebypassenl,sysclockconfig->HseSettings.hsecssenl,sysclockconfig->HseSettings.hseenabled);
    }
    else
    {
        /*Do nothing*/
    }

    if(sysclockconfig->PllSettings.pllenabled)
    {
        RetCode = RCC_ConfigurePllSrc(sysclockconfig->PllSettings.pllsrc);
        RetCode = RCC_ConfigurePllSettings(sysclockconfig->PllSettings.pllm,sysclockconfig->PllSettings.pllp,sysclockconfig->PllSettings.pllq,sysclockconfig->PllSettings.pllr,sysclockconfig->PllSettings.plln,sysclockconfig->PllSettings.plldiv);
        RetCode = RCC_EnablePllR(sysclockconfig->PllSettings.pllrenabled);
        RetCode = RCC_EnablePllQ(sysclockconfig->PllSettings.pllqenabled);
        RetCode = RCC_EnablePllP(sysclockconfig->PllSettings.pllpenabled);
    }

    else
    {
        /*Do nothing*/
    }
    
    if(sysclockconfig->PllSai1Settings.pllsai1enabled)
    {
        RetCode = RCC_ConfigurePllSai1Settings(sysclockconfig->PllSai1Settings.pllsai1m,sysclockconfig->PllSai1Settings.pllsai1p,sysclockconfig->PllSai1Settings.pllsai1q,sysclockconfig->PllSai1Settings.pllsai1r,sysclockconfig->PllSai1Settings.pllsai1n,sysclockconfig->PllSai1Settings.pllsai1div);
        RetCode = RCC_EnablePllSai1R(sysclockconfig->PllSai1Settings.pllsai1renabled);
        RetCode = RCC_EnablePllSai1Q(sysclockconfig->PllSai1Settings.pllsai1qenabled);
        RetCode = RCC_EnablePllSai1P(sysclockconfig->PllSai1Settings.pllsai1penabled);
    }

    else
    {
        /*Do nothing*/
    }
    RetCode = RCC_ConfigureMCO(sysclockconfig->McoSettings.McoOutClk,sysclockconfig->McoSettings.McoPreScaler);
        
    RetCode = RCC_SetAHBPrescaler(peripheralclk.AhbDiv);
    RetCode = RCC_SetAPB1Prescaler(peripheralclk.Apb1Div);
    RetCode = RCC_SetAPB2Prescaler(peripheralclk.Apb2Div);

}

/**
 * @brief Initializes all peripheral clocks defined in peripheral_configs array.
 *
 * Iterates through the global `peripheral_configs` array and applies
 * each configuration using `ApplyClockConfiguration`.
 *
 * @param None
 * */

static Error_t InitializeAllPeripheralsClocks(void)
{
    Error_t RetCode;
    for (uint32_t i = 0; i < CLOCK_CONFIG_CNT; i++)
    {
        RetCode = ApplyClockConfiguration(&peripheral_configs[i]);
    }

    return RetCode;
}

Error_t InitAllClocks(void)
{
    Error_t RetCode;
    RetCode = InitializeAllPeripheralsClocks();
    RetCode = InitSysClockConfigurtion(&systemclock);

    return RetCode;
}

