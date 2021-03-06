#include "timer_implementation.h"

uint8_t freqCarry = 0;
uint32_t freqMeasure = 0;

void ConfigTimerCounter(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0));

	TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_CAP_COUNT_UP);
	TimerControlEvent(TIMER0_BASE, TIMER_A, TIMER_EVENT_BOTH_EDGES);
	TimerLoadSet(TIMER0_BASE, TIMER_A, 0xFFFF);
	TimerMatchSet(TIMER0_BASE, TIMER_A, 0xFFFF);
	TimerPrescaleMatchSet(TIMER0_BASE, TIMER_A, 0x00FF);
	TimerIntEnable(TIMER0_BASE, TIMER_CAPA_MATCH);
	TimerIntRegister(TIMER0_BASE, TIMER_A, Time0A_Handler);
	TimerEnable(TIMER0_BASE, TIMER_A);
}
