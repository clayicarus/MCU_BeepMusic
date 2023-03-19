#include <REG51.H>
#include"beep.h"
#include"sym_table.h"
#include"delay.h"
#include"music.h"

#include"new_symtable.h"
#include"new_music.h"

//use timer0
sbit BEEP=P1^5;
void MusicPlay(unsigned char music_tab[]);
void _beep_(void);

void _beep_(void)
{
    BEEP=!BEEP;
}

#define DT 20
#define REVISION 10
/* [0]: beat per section, [1]: section num, [2]: bpm */
void MusicPlay(unsigned char music[])
{
    unsigned mspb;
    unsigned beats;
    unsigned i;
    unsigned char beat;

    BeepInit(_beep_);

    mspb=60000/music[2];
    beats=music[0]*music[1];
    
    for(i=3;beats>0;i++)
    {
        //start beeping.
        Beep(SymTable[music[i]][music[++i]]);
        //beatnum.
        beat=music[++i];

        //keep beeping for beat*mspb.
        delay(beat*mspb-REVISION);

        //seperate beats.
        BeepStop();

        beats-=beat;
        delay(DT);
    }

    BeepReset();
}

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
    return NewSymTable[a][b];
}
void NewMusicPlay(struct Track *pmusic)
{
    unsigned mspb;
    unsigned beats;
    struct Beat beat;
    unsigned i;

    BeepInit(_beep_);

    mspb = 60000 / pmusic->head.bpm;
    beats = pmusic->head.sect_num * pmusic->head.bps;
    
    i = 0;
    while(i < beats){
        //start beeping.
        beat = pmusic->beats[i];
        Beep(HashSymb(beat.name));

        //keep beeping for beat*mspb.
        delay(beat.durabeat * mspb - HTRE);

        //seperate beats.
        BeepStop();

        i += beat.durabeat;
        delay(DT);
    }

    BeepReset();
}

void main(void)
{
    MusicPlay(track[1]);
    
    while(1)
        continue;
    
}