#include "stm32_ll_timers_cfg.h"
#include "stm32_ll_timers.h"
#include <stddef.h>



volatile static uint8_t isr_occured=0;

static void ConfigureOutputSettings(TimerSpecificConfigs_t *TimerCfg)
{

    TimerSetCounterMode(TimerCfg->CntDirection);                              // Set up-counting mode (0)
    TimerConfigureControlRegister1(TIMER_DIR_MODE, TimerCfg->CntMode);   // Set direction to up-counting (0)
    TimerSetSampleRate(TimerCfg->SampleRate);                               // Set clock division to 0 (no division)
}


static void ConfigureTimerChannel(ChannelSpecificConfigs_t *ChannelCfg)
{
    /* Defensive checks: ensure pointer and index valid */
    if (ChannelCfg == NULL) { return; }
    if (ChannelCfg->TimerNumber >= TIMER_MAX_CHANNEL) { return; }

    ChannelSpecificConfigs_t *chan = ChannelCfg;

    if (chan == NULL) { return; }

    switch(chan->TimerNumber)
    {
        case TIMER_CH1:
            if(chan->TimerType==TIMER_OUTPUT_COMPARE)
            {
                
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,chan->CapCompareMapping); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPMODE1, chan->OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(chan->TimerNumber, chan->TimerCompareValue);                 // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE1, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN1, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,chan->CapCompareMapping);
                //TimerConfigureInputCaptureReg1(TIMER_CAP_PRESCA1,chan->ExtPrescaler);
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
                
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,chan->CapCompareMapping); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPMODE2, chan->OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(chan->TimerNumber, chan->TimerCompareValue);                     // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE2, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN2, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,chan->CapCompareMapping);
                //TimerConfigureInputCaptureReg1(TIMER_CAP_PRESCA2,chan->ExtPrescaler);
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
                
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,chan->CapCompareMapping); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPMODE3, chan->OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(chan->TimerNumber, chan->TimerCompareValue);                  // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE3, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN3, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,chan->CapCompareMapping);
                //TimerConfigureInputCaptureReg1(TIMER_CAP_PRESCA1,chan->ExtPrescaler);
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
                
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,chan->CapCompareMapping); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPMODE4, chan->OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(chan->TimerNumber, chan->TimerCompareValue);                     // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE4, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN4, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,chan->CapCompareMapping);
                //TimerConfigureInputCaptureReg1(TIMER_CAP_PRESCA1,chan->ExtPrescaler);
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

static void ConfigureTimerDmaEvtInterrupts(TimerSpecificConfigs_t *TimerCfg)
{

    TimerConfigureDmaAndInterrupts(TIMER_CNTCMP1_INTER_ENABLE_DMA,1);
    TimerConfigureDmaAndInterrupts(TIMER_UPDATEINTER_ENABLE_DMA,1);
    TimerConfigureDmaAndInterrupts(TIMER_TRIGINTER_ENABLE_DMA,0);
    TimerConfigureDmaAndInterrupts(TIMER_DMARQST_ENABLE_DMA,0);
    TimerConfigureDmaAndInterrupts(TIMER_TRIG_DMA_ENABLE_DMA,0);
    
}

void TimerInit(TimerSpecificConfigs_t *TimerCfg,ChannelSpecificConfigs_t *ChannelCfg,uint16_t pre , uint32_t arrvalue)
{
    /*Disable counter first to configure safely*/ 
    TimerUpdateCountValue(0);
    TimerConfigureControlRegister1(COUNTER_ENABLE, 0);
    ConfigureOutputSettings(TimerCfg);
   // Configure basic timer parameters
    TimerUpdatePrescale(pre);        // Set the prescaler value
    TimerUpdateAutoReloadCount(arrvalue);       // Set the period (Auto-Reload Register)

    // Basic CR1 settings (if not already handled by specialized functions)
    TimerConfigureControlRegister1(TIMER_AUTO_REL_EN, 1); // Enable auto-reload preload
   
    
    ConfigureTimerChannel(ChannelCfg);
    ConfigureTimerDmaEvtInterrupts(TimerCfg);
    // Finally, enable the timer counter
    TimerConfigureControlRegister1(COUNTER_ENABLE, 1);

    NVIC_SetPriority(TIM2_IRQn, TimerCfg->IsrPrio);
    NVIC_EnableIRQ(TIM2_IRQn);      // Enable the interrupt in the NVIC
}

void GetFeedbackValues(uint8_t timerchanIdx , float *dutycycle)
{
    static uint32_t previousCnt = 0;
    static uint32_t currentCnt = 0;
    *dutycycle = 0.0f;

    if(isr_occured==1)
    {
        previousCnt = TimerGetCountValue(timerchanIdx);
    }
    else if(isr_occured==2)
    {
        isr_occured = 0;
        currentCnt = previousCnt + TimerGetCountValue(timerchanIdx);
        *dutycycle = (float)(currentCnt-previousCnt)/160;
    }

}
void __isr_tim2(void)
{
    uint8_t test=0;
    
    // Clear the update interrupt flag
    TimerSetDmaAndInterruptSt(TIMER_STATUS_UPDATEINTER, 0);
    TimerGetDmaAndInterruptSt(TIMER_STATUS_CAPCMP1, &test);
    if( test != 0)
    {
        TimerSetDmaAndInterruptSt(TIMER_STATUS_CAPCMP1, 0);
        isr_occured++;
    }

}