//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.
 
#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"
#include <string.h>

void resetBit(int i, iRegister *r) {
	if(0 <= i < 32 && r != NULL) {
		r->content &= ~(1 << i);
	}
}

void resetAll(iRegister *r){
	if(r->content != NULL){
		r->content |= 0;
	}
}

void setBit(int i, iRegister *r) {
	if(0 <= i < 32 && r->content != NULL) {
		r->content |= (1 << i);
	}
}

void setAll(iRegister *r) {
	if(r->content != NULL) {
		r->content |= ~0;
	}
}

int getBit(int i, iRegister *r){
	if(0 > i >= 32 || r->content == NULL) {return -1;}
		return (r->content >> i) & 1;
}

void assignNibble(int i, int val, iRegister *r){	
	if(0 <= val < 16 && 0 < i <= 8 && r->content != NULL)   {
		r->content &= ~(0xF<<((i-1)*4)); //Masking
		r->content |= (val<<((i-1)*4));
	}
}

int getNibble(int i, iRegister *r){
	if(0 >= i > 8 || r->content == NULL) {return -1;}
		return r->content >> (((i-1)*4) & 0xF);
}

char *reg2str(iRegister r) {
	if(r.content == NULL){return NULL;}
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
	return output;
}
void shiftRight(int i, iRegister *r){
	if(0 <= i < 32 && r->content != NULL) {
		r->content = r->content>>i;
	}
}
void shiftLeft(int i, iRegister *r){
	if(0 <= i < 32 && r->content != NULL) {
		r->content = r->content<<i;
	}
}
