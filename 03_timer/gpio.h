#include "utils.h"
/* GPIO */

/* group 0-5 */
/* represents the 10s digit. So, for pin 23, the group is 2 */
volatile unsigned int* const GPFSEL0 = (unsigned int*)0x20200000;
volatile unsigned int* const GPFSEL1 = (unsigned int*)0x20200004;
volatile unsigned int* const GPFSEL2 = (unsigned int*)0x20200008;
volatile unsigned int* const GPFSEL3 = (unsigned int*)0x2020000C;
volatile unsigned int* const GPFSEL4 = (unsigned int*)0x20200010;
volatile unsigned int* const GPFSEL5 = (unsigned int*)0x20200014;
volatile unsigned int* const GPSET0 =  (unsigned int*)0x2020001C;
volatile unsigned int* const GPSET1 =  (unsigned int*)0x20200020;
volatile unsigned int* const GPCLR0 =  (unsigned int*)0x20200028;
volatile unsigned int* const GPCLR1 =  (unsigned int*)0x2020002C;
const volatile unsigned int* GPLEV0 =  (unsigned int*)0x20200034;
const volatile unsigned int* GPLEV1 =  (unsigned int*)0x20200038;
volatile unsigned int* GPEDS0 =        (unsigned int*)0x20200040;
volatile unsigned int* GPEDS1 =        (unsigned int*)0x20200044;
volatile unsigned int* GPREN0 =        (unsigned int*)0x2020004C;
volatile unsigned int* GPREN1 =        (unsigned int*)0x20200050;
volatile unsigned int* GPFEN0 =        (unsigned int*)0x20200058;
volatile unsigned int* GPFEN1 =        (unsigned int*)0x2020005C;
volatile unsigned int* GPHEN0 =        (unsigned int*)0x20200064;
volatile unsigned int* GPHEN1 =        (unsigned int*)0x20200068;
volatile unsigned int* GPLEN0 =        (unsigned int*)0x20200070;
volatile unsigned int* GPLEN1 =        (unsigned int*)0x20200074;
volatile unsigned int* GPAREN0 =       (unsigned int*)0x2020007C;
volatile unsigned int* GPAREN1 =       (unsigned int*)0x20200080;
volatile unsigned int* GPAFEN0 =       (unsigned int*)0x20200088;
volatile unsigned int* GPAFEN1 =       (unsigned int*)0x2020008C;
volatile unsigned int* GPPUD =         (unsigned int*)0x20200094;
volatile unsigned int* GPPUDCLK0 =     (unsigned int*)0x20200098;
volatile unsigned int* GPPUDCLK1 =     (unsigned int*)0x2020009C;



enum gpio_function {
    GPIO_FN_INPUT = 0,
    GPIO_FN_OUTPUT = 1,
    GPIO_FN_ALT0 = 4,
    GPIO_FN_ALT1 = 5,
    GPIO_FN_ALT2 = 6,
    GPIO_FN_ALT3 = 7,
    GPIO_FN_ALT4 = 3,
    GPIO_FN_ALT5 = 2
};

enum gpio {
    gpio00, gpio01, gpio02, gpio03, gpio04, gpio05, gpio06, gpio07,
    gpio08, gpio09, gpio10, gpio11, gpio12, gpio13, gpio14, gpio15,
    gpio16, gpio17, gpio18, gpio19, gpio20, gpio21, gpio22, gpio23,
    gpio24, gpio25, gpio26, gpio27, gpio28, gpio29, gpio30, gpio31,
    gpio32, gpio33, gpio34, gpio35, gpio36, gpio37, gpio38, gpio39,
    gpio40, gpio41, gpio42, gpio43, gpio44, gpio45, gpio46, gpio47,
    gpio48, gpio49, gpio50, gpio51, gpio52, gpio53
};

