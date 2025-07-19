#include "stm32_ll_exti.h"
#include "core_cm4.h"



#define GET(x,pos)   ((x & 1<<pos) >> pos)
#define SET(x,pos)   (x |= (1<<pos))
#define CLEAR(x,pos)   (x &= ~(1<<pos))
#define TOGGLE(x,pos) (x ^= 1<<pos)
#define SET_BITS(v, p, n, new_val) \
  ((v) = ((v) & ~(((1UL << (n)) - 1) << (p))) | (((new_val) & ((1UL << (n)) - 1)) << (p)))

#define GET_BITS(v, p, n) \
  (((v) >> (p)) & ((1UL << (n)) - 1))

#define TRUE 1
#define FALSE 0


/**
 * @brief      Configure Interrupt Mask
 *
 * @param[in]  exti_line: External Interrupt line to configure
 * @param[in]  En: Enable/Disable interrupt mask
 *
 * @return     Error code
 *
 * @retval     EXTI_SUCCESS if the configuration is successful
 * @retval     EXTI_FAILED if the configuration is not successful
 */
ErrorExti_t ConfigureInterruptMask(Exti_lines_t exti_line,bool En)
{
    ErrorExti_t RetCode = EXTI_FAILED;

    if(exti_line <= EXTI_LPUART1_WAKEUP_31)
    {
        SET_BITS(EXTI->IMR1,exti_line,1,En);
        RetCode = (GET_BITS(EXTI->IMR1,exti_line,1)==En);
    }
    else if(exti_line > EXTI_LPUART1_WAKEUP_31 && exti_line<=EXTI_LCD_WAKEUP_39)
    {
        SET_BITS(EXTI->IMR2,exti_line-EXTI_LPTIM1_32,1,En);
        RetCode = (GET_BITS(EXTI->IMR2,exti_line-EXTI_LPTIM1_32,1)==En);
    }
    else
    {
        RetCode = EXTI_FAILED;
    }

    return  RetCode;
    
}

/**
 * @brief      Configure Event Mask
 *
 * @param[in]  exti_line: External Interrupt line to configure
 * @param[in]  En: Enable/Disable event mask
 *
 * @return     Error code
 *
 * @retval     EXTI_SUCCESS if the configuration is successful
 * @retval     EXTI_FAILED if the configuration is not successful
 */
ErrorExti_t ConfigureEventMask(Exti_lines_t exti_line,bool En)
{
    ErrorExti_t RetCode = EXTI_FAILED;
    if(exti_line <= EXTI_LPUART1_WAKEUP_31)
    {
        SET_BITS(EXTI->EMR1,exti_line,1,En);
        RetCode = (GET_BITS(EXTI->EMR1,exti_line,1)==En);
    }
    else if(exti_line > EXTI_LPUART1_WAKEUP_31 && exti_line<=EXTI_LCD_WAKEUP_39)
    {
        SET_BITS(EXTI->EMR2,exti_line-EXTI_LPTIM1_32,1,En);
        RetCode = (GET_BITS(EXTI->EMR2,exti_line-EXTI_LPTIM1_32,1)==En);
    }
    else
    {
       RetCode = EXTI_FAILED;
    }
   
    return RetCode;
}

/**
 * @brief      Configure Rising Edge Interrupt
 *
 * @param[in]  exti_line: External Interrupt line to configure
 * @param[in]  En: Enable/Disable rising edge interrupt
 *
 * @return     Error code
 *
 * @retval     EXTI_SUCCESS if the configuration is successful
 * @retval     EXTI_FAILED if the configuration is not successful
 */
ErrorExti_t ConfigureRisingEdgeInterrupt(Exti_lines_t exti_line,bool En)
{
    ErrorExti_t RetCode = EXTI_FAILED;
    if(exti_line <= EXTI_COMP2_OUT_22)
    {
        SET_BITS(EXTI->RTSR1,exti_line,1,En);
        RetCode = (GET_BITS(EXTI->RTSR1,exti_line,1)==En);
    }
    else if(exti_line >= EXTI_PVM1_WAKEUP_35 && exti_line<=EXTI_PVM4_WAKEUP_38)
    {
        SET_BITS(EXTI->RTSR2,exti_line-EXTI_LPTIM1_32,1,En);
        RetCode = (GET_BITS(EXTI->RTSR2,exti_line-EXTI_LPTIM1_32,1)==En);
    }
    else
    {
        RetCode = EXTI_FAILED;
    }

    return RetCode;
}

