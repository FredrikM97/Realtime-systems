//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"
#include <cstring>
#include <assert.h>



void Test_setAll();
void Test_resetAll();
void Test_reg2str();

void Test_reg2str5(){
	iRegister r;

	r = {0};	
	assert(memcmp("00000000000000000000000000000000", reg2str(r),32) == 0);
	
	printf("reg2str works\n" );
}


int main (){
	iRegister r;
	iRegister e;
	//char out[33];

	/* Put all your test cases for the implemented functions here */
	

	printf("Start tests \n");
	r = {1};
	//e = {-1};
	
	Test_setAll();
	Test_resetAll();
	Test_reg2str();
	
	r = {60};
	printf("%s \n",reg2str(r));
	shiftLeft(2,&r);
	printf("%s \n",reg2str(r));
	
	r = {60};
	printf("%s \n",reg2str(r));
	shiftRight(2,&r);
	printf("%s \n",reg2str(r));
	
	return 0;
}

void Test_setAll(){
	iRegister r;
	iRegister e;
	e = {-1}; // set all bits in control
	
	r = {7};
	assert(e.content != r.content); //test that r is != to e (thet r have not started as the sam as e)
	
	setAll(&r);
	assert(e.content == r.content);//test that r gets all bits set given by random num
	
	r = {0};
	setAll(&r);
	assert(e.content == r.content);//test if all bits get set if r is only zeros
	
	r = {-1};
	setAll(&r);
	assert(e.content == r.content);//tests if all bits reman on if r starts white all bits
	
	printf("setAll works\n" );
}

void Test_resetAll(){
	iRegister r;
	iRegister e;
	e = {0};//set all bits in control
	
	r = {7};
	assert(e.content != r.content);//test that r is != to e (thet r have not started as the sam as e)
	
	resetAll(&r);	
	assert(e.content == r.content);//test that r gets all bits set given by random num
	
	r = {0};
	resetAll(&r);
	assert(e.content == r.content);//test if all bits get set if r is only zeros
	
	r = {-1};
	resetAll(&r);
	assert(e.content == r.content);//tests if all bits reman on if r starts white all bits set
	
	printf("resetAll works\n" );
}

void Test_reg2str(){
	iRegister r;

	r = {0};	
	assert(memcmp("00000000000000000000000000000000", reg2str(r),32) == 0);
	
	r = {-1};
	assert(memcmp("11111111111111111111111111111111", reg2str(r),32) == 0);
	
	r = {1431655765};
	assert(memcmp("01010101010101010101010101010101", reg2str(r),32) == 0);
	
	r = {123456789};
	assert(memcmp("00000111010110111100110100010101 ", reg2str(r),32) == 0);
	
	
	//0000 0000 0000 0000 0000 0000 0000 0000
	//0000 0000 0000 0000 0000 0000 0000 0000
	
	//11111111111111111111111111111111
	
	printf("reg2str works\n" );
}


