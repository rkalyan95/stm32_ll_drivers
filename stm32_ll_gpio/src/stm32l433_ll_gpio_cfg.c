#include "stm32l433_ll_gpio_cfg.h"
#include "stm32_syscfg_cfg.h"
#include "stm32_ll_exti.h"
//Warning : DO not change the Pa13 and Pa14 configs please , because they are used for debugger.

const portpintconfigs_t led_pin = {
    .port = GPIO_PORT_B,
    .pin = GPIO_PIN_13,
    .pinType = GPIO_OUTPUT,
    .pullconfig = GPIO_PULL_DOWN,
    .outputpushpull = GPIO_OTYPE_PUSHPULL,
    .initalstate = LOW,
    .alternate_functionality = AF_NONE,
    .pin_speed = HIGH_SPEED,
    .pin_interrupttype = ISR_NONE,
};

const portpintconfigs_t logic_pin = {
    .port = GPIO_PORT_C,
    .pin = GPIO_PIN_9,
    .pinType = GPIO_OUTPUT,
    .pullconfig = GPIO_PULL_DOWN,
    .outputpushpull = GPIO_OTYPE_PUSHPULL,
    .initalstate = LOW,
    .alternate_functionality = AF_NONE,
    .pin_speed = HIGH_SPEED,
    .pin_interrupttype = ISR_NONE,
};


const portpintconfigs_t ledred_pin = {
    .port = GPIO_PORT_A,
    .pin = GPIO_PIN_0,
    .pinType = ALTERNATE_FUNCTION,
    .pullconfig = GPIO_PULL_DOWN,
    .outputpushpull = GPIO_OTYPE_OPENDRAIN,
    .initalstate = LOW,
    .alternate_functionality = AF_1,
    .pin_speed = VERYHIGH_SPEED,
    .pin_interrupttype = ISR_NONE,
};

const portpintconfigs_t ledgreen_pin = {
    .port = GPIO_PORT_A,
    .pin = GPIO_PIN_1,
    .pinType = ALTERNATE_FUNCTION,
    .pullconfig = GPIO_PULL_DOWN,
    .outputpushpull = GPIO_OTYPE_PUSHPULL,
    .initalstate = LOW,
    .alternate_functionality = AF_1,
    .pin_speed = VERYHIGH_SPEED,
    .pin_interrupttype = ISR_NONE,
};

const portpintconfigs_t ledblue_pin = {
    .port = GPIO_PORT_A,
    .pin = GPIO_PIN_2,
    .pinType = ALTERNATE_FUNCTION,
    .pullconfig = GPIO_PULL_DOWN,
    .outputpushpull = GPIO_OTYPE_PUSHPULL,
    .initalstate = LOW,
    .alternate_functionality = AF_1,
    .pin_speed = VERYHIGH_SPEED,
    .pin_interrupttype = ISR_NONE,
};

const portpintconfigs_t ledyellow_pin = {
    .port = GPIO_PORT_A,
    .pin = GPIO_PIN_3,
    .pinType = ALTERNATE_FUNCTION,
    .pullconfig = GPIO_PULL_DOWN,
    .outputpushpull = GPIO_OTYPE_PUSHPULL,
    .initalstate = LOW,
    .alternate_functionality = AF_1,
    .pin_speed = VERYHIGH_SPEED,
    .pin_interrupttype = ISR_NONE,
};

const portpintconfigs_t usart1tx_pin = {
    .port = GPIO_PORT_A,
    .pin = GPIO_PIN_9,
    .pinType = ALTERNATE_FUNCTION,
    .pullconfig = GPIO_PULL_DOWN,
    .outputpushpull = GPIO_OTYPE_PUSHPULL,
    .initalstate = LOW,
    .alternate_functionality = AF_7,
    .pin_speed = VERYHIGH_SPEED,
    .pin_interrupttype = ISR_NONE,
};

const portpintconfigs_t usart1rx_pin = {
    .port = GPIO_PORT_A,
    .pin = GPIO_PIN_10,
    .pinType = ALTERNATE_FUNCTION,
    .pullconfig = GPIO_PULL_DOWN,
    .outputpushpull = GPIO_OTYPE_PUSHPULL,
    .initalstate = LOW,
    .alternate_functionality = AF_7,
    .pin_speed = VERYHIGH_SPEED,
    .pin_interrupttype = ISR_NONE,
};


const portpintconfigs_t button_pin = {
    .port = GPIO_PORT_C,
    .pin = GPIO_PIN_13,
    .pinType = GPIO_INPUT,
    .pullconfig = GPIO_PULL_DOWN, 
    .outputpushpull = GPIO_OTYPE_PUSHPULL,
    .initalstate = LOW,
    .alternate_functionality = AF_NONE,
    .pin_speed = HIGH_SPEED,
    .pin_interrupttype = ISR_RISING,
};

bool level = HIGH;
const portpintconfigs_t Stm32NucleoConfigsPortB[] = {led_pin,button_pin,ledred_pin,ledblue_pin,ledyellow_pin,ledgreen_pin,logic_pin,usart1tx_pin,usart1rx_pin};

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
        if(configsgpio[cfg_count].pin_interrupttype != ISR_NONE)
        {
           Gpio_Interrupts_Configure(configsgpio[cfg_count].port,configsgpio[cfg_count].pin);
           ConfigureInterruptMask(configsgpio[cfg_count].pin,1);
           ConfigureRisingEdgeInterrupt(configsgpio[cfg_count].pin,1);
           ConfigureFallingEdgeInterrupt(configsgpio[cfg_count].pin,1);
        }
    }

    return;
}

void Gpio_ConfigAllPorts(void)
{
    Gpio_InitialiseAllPinsPort(Stm32NucleoConfigsPortB,CONFIG_CNT);
    InitaliseAllPins(Stm32NucleoConfigsPortB,CONFIG_CNT);
}
