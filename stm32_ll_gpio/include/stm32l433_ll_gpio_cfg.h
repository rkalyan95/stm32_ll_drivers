#ifndef STM32L433_LL_GPIO_CFG_H
#define STM32L433_LL_GPIO_CFG_H

#include <stdint.h>
#include <stm32l433xx.h>
#include <stm32l433_ll_gpio.h>
#define MAX_PIN_CONFIGS    2

extern const portpintconfigs_t Stm32NucleoConfigsPortB[MAX_PIN_CONFIGS];


enum {
    GPIO_MODE_INPUT = 0x0,   // Input mode
    GPIO_MODE_OUTPUT = 0x1,  // Output mode
    GPIO_MODE_ALTERNATE = 0x2, // Alternate function mode
    GPIO_MODE_ANALOG = 0x3   // Analog mode
};

typedef struct
{
    uint32_t GPIOA_MODE0:2; // GPIO mode for pin 0
    uint32_t GPIOA_MODE1:2; // GPIO mode for pin 1   
    uint32_t GPIOA_MODE2:2; // GPIO mode for pin 2
    uint32_t GPIOA_MODE3:2; // GPIO mode for pin 3
    uint32_t GPIOA_MODE4:2; // GPIO mode for pin 4
    uint32_t GPIOA_MODE5:2; // GPIO mode for pin 5   
    uint32_t GPIOA_MODE6:2; // GPIO mode for pin 6
    uint32_t GPIOA_MODE7:2; // GPIO mode for pin 7
    uint32_t GPIOA_MODE8:2; // GPIO mode for pin 8
    uint32_t GPIOA_MODE9:2; // GPIO mode for pin 9
    uint32_t GPIOA_MODE10:2; // GPIO mode for pin 10
    uint32_t GPIOA_MODE11:2; // GPIO mode for pin 11
    uint32_t GPIOA_MODE12:2; // GPIO mode for pin 12
    uint32_t GPIOA_MODE13:2; // GPIO mode for pin 13
    uint32_t GPIOA_MODE14:2; // GPIO mode for pin 14
    uint32_t GPIOA_MODE15:2; // GPIO mode for pin 15
}GPIOA_MODER_B_t;

typedef union
{
    GPIOA_MODER_B_t B;
    uint32_t U;
}GPIOA_MODER_Reg_t;

extern volatile GPIOA_MODER_Reg_t GPIOA_MODER_Reg;

typedef struct
{
    uint32_t GPIOB_MODE0:2; // GPIO mode for pin 0
    uint32_t GPIOB_MODE1:2; // GPIO mode for pin 1   
    uint32_t GPIOB_MODE2:2; // GPIO mode for pin 2
    uint32_t GPIOB_MODE3:2; // GPIO mode for pin 3
    uint32_t GPIOB_MODE4:2; // GPIO mode for pin 4
    uint32_t GPIOB_MODE5:2; // GPIO mode for pin 5   
    uint32_t GPIOB_MODE6:2; // GPIO mode for pin 6
    uint32_t GPIOB_MODE7:2; // GPIO mode for pin 7
    uint32_t GPIOB_MODE8:2; // GPIO mode for pin 8
    uint32_t GPIOB_MODE9:2; // GPIO mode for pin 9
    uint32_t GPIOB_MODE10:2; // GPIO mode for pin 10
    uint32_t GPIOB_MODE11:2; // GPIO mode for pin 11
    uint32_t GPIOB_MODE12:2; // GPIO mode for pin 12
    uint32_t GPIOB_MODE13:2; // GPIO mode for pin 13
    uint32_t GPIOB_MODE14:2; // GPIO mode for pin 14
    uint32_t GPIOB_MODE15:2; // GPIO mode for pin 15 
}GPIOB_MODER_B_t;

typedef union
{
    GPIOB_MODER_B_t B;
    uint32_t U;
}GPIOB_MODER_Reg_t;


extern volatile GPIOB_MODER_Reg_t GPIOB_MODER_Reg;

typedef struct
{
    uint32_t GPIOC_MODE0:2; // GPIO mode for pin 0
    uint32_t GPIOC_MODE1:2; // GPIO mode for pin 1   
    uint32_t GPIOC_MODE2:2; // GPIO mode for pin 2
    uint32_t GPIOC_MODE3:2; // GPIO mode for pin 3
    uint32_t GPIOC_MODE4:2; // GPIO mode for pin 4
    uint32_t GPIOC_MODE5:2; // GPIO mode for pin 5   
    uint32_t GPIOC_MODE6:2; // GPIO mode for pin 6
    uint32_t GPIOC_MODE7:2; // GPIO mode for pin 7
    uint32_t GPIOC_MODE8:2; // GPIO mode for pin 8
    uint32_t GPIOC_MODE9:2; // GPIO mode for pin 9
    uint32_t GPIOC_MODE10:2; // GPIO mode for pin 10
    uint32_t GPIOC_MODE11:2; // GPIO mode for pin 11
    uint32_t GPIOC_MODE12:2; // GPIO mode for pin 12
    uint32_t GPIOC_MODE13:2; // GPIO mode for pin 13
    uint32_t GPIOC_MODE14:2; // GPIO mode for pin 14
    uint32_t GPIOC_MODE15:2; // GPIO mode for pin 15
}GPIOC_MODER_B_t;

typedef union
{
    GPIOC_MODER_B_t B;
    uint32_t U;
}GPIOC_MODER_Reg_t;

extern volatile GPIOC_MODER_Reg_t GPIOC_MODER_Reg;

typedef struct
{
    uint32_t GPIOD_MODE0:2; // GPIO mode for pin 0
    uint32_t GPIOD_MODE1:2; // GPIO mode for pin 1   
    uint32_t GPIOD_MODE2:2; // GPIO mode for pin 2
    uint32_t GPIOD_MODE3:2; // GPIO mode for pin 3
    uint32_t GPIOD_MODE4:2; // GPIO mode for pin 4
    uint32_t GPIOD_MODE5:2; // GPIO mode for pin 5   
    uint32_t GPIOD_MODE6:2; // GPIO mode for pin 6
    uint32_t GPIOD_MODE7:2; // GPIO mode for pin 7
    uint32_t GPIOD_MODE8:2; // GPIO mode for pin 8
    uint32_t GPIOD_MODE9:2; // GPIO mode for pin 9
    uint32_t GPIOD_MODE10:2; // GPIO mode for pin 10
    uint32_t GPIOD_MODE11:2; // GPIO mode for pin 11
    uint32_t GPIOD_MODE12:2; // GPIO mode for pin 12
    uint32_t GPIOD_MODE13:2; // GPIO mode for pin 13
    uint32_t GPIOD_MODE14:2; // GPIO mode for pin 14
    uint32_t GPIOD_MODE15:2; // GPIO mode for pin 15  
}GPIOD_MODER_B_t;

typedef union
{
    GPIOD_MODER_B_t B;
    uint32_t U;
}GPIOD_MODER_Reg_t;

extern volatile GPIOD_MODER_Reg_t GPIOD_MODER_Reg;

typedef struct
{
    uint32_t GPIOE_MODE0:2; // GPIO mode for pin 0
    uint32_t GPIOE_MODE1:2; // GPIO mode for pin 1   
    uint32_t GPIOE_MODE2:2; // GPIO mode for pin 2
    uint32_t GPIOE_MODE3:2; // GPIO mode for pin 3
    uint32_t GPIOE_MODE4:2; // GPIO mode for pin 4
    uint32_t GPIOE_MODE5:2; // GPIO mode for pin 5   
    uint32_t GPIOE_MODE6:2; // GPIO mode for pin 6
    uint32_t GPIOE_MODE7:2; // GPIO mode for pin 7
    uint32_t GPIOE_MODE8:2; // GPIO mode for pin 8
    uint32_t GPIOE_MODE9:2; // GPIO mode for pin 9
    uint32_t GPIOE_MODE10:2; // GPIO mode for pin 10
    uint32_t GPIOE_MODE11:2; // GPIO mode for pin 11
    uint32_t GPIOE_MODE12:2; // GPIO mode for pin 12
    uint32_t GPIOE_MODE13:2; // GPIO mode for pin 13
    uint32_t GPIOE_MODE14:2; // GPIO mode for pin 14
    uint32_t GPIOE_MODE15:2; // GPIO mode for pin 15    
}GPIOE_MODER_B_t;

typedef union
{
    GPIOE_MODER_B_t B;
    uint32_t U;
}GPIOE_MODER_Reg_t;

extern volatile GPIOE_MODER_Reg_t GPIOE_MODER_Reg;

typedef struct
{
    uint32_t GPIOH_MODE0:2; // GPIO mode for pin 0
    uint32_t GPIOH_MODE1:2; // GPIO mode for pin 1   
    uint32_t GPIOH_MODE2:2; // GPIO mode for pin 2
    uint32_t GPIOH_MODE3:2; // GPIO mode for pin 3
    uint32_t GPIOH_MODE4:2; // GPIO mode for pin 4
    uint32_t GPIOH_MODE5:2; // GPIO mode for pin 5   
    uint32_t GPIOH_MODE6:2; // GPIO mode for pin 6
    uint32_t GPIOH_MODE7:2; // GPIO mode for pin 7
    uint32_t GPIOH_MODE8:2; // GPIO mode for pin 8
    uint32_t GPIOH_MODE9:2; // GPIO mode for pin 9
    uint32_t GPIOH_MODE10:2; // GPIO mode for pin 10
    uint32_t GPIOH_MODE11:2; // GPIO mode for pin 11
    uint32_t GPIOH_MODE12:2; // GPIO mode for pin 12
    uint32_t GPIOH_MODE13:2; // GPIO mode for pin 13
    uint32_t GPIOH_MODE14:2; // GPIO mode for pin 14
    uint32_t GPIOH_MODE15:2; // GPIO mode for pin 15  
}GPIOH_MODER_B_t;

typedef union
{
    GPIOH_MODER_B_t B;
    uint32_t U;
}GPIOH_MODER_Reg_t;

extern volatile GPIOH_MODER_Reg_t GPIOH_MODER_Reg;

enum {
    GPIO_OTYPE_PP = 0x0,   // Push-pull output type
    GPIO_OTYPE_OD = 0x1    // Open-drain output type
};

typedef struct
{
    uint32_t GPIOA_OTYPER0:1; // GPIO output type for pin 0
    uint32_t GPIOA_OTYPER1:1; // GPIO output type for pin 1
    uint32_t GPIOA_OTYPER2:1; // GPIO output type for pin 2
    uint32_t GPIOA_OTYPER3:1; // GPIO output type for pin 3
    uint32_t GPIOA_OTYPER4:1; // GPIO output type for pin   4
    uint32_t GPIOA_OTYPER5:1; // GPIO output type for pin 5
    uint32_t GPIOA_OTYPER6:1; // GPIO output type for pin   6
    uint32_t GPIOA_OTYPER7:1; // GPIO output type for pin 7
    uint32_t GPIOA_OTYPER8:1; // GPIO output type for pin 8 
    uint32_t GPIOA_OTYPER9:1; // GPIO output type for pin 9
    uint32_t GPIOA_OTYPER10:1; // GPIO output type for pin 10
    uint32_t GPIOA_OTYPER11:1; // GPIO output type for pin 11   
    uint32_t GPIOA_OTYPER12:1; // GPIO output type for pin 12
    uint32_t GPIOA_OTYPER13:1; // GPIO output type for pin 13
    uint32_t GPIOA_OTYPER14:1; // GPIO output type for pin 14
    uint32_t GPIOA_OTYPER15:1; // GPIO output type for pin 15
}GPIOA_OTYPER_B_t;

typedef union
{
    GPIOA_OTYPER_B_t B;
    uint32_t U;
}GPIOA_OTYPER_Reg_t;

extern volatile GPIOA_OTYPER_Reg_t GPIOA_OTYPER_Reg;

typedef struct
{
    uint32_t GPIOB_OTYPER0:1; // GPIO output type for pin 0
    uint32_t GPIOB_OTYPER1:1; // GPIO output type for pin 1
    uint32_t GPIOB_OTYPER2:1; // GPIO output type for pin 2
    uint32_t GPIOB_OTYPER3:1; // GPIO output type for pin 3
    uint32_t GPIOB_OTYPER4:1; // GPIO output type for pin   4
    uint32_t GPIOB_OTYPER5:1; // GPIO output type for pin 5
    uint32_t GPIOB_OTYPER6:1; // GPIO output type for pin   6
    uint32_t GPIOB_OTYPER7:1; // GPIO output type for pin 7
    uint32_t GPIOB_OTYPER8:1; // GPIO output type for pin 8 
    uint32_t GPIOB_OTYPER9:1; // GPIO output type for pin 9
    uint32_t GPIOB_OTYPER10:1; // GPIO output type for pin 10
    uint32_t GPIOB_OTYPER11:1; // GPIO output type for pin 11   
    uint32_t GPIOB_OTYPER12:1; // GPIO output type for pin 12
    uint32_t GPIOB_OTYPER13:1; // GPIO output type for pin 13
    uint32_t GPIOB_OTYPER14:1; // GPIO output type for pin 14
    uint32_t GPIOB_OTYPER15:1; // GPIO output type for pin 15
}GPIOB_OTYPER_B_t;

typedef union
{
    GPIOB_OTYPER_B_t B;
    uint32_t U;
}GPIOB_OTYPER_Reg_t;

extern volatile GPIOB_OTYPER_Reg_t GPIOB_OTYPER_Reg;

