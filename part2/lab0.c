/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2016, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

#include <rpi3.h> 
#include <math.h>

void man_sleep(int x){
	int i;
	for(i = 0;i < (x*10000); i++){
		asm("nop");
	} 
}

float power(float x, int y) { 
    float temp; 
    if( y == 0) 
       return 1; 
    temp = power(x, y/2);        
    if (y%2 == 0) 
        return temp*temp; 
    else{ 
        if(y > 0) 
            return x*temp*temp; 
        else
            return (temp*temp)/x; 
    } 
}  

int main()
{
    /* Enable GPIO16 as an output */
    GPIO->GPFSEL1 |= (1 << 18); 
    
    /* Turn LED on */
    GPIO->GPSET0 |= (1 << 16); 
	int i = 1;
    while(1) 
    {
        /* Iteratively turn on and off the LED */
		GPIO->GPCLR0 |= (1 << 16);
		man_sleep(i);
		GPIO->GPSET0 |= (1 << 16); 
		man_sleep(i);
		
		if(i != -1) {
			i = i<<1;
		}
    }

	return 0;
}