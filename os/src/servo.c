#include "stm32_ll_timers_cfg.h"
#include "stm32_ll_timers.h"
#include "servo.h"


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


void ServoInit(void)
{
    TimerInit(myTimers,TIMER_PRESCALER, TIMER_ARRVALUE);
}

void TurnServo(float angle,uint8_t chIdx)
{
    float timeMs=0.f;

    timeMs = (float)SERVOANGLE_TOMS(angle);

    uint32_t ccr = (uint32_t)MS_TO_TICKS(timeMs);
    TimerUpdateCompareValue(myTimers[chIdx].TimerCfg->TimerNumber, ccr);
}
