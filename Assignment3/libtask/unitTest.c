#include <stdio.h>
#include "primes.h"
#include "working_primes.h"
#include <CUnit/Basic.h>

void compare_primes(){
  int up2number = 100;
  FILE *expected;
  FILE *input;
  int PATH_MAX = up2number;
  char data1[PATH_MAX];
  char data2[PATH_MAX];

  expected = popen("./working_primes" + up2number, "r");
  input = popen("./primes" + up2number, "r");

  CU_ASSERT(NULL != expected);
  CU_ASSERT(NULL != input);
  int i;
  while (fgets(data1, PATH_MAX, expected) != NULL || fgets(data2, PATH_MAX, expected) != NULL ){
    printf("%s - %s", data[0], data[1]);
    CU_ASSERT(data[0] == data[1]);
  }
}


int main(){
  /*

  */
  printf("Start stuff");
	CU_pSuite pSuite = NULL;

	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	pSuite = CU_add_suite("compare_primes",0,0);
	if (NULL == pSuite) {
      return CU_get_error();
  }
	if(NULL == CU_add_test(pSuite, "Compare primes",compare_primes)){
		CU_cleanup_registry();
  	return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
