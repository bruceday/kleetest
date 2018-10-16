#include "count_down.h"
#include<stdio.h>

void count_down_reset_digital(outC_count_down_digital *outC)
{
    outC->init=kcg_true;    
}

void count_down_digital(inC_count_down_digital *inC,outC_count_down_digital *outC)
{
    if(inC->Reset){
        outC->cpt=inC->N;
    }
    else if(outC->init){
        outC->cpt=inC->N;
    }else{
        outC->cpt=outC->_L4;
    }
    outC->_L4=outC->cpt-1;
    outC->init=kcg_false;
}

int main() {
  inC_count_down_digital a;
  outC_count_down_digital b;
  klee_make_symbolic(&a, sizeof(a), "a");
  klee_make_symbolic(&b, sizeof(b), "b");
  return get_sign(b);
}