#if !defined(__TIMER_IMPLEMENTATION_H__)
#define __TIMER_IMPLEMENTATION_H__
#include <stdbool.h>
#include <stdint.h>

#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"

#include "driverlib/sysctl.h"
#include "driverlib/timer.h"

extern uint8_t freqCarry;
extern uint32_t freqMeasure;

void Time0A_Handler(void);

void ConfigTimerCounter(void);

#endif // __TIMER_IMPLEMENTATION_H__
