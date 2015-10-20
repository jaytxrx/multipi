#include <stdint.h>

#define RPI RPI2

#include "memio.h"
#include "lib.h"

#if(RPI == RPI1)
	#error "Example works only for Raspberry Pi 2"
#endif

void main(void) __attribute__((naked));
void main(void)
{
  //enable_JTAG();
    
  ENABLE_ACT_LED();

  volatile uint32_t i;

  while(1)
  {
    ACT_LED_ON();

    for(i=0; i < 100000; i++); //wait for some time

    ACT_LED_OFF();

    for(i=0; i < 100000; i++); //wait for some time
  }
}
