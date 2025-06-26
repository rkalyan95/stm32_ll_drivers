
#include <stm32l433_ll_rcc.h>

RCC_TypeDef *RCC_ClockConfigs = ((RCC_TypeDef *) RCC_BASE);

void Rcc_Init(void)
{

         
        RCC_ClockConfigs->AHB2ENR = RCC_AHB2ENR_Reg.U;
        RCC_ClockConfigs->CFGR = RCC_CFGR_Reg.U;
        RCC_ClockConfigs->BDCR = RCC_BDCR_Reg.U;

 
        /*while(!(Rcc_Register_Configs->RCC_AHB2ENR_Reg.B.GPIOA_EN))
        {
            // Wait for GPIOA and GPIOB to be enabled
        }*/


}