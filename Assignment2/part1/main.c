#include "stdlib.h"
#include "stdio.h"
#include "TaylorSeries.h"
#include "assert.h"
#include "string.h"
#include "time.h"
#include "limits.h"
#include <CUnit/Basic.h>
//#include "CUnit/CUnit.h"

void test_expFraction(void){
	srand(time(0));
	int i, test;

	//for(i = 0; i < 5;i++){//testar så att det inte kan bli störe en 2 desimaler
		test = iexp(-10000000)->expFraction;
		CU_ASSERT(1 == 1);
	//}
}

int main (){
	//expStruct *temp = iexp(4);

	printf("Start stuff");

	//free(temp);

	CU_pSuite pSuite = NULL;

	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	pSuite = CU_add_suite("test_expFraction",0,0);
	if (NULL == pSuite) {
      return CU_get_error();
  }
	CU_add_test(pSuite, "test of fprintf()", test_expFraction);
	
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();

}

/*

gcc -Wall -I$HOME/local/include MyProg.c -L$HOME/local/lib -lcunit -o myprog
*/
