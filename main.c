//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"

int main (){
	iRegister r;
	char out[33];
	int x;
	//,bljab,
	/* Put all your test cases for the implemented functions here */

	printf("Start tests \n");
	
	/* Tests */
	setAll(&r);
	printf("%d \n",getBit(1,&r));
	
	printf("%d",sizeof(r));
	int i;
	for(i = sizeof(reg2str(r)); i >= 0; i--){
		printf("%c", reg2str(r)[i]);
	}
	printf("\n");
	printf("%d", r.content);
	return 0;
}
