#include "stm32_ll_timers.h"
#include "common.h"
#include <stdint.h>

/**
 * @file stm32_ll_timers.c
 * @brief Source file for the functions to work with the timers of the microcontroller.
 */

/**
 * @brief This function configures the first control register of the Timer.
 * @param[in] BitPos: The bit position of the register to be configured.
 * @param[in] Cfg: 8-bit value to be configured.
 * @return TimerError_t Enum value indicating the status of the operation.
 */

TimerError_t TimerConfigureControlRegister1(TimerControl1RegPos_t BitPos , uint8_t Cfg)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;

    switch(BitPos)
    {
        case COUNTER_ENABLE:
        case UPDATE_EVT_DISABLE:
        case UPDATE_RQST_SRC:
        case ONE_PULSE_MODE:
        case TIMER_DIR_MODE:
        case TIMER_AUTO_REL_EN:
            ((Cfg&0x01)==1)?SET(TIM2->CR1,BitPos):CLEAR(TIM2->CR1,BitPos);
            TimerErrorStatus = (GET(TIM2->CR1,BitPos) == Cfg&0x01);
            break;
        case TIMER_COUNTER_MODE:
            SET_BITS(TIM2->CR1,BitPos,2,Cfg&0x03);
            TimerErrorStatus = (GET_BITS(TIM2->CR1,BitPos,2)==Cfg&0x03);
            break;
        case TIMER_CLK_DIV:
            SET_BITS(TIM2->CR1,BitPos,2,Cfg&0x03);
            TimerErrorStatus = (GET_BITS(TIM2->CR1,BitPos,2)==Cfg&0x03);
            break;
        default:
    }

    return TimerErrorStatus;
}

/**
 * @brief This function configures the second control register of the Timer.
 * @param[in] BitPos: The bit position of the register to be configured.
 * @param[in] En: true to enable, false to disable.
 * @return TimerError_t Enum value indicating the status of the operation.
 */

TimerError_t TimerConfigureControlRegister2(TimerControl1RegPos_t BitPos , bool En)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    if(BitPos != TIMER_MASTERMODE_SEL)
    {
        (En==1)?SET(TIM2->CR2,BitPos):CLEAR(TIM2->CR2,BitPos);
        TimerErrorStatus = (GET(TIM2->CR2,BitPos) == En);
    }
    return TimerErrorStatus;

}


TimerError_t TimerConfigureMasterMode(uint8_t MasterConfig)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    SET_BITS(TIM2->CR2,TIMER_MASTERMODE_SEL,3,MasterConfig & 0x07);
    TimerErrorStatus = (GET_BITS(TIM2->CR2,TIMER_MASTERMODE_SEL,3) == MasterConfig & 0x07);
    return TimerErrorStatus;
}


TimerError_t TimerSetSampleRate(uint8_t SampleRate)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    SET_BITS(TIM2->CR1,TIMER_CLK_DIV,2,SampleRate & 0x03);
    TimerErrorStatus = (GET_BITS(TIM2->CR1,TIMER_CLK_DIV,2) == SampleRate & 0x03);
    return TimerErrorStatus;

}

TimerError_t TimerSetCounterMode(uint8_t CounterMode)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    SET_BITS(TIM2->CR1,TIMER_COUNTER_MODE,2,CounterMode & 0x03);
    TimerErrorStatus = (GET_BITS(TIM2->CR1,TIMER_COUNTER_MODE,2) == CounterMode & 0x03);
    return TimerErrorStatus;

}



/************************************************Slave mode control register ******************************************************/

