#include <reg51.H>

void (*pInt)(void);
// extern unsigned time;
char ini_time_low,ini_time_high;

void Timer0_Init(void (*pFunc)(void))
{
    /* mode set */
    TMOD&=0xF0; //clear Timer1.
    TMOD|=0x01; //set Timer0 mode 1.
    /* interrupt registers set */
    ET0=1;
    PT0=0;	//priority
    EA=1;
    /* clear int signal */
    TF0=0;
    /* set int program */
    pInt=pFunc;
}

// void Timer0_Set(unsigned ini_time)
// {
    
//     ini_time_low=ini_time%256;
//     ini_time_high=ini_time/256;
// }


void Timer0_Set(unsigned us,unsigned char mode)
{
    switch(mode)
    {
        case 0:
            us=65535-us;
        case 1:
            ini_time_low=us%256;
            ini_time_high=us/256;
        default:
            break;
    }	
}

void Timer0_Start(void)
{
    TL0=ini_time_low;
    TH0=ini_time_high;
    TR0=1;
}

void Timer0_Pause(void)
{
    TR0=0;
}

//stop and clear TX.
void Timer0_Reset(void)
{
    TR0=0;
    TF0=0;
    TL0=0;
    TH0=0;
}

void Timer0_Int(void) interrupt 1
{
    pInt();
    TL0=ini_time_low;
    TH0=ini_time_high;
}

void Timer0_Continue(void)
{
    TR0=1;
}

bit Timer0_IsRunning(void)
{
    return TR0;
}