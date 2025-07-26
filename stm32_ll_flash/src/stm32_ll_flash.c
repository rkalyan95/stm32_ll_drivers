
#include "stm32_ll_flash.h"
#include "common.h"

/**
 * @brief Naive line chunk processing.
 * 
 * This function is responsible for handling line chunk processing
 * in a naive manner. It serves as an introductory implementation
 * for understanding basic line processing operations.
 * 
 * Note: The implementation may not be optimized for performance.
 * 
 * @warning Ensure that all necessary preconditions are met before
 * calling this function.
 */


void ClearAllErrors(void)
{
    ((GetErrorInfo(EOP_ST)==1)?SetErrorInfo(EOP_ST):0);
    ((GetErrorInfo(OPERR_ST)==1)?SetErrorInfo(OPERR_ST):0);
    ((GetErrorInfo(PROGERR_ST)==1)?SetErrorInfo(PROGERR_ST):0);
    ((GetErrorInfo(WRPERR_ST)==1)?SetErrorInfo(WRPERR_ST):0);
    ((GetErrorInfo(PAGE_ALIGN_ST)==1)?SetErrorInfo(PAGE_ALIGN_ST):0);
    ((GetErrorInfo(SIZE_ERR_ST)==1)?SetErrorInfo(SIZE_ERR_ST):0);
    ((GetErrorInfo(PROG_SEQ_ERR_ST)==1)?SetErrorInfo(PROG_SEQ_ERR_ST):0);
    ((GetErrorInfo(FASTPROG_DMISS_ERR_ST)==1)?SetErrorInfo(FASTPROG_DMISS_ERR_ST):0);
    ((GetErrorInfo(FASTPROG_ERR_ST)==1)?SetErrorInfo(FASTPROG_ERR_ST):0);
    ((GetErrorInfo(PCROP_READ_ERR_ST)==1)?SetErrorInfo(PCROP_READ_ERR_ST):0);

}

/**
 * @brief Unlock or lock the option register sequence.
 * 
 * This function handles the unlocking and locking of the option register.
 * If the lock parameter is true, the function unlocks the option register
 * through a key sequence. Otherwise, it waits for the busy bit to clear,
 * clears all errors, and locks the option register by enabling the lock.
 * 
 * @param lock A boolean value to indicate lock status. 
 *             - true: Unlock the option register.
 *             - false: Lock the option register.
 * 
 * @note Ensure that necessary preconditions are met before calling this function.
 */

static inline FlashErr_t UnLockSequence(bool Unlock)
{
    uint32_t timeout = 1000000;
    //Unlock the opt register by key sequence
    if(Unlock==true)
    {
        UnlockOptReg();
    }
    else
    {
        //Wait for the Busy Bit to become 0
        while(GetErrorInfo(BUSY_ERR)!=0 && timeout-->0);
        if(timeout==0)
        {
            return FLASH_OPR_BUSY;
        }
        ClearAllErrors();
    //lock the opt register by enabling the lock again
        SetFlashCrRegister(OPTLOCK_ENABLED,true);
    }

    return FLASH_OPR_SUCESSS;
    
}
/**
 * @brief Retrieve the current read protection level.
 * 
 * This function retrieves the read protection level from the option register
 * and stores it in the provided memory location. The read protection level
 * determines the security level of the flash memory.
 * 
 * @param[out] ReadProtection Pointer to store the read protection level.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: Operation was successful.
 * 
 * @note Ensure that the pointer provided is valid and that the function is 
 *       called in a context where accessing the option register is safe.
 */



FlashErr_t GetReadProtection(uint8_t *ReadProtection)
{
    FlashErr_t RetCode=FLASH_OPR_FAILED;
    *ReadProtection = GET_BITS(FLASH->OPTR,FLASH_OPTR_RDP_Pos,8);
    RetCode = FLASH_OPR_SUCESSS;
    return RetCode;
}
/**
 * @brief Set the read protection level.
 * 
 * This function sets the read protection level in the option register. The
 * read protection level determines the security level of the flash memory.
 * 
 * @param[in] ReadProtection Read protection level to set.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: Operation was successful.
 * 
 * @note Ensure that the pointer provided is valid and that the function is 
 *       called in a context where accessing the option register is safe.
 */