TimerError_t TimerConfigureSlaveModeRegister(TimerSlaveModCtrlReg_t BitPos , uint8_t slaveconfig)
{

    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;

    switch(BitPos)
    {
        case TIMER_SLAVE_MOD_SEL: // Multi-bit field (SMS)
            SET_BITS(TIM2->SMCR,TIMER_SLAVE_MOD_SEL,3,slaveconfig & 0x07);
            SET_BITS(TIM2->SMCR,TIMER_SLAVE_MOD_SEL+16,1,((slaveconfig & 0x80)>>3));
            TimerErrorStatus = ((GET_BITS(TIM2->SMCR,TIMER_SLAVE_MOD_SEL,3) == (slaveconfig & 0x07)) &&
                                (GET_BITS(TIM2->SMCR,TIMER_SLAVE_MOD_SEL+16,1) == ((slaveconfig & 0x80)>>3)));
            break;
        case TIMER_SLAVE_EXT_PRESCLAER: // Multi-bit field (ETPS)
            SET_BITS(TIM2->SMCR,TIMER_SLAVE_EXT_PRESCLAER,2,slaveconfig & 0x03);
            TimerErrorStatus = (GET_BITS(TIM2->SMCR,TIMER_SLAVE_EXT_PRESCLAER,2) == (slaveconfig & 0x03));
            break;
        case TIMER_SLAVE_TRIG_SEL: // Multi-bit field (TS)
            SET_BITS(TIM2->SMCR,TIMER_SLAVE_TRIG_SEL,3,slaveconfig & 0x07);
            TimerErrorStatus = (GET_BITS(TIM2->SMCR,TIMER_SLAVE_TRIG_SEL,3) == (slaveconfig & 0x07));
            break;
        case TIMER_SLAVE_EXTTRIG_FILTER: // Multi-bit field (ETF)
            SET_BITS(TIM2->SMCR,TIMER_SLAVE_EXTTRIG_FILTER,4,slaveconfig & 0x0F);
            TimerErrorStatus = (GET_BITS(TIM2->SMCR,TIMER_SLAVE_EXTTRIG_FILTER,4) == (slaveconfig & 0x0F));
            break;
        // Single-bit fields (assuming all others in the enum are single bits)
        case TIMER_SLAVE_OCCS_SEL:
        case TIMER_MASTERSLAVE_SYNC:
        case TIMER_SLAVE_EXTCLK_ENABLE:
        case TIMER_SLAVE_EXT_TRIG_POL:
            ( (slaveconfig & 0x01) == 1 ) ? SET(TIM2->SMCR,BitPos) : CLEAR(TIM2->SMCR,BitPos);
            TimerErrorStatus = (GET(TIM2->SMCR,BitPos) == (slaveconfig & 0x01));
            break;
        default:
            TimerErrorStatus = TIMER_OPR_FAILED;
            break;
    }
    return TimerErrorStatus;

}

/************************************************ Timer DMA and Interrupt ******************************************************/

TimerError_t TimerConfigureDmaAndInterrupts(TimerDmaIntrReg_t BitPos , uint8_t Cfg)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    ((Cfg & 0x01) == 1)?SET(TIM2->DIER,BitPos):CLEAR(TIM2->DIER,BitPos);
    TimerErrorStatus = (GET(TIM2->DIER,BitPos) == (Cfg & 0x01));
    return TimerErrorStatus;
}

/************************************************ Timer Status Registers ******************************************************/

TimerError_t TimerGetDmaAndInterruptSt(TimerStatusReg_t BitPos , uint8_t *Cfg)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    *Cfg = GET(TIM2->SR,BitPos);
    TimerErrorStatus = TIMER_OPR_SUCCESS;
    return TimerErrorStatus;
}

TimerError_t TimerSetDmaAndInterruptSt(TimerStatusReg_t BitPos , uint8_t Cfg)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    (Cfg==1)?SET(TIM2->SR,BitPos):CLEAR(TIM2->SR,BitPos);
    TimerErrorStatus = TIMER_OPR_SUCCESS;
    return TimerErrorStatus;
}
/************************************************ Timer Event Generation Register ******************************************************/
TimerError_t TimerConfigureEvtGenRegister(TimerEvtGenReg_t BitPos , uint8_t Cfg)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    ((Cfg & 0x01) == 1)?SET(TIM2->EGR,BitPos):CLEAR(TIM2->EGR,BitPos);
    TimerErrorStatus = (GET(TIM2->EGR,BitPos) == (Cfg & 0x01));
    return TimerErrorStatus;
}

/************************************************ Timer Input Capture Reg 1 ******************************************************/

