/* GPIO */

/* group 0-5 */
/* represents the 10s digit. So, for pin 23, the group is 2 */
volatile unsigned int* const GPFSEL0 = (unsigned int*)0x20200000;
volatile unsigned int* const GPFSEL1 = (unsigned int*)0x20200004;
volatile unsigned int* const GPFSEL2 = (unsigned int*)0x20200008;
volatile unsigned int* const GPFSEL3 = (unsigned int*)0x2020000C;
volatile unsigned int* const GPFSEL4 = (unsigned int*)0x20200010;
volatile unsigned int* const GPFSEL5 = (unsigned int*)0x20200014;

volatile unsigned int* const GPSET0 = (unsigned int*)0x2020001C;
volatile unsigned int* const GPSET1 = (unsigned int*)0x20200020;
volatile unsigned int* const GPCLR0 = (unsigned int*)0x20200028;
volatile unsigned int* const GPCLR1 = (unsigned int*)0x2020002C;

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
