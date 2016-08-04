1. Create a new file, activity.c, containg the following:

#include "utils.h"
volatile unsigned int* GPFSEL1 = (unsigned int*)0x20200004;
volatile unsigned int* GPSET0 = (unsigned int*)0x2020001C;
volatile unsigned int* GPCLR0 = (unsigned int*)0x20200028;

//-------------------------------------------------------------------------
int startc ( void )
{
    *GPFSEL1 = set_bit_pattern(*GPFSEL1, 1, 18, 3);
    temp &= ~(7<<18);
    temp |= 1<<18;
    *GPFSEL1 = temp;

    while(1)
    {
        *GPSET0 = 1<<16;
        for (volatile int busy=0; busy<0x1000000; busy++);
        *GPCLR0 = 1<<16;
        for (volatile int busy=0; busy<0x1000000; busy++);
    }
    return(0);

unsigned int get_bit_pattern(unsigned int data, unsigned startbit, unsigned bit_count)
{
    data >>= startbit;
    unsigned int mask = (1 << bit_count) - 1;
    return data & mask;
}

