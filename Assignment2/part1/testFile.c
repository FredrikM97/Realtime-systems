




void test_expFraction(void){
	srand(time(0));
	int i, test;
	
	for(i = 0; i < 100;i++){//testar så att det inte kan bli störe en 2 desimaler
		test = iexp(rand()%22)->expFraction;
		CU_ASSERT(100 > test && test >= 0);	
	}
}


void test_BREAKiexp(void){ //try to break iexp
	srand(time(0));
	int i;
	expStruct test;
	
	test = iexp(-21); //test min int
	CU_ASSERT(test != NULL);	
	free(test);
	
	test = iexp(0);
	CU_ASSERT(test != NULL); //test 0	
	free(test);
	
	test = iexp(22);//test max int
	CU_ASSERT(test != NULL);	
	free(test);
	
	for(i = 0; i < 1000;i++){ //test random int 
		test = iexp(rand()%22);
		CU_ASSERT(test != NULL);	
		free(test);
	}
}