TimerError_t TimerConfigureInputCaptureReg1(TimerModeInputCaptureReg1_t BitPos , uint8_t Cfg)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    switch(BitPos)
    {
        case TIMER_CNTCMP_SEL1:
            SET_BITS(TIM2->CCMR1,TIMER_CNTCMP_SEL1,2,Cfg & 0x03);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_CNTCMP_SEL1,2) == Cfg & 0x03);
            break;
        case TIMER_CAP_PRESCA1:
            SET_BITS(TIM2->CCMR1,TIMER_CAP_PRESCA1,2,Cfg & 0x07);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_CAP_PRESCA1,3) == Cfg & 0x03);
            break;
        case TIMER_CAPFILTER1:
            SET_BITS(TIM2->CCMR1,TIMER_CAPFILTER1,4,Cfg & 0x0F);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_CAPFILTER1,4) == Cfg & 0x0F);
            break;
        case TIMER_CNTCMP_SEL2:
            SET_BITS(TIM2->CCMR1,TIMER_CNTCMP_SEL2,2,Cfg & 0x03);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_CNTCMP_SEL2,2) == Cfg & 0x03);
            break;
        case TIMER_CAP_PRESCA2:
            SET_BITS(TIM2->CCMR1,TIMER_CAP_PRESCA2,2,Cfg & 0x07);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_CAP_PRESCA2,2) == Cfg & 0x07);
            break;
        case TIMER_CAPFILTER2:
            SET_BITS(TIM2->CCMR1,TIMER_CAPFILTER2,4,Cfg & 0x0F);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_CAPFILTER2,4) == Cfg & 0x0F);
            break;
        default:
            TimerErrorStatus = TIMER_OPR_FAILED;
            break;

    }

    return TimerErrorStatus;

}

/************************************************ Timer Input Capture Reg 2 ******************************************************/

TimerError_t TimerConfigureInputCaptureReg2(TimerModeInputCaptureReg2_t BitPos , uint8_t Cfg)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    switch(BitPos)
    {
        case TIMER_CNTCMP_SEL3:
            SET_BITS(TIM2->CCMR2,TIMER_CNTCMP_SEL3,2,Cfg & 0x03);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_CNTCMP_SEL3,2) == Cfg & 0x03);
            break;
        case TIMER_CAP_PRESCA3:
            SET_BITS(TIM2->CCMR2,TIMER_CAP_PRESCA3,2,Cfg & 0x07);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_CAP_PRESCA3,2) == Cfg & 0x03);
            break;
        case TIMER_CAPFILTER3:
            SET_BITS(TIM2->CCMR2,TIMER_CAPFILTER3,4,Cfg & 0x0F);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_CAPFILTER3,4) == Cfg & 0x0F);
            break;
        case TIMER_CNTCMP_SEL4:
            SET_BITS(TIM2->CCMR2,TIMER_CNTCMP_SEL4,2,Cfg & 0x03);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_CNTCMP_SEL4,2) == Cfg & 0x03);
            break;
        case TIMER_CAP_PRESCA4:
            SET_BITS(TIM2->CCMR2,TIMER_CAP_PRESCA4,2,Cfg & 0x07);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_CAP_PRESCA4,2) == Cfg & 0x07);
            break;
        case TIMER_CAPFILTER4:
            SET_BITS(TIM2->CCMR2,TIMER_CAPFILTER4,4,Cfg & 0x0F);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_CAPFILTER4,4) == Cfg & 0x0F);
            break;
        default:
            TimerErrorStatus = TIMER_OPR_FAILED;
            break;

    }

    return TimerErrorStatus;

}

/************************************************ Timer Output Compare Reg 1 ******************************************************/

