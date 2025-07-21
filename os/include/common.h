#ifndef OS_INCLUDE_COMMON_H
#define OS_INCLUDE_COMMON_H

#include <stdbool.h>

#define GET(x,pos)   ((x & 1<<pos) >> pos)
#define SET(x,pos)   (x |= (1<<pos))
#define CLEAR(x,pos)   (x &= ~(1<<pos))
#define TOGGLE(x,pos) (x ^= 1<<pos)
#define SET_BITS(v, p, n, new_val) \
  ((v) = ((v) & ~(((1UL << (n)) - 1) << (p))) | (((new_val) & ((1UL << (n)) - 1)) << (p)))

#define GET_BITS(v, p, n) \
  (((v) >> (p)) & ((1UL << (n)) - 1))


typedef enum
{
    FLASH_OPR_FAILED,
    FLASH_OPR_SUCESSS,
    FLASH_OPR_BUSY,
}FlashErr_t;

#endif /* OS_INCLUDE_COMMON_H */
