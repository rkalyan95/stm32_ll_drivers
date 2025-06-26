#ifndef STM32L433_LL_RCC_H
#define STM32L433_LL_RCC_H

#include "stm32l433_ll_rcc_cfg.h"

#define GET(x,pos)   ((x && 1<<pos) >> pos)
#define SET(x,pos)   (x |= (1<<pos))
#define CLEAR(x,pos)   (x &= ~(1<<pos))
#define TOGGLE(x,pos) (x ^= 1<<pos)

void Rcc_Init(void);

#endif