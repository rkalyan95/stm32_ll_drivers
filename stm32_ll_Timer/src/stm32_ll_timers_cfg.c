#include "stm32_ll_timers_cfg.h"
#include "stm32_ll_timers.h"

#define OUTPUT_TIMER_TEST 

uint8_t ledisr=0;
volatile static bool isr_occured=0;

TimerChannelCfg_t TimerLedRed = {
    .TimerNumber = TIMER_CH1,
    .MasterModeTrigout = COUNTER_UP,
    .SampleRate = TIMER_SAMPLE_DIV1,
    .TimerOutPolarity = TIMER_ACTIVE_HIGH,
    .TimerType = TIMER_OUTPUT_COMPARE,//INPUT_CAPTURE_FALLING_EDGE,//
    .ExtPrescaler = PRESCALER_OFF,
    .InputCapturFilter = FSAMPLING_FDTS_DIV32_N6,
    .OutCmpMode = TIMER_OUT_PWM_MODE1,
    .CntDirection = COUNTER_UP,
    .CntMode = EDGE_ALIGNED,
    .UpdateEventGen = UPDATE_EVT_ENABLED,
};

TimerChannelCfg_t TimerLedGreen = {
    .TimerNumber = TIMER_CH2,
    .MasterModeTrigout = COUNTER_UP,
    .SampleRate = TIMER_SAMPLE_DIV1,
    .TimerOutPolarity = TIMER_ACTIVE_HIGH,
    .TimerType = TIMER_OUTPUT_COMPARE,//INPUT_CAPTURE_FALLING_EDGE,//
    .ExtPrescaler = PRESCALER_OFF,
    .InputCapturFilter = FSAMPLING_FDTS_DIV32_N6,
    .OutCmpMode = TIMER_OUT_PWM_MODE1,
    .CntDirection = COUNTER_UP,
    .CntMode = EDGE_ALIGNED,
    .UpdateEventGen = UPDATE_EVT_ENABLED,
};

TimerChannelCfg_t TimerLedBlue = {
    .TimerNumber = TIMER_CH3,
    .MasterModeTrigout = COUNTER_UP,
    .SampleRate = TIMER_SAMPLE_DIV1,
    .TimerOutPolarity = TIMER_ACTIVE_HIGH,
    .TimerType = TIMER_OUTPUT_COMPARE,//INPUT_CAPTURE_FALLING_EDGE,//
    .ExtPrescaler = PRESCALER_OFF,
    .InputCapturFilter = FSAMPLING_FDTS_DIV32_N6,
    .OutCmpMode = TIMER_OUT_PWM_MODE1,
    .CntDirection = COUNTER_UP,
    .CntMode = EDGE_ALIGNED,
    .UpdateEventGen = UPDATE_EVT_ENABLED,
};

TimerChannelCfg_t TimerLedYellow = {
    .TimerNumber = TIMER_CH4,
    .MasterModeTrigout = COUNTER_UP,
    .SampleRate = TIMER_SAMPLE_DIV1,
    .TimerOutPolarity = TIMER_ACTIVE_HIGH,
    .TimerType = TIMER_OUTPUT_COMPARE,//INPUT_CAPTURE_FALLING_EDGE,//
    .ExtPrescaler = PRESCALER_OFF,
    .InputCapturFilter = FSAMPLING_FDTS_DIV32_N6,
    .OutCmpMode = TIMER_OUT_PWM_MODE1,
    .CntDirection = COUNTER_UP,
    .CntMode = EDGE_ALIGNED,
    .UpdateEventGen = UPDATE_EVT_ENABLED,
};

ArrCfg_t ArrCfgLedGreen = {
    .AutoReloadValue = 79,
    .ArrEn = ENABLED_SET,
    .TimerCompareValue = 1,
    .TimerPrescaler = 2999,
};

ArrCfg_t ArrCfgLedRed = {
    .AutoReloadValue = 79,
    .ArrEn = ENABLED_SET,
    .TimerCompareValue = 1,
    .TimerPrescaler = 2999,
};

ArrCfg_t ArrCfgLedBlue = {
    .AutoReloadValue = 79,
    .ArrEn = ENABLED_SET,
    .TimerCompareValue = 1,
    .TimerPrescaler = 2999,
};

ArrCfg_t ArrCfgLedYellow = {
    .AutoReloadValue = 79,
    .ArrEn = ENABLED_SET,
    .TimerCompareValue = 1,
    .TimerPrescaler = 2999,
};

TimerIsr_t TimerIsr = {
    .IsrEn = ENABLED_SET,
    .IsrPrio = 56
};

DmaCfg_t DmaSetting = {
    .DmaEvt = DMA_EVT_ON_CNTCMP,
    .Trig_Evt_Dma_En = DISABLED_RESET,
    .Trig_Upd_Dma_En = DISABLED_RESET,
    .Trig_Cmp_Dma_En = DISABLED_RESET,
};

