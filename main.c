//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"
#include <cstring>
#include <assert.h>
#include <time.h>
#include <limits.h>


void Tests();
void Test_setAll();
void Test_setBit();
void Test_resetAll();
void Test_reg2str();
void Test_resetBit();
void Test_getNibble();
void Test_shiftRight();
void Test_shiftLeft();
void Test_getBit();
//inte gjorda en
void Test_assignNibble();






int main (){	
	//test test test set test test test test test test test test test test test test test test test test test test test
	
	/* Put all your test cases for the implemented functions here */
	Tests();
	return 0;
}

void Tests(){
	printf("Start tests \n\n");
	
	Test_resetAll();
	Test_setBit();
	Test_setAll();
	Test_getBit();
	Test_assignNibble();	
	Test_getNibble();
	Test_reg2str();
	Test_shiftRight();
	Test_shiftLeft();
	Test_resetBit();
	
	printf("\nall tests have been comlpeted\n");
}

void Test_resetAll(){//klar 
	iRegister r;
	iRegister e;
	srand(time(0));
	int x;
	e = {0}; //set all bits in the control
	
	r = {0};
	resetAll(&r);
	assert(e.content == r.content); //test if all bits get set if r is only zeros
	
	r = {-1};
	resetAll(&r);
	assert(e.content == r.content); //tests if all bits remaining on if r starts white all bits set
	
	for(x = 0; x < 32;x++){ //test resetAll on random int nummbers
		r = {rand()+1}; 		// set random positev int
		resetAll(&r);
		assert(e.content == r.content);
	}
	
	printf("resetAll works\n" );
}

void Test_setBit(){ //klar
	iRegister r;
	iRegister e;
	srand(time(0));
	int x, temp;
	e = {1};//set all bits in control

	r = {0};		
	setBit(0,&r);
	assert(e.content == r.content); //test seting the first bit
	
	e = {-2147483647};
	setBit(31,&r);
	assert(e.content == r.content); //test seting the last bit and that it retains the previes changes

	r = {0};
	e = {0};
	setBit(-1,&r);
	assert(e.content == r.content); //test that going below the regiseter dosent break any thing
	
	setBit(32,&r);
	assert(e.content == r.content);//testing in seting a bit over the register that it dosent brak enithing

	r = {0};
	e = {0};
	for(x = 0; x < 35;x++){ //test setBit on random int nummberspos and set bit on a alrady set bit
		temp = rand()%31;
		setBit(temp,&r);
		e = {e.content | 1<<temp};
		assert(e.content == r.content);
	}
	
	
	printf("setBit works\n" );
}

void Test_setAll(){ //klar
	iRegister r;
	iRegister e;
	srand(time(0));
	int x;
	e = {-1}; // set all bits in control
	
	r = {0};
	setAll(&r);
	assert(e.content == r.content);//test if all bits get set if r is only zeros
	
	r = {-1};
	setAll(&r);
	assert(e.content == r.content);//tests if all bits reman on if r starts white all bits
	
	for(x = 0; x < 32;x++){ //test setall on random int nummbers
		r = {rand()}; 		// set random positev int
		setAll(&r);
		assert(e.content == r.content);
	}
	
	printf("setAll works\n" );
}

void Test_getBit(){ //klar
	iRegister r;
	iRegister e;
	int x,y;
	srand(time(0));
	e = {56};//set all bits in control

	r = {-536870905};	
	
	assert(0 != getBit(0,&r)); //test first bit
	assert(1 == getBit(0,&r));
	
	assert(1 == getBit(31,&r)); // test last bit
	
	assert(-1 == getBit(-1,&r));//test out of bounse
	assert(-1 == getBit(32,&r));//test out of bounse
	/* 
	for(x = 0; x < 32;x++){ //test that it only returns 0 or 1
		r = {rand()}; // set random positev int
		for(y = 0; y < 32;y++){ 
			assert(1 == getBit(y,&r) || 0 == getBit(y,&r));
		}
	}
	*/
	printf("getBit works\n" );
}

void Test_assignNibble(){
	iRegister r;
	iRegister e;
	
	r = {0};
	e ={-2147483593};
	
	int x;
	
	assignNibble(1,7,&r);
	assert(e.content != r.content); 
	assignNibble(2,3,&r);
	assert(e.content != r.content); 
	assignNibble(8,8,&r);
	assert(e.content == r.content); 
	
	assignNibble(8,0,&r);
	assert(0 < r.content); 
	

	r = {0};
	e ={0};
	
	assignNibble(0,4,&r);
	assert(e.content == r.content); //test out of bounse
	
	assignNibble(9,4,&r);
	assert(e.content == r.content); //test out of bounse
	
	assignNibble(1,-1,&r);
	assert(e.content == r.content); //test out of bounse
	
	assignNibble(-1,16,&r);
	assert(e.content == r.content); //test out of bounse
	
	
	printf("assignNibble works\n" );
}

void Test_getNibble(){ //klar
	iRegister r;
	iRegister e;
	e = {0};//set all bits in control

	r = {1793};	
	assert(e.content != getNibble(1,&r));

	assert(e.content == getNibble(2,&r));
	
    e = {7};
	assert(7 == getNibble(3,&r));
	
	assert(-1 == getNibble(-1,&r)); //test out of bounse
	
	assert(-1 == getNibble(9,&r)); //test out of bounse
	
	
	printf("getNibble works\n" );
}

void Test_reg2str(){//Klar
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
	
	printf("reg2str works\n" );
}

void Test_shiftRight(){ //klar
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
	assert(-1 == r.content); //test out of bounse
	
	shiftRight(33,&r);
	assert(-1 == r.content); //test out of bounse
	
	printf("shiftRight works\n" );
}

void Test_shiftLeft(){ //klar
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
	assert(-1 == r.content); //test out of bounse
	
	shiftLeft(33,&r);
	assert(-1 == r.content); //test out of bounse
	
	printf("shiftLeft works\n" );
}

void Test_resetBit(){ //Klar
	iRegister r;
	iRegister e;
	int x,temp;
	srand(time(0));
	e = {0};//set all bits in control

	r = {1};	
	resetBit(0,&r);
	assert(e.content == r.content); //test seting the first bit
	
	r = {-2147483647};
	resetBit(31,&r);
	resetBit(0,&r);
	assert(e.content == r.content); //test seting the last bit and that it retanis the privies oltering
	
	resetBit(-1,&r);
	assert(e.content == r.content); //test that going below the regiseter dosen brak eny thing
	
	resetBit(32,&r);
	assert(e.content == r.content);//testing in seting a bit over the register that it dosent brak enithing
	
	r = {-1};
	e = {-1};
	for(x = 0; x < 35;x++){ //test resetBit on random int nummberspos and reset a bit on a alrady been reset bit
		temp = rand()%31;
		resetBit(temp,&r);
		e = {e.content & ~(1<<temp)};
		//printf("temp = %d, \nr= %d,\ne = %d\n",temp, r.content, e.content);
		assert(e.content == r.content);
	}
	
	printf("resetBit works\n" );
}