FlashErr_t SetReadProtection(uint8_t ReadProtection)
{
    FlashErr_t RetCode=FLASH_OPR_FAILED;
    SET_BITS(FLASH->OPTR,FLASH_OPTR_RDP_Pos,8,ReadProtection);
    RetCode = (GET_BITS(FLASH->OPTR,FLASH_OPTR_RDP_Pos,8)==ReadProtection);
    return RetCode;
}


/**
 * @brief Get the BOR reset level.
 * 
 * This function retrieves the level of the brown-out reset (BOR) from the
 * option register and stores it in the provided memory location. The BOR
 * is a reset caused by a failure in the power supply.
 * 
 * @param[out] BorLvl Pointer to store the brown-out reset level. The value
 *                    will be in the range 0 to 7, where 0 is the lowest
 *                    voltage and 7 is the highest.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: Operation was successful.
 * 
 * @note Ensure that the pointer provided is valid and that the function is 
 *       called in a context where accessing the option register is safe.
 */

FlashErr_t GetBorRstLvl(uint8_t *BorLvl)
{
    FlashErr_t RetCode=FLASH_OPR_FAILED;
    *BorLvl = GET_BITS(FLASH->OPTR,FLASH_OPTR_BOR_LEV_Pos,3);
    RetCode = FLASH_OPR_SUCESSS;
    return RetCode;
}
/**
 * @brief Set the options register settings.
 * 
 * This function sets the options register settings. The options register
 * contains configuration settings such as the read protection level and the
 * brown-out reset (BOR) level.
 * 
 * @param[in] OptrReg Options register setting to set.
 * @param[in] En      Setting value to set. If En is true the setting is
 *                    enabled.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: Operation was successful.
 * 
 * @note Ensure that the option register is unlocked before calling this
 *       function.
 */
FlashErr_t SetOptionsRegisterSettings(OptionsReg_t OptrReg,bool En)
{
    FlashErr_t RetCode=FLASH_OPR_FAILED;
    if(OptrReg>=nRST_STOP)
    {
        UnLockSequence(true);
        SET_BITS(FLASH->OPTR,OptrReg,1,En);
        RetCode = (GET_BITS(FLASH->OPTR,OptrReg,1)==En)?FLASH_OPR_SUCESSS:FLASH_OPR_FAILED;
        RetCode = UnLockSequence(false);
    }

    return RetCode;
}
/**
 * @brief Retrieve the PCROP region.
 * 
 * This function retrieves the start and end address of the PCROP region
 * from the option register and stores it in the provided memory locations.
 * The PCROP region is a region of the flash memory that has been protected
 * against writing.
 * 
 * @param[out] PcorpStart Pointer to store the start address of the PCROP region.
 * @param[out] PcorpEnd   Pointer to store the end address of the PCROP region.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: Operation was successful.
 * 
 * @note Ensure that the pointers provided are valid and that the function is 
 *       called in a context where accessing the option register is safe.
 */
FlashErr_t GetPcropRange(uint16_t *PcorpStart,uint16_t *PcorpEnd)  
{
    FlashErr_t RetCode=FLASH_OPR_FAILED;
    *PcorpStart = GET_BITS(FLASH->PCROP1SR,FLASH_PCROP1SR_PCROP1_STRT_Pos,16);
    *PcorpEnd = GET_BITS(FLASH->PCROP1ER,FLASH_PCROP1ER_PCROP1_END_Pos,16);
    RetCode = FLASH_OPR_SUCESSS;
    return RetCode;
}
/**
 * @brief Set the PCROP region.
 * 
 * This function sets the start and end address of the PCROP region
 * in the option register. The PCROP region is a region of the flash
 * memory that has been protected against writing.
 * 
 * @param[in] PcorpStart Start address of the PCROP region.
 * @param[in] PcorpEnd   End address of the PCROP region.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: Operation was successful.
 * 
 * @note Ensure that the pointers provided are valid and that the function is 
 *       called in a context where accessing the option register is safe.
 */