typedef struct
{
    uint32_t GPIOC_OTYPER0:1; // GPIO output type for pin 0
    uint32_t GPIOC_OTYPER1:1; // GPIO output type for pin 1
    uint32_t GPIOC_OTYPER2:1; // GPIO output type for pin 2
    uint32_t GPIOC_OTYPER3:1; // GPIO output type for pin 3
    uint32_t GPIOC_OTYPER4:1; // GPIO output type for pin   4
    uint32_t GPIOC_OTYPER5:1; // GPIO output type for pin 5
    uint32_t GPIOC_OTYPER6:1; // GPIO output type for pin   6
    uint32_t GPIOC_OTYPER7:1; // GPIO output type for pin 7
    uint32_t GPIOC_OTYPER8:1; // GPIO output type for pin 8 
    uint32_t GPIOC_OTYPER9:1; // GPIO output type for pin 9
    uint32_t GPIOC_OTYPER10:1; // GPIO output type for pin 10
    uint32_t GPIOC_OTYPER11:1; // GPIO output type for pin 11   
    uint32_t GPIOC_OTYPER12:1; // GPIO output type for pin 12
    uint32_t GPIOC_OTYPER13:1; // GPIO output type for pin 13
    uint32_t GPIOC_OTYPER14:1; // GPIO output type for pin 14
    uint32_t GPIOC_OTYPER15:1; // GPIO output type for pin 15   
}GPIOC_OTYPER_B_t;

typedef union
{
    GPIOC_OTYPER_B_t B;
    uint32_t U;
}GPIOC_OTYPER_Reg_t;

extern volatile GPIOC_OTYPER_Reg_t GPIOC_OTYPER_Reg;

typedef struct
{
    uint32_t GPIOD_OTYPER0:1; // GPIO output type for pin 0
    uint32_t GPIOD_OTYPER1:1; // GPIO output type for pin 1
    uint32_t GPIOD_OTYPER2:1; // GPIO output type for pin 2
    uint32_t GPIOD_OTYPER3:1; // GPIO output type for pin 3
    uint32_t GPIOD_OTYPER4:1; // GPIO output type for pin   4
    uint32_t GPIOD_OTYPER5:1; // GPIO output type for pin 5
    uint32_t GPIOD_OTYPER6:1; // GPIO output type for pin   6
    uint32_t GPIOD_OTYPER7:1; // GPIO output type for pin 7
    uint32_t GPIOD_OTYPER8:1; // GPIO output type for pin 8 
    uint32_t GPIOD_OTYPER9:1; // GPIO output type for pin 9
    uint32_t GPIOD_OTYPER10:1; // GPIO output type for pin 10
    uint32_t GPIOD_OTYPER11:1; // GPIO output type for pin 11   
    uint32_t GPIOD_OTYPER12:1; // GPIO output type for pin 12
    uint32_t GPIOD_OTYPER13:1; // GPIO output type for pin 13
    uint32_t GPIOD_OTYPER14:1; // GPIO output type for pin 14
    uint32_t GPIOD_OTYPER15:1; // GPIO output type for pin 15   
}GPIOD_OTYPER_B_t;

typedef union
{
    GPIOD_OTYPER_B_t B;
    uint32_t U;
}GPIOD_OTYPER_Reg_t;

extern volatile GPIOD_OTYPER_Reg_t GPIOD_OTYPER_Reg;

typedef struct
{
    uint32_t GPIOE_OTYPER0:1; // GPIO output type for pin 0
    uint32_t GPIOE_OTYPER1:1; // GPIO output type for pin 1
    uint32_t GPIOE_OTYPER2:1; // GPIO output type for pin 2
    uint32_t GPIOE_OTYPER3:1; // GPIO output type for pin 3
    uint32_t GPIOE_OTYPER4:1; // GPIO output type for pin   4
    uint32_t GPIOE_OTYPER5:1; // GPIO output type for pin 5
    uint32_t GPIOE_OTYPER6:1; // GPIO output type for pin   6
    uint32_t GPIOE_OTYPER7:1; // GPIO output type for pin 7
    uint32_t GPIOE_OTYPER8:1; // GPIO output type for pin 8 
    uint32_t GPIOE_OTYPER9:1; // GPIO output type for pin 9
    uint32_t GPIOE_OTYPER10:1; // GPIO output type for pin 10
    uint32_t GPIOE_OTYPER11:1; // GPIO output type for pin 11   
    uint32_t GPIOE_OTYPER12:1; // GPIO output type for pin 12
    uint32_t GPIOE_OTYPER13:1; // GPIO output type for pin 13
    uint32_t GPIOE_OTYPER14:1; // GPIO output type for pin 14
    uint32_t GPIOE_OTYPER15:1; // GPIO output type for pin 15   
}GPIOE_OTYPER_B_t;

typedef union
{
    GPIOE_OTYPER_B_t B;
    uint32_t U;
}GPIOE_OTYPER_Reg_t;

extern volatile GPIOE_OTYPER_Reg_t GPIOE_OTYPER_Reg;

typedef struct
{
    uint32_t GPIOH_OTYPER0:1; // GPIO output type for pin 0
    uint32_t GPIOH_OTYPER1:1; // GPIO output type for pin 1
    uint32_t GPIOH_OTYPER2:1; // GPIO output type for pin 2
    uint32_t GPIOH_OTYPER3:1; // GPIO output type for pin 3
    uint32_t GPIOH_OTYPER4:1; // GPIO output type for pin   4
    uint32_t GPIOH_OTYPER5:1; // GPIO output type for pin 5
    uint32_t GPIOH_OTYPER6:1; // GPIO output type for pin   6
    uint32_t GPIOH_OTYPER7:1; // GPIO output type for pin 7
    uint32_t GPIOH_OTYPER8:1; // GPIO output type for pin 8 
    uint32_t GPIOH_OTYPER9:1; // GPIO output type for pin 9
    uint32_t GPIOH_OTYPER10:1; // GPIO output type for pin 10
    uint32_t GPIOH_OTYPER11:1; // GPIO output type for pin 11   
    uint32_t GPIOH_OTYPER12:1; // GPIO output type for pin 12
    uint32_t GPIOH_OTYPER13:1; // GPIO output type for pin 13
    uint32_t GPIOH_OTYPER14:1; // GPIO output type for pin 14
    uint32_t GPIOH_OTYPER15:1; // GPIO output type for pin 15
}GPIOH_OTYPER_B_t;

typedef union
{
    GPIOH_OTYPER_B_t B;
    uint32_t U;
}GPIOH_OTYPER_Reg_t;

extern volatile GPIOH_OTYPER_Reg_t GPIOH_OTYPER_Reg;

enum {
    GPIO_SPEED_LOW = 0x0,    // Low speed
    GPIO_SPEED_MEDIUM = 0x1, // Medium speed
    GPIO_SPEED_HIGH = 0x2,   // High speed
    GPIO_SPEED_VERY_HIGH = 0x3 // Very high speed
};

typedef struct
{
    uint32_t GPIOA_OSPEEDR0:2; // GPIO speed for pin 0
    uint32_t GPIOA_OSPEEDR1:2; // GPIO speed for pin 1
    uint32_t GPIOA_OSPEEDR2:2; // GPIO speed for pin 2
    uint32_t GPIOA_OSPEEDR3:2; // GPIO speed for pin 3
    uint32_t GPIOA_OSPEEDR4:2; // GPIO speed for pin 4
    uint32_t GPIOA_OSPEEDR5:2; // GPIO speed for pin 5
    uint32_t GPIOA_OSPEEDR6:2; // GPIO speed for pin 6
    uint32_t GPIOA_OSPEEDR7:2; // GPIO speed for pin 7
    uint32_t GPIOA_OSPEEDR8:2; // GPIO speed for pin 8
    uint32_t GPIOA_OSPEEDR9:2; // GPIO speed for pin 9
    uint32_t GPIOA_OSPEEDR10:2; // GPIO speed for pin 10
    uint32_t GPIOA_OSPEEDR11:2; // GPIO speed for pin 11
    uint32_t GPIOA_OSPEEDR12:2; // GPIO speed for pin 12
    uint32_t GPIOA_OSPEEDR13:2; // GPIO speed for pin 13
    uint32_t GPIOA_OSPEEDR14:2; // GPIO speed for pin 14
    uint32_t GPIOA_OSPEEDR15:2; // GPIO speed for pin 15
}GPIOA_OSPEEDR_B_t;

typedef union
{
    GPIOA_OSPEEDR_B_t B;
    uint32_t U;
}GPIOA_OSPEEDR_Reg_t;

extern volatile GPIOA_OSPEEDR_Reg_t GPIOA_OSPEEDR_Reg;

typedef struct
{
    uint32_t GPIOB_OSPEEDR0:2; // GPIO speed for pin 0
    uint32_t GPIOB_OSPEEDR1:2; // GPIO speed for pin 1
    uint32_t GPIOB_OSPEEDR2:2; // GPIO speed for pin 2
    uint32_t GPIOB_OSPEEDR3:2; // GPIO speed for pin 3
    uint32_t GPIOB_OSPEEDR4:2; // GPIO speed for pin 4
    uint32_t GPIOB_OSPEEDR5:2; // GPIO speed for pin 5
    uint32_t GPIOB_OSPEEDR6:2; // GPIO speed for pin 6
    uint32_t GPIOB_OSPEEDR7:2; // GPIO speed for pin 7
    uint32_t GPIOB_OSPEEDR8:2; // GPIO speed for pin 8
    uint32_t GPIOB_OSPEEDR9:2; // GPIO speed for pin 9
    uint32_t GPIOB_OSPEEDR10:2; // GPIO speed for pin 10
    uint32_t GPIOB_OSPEEDR11:2; // GPIO speed for pin 11
    uint32_t GPIOB_OSPEEDR12:2; // GPIO speed for pin 12
    uint32_t GPIOB_OSPEEDR13:2; // GPIO speed for pin 13
    uint32_t GPIOB_OSPEEDR14:2; // GPIO speed for pin 14
    uint32_t GPIOB_OSPEEDR15:2; // GPIO speed for pin 15
}GPIOB_OSPEEDR_B_t;

typedef union
{
    GPIOB_OSPEEDR_B_t B;
    uint32_t U;
}GPIOB_OSPEEDR_Reg_t;

extern volatile GPIOB_OSPEEDR_Reg_t GPIOB_OSPEEDR_Reg;

typedef struct
{
    uint32_t GPIOC_OSPEEDR0:2; // GPIO speed for pin 0
    uint32_t GPIOC_OSPEEDR1:2; // GPIO speed for pin 1
    uint32_t GPIOC_OSPEEDR2:2; // GPIO speed for pin 2
    uint32_t GPIOC_OSPEEDR3:2; // GPIO speed for pin 3
    uint32_t GPIOC_OSPEEDR4:2; // GPIO speed for pin 4
    uint32_t GPIOC_OSPEEDR5:2; // GPIO speed for pin 5
    uint32_t GPIOC_OSPEEDR6:2; // GPIO speed for pin 6
    uint32_t GPIOC_OSPEEDR7:2; // GPIO speed for pin 7
    uint32_t GPIOC_OSPEEDR8:2; // GPIO speed for pin 8
    uint32_t GPIOC_OSPEEDR9:2; // GPIO speed for pin 9
    uint32_t GPIOC_OSPEEDR10:2; // GPIO speed for pin 10
    uint32_t GPIOC_OSPEEDR11:2; // GPIO speed for pin 11
    uint32_t GPIOC_OSPEEDR12:2; // GPIO speed for pin 12
    uint32_t GPIOC_OSPEEDR13:2; // GPIO speed for pin 13
    uint32_t GPIOC_OSPEEDR14:2; // GPIO speed for pin 14
    uint32_t GPIOC_OSPEEDR15:2; // GPIO speed for pin 15    
}GPIOC_OSPEEDR_B_t;

typedef union
{
    GPIOC_OSPEEDR_B_t B;
    uint32_t U;
}GPIOC_OSPEEDR_Reg_t;

extern volatile GPIOC_OSPEEDR_Reg_t GPIOC_OSPEEDR_Reg;

typedef struct
{
    uint32_t GPIOD_OSPEEDR0:2; // GPIO speed for pin 0
    uint32_t GPIOD_OSPEEDR1:2; // GPIO speed for pin 1
    uint32_t GPIOD_OSPEEDR2:2; // GPIO speed for pin 2
    uint32_t GPIOD_OSPEEDR3:2; // GPIO speed for pin 3
    uint32_t GPIOD_OSPEEDR4:2; // GPIO speed for pin 4
    uint32_t GPIOD_OSPEEDR5:2; // GPIO speed for pin 5
    uint32_t GPIOD_OSPEEDR6:2; // GPIO speed for pin 6
    uint32_t GPIOD_OSPEEDR7:2; // GPIO speed for pin 7
    uint32_t GPIOD_OSPEEDR8:2; // GPIO speed for pin 8
    uint32_t GPIOD_OSPEEDR9:2; // GPIO speed for pin 9
    uint32_t GPIOD_OSPEEDR10:2; // GPIO speed for pin 10
    uint32_t GPIOD_OSPEEDR11:2; // GPIO speed for pin 11
    uint32_t GPIOD_OSPEEDR12:2; // GPIO speed for pin 12
    uint32_t GPIOD_OSPEEDR13:2; // GPIO speed for pin 13
    uint32_t GPIOD_OSPEEDR14:2; // GPIO speed for pin 14
    uint32_t GPIOD_OSPEEDR15:2; // GPIO speed for pin 15   
}GPIOD_OSPEEDR_B_t;

typedef union
{
    GPIOD_OSPEEDR_B_t B;
    uint32_t U;
}GPIOD_OSPEEDR_Reg_t;

extern volatile GPIOD_OSPEEDR_Reg_t GPIOD_OSPEEDR_Reg;

