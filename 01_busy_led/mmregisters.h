/* GPIO */
const unsigned int GPIO_FN_INPUT = 0;
const unsigned int GPIO_FN_OUTPUT = 1;
const unsigned int GPIO_FN_ALT0 = 4;
const unsigned int GPIO_FN_ALT1 = 5;
const unsigned int GPIO_FN_ALT2 = 6;
const unsigned int GPIO_FN_ALT3 = 7;
const unsigned int GPIO_FN_ALT4 = 3;
const unsigned int GPIO_FN_ALT5 = 2;

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
