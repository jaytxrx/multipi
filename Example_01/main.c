#include <stdint.h>

#define RPI RPI2

#include "memio.h"
#include "lib.h"

#if(RPI == RPI1)
    #error "Example works only for Raspberry Pi 2"
#endif

#define ENABLE_RED_LED()    ARM_GPIO_GPFSEL1 |= 1 << 18; /*GPIO16(GPIO Function Select 1)*/
#define ENABLE_YELLOW_LED() ARM_GPIO_GPFSEL2 |= 1 << 00; /*GPIO20(GPIO Function Select 2)*/
#define ENABLE_GREEN_LED()  ARM_GPIO_GPFSEL2 |= 1 << 03; /*GPIO21(GPIO Function Select 2)*/

#define RED_LED_ON()    ARM_GPIO_GPSET0 |= 1 << 16;
#define YELLOW_LED_ON() ARM_GPIO_GPSET0 |= 1 << 20;
#define GREEN_LED_ON()  ARM_GPIO_GPSET0 |= 1 << 21;

#define RED_LED_OFF()    ARM_GPIO_GPCLR0 |= 1 << 16;
#define YELLOW_LED_OFF() ARM_GPIO_GPCLR0 |= 1 << 20;
#define GREEN_LED_OFF()  ARM_GPIO_GPCLR0 |= 1 << 21;

void main(void) __attribute__((naked));
void core3_main(void) __attribute__((naked));
void core1_main(void) __attribute__((naked));
void core2_main(void) __attribute__((naked));

void core0_submain(void);

volatile uint32_t i;
volatile uint32_t j;
volatile uint32_t k;
volatile uint32_t l;

void main(void)
{
    //enable_JTAG();
    
    ENABLE_ACT_LED();
    
    ENABLE_YELLOW_LED();
    ENABLE_GREEN_LED();
    ENABLE_RED_LED();

    start_core1(core1_main);
    start_core2(core2_main);
    start_core3(core3_main);

    core0_submain();
}


void core0_submain(void)
{
    while(1)
    {
        for(i=0; i < 500000; i++); //wait for some time
        ACT_LED_ON();
        for(i=0; i < 500000; i++); //wait for some time
        ACT_LED_OFF();
    }
}


void core1_main(void)
{
    //asm volatile ("mov sp,%0" : :"r" (ram1));
    
    while(1)
    {
        for(j=0; j < 300000; j++); //wait for some time
        RED_LED_ON();
        for(j=0; j < 300000; j++); //wait for some time
        RED_LED_OFF();
    }
}

void core2_main(void)
{
    //asm volatile ("mov sp,%0" : :"r" (ram2));
    
    while(1)
    {
        for(k=0; k < 200000; k++); //wait for some time
        YELLOW_LED_ON();
        for(k=0; k < 200000; k++); //wait for some time
        YELLOW_LED_OFF();
    }
}

void core3_main(void)
{
   // asm volatile ("mov sp,%0" : :"r" (ram3));
    
    while(1)
    {
        
        for(l=0; l < 500000; l++); //wait for some time
        GREEN_LED_ON();
        for(l=0; l < 500000; l++); //wait for some time
        GREEN_LED_OFF();
    }
}