typedef struct
{
    uint32_t GPIOE_OSPEEDR0:2; // GPIO speed for pin 0
    uint32_t GPIOE_OSPEEDR1:2; // GPIO speed for pin 1
    uint32_t GPIOE_OSPEEDR2:2; // GPIO speed for pin 2
    uint32_t GPIOE_OSPEEDR3:2; // GPIO speed for pin 3
    uint32_t GPIOE_OSPEEDR4:2; // GPIO speed for pin 4
    uint32_t GPIOE_OSPEEDR5:2; // GPIO speed for pin 5
    uint32_t GPIOE_OSPEEDR6:2; // GPIO speed for pin 6
    uint32_t GPIOE_OSPEEDR7:2; // GPIO speed for pin 7
    uint32_t GPIOE_OSPEEDR8:2; // GPIO speed for pin 8
    uint32_t GPIOE_OSPEEDR9:2; // GPIO speed for pin 9
    uint32_t GPIOE_OSPEEDR10:2; // GPIO speed for pin 10
    uint32_t GPIOE_OSPEEDR11:2; // GPIO speed for pin 11
    uint32_t GPIOE_OSPEEDR12:2; // GPIO speed for pin 12
    uint32_t GPIOE_OSPEEDR13:2; // GPIO speed for pin 13
    uint32_t GPIOE_OSPEEDR14:2; // GPIO speed for pin 14
    uint32_t GPIOE_OSPEEDR15:2; // GPIO speed for pin 15
}GPIOE_OSPEEDR_B_t;

typedef union
{
    GPIOE_OSPEEDR_B_t B;
    uint32_t U;
}GPIOE_OSPEEDR_Reg_t;

extern volatile GPIOE_OSPEEDR_Reg_t GPIOE_OSPEEDR_Reg;

typedef struct
{
    uint32_t GPIOH_OSPEEDR0:2; // GPIO speed for pin 0
    uint32_t GPIOH_OSPEEDR1:2; // GPIO speed for pin 1
    uint32_t GPIOH_OSPEEDR2:2; // GPIO speed for pin 2
    uint32_t GPIOH_OSPEEDR3:2; // GPIO speed for pin 3
    uint32_t GPIOH_OSPEEDR4:2; // GPIO speed for pin 4
    uint32_t GPIOH_OSPEEDR5:2; // GPIO speed for pin 5
    uint32_t GPIOH_OSPEEDR6:2; // GPIO speed for pin 6
    uint32_t GPIOH_OSPEEDR7:2; // GPIO speed for pin 7
    uint32_t GPIOH_OSPEEDR8:2; // GPIO speed for pin 8
    uint32_t GPIOH_OSPEEDR9:2; // GPIO speed for pin 9
    uint32_t GPIOH_OSPEEDR10:2; // GPIO speed for pin 10
    uint32_t GPIOH_OSPEEDR11:2; // GPIO speed for pin 11
    uint32_t GPIOH_OSPEEDR12:2; // GPIO speed for pin 12
    uint32_t GPIOH_OSPEEDR13:2; // GPIO speed for pin 13
    uint32_t GPIOH_OSPEEDR14:2; // GPIO speed for pin 14
    uint32_t GPIOH_OSPEEDR15:2; // GPIO speed for pin 15
}GPIOH_OSPEEDR_B_t;

typedef union
{
    GPIOH_OSPEEDR_B_t B;
    uint32_t U;
}GPIOH_OSPEEDR_Reg_t;

extern volatile GPIOH_OSPEEDR_Reg_t GPIOH_OSPEEDR_Reg;

enum {
    GPIO_PUPD_NONE = 0x0,   // No pull-up or pull-down
    GPIO_PUPD_PULL_UP = 0x1, // Pull-up
    GPIO_PUPD_PULL_DOWN = 0x2 // Pull-down
};

typedef struct
{
    uint32_t GPIOA_PUPDR0:2; // GPIO pull-up/pull-down for pin 0
    uint32_t GPIOA_PUPDR1:2; // GPIO pull-up/pull-down for pin 1
    uint32_t GPIOA_PUPDR2:2; // GPIO pull-up/pull-down for pin 2
    uint32_t GPIOA_PUPDR3:2; // GPIO pull-up/pull-down for pin 3
    uint32_t GPIOA_PUPDR4:2; // GPIO pull-up/pull-down for pin 4
    uint32_t GPIOA_PUPDR5:2; // GPIO pull-up/pull-down for pin 5
    uint32_t GPIOA_PUPDR6:2; // GPIO pull-up/pull-down for pin 6
    uint32_t GPIOA_PUPDR7:2; // GPIO pull-up/pull-down for pin 7
    uint32_t GPIOA_PUPDR8:2; // GPIO pull-up/pull-down for pin 8
    uint32_t GPIOA_PUPDR9:2; // GPIO pull-up/pull-down for pin 9
    uint32_t GPIOA_PUPDR10:2; // GPIO pull-up/pull-down for pin 10
    uint32_t GPIOA_PUPDR11:2; // GPIO pull-up/pull-down for pin 11
    uint32_t GPIOA_PUPDR12:2; // GPIO pull-up/pull-down for pin 12
    uint32_t GPIOA_PUPDR13:2; // GPIO pull-up/pull-down for pin 13
    uint32_t GPIOA_PUPDR14:2; // GPIO pull-up/pull-down for pin 14
    uint32_t GPIOA_PUPDR15:2; // GPIO pull-up/pull-down for pin 15
}GPIOA_PUPDR_B_t;

typedef union
{
    GPIOA_PUPDR_B_t B;
    uint32_t U;
}GPIOA_PUPDR_Reg_t;

extern volatile GPIOA_PUPDR_Reg_t GPIOA_PUPDR_Reg;

typedef struct
{
    uint32_t GPIOB_PUPDR0:2; // GPIO pull-up/pull-down for pin 0
    uint32_t GPIOB_PUPDR1:2; // GPIO pull-up/pull-down for pin 1
    uint32_t GPIOB_PUPDR2:2; // GPIO pull-up/pull-down for pin 2
    uint32_t GPIOB_PUPDR3:2; // GPIO pull-up/pull-down for pin 3
    uint32_t GPIOB_PUPDR4:2; // GPIO pull-up/pull-down for pin 4
    uint32_t GPIOB_PUPDR5:2; // GPIO pull-up/pull-down for pin 5
    uint32_t GPIOB_PUPDR6:2; // GPIO pull-up/pull-down for pin 6
    uint32_t GPIOB_PUPDR7:2; // GPIO pull-up/pull-down for pin 7
    uint32_t GPIOB_PUPDR8:2; // GPIO pull-up/pull-down for pin 8
    uint32_t GPIOB_PUPDR9:2; // GPIO pull-up/pull-down for pin 9
    uint32_t GPIOB_PUPDR10:2; // GPIO pull-up/pull-down for pin 10
    uint32_t GPIOB_PUPDR11:2; // GPIO pull-up/pull-down for pin 11
    uint32_t GPIOB_PUPDR12:2; // GPIO pull-up/pull-down for pin 12
    uint32_t GPIOB_PUPDR13:2; // GPIO pull-up/pull-down for pin 13
    uint32_t GPIOB_PUPDR14:2; // GPIO pull-up/pull-down for pin 14
    uint32_t GPIOB_PUPDR15:2; // GPIO pull-up/pull-down for pin 15
}GPIOB_PUPDR_B_t;

typedef union
{
    GPIOB_PUPDR_B_t B;
    uint32_t U;
}GPIOB_PUPDR_Reg_t;

extern volatile GPIOB_PUPDR_Reg_t GPIOB_PUPDR_Reg;

typedef struct
{
    uint32_t GPIOC_PUPDR0:2; // GPIO pull-up/pull-down for pin 0
    uint32_t GPIOC_PUPDR1:2; // GPIO pull-up/pull-down for pin 1
    uint32_t GPIOC_PUPDR2:2; // GPIO pull-up/pull-down for pin 2
    uint32_t GPIOC_PUPDR3:2; // GPIO pull-up/pull-down for pin 3
    uint32_t GPIOC_PUPDR4:2; // GPIO pull-up/pull-down for pin 4
    uint32_t GPIOC_PUPDR5:2; // GPIO pull-up/pull-down for pin 5
    uint32_t GPIOC_PUPDR6:2; // GPIO pull-up/pull-down for pin 6
    uint32_t GPIOC_PUPDR7:2; // GPIO pull-up/pull-down for pin 7
    uint32_t GPIOC_PUPDR8:2; // GPIO pull-up/pull-down for pin 8
    uint32_t GPIOC_PUPDR9:2; // GPIO pull-up/pull-down for pin 9
    uint32_t GPIOC_PUPDR10:2; // GPIO pull-up/pull-down for pin 10
    uint32_t GPIOC_PUPDR11:2; // GPIO pull-up/pull-down for pin 11
    uint32_t GPIOC_PUPDR12:2; // GPIO pull-up/pull-down for pin 12
    uint32_t GPIOC_PUPDR13:2; // GPIO pull-up/pull-down for pin 13
    uint32_t GPIOC_PUPDR14:2; // GPIO pull-up/pull-down for pin 14
    uint32_t GPIOC_PUPDR15:2; // GPIO pull-up/pull-down for pin 15
}GPIOC_PUPDR_B_t;

typedef union
{
    GPIOC_PUPDR_B_t B;
    uint32_t U;
}GPIOC_PUPDR_Reg_t;

extern volatile GPIOC_PUPDR_Reg_t GPIOC_PUPDR_Reg;

typedef struct
{
    uint32_t GPIOD_PUPDR0:2; // GPIO pull-up/pull-down for pin 0
    uint32_t GPIOD_PUPDR1:2; // GPIO pull-up/pull-down for pin 1
    uint32_t GPIOD_PUPDR2:2; // GPIO pull-up/pull-down for pin 2
    uint32_t GPIOD_PUPDR3:2; // GPIO pull-up/pull-down for pin 3
    uint32_t GPIOD_PUPDR4:2; // GPIO pull-up/pull-down for pin 4
    uint32_t GPIOD_PUPDR5:2; // GPIO pull-up/pull-down for pin 5
    uint32_t GPIOD_PUPDR6:2; // GPIO pull-up/pull-down for pin 6
    uint32_t GPIOD_PUPDR7:2; // GPIO pull-up/pull-down for pin 7
    uint32_t GPIOD_PUPDR8:2; // GPIO pull-up/pull-down for pin 8
    uint32_t GPIOD_PUPDR9:2; // GPIO pull-up/pull-down for pin 9
    uint32_t GPIOD_PUPDR10:2; // GPIO pull-up/pull-down for pin 10
    uint32_t GPIOD_PUPDR11:2; // GPIO pull-up/pull-down for pin 11
    uint32_t GPIOD_PUPDR12:2; // GPIO pull-up/pull-down for pin 12
    uint32_t GPIOD_PUPDR13:2; // GPIO pull-up/pull-down for pin 13
    uint32_t GPIOD_PUPDR14:2; // GPIO pull-up/pull-down for pin 14
    uint32_t GPIOD_PUPDR15:2; // GPIO pull-up/pull-down for pin 15
}GPIOD_PUPDR_B_t;

typedef union
{
    GPIOD_PUPDR_B_t B;
    uint32_t U;
}GPIOD_PUPDR_Reg_t;

extern volatile GPIOD_PUPDR_Reg_t GPIOD_PUPDR_Reg;

typedef struct
{
    uint32_t GPIOE_PUPDR0:2; // GPIO pull-up/pull-down for pin 0
    uint32_t GPIOE_PUPDR1:2; // GPIO pull-up/pull-down for pin 1
    uint32_t GPIOE_PUPDR2:2; // GPIO pull-up/pull-down for pin 2
    uint32_t GPIOE_PUPDR3:2; // GPIO pull-up/pull-down for pin 3
    uint32_t GPIOE_PUPDR4:2; // GPIO pull-up/pull-down for pin 4
    uint32_t GPIOE_PUPDR5:2; // GPIO pull-up/pull-down for pin 5
    uint32_t GPIOE_PUPDR6:2; // GPIO pull-up/pull-down for pin 6
    uint32_t GPIOE_PUPDR7:2; // GPIO pull-up/pull-down for pin 7
    uint32_t GPIOE_PUPDR8:2; // GPIO pull-up/pull-down for pin 8
    uint32_t GPIOE_PUPDR9:2; // GPIO pull-up/pull-down for pin 9
    uint32_t GPIOE_PUPDR10:2; // GPIO pull-up/pull-down for pin 10
    uint32_t GPIOE_PUPDR11:2; // GPIO pull-up/pull-down for pin 11
    uint32_t GPIOE_PUPDR12:2; // GPIO pull-up/pull-down for pin 12
    uint32_t GPIOE_PUPDR13:2; // GPIO pull-up/pull-down for pin 13
    uint32_t GPIOE_PUPDR14:2; // GPIO pull-up/pull-down for pin 14
    uint32_t GPIOE_PUPDR15:2; // GPIO pull-up/pull-down for pin 15
}GPIOE_PUPDR_B_t;

typedef union
{
    GPIOE_PUPDR_B_t B;
    uint32_t U;
}GPIOE_PUPDR_Reg_t;

extern volatile GPIOE_PUPDR_Reg_t GPIOE_PUPDR_Reg;

typedef struct
{
    uint32_t GPIOH_PUPDR0:2; // GPIO pull-up/pull-down for pin 0
    uint32_t GPIOH_PUPDR1:2; // GPIO pull-up/pull-down for pin 1
    uint32_t GPIOH_PUPDR2:2; // GPIO pull-up/pull-down for pin 2
    uint32_t GPIOH_PUPDR3:2; // GPIO pull-up/pull-down for pin 3
    uint32_t GPIOH_PUPDR4:2; // GPIO pull-up/pull-down for pin 4
    uint32_t GPIOH_PUPDR5:2; // GPIO pull-up/pull-down for pin 5
    uint32_t GPIOH_PUPDR6:2; // GPIO pull-up/pull-down for pin 6
    uint32_t GPIOH_PUPDR7:2; // GPIO pull-up/pull-down for pin 7
    uint32_t GPIOH_PUPDR8:2; // GPIO pull-up/pull-down for pin 8
    uint32_t GPIOH_PUPDR9:2; // GPIO pull-up/pull-down for pin 9
    uint32_t GPIOH_PUPDR10:2; // GPIO pull-up/pull-down for pin 10
    uint32_t GPIOH_PUPDR11:2; // GPIO pull-up/pull-down for pin 11
    uint32_t GPIOH_PUPDR12:2; // GPIO pull-up/pull-down for pin 12
    uint32_t GPIOH_PUPDR13:2; // GPIO pull-up/pull-down for pin 13
    uint32_t GPIOH_PUPDR14:2; // GPIO pull-up/pull-down for pin 14
    uint32_t GPIOH_PUPDR15:2; // GPIO pull-up/pull-down for pin 15
}GPIOH_PUPDR_B_t;

