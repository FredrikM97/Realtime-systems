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

void display_Controller(int);
void led_Controller();
void led_Delay(int);
int main()
{
    /* Enable GPIO16 as an output */
    GPIO->GPFSEL1 |= (1 << 18);

    /* Turn LED on */
    GPIO->GPSET0 |= (1 << 16);

    /* Write to PiFace's LCD screen */
    piface_puts("Hello World!\n");

    int i=0;
    while (1){
      display_Controller(i);
      led_Controller();
      i++;
    }
	return 0;
}

void display_Controller(int i){
  char data[32];
  ExpStruct *temp=iexp(i);
  sprintf(data, "Data: %d.%d",temp->expInt,temp->expFraction);
  piface_puts(data);
  piface_delay();
  piface_clear();
  free(temp);
}
void led_Controller(void){
  /* Iteratively turn on and off the LED */
  GPIO->GPCLR0 |= (1 << 16);
  led_Delay(100);
  GPIO->GPSET0 |= (1 << 16);
  led_Delay(100);
  /*Change delay speed*/
  //if(i != -1) {
  //  i = i<<1;
  //}
}

void led_Delay(int x){
	int i;
	for(i = 0;i < (x*10000); i++){
		asm("nop");
	}
}
