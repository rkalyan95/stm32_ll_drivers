#ifndef SERVO_H_
#define SERVO_H_

#include <stdint.h>
#include <stddef.h>


#define INPUT_FREQUENCY    24000000UL
#define MIN_PW             0.5f
#define MAX_PW             2.5f
#define MAX_ANGLE          180.f
#define MIN_ANGLE          0.f

#define SERVOANGLE_TOMS(ANGLE)    ((MIN_PW + ((MAX_PW - MIN_PW)*(ANGLE/(MAX_ANGLE-MIN_ANGLE)))))

#define TIMER_ARRVALUE     159  
#define TIMER_PRESCALER    2999
#define AUTO_RELOADED       1  

#define OUTPUT_FREQENCY    ((INPUT_FREQUENCY)/((TIMER_PRESCALER+1)*(TIMER_ARRVALUE+1)))


#define MS_TO_TICKS(MS) \
    ((uint32_t)((MS * OUTPUT_FREQENCY * (TIMER_ARRVALUE+1)) / 1000.0f))


#define SERVOANGLETOTICKS(angle)   MS_TO_TICKS(SERVOANGLE_TOMS(angle))


void ServoInit(void);
void TurnServo(float angle,uint8_t chIdx);
float GetDutyCycle(uint8_t chIdx);

#endif  // SERVO_H_