enum gpio_bitmasks {
    gpio00_bit = 0x00000001, 
    gpio01_bit = 0x00000002, 
    gpio02_bit = 0x00000004, 
    gpio03_bit = 0x00000008, 
    gpio04_bit = 0x00000010, 
    gpio05_bit = 0x00000020, 
    gpio06_bit = 0x00000040, 
    gpio07_bit = 0x00000080,
    gpio08_bit = 0x00000100, 
    gpio09_bit = 0x00000200, 
    gpio10_bit = 0x00000400, 
    gpio11_bit = 0x00000800, 
    gpio12_bit = 0x00001000, 
    gpio13_bit = 0x00002000, 
    gpio14_bit = 0x00004000, 
    gpio15_bit = 0x00008000,
    gpio16_bit = 0x00010000, 
    gpio17_bit = 0x00020000, 
    gpio18_bit = 0x00040000, 
    gpio19_bit = 0x00080000, 
    gpio20_bit = 0x00100000, 
    gpio21_bit = 0x00200000, 
    gpio22_bit = 0x00400000, 
    gpio23_bit = 0x00800000,
    gpio24_bit = 0x01000000, 
    gpio25_bit = 0x02000000, 
    gpio26_bit = 0x03000000, 
    gpio27_bit = 0x08000000, 
    gpio28_bit = 0x10000000, 
    gpio29_bit = 0x20000000, 
    gpio30_bit = 0x40000000, 
    gpio31_bit = 0x80000000,
    gpio32_bit = 0x00000001, 
    gpio33_bit = 0x00000002, 
    gpio34_bit = 0x00000004, 
    gpio35_bit = 0x00000008, 
    gpio36_bit = 0x00000010, 
    gpio37_bit = 0x00000020, 
    gpio38_bit = 0x00000040, 
    gpio39_bit = 0x00000080,
    gpio40_bit = 0x00000100, 
    gpio41_bit = 0x00000200, 
    gpio42_bit = 0x00000400, 
    gpio43_bit = 0x00000800, 
    gpio44_bit = 0x00001000, 
    gpio45_bit = 0x00002000, 
    gpio46_bit = 0x00004000, 
    gpio47_bit = 0x00008000,
    gpio48_bit = 0x00010000, 
    gpio49_bit = 0x00020000, 
    gpio50_bit = 0x00040000, 
    gpio51_bit = 0x00080000, 
    gpio52_bit = 0x00100000, 
    gpio53_bit = 0x00200000
};

enum GPIO_PUD_state {
    PUD_off = 0,
    PUD_enable_pull_down = 1,
    PUD_enable_pull_up = 2
};

inline void gpio_fsel(enum gpio pin, enum gpio_function fun)
{
    enum { THREE_BITS = 3 };
    if ((pin>=gpio00) && (pin<=gpio09))
    {
        *GPFSEL0 = set_bit_pattern(*GPFSEL0, fun, pin*3, THREE_BITS);
    }
    else if ((pin>=gpio10) && (pin<=gpio19))
    {
        *GPFSEL1 = set_bit_pattern(*GPFSEL1, fun, (pin-gpio10)*3, THREE_BITS);
    }
    else if ((pin>=gpio20) && (pin<=gpio29))
    {
        *GPFSEL2 = set_bit_pattern(*GPFSEL2, fun, (pin-gpio20)*3, THREE_BITS);
    }
    else if ((pin>=gpio30) && (pin<=gpio39))
    {
        *GPFSEL3 = set_bit_pattern(*GPFSEL3, fun, (pin-gpio30)*3, THREE_BITS);
    }
    else if ((pin>=gpio40) && (pin<=gpio49))
    {
        *GPFSEL4 = set_bit_pattern(*GPFSEL4, fun, (pin-gpio40)*3, THREE_BITS);
    }
    else if ((pin>=gpio50) && (pin<=gpio53))
    {
        *GPFSEL5 = set_bit_pattern(*GPFSEL5, fun, (pin-gpio50)*3, THREE_BITS);
    }
}

inline void gpio_set(enum gpio pin)
{
    enum { SET=1, ONE_BIT=1 };
    if ((pin>=gpio00) && (pin<=gpio31))
    {
        *GPSET0 = set_bit_pattern(*GPSET0, SET, pin, ONE_BIT);
    }
    else if ((pin>=gpio31) && (pin<=gpio53))
    {
        *GPSET1 = set_bit_pattern(*GPSET1, SET, pin-32, ONE_BIT);
    }
}

inline void gpio_clear(enum gpio pin)
{
    enum { CLEAR=1, ONE_BIT=1 };
    if ((pin>=gpio00) && (pin<=gpio31))
    {
        *GPCLR0 = set_bit_pattern(*GPCLR0, CLEAR, pin, ONE_BIT);
    }
    else if ((pin>=gpio31) && (pin<=gpio53))
    {
        *GPCLR1 = set_bit_pattern(*GPCLR1, CLEAR, pin-32, ONE_BIT);
    }
}

inline unsigned int gpio_level(enum gpio pin)
{
    enum { ONE_BIT=1 };
    return ((pin >= gpio00) && (pin <= gpio31)) ?
            get_bit_pattern(*GPLEV0, pin, ONE_BIT) :
            get_bit_pattern(*GPLEV1, pin-32, ONE_BIT);
}

inline void set_pud(enum gpio pin, enum GPIO_PUD_state pud)
{
    *GPPUD = pud;
    for (volatile int i=0; i<150; ++i);
    if ((pin >= gpio00) && (pin <= gpio31))
    {
        set_bit_pattern(*GPPUDCLK0, 1, pin, 1);
    }
    else
    {
        set_bit_pattern(*GPPUDCLK1, 1, pin-32, 1);
    }
    for (volatile int i=0; i<150; ++i);
}

