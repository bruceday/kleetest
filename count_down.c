#include "count_down.h"

void count_down_reset_digital(outC_count_down_digital *outC)
{
    outC->init = kcg_true;
}

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

int main()
{
    inC_count_down_digital *inC;
    outC_count_down_digital *outC;
    klee_make_symbolic(&inC->N, sizeof(inC->N), "n");
    klee_make_symbolic(&inC->Reset, sizeof(inC->Reset), "r");
    klee_make_symbolic(&outC->cpt, sizeof(outC->cpt), "c");
    klee_make_symbolic(&outC->init, sizeof(outC->init), "i");
    klee_make_symbolic(&outC->_L4, sizeof(outC->_L4), "l");
    return count_down_digital(inC,outC);
}