FlashErr_t SetPcropRange(uint16_t *PcorpStart,uint16_t *PcorpEnd)  
{
    FlashErr_t RetCode=FLASH_OPR_FAILED;
    
    UnLockSequence(true);

    SET_BITS(FLASH->PCROP1SR,FLASH_PCROP1SR_PCROP1_STRT_Pos,16,*PcorpStart);
    SET_BITS(FLASH->PCROP1ER,FLASH_PCROP1ER_PCROP1_END_Pos,16,*PcorpEnd);
    SetFlashCrRegister(OPT_MODIFY_STRT,true);

    RetCode = UnLockSequence(false);
    return RetCode;

}
/**
 * @brief Get the write protection for area A.
 * 
 * This function retrieves the start and end address of the write protection
 * area A from the option register and stores it in the provided memory
 * locations.
 * 
 * @param[out] WrpStart Pointer to store the start address of the write
 *                     protection area A.
 * @param[out] WrpEnd   Pointer to store the end address of the write
 *                     protection area A.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: Operation was successful.
 * 
 * @note Ensure that the pointers provided are valid and that the function is 
 *       called in a context where accessing the option register is safe.
 */
FlashErr_t GetWriteProtAreaA(uint8_t *WrpStart , uint8_t *WrpEnd)
{
    FlashErr_t RetCode=FLASH_OPR_FAILED;
    *WrpStart = GET_BITS(FLASH->WRP1AR,FLASH_WRP1AR_WRP1A_STRT_Pos,8);
    *WrpEnd = GET_BITS(FLASH->WRP1AR,FLASH_WRP1AR_WRP1A_END_Pos,8);
    RetCode = FLASH_OPR_SUCESSS;
    return RetCode;
}
/**
 * @brief Get the write protection for area A.
 * 
 * This function retrieves the start and end address of the write protection
 * area A from the option register and stores it in the provided memory
 * locations.
 * 
 * @param[out] WrpStart Pointer to store the start address of the write
 *                      protection area A.
 * @param[out] WrpEnd   Pointer to store the end address of the write
 *                      protection area A.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: Operation was successful.
 *         - FLASH_OPR_FAILED: Operation failed.
 * 
 * @note Ensure that the pointers provided are valid and that the function is 
 *       called in a context where accessing the option register is safe.
 */

FlashErr_t SetWriteProtAreaA(uint8_t *WrpStart , uint8_t *WrpEnd)
{
    FlashErr_t RetCode=FLASH_OPR_FAILED;

    //Unlock the opt register by key sequence
    UnLockSequence(true);
    SET_BITS(FLASH->WRP1AR,FLASH_WRP1AR_WRP1A_STRT_Pos,8,*WrpStart);
    SET_BITS(FLASH->WRP1AR,FLASH_WRP1AR_WRP1A_END_Pos,8,*WrpEnd);
    SetFlashCrRegister(OPT_MODIFY_STRT,true);
    RetCode = UnLockSequence(false);

    return RetCode;
}


/**
 * @brief Retrieve the write protection for area B.
 * 
 * This function retrieves the start and end address of the write protection
 * area B from the option register and stores it in the provided memory
 * locations.
 * 
 * @param[out] WrpStart Pointer to store the start address of the write
 *                      protection area B.
 * @param[out] WrpEnd   Pointer to store the end address of the write
 *                      protection area B.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: Operation was successful.
 *         - FLASH_OPR_FAILED: Operation failed.
 * 
 * @note Ensure that the pointers provided are valid and that the function is 
 *       called in a context where accessing the option register is safe.
 */
FlashErr_t GetWriteProtAreaB(uint8_t *WrpStart , uint8_t *WrpEnd)
{
    FlashErr_t RetCode=FLASH_OPR_FAILED;
    *WrpStart = GET_BITS(FLASH->WRP1BR,FLASH_WRP1BR_WRP1B_STRT_Pos,8);
    *WrpEnd = GET_BITS(FLASH->WRP1BR,FLASH_WRP1BR_WRP1B_END_Pos,8);
    RetCode = FLASH_OPR_SUCESSS;
    return RetCode;
}
/**
 * @brief Set the write protection for area B.
 * 
 * This function sets the start and end address of the write protection area B
 * in the option register.
 * 
 * @param[out] WrpStart Pointer to store the start address of the write
 *                      protection area B.
 * @param[out] WrpEnd   Pointer to store the end address of the write
 *                      protection area B.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: Operation was successful.
 *         - FLASH_OPR_FAILED: Operation failed.
 * 
 * @note Ensure that the pointers provided are valid and that the function is 
 *       called in a context where accessing the option register is safe.
 */