/**
 * @brief      Configure Falling Edge Interrupt
 *
 * @param[in]  exti_line: External Interrupt line to configure
 * @param[in]  En: Enable/Disable falling edge interrupt
 *
 * @return     Error code
 *
 * @retval     EXTI_SUCCESS if the configuration is successful
 * @retval     EXTI_FAILED if the configuration is not successful
 */
ErrorExti_t ConfigureFallingEdgeInterrupt(Exti_lines_t exti_line,bool En)
{
    ErrorExti_t RetCode = EXTI_FAILED;
    if(exti_line <= EXTI_COMP2_OUT_22)
    {
        SET_BITS(EXTI->FTSR1,exti_line,1,En);
        RetCode = (GET_BITS(EXTI->FTSR1,exti_line,1)==En);
    }
    else if(exti_line >= EXTI_PVM1_WAKEUP_35 && exti_line<=EXTI_PVM4_WAKEUP_38)
    {
        SET_BITS(EXTI->FTSR2,exti_line-EXTI_LPTIM1_32,1,En);
        RetCode = (GET_BITS(EXTI->FTSR2,exti_line-EXTI_LPTIM1_32,1)==En);
    }
    else
    {
        RetCode = EXTI_FAILED;
    }
   return RetCode;
}

/**
 * @brief      Configures the software interrupt for a specified EXTI line.
 *
 * @param[in]  exti_line: The EXTI line number to configure.
 * @param[in]  En: Boolean value to enable (true) or disable (false) the interrupt.
 *
 * @return     EXTI_SUCCESS if the configuration was successful, EXTI_FAILED otherwise.
 *
 * This function sets or clears the software interrupt for the given EXTI line
 * by modifying the appropriate SWIER register. Only lines within the defined 
 * range can be configured.
 */

ErrorExti_t ConfigureSoftwareInterrupt(Exti_lines_t exti_line,bool En)
{
    ErrorExti_t RetCode = EXTI_FAILED;
    if(exti_line <= EXTI_COMP2_OUT_22)
    {
        SET_BITS(EXTI->SWIER1,exti_line,1,En);
        RetCode = (GET_BITS(EXTI->SWIER1,exti_line,1)==En);
    }
    else if(exti_line >= EXTI_PVM1_WAKEUP_35 && exti_line<=EXTI_PVM4_WAKEUP_38)
    {
        SET_BITS(EXTI->SWIER2,exti_line-EXTI_LPTIM1_32,1,En);
        RetCode = (GET_BITS(EXTI->SWIER2,exti_line-EXTI_LPTIM1_32,1)==En);
    }
    else
    {
        RetCode = EXTI_FAILED;
    }
    return RetCode;
}

/**
 * @brief      Check if a given EXTI interrupt is being serviced
 *
 * @param[in]  exti_line: The EXTI line to check
 *
 * @return     1 if the interrupt is being serviced, 0 otherwise
 */
uint8_t IsInterruptServiced(Exti_lines_t exti_line)
{
    uint8_t PendingStatus=1;
    if(exti_line <= EXTI_COMP2_OUT_22)
    {
        PendingStatus = GET_BITS(EXTI->PR1,exti_line,1);
    }
    else if(exti_line >= EXTI_PVM1_WAKEUP_35 && exti_line<=EXTI_PVM4_WAKEUP_38)
    {
        PendingStatus = GET_BITS(EXTI->PR2,exti_line-EXTI_LPTIM1_32,1);
    }
    else
    {
        PendingStatus = 0;
    }

    return PendingStatus;
    
}



/**
  \brief   Clear Pending Interrupt
  \details Clears the pending bit of a specified EXTI line.
  \param [in]      exti_line  Specifies the EXTI line to clear the pending bit.
  \return          EXTI_SUCCESS if the pending bit was cleared successfully.
                   EXTI_FAILED if the specified EXTI line is invalid.
  \note    Handles registers based on the line number.
 */

ErrorExti_t ClearPendingInterrupt(Exti_lines_t exti_line)
{
    ErrorExti_t RetCode = EXTI_SUCCESS;
    if(exti_line <= EXTI_COMP2_OUT_22)
    {
        SET_BITS(EXTI->PR1,exti_line,1,1);
        RetCode = (GET_BITS(EXTI->PR1,exti_line,1)==0);
    }
    else if(exti_line >= EXTI_PVM1_WAKEUP_35 && exti_line<=EXTI_PVM4_WAKEUP_38)
    {
        SET_BITS(EXTI->PR2,exti_line-EXTI_LPTIM1_32,1,1);
        RetCode = (GET_BITS(EXTI->PR2,exti_line-EXTI_LPTIM1_32,1)==0);
    }   
    else
    {
        RetCode = EXTI_FAILED;
    }

    return RetCode;
    //handle both the registers here based on the line number passed
}
