#ifndef STM32_LL_TIMERS_H
#define STM32_LL_TIMERS_H

#include <stm32l433xx.h>
#include <stdbool.h>
typedef enum
{
    TIMER_OPR_FAILED,
    TIMER_OPR_SUCCESS
}TimerError_t;

typedef enum
{
    COUNTER_ENABLE=TIM_CR1_CEN_Pos,
    UPDATE_EVT_DISABLE=TIM_CR1_UDIS_Pos,
    UPDATE_RQST_SRC=TIM_CR1_URS_Pos,
    ONE_PULSE_MODE=TIM_CR1_OPM_Pos,
    TIMER_DIR_MODE=TIM_CR1_DIR_Pos,
    TIMER_COUNTER_MODE=TIM_CR1_CMS_Pos,
    TIMER_AUTO_REL_EN=TIM_CR1_ARPE_Pos,
    TIMER_CLK_DIV=TIM_CR1_CKD_Pos,
    TIMER_UIF_REMAP=TIM_CR1_UIFREMAP_Pos,

}TimerControl1RegPos_t;

typedef enum
{
    TIMER_CC_DMASEL=TIM_CR2_CCDS_Pos,
    TIMER_MASTERMODE_SEL=TIM_CR2_MMS_Pos,
    TIMER_INPUT_SEL=TIM_CR2_TI1S_Pos,
    
}TimerControl2RegPos_t;

typedef enum
{
    TIMER_SLAVE_MOD_SEL=TIM_SMCR_SMS_Pos,
    TIMER_SLAVE_OCCS_SEL=TIM_SMCR_OCCS_Pos,
    TIMER_SLAVE_TRIG_SEL=TIM_SMCR_TS_Pos,
    TIMER_MASTERSLAVE_SYNC=TIM_SMCR_MSM_Pos,
    TIMER_SLAVE_EXTTRIG_FILTER=TIM_SMCR_ETF_Pos,
    TIMER_SLAVE_EXT_PRESCLAER=TIM_SMCR_ETPS_Pos,
    TIMER_SLAVE_EXTCLK_ENABLE=TIM_SMCR_ECE_Pos,
    TIMER_SLAVE_EXT_TRIG_POL=TIM_SMCR_ETP_Pos,
}TimerSlaveModCtrlReg_t;

typedef enum
{
    TIMER_UPDATEINTER_ENABLE=TIM_DIER_UIE_Pos,
    TIMER_CNTCMP1_INTER_ENABLE=TIM_DIER_CC1IE_Pos,
    TIMER_CNTCMP2_INTER_ENABLE=TIM_DIER_CC2IE_Pos,
    TIMER_CNTCMP3_INTER_ENABLE=TIM_DIER_CC3IE_Pos,
    TIMER_CNTCMP4_INTER_ENABLE=TIM_DIER_CC4IE_Pos,
    TIMER_TRIGINTER_ENABLE=TIM_DIER_TIE_Pos,
    TIMER_DMARQST_ENABLE=TIM_DIER_UDE_Pos,
    TIMER_CNTCMP1_DMA_ENABLE=TIM_DIER_CC1DE_Pos,
    TIMER_CNTCMP2_DMA_ENABLE=TIM_DIER_CC2DE_Pos,
    TIMER_CNTCMP3_DMA_ENABLE=TIM_DIER_CC3DE_Pos,
    TIMER_CNTCMP4_DMA_ENABLE=TIM_DIER_CC4DE_Pos,
    TIMER_TRIG_DMA_ENABLE=TIM_DIER_TDE_Pos,

}TimerDmaIntrReg_t;

typedef enum
{
    TIMER_STATUS_UPDATEINTER = TIM_SR_UIF_Pos,
    TIMER_STATUS_CAPCMP1 = TIM_SR_CC1IF_Pos,
    TIMER_STATUS_CAPCMP2 = TIM_SR_CC2IF_Pos,
    TIMER_STATUS_CAPCMP3 = TIM_SR_CC3IF_Pos,
    TIMER_STATUS_CAPCMP4 = TIM_SR_CC4IF_Pos,
    TIMER_STATUS_TRIGINTER = TIM_SR_TIF_Pos,
    TIMER_STATUS_OVERCAP1 = TIM_SR_CC1OF_Pos,
    TIMER_STATUS_OVERCAP2 = TIM_SR_CC2OF_Pos,
    TIMER_STATUS_OVERCAP3 = TIM_SR_CC3OF_Pos,
    TIMER_STATUS_OVERCAP4 = TIM_SR_CC4OF_Pos,
}TimerStatusReg_t;

