#ifndef SYSTEM_FSM_H
#define SYSTEM_FSM_H

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


led_states_t Fsm_Run(btn_evt_t evt , led_states_t currentstate);
btn_evt_t handledebouncecrudeway(void);
#endif // SYSTEM_FSM_H

