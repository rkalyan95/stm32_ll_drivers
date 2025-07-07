#include "stm32l433_ll_gpio_cfg.h"

//Warning : DO not change the Pa13 and Pa14 configs please , because they are used for debugger.

const portpintconfigs_t led_pin = {
    .port = GPIO_PORT_B,
    .pin = GPIO_PIN_13,
    .pinType = GPIO_OUTPUT,
    .pullconfig = GPIO_PULL_DOWN,
    .outputpushpull = GPIO_OTYPE_PUSHPULL,
    .initalstate = HIGH,
    .alternate_functionality = AF_NONE,
    .pin_speed = HIGH_SPEED,
};

const portpintconfigs_t nucleo_pb0_pin = {
    .port = GPIO_PORT_B,
    .pin = GPIO_PIN_0,
    .pinType = GPIO_OUTPUT,
    .pullconfig = GPIO_PULL_DOWN,
    .outputpushpull = GPIO_OTYPE_PUSHPULL,
    .initalstate = LOW,
    .alternate_functionality = AF_NONE,
    .pin_speed = HIGH_SPEED,
};



const portpintconfigs_t logic_pin = {
    .port = GPIO_PORT_B,
    .pin = GPIO_PIN_14,
    .pinType = GPIO_OUTPUT,
    .pullconfig = GPIO_PULL_DOWN, 
    .outputpushpull = GPIO_OTYPE_PUSHPULL,
    .initalstate = LOW,
    .alternate_functionality = AF_NONE,
    .pin_speed = HIGH_SPEED,
};


const portpintconfigs_t Stm32NucleoConfigsPortB[] = {led_pin,logic_pin,nucleo_pb0_pin};

#define CONFIG_CNT     (sizeof(Stm32NucleoConfigsPortB)/sizeof(Stm32NucleoConfigsPortB[0]))



static void Gpio_InitialiseAllPinsPort(const portpintconfigs_t *configsgpio , uint32_t config_count)
{
    /*Warning : this config count var must be 32-bit , i need to find a reason why and fix it*/

    /*
    * Compiler issue : Aligns with EABI Principles: While EABI defines rules for all integer types, 
    * using native word sizes for loop counters and significant arithmetic operations generally 
    * leads to more stable and predictable code, as it avoids potential edge cases or less-optimized 
    * paths that compilers might have for smaller types when they interact with pointer arithmetic
    */
    uint32_t cfg_count=0;

    for(cfg_count=0;cfg_count<config_count;cfg_count++)
    {
        Gpio_ConfigPin(&configsgpio[cfg_count]);
    }

    return;
    
}


static void InitaliseAllPins(const portpintconfigs_t *configsgpio , uint32_t config_count)
{
     uint32_t cfg_count=0;
    
    for(cfg_count=0;cfg_count<config_count;cfg_count++)
    {
        Gpio_SetLevel(configsgpio[cfg_count].port , configsgpio[cfg_count].pin , configsgpio[cfg_count].initalstate);
        
    }

    return;
}

void Gpio_ConfigAllPorts(void)
{
    Gpio_InitialiseAllPinsPort(Stm32NucleoConfigsPortB,CONFIG_CNT);
    InitaliseAllPins(Stm32NucleoConfigsPortB,CONFIG_CNT);
}
