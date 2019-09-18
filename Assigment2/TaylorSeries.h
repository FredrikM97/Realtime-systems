
struct expStruct {
	int expInt;
	int expFraction;
};

typedef struct expStruct ExpStruct;

ExpStruct * iexp ( int ); 

char *expToString(ExpStruct *iexp);
