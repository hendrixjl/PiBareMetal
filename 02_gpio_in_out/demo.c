#include "utils.h"
#include "mmregisters.h"

void startc ( void )
{
    gpio_fsel(gpio47, GPIO_FN_OUTPUT);
    gpio_fsel(gpio23, GPIO_FN_OUTPUT);

    while(1)
    {
        gpio_set(gpio47);
        gpio_clear(gpio23);
        for (volatile int busy=0; busy<0x200000; busy++);
        gpio_clear(gpio47);
        gpio_set(gpio23);
        for (volatile int busy=0; busy<0x200000; busy++);
    }
}
