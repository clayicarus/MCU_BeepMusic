#ifndef _MUSIC_H_
#define _MUSIC_H_

unsigned char code track0[]=
{
    /* beat per section, section_sum, BPM */
    4,12,120,
    /* pitch(0,1(C),2), sym_num(symtable), time(beat) */
    /* section 1 */
    1,1,1,
    1,1,1,
    1,5,1,
    1,5,1,
    /* section 2 */
    1,6,1,
    1,6,1,
    1,5,2,
    /* section 3 */
    1,4,1,
    1,4,1,
    1,3,1,
    1,3,1,
    /* section 4 */
    1,2,1,
    1,2,1,
    1,1,1,
    0,0,1,
    /* section 5 */
    1,5,1,
    1,5,1,
    1,4,1,
    1,4,1,
    /* section 6 */
    1,3,1,
    1,3,1,
    1,2,2,
    /* section 7 */
    1,5,1,
    1,5,1,
    1,4,1,
    1,4,1,
    /* section 8 */
    1,3,1,
    1,3,1,
    1,2,1,
    1,0,1,
    /* section 9 */
    1,1,1,
    1,1,1,
    1,5,1,
    1,5,1,
    /* section 10 */
    1,6,1,
    1,6,1,
    1,5,2,
    /* section 11 */
    1,4,1,
    1,4,1,
    1,3,1,
    1,3,1,
    /* section 12 */
    1,2,1,
    1,2,1,
    1,1,2,
};

unsigned char code track1[]=
{
    6,7,240,
    /* section 1 */
    0,0,2,
    0,0,2,
    1,5,1,
    1,5,1,
    /* section 2 */
    1,6,2,
    1,5,2,
    2,1,2,
    /* section 3 */
    1,7,4,
    1,5,1,
    1,5,1,
    /* section 4 */
    1,6,2,
    1,5,2,
    2,2,2,
    /* section 5 */
    2,1,4,
    1,5,1,
    1,5,1,
    /* section 6 */
    2,5,2,
    2,3,2,
    2,1,2,
    /* section 7 */
    1,7,2,
    0,0,4,
};

unsigned char code * track[]=
{
    "TwinkleStar",track0,
    "HappyBirthday",track1,
};


#endif