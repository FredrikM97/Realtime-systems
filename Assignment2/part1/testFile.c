




void test_expFraction(void){
	srand(time(0));
	int i, test;
	
	for(i = 0; i < 100;i++){//testar så att det inte kan bli störe en 2 desimaler
		test = iexp(rand())->expFraction;
		CU_ASSERT(100 > test && test >= 0);	
	}
}
