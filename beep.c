#include"timer0.h"
void BeepInit(void(*Beep)(void))
{
    Timer0_Init(Beep);
}
    
static bit beeping;
void Beep(unsigned ht)
{
    if(beeping==0)
    {
        beeping=1;
        if(ht!=0)
        {
            Timer0_Set(ht,0);
            Timer0_Start();
        }
        else
            Timer0_Pause();
    }
}

void BeepStop(void)
{
    beeping=0;
    Timer0_Pause();
}

void BeepReset(void)
{
    beeping=0;
    Timer0_Reset();
}