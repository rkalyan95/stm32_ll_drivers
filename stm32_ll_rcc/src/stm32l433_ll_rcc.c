
#include <stm32l433_ll_rcc.h>

RCC_TypeDef *RCC_ClockConfigs = ((RCC_TypeDef *) RCC_BASE);

void Rcc_Init(void)
{
    /*Check the cfg.c file for the settings , to change and use*/
    
        uint32_t RegisteTempValue = 0;  
        RCC_AHB2ENR_Reg_t Rcc_Ahb2Enr_local;  
        /*Copy the configurations to Actual Hardware Registers*/    
        RCC_ClockConfigs->AHB2ENR = RCC_AHB2ENR_Reg.U;
        RCC_ClockConfigs->CFGR = RCC_CFGR_Reg.U;
        RCC_ClockConfigs->BDCR = RCC_BDCR_Reg.U;
        
        /* Keep on reading the hardware registers to a local value and operate upon bits for easier access */
        while(Rcc_Ahb2Enr_local.B.GPIOA_EN != 1)
        {
            RegisteTempValue = RCC_ClockConfigs->AHB2ENR;
            Rcc_Ahb2Enr_local.U = RegisteTempValue;
        }


}