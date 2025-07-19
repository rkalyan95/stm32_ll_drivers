#include <stm32l433xx.h>
#include "core_cm4.h"
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"
#include "stm32l433_ll_gpio_cfg.h"
#include "stm32l433_ll_gpio.h"
#include "stm32_ll_exti.h"
#include "System_Fsm.h"

#define DEBOUNCE_TIMER   4000


uint32_t debouncetimer=0;
uint8_t initalBtnLvl;
btn_evt_t fsmEvt;
btn_evt_t btn_event = BTN_RELEASED;
led_states_t led_state = LED_OFF;
uint8_t btn_level;

void __isr_exti15_10(void)
{
    
    btn_level = Gpio_GetPin(button_pin.port,button_pin.pin);

    if(btn_level == HIGH)
    {
        btn_event = BTN_PRESSED;
    }
    else if(btn_level==LOW)
    {
        btn_event = BTN_RELEASED;
    }

    ClearPendingInterrupt(button_pin.pin);
   
}

btn_evt_t handledebouncecrudeway(void)
{
    fsmEvt = BTN_NONE;
    debouncetimer++;

    if (btn_event != BTN_NONE && debouncetimer >= DEBOUNCE_TIMER)
    {
        uint8_t finalBtnLvl = Gpio_GetPin(button_pin.port, button_pin.pin);

        fsmEvt = (finalBtnLvl == HIGH) ? BTN_PRESSED : BTN_RELEASED;

        debouncetimer = 0;
        btn_event = BTN_NONE;
    }

    return fsmEvt;
}


void LedOn(void)
{
    Gpio_SetLevel(led_pin.port,led_pin.pin,HIGH);

}

void LedOff(void)
{
    Gpio_SetLevel(led_pin.port,led_pin.pin,LOW);

}

const Fsm_t myLedSm[] = {
    {.current_state=LED_OFF,.evt=BTN_PRESSED,.next_state=LED_ON,.Dispatch=LedOn},
    {.current_state=LED_OFF,.evt=BTN_RELEASED,.next_state=LED_OFF,.Dispatch=LedOff},
    {.current_state=LED_ON,.evt=BTN_PRESSED,.next_state=LED_ON,.Dispatch=LedOn},
    {.current_state=LED_ON,.evt=BTN_RELEASED,.next_state=LED_OFF,.Dispatch=LedOff}

    };


#define FS_CNT    (sizeof(myLedSm)/sizeof(myLedSm[0]))


static void Fsm_Init(void)
{
    LedOff();
}

led_states_t Fsm_Run(btn_evt_t evt , led_states_t currentstate)
{
    led_states_t nextState = currentstate;
    for(uint32_t i=0;i<FS_CNT;i++)
    {
        if(evt==myLedSm[i].evt && currentstate == myLedSm[i].current_state)   /* Match Found */
        {
            myLedSm[i].Dispatch();
            nextState = myLedSm[i].next_state;
            break;
        }
    }

    return nextState;

}