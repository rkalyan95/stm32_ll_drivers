#ifndef SYSTEM_FSM_H
#define SYSTEM_FSM_H

#include "stm32_ll_usart.h"
#include <stddef.h>
#include <string.h>
#include <stdint.h>
typedef void (*execution_t)(void);

typedef enum
{
    LED_OFF,
    LED_ON
}led_states_t;

typedef enum
{
    BTN_PRESSED,
    BTN_RELEASED,
    BTN_NONE,
}btn_evt_t;


typedef struct
{
    led_states_t current_state;
    led_states_t next_state;
    btn_evt_t evt;
    execution_t Dispatch;
}Fsm_t;

typedef err_t (*sendresponse_t)(uint8_t *ptr);
typedef void (*callback_t)(void);

typedef struct uartcmddb_
{
    const uint8_t *cmd;
    const uint8_t *response;
    sendresponse_t function;
    callback_t cb;

}uartfsm_t;

err_t sendresponse(uint8_t *ptr);
void UartFsm_Run(void);

void LedOn(void);
void LedOff(void);
void getledstate(void);

led_states_t Fsm_Run(btn_evt_t evt , led_states_t currentstate);
btn_evt_t handledebouncecrudeway(void);
void LedBtnFsm_Run(void);
#endif // SYSTEM_FSM_H

