#ifndef STM32L433_LL_CFG_H
#define STM32L433_LL_CFG_H

#include <stdint.h>
#include "stm32l433_ll_rcc.h"

typedef enum
{
    PERIPHERAL_CAT_NONE = 0, // Default/invalid
    PERIPHERAL_CAT_AHB1,
    PERIPHERAL_CAT_AHB2,
    PERIPHERAL_CAT_AHB3, // Don't forget AHB3 if applicable to your MCU
    PERIPHERAL_CAT_APB1P1,
    PERIPHERAL_CAT_APB1P2,
    PERIPHERAL_CAT_APB2,
    PERIPHERAL_CAT_CCIPR, // For Clock Configuration Interconnect Peripheral Registers (clock source selection)
    // Add other categories if you generalize core clock settings too (e.g., OSCILLATOR_CONFIG, PLL_CONFIG)
} PeripheralCategory_t;


typedef struct 
{
    RCCSysClkSource_t SysClkSrc;
    RccMsiRngSel_t MsiRngSelection;
    RccMcoSource_t McoOutClk;
    RccMcoPrescaler_t McoPreScaler;
    RccMsiRng_t MsiRange;

}system_clk_config;

typedef struct 
{
    Apb1Prescaler_t Apb1Div;
    Apb2Prescaler_t Apb2Div;
    AhbPrescaler_t  AhbDiv;
}peripheral_clk_settings;


typedef union
{
    Rcc_Ahb1Peripheral_t ahb1_id;
    Rcc_Ahb2Peripheral_t ahb2_id;
    Rcc_Ahb3Peripheral_t ahb3_id;
    Rcc_Apb1Peripheral1_t apb1p1_id;
    Rcc_Apb1Peripheral2_t apb1p2_id;
    Rcc_Apb2Peripheral_t apb2_id;
    Rcc_CciprPeripheral_t ccipr_id;
    // A generic uint32_t can still be included for convenience or debugging if needed,
    // but its primary purpose is diminished with specific enum members.
    uint32_t generic_val; // For cases where you might need a raw value or don't have a specific enum
} PeripheralIdUnion_t;
 
typedef struct
{
    PeripheralCategory_t peripheral_cat; /* Category of peripheral */
    PeripheralIdUnion_t peripheral_id;   /* Specific peripheral ID, accessed via union member based on category */
    Rcc_Ccipr_ClockSrc_t peripheral_clksrc; /* Clock source value, valid only if category is CCIPR */
} peripheral_clock_cfg_t;



void InitAllClocks(void);

#endif // STM32L433_LL_CFG_H