FlashErr_t SetWriteProtAreaB(uint8_t *WrpStart , uint8_t *WrpEnd)
{
    FlashErr_t RetCode=FLASH_OPR_FAILED;
    //Unlock the opt register by key sequence
    UnLockSequence(true);
    SET_BITS(FLASH->WRP1BR,FLASH_WRP1BR_WRP1B_STRT_Pos,8,*WrpStart);
    SET_BITS(FLASH->WRP1BR,FLASH_WRP1BR_WRP1B_END_Pos,8,*WrpEnd);
    SetFlashCrRegister(OPT_MODIFY_STRT,true);
    RetCode = UnLockSequence(false);
    return RetCode;
}
/**
 * @brief Set the flash latency.
 * 
 * This function sets the flash latency by configuring the appropriate bits in the
 * Access Control Register (ACR) of the flash memory.
 * 
 * @param[in] FlashLat The desired flash latency level of type FlashLatency_t.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the latency was set successfully.
 *         - FLASH_OPR_FAILED: If setting the latency failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */

FlashErr_t SetFlashLatency(FlashLatency_t FlashLat)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;;

    while(GetErrorInfo(BUSY_ERR)!=0);

    SET_BITS(FLASH->ACR,FLASH_ACR_LATENCY_Pos,2,FlashLat);
    RetCode = (GET_BITS(FLASH->ACR,FLASH_ACR_LATENCY_Pos,2)==FlashLat);
    return RetCode;
}

/**
 * @brief Configure the flash memory with the desired configuration.
 * 
 * This function can be used to set the flash memory to the desired
 * configuration. The configuration can be one of the following:
 * - FLASH_CONF_DEFAULT: The default configuration.
 * - FLASH_CONF_I_CACHE: The instruction cache is enabled.
 * - FLASH_CONF_D_CACHE: The data cache is enabled.
 * - FLASH_CONF_PREFETCH: The prefetch cache is enabled.
 * - FLASH_CONF_I_CACHE_D_CACHE: The instruction cache and the data cache are
 *                               enabled.
 * - FLASH_CONF_PREFETCH_I_CACHE: The prefetch cache and the instruction cache
 *                                are enabled.
 * - FLASH_CONF_PREFETCH_D_CACHE: The prefetch cache and the data cache are
 *                                enabled.
 * - FLASH_CONF_PREFETCH_I_CACHE_D_CACHE: The prefetch cache, the instruction
 *                                        cache and the data cache are enabled.
 * 
 * @param[in] Config The desired configuration of type FlashConfig_t.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the configuration was set successfully.
 *         - FLASH_OPR_FAILED: If setting the configuration failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */
FlashErr_t SetPreFetchCache(bool IPre , bool Icache , bool Dcache)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;;
    SET_BITS(FLASH->ACR,FLASH_ACR_PRFTEN_Pos,1,IPre);
    SET_BITS(FLASH->ACR,FLASH_ACR_ICEN_Pos,1,Icache);
    SET_BITS(FLASH->ACR,FLASH_ACR_DCEN_Pos,1,Dcache);
    RetCode = (GET_BITS(FLASH->ACR,FLASH_ACR_PRFTEN_Pos,1)==IPre) && (GET_BITS(FLASH->ACR,FLASH_ACR_ICEN_Pos,1)==Icache) && (GET_BITS(FLASH->ACR,FLASH_ACR_DCEN_Pos,1)==Dcache);
    return RetCode;
}
/**
 * @brief Enable or disable the reset of the instruction and data caches.
 * 
 * This function can be used to enable or disable the reset of the instruction
 * and data caches. The reset is only enabled if the instruction and data caches
 * are enabled.
 * 
 * @param[in] DCacheRst true to enable the reset of the data cache, otherwise false.
 * @param[in] ICacheRst true to enable the reset of the instruction cache, otherwise false.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the configuration was set successfully.
 *         - FLASH_OPR_FAILED: If setting the configuration failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */
FlashErr_t EnableDataInstructionReset(bool DCacheRst , bool ICacheRst)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;;
    if((!GET(FLASH->ACR,FLASH_ACR_DCEN_Pos))&& (!GET(FLASH->ACR,FLASH_ACR_ICEN_Pos)))
    {
        SET_BITS(FLASH->ACR,FLASH_ACR_DCRST_Pos,1,DCacheRst);
        SET_BITS(FLASH->ACR,FLASH_ACR_ICRST_Pos,1,ICacheRst);
        RetCode = (GET_BITS(FLASH->ACR,FLASH_ACR_DCRST_Pos,1)==0) && (GET_BITS(FLASH->ACR,FLASH_ACR_ICRST_Pos,1)==0);
    }
    else
    {
        RetCode = FLASH_OPR_FAILED;
    }

    return RetCode;
}

/**
 * @brief Enable or disable the reset of the instruction and data caches on power down.
 * 
 * This function can be used to enable or disable the reset of the instruction
 * and data caches when the device is powered down. The reset is only enabled if
 * the instruction and data caches are enabled.
 * 
 * @param[in] Sleep true to enable the reset of the instruction and data caches
 *                  when the device is in sleep mode, otherwise false.
 * @param[in] PwrDwn true to enable the reset of the instruction and data caches
 *                  when the device is powered down, otherwise false.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the configuration was set successfully.
 *         - FLASH_OPR_FAILED: If setting the configuration failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */

FlashErr_t ConfigureSlpPwrDwn(bool Sleep , bool PwrDwn)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;;
    SET_BITS(FLASH->ACR,FLASH_ACR_SLEEP_PD_Pos,1,Sleep);
    SET_BITS(FLASH->ACR,FLASH_ACR_RUN_PD_Pos,1,PwrDwn);
    RetCode = (GET_BITS(FLASH->ACR,FLASH_ACR_SLEEP_PD_Pos,1)==Sleep) && (GET_BITS(FLASH->ACR,FLASH_ACR_RUN_PD_Pos,1)==PwrDwn);
    return RetCode;
}

/**
 * @brief Unlock the power down register for programming.
 * 
 * This function unlocks the power down register for programming. The unlock
 * sequence must be performed in the exact order as specified in the
 * datasheet.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the unlock sequence was successful.
 *         - FLASH_OPR_FAILED: If the unlock sequence failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */
FlashErr_t UnlockFlashSeq(void)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;
    SET_BITS(FLASH->KEYR,0,32,0x45670123);
    SET_BITS(FLASH->KEYR,0,32,0xCDEF89AB);

    RetCode = FLASH_OPR_SUCESSS;
    return RetCode;
}

/**
 * @brief Lock the power down register for programming.
 * 
 * This function locks the power down register for programming. The lock
 * sequence must be performed in the exact order as specified in the
 * datasheet.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the lock sequence was successful.
 *         - FLASH_OPR_FAILED: If the lock sequence failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */
FlashErr_t UnlockOptReg(void)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;
    SET_BITS(FLASH->OPTKEYR,0,32,0x08192A3B);
    SET_BITS(FLASH->OPTKEYR,0,32,0x4C5D6E7F);
    RetCode = FLASH_OPR_SUCESSS;
    return RetCode;
}

/**
 * @brief Set the error information for the flash.
 * 
 * This function sets the error information for the flash. The error
 * information is used to indicate the type of error that occurred.
 * 
 * @param[in] FlashStatus The status of the flash.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the operation was successful.
 *         - FLASH_OPR_FAILED: If the operation failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */

