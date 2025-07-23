#include "stm32_ll_flash_cfg.h"

#define RDPVALUE 0x08 

const FlashSettings_t DefaultFlashSettings = {.RDP = RDPVALUE, .BOR_LEVEL = 0x00, .FLASH_LATENCY = 0x00};

const FlashProtCfg_t DefaultFlashProtCfg = {.PCROP_STRT = 0x0000, .PCROP_END = 0x0000, .WRPAREAA_STRT = 0x0000, .WRPAREAA_END = 0x0000, .WRPAREBB_STRT = 0x0000, .WRPAREBB_END = 0x0000};

const FlashControlBits_t DefaultFlashControl = {
                        .BOOT0_SEL = DISABLED,
                        .BOOT1_SEL = DISABLED,
                        .SWBOOT_SEL = DISABLED,
                        .SRAM2_ERASE_SEL = DISABLED,
                        .SRAM2_PE_SEL = DISABLED,
                        .WWDG_SEL = DISABLED,
                        .IWDG_STDBY_SEL = DISABLED,
                        .IWDG_STOP_SEL = DISABLED,
                        .IWDG_SEL = DISABLED,
                        .RSTON_STOP_SEL = DISABLED,
                        .RSTON_STDBY_SEL = DISABLED,
                        .RSTON_SHDWN_SEL = DISABLED,
                        .ERROR_IE_SEL = DISABLED,
                        .EOP_IE_SEL = DISABLED,
                        .PCROP_RDERR_IE_SEL = DISABLED,
                        .ECCC_IE_SEL = DISABLED,
};


FlashErr_t ConfigureFlashMemory(FlashSettings_t FlashSettings, FlashProtCfg_t FlashProtCfg, FlashControlBits_t FlashControl)
{

}