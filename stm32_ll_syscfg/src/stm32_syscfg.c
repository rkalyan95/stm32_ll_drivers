#include "stm32_syscfg.h"
#include "stm32l433xx.h"
#include <stdbool.h>

Error_t SetSysConfigMemoryMap(SysCfg_MemMode_t MemMode)
{
    SET_BITS(SYSCFG->MEMRMP,SYSCFG_MEMRMP_MEM_MODE_Pos,3,MemMode);

    return (GET_BITS(SYSCFG->MEMRMP,SYSCFG_MEMRMP_MEM_MODE_Pos,3)==MemMode);
}

Error_t SetSysCfgFastModePlus(SysCfg_FastMode_Perpih_t FmPeriph_t)
{
  Error_t RetCode=SYSCFG_FAILED;

  switch(FmPeriph_t)
  {
    case I2C_PB6_FMP:
      SET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C_PB6_FMP_Pos);
      RetCode = GET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C_PB6_FMP_Pos);
      break;
    case I2C_PB7_FMP:
      SET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C_PB7_FMP_Pos);
      RetCode = GET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C_PB7_FMP_Pos);     
      break;
    case I2C_PB8_FMP:
      SET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C_PB8_FMP_Pos);
      RetCode = GET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C_PB8_FMP_Pos);
      break;
    case I2C_PB9_FMP:
      SET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C_PB9_FMP_Pos);
      RetCode = GET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C_PB9_FMP_Pos);
      break;
    case I2C1_FMP:
      SET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C1_FMP_Pos);
      RetCode = GET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C1_FMP_Pos);
      break;
    case I2C2_FMP:
      SET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C2_FMP_Pos);
      RetCode = GET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C2_FMP_Pos);
      break;
    case I2C3_FMP:
      SET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C3_FMP_Pos);
      RetCode = GET(SYSCFG->CFGR1,SYSCFG_CFGR1_I2C3_FMP_Pos);
      break;
    default:
      return RetCode;
  }
    
  return RetCode;
}

Error_t SysCfgFirewallEnabled(bool En)
{

    SET_BITS(SYSCFG->CFGR1,SYSCFG_CFGR1_FWDIS_Pos,1,En);

    return (GET_BITS(SYSCFG->CFGR1,SYSCFG_CFGR1_FWDIS_Pos,1)==En);
}

Error_t SysCfgBoostEnabled(bool En)
{
    SET_BITS(SYSCFG->CFGR1,SYSCFG_CFGR1_BOOSTEN_Pos,1,En);

    return (GET_BITS(SYSCFG->CFGR1,SYSCFG_CFGR1_BOOSTEN_Pos,1)==En); 
}