typedef enum
{
    TIMER_EVT_UG=TIM_EGR_UG_Pos,
    TIMER_EVT_CC1G=TIM_EGR_CC1G_Pos,
    TIMER_EVT_CC2G=TIM_EGR_CC2G_Pos,
    TIMER_EVT_CC3G=TIM_EGR_CC3G_Pos,
    TIMER_EVT_CC4G=TIM_EGR_CC4G_Pos,
    TIMER_EVT_TRG=TIM_EGR_TG_Pos,

}TimerEvtGenReg_t;

typedef enum
{
    TIMER_CNTCMP_SEL1=TIM_CCMR1_CC1S_Pos,
    TIMER_CAP_PRESCA1= TIM_CCMR1_IC1PSC_Pos,
    TIMER_CAPFILTER1 = TIM_CCMR1_IC1F_Pos,

    TIMER_CNTCMP_SEL2=TIM_CCMR1_CC2S_Pos,
    TIMER_CAP_PRESCA2 = TIM_CCMR1_IC2PSC_Pos,
    TIMER_CAPFILTER2 = TIM_CCMR1_IC2F_Pos,    
}TimerModeInputCaptureReg1_t;

typedef enum
{
    TIMER_CNTCMP_SEL3=TIM_CCMR2_CC3S_Pos,
    TIMER_CAP_PRESCA3 = TIM_CCMR2_IC3PSC_Pos,
    TIMER_CAPFILTER3= TIM_CCMR2_IC3F_Pos,

    TIMER_CNTCMP_SEL4=TIM_CCMR2_CC4S_Pos,
    TIMER_CAP_PRESCA4 = TIM_CCMR2_IC4PSC_Pos,
    TIMER_CAPFILTER4= TIM_CCMR2_IC4F_Pos,    
}TimerModeInputCaptureReg2_t;

typedef enum
{
    TIMER_OUTPUT_CMPSEL1=TIM_CCMR1_CC1S_Pos,
    TIMER_OUTPUT_CMP_FASTEN1 = TIM_CCMR1_OC1FE_Pos,
    TIMER_OUTPUT_PRELOAD_EN1=TIM_CCMR1_OC1PE_Pos,
    TIMER_OUTPUT_CMPMODE1=TIM_CCMR1_OC1M_Pos,
    TIMER_OUTPUT_CMPCLR_EN1=TIM_CCMR1_OC1CE_Pos,

    TIMER_OUTPUT_CMPSEL2=TIM_CCMR1_CC2S_Pos,
    TIMER_OUTPUT_CMP_FASTEN2 = TIM_CCMR1_OC2FE_Pos,
    TIMER_OUTPUT_PRELOAD_EN2=TIM_CCMR1_OC2PE_Pos,
    TIMER_OUTPUT_CMPMODE2=TIM_CCMR1_OC2M_Pos,
    TIMER_OUTPUT_CMPCLR_EN2=TIM_CCMR1_OC2CE_Pos,
}TimerOutputCompareReg1_t;

typedef enum
{
    TIMER_OUTPUT_CMPSEL3=TIM_CCMR2_CC3S_Pos,
    TIMER_OUTPUT_CMP_FASTEN3 = TIM_CCMR2_OC3FE_Pos,
    TIMER_OUTPUT_PRELOAD_EN3=TIM_CCMR2_OC3PE_Pos,
    TIMER_OUTPUT_CMPMODE3=TIM_CCMR2_OC3M_Pos,
    TIMER_OUTPUT_CMPCLR_EN3=TIM_CCMR2_OC3CE_Pos,

    TIMER_OUTPUT_CMPSEL4=TIM_CCMR2_CC4S_Pos,
    TIMER_OUTPUT_CMP_FASTEN4 = TIM_CCMR2_OC4FE_Pos,
    TIMER_OUTPUT_PRELOAD_EN4=TIM_CCMR2_OC4PE_Pos,
    TIMER_OUTPUT_CMPMODE4=TIM_CCMR2_OC4M_Pos,
    TIMER_OUTPUT_CMPCLR_EN4=TIM_CCMR2_OC4CE_Pos,
}TimerOutputCompareReg2_t;


