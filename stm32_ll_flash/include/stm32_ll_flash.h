#ifndef STM32_LL_FLASH_H
#define STM32_LL_FLASH_H

#include <stdbool.h>
#include <stdint.h>
#include <stm32l433xx.h>
#define PDKEY1  0x04152637U
#define PDKEY2  0xFAFBFCFDU


typedef enum
{
    FLASH_OPR_FAILED,
    FLASH_OPR_SUCESSS,
    FLASH_OPR_BUSY,
}FlashErr_t;


typedef enum{
    ZERO_WAIT,
    ONE_WAIT,
    TWO_WAIT,
    THREE_WAIT,
    FOUR_WAIT,
}FlashLatency_t;


typedef enum
{
    EOP_ST=0,
    OPERR_ST,
    PROGERR_ST=3,
    WRPERR_ST,
    PAGE_ALIGN_ST,
    SIZE_ERR_ST,
    PROG_SEQ_ERR_ST,
    FASTPROG_DMISS_ERR_ST,
    FASTPROG_ERR_ST,
    PCROP_READ_ERR_ST=14,
    OPTV_ERR_ST,
    BUSY_ERR,
    PROG_EMPTY,
}FlashStatus_t;

typedef enum
{
   PROG_ENABLED=0,
   PAGE_ERASE_ENABLE,
   MASS_ERASE_ENABLE,
   START_ERASE=16,
   OPT_MODIFY_STRT,
   FASTPROG_ENABLED,
   EOP_IE_ENABLED=24,
   ERR_IE_ENABLED,
   READ_ERR_IE_ENABLED,
   FORCE_OBL,
   OPTLOCK_ENABLED=30,
   FLASHCR_LOCK_ENABLED,
}FlashControl_t;

typedef enum
{
    nRST_STOP=12,
    nRST_STDBY,
    nRST_SHUTDOWN,
    IWDG_SW,
    IWDG_STOP,
    IWDG_STDBY,
    WWDG_SW,
    nBOOT1=23,
    SRAM2_PE,
    SRAM2_RST,
    nSWBOOT0,
    nBOOT0,
    
}OptionsReg_t;

typedef enum
{
    SYSCFG_ECC=20,
    ECCC_IE=24,
    ECCC=30,
    ECCD=31,
}EccReg_t;

typedef enum
{
    MASS_ERASE=0,
    PAGE_ERASE,
    PROG_ERASE,
}Erase_t;


FlashErr_t GetReadProtection(uint8_t *ReadProtection);
FlashErr_t SetReadProtection(uint8_t ReadProtection);
FlashErr_t GetBorRstLvl(uint8_t *BorLvl);
FlashErr_t SetOptionsRegisterSettings(OptionsReg_t OptrReg,bool En);
FlashErr_t GetPcropRange(uint16_t *PcorpStart,uint16_t *PcorpEnd);
FlashErr_t SetPcropRange(uint16_t *PcorpStart,uint16_t *PcorpEnd);
FlashErr_t GetWriteProtAreaA(uint8_t *WrpStart , uint8_t *WrpEnd);
FlashErr_t SetWriteProtAreaA(uint8_t *WrpStart , uint8_t *WrpEnd);
FlashErr_t GetWriteProtAreaB(uint8_t *WrpStart , uint8_t *WrpEnd);
FlashErr_t SetWriteProtAreaB(uint8_t *WrpStart , uint8_t *WrpEnd);
FlashErr_t SetFlashLatency(FlashLatency_t FlashLat);
FlashErr_t SetPreFetchCache(bool IPre , bool Icache , bool Dcache);
FlashErr_t EnableDataInstructionReset(bool DCacheRst , bool ICacheRst);
FlashErr_t ConfigureSlpPwrDwn(bool Sleep , bool PwrDwn);
FlashErr_t UnlockFlashSeq(void);
FlashErr_t UnlockOptReg(void);
FlashErr_t SetErrorInfo(FlashStatus_t FlashStatus);
FlashErr_t GetErrorInfo(FlashStatus_t FlashStatus);
FlashErr_t SetFlashCrRegister(FlashControl_t FlashCtrl, bool En);
FlashErr_t SelectPageNumber(uint8_t PageNum);
FlashErr_t GetErrorAddressEcc(uint32_t *ecc_address);
FlashErr_t EnableEccInterrupt(EccReg_t EccReg, bool En);
FlashErr_t GetEccCorrAndDet(bool *EccCorr , bool *EccDet);
FlashErr_t FlashErasePage(uint8_t PageNum);
FlashErr_t FlashEraseMass(void);
FlashErr_t GetFlashCrRegister(FlashControl_t controlBit);
void ClearAllErrors(void);
#endif