typedef union
{
    GPIOH_PUPDR_B_t B;
    uint32_t U;
}GPIOH_PUPDR_Reg_t;

extern volatile GPIOH_PUPDR_Reg_t GPIOH_PUPDR_Reg;

typedef struct
{
    uint32_t GPIOA_ID0:1; // GPIOA pin 0 input data
    uint32_t GPIOA_ID1:1; // GPIOA pin 1 input data
    uint32_t GPIOA_ID2:1; // GPIOA pin 2 input data
    uint32_t GPIOA_ID3:1; // GPIOA pin 3 input data
    uint32_t GPIOA_ID4:1; // GPIOA pin 4 input data
    uint32_t GPIOA_ID5:1; // GPIOA pin 5 input data
    uint32_t GPIOA_ID6:1; // GPIOA pin 6 input data
    uint32_t GPIOA_ID7:1; // GPIOA pin 7 input data
    uint32_t GPIOA_ID8:1; // GPIOA pin 8 input data
    uint32_t GPIOA_ID9:1; // GPIOA pin 9 input data
    uint32_t GPIOA_ID10:1; // GPIOA pin 10 input data
    uint32_t GPIOA_ID11:1; // GPIOA pin 11 input data
    uint32_t GPIOA_ID12:1; // GPIOA pin 12 input data
    uint32_t GPIOA_ID13:1; // GPIOA pin 13 input data
    uint32_t GPIOA_ID14:1; // GPIOA pin 14 input data
    uint32_t GPIOA_ID15:1; // GPIOA pin 15 input data
}GPIOA_IDR_B_t;

typedef union
{
    GPIOA_IDR_B_t B;
    uint32_t U;
}GPIOA_IDR_Reg_t;

extern volatile GPIOA_IDR_Reg_t GPIOA_IDR_Reg;

typedef struct
{
    uint32_t GPIOB_ID0:1; // GPIOB pin 0 input data
    uint32_t GPIOB_ID1:1; // GPIOB pin 1 input data
    uint32_t GPIOB_ID2:1; // GPIOB pin 2 input data
    uint32_t GPIOB_ID3:1; // GPIOB pin 3 input data
    uint32_t GPIOB_ID4:1; // GPIOB pin 4 input data
    uint32_t GPIOB_ID5:1; // GPIOB pin 5 input data
    uint32_t GPIOB_ID6:1; // GPIOB pin 6 input data
    uint32_t GPIOB_ID7:1; // GPIOB pin 7 input data
    uint32_t GPIOB_ID8:1; // GPIOB pin 8 input data
    uint32_t GPIOB_ID9:1; // GPIOB pin 9 input data
    uint32_t GPIOB_ID10:1; // GPIOB pin 10 input data
    uint32_t GPIOB_ID11:1; // GPIOB pin 11 input data
    uint32_t GPIOB_ID12:1; // GPIOB pin 12 input data
    uint32_t GPIOB_ID13:1; // GPIOB pin 13 input data
    uint32_t GPIOB_ID14:1; // GPIOB pin 14 input data
    uint32_t GPIOB_ID15:1; // GPIOB pin 15 input data
}GPIOB_IDR_B_t;

typedef union
{
    GPIOB_IDR_B_t B;
    uint32_t U;
}GPIOB_IDR_Reg_t;

extern volatile GPIOB_IDR_Reg_t GPIOB_IDR_Reg;

typedef struct
{
    uint32_t GPIOC_ID0:1; // GPIOC pin 0 input data
    uint32_t GPIOC_ID1:1; // GPIOC pin 1 input data
    uint32_t GPIOC_ID2:1; // GPIOC pin 2 input data
    uint32_t GPIOC_ID3:1; // GPIOC pin 3 input data
    uint32_t GPIOC_ID4:1; // GPIOC pin 4 input data
    uint32_t GPIOC_ID5:1; // GPIOC pin 5 input data
    uint32_t GPIOC_ID6:1; // GPIOC pin 6 input data
    uint32_t GPIOC_ID7:1; // GPIOC pin 7 input data
    uint32_t GPIOC_ID8:1; // GPIOC pin 8 input data
    uint32_t GPIOC_ID9:1; // GPIOC pin 9 input data
    uint32_t GPIOC_ID10:1; // GPIOC pin 10 input data
    uint32_t GPIOC_ID11:1; // GPIOC pin 11 input data
    uint32_t GPIOC_ID12:1; // GPIOC pin 12 input data
    uint32_t GPIOC_ID13:1; // GPIOC pin 13 input data
    uint32_t GPIOC_ID14:1; // GPIOC pin 14 input data
    uint32_t GPIOC_ID15:1; // GPIOC pin 15 input data
}GPIOC_IDR_B_t;

typedef union
{
    GPIOC_IDR_B_t B;
    uint32_t U;
}GPIOC_IDR_Reg_t;

extern volatile GPIOC_IDR_Reg_t GPIOC_IDR_Reg;

typedef struct
{
    uint32_t GPIOD_ID0:1; // GPIOD pin 0 input data
    uint32_t GPIOD_ID1:1; // GPIOD pin 1 input data
    uint32_t GPIOD_ID2:1; // GPIOD pin 2 input data
    uint32_t GPIOD_ID3:1; // GPIOD pin 3 input data
    uint32_t GPIOD_ID4:1; // GPIOD pin 4 input data
    uint32_t GPIOD_ID5:1; // GPIOD pin 5 input data
    uint32_t GPIOD_ID6:1; // GPIOD pin 6 input data
    uint32_t GPIOD_ID7:1; // GPIOD pin 7 input data
    uint32_t GPIOD_ID8:1; // GPIOD pin 8 input data
    uint32_t GPIOD_ID9:1; // GPIOD pin 9 input data
    uint32_t GPIOD_ID10:1; // GPIOD pin 10 input data
    uint32_t GPIOD_ID11:1; // GPIOD pin 11 input data
    uint32_t GPIOD_ID12:1; // GPIOD pin 12 input data
    uint32_t GPIOD_ID13:1; // GPIOD pin 13 input data
    uint32_t GPIOD_ID14:1; // GPIOD pin 14 input data
    uint32_t GPIOD_ID15:1; // GPIOD pin 15 input data
}GPIOD_IDR_B_t;

typedef union
{
    GPIOD_IDR_B_t B;
    uint32_t U;
}GPIOD_IDR_Reg_t;

extern volatile GPIOD_IDR_Reg_t GPIOD_IDR_Reg;

typedef struct
{
    uint32_t GPIOE_ID0:1; // GPIOE pin 0 input data
    uint32_t GPIOE_ID1:1; // GPIOE pin 1 input data
    uint32_t GPIOE_ID2:1; // GPIOE pin 2 input data
    uint32_t GPIOE_ID3:1; // GPIOE pin 3 input data
    uint32_t GPIOE_ID4:1; // GPIOE pin 4 input data
    uint32_t GPIOE_ID5:1; // GPIOE pin 5 input data
    uint32_t GPIOE_ID6:1; // GPIOE pin 6 input data
    uint32_t GPIOE_ID7:1; // GPIOE pin 7 input data
    uint32_t GPIOE_ID8:1; // GPIOE pin 8 input data
    uint32_t GPIOE_ID9:1; // GPIOE pin 9 input data
    uint32_t GPIOE_ID10:1; // GPIOE pin 10 input data
    uint32_t GPIOE_ID11:1; // GPIOE pin 11 input data
    uint32_t GPIOE_ID12:1; // GPIOE pin 12 input data
    uint32_t GPIOE_ID13:1; // GPIOE pin 13 input data
    uint32_t GPIOE_ID14:1; // GPIOE pin 14 input data
    uint32_t GPIOE_ID15:1; // GPIOE pin 15 input data
}GPIOE_IDR_B_t;

typedef union
{
    GPIOE_IDR_B_t B;
    uint32_t U;
}GPIOE_IDR_Reg_t;

extern volatile GPIOE_IDR_Reg_t GPIOE_IDR_Reg;

typedef struct
{
    uint32_t GPIOH_ID0:1; // GPIOH pin 0 input data
    uint32_t GPIOH_ID1:1; // GPIOH pin 1 input data
    uint32_t GPIOH_ID2:1; // GPIOH pin 2 input data
    uint32_t GPIOH_ID3:1; // GPIOH pin 3 input data
    uint32_t GPIOH_ID4:1; // GPIOH pin 4 input data
    uint32_t GPIOH_ID5:1; // GPIOH pin 5 input data
    uint32_t GPIOH_ID6:1; // GPIOH pin 6 input data
    uint32_t GPIOH_ID7:1; // GPIOH pin 7 input data
    uint32_t GPIOH_ID8:1; // GPIOH pin 8 input data
    uint32_t GPIOH_ID9:1; // GPIOH pin 9 input data
    uint32_t GPIOH_ID10:1; // GPIOH pin 10 input data
    uint32_t GPIOH_ID11:1; // GPIOH pin 11 input data
    uint32_t GPIOH_ID12:1; // GPIOH pin 12 input data
    uint32_t GPIOH_ID13:1; // GPIOH pin 13 input data
    uint32_t GPIOH_ID14:1; // GPIOH pin 14 input data
    uint32_t GPIOH_ID15:1; // GPIOH pin 15 input data
}GPIOH_IDR_B_t;

typedef union
{
    GPIOH_IDR_B_t B;
    uint32_t U;
}GPIOH_IDR_Reg_t;

extern volatile GPIOH_IDR_Reg_t GPIOH_IDR_Reg;

enum {
    GPIOA_ODR_LOW = 0x0, // Output data low
    GPIOA_ODR_HIGH = 0x1 // Output data high
};

typedef struct
{
    uint32_t GPIOA_ODR0:1; // GPIOA pin 0 output data
    uint32_t GPIOA_ODR1:1; // GPIOA pin 1 output data
    uint32_t GPIOA_ODR2:1; // GPIOA pin 2 output data
    uint32_t GPIOA_ODR3:1; // GPIOA pin 3 output data
    uint32_t GPIOA_ODR4:1; // GPIOA pin 4 output data
    uint32_t GPIOA_ODR5:1; // GPIOA pin 5 output data
    uint32_t GPIOA_ODR6:1; // GPIOA pin 6 output data
    uint32_t GPIOA_ODR7:1; // GPIOA pin 7 output data
    uint32_t GPIOA_ODR8:1; // GPIOA pin 8 output data
    uint32_t GPIOA_ODR9:1; // GPIOA pin 9 output data
    uint32_t GPIOA_ODR10:1; // GPIOA pin 10 output data
    uint32_t GPIOA_ODR11:1; // GPIOA pin 11 output data
    uint32_t GPIOA_ODR12:1; // GPIOA pin 12 output data
    uint32_t GPIOA_ODR13:1; // GPIOA pin 13 output data
    uint32_t GPIOA_ODR14:1; // GPIOA pin 14 output data
    uint32_t GPIOA_ODR15:1; // GPIOA pin 15 output data
}GPIOA_ODR_B_t;

typedef union
{
    GPIOA_ODR_B_t B;
    uint32_t U;
}GPIOA_ODR_Reg_t;

extern volatile GPIOA_ODR_Reg_t GPIOA_ODR_Reg;

typedef struct
{
    uint32_t GPIOB_ODR0:1; // GPIOB pin 0 output data
    uint32_t GPIOB_ODR1:1; // GPIOB pin 1 output data
    uint32_t GPIOB_ODR2:1; // GPIOB pin 2 output data
    uint32_t GPIOB_ODR3:1; // GPIOB pin 3 output data
    uint32_t GPIOB_ODR4:1; // GPIOB pin 4 output data
    uint32_t GPIOB_ODR5:1; // GPIOB pin 5 output data
    uint32_t GPIOB_ODR6:1; // GPIOB pin 6 output data
    uint32_t GPIOB_ODR7:1; // GPIOB pin 7 output data
    uint32_t GPIOB_ODR8:1; // GPIOB pin 8 output data
    uint32_t GPIOB_ODR9:1; // GPIOB pin 9 output data
    uint32_t GPIOB_ODR10:1; // GPIOB pin 10 output data
    uint32_t GPIOB_ODR11:1; // GPIOB pin 11 output data
    uint32_t GPIOB_ODR12:1; // GPIOB pin 12 output data
    uint32_t GPIOB_ODR13:1; // GPIOB pin 13 output data
    uint32_t GPIOB_ODR14:1; // GPIOB pin 14 output data
    uint32_t GPIOB_ODR15:1; // GPIOB pin 15 output data
}GPIOB_ODR_B_t;

typedef union
{
    GPIOB_ODR_B_t B;
    uint32_t U;
}GPIOB_ODR_Reg_t;

extern volatile GPIOB_ODR_Reg_t GPIOB_ODR_Reg;

typedef struct
{
    uint32_t GPIOC_ODR0:1; // GPIOC pin 0 output data
    uint32_t GPIOC_ODR1:1; // GPIOC pin 1 output data
    uint32_t GPIOC_ODR2:1; // GPIOC pin 2 output data
    uint32_t GPIOC_ODR3:1; // GPIOC pin 3 output data
    uint32_t GPIOC_ODR4:1; // GPIOC pin 4 output data
    uint32_t GPIOC_ODR5:1; // GPIOC pin 5 output data
    uint32_t GPIOC_ODR6:1; // GPIOC pin 6 output data
    uint32_t GPIOC_ODR7:1; // GPIOC pin 7 output data
    uint32_t GPIOC_ODR8:1; // GPIOC pin 8 output data
    uint32_t GPIOC_ODR9:1; // GPIOC pin 9 output data
    uint32_t GPIOC_ODR10:1; // GPIOC pin 10 output data
    uint32_t GPIOC_ODR11:1; // GPIOC pin 11 output data
    uint32_t GPIOC_ODR12:1; // GPIOC pin 12 output data
    uint32_t GPIOC_ODR13:1; // GPIOC pin 13 output data
    uint32_t GPIOC_ODR14:1; // GPIOC pin 14 output data
    uint32_t GPIOC_ODR15:1; // GPIOC pin 15 output data
}GPIOC_ODR_B_t;

