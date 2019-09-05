//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"
#include <string.h>
#include <math.h>

void assert(iRegister *e, iRegister *r){
	if(e->content != r->content){
		printf("\nThe content is not the same! Expected: %d Observed: %d",e->content, r->content);
	}
}
void assert_INT(int e,int r){
	printf("\n%d", e);
	if(e != r){
		printf("\n Test is not the same! Expected: %d Observed: %d", e, r);
	}
}

void unit_test(iRegister r){
	iRegister e;
	printf("\nStart tests \n");
	int i;
	
	/*Test resetBit*/
	r = {15};
	int val = 15;
	for(i = 0; i <4; i++){
		val = val - pow(2,i);
		resetBit(i, &r);
		assert_INT(val, r.content);
	}
	
	/*Test setBit*/
	for(i = 0; i <4; i++){
		r = {0};
		setBit(i, &r);
		assert_INT(pow(2,i), r.content);
	}
	/*Test setAll*/
	for(i = 0; i <4; i++){
		r = {(int)pow(2,i)};
		setAll(&r);
		assert_INT(~0, r.content);
	}

	/*Test getBit*/
	r = {35};
	int temp[6] = {1,0,0,0,1,1};
	for(i = 0; i <5; i++){
		assert_INT(temp[5-i], getBit(i,&r));
	}
	/*Test assignNibble*/
	
	
	/*Test getNibble*/
	/*Test reg2str*/
	/*Test shiftRight*/
	/*Test shiftLeft*/
	
}
int main (){
	iRegister r;

	/* Put all your test cases for the implemented functions here */	
	
	printf("\nAddress_R: %p\n", &r);
	printf("Memory: %s", reg2str(r));
	printf("\nValue in Memory: %d", r.content);
	
	unit_test(r);
	return 0;
}
