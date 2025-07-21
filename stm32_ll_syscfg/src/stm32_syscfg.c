#include "stm32_syscfg.h"
#include "stm32l433xx.h"
#include <stdbool.h>
#include "common.h"

/**
 * @brief  Sets the system memory mapping mode.
 * @param  MemMode: Memory mapping mode to be set. This should be a value of type SysCfg_MemMode_t.
 * @retval Error_t: Returns SYSCFG_SUCCESS if the operation was successful, otherwise SYSCFG_FAILED.
 *
 * This function configures the SYSCFG->MEMRMP register to select the memory mapping mode
 * for the system (main flash, system flash, or SRAM). It uses SET_BITS and GET_BITS macros
 * to write and verify the configuration.
 */

Error_t SetSysConfigMemoryMap(SysCfg_MemMode_t MemMode)
{
    SET_BITS(SYSCFG->MEMRMP,SYSCFG_MEMRMP_MEM_MODE_Pos,3,MemMode);

    return (GET_BITS(SYSCFG->MEMRMP,SYSCFG_MEMRMP_MEM_MODE_Pos,3)==MemMode);
}

/**
 * @brief  Enables Fast Mode Plus for the specified I2C peripheral or pin.
 * @param  FmPeriph_t: The I2C peripheral or pin to enable Fast Mode Plus for. 
 *         This should be a value of type SysCfg_FastMode_Perpih_t.
 *         Possible values: I2C_PB6_FMP, I2C_PB7_FMP, I2C_PB8_FMP, I2C_PB9_FMP, I2C1_FMP, I2C2_FMP, I2C3_FMP.
 * @retval Error_t: Returns SYSCFG_SUCCESS if the operation was successful, otherwise SYSCFG_FAILED.
 *
 * This function sets the corresponding bit in the SYSCFG->CFGR1 register to enable Fast Mode Plus
 * for the selected I2C peripheral or pin. It verifies the operation by reading back the register.
 */

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

/**
 * @brief  Enables or disables the SYSCFG firewall.
 * @param  En: Boolean value to enable (true) or disable (false) the firewall.
 * @retval Error_t: Returns SYSCFG_SUCCESS if the operation was successful, otherwise SYSCFG_FAILED.
 *
 * This function sets or clears the FWDIS bit in the SYSCFG->CFGR1 register to control the firewall feature.
 * It verifies the operation by reading back the register value.
 */

Error_t SysCfgFirewallEnabled(bool En)
{

    SET_BITS(SYSCFG->CFGR1,SYSCFG_CFGR1_FWDIS_Pos,1,En);

    return (GET_BITS(SYSCFG->CFGR1,SYSCFG_CFGR1_FWDIS_Pos,1)==En);
}

/**
 * @brief  Enables or disables the SYSCFG I/O compensation cell (BOOST).
 * @param  En: Boolean value to enable (true) or disable (false) the boost feature.
 * @retval Error_t: Returns SYSCFG_SUCCESS if the operation was successful, otherwise SYSCFG_FAILED.
 *
 * This function sets or clears the BOOSTEN bit in the SYSCFG->CFGR1 register to control the I/O compensation cell.
 * It verifies the operation by reading back the register
 * */

Error_t SysCfgBoostEnabled(bool En)
{
    SET_BITS(SYSCFG->CFGR1,SYSCFG_CFGR1_BOOSTEN_Pos,1,En);

    return (GET_BITS(SYSCFG->CFGR1,SYSCFG_CFGR1_BOOSTEN_Pos,1)==En); 
}

/**
 * @brief  Configures the EXTI0 line source input.
 * @param  Exti1Config: EXTI0 configuration value of type SysCfg_Exti0_Cfg_t.
 * @retval Error_t: Returns SYSCFG_SUCCESS if the operation was successful, otherwise SYSCFG_FAILED.
 *
 * This function sets the source input for EXTI0 in the SYSCFG->EXTICR[0] register.
 * It uses SET_BITS and GET_BITS macros to write and verify 
 * */

Error_t SysCfgExti1Configure(Exti_Reg_t ExtiReg , uint8_t RegPos,SysCfg_ExtiX_Cfg_t PortPin)
{
  Error_t RetCode=SYSCFG_FAILED;

  SET_BITS(SYSCFG->EXTICR[ExtiReg],RegPos,3,PortPin);  
  RetCode = (GET_BITS(SYSCFG->EXTICR[ExtiReg],RegPos,3)==PortPin);  
  return RetCode;

}



Error_t SysCfgSram2StartErase(void)
{
  Error_t RetCode=SYSCFG_FAILED;
  
  SET(SYSCFG->SCSR,SYSCFG_SCSR_SRAM2ER_Pos);
  RetCode = GET(SYSCFG->SCSR,SYSCFG_SCSR_SRAM2ER_Pos);
  return RetCode;
}

Error_t GetSysCfgSramBusyStatus(void)
{

  Error_t RetCode=SYSCFG_FAILED;
  RetCode = GET(SYSCFG->SCSR,SYSCFG_SCSR_SRAM2BSY_Pos);
  return RetCode;

}

bool SysCfgSram2ParityErrOccured(void)
{
    return (GET(SYSCFG->CFGR2,SYSCFG_CFGR2_SPF_Pos));
}

Error_t SysCfgEccErrtoTimBrkSet(void)
{
  Error_t RetCode=SYSCFG_FAILED;
    SET(SYSCFG->CFGR2,SYSCFG_CFGR2_ECCL_Pos);
  RetCode = GET(SYSCFG->CFGR2,SYSCFG_CFGR2_ECCL_Pos);
  return RetCode;
}

Error_t SysCfgEPvdLckEnableSet(void)
{
  Error_t RetCode=SYSCFG_FAILED;
    SET(SYSCFG->CFGR2,SYSCFG_CFGR2_PVDL_Pos);
    RetCode = GET(SYSCFG->CFGR2,SYSCFG_CFGR2_PVDL_Pos);
    return RetCode;
}
Error_t SysCfgParityLockEnableSet(void)
{
  Error_t RetCode=SYSCFG_FAILED;
    SET(SYSCFG->CFGR2,SYSCFG_CFGR2_SPL_Pos);
    RetCode = GET(SYSCFG->CFGR2,SYSCFG_CFGR2_SPL_Pos);
    return RetCode;
}

Error_t SysCfgHardFaultToTimBrkEnable(void)
{
  Error_t RetCode=SYSCFG_FAILED;
  SET(SYSCFG->CFGR2,SYSCFG_CFGR2_CLL_Pos);
  RetCode = GET(SYSCFG->CFGR2,SYSCFG_CFGR2_CLL_Pos);
  return RetCode;
}

Error_t SysCfgEnableSramPageWriteProtection(SramPage_t PageBitPos,bool En)
{
  Error_t RetCode=SYSCFG_FAILED;
  SET_BITS(SYSCFG->CFGR2,PageBitPos,1,En);
  RetCode = (GET_BITS(SYSCFG->CFGR2,PageBitPos,1)==En);
  return RetCode;
}

Error_t DisableWriteProtectionKey(void)
{
  Error_t RetCode=SYSCFG_FAILED;
   SET_BITS(SYSCFG->SKR,SYSCFG_SKR_KEY_Pos,8,SRAM_KEY1);
   SET_BITS(SYSCFG->SKR,SYSCFG_SKR_KEY_Pos,8,SRAM_KEY2);
   RetCode = SYSCFG_SUCCESS;
return RetCode;

}