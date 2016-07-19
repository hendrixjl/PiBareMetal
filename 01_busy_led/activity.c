#include "utils.h"
#include "mmregisters.h"

void startc ( void )
{
    *GPFSEL1 = set_bit_pattern(*GPFSEL1, 1, 18, 3);

    while(1)
    {
        *GPSET0 = set_bit_pattern(*GPSET0, 1, 16, 1);
        for (volatile int busy=0; busy<0x200000; busy++);
        *GPCLR0 = set_bit_pattern(*GPCLR0, 1, 16, 1);
        for (volatile int busy=0; busy<0x200000; busy++);
    }
}
