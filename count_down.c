typedef int kcg_bool;
typedef int kcg_int;
kcg_int kcg_true = 1;
kcg_int kcg_false = 0;


typedef struct {
	kcg_bool Reset;
	kcg_int N;
}inC_count_down_digital;

typedef struct {
	kcg_int cpt;
	kcg_bool init;
	kcg_int _L4;
}outC_count_down_digital;

// #include <klee/klee.h>
#include<stdio.h>

// void count_down_reset_digital(outC_count_down_digital *outC)
// {
//     outC->init = kcg_true;
// }

void count_down_digital(inC_count_down_digital *inC, outC_count_down_digital *outC)
{
	if (inC->Reset)
	{
		outC->cpt = inC->N;
	}
	else if (outC->init)
	{
		outC->cpt = inC->N;
	}
	else
	{
		outC->cpt = outC->_L4;
	}
	outC->_L4 = outC->cpt - 1;
	outC->init = kcg_false;
}

void main()
{
	inC_count_down_digital inC;
	outC_count_down_digital outC;
	 klee_make_symbolic(&inC.N, sizeof(inC.N), "n");
	 klee_make_symbolic(&inC.Reset, sizeof(inC.Reset), "r");
	 klee_make_symbolic(&outC.cpt, sizeof(outC.cpt), "c");
	 klee_make_symbolic(&outC.init, sizeof(outC.init), "i");
	 klee_make_symbolic(&outC._L4, sizeof(outC._L4), "l");
	 return count_down_digital(&inC,&outC);
}