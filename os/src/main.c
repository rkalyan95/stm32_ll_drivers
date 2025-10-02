/*led is on pb13*/
#include <stdint.h>

#include <stm32l433xx.h>
#include "core_cm4.h"
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"
#include "stm32l433_ll_gpio_cfg.h"
#include "stm32l433_ll_gpio.h"
#include "stm32_ll_exti.h"
#include "System_Fsm.h"
#include "stm32_ll_flash.h"
#include "stm32_ll_flash_cfg.h"
#include "stm32_ll_timers_cfg.h"
#include "servo.h"
#include "stm32_ll_usart.h"

FirmwareVersion_t Version;

float angle=0.0f;
float dutycycle = 0.0f;



static void delayrndom(uint32_t dly)
{
    for(uint32_t i=0;i<dly;i++)
    {
        __NOP();
    }
}

static void boot_init(void)
{
    uint16_t ccr=0;
    FlashErr_t RetCode;
    
    InitAllClocks();
    Gpio_ConfigAllPorts();
#if 0
    RetCode = ReadFirmwareDetails(&Version);  //this is causing issue , even the writes do not work

    if(RetCode!=FLASH_OPR_SUCESSS)
    {
        Gpio_SetLevel(led_pin.port,led_pin.pin,HIGH);
        delayrndom(100000);
        RetCode = UpdateFirmwareInFlash();
        Gpio_SetLevel(led_pin.port,led_pin.pin,LOW);
    }
#endif
     __enable_irq();
    NVIC_SetPriority(EXTI15_10_IRQn, 47);
    NVIC_EnableIRQ(EXTI15_10_IRQn);      // Enable the interrupt in the NVIC
    ServoInit();
    init_usart();
    delayrndom(50000);
    printdebugstring("Welcome to STM32 UART\r\n");
}


void main(void)
{
    boot_init();
    while(1)
    {
        LedBtnFsm_Run();
        UartFsm_Run();
    }
}


