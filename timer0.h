#ifndef _TIMER_H_
#define _TIMER_H_

void Timer0_Init(void (*pInt)(void));

//     set an initial time.
//     mode 0: counter.
//     mode 1: timer.
void Timer0_Set(unsigned us,unsigned char mode);
void Timer0_Start(void);
void Timer0_Pause(void);
void Timer0_Reset(void);
void Timer0_Continue(void);
bit Timer0_IsRunning(void);

// void Timer0_Count(unsigned us);
// void Timer0_Set(unsigned ini_time);
#endif