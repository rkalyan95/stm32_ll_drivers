#ifndef STM32L433_LL_GPIO_H
#define STM32L433_LL_GPIO_H

#define LED_PIN 13

#include <stdint.h>
#include <stm32l433xx.h>

typedef enum 
{
    GPIO_PORT_A = 0,
    GPIO_PORT_B = 1,
    GPIO_PORT_C = 2,
    GPIO_PORT_D = 3,
    GPIO_PORT_E = 4,
    GPIO_PORT_H = 7
}gpioport_t;

typedef enum
{
    GPIO_NO_PULL = 0x0,   // No pull-up or pull-d  own
    GPIO_PULL_UP = 0x1, // Pull-up
    GPIO_PULL_DOWN = 0x2 // Pull-down
}gpiopull_t;

typedef enum
{
    GPIO_OTYPE_PUSHPULL = 0x0,   // Push-pull output type
    GPIO_OTYPE_OPENDRAIN = 0x1    // Open-drain output type
}gpio_otypeconfig_t;

typedef enum 
{
    GPIO_PIN_0 = 0,
    GPIO_PIN_1 = 1,
    GPIO_PIN_2 = 2,
    GPIO_PIN_3 = 3,
    GPIO_PIN_4 = 4,
    GPIO_PIN_5 = 5,
    GPIO_PIN_6 = 6,
    GPIO_PIN_7 = 7,
    GPIO_PIN_8 = 8,
    GPIO_PIN_9 = 9,
    GPIO_PIN_10 = 10,
    GPIO_PIN_11 = 11,
    GPIO_PIN_12 = 12,
    GPIO_PIN_13 = 13,
    GPIO_PIN_14 = 14,
    GPIO_PIN_15 = 15,
    GPIO_PIN_MAX=16,
}pinnumber_t;

typedef enum
{
    AF_0,
    AF_1,
    AF_2,
    AF_3,
    AF_4,
    AF_5,
    AF_6,
    AF_7,
    AF_8,
    AF_9,
    AF_10,
    AF_11,
    AF_12,
    AF_13,
    AF_14,
    AF_15,
    AF_NONE,
}alternatefunction_t;

typedef enum
{
    GPIO_INPUT,
    GPIO_OUTPUT,
    ALTERNATE_FUNCTION,
    ANALOG_INPUT,
}portpintype_t;

typedef enum
{
    LOW,
    HIGH
}pininitalstate_t;

typedef enum
{
    LOW_SPEED,
    MEDIUM_SPEED,
    HIGH_SPEED,
    VERYHIGH_SPEED,
}pinspeed_t;

typedef enum
{
    ISR_FALLING,
    ISR_RISING,
    ISR_BOTH,
    ISR_NONE,
}pininterrupt_t;

typedef struct
{
    gpioport_t port;
    pinnumber_t pin;
    portpintype_t pinType;
    gpiopull_t pullconfig;
    gpio_otypeconfig_t outputpushpull;
    pininitalstate_t initalstate;
    alternatefunction_t alternate_functionality;
    pinspeed_t pin_speed;
    pininterrupt_t pin_interrupttype;
}portpintconfigs_t;



void Gpio_ConfigPin(const portpintconfigs_t *portpinconfigs);
void Gpio_ClearPin(const uint8_t port , const uint8_t pin);
void Gpio_SetPin(const uint8_t port , const uint8_t pin);
uint8_t Gpio_GetPin(const uint8_t port ,const uint8_t pin);
void Gpio_SetLevel(const uint8_t port , const uint8_t pin,const uint8_t level);
#endif // STM32L433_LL_GPIO_H