typedef union
{
    GPIOC_ODR_B_t B;
    uint32_t U;
}GPIOC_ODR_Reg_t;

extern volatile GPIOC_ODR_Reg_t GPIOC_ODR_Reg;

typedef struct
{
    uint32_t GPIOD_ODR0:1; // GPIOD pin 0 output data
    uint32_t GPIOD_ODR1:1; // GPIOD pin 1 output data
    uint32_t GPIOD_ODR2:1; // GPIOD pin 2 output data
    uint32_t GPIOD_ODR3:1; // GPIOD pin 3 output data
    uint32_t GPIOD_ODR4:1; // GPIOD pin 4 output data
    uint32_t GPIOD_ODR5:1; // GPIOD pin 5 output data
    uint32_t GPIOD_ODR6:1; // GPIOD pin 6 output data
    uint32_t GPIOD_ODR7:1; // GPIOD pin 7 output data
    uint32_t GPIOD_ODR8:1; // GPIOD pin 8 output data
    uint32_t GPIOD_ODR9:1; // GPIOD pin 9 output data
    uint32_t GPIOD_ODR10:1; // GPIOD pin 10 output data
    uint32_t GPIOD_ODR11:1; // GPIOD pin 11 output data
    uint32_t GPIOD_ODR12:1; // GPIOD pin 12 output data
    uint32_t GPIOD_ODR13:1; // GPIOD pin 13 output data
    uint32_t GPIOD_ODR14:1; // GPIOD pin 14 output data
    uint32_t GPIOD_ODR15:1; // GPIOD pin 15 output data
}GPIOD_ODR_B_t;

typedef union
{
    GPIOD_ODR_B_t B;
    uint32_t U;
}GPIOD_ODR_Reg_t;

extern volatile GPIOD_ODR_Reg_t GPIOD_ODR_Reg;

typedef struct
{
    uint32_t GPIOE_ODR0:1; // GPIOE pin 0 output data
    uint32_t GPIOE_ODR1:1; // GPIOE pin 1 output data
    uint32_t GPIOE_ODR2:1; // GPIOE pin 2 output data
    uint32_t GPIOE_ODR3:1; // GPIOE pin 3 output data
    uint32_t GPIOE_ODR4:1; // GPIOE pin 4 output data
    uint32_t GPIOE_ODR5:1; // GPIOE pin 5 output data
    uint32_t GPIOE_ODR6:1; // GPIOE pin 6 output data
    uint32_t GPIOE_ODR7:1; // GPIOE pin 7 output data
    uint32_t GPIOE_ODR8:1; // GPIOE pin 8 output data
    uint32_t GPIOE_ODR9:1; // GPIOE pin 9 output data
    uint32_t GPIOE_ODR10:1; // GPIOE pin 10 output data
    uint32_t GPIOE_ODR11:1; // GPIOE pin 11 output data
    uint32_t GPIOE_ODR12:1; // GPIOE pin 12 output data
    uint32_t GPIOE_ODR13:1; // GPIOE pin 13 output data
    uint32_t GPIOE_ODR14:1; // GPIOE pin 14 output data
    uint32_t GPIOE_ODR15:1; // GPIOE pin 15 output data
}GPIOE_ODR_B_t;

typedef union
{
    GPIOE_ODR_B_t B;
    uint32_t U;
}GPIOE_ODR_Reg_t;

extern volatile GPIOE_ODR_Reg_t GPIOE_ODR_Reg;

typedef struct
{
    uint32_t GPIOH_ODR0:1; // GPIOH pin 0 output data
    uint32_t GPIOH_ODR1:1; // GPIOH pin 1 output data
    uint32_t GPIOH_ODR2:1; // GPIOH pin 2 output data
    uint32_t GPIOH_ODR3:1; // GPIOH pin 3 output data
    uint32_t GPIOH_ODR4:1; // GPIOH pin 4 output data
    uint32_t GPIOH_ODR5:1; // GPIOH pin 5 output data
    uint32_t GPIOH_ODR6:1; // GPIOH pin 6 output data
    uint32_t GPIOH_ODR7:1; // GPIOH pin 7 output data
    uint32_t GPIOH_ODR8:1; // GPIOH pin 8 output data
    uint32_t GPIOH_ODR9:1; // GPIOH pin 9 output data
    uint32_t GPIOH_ODR10:1; // GPIOH pin 10 output data
    uint32_t GPIOH_ODR11:1; // GPIOH pin 11 output data
    uint32_t GPIOH_ODR12:1; // GPIOH pin 12 output data
    uint32_t GPIOH_ODR13:1; // GPIOH pin 13 output data
    uint32_t GPIOH_ODR14:1; // GPIOH pin 14 output data
    uint32_t GPIOH_ODR15:1; // GPIOH pin 15 output data
}GPIOH_ODR_B_t;

typedef union
{
    GPIOH_ODR_B_t B;
    uint32_t U;
}GPIOH_ODR_Reg_t;

extern volatile GPIOH_ODR_Reg_t GPIOH_ODR_Reg;

enum {
    GPIOA_BSRR_SET = 0x0, // Set bit in GPIOA_BSRR
    GPIOA_BSRR_RESET = 0x1 // Reset bit in GPIOA_BSRR
};

typedef struct
{
    uint32_t GPIOA_BS0 : 1; // GPIOA pin 0 bit set
    uint32_t GPIOA_BS1 : 1; // GPIOA pin 1
    uint32_t GPIOA_BS2 : 1; // GPIOA pin 2 bit set
    uint32_t GPIOA_BS3 : 1; // GPIOA pin 3
    uint32_t GPIOA_BS4 : 1; // GPIOA pin 4 bit set
    uint32_t GPIOA_BS5 : 1; // GPIOA pin 5
    uint32_t GPIOA_BS6 : 1; // GPIOA pin 6 bit set
    uint32_t GPIOA_BS7 : 1; // GPIOA pin 7
    uint32_t GPIOA_BS8 : 1; // GPIOA pin 8 bit set
    uint32_t GPIOA_BS9 : 1; // GPIOA pin 9
    uint32_t GPIOA_BS10 : 1; // GPIOA pin 10 bit set
    uint32_t GPIOA_BS11 : 1; // GPIOA pin 11
    uint32_t GPIOA_BS12 : 1; // GPIOA pin 12
    uint32_t GPIOA_BS13 : 1; // GPIOA pin 13
    uint32_t GPIOA_BS14 : 1; // GPIOA pin 14
    uint32_t GPIOA_BS15 : 1; // GPIOA pin 15
    uint32_t GPIOA_BR0 : 1; // GPIOB pin 0 bit set
    uint32_t GPIOA_BR1 : 1; // GPIOB pin 1
    uint32_t GPIOA_BR2 : 1; // GPIOB pin 2 bit
    uint32_t GPIOA_BR3 : 1; // GPIOB pin 3
    uint32_t GPIOA_BR4 : 1; // GPIOB pin 4 bit
    uint32_t GPIOA_BR5 : 1; // GPIOB pin 5
    uint32_t GPIOA_BR6 : 1; // GPIOB pin 6 bit
    uint32_t GPIOA_BR7 : 1; // GPIOB pin 7
    uint32_t GPIOA_BR8 : 1; // GPIOB pin 8 bit
    uint32_t GPIOA_BR9 : 1; // GPIOB pin 9
    uint32_t GPIOA_BR10 : 1; // GPIOB pin 10 bit
    uint32_t GPIOA_BR11 : 1; // GPIOB pin 11
    uint32_t GPIOA_BR12 : 1; // GPIOB pin 12
    uint32_t GPIOA_BR13 : 1; // GPIOB pin 13
    uint32_t GPIOA_BR14 : 1; // GPIOB pin 14
    uint32_t GPIOA_BR15 : 1; // GPIOB pin 15
}GPIOA_BSRR_B_t;    

typedef union
{
    GPIOA_BSRR_B_t B;
    uint32_t U;
}GPIOA_BSRR_Reg_t;

extern volatile GPIOA_BSRR_Reg_t GPIOA_BSRR_Reg;

typedef struct
{
    uint32_t GPIOB_BS0 : 1; // GPIOB pin 0 bit set
    uint32_t GPIOB_BS1 : 1; // GPIOB pin 1
    uint32_t GPIOB_BS2 : 1; // GPIOB pin 2 bit set
    uint32_t GPIOB_BS3 : 1; // GPIOB pin 3
    uint32_t GPIOB_BS4 : 1; // GPIOB pin 4 bit set
    uint32_t GPIOB_BS5 : 1; // GPIOB pin 5
    uint32_t GPIOB_BS6 : 1; // GPIOB pin 6 bit set
    uint32_t GPIOB_BS7 : 1; // GPIOB pin 7
    uint32_t GPIOB_BS8 : 1; // GPIOB pin 8 bit set
    uint32_t GPIOB_BS9 : 1; // GPIOB pin 9
    uint32_t GPIOB_BS10 : 1; // GPIOB pin 10 bit set
    uint32_t GPIOB_BS11 : 1; // GPIOB pin 11
    uint32_t GPIOB_BS12 : 1; // GPIOB pin 12
    uint32_t GPIOB_BS13 : 1; // GPIOB pin 13
    uint32_t GPIOB_BS14 : 1; // GPIOB pin 14
    uint32_t GPIOB_BS15 : 1; // GPIOB pin 15
    uint32_t GPIOB_BR0 : 1; // GPIOA pin 0 bit reset
    uint32_t GPIOB_BR1 : 1; // GPIOA pin 1
    uint32_t GPIOB_BR2 : 1; // GPIOA pin 2 bit reset
    uint32_t GPIOB_BR3 : 1; // GPIOA pin 3
    uint32_t GPIOB_BR4 : 1; // GPIOA pin 4 bit reset
    uint32_t GPIOB_BR5 : 1; // GPIOA pin 5
    uint32_t GPIOB_BR6 : 1; // GPIOA pin 6 bit reset
    uint32_t GPIOB_BR7 : 1; // GPIOA pin 7
    uint32_t GPIOB_BR8 : 1; // GPIOA pin 8 bit reset
    uint32_t GPIOB_BR9 : 1; // GPIOA pin 9
    uint32_t GPIOB_BR10 : 1; // GPIOA pin 10 bit
    uint32_t GPIOB_BR11 : 1; // GPIOA pin 11
    uint32_t GPIOB_BR12 : 1; // GPIOA pin 12
    uint32_t GPIOB_BR13 : 1; // GPIOA pin 13
    uint32_t GPIOB_BR14 : 1; // GPIOA pin 14
    uint32_t GPIOB_BR15 : 1; // GPIOA pin 15
}GPIOB_BSRR_B_t;

typedef union
{
    GPIOB_BSRR_B_t B;
    uint32_t U;
}GPIOB_BSRR_Reg_t;

extern volatile GPIOB_BSRR_Reg_t GPIOB_BSRR_Reg;

typedef struct
{
    uint32_t GPIOC_BS0 : 1; // GPIOC pin 0 bit set
    uint32_t GPIOC_BS1 : 1; // GPIOC pin 1
    uint32_t GPIOC_BS2 : 1; // GPIOC pin 2 bit set
    uint32_t GPIOC_BS3 : 1; // GPIOC pin 3
    uint32_t GPIOC_BS4 : 1; // GPIOC pin 4 bit set
    uint32_t GPIOC_BS5 : 1; // GPIOC pin 5
    uint32_t GPIOC_BS6 : 1; // GPIOC pin 6 bit set
    uint32_t GPIOC_BS7 : 1; // GPIOC pin 7
    uint32_t GPIOC_BS8 : 1; // GPIOC pin 8 bit set
    uint32_t GPIOC_BS9 : 1; // GPIOC pin 9
    uint32_t GPIOC_BS10 : 1; // GPIOC pin 10 bit set
    uint32_t GPIOC_BS11 : 1; // GPIOC pin 11
    uint32_t GPIOC_BS12 : 1; // GPIOC pin 12
    uint32_t GPIOC_BS13 : 1; // GPIOC pin 13
    uint32_t GPIOC_BS14 : 1; // GPIOC pin 14
    uint32_t GPIOC_BS15 : 1; // GPIOC pin 15
    uint32_t GPIOC_BR0 : 1; // GPIOD pin 0 bit reset
    uint32_t GPIOC_BR1 : 1; // GPIOD pin 1
    uint32_t GPIOC_BR2 : 1; // GPIOD pin 2 bit reset
    uint32_t GPIOC_BR3 : 1; // GPIOD pin 3
    uint32_t GPIOC_BR4 : 1; // GPIOD pin 4 bit reset
    uint32_t GPIOC_BR5 : 1; // GPIOD pin 5
    uint32_t GPIOC_BR6 : 1; // GPIOD pin 6 bit reset
    uint32_t GPIOC_BR7 : 1; // GPIOD pin 7
    uint32_t GPIOC_BR8 : 1; // GPIOD pin 8 bit reset
    uint32_t GPIOC_BR9 : 1; // GPIOD pin 9
    uint32_t GPIOC_BR10 : 1; // GPIOD pin 10 bit reset
    uint32_t GPIOC_BR11 : 1; // GPIOD pin 11    
    uint32_t GPIOC_BR12 : 1; // GPIOD pin 12 bit reset
    uint32_t GPIOC_BR13 : 1; // GPIOD pin 13
    uint32_t GPIOC_BR14 : 1; // GPIOD pin 14 bit reset
    uint32_t GPIOC_BR15 : 1; // GPIOD pin 15
}GPIOC_BSRR_B_t;

typedef union
{
    GPIOC_BSRR_B_t B;
    uint32_t U;
}GPIOC_BSRR_Reg_t;

extern volatile GPIOC_BSRR_Reg_t GPIOC_BSRR_Reg;