FlashErr_t SetErrorInfo(FlashStatus_t FlashStatus)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;

    SET(FLASH->SR,FlashStatus);

    RetCode = GET(FLASH->SR,FlashStatus);
    return RetCode;

}
/**
 * @brief Retrieve the error information for the flash.
 * 
 * This function retrieves the error information for the flash. The error
 * information is used to indicate the type of error that occurred.
 * 
 * @param[out] FlashStatus Pointer to store the status of the flash.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the operation was successful.
 *         - FLASH_OPR_FAILED: If the operation failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */
FlashErr_t GetErrorInfo(FlashStatus_t FlashStatus)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;
    RetCode = GET(FLASH->SR,FlashStatus);
    return RetCode;

}

/**
 * @brief Set the flash control register.
 * 
 * This function sets the flash control register with the desired value. The
 * value is a bit field where each bit corresponds to a specific control signal.
 * The control signals are:
 * - FLASH_CR_PNB: Page number bit.
 * - FLASH_CR_BKER: Bank erase bit.
 * - FLASH_CR_MER: Mass erase bit.
 * - FLASH_CR_PER: Page erase bit.
 * - FLASH_CR_STRT: Start bit.
 * - FLASH_CR_LOCK: Lock bit.
 * - FLASH_CR_OBL_LAUNCH: Launch bit for the option byte loading.
 * - FLASH_CR_FSTPG: Fast programming bit.
 * - FLASH_CR_EOPIE: End of operation interrupt enable bit.
 * - FLASH_CR_ERRIE: Error interrupt enable bit.
 * - FLASH_CR_OBL_RDPRT: Option byte loading read protection bit.
 * - FLASH_CR_RDPRT: Read protection bit.
 * - FLASH_CR_WRP: Write protect bit.
 * - FLASH_CR_PNBSTR: Page number bit strap.
 * - FLASH_CR_PNBREL: Page number bit release.
 * - FLASH_CR_OPTSTRT: Option start bit.
 * - FLASH_CR_OPTLOCK: Option lock bit.
 * - FLASH_CR_OPTWIP: Option write in progress bit.
 * - FLASH_CR_BUSY: Busy bit.
 * - FLASH_CR_WRPRT: Write protect bit read.
 * - FLASH_CR_RDP: Read protection bit read.
 * - FLASH_CR_OTP: One time programming bit read.
 * - FLASH_CR_BYP: Boot loader protection bit read.
 * - FLASH_CR_PRG: Programming bit read.
 * - FLASH_CR_EOP: End of operation bit read.
 * - FLASH_CR_WRPRT0: Write protect bit read.
 * - FLASH_CR_WRPRT1: Write protect bit read.
 * - FLASH_CR_WRPRT2: Write protect bit read.
 * - FLASH_CR_WRPRT3: Write protect bit read.
 * 
 * @param[in] FlashCtrl The desired value for the flash control register.
 * @param[in] En        true to enable the bit, false to disable it.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the operation was successful.
 *         - FLASH_OPR_FAILED: If the operation failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */
FlashErr_t SetFlashCrRegister(FlashControl_t FlashCtrl, bool En)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;
    
    // FIXED: Allow all bits EXCEPT PNB range to be set individually
    // PNB should be set using SelectPageNumber() function
    if(FlashCtrl >= FLASH_CR_PNB_Pos && FlashCtrl <= FLASH_CR_PNB_Pos + 7) {
        // PNB bits should use SelectPageNumber function instead
        return FLASH_OPR_FAILED;
    }
    
    SET_BITS(FLASH->CR, FlashCtrl, 1, En);
    RetCode = (GET_BITS(FLASH->CR, FlashCtrl, 1) == En) ? FLASH_OPR_SUCESSS : FLASH_OPR_FAILED;
    
    return RetCode;
    
}

FlashErr_t GetFlashCrRegister(FlashControl_t controlBit)
{
    return GET(FLASH->CR, controlBit); 
}

/**
 * @brief Set the flash page number.
 * 
 * This function sets the flash page number to the desired value. The page
 * number is a bit field where each bit corresponds to a specific page number.
 * 
 * @param[in] PageNum The desired page number.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the operation was successful.
 *         - FLASH_OPR_FAILED: If the operation failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */
