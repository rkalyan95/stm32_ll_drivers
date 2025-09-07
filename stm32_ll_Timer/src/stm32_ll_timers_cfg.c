#include "stm32_ll_timers_cfg.h"
#include "stm32_ll_timers.h"
#include <stddef.h>



volatile static bool isr_occured=0;


static void ConfigureOutputSettings(TimerCfg_t *TimerCfg,uint8_t timerIdx)
{

    TimerSetCounterMode(TimerCfg[timerIdx].TimerCfg->CntDirection);                              // Set up-counting mode (0)
    TimerConfigureControlRegister1(TIMER_DIR_MODE, TimerCfg[timerIdx].TimerCfg->CntMode);   // Set direction to up-counting (0)
    TimerSetSampleRate(TimerCfg[timerIdx].TimerCfg->SampleRate);                               // Set clock division to 0 (no division)
}


static void ConfigureTimerChannel(TimerCfg_t *TimerCfg,uint8_t timerIdx)
{
    /* Defensive checks: ensure pointer and index valid */
    if (TimerCfg == NULL) { return; }
    if (timerIdx >= TIMER_MAX_CHANNEL) { return; }

    TimerChannelCfg_t *chan = TimerCfg[timerIdx].TimerCfg;

    if (chan == NULL) { return; }

    switch(chan->TimerNumber)
    {
        case TIMER_CH1:
            if(chan->TimerType==TIMER_OUTPUT_COMPARE)
            {
                ConfigureOutputSettings(TimerCfg,timerIdx);
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPSEL1, chan->TimerType); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPMODE1, chan->OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(chan->TimerNumber, chan->TimerCompareValue);                 // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE1, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN1, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,chan->TimerType);
                TimerConfigureInputCaptureReg1(TIMER_CAP_PRESCA1,chan->ExtPrescaler);
                TimerConfigureInputCaptureReg1(TIMER_CAPFILTER1,chan->InputCapturFilter);
                if(chan->TimerType==INPUT_CAPTURE_FALLING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE1, 1); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE1, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(chan->TimerType==INPUT_CAPTURE_RISING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE1, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE1, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(chan->TimerType==INPUT_CAPTURE_BOTH_EDGES)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE1, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE1, 1); // Enable Capture/Compare Channel 1 output
                }

                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN1, 1);
            }
            break;
        case TIMER_CH2:
            if(chan->TimerType==TIMER_OUTPUT_COMPARE)
            {
                ConfigureOutputSettings(TimerCfg,timerIdx);
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPSEL2, chan->TimerType); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPMODE2, chan->OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(chan->TimerNumber, chan->TimerCompareValue);                     // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE2, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN2, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL2,chan->TimerType);
                TimerConfigureInputCaptureReg1(TIMER_CAP_PRESCA2,chan->ExtPrescaler);
                TimerConfigureInputCaptureReg1(TIMER_CAPFILTER2,chan->InputCapturFilter);
                if(chan->TimerType==INPUT_CAPTURE_FALLING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE2, 1); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE2, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(chan->TimerType==INPUT_CAPTURE_RISING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE2, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE2, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(chan->TimerType==INPUT_CAPTURE_BOTH_EDGES)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE2, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE2, 1); // Enable Capture/Compare Channel 1 output
                }

            }
            break;
        case TIMER_CH3:
            if(chan->TimerType==TIMER_OUTPUT_COMPARE)
            {
                ConfigureOutputSettings(TimerCfg,timerIdx);
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPSEL3, chan->TimerType); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPMODE3, chan->OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(chan->TimerNumber, chan->TimerCompareValue);                  // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE3, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN3, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,chan->TimerType);
                TimerConfigureInputCaptureReg1(TIMER_CAP_PRESCA1,chan->ExtPrescaler);
                TimerConfigureInputCaptureReg1(TIMER_CAPFILTER1,chan->InputCapturFilter);
                if(chan->TimerType==INPUT_CAPTURE_FALLING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE3, 1); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE3, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(chan->TimerType==INPUT_CAPTURE_RISING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE3, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE3, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(chan->TimerType==INPUT_CAPTURE_BOTH_EDGES)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE3, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE3, 1); // Enable Capture/Compare Channel 1 output
                }
         
            }
            break;
        case TIMER_CH4:
            if(chan->TimerType==TIMER_OUTPUT_COMPARE)
            {
                ConfigureOutputSettings(TimerCfg,timerIdx);
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPSEL4, chan->TimerType); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPMODE4, chan->OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(chan->TimerNumber, chan->TimerCompareValue);                     // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE4, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN4, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,chan->TimerType);
                TimerConfigureInputCaptureReg1(TIMER_CAP_PRESCA1,chan->ExtPrescaler);
                TimerConfigureInputCaptureReg1(TIMER_CAPFILTER1,chan->InputCapturFilter);
                if(chan->TimerType==INPUT_CAPTURE_FALLING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE4, 1); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE4, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(chan->TimerType==INPUT_CAPTURE_RISING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE4, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE4, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(chan->TimerType==INPUT_CAPTURE_BOTH_EDGES)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE4, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE4, 1); // Enable Capture/Compare Channel 1 output
                }
             
            }
            break;        
    }


}

static void ConfigureChannelDmaEvtInterrupts(TimerCfg_t *TimerCfg,uint8_t timerIdx)
{
    // Generate an update event to load all configured values into active registers
    // Use the specific bit position for the Update Generation event (UG)
   // TimerConfigureEvtGenRegister(TIMER_EVT_CC1G, TimerCfg[0].UpdateEventGen);
    TimerConfigureEvtGenRegister(TIMER_EVT_UG, TimerCfg[timerIdx].TimerCfg->UpdateEventGen);
    TimerConfigureDmaAndInterrupts(TIMER_STATUS_UPDATEINTER,1);
}

void TimerInit(TimerCfg_t *TimerCfg,uint16_t pre , uint32_t arrvalue)
{
    /*Disable counter first to configure safely*/ 
    TimerUpdateCountValue(0);
    TimerConfigureControlRegister1(COUNTER_ENABLE, 0);
   // Configure basic timer parameters
    TimerUpdatePrescale(pre);        // Set the prescaler value
    TimerUpdateAutoReloadCount(arrvalue);       // Set the period (Auto-Reload Register)

    // Basic CR1 settings (if not already handled by specialized functions)
    TimerConfigureControlRegister1(TIMER_AUTO_REL_EN, 1); // Enable auto-reload preload

    for (int i = 0; i < 4; i++) {
        ConfigureTimerChannel(TimerCfg, i);
        ConfigureChannelDmaEvtInterrupts(TimerCfg, i);
    }


    // Finally, enable the timer counter
    TimerConfigureControlRegister1(COUNTER_ENABLE, 1);

    NVIC_SetPriority(TIM2_IRQn, TimerCfg[0].IsrData->IsrPrio);
    NVIC_EnableIRQ(TIM2_IRQn);      // Enable the interrupt in the NVIC
}

void __isr_tim2(void)
{
    // Clear the update interrupt flag
    TimerSetDmaAndInterruptSt(TIMER_STATUS_UPDATEINTER, 0);
    isr_occured = 1;

}