#ifndef STM32L433_LL_CFG_H
#define STM32L433_LL_CFG_H

#include <stdint.h>
#include <stm32l433xx.h>

typedef struct
{
    uint32_t GPIOA_EN:1;
    uint32_t GPIOB_EN:1;
    uint32_t GPIOC_EN:1;
    uint32_t GPIOD_EN:1;
    uint32_t GPIOE_EN:1;
    uint32_t res1 : 2;
    uint32_t GPIOH_EN:1;
    uint32_t res2 : 5;
    uint32_t ADC_EN:1;
    uint32_t res3 : 2;
    uint32_t AES_EN:1;
    uint32_t res4 : 1;
    uint32_t RNG_B:1;
    uint32_t res5 : 13;
}RCC_AHB2ENR_B_t;

typedef union 
{
    RCC_AHB2ENR_B_t B;
    uint32_t U;
}RCC_AHB2ENR_Reg_t;

extern RCC_AHB2ENR_Reg_t RCC_AHB2ENR_Reg;

void Rcc_Init(void);
#endif