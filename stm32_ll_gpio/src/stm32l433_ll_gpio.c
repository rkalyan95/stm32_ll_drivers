#include "stm32l433_ll_gpio.h"
#include "stm32l433_ll_gpio_cfg.h"
#include "common.h"

static inline GPIO_TypeDef *GetPortAddress(const uint8_t port)
{
    switch(port)
    {
        case GPIO_PORT_A:
            return ((GPIO_TypeDef *) GPIOA_BASE);
        case GPIO_PORT_B:
            return ((GPIO_TypeDef *) GPIOB_BASE);
        case GPIO_PORT_C:
            return ((GPIO_TypeDef *) GPIOC_BASE);
        case GPIO_PORT_D:
            return ((GPIO_TypeDef *) GPIOD_BASE);
        case GPIO_PORT_E:
            return ((GPIO_TypeDef *) GPIOE_BASE);
        case GPIO_PORT_H:
            return ((GPIO_TypeDef *) GPIOH_BASE);
        default:
            // TODO: Log error for invalid port.
            return 0; // or assert, or log error
    } 

    
}

void Gpio_ConfigPin(const portpintconfigs_t *portpinconfigs)
{
    uint8_t pinrange;

    GPIO_TypeDef *Gpio_Port = GetPortAddress(portpinconfigs->port);

    if(portpinconfigs->pin > GPIO_PIN_MAX || Gpio_Port == 0)
    {
        return;
    }

/*Configure the mode of the pin*/

    SET_BITS(Gpio_Port->MODER,((portpinconfigs->pin) << 1),2,portpinconfigs->pinType);

/* configure the alternate functionality : update the AFRL and AFRH registers */

    if(portpinconfigs->alternate_functionality != AF_NONE)
    {
        pinrange = (portpinconfigs->pin > GPIO_PIN_7 ? 1 : 0 );
        if(pinrange)
        {
           SET_BITS(Gpio_Port->AFR[1],((portpinconfigs->pin-8) << 2),4,portpinconfigs->alternate_functionality);
        }
        else
        {
            SET_BITS(Gpio_Port->AFR[0],((portpinconfigs->pin) << 2),4,portpinconfigs->alternate_functionality);
        }
    }
    else
    {
        // No alternate function to configure.
    }

/* configure the pull configuration*/
        SET_BITS(Gpio_Port->PUPDR,((portpinconfigs->pin) << 1),2,portpinconfigs->pullconfig);

/* config the pushpull/open drain using OT register*/
        SET_BITS(Gpio_Port->OTYPER,(portpinconfigs->pin),1,portpinconfigs->outputpushpull);

/* Configure the output speed */
    SET_BITS(Gpio_Port->OSPEEDR,((portpinconfigs->pin) << 1),2,portpinconfigs->pin_speed);

}

void Gpio_SetPin(const uint8_t port , const uint8_t pin)
{
    GPIO_TypeDef *Gpio_Port = GetPortAddress(port);
    if(Gpio_Port!=0)
    {
       Gpio_Port->BSRR = (1UL << pin); // Use 1UL for unsigned long literal
    }
    else
    {
        // Intentionally empty for invalid port
    }

}

void Gpio_ClearPin(const uint8_t port , const uint8_t pin)
{
    GPIO_TypeDef *Gpio_Port = GetPortAddress(port);

    if(Gpio_Port!=0)
    {
       Gpio_Port->BSRR = (1UL << (pin + 16)); // Use 1UL for unsigned long literal
    }
    else
    {
         // Intentionally empty for invalid port
    }

}

void Gpio_SetLevel(const uint8_t port , const uint8_t pin,const uint8_t level)
{
    switch(level)
    {
        case LOW:
            Gpio_ClearPin(port,pin);
            break;
        case HIGH:
            Gpio_SetPin(port,pin);
            break;
        default:
            return; // TODO: Log error for invalid level.
    }
}


uint8_t Gpio_GetPin(const uint8_t port ,const uint8_t pin)
{
    uint8_t pinLvl;

    GPIO_TypeDef *Gpio_Port = GetPortAddress(port);
    if(Gpio_Port!=0)
    {
        pinLvl = GET(Gpio_Port->IDR, pin); // Toggle the LED pin
    }
    else
    {
        pinLvl = 0xff;
        
    }

    return pinLvl;
}

