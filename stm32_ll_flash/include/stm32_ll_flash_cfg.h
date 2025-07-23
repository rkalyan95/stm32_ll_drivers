#ifndef STM32_LL_FLASH_CFG_H
#define STM32_LL_FLASH_CFG_H

#include "stm32_ll_flash.h"
#include <stdint.h>


typedef enum
{
    DISABLED,
    ENABLED,
}Control_t;


typedef struct
{
    uint16_t  PCROP_STRT;
    uint16_t  PCROP_END;
    uint16_t  WRPAREAA_STRT;
    uint16_t  WRPAREAA_END;
    uint16_t  WRPAREBB_STRT;
    uint16_t  WRPAREBB_END;

}FlashProtCfg_t;

typedef struct 
{
    uint8_t RDP;
    uint8_t BOR_LEVEL;
    uint8_t FLASH_LATENCY;
}FlashSettings_t;

typedef struct
{
    Control_t BOOT0_SEL;
    Control_t BOOT1_SEL;
    Control_t SWBOOT_SEL;
    Control_t SRAM2_ERASE_SEL;
    Control_t SRAM2_PE_SEL;
    Control_t WWDG_SEL;
    Control_t IWDG_STDBY_SEL;
    Control_t IWDG_STOP_SEL;
    Control_t IWDG_SEL;
    Control_t RSTON_STOP_SEL;
    Control_t RSTON_STDBY_SEL;
    Control_t RSTON_SHDWN_SEL;
    Control_t ERROR_IE_SEL;
    Control_t EOP_IE_SEL;
    Control_t PCROP_RDERR_IE_SEL;
    Control_t ECCC_IE_SEL;

}FlashControlBits_t;

FlashErr_t ConfigureFlashMemory(FlashSettings_t FlashSettings, FlashProtCfg_t FlashProtCfg, FlashControlBits_t FlashControl);

#endif
