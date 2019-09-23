/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <rpi3.h>
#include "TaylorSeries.h"
#include "piface.h"
int main()
{
    /* Enable GPIO16 as an output */
    GPIO->GPFSEL1 |= (1 << 18);

    /* Turn LED on */
    GPIO->GPSET0 |= (1 << 16);

    /* Write to PiFace's LCD screen */
    piface_puts("Hello World!\n");
    //ExpStruct *temp;
    int i=0;
    char data[32];
    while (1)
    {
      ExpStruct *temp=iexp(i);
      sprintf(data, "Data: %d.%d",temp->expInt,temp->expFraction);
      piface_puts(data);
      piface_delay();
      piface_clear();
      i++;
      free(temp);
    }
	return 0;
}
