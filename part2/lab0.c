/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2016, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

#include <rpi3.h>

int main()
{
    /* Enable GPIO16 as an output */
    GPIO->GPFSEL1 |= (1 << 18);
    
    /* Turn LED on */
    GPIO->GPSET0 |= (1 << 16);

    while(1) 
    {
        /* Iteratively turn on and off the LED */
    }

	return 0;
}