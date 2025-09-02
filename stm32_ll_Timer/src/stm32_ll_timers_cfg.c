#include "stm32_ll_timers_cfg.h"
#include "stm32_ll_timers.h"
#include <stddef.h>
#define OUTPUT_TIMER_TEST 


#define INPUT_FREQUENCY    24000000UL
#define MIN_PW             0.5f
#define MAX_PW             2.5f
#define MAX_ANGLE          180.f
#define MIN_ANGLE          0.f

#define SERVOANGLE_TOMS(ANGLE)    ((MIN_PW + ((MAX_PW - MIN_PW)*(ANGLE/(MAX_ANGLE-MIN_ANGLE)))))

#define TIMER_ARRVALUE     159  
#define TIMER_PRESCALER    2999
#define AUTO_RELOADED       1  

#define OUTPUT_FREQENCY    ((INPUT_FREQUENCY)/((TIMER_PRESCALER+1)*(TIMER_ARRVALUE+1)))


#define MS_TO_TICKS(MS) \
    ((uint32_t)((MS * OUTPUT_FREQENCY * (TIMER_ARRVALUE+1)) / 1000.0f))


#define SERVOANGLETOTICKS(angle)   MS_TO_TICKS(SERVOANGLE_TOMS(angle))

uint8_t ledisr=0;
volatile static bool isr_occured=0;
volatile uint8_t tickCnt = 0;

TimerChannelCfg_t ServoBottom = {
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
    .TimerCompareValue = 10,
};

TimerChannelCfg_t ServoMiddle = {
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
    .TimerCompareValue = 10,
};

TimerChannelCfg_t ServoTop = {
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
    .TimerCompareValue = 10,
};

TimerChannelCfg_t ServoHand = {
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
    .TimerCompareValue = 10,
};


TimerIsr_t TimerIsr = {
    .IsrEn = 1,
    .IsrPrio = 56
};

DmaCfg_t DmaSetting = {
    .DmaEvt = DMA_EVT_ON_CNTCMP,
    .Trig_Evt_Dma_En = 0,
    .Trig_Upd_Dma_En = 0,
    .Trig_Cmp_Dma_En = 0,
};

TimerCfg_t myTimers[] = 
{
    {
        .TimerCfg = &ServoHand,
        .IsrData = &TimerIsr,
        .DmaCfg = &DmaSetting,
    },
    {
        .TimerCfg = &ServoBottom,
        .IsrData = &TimerIsr,
        .DmaCfg = &DmaSetting,
    },
    {
        .TimerCfg = &ServoTop,
        .IsrData = &TimerIsr,
        .DmaCfg = &DmaSetting,
    },
    {
        .TimerCfg = &ServoMiddle,
        .IsrData = &TimerIsr,
        .DmaCfg = &DmaSetting,
    },

};


#define TIMERCHANNEL_CNT      (sizeof(myTimers)/sizeof(myTimers[0]))


static void ConfigureOutputSettings(TimerCfg_t *TimerCfg,uint8_t timerIdx)
{

    TimerSetCounterMode(TimerCfg[timerIdx].TimerCfg->CntDirection);                              // Set up-counting mode (0)
    TimerConfigureControlRegister1(TIMER_DIR_MODE, TimerCfg[timerIdx].TimerCfg->CntMode);   // Set direction to up-counting (0)
    TimerSetSampleRate(TimerCfg[timerIdx].TimerCfg->SampleRate);                               // Set clock division to 0 (no division)

    
}


static void ConfigureTimerChannel(TimerCfg_t *TimerCfg,uint8_t timerIdx)
{
    /* Defensive checks: ensure pointer and index valid */
    if (TimerCfg == NULL) return;
    if (timerIdx >= TIMERCHANNEL_CNT) return;
    TimerChannelCfg_t *chan = TimerCfg[timerIdx].TimerCfg;
    if (chan == NULL) return;

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

static void TimerInit(TimerCfg_t *TimerCfg)
{
    /*Disable counter first to configure safely*/ 
    TimerUpdateCountValue(0);
    TimerConfigureControlRegister1(COUNTER_ENABLE, 0);
   // Configure basic timer parameters
    TimerUpdatePrescale(TIMER_PRESCALER);        // Set the prescaler value
    TimerUpdateAutoReloadCount(TIMER_ARRVALUE);       // Set the period (Auto-Reload Register)

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

void PwmInit(void)
{
    TimerInit(myTimers);
}

void LedFade(void)
{

    static uint32_t ccr = 0;

    static int8_t direction = 1; // 1 for fade up, -1 for fade down

if(isr_occured)
{
    
    isr_occured = 0;

    // Update the compare value
    ccr += direction;

    // Correctly handle the boundaries
    if (direction == 1 && ccr >= TIMER_ARRVALUE) {
        ccr = TIMER_ARRVALUE;
        direction = -1;
    } else if (direction == -1 && ccr == 0) {
        direction = 1;
    }

    // Apply the new compare value
   // TimerUpdateCompareValue(myTimers[0].TimerCfg->TimerNumber, ccr);
    //TimerUpdateCompareValue(myTimers[1].TimerCfg->TimerNumber, ccr);
    //TimerUpdateCompareValue(myTimers[2].TimerCfg->TimerNumber, ccr);


}

}


void TurnServo(float angle)
{
    float timeMs=0.f;

    timeMs = (float)SERVOANGLE_TOMS(angle);

    uint32_t ccr = (uint32_t)MS_TO_TICKS(timeMs);
    TimerUpdateCompareValue(myTimers[3].TimerCfg->TimerNumber, ccr);
}


void __isr_tim2(void)
{
    // Clear the update interrupt flag
    TimerSetDmaAndInterruptSt(TIMER_STATUS_UPDATEINTER, 0);
    isr_occured = 1;
    tickCnt++;
}