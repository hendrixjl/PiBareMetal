/* timer.h */

volatile unsigned int* SYSTIMERCS = (unsigned int*)0x20003000;
const volatile unsigned int* SYSTIMERCLO = (unsigned int*)0x20003004;
const volatile unsigned int* SYSTIMERCHI = (unsigned int*)0x20003008;
volatile unsigned int* SYSTIMERC0 = (unsigned int*)0x2000300C;
volatile unsigned int* SYSTIMERC1 = (unsigned int*)0x2000300C;
volatile unsigned int* SYSTIMERC2 = (unsigned int*)0x2000300C;
volatile unsigned int* SYSTIMERC3 = (unsigned int*)0x2000300C;

enum systimer_compare_register {
    systimer_compare_c0=0,
    systimer_compare_c1=1,
    systimer_compare_c2=2,
    systimer_compare_c3=3
};

inline void systimer_set_compare(enum systimer_compare_register r, unsigned int time)
{
    SYSTIMERC0[r] = time;
}

inline unsigned int systimer_compare_fired(enum systimer_compare_register r)
{
    if (r == systimer_compare_c0)
    {
        if ((*SYSTIMERCS & 0x01) != 0)
        {
            *SYSTIMERCS = 0x0E; // reset bit 0
            return 1;
        }
        return 0;
    }
    else if (r == systimer_compare_c1)
    {
        if ((*SYSTIMERCS & 0x02) != 0)
        {
            *SYSTIMERCS = 0x0D; // reset bit 1
            return 1;
        }
    }
    else if (r == systimer_compare_c2)
    {
        if ((*SYSTIMERCS & 0x04) != 0)
        {
            *SYSTIMERCS = 0x0B; // reset bit 2
            return 1;
        }
    }
    else if (r == systimer_compare_c2)
    {
        if ((*SYSTIMERCS & 0x08) != 0)
        {
            *SYSTIMERCS = 0x07; // reset bit 3
            return 1;
        }
    }
    return 0;
}
