
#include "stm32l433_ll_rcc_cfg.h"

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

/**
 * @brief Initializes all peripheral clocks defined in peripheral_configs array.
 *
 * Iterates through the global `peripheral_configs` array and applies
 * each configuration using `ApplyClockConfiguration`.
 *
 * @param None
 */
void InitializeAllPeripheralsClocks(void)
{

    for (uint32_t i = 0; i < CLOCK_CONFIG_CNT; i++)
    {
        ApplyClockConfiguration(&peripheral_configs[i]);
    }
}

