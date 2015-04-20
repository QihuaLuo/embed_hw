#include "mbed.h"

int main() {
    
uint32_t volatile *FIO4DIR0 =   (uint32_t *) 0x2009C000;
uint32_t volatile *FIO4SET0 =   (uint32_t *) 0x2009C018;
uint32_t volatile *FIO4CLR0 =   (uint32_t *) 0x2009C01C;
uint32_t volatile *FIO4MASK0 =  (uint32_t *) 0x2009C010;

*FIO4DIR0 =     0xFF;
*FIO4MASK0 =    0xBF; 
*FIO4CLR0 =     0xFF;


    while(1) {
      *FIO4SET0 = 0x40;
      *FIO4CLR0 = 0x40;
      wait(0.2);
    }
}