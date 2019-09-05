//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.
 
#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"
#include <string.h>

void resetBit(int i, iRegister *r) {
	r->content &= ~(1 << i);
}

void resetAll(iRegister *r){
	r->content |= 0;
}

void setBit(int i, iRegister *r) {
	r->content |= (1 << i);
}

void setAll(iRegister *r) {
	r->content |= ~0;
}

int getBit(int i, iRegister *r){
	return (r->content >> i) & 1;
}

void assignNibble(int pos, int val, iRegister *r){	
	r->content &= ~(0xF<<((pos-1)*4)); //Masking
	r->content |= (val<<((pos-1)*4));
}

int getNibble(int pos, iRegister *r){
	return r->content >> (((pos-1)*4) & 0xF);
}

char *reg2str(iRegister r) {
	static char output[33];
	
	int i; 
	for (i = 31; i >= 0; i--){
		//shift left check value, if 1 store in char at position i
		if(getBit(i,&r) == 1) {
			output[31-i] = '1';
		}else {
			output[31-i] = '0';
		}
	}
	output[32] = 0x0;
	return output; //check why &
}
void shiftRight(int i, iRegister *r){
	r->content |= 0<<i;
}
void shiftLeft(int i, iRegister *r){
	r->content |= 0>>i;
}

bool assert(char *i, iRegister r){
	if(memcmp(i, reg2str(r),32) == 0) { return true;}
	return false;
}
