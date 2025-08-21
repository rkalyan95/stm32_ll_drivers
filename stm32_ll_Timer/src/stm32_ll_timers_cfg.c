#include "stm32_ll_timers_cfg.h"
#include "stm32_ll_timers.h"

#define OUTPUT_TIMER_TEST 

volatile static bool isr_occured=0;
TimerChannelCfg_t TimerMaster = {
    .TimerNumber = TIMER_CH1,
    .MasterModeTrigout = COUNTER_UP,
    .SampleRate = TIMER_SAMPLE_DIV1,
    .TimerOutPolarity = TIMER_ACTIVE_HIGH,
    .TimerType = TIMER_OUTPUT_COMPARE,
    .ExtPrescaler = PRESCALER_OFF,
};

ArrCfg_t ArrCfg = {
    .AutoReloadValue = 83,
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
        .TimerCfg = &TimerMaster,
        .AutoReloadSetting = &ArrCfg,
        .IsrData = &TimerIsr,
        .DmaCfg = &DmaSetting,
        .OutCmpMode = TIMER_OUT_PWM_MODE1,
        .CntDirection = COUNTER_UP,
        .CntMode = EDGE_ALIGNED,
        .UpdateEventGen = UPDATE_EVT_ENABLED,
        
    }
};

static void ConfigureOutputSettings(TimerCfg_t *TimerCfg)
{
    // Configure basic timer parameters
    TimerUpdatePrescale(TimerCfg[0].AutoReloadSetting->TimerPrescaler);        // Set the prescaler value
    TimerUpdateAutoReloadCount(TimerCfg[0].AutoReloadSetting->AutoReloadValue);       // Set the period (Auto-Reload Register)

    // Basic CR1 settings (if not already handled by specialized functions)
    TimerConfigureControlRegister1(TIMER_AUTO_REL_EN, TimerCfg[0].AutoReloadSetting->ArrEn); // Enable auto-reload preload
    TimerSetCounterMode(TimerCfg[0].CntDirection);                              // Set up-counting mode (0)
    TimerConfigureControlRegister1(TIMER_DIR_MODE, TimerCfg[0].CntMode);   // Set direction to up-counting (0)
    TimerSetSampleRate(TimerCfg[0].TimerCfg->SampleRate);                               // Set clock division to 0 (no division)

    
}


static void ConfigureTimerChannel(TimerCfg_t *TimerCfg)
{
    switch(TimerCfg[0].TimerCfg->TimerNumber)
    {
        case TIMER_CH1:
            if(TimerCfg[0].TimerCfg->TimerType==TIMER_OUTPUT_COMPARE)
            {
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPSEL1, TimerCfg[0].TimerCfg->TimerType); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPMODE1, TimerCfg[0].OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(TimerCfg[0].TimerCfg->TimerNumber, TimerCfg[0].AutoReloadSetting->TimerCompareValue);                 // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE1, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN1, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                TimerConfigureInputCaptureReg1(TIMER_CNTCMP_SEL1,TimerCfg[0].TimerCfg->TimerType);
            }
            break;
        case TIMER_CH2:
            if(TimerCfg[0].TimerCfg->TimerType==TIMER_OUTPUT_COMPARE)
            {
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPSEL2, TimerCfg[0].TimerCfg->TimerType); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg1(TIMER_OUTPUT_CMPMODE2, TimerCfg[0].OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(TimerCfg[0].TimerCfg->TimerNumber, TimerCfg[0].AutoReloadSetting->TimerCompareValue);                 // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE2, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN2, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                
            }
            break;
        case TIMER_CH3:
            if(TimerCfg[0].TimerCfg->TimerType==TIMER_OUTPUT_COMPARE)
            {
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPSEL3, TimerCfg[0].TimerCfg->TimerType); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPMODE3, TimerCfg[0].OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(TimerCfg[0].TimerCfg->TimerNumber, TimerCfg[0].AutoReloadSetting->TimerCompareValue);                 // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE3, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN3, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                
            }
            break;
        case TIMER_CH4:
            if(TimerCfg[0].TimerCfg->TimerType==TIMER_OUTPUT_COMPARE)
            {
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPSEL4, TimerCfg[0].TimerCfg->TimerType); // Select output compare mode (0 usually for output)
                TimerConfigureOutputCompReg2(TIMER_OUTPUT_CMPMODE4, TimerCfg[0].OutCmpMode); // Set PWM Mode 1 (0x06 for 0b110)
                // Configure Output Compare Channel 1 for PWM
                TimerUpdateCompareValue(TimerCfg[0].TimerCfg->TimerNumber, TimerCfg[0].AutoReloadSetting->TimerCompareValue);                 // Set the compare value for Channel 1
                TimerCounterCompareEnable(TIMER_CNTCMP_POSTIVE4, 0); // Set Channel 1 polarity to Active High (0)
                TimerCounterCompareEnable(TIMER_CNTCMP_OUTPUT_EN4, 1); // Enable Capture/Compare Channel 1 output
            }
            else
            {
                
            }
            break;        
    }


}

static void ConfigureChannelDmaEvtInterrupts(TimerCfg_t *TimerCfg)
{
    // Generate an update event to load all configured values into active registers
    // Use the specific bit position for the Update Generation event (UG)
    TimerConfigureEvtGenRegister(TIMER_EVT_UG, TimerCfg[0].UpdateEventGen);
    TimerConfigureDmaAndInterrupts(TIMER_STATUS_UPDATEINTER,1);
}

static void TimerInit(TimerCfg_t *TimerCfg)
{
    /*Disable counter first to configure safely*/ 
    TimerConfigureControlRegister1(COUNTER_ENABLE, 0);

    ConfigureOutputSettings(TimerCfg);
    ConfigureTimerChannel(TimerCfg);
    ConfigureChannelDmaEvtInterrupts(TimerCfg);

    // Finally, enable the timer counter
    TimerConfigureControlRegister1(COUNTER_ENABLE, 1);

    NVIC_SetPriority(TIM2_IRQn, TimerCfg[0].IsrData->IsrPrio);
    NVIC_EnableIRQ(TIM2_IRQn);      // Enable the interrupt in the NVIC
}

void PwmInit(void)
{
    TimerInit(&myTimers[0]);
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
    if (direction == 1 && ccr >= myTimers[0].AutoReloadSetting->AutoReloadValue) {
        ccr = myTimers[0].AutoReloadSetting->AutoReloadValue;
        direction = -1;
    } else if (direction == -1 && ccr == 0) {
        direction = 1;
    }

    // Apply the new compare value
    TimerUpdateCompareValue(1, ccr);
}
}

void __isr_tim2(void)
{
    // Clear the update interrupt flag
    TimerSetDmaAndInterruptSt(TIMER_STATUS_UPDATEINTER, 0);
    isr_occured = 1;
}