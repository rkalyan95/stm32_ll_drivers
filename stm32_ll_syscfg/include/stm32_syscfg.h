#ifndef STM32_SYSCFG_H
#define STM32_SYSCFG_H

#include <stdint.h>
#include <stdbool.h>

#define SYSCFG  ((SYSCFG_TypeDef *) SYSCFG_BASE)

#define SRAM_KEY1    0x53
#define SRAM_KEY2    0xCA




typedef enum
{
    SYSCFG_FAILED,
    SYSCFG_SUCCESS
}Error_t;


typedef enum
{
    SYSCFG_MAINFLASH=0,
    SYSCFG_SYSTEMFLASH=1,
    SYSCFG_SRAMFLASH=3,
    SYSCFG_QSPI=6
}SysCfg_MemMode_t;

typedef enum
{
    I2C_PB6_FMP,
    I2C_PB7_FMP,
    I2C_PB8_FMP,
    I2C_PB9_FMP,
    I2C1_FMP,
    I2C2_FMP,
    I2C3_FMP,
}SysCfg_FastMode_Perpih_t;

typedef enum
{
    EXTI1,
    EXTI2,
    EXTI3,
    EXTI4,
    EXTI_INVALID
}Exti_Reg_t;

typedef enum
{
    EXTIx_PAx,
    EXTIx_PBx,
    EXTIx_PCx,
    EXTIx_PDx,
    EXTIx_PEx,
    EXTIx_PHx=7,

}SysCfg_ExtiX_Cfg_t;



typedef enum
{
    PAGE0_WP,
    PAGE1_WP,
    PAGE2_WP,
    PAGE3_WP,
    PAGE4_WP,
    PAGE5_WP,
    PAGE6_WP,
    PAGE7_WP,
    PAGE8_WP,
    PAGE9_WP,
    PAGE10_WP,
    PAGE11_WP,
    PAGE12_WP,
    PAGE13_WP,
    PAGE14_WP,
    PAGE15_WP,
    PAGE16_WP,
    PAGE17_WP,
    PAGE18_WP,
    PAGE19_WP,
    PAGE20_WP,
    PAGE21_WP,
    PAGE22_WP,
    PAGE23_WP,
    PAGE24_WP,
    PAGE25_WP,
    PAGE26_WP,
    PAGE27_WP,
    PAGE28_WP,
    PAGE29_WP,
    PAGE30_WP,
    PAGE31_WP,
}SramPage_t;

Error_t SetSysConfigMemoryMap(SysCfg_MemMode_t MemMode);
Error_t SetSysCfgFastModePlus(SysCfg_FastMode_Perpih_t FmPeriph_t);
Error_t SysCfgFirewallEnabled(bool En);
Error_t SysCfgBoostEnabled(bool En);
Error_t SysCfgExti1Configure(Exti_Reg_t ExtiReg , uint8_t RegPos,SysCfg_ExtiX_Cfg_t PortPin);
Error_t SysCfgSram2StartErase(void);
Error_t GetSysCfgSramBusyStatus(void);
bool SysCfgSram2ParityErrOccured(void);
Error_t SysCfgEccErrtoTimBrkSet(void);
Error_t SysCfgEPvdLckEnableSet(void);
Error_t SysCfgParityLockEnableSet(void);
Error_t SysCfgHardFaultToTimBrkEnable(void);
Error_t SysCfgEnableSramPageWriteProtection(SramPage_t PageBitPos, bool En);
Error_t DisableWriteProtectionKey(void);

#endif // STM32_SYSCFG_H