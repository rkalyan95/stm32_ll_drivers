//#include "stm32l433_ll_gpio.h"
#include "stm32_syscfg.h"
#include "stm32_syscfg_cfg.h"
#include "stm32_ll_exti.h"
#include <stdint.h>



static Exti_Reg_t GetExtiReg(uint8_t *RegPos,pinnumber_t pin)
{
    Exti_Reg_t RegNum = EXTI_INVALID;
    if((pin == GPIO_PIN_0 || pin == GPIO_PIN_4 || pin == GPIO_PIN_8 || pin == GPIO_PIN_12))
    {
        *RegPos = 0;
    }
    else if((pin == GPIO_PIN_1 || pin == GPIO_PIN_5 || pin == GPIO_PIN_9 || pin == GPIO_PIN_13))
    {
        *RegPos = 4;
    }
    else if((pin == GPIO_PIN_2 || pin == GPIO_PIN_6 || pin == GPIO_PIN_10 || pin == GPIO_PIN_14))
    {
        *RegPos = 8;
    }
    else if((pin == GPIO_PIN_3 || pin == GPIO_PIN_7 || pin == GPIO_PIN_11 || pin == GPIO_PIN_15))
    {
        *RegPos = 12;
    }
    else {
        // Should not happen for valid pinnumber_t (0-15), but good for robustness
        // Or handle an error case here, e.g., return EXTI_INVALID
        return EXTI_INVALID;
    }

    if(pin >= GPIO_PIN_0 && pin <= GPIO_PIN_3) {
        RegNum = EXTI1; // Corresponds to SYSCFG->EXTICR[0]
    } else if (pin >= GPIO_PIN_4 && pin <= GPIO_PIN_7) {
        RegNum = EXTI2; // Corresponds to SYSCFG->EXTICR[1]
    } else if (pin >= GPIO_PIN_8 && pin <= GPIO_PIN_11) {
        RegNum = EXTI3; // Corresponds to SYSCFG->EXTICR[2]
    } else if (pin >= GPIO_PIN_12 && pin <= GPIO_PIN_15) { RegNum = EXTI4;
    }
        
    return RegNum;
}

void Gpio_Interrupts_Configure(gpioport_t port , pinnumber_t pin)
{

    Exti_Reg_t ExtiReg;
    uint8_t RegPos;

    ExtiReg = GetExtiReg(&RegPos ,pin);
    if(ExtiReg!=EXTI_INVALID)
    {
    switch (port)
    {
        case GPIO_PORT_A:
             //if portA , pass PAx and the calculated position for register value.
            SysCfgExti1Configure(ExtiReg,RegPos,EXTIx_PAx);
            break;
        case GPIO_PORT_B:
            SysCfgExti1Configure(ExtiReg,RegPos,EXTIx_PBx);
            break;
        case GPIO_PORT_C:
            SysCfgExti1Configure(ExtiReg,RegPos,EXTIx_PCx);
            break;
        case GPIO_PORT_D:
            SysCfgExti1Configure(ExtiReg,RegPos,EXTIx_PDx);
            break;
        case GPIO_PORT_E:
            SysCfgExti1Configure(ExtiReg,RegPos,EXTIx_PEx);
            break;
        case GPIO_PORT_H:
            SysCfgExti1Configure(ExtiReg,RegPos,EXTIx_PHx);
            break;
    }
}
else
{
    /*Add logging here if needed*/
}
}