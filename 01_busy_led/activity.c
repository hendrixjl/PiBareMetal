#include "utils.h"
#include "mmregisters.h"

void startc ( void )
{
    *GPFSEL1 = set_bit_pattern(*GPFSEL4, 1, 21, 3);

    while(1)
    {
        *GPSET1 = set_bit_pattern(*GPSET1, 1, 47-32, 1);
        for (volatile int busy=0; busy<0x200000; busy++);
        *GPCLR1 = set_bit_pattern(*GPCLR1, 1, 47-32, 1);
        for (volatile int busy=0; busy<0x200000; busy++);
    }
}
