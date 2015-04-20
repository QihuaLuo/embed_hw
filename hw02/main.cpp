
#include "mbed.h"
#include "gpio.h"

unsigned char buffer[1024];

void toggle(void)
{
    GPIO0_FIO0DIR0 = (unsigned char)(1 << 6); 

    while (1) {
        GPIO0_FIO0SET0 |= (unsigned char)(1 << 6);  
        wait_ms(50);
        GPIO0_FIO0CLR0 |= (unsigned char)(1 << 6);  
        wait_ms(50);
    }
}

void reading(unsigned char *buf)
{
    register unsigned char r0, r1, r2, r3, r4, r5, r6, r7;

    GPIO0_FIO0DIR2 = 0x00;

    r0 = GPIO0_FIO0PIN2;
    r1 = GPIO0_FIO0PIN2;
    r2 = GPIO0_FIO0PIN2;
    r3 = GPIO0_FIO0PIN2;
    r4 = GPIO0_FIO0PIN2;
    r5 = GPIO0_FIO0PIN2;
    r6 = GPIO0_FIO0PIN2;
    r7 = GPIO0_FIO0PIN2;

    buf[0] = r0;
    buf[1] = r1;
    buf[2] = r2;
    buf[3] = r3;
    buf[4] = r4;
    buf[5] = r5;
    buf[6] = r6;
    buf[7] = r7;
}


int main(void)
{

    toggle();
    unsigned char *p = buffer;

    while (p < &buffer[1023]) {
        reading(p);
        p += 8;
    }

    return 0;
}
