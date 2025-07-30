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
#include "stm32_ll_timers.h"

btn_evt_t finalBtnEvt;
led_states_t led_state_main = LED_OFF;
FirmwareVersion_t Version;


#define ARR_CNT 360
#define PRESCALER_VAL 65535
#define CCR_CNT 180

static void delayrndom(uint32_t dly)
{
    for(uint32_t i=0;i<dly;i++)
    {
        __NOP();
    }
}

/* timer_out_t struct
    type input or output : enum
    pwm frequency : float
    pwm duty cycle : float
    auto reload enabled : enum
    counting direction : enum
    mode of operation : enum
    update event generation : enum
    master or slave : enum and then have another struct with slave configs
    dma config : enum
    priority : 
    isr : 

*/


static void InitPwm(void)
{

    // Disable counter first to configure safely
    TimerConfigureControlRegister1(COUNTER_ENABLE, 0);

    // Configure basic timer parameters
    TimerUpdatePrescale(PRESCALER_VAL);        // Set the prescaler value
    TimerUpdateAutoReloadCount(ARR_CNT);       // Set the period (Auto-Reload Register)

    // Basic CR1 settings (if not already handled by specialized functions)
    TimerConfigureControlRegister1(TIMER_AUTO_REL_EN, 1); // Enable auto-reload preload
    TimerSetCounterMode(0);                              // Set up-counting mode (0)
    TimerConfigureControlRegister1(TIMER_DIR_MODE, 0);   // Set direction to up-counting (0)
    TimerSetSampleRate(0);                               // Set clock division to 0 (no division)

    // Configure Output Compare Channel 1 for PWM
    TimerUpdateCompareValue(1, CCR_CNT);                 // Set the compare value for Channel 1
    TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPSEL1, 0); // Select output compare mode (0 usually for output)
    TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPMODE1, 0x06); // Set PWM Mode 1 (0x06 for 0b110)

    // Configure Capture/Compare Enable Register (CCER)
    // These are standard bit positions (CC1E for enable, CC1P for polarity)
    // Assuming TIM_CCER_CC1P_Pos and TIM_CCER_CC1E_Pos are correct for your enums.
    TimerCounterCompareEnable(TIM_CCER_CC1P_Pos, 0); // Set Channel 1 polarity to Active High (0)
    TimerCounterCompareEnable(TIM_CCER_CC1E_Pos, 1); // Enable Capture/Compare Channel 1 output

    // Generate an update event to load all configured values into active registers
    // Use the specific bit position for the Update Generation event (UG)
    TimerConfigureEvtGenRegister(TIM_EGR_UG_Pos, 1);

    // Finally, enable the timer counter
    TimerConfigureControlRegister1(COUNTER_ENABLE, 1);

}


void main(void)
{
    uint16_t ccr=0;
    FlashErr_t RetCode;
    InitAllClocks();
    Gpio_ConfigAllPorts();

    RetCode = ReadFirmwareDetails(&Version);  //this is causing issue , even the writes do not work

    if(RetCode!=FLASH_OPR_SUCESSS)
    {
        Gpio_SetLevel(led_pin.port,led_pin.pin,HIGH);
        delayrndom(100000);
        RetCode = UpdateFirmwareInFlash();
        Gpio_SetLevel(led_pin.port,led_pin.pin,LOW);
    }
    InitPwm();
     __enable_irq();
    NVIC_SetPriority(EXTI15_10_IRQn, 47);
    NVIC_EnableIRQ(EXTI15_10_IRQn);      // Enable the interrupt in the NVIC

   
    while(1)
    {
        finalBtnEvt = BTN_NONE;
        finalBtnEvt = handledebouncecrudeway();
        led_state_main = Fsm_Run(finalBtnEvt,led_state_main);
        TimerUpdateCompareValue(1, ccr++); 
        if(ccr>=ARR_CNT)
        {
            ccr = 0;
        }                // Set the compare value for Channel 1
        
    }

}

