#include "stm32_ll_timers_cfg.h"
#include "stm32_ll_timers.h"
#include "servo.h"

TimerSpecificConfigs_t ServoTimer = {
    .MasterModeTrigout = COUNTER_UP,
    .SampleRate = TIMER_SAMPLE_DIV1,
    .TimerOutPolarity = TIMER_ACTIVE_HIGH,
    .ExtPrescaler = PRESCALER_OFF,
    .CntMode = CENTER_ALIGNED_UP,
    .UpdateEventGen = UPDATE_EVT_ENABLED,
    .CntDirection = COUNTER_UP,
    .IsrEn = 1,
    .IsrPrio = 56
};


ChannelSpecificConfigs_t ServoTopChannel = {
    .TimerNumber = TIMER_CH1,
    .TimerType = TIMER_OUTPUT_COMPARE,
    .OutCmpMode = TIMER_OUT_PWM_MODE1,
    .TimerCompareValue = 79,
};

ChannelSpecificConfigs_t ServoMiddleChannel = {
    .TimerNumber = TIMER_CH2,
    .TimerType = TIMER_OUTPUT_COMPARE,
    .OutCmpMode = TIMER_OUT_PWM_MODE1,
    .TimerCompareValue = 79,
};

ChannelSpecificConfigs_t ServoBottomChannel = {
    .TimerNumber = TIMER_CH3,
    .TimerType = TIMER_OUTPUT_COMPARE,
    .OutCmpMode = TIMER_OUT_PWM_MODE1,
    .TimerCompareValue = 79,
};

ChannelSpecificConfigs_t ServoHandChannel = {
    .TimerNumber = TIMER_CH4,
    .TimerType = TIMER_OUTPUT_COMPARE,
    .OutCmpMode = TIMER_OUT_PWM_MODE1,
    .TimerCompareValue = 79,
};




void ServoInit(void)
{
    TimerInit(&ServoTimer,&ServoTopChannel,TIMER_PRESCALER, TIMER_ARRVALUE);
    TimerInit(&ServoTimer,&ServoBottomChannel,TIMER_PRESCALER, TIMER_ARRVALUE);
    TimerInit(&ServoTimer,&ServoHandChannel,TIMER_PRESCALER, TIMER_ARRVALUE);
    TimerInit(&ServoTimer,&ServoMiddleChannel,TIMER_PRESCALER, TIMER_ARRVALUE);
}

void TurnServo(float angle,uint8_t chIdx)
{
    float timeMs=0.f;

    timeMs = (float)SERVOANGLE_TOMS(angle);

    uint32_t ccr = (uint32_t)MS_TO_TICKS(timeMs);
    TimerUpdateCompareValue(ServoTopChannel.TimerNumber, ccr);
}
