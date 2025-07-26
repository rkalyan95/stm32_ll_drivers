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

#ifdef DEBUG_DELAY
static void delayrndom(uint32_t dly)
{
    for(uint32_t i=0;i<dly;i++)
    {
        __NOP();
    }
}
#endif

btn_evt_t finalBtnEvt;
led_states_t led_state_main = LED_OFF;

void main(void)
{
    FlashErr_t RetCode;
    InitAllClocks();
    RetCode = UpdateFirmwareInFlash();

    Gpio_ConfigAllPorts();

     __enable_irq();
    NVIC_SetPriority(EXTI15_10_IRQn, 47);
    NVIC_EnableIRQ(EXTI15_10_IRQn);      // Enable the interrupt in the NVIC


    while(1)
    {
        finalBtnEvt = BTN_NONE;
        finalBtnEvt = handledebouncecrudeway();
        led_state_main = Fsm_Run(finalBtnEvt,led_state_main);
        
    }

}

