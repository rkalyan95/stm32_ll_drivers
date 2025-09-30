#ifndef OS_INCLUDE_COMMON_H
#define OS_INCLUDE_COMMON_H

#include <stdbool.h>
#include <stdint.h>
#define GET(x,pos)   ((x & 1<<pos) >> pos)
#define SET(x,pos)   (x |= (1<<pos))
#define CLEAR(x,pos)   (x &= ~(1<<pos))
#define TOGGLE(x,pos) (x ^= 1<<pos)
#define BITS_MASK(n_val) \
  (((n_val) >= (sizeof(unsigned long) * 8)) ? (~0UL) : ((1UL << (n_val)) - 1))

#define SET_BITS(v, p, n, new_val) \
  ((v) = ((v) & ~(BITS_MASK(n) << (p))) | (((new_val) & BITS_MASK(n)) << (p)))

#define GET_BITS(v, p, n) \
  (((v) >> (p)) & BITS_MASK(n))



#endif /* OS_INCLUDE_COMMON_H */
