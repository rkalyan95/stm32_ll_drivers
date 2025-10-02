#include <stm32l433xx.h>
#include "core_cm4.h"
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"
#include "stm32l433_ll_gpio_cfg.h"
#include "stm32l433_ll_gpio.h"
#include "stm32_ll_exti.h"
#include "System_Fsm.h"

#define DEBOUNCE_TIMER   4000

uint8_t readmymessage[256];
uint32_t debouncetimer=0;
uint8_t initalBtnLvl;
btn_evt_t fsmEvt;
btn_evt_t btn_event = BTN_RELEASED;
led_states_t led_state = LED_OFF;
uint8_t btn_level;


btn_evt_t finalBtnEvt;
led_states_t led_state_main = LED_OFF;




uartfsm_t uartfsm[] = 
{
  {.cmd = "stm --version\r", .response = "version 1.0\r\n",.function = sendresponse,.cb = NULL},
  {.cmd = "stm led --on\r", .response = "led on\r\n",.function = sendresponse,.cb = LedOn},
  {.cmd = "stm led --off\r", .response = "led off\r\n",.function = sendresponse,.cb = LedOff},
  {.cmd = "stm get --led\r", .response = "led reading state..\r\n",.function = sendresponse,.cb = getledstate},
};

#define commanddbsize (sizeof(uartfsm)/sizeof(uartfsm[0]))


void __isr_exti15_10(void)
{
    
    btn_level = Gpio_GetPin(button_pin.port,button_pin.pin);

    if(btn_level == HIGH)
    {
        btn_event = BTN_PRESSED;
    }
    else if(btn_level==LOW)
    {
        btn_event = BTN_RELEASED;
    }

    ClearPendingInterrupt(button_pin.pin);
   
}

btn_evt_t handledebouncecrudeway(void)
{
    fsmEvt = BTN_NONE;
    debouncetimer++;

    if (btn_event != BTN_NONE && debouncetimer >= DEBOUNCE_TIMER)
    {
        uint8_t finalBtnLvl = Gpio_GetPin(button_pin.port, button_pin.pin);

        fsmEvt = (finalBtnLvl == HIGH) ? BTN_PRESSED : BTN_RELEASED;

        debouncetimer = 0;
        btn_event = BTN_NONE;
    }

    return fsmEvt;
}


void LedOn(void)
{
    Gpio_SetLevel(led_pin.port,led_pin.pin,HIGH);

}

void LedOff(void)
{
    Gpio_SetLevel(led_pin.port,led_pin.pin,LOW);

}

const Fsm_t myLedSm[] = {
    {.current_state=LED_OFF,.evt=BTN_PRESSED,.next_state=LED_ON,.Dispatch=LedOn},
    {.current_state=LED_OFF,.evt=BTN_RELEASED,.next_state=LED_OFF,.Dispatch=LedOff},
    {.current_state=LED_ON,.evt=BTN_PRESSED,.next_state=LED_ON,.Dispatch=LedOn},
    {.current_state=LED_ON,.evt=BTN_RELEASED,.next_state=LED_OFF,.Dispatch=LedOff}

    };


#define FS_CNT    (sizeof(myLedSm)/sizeof(myLedSm[0]))


static void Fsm_Init(void)
{
    LedOff();
}

led_states_t Fsm_Run(btn_evt_t evt , led_states_t currentstate)
{
    led_states_t nextState = currentstate;
    for(uint32_t i=0;i<FS_CNT;i++)
    {
        if(evt==myLedSm[i].evt && currentstate == myLedSm[i].current_state)   /* Match Found */
        {
            myLedSm[i].Dispatch();
            nextState = myLedSm[i].next_state;
            break;
        }
    }

    return nextState;

}

void LedBtnFsm_Run(void)
{
  finalBtnEvt = BTN_NONE;
  finalBtnEvt = handledebouncecrudeway();
        
  led_state_main = Fsm_Run(finalBtnEvt,led_state_main);
}


static uint32_t str_len(const char *s1)
{
  uint32_t len=0;
  while(*s1!='\0')
  {
    len++;
    s1++;
  }

  return len;

}


static bool str_equal(const char *s1 , const char *s2)
{
  if(str_len(s1) !=  str_len(s2))
  {
    return false;
  }
  if(s1 == NULL || s2 == NULL)
  {
    return false;
  }
  while((*s1 != '\0') && (*s2!='\0'))
  {
    if(*s1 != *s2)
    {
      return false;
    }

    s1++;
    s2++;
  }

  return true;
}

static void str_allsmallcase(char *s1)
{
    while(*s1!='\0')
    {
        if(*s1>='A' && *s1<='Z')
        {
            *s1=*s1+32;
        }
        s1++;
    }
}

static void joinstr(const uint8_t *s1 , const uint8_t *s2)
{
  
}

err_t sendresponse(uint8_t *ptr)
{
   printdebugstring((const uint8_t *)ptr);
}

void getledstate(void)
{
    uint8_t state = 0;
    state =Gpio_GetPin(led_pin.port,led_pin.pin);
    if(state == 1)
    {
      printdebugstring("led state HIGH\r\n");
    }
    else if(state == 0)
    {
      printdebugstring("led state LOW\r\n");
    }
}



void UartFsm_Run(void)
{
    bool matchfound=0;
    err_t err_st = readuntillnewline(readmymessage);
    if(err_st==error_ok)
    {
      str_allsmallcase(readmymessage);
      for(uint32_t i=0;i<commanddbsize;i++)
      {
          if(str_equal(readmymessage,uartfsm[i].cmd))
          {
              matchfound = 1;
              if(uartfsm[i].function!=NULL)
              {
                uartfsm[i].function(uartfsm[i].response);
              }
              if(uartfsm[i].cb!=NULL )
              {
                 uartfsm[i].cb();
              }
              break;
          }
          else
          {
          
          }
      }
      if(matchfound==0)
      {
        printdebugstring("Invalid command\r\n");
      }
      
    }

}