TimerCfg_t myTimers[] = 
{
    {
        .TimerCfg = &TimerLedRed,
        .AutoReloadSetting = &ArrCfgLedRed,
        .IsrData = &TimerIsr,
        .DmaCfg = &DmaSetting,
    },
    {
        .TimerCfg = &TimerLedGreen,
        .AutoReloadSetting = &ArrCfgLedGreen,
        .IsrData = &TimerIsr,
        .DmaCfg = &DmaSetting,
    },
    {
        .TimerCfg = &TimerLedBlue,
        .AutoReloadSetting = &ArrCfgLedBlue,
        .IsrData = &TimerIsr,
        .DmaCfg = &DmaSetting,
    },
    {
        .TimerCfg = &TimerLedYellow,
        .AutoReloadSetting = &ArrCfgLedYellow,
        .IsrData = &TimerIsr,
        .DmaCfg = &DmaSetting,
    },
};

static void ConfigureOutputSettings(TimerCfg_t *TimerCfg,uint8_t timerIdx)
{
    // Configure basic timer parameters
    TimerUpdatePrescale(TimerCfg[timerIdx].AutoReloadSetting->TimerPrescaler);        // Set the prescaler value
    TimerUpdateAutoReloadCount(TimerCfg[timerIdx].AutoReloadSetting->AutoReloadValue);       // Set the period (Auto-Reload Register)

    // Basic CR1 settings (if not already handled by specialized functions)
    TimerConfigureControlRegister1(TIMER_AUTO_REL_EN, TimerCfg[timerIdx].AutoReloadSetting->ArrEn); // Enable auto-reload preload
    TimerSetCounterMode(TimerCfg[timerIdx].TimerCfg->CntDirection);                              // Set up-counting mode (0)
    TimerConfigureControlRegister1(TIMER_DIR_MODE, TimerCfg[timerIdx].TimerCfg->CntMode);   // Set direction to up-counting (0)
    TimerSetSampleRate(TimerCfg[timerIdx].TimerCfg->SampleRate);                               // Set clock division to 0 (no division)

    
}


static void ConfigureTimerChannel(TimerCfg_t *TimerCfg,uint8_t timerIdx)
{
    switch(TimerCfg[timerIdx].TimerCfg->TimerNumber)
    {
        case TIMER_CH1:
            if(TimerCfg[timerIdx].TimerCfg->TimerType==TIMER_OUTPUT_COMPARE)
            {
                ConfigureOutputSettings(TimerCfg,timerIdx);
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPSEL1, TimerCfg[timerIdx].TimerCfg->TimerType); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPMODE1, TimerCfg[timerIdx].TimerCfg->OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(TimerCfg[timerIdx].TimerCfg->TimerNumber, TimerCfg[0].AutoReloadSetting->TimerCompareValue);                 // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE1, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN1, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,TimerCfg[timerIdx].TimerCfg->TimerType);
                TimerConfigureInputCaptureReg1(TIMER_CAP_PRESCA1,TimerCfg[timerIdx].TimerCfg->ExtPrescaler);
                TimerConfigureInputCaptureReg1(TIMER_CAPFILTER1,TimerCfg[timerIdx].TimerCfg->InputCapturFilter);
                if(TimerCfg[timerIdx].TimerCfg->TimerType==INPUT_CAPTURE_FALLING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE1, 1); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE1, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(TimerCfg[timerIdx].TimerCfg->TimerType==INPUT_CAPTURE_RISING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE1, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE1, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(TimerCfg[timerIdx].TimerCfg->TimerType==INPUT_CAPTURE_BOTH_EDGES)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE1, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE1, 1); // Enable Capture/Compare Channel 1 output
                }

                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN1, 1);
            }
            break;
        case TIMER_CH2:
            if(TimerCfg[timerIdx].TimerCfg->TimerType==TIMER_OUTPUT_COMPARE)
            {
                ConfigureOutputSettings(TimerCfg,timerIdx);
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPSEL2, TimerCfg[timerIdx].TimerCfg->TimerType); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPMODE2, TimerCfg[timerIdx].TimerCfg->OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(TimerCfg[timerIdx].TimerCfg->TimerNumber, TimerCfg[timerIdx].AutoReloadSetting->TimerCompareValue);                 // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE2, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN2, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL2,TimerCfg[timerIdx].TimerCfg->TimerType);
                TimerConfigureInputCaptureReg1(TIMER_CAP_PRESCA2,TimerCfg[timerIdx].TimerCfg->ExtPrescaler);
                TimerConfigureInputCaptureReg1(TIMER_CAPFILTER2,TimerCfg[timerIdx].TimerCfg->InputCapturFilter);
                if(TimerCfg[0].TimerCfg->TimerType==INPUT_CAPTURE_FALLING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE2, 1); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE2, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(TimerCfg[0].TimerCfg->TimerType==INPUT_CAPTURE_RISING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE2, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE2, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(TimerCfg[0].TimerCfg->TimerType==INPUT_CAPTURE_BOTH_EDGES)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE2, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE2, 1); // Enable Capture/Compare Channel 1 output
                }

            }
            break;
        case TIMER_CH3:
            if(TimerCfg[timerIdx].TimerCfg->TimerType==TIMER_OUTPUT_COMPARE)
            {
                ConfigureOutputSettings(TimerCfg,timerIdx);
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPSEL3, TimerCfg[timerIdx].TimerCfg->TimerType); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPMODE3, TimerCfg[timerIdx].TimerCfg->OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(TimerCfg[timerIdx].TimerCfg->TimerNumber, TimerCfg[timerIdx].AutoReloadSetting->TimerCompareValue);                 // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE3, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN3, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,TimerCfg[timerIdx].TimerCfg->TimerType);
                TimerConfigureInputCaptureReg1(TIMER_CAP_PRESCA1,TimerCfg[timerIdx].TimerCfg->ExtPrescaler);
                TimerConfigureInputCaptureReg1(TIMER_CAPFILTER1,TimerCfg[timerIdx].TimerCfg->InputCapturFilter);
                if(TimerCfg[timerIdx].TimerCfg->TimerType==INPUT_CAPTURE_FALLING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE3, 1); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE3, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(TimerCfg[timerIdx].TimerCfg->TimerType==INPUT_CAPTURE_RISING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE3, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE3, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(TimerCfg[timerIdx].TimerCfg->TimerType==INPUT_CAPTURE_BOTH_EDGES)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE3, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE3, 1); // Enable Capture/Compare Channel 1 output
                }
         
            }
            break;
        case TIMER_CH4:
            if(TimerCfg[timerIdx].TimerCfg->TimerType==TIMER_OUTPUT_COMPARE)
            {
                ConfigureOutputSettings(TimerCfg,timerIdx);
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPSEL4, TimerCfg[timerIdx].TimerCfg->TimerType); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPMODE4, TimerCfg[timerIdx].TimerCfg->OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(TimerCfg[timerIdx].TimerCfg->TimerNumber, TimerCfg[timerIdx].AutoReloadSetting->TimerCompareValue);                 // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE4, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN4, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,TimerCfg[timerIdx].TimerCfg->TimerType);
                TimerConfigureInputCaptureReg1(TIMER_CAP_PRESCA1,TimerCfg[timerIdx].TimerCfg->ExtPrescaler);
                TimerConfigureInputCaptureReg1(TIMER_CAPFILTER1,TimerCfg[timerIdx].TimerCfg->InputCapturFilter);
                if(TimerCfg[timerIdx].TimerCfg->TimerType==INPUT_CAPTURE_FALLING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE4, 1); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE4, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(TimerCfg[timerIdx].TimerCfg->TimerType==INPUT_CAPTURE_RISING_EDGE)
                {
                    TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE4, 0); // Enable Capture/Compare Channel 1 output
                    TimerCounterCompareEnable(TIMER_CNTCMP_NEGATIVE4, 0); // Enable Capture/Compare Channel 1 output
                }
                else if(TimerCfg[timerIdx].TimerCfg->TimerType==INPUT_CAPTURE_BOTH_EDGES)
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

