#ifndef _BEEP_H_
#define _BEEP_H_

/* use timer to play a sym during Beep() and BeepStop()  */

/* use timer0 to drive buzzer */
void BeepInit(void(*Beep)(void));
/* input T/2 */
void Beep(unsigned ht);
/* stop beeping */
void BeepStop(void);
/* reset timer0 to mute beeper */
void BeepReset(void);

/* eg */
// BeepInit(Beep);
// ...
// for(i=1;i<=7;i++)
//         {
//             if(GetKey(i))
//                 Beep(SymTable[flag][i]);
//             if(GetKeyUp(i))
//                 BeepStop();
//         }


#endif