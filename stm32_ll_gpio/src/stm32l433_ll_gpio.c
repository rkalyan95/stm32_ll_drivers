#include "stm32l433_ll_gpio.h"
#include "stm32l433_ll_gpio_cfg.h"

GPIO_TypeDef *Gpio_Port;

void Gpio_Init(void)
{
    GPIO_TypeDef *GpioB_Configs = ((GPIO_TypeDef *) GPIOB_BASE);
    GPIO_TypeDef *GpioA_Configs = ((GPIO_TypeDef *) GPIOA_BASE);

    /* 
    * Copy the configs from local to the hardware registers 
    */
    //GpioA_Configs->MODER = GPIOA_MODER_Reg.U;
   // GpioA_Configs->AFR[1] = GPIOA_AFRH_Reg.U; // Set alternate function for pins 13 and 14
   // GpioB_Configs->MODER = GPIOB_MODER_Reg.U;
}

GPIO_TypeDef *GetPortAddress(uint8_t port)
{
    switch(port)
    {
        case GPIO_PORT_A:
            Gpio_Port = ((GPIO_TypeDef *) GPIOA_BASE);
            break;
        case GPIO_PORT_B:
            Gpio_Port = ((GPIO_TypeDef *) GPIOB_BASE);
            break;
        case GPIO_PORT_C:
            Gpio_Port = ((GPIO_TypeDef *) GPIOC_BASE);
            break;
        case GPIO_PORT_D:
            Gpio_Port = ((GPIO_TypeDef *) GPIOD_BASE);
            break;  
        case GPIO_PORT_E:
            Gpio_Port = ((GPIO_TypeDef *) GPIOE_BASE);
            break;
        case GPIO_PORT_H:
            Gpio_Port = ((GPIO_TypeDef *) GPIOH_BASE);
            break;
        default:
            // Invalid port, handle error
            return 0; // or assert, or log error
    } 

    return Gpio_Port;
}

void Gpio_ConfigPin(const portpintconfigs_t *portpinconfigs)
{
    uint8_t pinrange;

    GPIO_TypeDef *Gpio_Port;

    if(portpinconfigs->pin > GPIO_PIN_MAX)
    {
        return;
    }
/*Get the port address*/

    Gpio_Port = GetPortAddress(portpinconfigs->port);

/*Configure the mode of the pin*/

    SET_BITS(Gpio_Port->MODER,((portpinconfigs->pin) << 1),2,portpinconfigs->pinType);

/* configure the alternate functionality : update the AFRL and AFRH registers */

    if(portpinconfigs->port != AF_NONE)
    {
        pinrange = (portpinconfigs->pin > GPIO_PIN_7 ? 1 : 0 );
        if(pinrange)
        {
           SET_BITS(Gpio_Port->AFR[1],((portpinconfigs->pin) << 2),4,portpinconfigs->alternate_functionality);
        }
        else
        {
            SET_BITS(Gpio_Port->AFR[0],((portpinconfigs->pin) << 2),4,portpinconfigs->alternate_functionality);
        }
    }
    else
    {
        /*Do nothing*/
    }

/* configure the pull configuration*/
        SET_BITS(Gpio_Port->PUPDR,((portpinconfigs->pin) << 1),2,portpinconfigs->pullconfig);

/* config the pushpull/open drain using OT register*/
        SET_BITS(Gpio_Port->OTYPER,(portpinconfigs->pin),1,portpinconfigs->outputpushpull);
}

void Gpio_SetPin(uint8_t port , uint8_t pin)
{
    GPIO_TypeDef *Gpio_Port;
    if(Gpio_Port!=0)
    {
        SET(Gpio_Port->ODR, pin); // Toggle the LED pin
    }
    else
    {
        /*Do nothing*/
    }

}

void Gpio_ClearPin(uint8_t port , uint8_t pin)
{
    GPIO_TypeDef *Gpio_Port;
    if(Gpio_Port!=0)
    {
        CLEAR(Gpio_Port->ODR, pin); // Toggle the LED pin
    }
    else
    {
        /*Do nothing*/
    }

}

void Gpio_GetPin(uint8_t port ,uint8_t pin)
{
    GPIO_TypeDef *Gpio_Port;
    if(Gpio_Port!=0)
    {
        TOGGLE(Gpio_Port->ODR, pin); // Toggle the LED pin
    }
    else
    {
        /*Do nothing*/
    }

}

void Gpio_TogglePin(uint8_t port , uint8_t pin)
{
    
    GPIO_TypeDef *Gpio_Port;

    Gpio_Port = GetPortAddress(port);

    if(Gpio_Port!=0)
    {
        TOGGLE(Gpio_Port->ODR, pin); // Toggle the LED pin
    }
    else
    {
        /*Do nothing*/
    }

}  