#include "stm32_ll_flash_cfg.h"

#define RDPVALUE 0xAA
#define MAX_PAGES 0x7FU
#define PAGE_SIZE 0x800

#define FIRMWARE_VERSION_PAGE  80



FlashErr_t PageNumToAddr(uint8_t PageNum,uint32_t *pgstart_address,uint32_t *pgend_address)
{
 
    uint32_t addresstart;
    uint32_t addresend;

   if(PageNum>MAX_PAGES || pgstart_address==0 ||  pgend_address==0)
   {
       return FLASH_OPR_FAILED;
   }

   addresstart = FLASH_BASE + PageNum * PAGE_SIZE;
   addresend = (addresstart + PAGE_SIZE) - 1;

  *pgstart_address = addresstart;
  *pgend_address = addresend;

  return FLASH_OPR_SUCESSS;
}
FlashErr_t RunPageProgramSeq(uint8_t PageNum)
{
    FlashErr_t RetCode;

    while(GetErrorInfo(BUSY_ERR)!=0);

    ClearAllErrors();

    RetCode = FlashErasePage(PageNum);

    if(RetCode != FLASH_OPR_SUCESSS)
    {
        return RetCode;
    }

    SetFlashCrRegister(PROG_ENABLED,true);

    RetCode = FLASH_OPR_SUCESSS;

    return RetCode;
}
FlashErr_t WriteDataToPageNumber(uint8_t PageNum, uint64_t *Data,uint16_t size)
{
    FlashErr_t RetCode;
    uint32_t pagestart_address;
    uint32_t pageend_address;
    uint16_t numberofDwords;

    numberofDwords = size/sizeof(uint64_t);

    RetCode = PageNumToAddr(PageNum,&pagestart_address,&pageend_address);

    RetCode = RunPageProgramSeq(PageNum);
    if(RetCode != FLASH_OPR_SUCESSS) // Add error check for erase/setup
    {
        return RetCode;
    }
    if (pagestart_address & 0x7){ return FLASH_OPR_FAILED; }

    RetCode = SelectPageNumber(PageNum);

    if(RetCode != FLASH_OPR_SUCESSS) {
        // Handle error if page selection fails
        SetFlashCrRegister(PROG_ENABLED, false); // Disable programming
        SetFlashCrRegister(FLASHCR_LOCK_ENABLED, true); // Re-lock flash if needed
        return RetCode;
    }


    if(size < PAGE_SIZE && size % sizeof(uint64_t) == 0)
    {
        for(uint32_t i = 0; i < numberofDwords; i++)
        {
            *(volatile uint64_t *)(pagestart_address + i * sizeof(uint64_t)) = Data[i];
            while(GetErrorInfo(BUSY_ERR) != 0);

            if(GetErrorInfo(WRPERR_ST) == 1 || GetErrorInfo(PROGERR_ST) == 1 )
            {
                SetFlashCrRegister(PROG_ENABLED, false);
                SetFlashCrRegister(FLASHCR_LOCK_ENABLED, true);
                
                return FLASH_OPR_FAILED;
            }
        }
    }

    SetFlashCrRegister(PROG_ENABLED, false);
    SetFlashCrRegister(FLASHCR_LOCK_ENABLED, true);

    return RetCode;
}



FlashErr_t UpdateFirmwareInFlash(void)
{
    FlashErr_t RetCode;
    uint64_t data = 0x74616a6152;
    //RetCode = WriteDataToPageNumber(FIRMWARE_VERSION_PAGE,(uint64_t*)&FirmwareVersion,sizeof(FirmwareVersion_t));
    RetCode = WriteDataToPageNumber(FIRMWARE_VERSION_PAGE,&data,sizeof(uint64_t));

    return RetCode;
}