TimerError_t TimerConfigureOutputCompReg1(TimerOutputCompareReg1_t BitPos , uint8_t Cfg)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    switch(BitPos)
    {
        case TIMER_OUTPUT_CMPSEL1:
            SET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPSEL1,2,Cfg & 0x03);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPSEL1,2) == Cfg & 0x03);
            break;
        case TIMER_OUTPUT_CMP_FASTEN1:
            SET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMP_FASTEN1,1,Cfg & 0x01);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMP_FASTEN1,1) == Cfg & 0x01);
            break;
        case TIMER_OUTPUT_PRELOAD_EN1:
            SET_BITS(TIM2->CCMR1,TIMER_OUTPUT_PRELOAD_EN1,1,Cfg & 0x01);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_OUTPUT_PRELOAD_EN1,1) == Cfg & 0x01);
            break;
        case TIMER_OUTPUT_CMPMODE1:
            SET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPMODE1,3,Cfg & 0x07);
            
            SET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPMODE1+12,1,(Cfg & 0x08)>>3);

            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPMODE1,3) == Cfg & 0x07)  &&
                                (GET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPMODE1+12,1) == (Cfg & 0x80)>>7);

            break;
        case TIMER_OUTPUT_CMPCLR_EN1:
            SET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPCLR_EN1,1,Cfg & 0x01);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPCLR_EN1,1) == Cfg & 0x01);
            break;

        case TIMER_OUTPUT_CMPSEL2:
            SET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPSEL2,2,Cfg & 0x03);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPSEL2,2) == Cfg & 0x03);
            break;
        case TIMER_OUTPUT_CMP_FASTEN2:
            SET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMP_FASTEN2,1,Cfg & 0x01);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMP_FASTEN2,1) == Cfg & 0x01);
            break;
        case TIMER_OUTPUT_PRELOAD_EN2:
            SET_BITS(TIM2->CCMR1,TIMER_OUTPUT_PRELOAD_EN2,1,Cfg & 0x01);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_OUTPUT_PRELOAD_EN2,1) == Cfg & 0x01);
            break;
        case TIMER_OUTPUT_CMPMODE2:
            SET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPMODE2,3,Cfg & 0x07);
            
            SET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPMODE2+12,1,(Cfg & 0x08)>>3);

            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPMODE2,3) == Cfg & 0x07);

            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPMODE2+12,1) == (Cfg & 0x80)>>7);
            break;
        case TIMER_OUTPUT_CMPCLR_EN2:
            SET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPCLR_EN2,1,Cfg & 0x01);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR1,TIMER_OUTPUT_CMPCLR_EN2,1) == Cfg & 0x01);
            break;      
        default:
            TimerErrorStatus = TIMER_OPR_FAILED;
    }

    return TimerErrorStatus;


}

/************************************************ Timer Output Compare Reg 2 ******************************************************/

TimerError_t TimerConfigureOutputCompReg2(TimerOutputCompareReg2_t BitPos , uint8_t Cfg)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    switch(BitPos)
    {
        case TIMER_OUTPUT_CMPSEL3:
            SET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPSEL3,2,Cfg & 0x03);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPSEL3,2) == Cfg & 0x03);
            break;
        case TIMER_OUTPUT_CMP_FASTEN3:
            SET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMP_FASTEN3,1,Cfg & 0x01);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMP_FASTEN3,1) == Cfg & 0x01);
            break;
        case TIMER_OUTPUT_PRELOAD_EN3:
            SET_BITS(TIM2->CCMR2,TIMER_OUTPUT_PRELOAD_EN3,1,Cfg & 0x01);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_OUTPUT_PRELOAD_EN3,1) == Cfg & 0x01);
            break;
        case TIMER_OUTPUT_CMPMODE3:
            SET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPMODE3,3,Cfg & 0x07);
            
            SET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPMODE3+12,1,(Cfg & 0x08)>>3);

            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPMODE3,3) == Cfg & 0x07);

            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPMODE3+12,1) == (Cfg & 0x80)>>7);
            break;
        case TIMER_OUTPUT_CMPCLR_EN3:
            SET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPCLR_EN3,1,Cfg & 0x01);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPCLR_EN3,1) == Cfg & 0x01);
            break;

        case TIMER_OUTPUT_CMPSEL4:
            SET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPSEL4,2,Cfg & 0x03);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPSEL4,2) == Cfg & 0x03);
            break;
        case TIMER_OUTPUT_CMP_FASTEN4:
            SET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMP_FASTEN4,1,Cfg & 0x01);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMP_FASTEN4,1) == Cfg & 0x01);
            break;
        case TIMER_OUTPUT_PRELOAD_EN4:
            SET_BITS(TIM2->CCMR2,TIMER_OUTPUT_PRELOAD_EN4,1,Cfg & 0x01);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_OUTPUT_PRELOAD_EN4,1) == Cfg & 0x01);
            break;
        case TIMER_OUTPUT_CMPMODE4:
            SET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPMODE4,3,Cfg & 0x07);
            
            SET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPMODE4+12,1,(Cfg & 0x08)>>3);

            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPMODE4,3) == Cfg & 0x07);

            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPMODE4+12,1) == (Cfg & 0x80)>>7);
            break;
        case TIMER_OUTPUT_CMPCLR_EN4:
            SET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPCLR_EN4,1,Cfg & 0x01);
            TimerErrorStatus = (GET_BITS(TIM2->CCMR2,TIMER_OUTPUT_CMPCLR_EN4,1) == Cfg & 0x01);
            break;      
        default:
            TimerErrorStatus = TIMER_OPR_FAILED;
    }

    return TimerErrorStatus;


}

