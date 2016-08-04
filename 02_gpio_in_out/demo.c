#include "utils.h"
#include "gpio.h"

void startc ( void )
{
    gpio_fsel(gpio47, GPIO_FN_OUTPUT);
    gpio_fsel(gpio23, GPIO_FN_OUTPUT);
    gpio_fsel(gpio24, GPIO_FN_INPUT);

    while(1)
    {
        gpio_set(gpio47);

        enum { HIGH = 1 };
        if (gpio_level(gpio24) == HIGH)
        {
            gpio_set(gpio23);
        }
        else
        {
            gpio_clear(gpio23);
        }

        for (volatile int busy=0; busy<0x400000; busy++);

        gpio_clear(gpio47);

        for (volatile int busy=0; busy<0x400000; busy++);
    }
}
