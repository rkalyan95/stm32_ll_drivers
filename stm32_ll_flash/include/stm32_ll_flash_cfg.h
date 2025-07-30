#ifndef STM32_LL_FLASH_CFG_H
#define STM32_LL_FLASH_CFG_H

#include "stm32_ll_flash.h"
#include <stdint.h>

typedef struct
{

}ErrorLog_t;

typedef struct 
{
    uint8_t  major;
    uint8_t  minor;
    uint8_t  patch;
    uint8_t  versi[61];
} FirmwareVersion_t;




FlashErr_t UpdateFirmwareInFlash(void);
FlashErr_t PageNumToAddr(uint8_t PageNum,uint32_t *pgstart_address,uint32_t *pgend_address);
FlashErr_t RunPageProgramSeq(uint8_t PageNum);
FlashErr_t WriteDataToPageNumber(uint8_t PageNum, uint64_t *Data,uint16_t size);
FlashErr_t ReadFirmwareDetails(FirmwareVersion_t *FirmwareVer);
#endif
