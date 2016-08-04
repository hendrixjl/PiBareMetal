#include "timer.h"
#include "gpio.h"

enum { HIGH = 1 };

void delay()
{
    static const unsigned int BIT_MASK = 0x00400000;
    unsigned int timer_bit = *SYSTIMERCLO & BIT_MASK;
    while ((*SYSTIMERCLO & BIT_MASK) == timer_bit);
}

void flip_led(enum gpio pin)
{
    if (gpio_level(pin) == HIGH)
    {
        gpio_clear(pin);
    }
    else
    {
        gpio_set(pin);
    }
}

void startc ( void )
{
    gpio_fsel(gpio47, GPIO_FN_OUTPUT);
    gpio_fsel(gpio23, GPIO_FN_OUTPUT);
    gpio_fsel(gpio24, GPIO_FN_INPUT);

    while(1)
    {
        flip_led(gpio47);

        if (gpio_level(gpio24) == HIGH)
        {
            gpio_set(gpio23);
        }
        else
        {
            gpio_clear(gpio23);
        }

        delay();
    }
}