typedef struct
{
    uint32_t GPIOD_BS0 : 1; // GPIOD pin 0 bit set
    uint32_t GPIOD_BS1 : 1; // GPIOD pin 1
    uint32_t GPIOD_BS2 : 1; // GPIOD pin 2 bit set
    uint32_t GPIOD_BS3 : 1; // GPIOD pin 3
    uint32_t GPIOD_BS4 : 1; // GPIOD pin 4 bit set
    uint32_t GPIOD_BS5 : 1; // GPIOD pin 5
    uint32_t GPIOD_BS6 : 1; // GPIOD pin 6 bit set
    uint32_t GPIOD_BS7 : 1; // GPIOD pin 7
    uint32_t GPIOD_BS8 : 1; // GPIOD pin 8 bit set
    uint32_t GPIOD_BS9 : 1; // GPIOD pin 9
    uint32_t GPIOD_BS10 : 1; // GPIOD pin 10 bit set
    uint32_t GPIOD_BS11 : 1; // GPIOD pin 11
    uint32_t GPIOD_BS12 : 1; // GPIOD pin 12 bit set
    uint32_t GPIOD_BS13 : 1; // GPIOD pin 13
    uint32_t GPIOD_BS14 : 1; // GPIOD pin 14
    uint32_t GPIOD_BS15 : 1; // GPIOD pin 15
    uint32_t GPIOD_BR0 : 1; // GPIOE pin 0 bit reset
    uint32_t GPIOD_BR1 : 1; // GPIOE pin 1
    uint32_t GPIOD_BR2 : 1; // GPIOE pin 2 bit reset
    uint32_t GPIOD_BR3 : 1; // GPIOE pin 3
    uint32_t GPIOD_BR4 : 1; // GPIOE pin 4 bit reset
    uint32_t GPIOD_BR5 : 1; // GPIOE pin 5
    uint32_t GPIOD_BR6 : 1; // GPIOE pin 6 bit reset
    uint32_t GPIOD_BR7 : 1; // GPIOE pin 7  
    uint32_t GPIOD_BR8 : 1; // GPIOE pin 8 bit reset
    uint32_t GPIOD_BR9 : 1; // GPIOE pin 9
    uint32_t GPIOD_BR10 : 1; // GPIOE pin 10 bit reset
    uint32_t GPIOD_BR11 : 1; // GPIOE pin 11
    uint32_t GPIOD_BR12 : 1; // GPIOE pin 12 bit reset
    uint32_t GPIOD_BR13 : 1; // GPIOE pin 13
    uint32_t GPIOD_BR14 : 1; // GPIOE pin 14 bit reset
    uint32_t GPIOD_BR15 : 1; // GPIOE pin 15
}GPIOD_BSRR_B_t;

typedef union
{
    GPIOD_BSRR_B_t B;
    uint32_t U;
}GPIOD_BSRR_Reg_t;

extern volatile GPIOD_BSRR_Reg_t GPIOD_BSRR_Reg;

typedef struct
{
    uint32_t GPIOE_BS0 : 1; // GPIOE pin 0 bit set
    uint32_t GPIOE_BS1 : 1; // GPIOE pin 1
    uint32_t GPIOE_BS2 : 1; // GPIOE pin 2 bit set
    uint32_t GPIOE_BS3 : 1; // GPIOE pin 3
    uint32_t GPIOE_BS4 : 1; // GPIOE pin 4 bit set
    uint32_t GPIOE_BS5 : 1; // GPIOE pin 5
    uint32_t GPIOE_BS6 : 1; // GPIOE pin 6 bit set
    uint32_t GPIOE_BS7 : 1; // GPIOE pin 7
    uint32_t GPIOE_BS8 : 1; // GPIOE pin 8 bit set
    uint32_t GPIOE_BS9 : 1; // GPIOE pin 9
    uint32_t GPIOE_BS10 : 1; // GPIOE pin 10 bit set
    uint32_t GPIOE_BS11 : 1; // GPIOE pin 11
    uint32_t GPIOE_BS12 : 1; // GPIOE pin 12 bit set
    uint32_t GPIOE_BS13 : 1; // GPIOE pin 13
    uint32_t GPIOE_BS14 : 1; // GPIOE pin 14
    uint32_t GPIOE_BS15 : 1; // GPIOE pin 15
    uint32_t GPIOE_BR0 : 1; // GPIOH pin 0 bit reset
    uint32_t GPIOE_BR1 : 1; // GPIOH pin 1
    uint32_t GPIOE_BR2 : 1; // GPIOH pin 2 bit reset
    uint32_t GPIOE_BR3 : 1; // GPIOH pin 3
    uint32_t GPIOE_BR4 : 1; // GPIOH pin 4 bit reset
    uint32_t GPIOE_BR5 : 1; // GPIOH pin 5
    uint32_t GPIOE_BR6 : 1; // GPIOH pin 6 bit reset
    uint32_t GPIOE_BR7 : 1; // GPIOH pin 7  
    uint32_t GPIOE_BR8 : 1; // GPIOH pin 8 bit reset
    uint32_t GPIOE_BR9 : 1; // GPIOH pin 9
    uint32_t GPIOE_BR10 : 1; // GPIOH pin 10 bit reset
    uint32_t GPIOE_BR11 : 1; // GPIOH pin 11
    uint32_t GPIOE_BR12 : 1; // GPIOH pin 12 bit reset
    uint32_t GPIOE_BR13 : 1; // GPIOH pin 13
    uint32_t GPIOE_BR14 : 1; // GPIOH pin 14 bit reset
    uint32_t GPIOE_BR15 : 1; // GPIOH pin 15
}GPIOE_BSRR_B_t;

typedef union
{
    GPIOE_BSRR_B_t B;
    uint32_t U;
}GPIOE_BSRR_Reg_t;

extern volatile GPIOE_BSRR_Reg_t GPIOE_BSRR_Reg;

typedef struct
{
    uint32_t GPIOH_BS0 : 1; // GPIOH pin 0 bit set
    uint32_t GPIOH_BS1 : 1; // GPIOH pin 1
    uint32_t GPIOH_BS2 : 1; // GPIOH pin 2 bit set
    uint32_t GPIOH_BS3 : 1; // GPIOH pin 3
    uint32_t GPIOH_BS4 : 1; // GPIOH pin 4 bit set
    uint32_t GPIOH_BS5 : 1; // GPIOH pin 5
    uint32_t GPIOH_BS6 : 1; // GPIOH pin 6 bit set
    uint32_t GPIOH_BS7 : 1; // GPIOH pin 7
    uint32_t GPIOH_BS8 : 1; // GPIOH pin 8 bit set
    uint32_t GPIOH_BS9 : 1; // GPIOH pin 9
    uint32_t GPIOH_BS10 : 1; // GPIOH pin 10 bit set
    uint32_t GPIOH_BS11 : 1; // GPIOH pin 11
    uint32_t GPIOH_BS12 : 1; // GPIOH pin 12 bit set
    uint32_t GPIOH_BS13 : 1; // GPIOH pin 13
    uint32_t GPIOH_BS14 : 1; // GPIOH pin 14
    uint32_t GPIOH_BS15 : 1; // GPIOH pin 15
    uint32_t GPIOH_BR0 : 1; // not used, reserved for future use    
    uint32_t GPIOH_BR1 : 1; // not used, reserved for future use
    uint32_t GPIOH_BR2 : 1; // not used, reserved for future
    uint32_t GPIOH_BR3 : 1; // not used, reserved for future use
    uint32_t GPIOH_BR4 : 1; // not used, reserved for future
    uint32_t GPIOH_BR5 : 1; // not used, reserved for future use
    uint32_t GPIOH_BR6 : 1; // not used, reserved for future use
    uint32_t GPIOH_BR7 : 1; // not used, reserved for future
    uint32_t GPIOH_BR8 : 1; // not used, reserved for future use
    uint32_t GPIOH_BR9 : 1; // not used, reserved for future
    uint32_t GPIOH_BR10 : 1; // not used, reserved for future use
    uint32_t GPIOH_BR11 : 1; // not used, reserved for future
    uint32_t GPIOH_BR12 : 1; // not used, reserved for future use
    uint32_t GPIOH_BR13 : 1; // not used, reserved for future
    uint32_t GPIOH_BR14 : 1; // not used, reserved for future
    uint32_t GPIOH_BR15 : 1; // not used, reserved for future
}GPIOH_BSRR_B_t;

typedef union
{
    GPIOH_BSRR_B_t B;
    uint32_t U;
}GPIOH_BSRR_Reg_t;

extern volatile GPIOH_BSRR_Reg_t GPIOH_BSRR_Reg;

enum {
    LOCK = 0x1, // Lock bit
    UNLOCK = 0x0 // Unlock bit
};
typedef struct
{
    uint32_t GPIOA_LCK0:1; // GPIOA pin 0 lock bit
    uint32_t GPIOA_LCK1:1; // GPIOA pin 1 lock bit
    uint32_t GPIOA_LCK2:1; // GPIOA pin 2 lock bit
    uint32_t GPIOA_LCK3:1; // GPIOA pin 3 lock bit
    uint32_t GPIOA_LCK4:1; // GPIOA pin 4 lock bit
    uint32_t GPIOA_LCK5:1; // GPIOA pin 5 lock bit
    uint32_t GPIOA_LCK6:1; // GPIOA pin 6 lock bit
    uint32_t GPIOA_LCK7:1; // GPIOA pin 7 lock bit
    uint32_t GPIOA_LCK8:1; // GPIOA pin 8 lock bit
    uint32_t GPIOA_LCK9:1; // GPIOA pin 9 lock bit
    uint32_t GPIOA_LCK10:1; // GPIOA pin 10 lock bit
    uint32_t GPIOA_LCK11:1; // GPIOA pin 11 lock bit
    uint32_t GPIOA_LCK12:1; // GPIOA pin 12 lock bit
    uint32_t GPIOA_LCK13:1; // GPIOA pin 13 lock bit
    uint32_t GPIOA_LCK14:1; // GPIOA pin 14 lock bit
    uint32_t GPIOA_LCK15:1; // GPIOA pin 15 lock bit
    uint32_t GPIOA_LCKK:1; // GPIOA lock key
}GPIOA_LCKR_B_t;

typedef union
{
    GPIOA_LCKR_B_t B;
    uint32_t U;
}GPIOA_LCKR_Reg_t;

extern volatile GPIOA_LCKR_Reg_t GPIOA_LCKR_Reg;

typedef struct
{
    uint32_t GPIOB_LCK0:1; // GPIOB pin 0 lock bit
    uint32_t GPIOB_LCK1:1; // GPIOB pin 1 lock bit
    uint32_t GPIOB_LCK2:1; // GPIOB pin 2 lock bit
    uint32_t GPIOB_LCK3:1; // GPIOB pin 3 lock bit
    uint32_t GPIOB_LCK4:1; // GPIOB pin 4 lock bit
    uint32_t GPIOB_LCK5:1; // GPIOB pin 5 lock bit
    uint32_t GPIOB_LCK6:1; // GPIOB pin 6 lock bit
    uint32_t GPIOB_LCK7:1; // GPIOB pin 7 lock bit
    uint32_t GPIOB_LCK8:1; // GPIOB pin 8 lock bit
    uint32_t GPIOB_LCK9:1; // GPIOB pin 9 lock bit
    uint32_t GPIOB_LCK10:1; // GPIOB pin 10 lock bit
    uint32_t GPIOB_LCK11:1; // GPIOB pin 11 lock bit
    uint32_t GPIOB_LCK12:1; // GPIOB pin 12 lock bit
    uint32_t GPIOB_LCK13:1; // GPIOB pin 13 lock bit
    uint32_t GPIOB_LCK14:1; // GPIOB pin 14 lock bit
    uint32_t GPIOB_LCK15:1; // GPIOB pin 15 lock bit
    uint32_t GPIOB_LCKK:1; // GPIOB lock key
}GPIOB_LCKR_B_t;

typedef union
{
    GPIOB_LCKR_B_t B;
    uint32_t U;
}GPIOB_LCKR_Reg_t;

extern volatile GPIOB_LCKR_Reg_t GPIOB_LCKR_Reg;

typedef struct
{
    uint32_t GPIOC_LCK0:1; // GPIOC pin 0 lock bit
    uint32_t GPIOC_LCK1:1; // GPIOC pin 1 lock bit
    uint32_t GPIOC_LCK2:1; // GPIOC pin 2 lock bit
    uint32_t GPIOC_LCK3:1; // GPIOC pin 3 lock bit
    uint32_t GPIOC_LCK4:1; // GPIOC pin 4 lock bit
    uint32_t GPIOC_LCK5:1; // GPIOC pin 5 lock bit
    uint32_t GPIOC_LCK6:1; // GPIOC pin 6 lock bit
    uint32_t GPIOC_LCK7:1; // GPIOC pin 7 lock bit
    uint32_t GPIOC_LCK8:1; // GPIOC pin 8 lock bit
    uint32_t GPIOC_LCK9:1; // GPIOC pin 9 lock bit
    uint32_t GPIOC_LCK10:1; // GPIOC pin 10 lock bit
    uint32_t GPIOC_LCK11:1; // GPIOC pin 11 lock bit
    uint32_t GPIOC_LCK12:1; // GPIOC pin 12 lock bit
    uint32_t GPIOC_LCK13:1; // GPIOC pin 13 lock bit
    uint32_t GPIOC_LCK14:1; // GPIOC pin 14 lock bit
    uint32_t GPIOC_LCK15:1; // GPIOC pin 15 lock bit
    uint32_t GPIOC_LCKK:1; // GPIOC lock key
}GPIOC_LCKR_B_t;

typedef union
{
    GPIOC_LCKR_B_t B;
    uint32_t U;
}GPIOC_LCKR_Reg_t;

extern volatile GPIOC_LCKR_Reg_t GPIOC_LCKR_Reg;

