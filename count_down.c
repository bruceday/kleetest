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

void count_down_digital(kcg_bool Reset, kcg_int N,kcg_int cpt,kcg_bool init,kcg_int _L4)
{
	if (Reset)
	{
		cpt = N;
	}
	else if (init)
	{
		cpt = N;
	}
	else
	{
		cpt = _L4;
	}
	_L4 =cpt - 1;
	init = kcg_false;
}

void main()
{
	kcg_bool Reset;
	kcg_int N; 
	kcg_int cpt;
	kcg_bool init; 
	kcg_int _L4;
	klee_make_symbolic(&N, sizeof(N), "N");
	klee_make_symbolic(&Reset, sizeof(Reset), "Reset");
	klee_make_symbolic(&cpt, sizeof(cpt), "cpt");
	klee_make_symbolic(&init, sizeof(init), "init");
	klee_make_symbolic(&_L4, sizeof(_L4), "_L4");
	return count_down_digital(Reset,N,cpt,init,_L4);
}