FlashErr_t SelectPageNumber(uint8_t PageNum)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;
    SET_BITS(FLASH->CR,FLASH_CR_PNB_Pos,8,PageNum);
    RetCode = (GET_BITS(FLASH->CR,FLASH_CR_PNB_Pos,8)==PageNum);
    return RetCode;
}

/**
 * @brief Retrieve the error address for the ECC.
 * 
 * This function retrieves the address where an ECC error occurred.
 * 
 * @param[out] ecc_address Pointer to store the address of the ECC error.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the operation was successful.
 *         - FLASH_OPR_FAILED: If the operation failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */
FlashErr_t GetErrorAddressEcc(uint32_t *ecc_address)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;
    *ecc_address = GET_BITS(FLASH->ECCR,FLASH_ECCR_ADDR_ECC_Pos,32);
    RetCode = FLASH_OPR_SUCESSS;
    return RetCode;
}

/**
 * @brief Enable or disable the ECC interrupt.
 * 
 * This function enables or disables the ECC interrupt for the specified
 * register.
 * 
 * @param[in] EccReg The ECC register to enable or disable the interrupt for.
 * @param[in] En     true to enable the interrupt, false to disable it.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the operation was successful.
 *         - FLASH_OPR_FAILED: If the operation failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */
FlashErr_t EnableEccInterrupt(EccReg_t EccReg, bool En)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;
    SET_BITS(FLASH->ECCR,EccReg,1,En);
    RetCode = (GET_BITS(FLASH->ECCR,EccReg,1)==En);;
    return RetCode;
}

/**
 * @brief Get ECC correction and detection status.
 * 
 * This function retrieves the status of ECC correction and detection from the
 * flash memory. It provides information on whether an ECC correction or
 * detection event has occurred.
 * 
 * @param[out] EccCorr Pointer to store the ECC correction status. True if an
 *                     ECC correction event occurred, otherwise false.
 * @param[out] EccDet  Pointer to store the ECC detection status. True if an
 *                     ECC detection event occurred, otherwise false.
 * 
 * @return FlashErr_t 
 *         - FLASH_OPR_SUCESSS: If the operation was successful.
 *         - FLASH_OPR_FAILED: If the operation failed.
 * 
 * @note Ensure that the flash is not busy before calling this function.
 */


FlashErr_t GetEccCorrAndDet(bool *EccCorr , bool *EccDet)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;
    *EccCorr = GET_BITS(FLASH->ECCR,FLASH_ECCR_ECCC_Pos,1);
    *EccDet = GET_BITS(FLASH->ECCR,FLASH_ECCR_ECCD_Pos,1);
    RetCode = FLASH_OPR_SUCESSS;
    return RetCode;
}


FlashErr_t FlashErasePage(uint8_t PageNum)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;

    UnlockFlashSeq();
    if(GET_BITS(FLASH->CR, FLASH_CR_LOCK_Pos, 1) == 1) {
        // Flash is still locked - unlock failed
        return FLASH_OPR_FAILED;
    }
    RetCode = SelectPageNumber(PageNum);
    if(RetCode != FLASH_OPR_SUCESSS) {
        return RetCode;
    }

    RetCode = SetFlashCrRegister(PAGE_ERASE_ENABLE,true);
    
    if(RetCode != FLASH_OPR_SUCESSS) {
        return RetCode;
    }

    SetFlashCrRegister(START_ERASE,true);

    while(GetFlashCrRegister(BUSY_ERR)!=0);
    
    SetErrorInfo(EOP_ST);

    RetCode = SetFlashCrRegister(PAGE_ERASE_ENABLE,false);

    return RetCode;

}


FlashErr_t FlashEraseMass(void)
{
    FlashErr_t RetCode = FLASH_OPR_FAILED;

    RetCode = SetFlashCrRegister(MASS_ERASE_ENABLE,true);

    if(RetCode == FLASH_OPR_SUCESSS)
    {

        /* Disable the Page  erase bit according to datasheet */
        SetFlashCrRegister(PAGE_ERASE_ENABLE,false);
        SetFlashCrRegister(START_ERASE,true);
        /*Wait till it is cleared by the flash , no timeout because its flash erase operation*/
        while(GetFlashCrRegister(START_ERASE)!=0);
    }
    return RetCode;
}