/************************************************ Timer Counter Compare Enable ******************************************************/


TimerError_t TimerCounterCompareEnable(TimerCapCmpReg_t BitPos , uint8_t Cfg)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;

    ((Cfg & 0x01)==1)?SET(TIM2->CCER,BitPos):CLEAR(TIM2->CCER,BitPos);
    TimerErrorStatus = (GET(TIM2->CCER,BitPos) == (Cfg & 0x01));
    return TimerErrorStatus;

}

/************************************************ Timer Counter Value ******************************************************/
TimerError_t TimerUpdateCountValue(uint32_t TimerCnt)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;

    //Remapping is enabled , hence 31-bit count
    if(GET(TIM2->CR1,TIM_CR1_UIFREMAP_Pos) == 1) 
    {
        TimerCnt &= 0x7FFF;
        SET_BITS(TIM2->CNT,TIM_CNT_CNT_Pos,31,TimerCnt);
        TimerErrorStatus = (GET_BITS(TIM2->CNT,TIM_CNT_CNT_Pos,31)==TimerCnt);
    }
    else
    {
        //Remapping is disabled , hence 32-bit count
        SET_BITS(TIM2->CNT,TIM_CNT_CNT_Pos,32,TimerCnt);
        TimerErrorStatus = (GET_BITS(TIM2->CNT,TIM_CNT_CNT_Pos,32)==TimerCnt);
    }

    return TimerErrorStatus;
}

uint32_t TimerGetCountValue(uint8_t TimerChannelIdx)
{
    uint32_t TimerCnt = 0;
switch(TimerChannelIdx)
{
    case 1:
         TimerCnt = GET_BITS(TIM2->CCR1,TIM_CNT_CNT_Pos,32);
         break;
    case 2:
         TimerCnt = GET_BITS(TIM2->CCR2,TIM_CNT_CNT_Pos,32);
         break;
    case 3:
         TimerCnt = GET_BITS(TIM2->CCR3,TIM_CNT_CNT_Pos,32);
         break;
    case 4:
         TimerCnt = GET_BITS(TIM2->CCR4,TIM_CNT_CNT_Pos,32);
         break;
}
  
    return TimerCnt;
}

/************************************************ Timer Prescaler ******************************************************/

TimerError_t TimerUpdatePrescale(uint16_t PrescalerValue)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    SET_BITS(TIM2->PSC,TIM_PSC_PSC_Pos,16,PrescalerValue);
    TimerErrorStatus = (GET_BITS(TIM2->PSC,TIM_PSC_PSC_Pos,16)==PrescalerValue);
    return TimerErrorStatus;
}


/************************************************ Timer Auto Reload Value ******************************************************/

TimerError_t TimerUpdateAutoReloadCount(uint32_t AutoReloadCount)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    SET_BITS(TIM2->ARR,TIM_ARR_ARR_Pos,32,AutoReloadCount);
    TimerErrorStatus = (GET_BITS(TIM2->ARR,TIM_ARR_ARR_Pos,32)==AutoReloadCount);
    return TimerErrorStatus;
}

