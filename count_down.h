typedef int kcg_bool ;
typedef int kcg_int ;
kcg_int kcg_true=1;
kcg_int kcg_false=0;


typedef struct{
    kcg_bool Reset;
    kcg_int N;    
}inC_count_down_digital;

typedef struct{
    kcg_int cpt;
    kcg_bool init;
    kcg_int _L4;
}outC_count_down_digital;