typedef struct
{
    uint32_t GPIOD_LCK0:1; // GPIOD pin 0 lock bit
    uint32_t GPIOD_LCK1:1; // GPIOD pin 1 lock bit
    uint32_t GPIOD_LCK2:1; // GPIOD pin 2 lock bit
    uint32_t GPIOD_LCK3:1; // GPIOD pin 3 lock bit
    uint32_t GPIOD_LCK4:1; // GPIOD pin 4 lock bit
    uint32_t GPIOD_LCK5:1; // GPIOD pin 5 lock bit
    uint32_t GPIOD_LCK6:1; // GPIOD pin 6 lock bit
    uint32_t GPIOD_LCK7:1; // GPIOD pin 7 lock bit
    uint32_t GPIOD_LCK8:1; // GPIOD pin 8 lock bit
    uint32_t GPIOD_LCK9:1; // GPIOD pin 9 lock bit
    uint32_t GPIOD_LCK10:1; // GPIOD pin 10 lock bit
    uint32_t GPIOD_LCK11:1; // GPIOD pin 11 lock bit
    uint32_t GPIOD_LCK12:1; // GPIOD pin 12 lock bit
    uint32_t GPIOD_LCK13:1; // GPIOD pin 13 lock bit
    uint32_t GPIOD_LCK14:1; // GPIOD pin 14 lock bit
    uint32_t GPIOD_LCK15:1; // GPIOD pin 15 lock bit
    uint32_t GPIOD_LCKK:1; // GPIOD lock key
}GPIOD_LCKR_B_t;

typedef union
{
    GPIOD_LCKR_B_t B;
    uint32_t U;
}GPIOD_LCKR_Reg_t;

extern volatile GPIOD_LCKR_Reg_t GPIOD_LCKR_Reg;

typedef struct
{
    uint32_t GPIOE_LCK0:1; // GPIOE pin 0 lock bit
    uint32_t GPIOE_LCK1:1; // GPIOE pin 1 lock bit
    uint32_t GPIOE_LCK2:1; // GPIOE pin 2 lock bit
    uint32_t GPIOE_LCK3:1; // GPIOE pin 3 lock bit
    uint32_t GPIOE_LCK4:1; // GPIOE pin 4 lock bit
    uint32_t GPIOE_LCK5:1; // GPIOE pin 5 lock bit
    uint32_t GPIOE_LCK6:1; // GPIOE pin 6 lock bit
    uint32_t GPIOE_LCK7:1; // GPIOE pin 7 lock bit
    uint32_t GPIOE_LCK8:1; // GPIOE pin 8 lock bit
    uint32_t GPIOE_LCK9:1; // GPIOE pin 9 lock bit
    uint32_t GPIOE_LCK10:1; // GPIOE pin 10 lock bit
    uint32_t GPIOE_LCK11:1; // GPIOE pin 11 lock bit
    uint32_t GPIOE_LCK12:1; // GPIOE pin 12 lock bit
    uint32_t GPIOE_LCK13:1; // GPIOE pin 13 lock bit
    uint32_t GPIOE_LCK14:1; // GPIOE pin 14 lock bit
    uint32_t GPIOE_LCK15:1; // GPIOE pin 15 lock bit
    uint32_t GPIOE_LCKK:1; // GPIOE lock key    
}GPIOE_LCKR_B_t;

typedef union
{
    GPIOE_LCKR_B_t B;
    uint32_t U;
}GPIOE_LCKR_Reg_t;

extern volatile GPIOE_LCKR_Reg_t GPIOE_LCKR_Reg;

typedef struct
{
    uint32_t GPIOH_LCK0:1; // GPIOH pin 0 lock bit
    uint32_t GPIOH_LCK1:1; // GPIOH pin 1 lock bit
    uint32_t GPIOH_LCK2:1; // GPIOH pin 2 lock bit
    uint32_t GPIOH_LCK3:1; // GPIOH pin 3 lock bit
    uint32_t GPIOH_LCK4:1; // GPIOH pin 4 lock bit
    uint32_t GPIOH_LCK5:1; // GPIOH pin 5 lock bit
    uint32_t GPIOH_LCK6:1; // GPIOH pin 6 lock bit
    uint32_t GPIOH_LCK7:1; // GPIOH pin 7 lock bit
    uint32_t GPIOH_LCK8:1; // GPIOH pin 8 lock bit
    uint32_t GPIOH_LCK9:1; // GPIOH pin 9 lock bit
    uint32_t GPIOH_LCK10:1; // GPIOH pin 10 lock bit
    uint32_t GPIOH_LCK11:1; // GPIOH pin 11 lock bit
    uint32_t GPIOH_LCK12:1; // GPIOH pin 12 lock bit
    uint32_t GPIOH_LCK13:1; // GPIOH pin 13 lock bit
    uint32_t GPIOH_LCK14:1; // GPIOH pin 14 lock bit
    uint32_t GPIOH_LCK15:1; // GPIOH pin 15 lock bit
    uint32_t GPIOH_LCKK:1; // GPIOH lock key
}GPIOH_LCKR_B_t;

typedef union
{
    GPIOH_LCKR_B_t B;
    uint32_t U;
}GPIOH_LCKR_Reg_t;

extern volatile GPIOH_LCKR_Reg_t GPIOH_LCKR_Reg;

enum {
    GPIOx_AFRL0 = 0x0, // GPIOA pin 0 alternate function low
    GPIOx_AFRL1 = 0x1, // GPIOA pin 1 alternate function low
    GPIOx_AFRL2 = 0x2, // GPIOA pin 2 alternate function low
    GPIOx_AFRL3 = 0x3, // GPIOA pin 3 alternate function low
    GPIOx_AFRL4 = 0x4, // GPIOA pin 4 alternate function low
    GPIOx_AFRL5 = 0x5, // GPIOA pin 5 alternate function low
    GPIOx_AFRL6 = 0x6, // GPIOA pin 6 alternate function low
    GPIOx_AFRL7 = 0x7, // GPIOA pin 7 alternate function low
};

typedef struct
{
    uint32_t GPIOA_AFRL0:4; // GPIOA pin 0 alternate function low
    uint32_t GPIOA_AFRL1:4; // GPIOA pin 1 alternate function low
    uint32_t GPIOA_AFRL2:4; // GPIOA pin 2 alternate function low
    uint32_t GPIOA_AFRL3:4; // GPIOA pin 3 alternate function low
    uint32_t GPIOA_AFRL4:4; // GPIOA pin 4 alternate function low
    uint32_t GPIOA_AFRL5:4; // GPIOA pin 5 alternate function low
    uint32_t GPIOA_AFRL6:4; // GPIOA pin 6 alternate function low
    uint32_t GPIOA_AFRL7:4; // GPIOA pin 7 alternate function low
}GPIOA_AFRL_B_t;

typedef union
{
    GPIOA_AFRL_B_t B;
    uint32_t U;
}GPIOA_AFRL_Reg_t;

extern volatile GPIOA_AFRL_Reg_t GPIOA_AFRL_Reg;

typedef struct
{
    uint32_t GPIOB_AFRL0:4; // GPIOB pin 0 alternate function low
    uint32_t GPIOB_AFRL1:4; // GPIOB pin 1 alternate function low
    uint32_t GPIOB_AFRL2:4; // GPIOB pin 2 alternate function low
    uint32_t GPIOB_AFRL3:4; // GPIOB pin 3 alternate function low
    uint32_t GPIOB_AFRL4:4; // GPIOB pin 4 alternate function low
    uint32_t GPIOB_AFRL5:4; // GPIOB pin 5 alternate function low
    uint32_t GPIOB_AFRL6:4; // GPIOB pin 6 alternate function low
    uint32_t GPIOB_AFRL7:4; // GPIOB pin 7 alternate function low
}GPIOB_AFRL_B_t;

typedef union
{
    GPIOB_AFRL_B_t B;
    uint32_t U;
}GPIOB_AFRL_Reg_t;

extern volatile GPIOB_AFRL_Reg_t GPIOB_AFRL_Reg;

typedef struct
{
    uint32_t GPIOC_AFRL0:4; // GPIOC pin 0 alternate function low
    uint32_t GPIOC_AFRL1:4; // GPIOC pin 1 alternate function low
    uint32_t GPIOC_AFRL2:4; // GPIOC pin 2 alternate function low
    uint32_t GPIOC_AFRL3:4; // GPIOC pin 3 alternate function low
    uint32_t GPIOC_AFRL4:4; // GPIOC pin 4 alternate function low
    uint32_t GPIOC_AFRL5:4; // GPIOC pin 5 alternate function low
    uint32_t GPIOC_AFRL6:4; // GPIOC pin 6 alternate function low
    uint32_t GPIOC_AFRL7:4; // GPIOC pin 7 alternate function low
}GPIOC_AFRL_B_t;

typedef union
{
    GPIOC_AFRL_B_t B;
    uint32_t U;
}GPIOC_AFRL_Reg_t;

extern volatile GPIOC_AFRL_Reg_t GPIOC_AFRL_Reg;

typedef struct
{
    uint32_t GPIOD_AFRL0:4; // GPIOD pin 0 alternate function low
    uint32_t GPIOD_AFRL1:4; // GPIOD pin 1 alternate function low
    uint32_t GPIOD_AFRL2:4; // GPIOD pin 2 alternate function low
    uint32_t GPIOD_AFRL3:4; // GPIOD pin 3 alternate function low
    uint32_t GPIOD_AFRL4:4; // GPIOD pin 4 alternate function low
    uint32_t GPIOD_AFRL5:4; // GPIOD pin 5 alternate function low
    uint32_t GPIOD_AFRL6:4; // GPIOD pin 6 alternate function low
    uint32_t GPIOD_AFRL7:4; // GPIOD pin 7 alternate function low
}GPIOD_AFRL_B_t;

typedef union
{
    GPIOD_AFRL_B_t B;
    uint32_t U;
}GPIOD_AFRL_Reg_t;

extern volatile GPIOD_AFRL_Reg_t GPIOD_AFRL_Reg;

typedef struct
{
    uint32_t GPIOE_AFRL0:4; // GPIOE pin 0 alternate function low
    uint32_t GPIOE_AFRL1:4; // GPIOE pin 1 alternate function low
    uint32_t GPIOE_AFRL2:4; // GPIOE pin 2 alternate function low
    uint32_t GPIOE_AFRL3:4; // GPIOE pin 3 alternate function low
    uint32_t GPIOE_AFRL4:4; // GPIOE pin 4 alternate function low
    uint32_t GPIOE_AFRL5:4; // GPIOE pin 5 alternate function low
    uint32_t GPIOE_AFRL6:4; // GPIOE pin 6 alternate function low
    uint32_t GPIOE_AFRL7:4; // GPIOE pin 7 alternate function low
}GPIOE_AFRL_B_t;    

typedef union
{
    GPIOE_AFRL_B_t B;
    uint32_t U;
}GPIOE_AFRL_Reg_t;

extern volatile GPIOE_AFRL_Reg_t GPIOE_AFRL_Reg;

typedef struct
{
    uint32_t GPIOH_AFRL0:4; // GPIOH pin 0 alternate function low
    uint32_t GPIOH_AFRL1:4; // GPIOH pin 1 alternate function low
    uint32_t GPIOH_AFRL2:4; // GPIOH pin 2 alternate function low
    uint32_t GPIOH_AFRL3:4; // GPIOH pin 3 alternate function low
    uint32_t GPIOH_AFRL4:4; // GPIOH pin 4 alternate function low
    uint32_t GPIOH_AFRL5:4; // GPIOH pin 5 alternate function low
    uint32_t GPIOH_AFRL6:4; // GPIOH pin 6 alternate function low
    uint32_t GPIOH_AFRL7:4; // GPIOH pin 7 alternate function low
}GPIOH_AFRL_B_t;

typedef union
{
    GPIOH_AFRL_B_t B;
    uint32_t U;
}GPIOH_AFRL_Reg_t;

extern volatile GPIOH_AFRL_Reg_t GPIOH_AFRL_Reg;

enum {
    GPIOx_AFRH0 = 0x0, // GPIOA pin 8 alternate function high
    GPIOx_AFRH1 = 0x1, // GPIOA pin 9 alternate function high
    GPIOx_AFRH2 = 0x2, // GPIOA pin 10 alternate function high
    GPIOx_AFRH3 = 0x3, // GPIOA pin 11 alternate function high
    GPIOx_AFRH4 = 0x4, // GPIOA pin 12 alternate function high
    GPIOx_AFRH5 = 0x5, // GPIOA pin 13 alternate function high
    GPIOx_AFRH6 = 0x6, // GPIOA pin 14 alternate function high
    GPIOx_AFRH7 = 0x7, // GPIOA pin 15 alternate function high
};

typedef struct
{
    uint32_t GPIOA_AFRH0:4; // GPIOA pin 8 alternate function high
    uint32_t GPIOA_AFRH1:4; // GPIOA pin 9 alternate function high
    uint32_t GPIOA_AFRH2:4; // GPIOA pin 10 alternate function high
    uint32_t GPIOA_AFRH3:4; // GPIOA pin 11 alternate function high
    uint32_t GPIOA_AFRH4:4; // GPIOA pin 12 alternate function high
    uint32_t GPIOA_AFRH5:4; // GPIOA pin 13 alternate function high
    uint32_t GPIOA_AFRH6:4; // GPIOA pin 14 alternate function high
    uint32_t GPIOA_AFRH7:4; // GPIOA pin 15 alternate function high
}GPIOA_AFRH_B_t;

typedef union
{
    GPIOA_AFRH_B_t B;
    uint32_t U;
}GPIOA_AFRH_Reg_t;

extern volatile GPIOA_AFRH_Reg_t GPIOA_AFRH_Reg;

typedef struct
{
    uint32_t GPIOB_AFRH0:4; // GPIOB pin 8 alternate function high
    uint32_t GPIOB_AFRH1:4; // GPIOB pin 9 alternate function high
    uint32_t GPIOB_AFRH2:4; // GPIOB pin 10 alternate function high
    uint32_t GPIOB_AFRH3:4; // GPIOB pin 11 alternate function high
    uint32_t GPIOB_AFRH4:4; // GPIOB pin 12 alternate function high
    uint32_t GPIOB_AFRH5:4; // GPIOB pin 13 alternate function high
    uint32_t GPIOB_AFRH6:4; // GPIOB pin 14 alternate function high
    uint32_t GPIOB_AFRH7:4; // GPIOB pin 15 alternate function high
}GPIOB_AFRH_B_t;    