/************************************************ Timer Counter Compare Register ******************************************************/

TimerError_t TimerUpdateCompareValue(uint8_t TimerCnt,uint32_t CompareValue)
{

    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;

    switch(TimerCnt)
    {
        case 1:
            SET_BITS(TIM2->CCR1,TIM_CCR1_CCR1_Pos,32,CompareValue);
            TimerErrorStatus = (GET_BITS(TIM2->CCR1,TIM_CCR1_CCR1_Pos,32)==CompareValue);
            break;
        case 2:
            SET_BITS(TIM2->CCR2,TIM_CCR2_CCR2_Pos,32,CompareValue);
            TimerErrorStatus = (GET_BITS(TIM2->CCR2,TIM_CCR2_CCR2_Pos,32)==CompareValue);
            break;
        case 3:
            SET_BITS(TIM2->CCR3,TIM_CCR3_CCR3_Pos,32,CompareValue);
            TimerErrorStatus = (GET_BITS(TIM2->CCR3,TIM_CCR3_CCR3_Pos,32)==CompareValue);
            break;
        case 4:
            SET_BITS(TIM2->CCR4,TIM_CCR4_CCR4_Pos,32,CompareValue);
            TimerErrorStatus = (GET_BITS(TIM2->CCR4,TIM_CCR4_CCR4_Pos,32)==CompareValue);
            break;
        default:
            TimerErrorStatus = TIMER_OPR_FAILED;
    }

    return TimerErrorStatus;

}

/************************************************ Timer DMA Config ******************************************************/

TimerError_t TimerConfigureDmaSettings(TimerDmaControlReg_t BitPos , uint8_t RegValue)
{
   TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
   switch(BitPos)
   {
        case TIMER_DMA_BASEADDR:
            SET_BITS(TIM2->DCR,TIM_DCR_DBA_Pos,5,RegValue);
            TimerErrorStatus = (GET_BITS(TIM2->DCR,TIM_DCR_DBA_Pos,5)==RegValue);
            break;
        case TIMER_DMA_BURSTLEN:
            SET_BITS(TIM2->DCR,TIM_DCR_DBL_Pos,5,RegValue);
            TimerErrorStatus = (GET_BITS(TIM2->DCR,TIM_DCR_DBL_Pos,5)==RegValue);
            break;
        default:
            TimerErrorStatus = TIMER_OPR_FAILED;
   }

   return TimerErrorStatus;
}

/************************************************ Timer DMA Full Transfer ******************************************************/
TimerError_t TimerConfigFullTransferAddr(uint16_t RegValue)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    SET_BITS(TIM2->DMAR,TIM_DMAR_DMAB_Pos,16,RegValue);
    TimerErrorStatus = (GET_BITS(TIM2->DMAR,TIM_DMAR_DMAB_Pos,16)==RegValue);
    return TimerErrorStatus;

}

/************************************************ Timer Option Register******************************************************/
TimerError_t TimerConfigOptionReg1(Timer2OptionReg1_t BitPos , uint8_t Cfg)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;
    if(BitPos!=TIMER_INPUT4_REMAP)
    {
        SET_BITS(TIM2->OR1,BitPos,1,Cfg & 0x01);
        TimerErrorStatus = (GET_BITS(TIM2->OR1,BitPos,1)==Cfg&0x01);
    }
    else
    {
        SET_BITS(TIM2->OR1,BitPos,2,Cfg & 0x03);
        TimerErrorStatus = (GET_BITS(TIM2->OR1,BitPos,2)==Cfg&0x03);
    }
    return TimerErrorStatus;
}

/************************************************ Timer Option Register2******************************************************/
TimerError_t TimerConfigOptionReg2(Timer2OptionReg2_t BitPos , uint8_t Cfg)
{
    TimerError_t TimerErrorStatus = TIMER_OPR_FAILED;

    SET_BITS(TIM2->OR2,BitPos,3,Cfg & 0x07);
    TimerErrorStatus = (GET_BITS(TIM2->OR2,BitPos,3)==Cfg&0x07);

    return TimerErrorStatus;
}

