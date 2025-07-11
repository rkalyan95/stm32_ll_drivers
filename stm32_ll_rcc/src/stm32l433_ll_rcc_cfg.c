
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
        .HsiSettings.hsienabled = 1,

        .PllSettings.pllsrc = PLL_PLL_MSICLK,
        .PllSettings.pllenabled = 1,
        .PllSettings.pllpenabled = 1,
        .PllSettings.pllqenabled = 1,
        .PllSettings.pllrenabled = 1,
        .PllSettings.plldiv = 0,
        .PllSettings.pllr = RCC_PLLR_2,
        .PllSettings.pllq = RCC_PLLQ_2,
        .PllSettings.pllp = RCC_PLLP_7,
        .PllSettings.plln = 8,
        .PllSettings.pllm = RCC_PLL_M_1,


        .PllSai1Settings.pllsai1enabled = 1,
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

const peripheral_clk_settings peripheralclk[] =
{
    {
        .AhbDiv = APB1_HCLK_NODIV,
        .Apb1Div = APB2_HCLK_NODIV,
        .Apb2Div = AHB_SYSCLK_NODIV
    }
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

#define SYSCLOCK_CONFIG_CNT      (sizeof(systemclock)/sizeof(systemclock[0]))

#define PERIPHERAL_CLOCK_CONFIG_CNT      (sizeof(peripheralclk)/sizeof(peripheralclk[0]))


static void ApplyClockConfiguration(const peripheral_clock_cfg_t* config)
{
    switch (config->peripheral_cat)
    {
        case PERIPHERAL_CAT_AHB1:
            RCC_EnableAhb1Peripheral(config->peripheral_id.ahb1_id);
            break;
        case PERIPHERAL_CAT_AHB2:
            RCC_EnableAhb2Peripheral(config->peripheral_id.ahb2_id);
            break;
        case PERIPHERAL_CAT_AHB3:
            RCC_EnableAhb3Peripheral(config->peripheral_id.ahb3_id);
            break;
        case PERIPHERAL_CAT_APB1P1:
            RCC_EnableApb1Peripheral1(config->peripheral_id.apb1p1_id);
            break;
        case PERIPHERAL_CAT_APB1P2:
            RCC_EnableApb1Peripheral2(config->peripheral_id.apb1p2_id);
            break;
        case PERIPHERAL_CAT_APB2:
            RCC_EnableApb2Peripheral(config->peripheral_id.apb2_id);
            break;
        case PERIPHERAL_CAT_CCIPR:
            RCC_ConfigureCciprClocks(config->peripheral_id.ccipr_id, config->peripheral_clksrc);
            break;
        case PERIPHERAL_CAT_NONE:
            // This category can be used to mark ignored entries or end of a list if needed.
            break;
        default:
            // Handle unknown or uninitialized category (e.g., log an error, assert, or do nothing)
            // Consider adding a robust error handling mechanism here for production code.
            break;
    }
}



static void InitSysClockConfigurtion(const system_clk_config *sysclockconfig)
{

    RCC_SetSystemClockSource(sysclockconfig->SysClkSrc);
    if(sysclockconfig->MsiSettings.msienabled)
    {
        RCC_MsiRangeSelect(sysclockconfig->MsiSettings.MsiRngSelection);
        RCC_EnableMSI(sysclockconfig->MsiSettings.MsiRange,sysclockconfig->MsiSettings.msienabled);    
    }
    else
    {
        /* Do nothing or log if needed */
    }

    if(sysclockconfig->HsiSettings.hsienabled)
    {
        RCC_EnableHSI(sysclockconfig->HsiSettings.hsikernelon,sysclockconfig->HsiSettings.hsiautostart,sysclockconfig->HsiSettings.hsienabled);
    }
    else
    {
        /*Do nothing*/
    }

    if(sysclockconfig->HseSettings.hseenabled)
    {
        RCC_EnableHSE(sysclockconfig->HseSettings.hsebypassenl,sysclockconfig->HseSettings.hsecssenl,sysclockconfig->HseSettings.hseenabled);
    }
    else
    {
        /*Do nothing*/
    }

    if(sysclockconfig->PllSettings.pllenabled)
    {
        RCC_ConfigurePllSrc(sysclockconfig->PllSettings.pllsrc);
        RCC_ConfigurePllSettings(sysclockconfig->PllSettings.pllm,sysclockconfig->PllSettings.pllp,sysclockconfig->PllSettings.pllq,sysclockconfig->PllSettings.pllr,sysclockconfig->PllSettings.plln,sysclockconfig->PllSettings.plldiv);
        RCC_EnablePllR(sysclockconfig->PllSettings.pllrenabled);
        RCC_EnablePllQ(sysclockconfig->PllSettings.pllqenabled);
        RCC_EnablePllP(sysclockconfig->PllSettings.pllpenabled);
    }

    else
    {
        /*Do nothing*/
    }
    
    if(sysclockconfig->PllSai1Settings.pllsai1enabled)
    {
        RCC_ConfigurePllSai1Settings(sysclockconfig->PllSai1Settings.pllsai1m,sysclockconfig->PllSai1Settings.pllsai1p,sysclockconfig->PllSai1Settings.pllsai1q,sysclockconfig->PllSai1Settings.pllsai1r,sysclockconfig->PllSai1Settings.pllsai1n,sysclockconfig->PllSai1Settings.pllsai1div);
        RCC_EnablePllSai1R(sysclockconfig->PllSai1Settings.pllsai1renabled);
        RCC_EnablePllSai1Q(sysclockconfig->PllSai1Settings.pllsai1qenabled);
        RCC_EnablePllSai1P(sysclockconfig->PllSai1Settings.pllsai1penabled);
    }

    else
    {
        /*Do nothing*/
    }
    RCC_ConfigureMCO(sysclockconfig->McoSettings.McoOutClk,sysclockconfig->McoSettings.McoPreScaler);
        

}

/**
 * @brief Initializes all peripheral clocks defined in peripheral_configs array.
 *
 * Iterates through the global `peripheral_configs` array and applies
 * each configuration using `ApplyClockConfiguration`.
 *
 * @param None
 * */

static void InitializeAllPeripheralsClocks(void)
{

    for (uint32_t i = 0; i < CLOCK_CONFIG_CNT; i++)
    {
        ApplyClockConfiguration(&peripheral_configs[i]);
    }
}

void InitAllClocks(void)
{
    InitializeAllPeripheralsClocks();
    InitSysClockConfigurtion(&systemclock);
}

