#ifndef STM32_SYSCFG_H
#define STM32_SYSCFG_H

#include <stdint.h>

#define SYSCFG  ((SYSCFG_TypeDef *) SYSCFG_BASE)

#define GET(x,pos)   ((x & 1UL<<pos) >> pos)
#define SET(x,pos)   (x |= (1UL<<pos))
#define CLEAR(x,pos)   (x &= ~(1UL<<pos))
#define TOGGLE(x,pos) (x ^= 1UL<<pos)
#define SET_BITS(v, p, n, new_val) \
  ((v) = ((v) & ~(((1UL << (n)) - 1) << (p))) | (((new_val) & ((1UL << (n)) - 1)) << (p)))

#define GET_BITS(v, p, n) \
  (((v) >> (p)) & ((1UL << (n)) - 1))

typedef enum
{
    SYSCFG_FAILED,
    SYSCFG_SUCCESS
}Error_t;


typedef enum
{
    SYSCFG_MAINFLASH=0,
    SYSCFG_SYSTEMFLASH=1,
    SYSCFG_SRAMFLASH=3,
    SYSCFG_QSPI=6
}SysCfg_MemMode_t;

typedef enum
{
    I2C_PB6_FMP,
    I2C_PB7_FMP,
    I2C_PB8_FMP,
    I2C_PB9_FMP,
    I2C1_FMP,
    I2C2_FMP,
    I2C3_FMP,
}SysCfg_FastMode_Perpih_t;

typedef enum
{
    EXTI0_PA0,
    EXTI0_PB0,
    EXTI0_PC0,
    EXTI0_PD0,
    EXTI0_PE0,
    EXTI0_PH0=7,

}SysCfg_Exti0_Cfg_t;

typedef enum
{
    EXTI1_PA1,
    EXTI1_PB1,
    EXTI1_PC1,
    EXTI1_PD1,
    EXTI1_PE1,
    EXTI1_PH1=7,

}SysCfg_Exti1_Cfg_t;

typedef enum
{
    EXTI2_PA2,
    EXTI2_PB2,
    EXTI2_PC2,
    EXTI2_PD2,
    EXTI2_PE2,

}SysCfg_Exti2_Cfg_t;

typedef enum
{
    EXTI3_PA3,
    EXTI3_PB3,
    EXTI3_PC3,
    EXTI3_PD3,
    EXTI3_PE3,
    EXTI3_PH3=7,

}SysCfg_Exti3_Cfg_t;

#endif // STM32_SYSCFG_H