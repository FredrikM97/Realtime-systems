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
void Test_setBit();
void Test_resetAll();
void Test_reg2str();
void Test_resetBit();
void Test_getNibble();
void Test_shiftRight();
void Test_shiftLeft();
//inte gjorda en
void Test_getBit();
void Test_assignNibble();


void Test_assignNibble(){
	iRegister r;
	iRegister e;
	
	r = {0};
	e ={-1};
	
	int x;
	
	
	for(x = 1; x < 9;x++){
		assert(e.content != r.content);
		assignNibble(x,15,&r);
	}
	
	
	printf("assignNibble works\n" );
}

void Test_getBit(){
	iRegister r;
	iRegister e;
	int x;
	e = {56};//set all bits in control

	r = {-536870905};	
	assert(0 != getBit(0,&r));
	assert(1 == getBit(0,&r));
	
	assert(1 == getBit(31,&r));
	
	for(x = 0; x < 32;x++){
		assert(1 == getBit(x,&r) || 0 == getBit(x,&r));
	}
	
	assert(-1 == getBit(-1,&r));
	assert(-1 == getBit(32,&r));
	
	printf("getBit works\n" );
}



int main (){
	iRegister r;
	iRegister e;
	e = {0};//set all bits in control

	r = {-1};	
	
	//test test test set test test test test test test test test test test test test test test test test test test test
	
	/* Put all your test cases for the implemented functions here */
	
	printf("Start tests \n");
	
	Test_setAll();
	Test_resetAll();
	Test_reg2str();
	Test_setBit();
	Test_resetBit();	
	Test_getNibble();
	Test_shiftRight();
	Test_shiftLeft();
	
	Test_getBit();
	Test_assignNibble();
	
	
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
	
	assert(memcmp("00000000000000000000000000000001", reg2str(r),32) != 0);
	
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

void Test_setBit(){
	iRegister r;
	iRegister e;
	e = {1};//set all bits in control

	r = {0};	
	assert(e.content != r.content); //test that the they are diffrent
	
	setBit(0,&r);
	assert(e.content == r.content); //test seting the first bit
	
	e = {-2147483647};
	setBit(31,&r);
	assert(e.content == r.content); //test seting the last bit and that it retanis the privies oltering
	
	setBit(31,&r);
	assert(e.content == r.content);//test that seting a olredy set bit dosent chenge enything
	
	e = {-2147418111};
	
	setBit(16,&r);
	assert(e.content == r.content);//adding a bit in the middel to see that i works
	
	setBit(-1,&r);
	assert(e.content == r.content); //test that going below the regiseter dosen brak eny thing
	
	setBit(32,&r);
	assert(e.content == r.content);//testing in seting a bit over the register that it dosent brak enithing
	
	printf("setBit works\n" );
}

void Test_resetBit(){
	iRegister r;
	iRegister e;
	e = {0};//set all bits in control

	r = {1};	
	assert(e.content != r.content); //test that the they are diffrent
	
	resetBit(0,&r);
	assert(e.content == r.content); //test seting the first bit
	
	r = {-2147483647};
	resetBit(31,&r);
	resetBit(0,&r);
	assert(e.content == r.content); //test seting the last bit and that it retanis the privies oltering
	
	resetBit(31,&r);
	assert(e.content == r.content);//test that seting a olredy set bit dosent chenge enything
	
	r = {65536 };
	resetBit(16,&r);
	assert(e.content == r.content);//adding a bit in the middel to see that i works
	
	resetBit(-1,&r);
	assert(e.content == r.content); //test that going below the regiseter dosen brak eny thing
	
	resetBit(32,&r);
	assert(e.content == r.content);//testing in seting a bit over the register that it dosent brak enithing
	
	printf("resetBit works\n" );
}

void Test_getNibble(){
	iRegister r;
	iRegister e;
	e = {0};//set all bits in control

	r = {1793};	
	//getNibble(1,&r);
	assert(e.content != getNibble(1,&r));

	assert(e.content == getNibble(2,&r));
	
	e = {1};
	getNibble(1,&r);
	assert(e.content == getNibble(1,&r));
	
    e = {7};
	assert(7 == getNibble(3,&r));
	
	assert(-1 == getNibble(-1,&r));
	
	assert(-1 == getNibble(9,&r));
	
	
	printf("getNibble works\n" );
}

void Test_shiftRight(){
	iRegister r;
	iRegister e;
	e = {33554432};//set all bits in control

	r = {-2147483587};	
	shiftRight(6,&r);
	assert(e.content == r.content);
	
	e = {0};
	r = {-1};	
	shiftRight(32,&r);
	assert(e.content == r.content);
	
	shiftRight(32,&r);
	assert(e.content == r.content);
	
	e = {-1};
	r = {-1};	
	shiftRight(0,&r);
	assert(-1 == r.content);
	
	shiftRight(33,&r);
	assert(-1 == r.content);
	
	printf("shiftRight works\n" );
}

void Test_shiftLeft(){
	iRegister r;
	iRegister e;
	e = {56};//set all bits in control

	r = {-536870905};	
	shiftLeft(3,&r);
	assert(e.content == r.content);
	
	e = {0};
	r = {-1};	
	shiftLeft(32,&r);
	assert(e.content == r.content);
	
	shiftLeft(32,&r);
	assert(e.content == r.content);
	
	e = {-1};
	r = {-1};	
	shiftLeft(0,&r);
	assert(-1 == r.content);
	
	shiftLeft(33,&r);
	assert(-1 == r.content);
	
	printf("shiftLeft works\n" );
}