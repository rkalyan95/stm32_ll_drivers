
#include <stm32l433_ll_rcc.h>



void Rcc_InitSystemClocks(void)
{
    RCC_TypeDef *RCC_ClockConfigs = ((RCC_TypeDef *) RCC_BASE);
    /*Check the cfg.c file for the settings , to change and use*/
   
        RCC_ClockConfigs->AHB2ENR = RCC_AHB2ENR_Reg.U;
        RCC_ClockConfigs->AHB1ENR = RCC_AHB1ENR_Reg.U;
        RCC_ClockConfigs->CFGR = RCC_CFGR_Reg.U;
        RCC_ClockConfigs->BDCR = RCC_BDCR_Reg.U;
                               
}

