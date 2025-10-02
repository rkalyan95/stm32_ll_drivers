#ifndef STM32_LL_TIMERS_CFG_H
#define STM32_LL_TIMERS_CFG_H

#include <stdint.h>
#include <stdbool.h>

extern uint8_t ledisr;
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
    TIMER_MAX_CHANNEL,
}TimerChannel_t;
// Your code here
typedef enum
{
    TIMER_OUTPUT_COMPARE,
    INPUT_CAPTURE_FALLING_EDGE,
    INPUT_CAPTURE_RISING_EDGE,
    INPUT_CAPTURE_BOTH_EDGES,
}TimerInputOutput_t;

typedef enum
{
    OUTPUT_COMPARE,
    INPUT_CAPTURE_TI1,
    INPUT_CAPTURE_TI2,
    INPUT_CAPTURE_TRGI,
    
}CapCompareMapping_t;

typedef enum
{
    COUNTER_UP,
    COUNTER_DOWN,
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
    TIMER_OUT_PWM_MODE2,
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

typedef enum
{
    NO_FILTER,                          // 0000: No filter, sampling is done
    FSAMPLING_FCK_INT_N2,               // 0001: fSAMPLING=fCK_INT, N=2
    FSAMPLING_FCK_INT_N4,               // 0010: fSAMPLING=fCK_INT, N=4
    FSAMPLING_FCK_INT_N8,               // 0011: fSAMPLING=fCK_INT, N=8
    FSAMPLING_FDTS_DIV2_N6,             // 0100: fSAMPLING=fDTS/2, N=6
    FSAMPLING_FDTS_DIV2_N8,             // 0101: fSAMPLING=fDTS/2, N=8
    FSAMPLING_FDTS_DIV4_N6,             // 0110: fSAMPLING=fDTS/4, N=6
    FSAMPLING_FDTS_DIV4_N8,             // 0111: fSAMPLING=fDTS/4, N=8
    FSAMPLING_FDTS_DIV8_N6,             // 1000: fSAMPLING=fDTS/8, N=6
    FSAMPLING_FDTS_DIV8_N8,             // 1001: fSAMPLING=fDTS/8, N=8
    FSAMPLING_FDTS_DIV16_N5,            // 1010: fSAMPLING=fDTS/16, N=5
    FSAMPLING_FDTS_DIV16_N6,            // 1011: fSAMPLING=fDTS/16, N=6
    FSAMPLING_FDTS_DIV16_N8,            // 1100: fSAMPLING=fDTS/16, N=8
    FSAMPLING_FDTS_DIV32_N5,            // 1101: fSAMPLING=fDTS/32, N=5
    FSAMPLING_FDTS_DIV32_N6,            // 1110: fSAMPLING=fDTS/32, N=6
    FSAMPLING_FDTS_DIV32_N_NO_VALUE     // 1111: fSAMPLING=fDTS/32, N=  
}InputCapFilter_t;


typedef struct 
{
    DmaEvt_t DmaEvt;
    uint8_t Trig_Evt_Dma_En;
    uint8_t Trig_Upd_Dma_En;
    uint8_t Trig_Cmp_Dma_En;
}DmaCfg_t;


typedef struct
{
    
    ClockDivFilters_t SampleRate;
    Master_TrgOut_t MasterModeTrigout;
    TimerPolarity_t TimerOutPolarity;
    Mode_t CntMode;
    Dir_t CntDirection;
    UpdateEventGen_t UpdateEventGen;
    SlaveMode_t SlaveMode;
    SlaveInputTriggerSel_t InputTrigger;
    ExtPrescaler_t ExtPrescaler;
    Enable_t IsrEn;
    uint8_t IsrPrio;
    
}TimerSpecificConfigs_t;


typedef struct
{
    TimerInputOutput_t TimerType;
    CapCompareMapping_t CapCompareMapping;
    TimerChannel_t TimerNumber;
    InputCapFilter_t InputCapturFilter;
    OutputCmpMode_t OutCmpMode;
    uint32_t TimerCompareValue;
}ChannelSpecificConfigs_t;

uint8_t GetFeedbackValues(uint8_t timerchanIdx , float *dutycycle);
//void TimerInit(TimerCfg_t *TimerCfg,uint16_t pre , uint32_t arrvalue);
void TimerInit(TimerSpecificConfigs_t *TimerCfg,ChannelSpecificConfigs_t *ChannelCfg,uint16_t pre , uint32_t arrvalue);
#endif // STM32_LL_TIMERS_CFG_H