static void TimerInit(TimerCfg_t *TimerCfg)
{
    /*Disable counter first to configure safely*/ 
    TimerUpdateCountValue(0);
    TimerConfigureControlRegister1(COUNTER_ENABLE, 0);

    ConfigureTimerChannel(TimerCfg,0);
    ConfigureTimerChannel(TimerCfg,1);
    ConfigureTimerChannel(TimerCfg,2);
    ConfigureTimerChannel(TimerCfg,3);
    ConfigureChannelDmaEvtInterrupts(TimerCfg,0);

    // Finally, enable the timer counter
    TimerConfigureControlRegister1(COUNTER_ENABLE, 1);

    NVIC_SetPriority(TIM2_IRQn, TimerCfg[0].IsrData->IsrPrio);
    NVIC_EnableIRQ(TIM2_IRQn);      // Enable the interrupt in the NVIC
}

void PwmInit(void)
{
    TimerInit(&myTimers[0]);
    TimerInit(&myTimers[1]);
    TimerInit(&myTimers[2]);
    TimerInit(&myTimers[3]);
}

void LedFade(void)
{
    static uint32_t ccr = 0;

    static int8_t direction = 1; // 1 for fade up, -1 for fade down

if(isr_occured)
{
    
    isr_occured = 0;
    //ledisr++;
    
    // Update the compare value
    ccr += direction;

    // Correctly handle the boundaries
    if (direction == 1 && ccr >= myTimers[0].AutoReloadSetting->AutoReloadValue) {
        ccr = myTimers[0].AutoReloadSetting->AutoReloadValue;
        direction = -1;
    } else if (direction == -1 && ccr == 0) {
        direction = 1;
    }

    // Apply the new compare value
    TimerUpdateCompareValue(myTimers[0].TimerCfg->TimerNumber, ccr);
    TimerUpdateCompareValue(myTimers[1].TimerCfg->TimerNumber, ccr);
    TimerUpdateCompareValue(myTimers[2].TimerCfg->TimerNumber, ccr);
    TimerUpdateCompareValue(myTimers[3].TimerCfg->TimerNumber, ccr);
}
}

void __isr_tim2(void)
{
    // Clear the update interrupt flag
    TimerSetDmaAndInterruptSt(TIMER_STATUS_UPDATEINTER, 0);
    isr_occured = 1;
    //ledisr++;
}