/*led is on pb13*/
#include <stdint.h>

#include <stm32l433xx.h>
#include "core_cm4.h"
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"
#include "stm32l433_ll_gpio_cfg.h"
#include "stm32l433_ll_gpio.h"
#include "stm32_ll_exti.h"
#include "System_Fsm.h"
#include "stm32_ll_flash.h"
#include "stm32_ll_flash_cfg.h"
#include "stm32_ll_timers_cfg.h"

btn_evt_t finalBtnEvt;
led_states_t led_state_main = LED_OFF;
FirmwareVersion_t Version;

float angle=0;
static void delayrndom(uint32_t dly)
{
    for(uint32_t i=0;i<dly;i++)
    {
        __NOP();
    }
}

void main(void)
{
    uint16_t ccr=0;
    FlashErr_t RetCode;
    InitAllClocks();
    Gpio_ConfigAllPorts();
#if 0
    RetCode = ReadFirmwareDetails(&Version);  //this is causing issue , even the writes do not work

    if(RetCode!=FLASH_OPR_SUCESSS)
    {
        Gpio_SetLevel(led_pin.port,led_pin.pin,HIGH);
        delayrndom(100000);
        RetCode = UpdateFirmwareInFlash();
        Gpio_SetLevel(led_pin.port,led_pin.pin,LOW);
    }
    //InitPwm();
#endif
     __enable_irq();
    NVIC_SetPriority(EXTI15_10_IRQn, 47);
    NVIC_EnableIRQ(EXTI15_10_IRQn);      // Enable the interrupt in the NVIC
    PwmInit();
    while(1)
    {
        finalBtnEvt = BTN_NONE;
        finalBtnEvt = handledebouncecrudeway();
        if(finalBtnEvt==BTN_PRESSED)
        {
            TurnServo(angle);
            angle+=30;
            angle = (angle>180)?0:angle;
        }
        led_state_main = Fsm_Run(finalBtnEvt,led_state_main);
        //LedFade();
#if 0
        if(ledisr>2 && ledisr<5)
        {  
             
             Gpio_SetLevel(led_pin.port,led_pin.pin,1);
        }
        else if(ledisr>5)
        {
            ledisr = 0;
            Gpio_SetLevel(led_pin.port,led_pin.pin,0); 
        }
#endif
       
    }

}

