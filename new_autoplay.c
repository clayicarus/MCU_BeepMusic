#include <REG51.H>
#include"beep.h"
#include"delay.h"

#include"new_symtable.h"
#include"new_music.h"

//use timer0
sbit BEEP = P1 ^ 5;

void _beep_(void)
{
    BEEP=!BEEP;
}

#define DT 10
#define HTRE 30
#define BPMRE 80
/* [0]: beat per section, [1]: section num, [2]: bpm */
/* hash<char *, unsigned> */
unsigned HashSymb(char *name)
{
    unsigned char a, b;

    if(name[0] == '0')
        return 0;

    a = name[0] - 'A';
    if(name[1] == '#'){
        a += 7;
        b = name[2] - '1';
    }
    else
        b = name[1] - '1';
    return NewSymTable[a][b] - HTRE;
}
void NewMusicPlay(struct Track *pmusic)
{
    unsigned mspb;
    unsigned beats_total;
    unsigned beats_cnt;
    struct Beat beat;
    unsigned i;

    BeepInit(_beep_);

    mspb = 60000 / (pmusic->head.bpm + BPMRE);
    beats_total = pmusic->head.sect_num * pmusic->head.bps;
    
    i = 0;
    beats_cnt = 0;
    while(beats_cnt < beats_total){
        //start beeping.
        beat = pmusic->beats[i];
        Beep(HashSymb(beat.name));

        //keep beeping for beat*mspb.
        delay(beat.durabeat * mspb - DT);

        //seperate beats.
        BeepStop();

        i++;
        beats_cnt += beat.durabeat;
        delay(DT);
    }

    BeepReset();
}

void main(void)
{
    NewMusicPlay(&tr1);
    while(1)
        continue;
    
}