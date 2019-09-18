#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "TaylorSeries.h"


ExpStruct * iexp ( int x){
	ExpStruct *output = (ExpStruct*) malloc(sizeof (ExpStruct)); //declare structure and allocate it to memory

	int i; //init values
	int n = abs(x)+1;
	float sum = 1;
	int fac = 1;

	for(i = 1; i < n; i++){ //doing the Taylor Series one step at the time
		fac *= i;
		sum += pow(x,i)/fac;
	}

	output->expInt = (int)sum;//allocate the values to the structure
	output->expFraction = (int)((sum - (int)sum)*100.0);

	return output;//return the struktur
}
