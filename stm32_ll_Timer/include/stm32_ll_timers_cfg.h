#ifndef STM32_LL_TIMERS_CFG_H
#define STM32_LL_TIMERS_CFG_H

#include <stdint.h>

typedef enum
{
    ENABLED_SET,
    DISABLED_RESET
}Enable_t;

typedef enum
{
    TIMER_CH1=1,
    TIMER_CH2,
    TIMER_CH3,
    TIMER_CH4,
}TimerChannel_t;
// Your code here
typedef enum
{
    TIMER_OUTPUT_COMPARE,
    TIMER_INPUT_CAPTURE_MODE1,
    TIMER_INPUT_CAPTURE_MODE2,
    TIMER_INPUT_CAPTURE_MODE3,
}Timer_t;

typedef enum
{
    COUNTER_UP,
    COUNTER_DOWN,
    COUNTER_UP_DOWN
}Dir_t;

typedef enum
{
    EDGE_ALIGNED,
    CENTER_ALIGNED_UP,
    CENTER_ALIGNED_DOWN,
    CENTER_ALIGNED_UP_DOWN,
}Mode_t;

typedef enum
{
    TIMER_SAMPLE_DIV1,
    TIMER_SAMPLE_DIV2,
    TIMER_SAMPLE_DIV4,
    TIMER_SAMPLE_INVALID,
}ClockDivFilters_t;

typedef enum
{
    TIMER_ACTIVE_HIGH,
    TIMER_ACTIVE_LOW
}TimerPolarity_t;

typedef enum
{
    TIMER_OUT_FROZEN,
    TIMER_OUT_SET_ONMATCH,
    TIMER_OUT_RESET_ONMATCH,
    TIMER_OUT_TOGGLE_ONMATCH,
    TIMER_OUT_FORCE_ON,
    TIMER_OUT_FORCE_OFF,
    TIMER_OUT_PWM_MODE1,
    TIMER_OUT_RETRIGGERABLE_MODE1,
    TIMER_OUT_RETRIGGERABLE_MODE2,
    TIMER_RESERVED1,
    TIMER_RESERVED2,
    TIMER_COMBINED_PWM1,
    TIMER_COMBINED_PWM2,
    TIMER_ASYMMETRIC_PWM1,
    TIMER_ASYMMETRIC_PWM2,
    TIMER_INVALID,
}OutputCmpMode_t;

typedef enum
{
   UPDATE_EVT_ENABLED,
   UPDATE_EVT_DISABLED
}UpdateEventGen_t;

typedef enum
{
    TRGOUT_UG,
    TRGOUT_CNT_EN,
    TRGOUT_UPDATE_EVT,
    TRGOUT_CNT_CMP_MATCH,
    TRGOUT_OUT_CMP_REF1_CLEAR,
    TRGOUT_OUT_CMP_REF2_CLEAR,
    TRGOUT_OUT_CMP_REF3_CLEAR,
    TRGOUT_OUT_CMP_REF4_CLEAR,
}Master_TrgOut_t;

typedef enum
{
    DMA_EVT_ON_CNTCMP,
    DMA_EVT_ON_UG,
}DmaEvt_t;

typedef enum
{
    SLAVE_MODE_DISABLED,
    SLAVE_ENCODER_MODE1,
    SLAVE_ENCODER_MODE2,
    SLAVE_ENCODER_MODE3,
    SLAVE_RESET_MODE,
    SLAVE_GATED_MODE,
    SLAVE_TRIGGER_MODE,
    SLAVE_EXTCLK_MODE,
    SLAVE_COMBINED_MODE,
}SlaveMode_t;

typedef enum
{
    INTERNAL_TRIGGER0,
    INTERNAL_TRIGGER1,
    TIMER_EDGEINPUT1,
    FILTERED_INPUT1,
    FILTERED_INPUT2,
    EXTERNAL_TRIGGER1,
}SlaveInputTriggerSel_t;

typedef enum
{
    PRESCALER_OFF,
    EXTERNAL_DIVBY2,
    EXTERNAL_DIVBY4,
    EXTERNAL_DIVBY8,
}ExtPrescaler_t;

typedef struct 
{
    DmaEvt_t DmaEvt;
    uint8_t Trig_Evt_Dma_En;
    uint8_t Trig_Upd_Dma_En;
    uint8_t Trig_Cmp_Dma_En;
}DmaCfg_t;

typedef struct 
{
    Enable_t IsrEn;
    uint8_t IsrPrio;

}TimerIsr_t;

typedef struct
{
  Enable_t ArrEn;  
  uint32_t AutoReloadValue;
  uint32_t TimerCompareValue;
  uint16_t TimerPrescaler;
}ArrCfg_t;

typedef struct
{
    TimerChannel_t TimerNumber;
    Master_TrgOut_t MasterModeTrigout;
    ClockDivFilters_t SampleRate;
    TimerPolarity_t TimerOutPolarity;
    Timer_t TimerType;
    SlaveMode_t SlaveMode;
    SlaveInputTriggerSel_t InputTrigger;
    ExtPrescaler_t ExtPrescaler;
    
}TimerChannelCfg_t;

typedef struct 
{
    TimerChannelCfg_t *TimerCfg;
    ArrCfg_t *AutoReloadSetting;
    DmaCfg_t *DmaCfg;
    TimerIsr_t *IsrData;
    OutputCmpMode_t OutCmpMode;
    Dir_t CntDirection;
    Mode_t CntMode;
    UpdateEventGen_t UpdateEventGen;
    
}TimerCfg_t;

void PwmInit(void);
void LedFade(void);
#endif // STM32_LL_TIMERS_CFG_H

