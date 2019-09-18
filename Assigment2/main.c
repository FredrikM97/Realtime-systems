#include <stdlib.h>
#include <stdio.h>
#include "TaylorSeries.h"
#include <cstring>
#include <assert.h>
#include <time.h>
#include <limits.h>

int main (){	
	expStruct *temp = iexp(4);
	
	printf("%d\n",temp->expInt);
	printf("%s\n",expToString(temp));
	
	free(temp);
	return 0;
}
