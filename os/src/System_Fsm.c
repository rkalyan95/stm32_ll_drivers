#include <stm32l433xx.h>
#include "core_cm4.h"
#include "stm32l433_ll_rcc_cfg.h"
#include "stm32l433_ll_rcc.h"
#include "stm32l433_ll_gpio_cfg.h"
#include "stm32l433_ll_gpio.h"
#include "stm32_ll_exti.h"
#include "System_Fsm.h"
#include "servo.h"
#include <stdlib.h>

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
uint8_t dc;

float dutycurrent=0.0f;
float dutysaved=0.0f;

const Fsm_t myLedSm[] = {
    {.current_state=LED_OFF,.evt=BTN_PRESSED,.next_state=LED_ON,.Dispatch=LedOn},
    {.current_state=LED_OFF,.evt=BTN_RELEASED,.next_state=LED_OFF,.Dispatch=LedOff},
    {.current_state=LED_ON,.evt=BTN_PRESSED,.next_state=LED_ON,.Dispatch=LedOn},
    {.current_state=LED_ON,.evt=BTN_RELEASED,.next_state=LED_OFF,.Dispatch=LedOff}

    };





uartfsm_t uartfsm[] = 
{
  {.prefixcmd = 0,.cmd = "stm --version\r", .response = "version 1.0\r\n",.function = sendresponse,.cb = NULL},
  {.prefixcmd = 0,.cmd = "stm led --on\r", .response = "led on\r\n",.function = sendresponse,.cb = setledon},
  {.prefixcmd = 0,.cmd = "stm led --off\r", .response = "led off\r\n",.function = sendresponse,.cb = setledoff},
  {.prefixcmd = 0,.cmd = "stm get --led\r", .response = "led reading state..\r\n",.function = sendresponse,.cb = getledstate},
  {.prefixcmd = 1,.cmd = "stm servo=", .response = "setting servo angle..\r\n",.function = sendresponse,.cb = servoanglerxed},
  {.prefixcmd = 0,.cmd = "stm --servo\r", .response = "reading servo dc..\r\n",.function = sendresponse,.cb = servofeedback},
};

#define commanddbsize (sizeof(uartfsm)/sizeof(uartfsm[0]))
#define FS_CNT    (sizeof(myLedSm)/sizeof(myLedSm[0]))

static void Fsm_Init(void)
{
    LedOff();
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

void getledstate(uint8_t *param)
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

static float basic_atof(const char *s)
{
    float result = 0.0f;
    float scale = 1.0f; // Used to track powers of 10 after the decimal
    int sign = 1;
    bool after_decimal = false;

    // 1. Handle Sign
    if (*s == '-') {
        sign = -1;
        s++;
    } else if (*s == '+') {
        s++;
    }

    // 2. Process Digits
    while (*s != '\0') 
    {
        if (*s == '.') {
            // Found the decimal point
            if (after_decimal) break; // Should not happen in well-formed input
            after_decimal = true;
        } 
        else if (*s >= '0' && *s <= '9') {
            
            if (after_decimal) {
                // Digits after the decimal point
                scale /= 10.0f; // Scale becomes 0.1, 0.01, 0.001, etc.
                result = result + (*s - '0') * scale;
            } else {
                // Digits before the decimal point
                result = result * 10.0f + (*s - '0');
            }
        } 
        else {
            // Stop on any non-digit/non-decimal character (like 'e', 'f', space, etc.)
            break; 
        }
        s++;
    }

    // 3. Return the signed result
    return sign * result;
}

static int is_prefix_of(const char *haystack, const char *needle,uint8_t *outstr)
{
    uint8_t idx = 0;
    while (*needle != '\0')
    {
        if (*haystack != *needle)
        {
            return 0;
        }
        
        if (*haystack == '\0')
        {
            return 0;
        }

        haystack++;
        needle++;
    }

    while(*haystack!='\r')
    {
       outstr[idx++] = *haystack;
       haystack++;
    }
    outstr[idx] = '\0';

    return 1;
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




void servoanglerxed(uint8_t *param)
{
  uint8_t str[256];
  float anglef = 0.0f;
  float dutycycle = 0.0f;
  anglef = basic_atof((const char *)param);
  TurnServo(anglef,2);
  printdebugstring("Updated Servo\r\n");
}

void servofeedback(uint8_t *param)
{

    dc = (uint8_t)(dutysaved*100.0f);
    //printdebugstring("Servo Feedback Rxed\r\n");
    Uart_ll_SendByte(dc+0x30);
    printdebugstring(" %duty cycle\r\n");

}


void setledon(uint8_t *param)
{
  LedOn();
}

void setledoff(uint8_t *param)
{
  LedOff();
}

void UartFsm_Run(void)
{
    uint8_t servorx[8];
    bool matchfound=0;
    
    err_t err_st = readuntillnewline(readmymessage);
    dutycurrent = GetDutyCycle(1);
    if(dutycurrent!=-1)
    {
      if(dutysaved!=dutycurrent)
      {
        dutysaved = dutycurrent;
      }
    }
    if(err_st==error_ok)
    {
      str_allsmallcase(readmymessage);
      for(uint32_t i=0;i<commanddbsize;i++)
      {
        if(uartfsm[i].prefixcmd == 0)
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
                 uartfsm[i].cb(NULL);
              }
              break;
          }
        }
        else if(uartfsm[i].prefixcmd == 1)
        {
          if(is_prefix_of(readmymessage, uartfsm[i].cmd,servorx) == 1)
          {
            
              matchfound = 1;
              if(uartfsm[i].cb!=NULL )
              {
                 uartfsm[i].cb(servorx);
              }
              break;
          }
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