typedef union
{
    GPIOB_AFRH_B_t B;
    uint32_t U;
}GPIOB_AFRH_Reg_t;

extern volatile GPIOB_AFRH_Reg_t GPIOB_AFRH_Reg;

typedef struct
{
    uint32_t GPIOC_AFRH0:4; // GPIOC pin 8 alternate function high
    uint32_t GPIOC_AFRH1:4; // GPIOC pin 9 alternate function high
    uint32_t GPIOC_AFRH2:4; // GPIOC pin 10 alternate function high
    uint32_t GPIOC_AFRH3:4; // GPIOC pin 11 alternate function high
    uint32_t GPIOC_AFRH4:4; // GPIOC pin 12 alternate function high
    uint32_t GPIOC_AFRH5:4; // GPIOC pin 13 alternate function high
    uint32_t GPIOC_AFRH6:4; // GPIOC pin 14 alternate function high
    uint32_t GPIOC_AFRH7:4; // GPIOC pin 15 alternate function high
}GPIOC_AFRH_B_t;

typedef union
{
    GPIOC_AFRH_B_t B;
    uint32_t U;
}GPIOC_AFRH_Reg_t;

extern volatile GPIOC_AFRH_Reg_t GPIOC_AFRH_Reg;

typedef struct
{
    uint32_t GPIOD_AFRH0:4; // GPIOD pin 8 alternate function high
    uint32_t GPIOD_AFRH1:4; // GPIOD pin 9 alternate function high
    uint32_t GPIOD_AFRH2:4; // GPIOD pin 10 alternate function high
    uint32_t GPIOD_AFRH3:4; // GPIOD pin 11 alternate function high
    uint32_t GPIOD_AFRH4:4; // GPIOD pin 12 alternate function high
    uint32_t GPIOD_AFRH5:4; // GPIOD pin 13 alternate function high
    uint32_t GPIOD_AFRH6:4; // GPIOD pin 14 alternate function high
    uint32_t GPIOD_AFRH7:4; // GPIOD pin 15 alternate function high
}GPIOD_AFRH_B_t;

typedef union
{
    GPIOD_AFRH_B_t B;
    uint32_t U;
}GPIOD_AFRH_Reg_t;

extern volatile GPIOD_AFRH_Reg_t GPIOD_AFRH_Reg;

typedef struct
{
    uint32_t GPIOE_AFRH0:4; // GPIOE pin 8 alternate function high
    uint32_t GPIOE_AFRH1:4; // GPIOE pin 9 alternate function high
    uint32_t GPIOE_AFRH2:4; // GPIOE pin 10 alternate function high
    uint32_t GPIOE_AFRH3:4; // GPIOE pin 11 alternate function high
    uint32_t GPIOE_AFRH4:4; // GPIOE pin 12 alternate function high
    uint32_t GPIOE_AFRH5:4; // GPIOE pin 13 alternate function high
    uint32_t GPIOE_AFRH6:4; // GPIOE pin 14 alternate function high
    uint32_t GPIOE_AFRH7:4; // GPIOE pin 15 alternate function high
}GPIOE_AFRH_B_t;

typedef union
{
    GPIOE_AFRH_B_t B;
    uint32_t U;
}GPIOE_AFRH_Reg_t;

extern volatile GPIOE_AFRH_Reg_t GPIOE_AFRH_Reg;

typedef struct
{
    uint32_t GPIOH_AFRH0:4; // GPIOH pin 8 alternate function high
    uint32_t GPIOH_AFRH1:4; // GPIOH pin 9 alternate function high
    uint32_t GPIOH_AFRH2:4; // GPIOH pin 10 alternate function high
    uint32_t GPIOH_AFRH3:4; // GPIOH pin 11 alternate function high
    uint32_t GPIOH_AFRH4:4; // GPIOH pin 12 alternate function high
    uint32_t GPIOH_AFRH5:4; // GPIOH pin 13 alternate function high
    uint32_t GPIOH_AFRH6:4; // GPIOH pin 14 alternate function high
    uint32_t GPIOH_AFRH7:4; // GPIOH pin 15 alternate function high
}GPIOH_AFRH_B_t;

typedef union
{
    GPIOH_AFRH_B_t B;
    uint32_t U;
}GPIOH_AFRH_Reg_t;

extern volatile GPIOH_AFRH_Reg_t GPIOH_AFRH_Reg;

typedef struct
{
    uint32_t GPIOA_BRR0:1; // GPIOA pin 0 bit reset
    uint32_t GPIOA_BRR1:1; // GPIOA pin 1
    uint32_t GPIOA_BRR2:1; // GPIOA pin 2 bit reset
    uint32_t GPIOA_BRR3:1; // GPIOA pin 3
    uint32_t GPIOA_BRR4:1; // GPIOA pin 4 bit reset
    uint32_t GPIOA_BRR5:1; // GPIOA pin 5
    uint32_t GPIOA_BRR6:1; // GPIOA pin 6 bit reset
    uint32_t GPIOA_BRR7:1; // GPIOA pin 7  
    uint32_t GPIOA_BRR8:1; // GPIOA pin 8 bit reset
    uint32_t GPIOA_BRR9:1; // GPIOA pin 9
    uint32_t GPIOA_BRR10:1; // GPIOA pin 10 bit reset
    uint32_t GPIOA_BRR11:1; // GPIOA pin 11
    uint32_t GPIOA_BRR12:1; // GPIOA pin 12 bit reset
    uint32_t GPIOA_BRR13:1; // GPIOA pin 13
    uint32_t GPIOA_BRR14:1; // GPIOA pin 14 bit reset
    uint32_t GPIOA_BRR15:1; // GPIOA pin 15 bit reset
}GPIOA_BRR_B_t;

typedef union
{
    GPIOA_BRR_B_t B;
    uint32_t U;
}GPIOA_BRR_Reg_t;

extern volatile GPIOA_BRR_Reg_t GPIOA_BRR_Reg;

typedef struct
{
    uint32_t GPIOB_BRR0:1; // GPIOB pin 0 bit reset
    uint32_t GPIOB_BRR1:1; // GPIOB pin 1
    uint32_t GPIOB_BRR2:1; // GPIOB pin 2 bit reset
    uint32_t GPIOB_BRR3:1; // GPIOB pin 3
    uint32_t GPIOB_BRR4:1; // GPIOB pin 4 bit reset
    uint32_t GPIOB_BRR5:1; // GPIOB pin 5
    uint32_t GPIOB_BRR6:1; // GPIOB pin 6 bit reset
    uint32_t GPIOB_BRR7:1; // GPIOB pin 7  
    uint32_t GPIOB_BRR8:1; // GPIOB pin 8 bit reset
    uint32_t GPIOB_BRR9:1; // GPIOB pin 9
    uint32_t GPIOB_BRR10:1; // GPIOB pin 10 bit reset
    uint32_t GPIOB_BRR11:1; // GPIOB pin 11
    uint32_t GPIOB_BRR12:1; // GPIOB pin 12 bit reset
    uint32_t GPIOB_BRR13:1; // GPIOB pin 13
    uint32_t GPIOB_BRR14:1; // GPIOB pin 14 bit reset
    uint32_t GPIOB_BRR15:1; // GPIOB pin 15 bit reset
}GPIOB_BRR_B_t;

typedef union
{
    GPIOB_BRR_B_t B;
    uint32_t U;
}GPIOB_BRR_Reg_t;

extern volatile GPIOB_BRR_Reg_t GPIOB_BRR_Reg;

typedef struct
{
    uint32_t GPIOC_BRR0:1; // GPIOC pin 0 bit reset
    uint32_t GPIOC_BRR1:1; // GPIOC pin 1
    uint32_t GPIOC_BRR2:1; // GPIOC pin 2 bit reset
    uint32_t GPIOC_BRR3:1; // GPIOC pin 3
    uint32_t GPIOC_BRR4:1; // GPIOC pin 4 bit reset
    uint32_t GPIOC_BRR5:1; // GPIOC pin 5
    uint32_t GPIOC_BRR6:1; // GPIOC pin 6 bit reset
    uint32_t GPIOC_BRR7:1; // GPIOC pin 7  
    uint32_t GPIOC_BRR8:1; // GPIOC pin 8 bit reset
    uint32_t GPIOC_BRR9:1; // GPIOC pin 9
    uint32_t GPIOC_BRR10:1; // GPIOC pin 10 bit reset
    uint32_t GPIOC_BRR11:1; // GPIOC pin 11
    uint32_t GPIOC_BRR12:1; // GPIOC pin 12 bit reset
    uint32_t GPIOC_BRR13:1; // GPIOC pin 13
    uint32_t GPIOC_BRR14:1; // GPIOC pin 14 bit reset
    uint32_t GPIOC_BRR15:1; // GPIOC pin 15 bit reset
}GPIOC_BRR_B_t;

typedef union
{
    GPIOC_BRR_B_t B;
    uint32_t U;
}GPIOC_BRR_Reg_t;

extern volatile GPIOC_BRR_Reg_t GPIOC_BRR_Reg;

typedef struct
{
    uint32_t GPIOD_BRR0:1; // GPIOD pin 0 bit reset
    uint32_t GPIOD_BRR1:1; // GPIOD pin 1
    uint32_t GPIOD_BRR2:1; // GPIOD pin 2 bit reset
    uint32_t GPIOD_BRR3:1; // GPIOD pin 3
    uint32_t GPIOD_BRR4:1; // GPIOD pin 4 bit reset
    uint32_t GPIOD_BRR5:1; // GPIOD pin 5
    uint32_t GPIOD_BRR6:1; // GPIOD pin 6 bit reset
    uint32_t GPIOD_BRR7:1; // GPIOD pin 7  
    uint32_t GPIOD_BRR8:1; // GPIOD pin 8 bit reset
    uint32_t GPIOD_BRR9:1; // GPIOD pin 9
    uint32_t GPIOD_BRR10:1; // GPIOD pin 10 bit reset
    uint32_t GPIOD_BRR11:1; // GPIOD pin 11
    uint32_t GPIOD_BRR12:1; // GPIOD pin 12 bit reset
    uint32_t GPIOD_BRR13:1; // GPIOD pin 13
    uint32_t GPIOD_BRR14:1; // GPIOD pin 14 bit reset
    uint32_t GPIOD_BRR15:1; // GPIOD pin 15 bit reset
}GPIOD_BRR_B_t;

typedef union
{
    GPIOD_BRR_B_t B;
    uint32_t U;
}GPIOD_BRR_Reg_t;

extern volatile GPIOD_BRR_Reg_t GPIOD_BRR_Reg;

typedef struct
{
    uint32_t GPIOE_BRR0:1; // GPIOE pin 0 bit reset
    uint32_t GPIOE_BRR1:1; // GPIOE pin 1
    uint32_t GPIOE_BRR2:1; // GPIOE pin 2 bit reset
    uint32_t GPIOE_BRR3:1; // GPIOE pin 3
    uint32_t GPIOE_BRR4:1; // GPIOE pin 4 bit reset
    uint32_t GPIOE_BRR5:1; // GPIOE pin 5
    uint32_t GPIOE_BRR6:1; // GPIOE pin 6 bit reset
    uint32_t GPIOE_BRR7:1; // GPIOE pin 7  
    uint32_t GPIOE_BRR8:1; // GPIOE pin 8 bit reset
    uint32_t GPIOE_BRR9:1; // GPIOE pin 9
    uint32_t GPIOE_BRR10:1; // GPIOE pin 10 bit reset
    uint32_t GPIOE_BRR11:1; // GPIOE pin 11
    uint32_t GPIOE_BRR12:1; // GPIOE pin 12 bit reset
    uint32_t GPIOE_BRR13:1; // GPIOE pin 13
    uint32_t GPIOE_BRR14:1; // GPIOE pin 14 bit reset
    uint32_t GPIOE_BRR15:1; // GPIOE pin 15 bit reset
}GPIOE_BRR_B_t;

typedef union
{
    GPIOE_BRR_B_t B;
    uint32_t U;
}GPIOE_BRR_Reg_t;

extern volatile GPIOE_BRR_Reg_t GPIOE_BRR_Reg;

typedef struct
{
    uint32_t GPIOH_BRR0:1; // GPIOH pin 0 bit reset
    uint32_t GPIOH_BRR1:1; // GPIOH pin 1
    uint32_t GPIOH_BRR2:1; // GPIOH pin 2 bit reset
    uint32_t GPIOH_BRR3:1; // GPIOH pin 3
    uint32_t GPIOH_BRR4:1; // GPIOH pin 4 bit reset
    uint32_t GPIOH_BRR5:1; // GPIOH pin 5
    uint32_t GPIOH_BRR6:1; // GPIOH pin 6 bit reset
    uint32_t GPIOH_BRR7:1; // GPIOH pin 7  
    uint32_t GPIOH_BRR8:1; // GPIOH pin 8 bit reset
    uint32_t GPIOH_BRR9:1; // GPIOH pin 9
    uint32_t GPIOH_BRR10:1; // GPIOH pin 10 bit reset
    uint32_t GPIOH_BRR11:1; // GPIOH pin 11
    uint32_t GPIOH_BRR12:1; // GPIOH pin 12 bit reset
    uint32_t GPIOH_BRR13:1; // GPIOH pin 13
    uint32_t GPIOH_BRR14:1; // GPIOH pin 14 bit reset
    uint32_t GPIOH_BRR15:1; // GPIOH pin 15 bit reset
}GPIOH_BRR_B_t;

typedef union
{
    GPIOH_BRR_B_t B;
    uint32_t U;
}GPIOH_BRR_Reg_t;

extern volatile GPIOH_BRR_Reg_t GPIOH_BRR_Reg;





#endif // STM32L433_LL_GPIO_CFG_H