typedef enum
{
    TIMER_CNTCMP_OUTPUT_EN1 = TIM_CCER_CC1E_Pos,
    TIMER_CNTCMP_POSTIVE1=TIM_CCER_CC1P_Pos,
    TIMER_CNTCMP_NEGATIVE1 = TIM_CCER_CC1NP_Pos,

    TIMER_CNTCMP_OUTPUT_EN2 = TIM_CCER_CC2E_Pos,
    TIMER_CNTCMP_POSTIVE2=TIM_CCER_CC2P_Pos,
    TIMER_CNTCMP_NEGATIVE2 = TIM_CCER_CC2NP_Pos,

    TIMER_CNTCMP_OUTPUT_EN3 = TIM_CCER_CC3E_Pos,
    TIMER_CNTCMP_POSTIVE3=TIM_CCER_CC3P_Pos,
    TIMER_CNTCMP_NEGATIVE3 = TIM_CCER_CC3NP_Pos,

    TIMER_CNTCMP_OUTPUT_EN4 = TIM_CCER_CC4E_Pos,
    TIMER_CNTCMP_POSTIVE4=TIM_CCER_CC4P_Pos,
    TIMER_CNTCMP_NEGATIVE4 = TIM_CCER_CC4NP_Pos,
}TimerCapCmpReg_t;


typedef enum
{
    TIMER_DMA_BASEADDR=TIM_DCR_DBA_Pos,
    TIMER_DMA_BURSTLEN = TIM_DCR_DBL_Pos,
}TimerDmaControlReg_t;

typedef enum
{
    TIMER2_REMAP_INTERNAL_ENABLE=TIM2_OR1_ITR1_RMP_Pos,
    TIMER2_REMAP_EXTERNAL_ENABLE=TIM2_OR1_ETR1_RMP_Pos,
    TIMER_INPUT4_REMAP=TIM2_OR1_TI4_RMP_Pos,
}Timer2OptionReg1_t;

typedef enum
{
    TIMER2_EXTERN_TRIG_SRCSEL=TIM2_OR2_ETRSEL_Pos,
}Timer2OptionReg2_t;


TimerError_t TimerConfigureControlRegister1(TimerControl1RegPos_t BitPos , uint8_t Cfg);

TimerError_t TimerConfigureControlRegister2(TimerControl1RegPos_t BitPos , bool En);

TimerError_t TimerConfigureMasterMode(uint8_t MasterConfig);

TimerError_t TimerSetSampleRate(uint8_t SampleRate);

TimerError_t TimerSetCounterMode(uint8_t CounterMode);

TimerError_t TimerConfigureSlaveModeRegister(TimerSlaveModCtrlReg_t BitPos , uint8_t slaveconfig);

TimerError_t TimerConfigureDmaAndInterrupts(TimerDmaIntrReg_t BitPos , uint8_t Cfg);

TimerError_t TimerGetDmaAndInterruptSt(TimerStatusReg_t BitPos , uint8_t *Cfg);

TimerError_t TimerConfigureEvtGenRegister(TimerEvtGenReg_t BitPos , uint8_t Cfg);

TimerError_t TimerConfigureInputCaptureReg1(TimerModeInputCaptureReg1_t BitPos , uint8_t Cfg);

TimerError_t TimerConfigureInputCaptureReg2(TimerModeInputCaptureReg2_t BitPos , uint8_t Cfg);

TimerError_t TimerConfigureOutputCompReg1(TimerOutputCompareReg1_t BitPos , uint8_t Cfg);

TimerError_t TimerConfigureOutputCompReg2(TimerOutputCompareReg2_t BitPos , uint8_t Cfg);

TimerError_t TimerCounterCompareEnable(TimerCapCmpReg_t BitPos , uint8_t Cfg);

TimerError_t TimerUpdateCountValue(uint32_t TimerCnt);

TimerError_t TimerUpdatePrescale(uint16_t PrescalerValue);

TimerError_t TimerUpdateAutoReloadCount(uint32_t AutoReloadCount);

TimerError_t TimerUpdateCompareValue(uint8_t TimerCnt,uint32_t CompareValue);

TimerError_t TimerConfigureDmaSettings(TimerDmaControlReg_t BitPos , uint8_t RegValue);

TimerError_t TimerConfigFullTransferAddr(uint16_t RegValue);

TimerError_t TimerConfigOptionReg1(Timer2OptionReg1_t BitPos , uint8_t Cfg);

TimerError_t TimerConfigOptionReg2(Timer2OptionReg2_t BitPos , uint8_t Cfg);

#endif /* STM32_LL_TIMERS_H */
