
#include <stm32l433_ll_rcc.h>



void Rcc_InitSystemClocks(void)
{
    RCC_TypeDef *RCC_ClockConfigs = ((RCC_TypeDef *) RCC_BASE);
    /*Check the cfg.c file for the settings , to change and use*/
   
        RCC_ClockConfigs->AHB2ENR = RCC_AHB2ENR_Reg.U;
        RCC_ClockConfigs->AHB1ENR = RCC_AHB1ENR_Reg.U;
        RCC_ClockConfigs->CFGR = RCC_CFGR_Reg.U;
        RCC_ClockConfigs->BDCR = RCC_BDCR_Reg.U;

        /* added later */

        RCC_ClockConfigs->CR = RCC_CR_Reg.U;
        RCC_ClockConfigs->PLLSAI1CFGR = RCC_PLLSAI1CFGR_Reg.U; 
        RCC_ClockConfigs->CIER = RCC_CIER_Reg.U;
        RCC_ClockConfigs->PLLCFGR = RCC_PLLCFGR_Reg.U;
        RCC_ClockConfigs->AHB1RSTR = RCC_AHB1RSTR_Reg.U;
        RCC_ClockConfigs->AHB2RSTR = RCC_AHB2RSTR_Reg.U;
        RCC_ClockConfigs->AHB3RSTR = RCC_AHB3RSTR_Reg.U;
        RCC_ClockConfigs->APB1RSTR1 = RCC_APB1RSTR1_Reg.U;
        RCC_ClockConfigs->APB1RSTR2 = RCC_APB1RSTR2_Reg.U;
        RCC_ClockConfigs->APB2RSTR = RCC_APB2RSTR_Reg.U;

        RCC_ClockConfigs->AHB3ENR = RCC_AHB3ENR_Reg.U;
        RCC_ClockConfigs->APB1ENR1 = RCC_APB1ENR1_Reg.U;
        RCC_ClockConfigs->APB1ENR2 = RCC_APB1ENR2_Reg.U;
        RCC_ClockConfigs->APB2ENR = RCC_APB2ENR_Reg.U;
        RCC_ClockConfigs->AHB1SMENR = RCC_AHB1SMENR_Reg.U;
        RCC_ClockConfigs->AHB2SMENR = RCC_AHB2SMENR_Reg.U;
        RCC_ClockConfigs->AHB3SMENR = RCC_AHB3SMENR_Reg.U;
        RCC_ClockConfigs->APB1SMENR1 = RCC_APB1SMENR1_Reg.U;
        RCC_ClockConfigs->APB1SMENR2 = RCC_APB1SMENR2_Reg.U;
        RCC_ClockConfigs->APB2SMENR = RCC_APB2SMENR_Reg.U;
        RCC_ClockConfigs->CCIPR = RCC_CCIPR_Reg.U;
        RCC_ClockConfigs->CSR = RCC_CSR_Reg.U;
        RCC_ClockConfigs->CRRCR = RCC_CRRCR_Reg.U;
                              
}

