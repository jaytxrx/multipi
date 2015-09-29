#include <stdint.h>

#include "memio.h"
#include "lib.h"

void main(void) __attribute__((naked));
void main(void)
{
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