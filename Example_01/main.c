#include <stdint.h>

#include "memio.h"
#include "lib.h"

#define ENABLE_RED_LED()    ARM_GPIO_GPFSEL1 |= 1 << 18; /*GPIO16(GPIO Function Select 1)*/
#define ENABLE_YELLOW_LED() ARM_GPIO_GPFSEL2 |= 1 << 00;  /*GPIO20(GPIO Function Select 2)*/
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

void main(void) /*belongs to Core 0*/
{
    start_core3(core3_main);
    start_core2(core2_main);
    
    start_core1(core1_main);
 

    
    core0_submain();
}

void core0_submain(void)
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


void core1_main(void)
{
            
 ENABLE_YELLOW_LED();

    
    volatile uint32_t i;
    
    while(1)
    {

        YELLOW_LED_ON();


        for(i=0; i < 300000; i++); //wait for some time

      YELLOW_LED_OFF();


        for(i=0; i < 300000; i++); //wait for some time

    }

}

void core2_main(void)
{
    
            ENABLE_RED_LED();

    
    volatile uint32_t i;
    
    while(1)
    {
        RED_LED_ON();


        for(i=0; i < 200000; i++); //wait for some time

        RED_LED_OFF();


        for(i=0; i < 200000; i++); //wait for some time

    }
    

   

}

void core3_main(void)
{


    ENABLE_GREEN_LED();
    
    volatile uint32_t i;
    
    while(1)
    {

        GREEN_LED_ON();

        for(i=0; i < 500000; i++); //wait for some time


        GREEN_LED_OFF();

        for(i=0; i < 500000; i++); //wait for some time

    }

}




