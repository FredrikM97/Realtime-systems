//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"
#include <cstring>


int main (){
	iRegister r;
	//char out[33];

	/* Put all your test cases for the implemented functions here */

	printf("Start tests \n");
	r = {7};
	
	setBit(10, &r);
	/* Tests */
	//setAll(&r);
	printf("%d",getBit(0, &r));
		
		
	printf("\nAddress: %p\n", &r);
	printf("Memory: %s", reg2str(r));
	printf("\nValue in Memory: %d", r.content);
	
	//Remove reccurrent information, do a function somehow
	/*Test resetBit*/
	if(memcmp("00000000000000000000010000000111", reg2str(r),32) == 0) { printf("\nTest: Success");}else{printf("\nTest: Fail");}
	if(memcmp("00000000000000000000010000000111", reg2str(r),32) == 0) { printf("\nTest: Success");}else{printf("\nTest: Fail");}
	if(memcmp("00000000000000000000010000000111", reg2str(r),32) == 0) { printf("\nTest: Success");}else{printf("\nTest: Fail");}
	if(memcmp("00000000000000000000010000000111", reg2str(r),32) == 0) { printf("\nTest: Success");}else{printf("\nTest: Fail");}
	/*Test setBit*/
	if(memcmp("00000000000000000000010000000111", reg2str(r),32) == 0) { printf("\nTest: Success");}else{printf("\nTest: Fail");}
	if(memcmp("00000000000000000000010000000111", reg2str(r),32) == 0) { printf("\nTest: Success");}else{printf("\nTest: Fail");}
	if(memcmp("00000000000000000000010000000111", reg2str(r),32) == 0) { printf("\nTest: Success");}else{printf("\nTest: Fail");}
	if(memcmp("00000000000000000000010000000111", reg2str(r),32) == 0) { printf("\nTest: Success");}else{printf("\nTest: Fail");}
	/*Test setAll*/
	/*Test getBit*/
	/*Test assignNibble*/
	/*Test getNibble*/
	/*Test reg2str*/
	/*Test shiftRight*/
	/*Test shiftLeft*/
	return 0;
}
