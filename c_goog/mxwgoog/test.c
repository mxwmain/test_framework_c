#include <mxwgoog/linklist.h>
#include <mxwgoog/test.h>

int func_cnt = 0;
Function func_head, *func_tail = &func_head;
struct FunctionInfo haizei_test_info;
int RUN_ALL_TESTS() {
    for (struct LinkNode *p = func_head.p.next; p; p = p->next) {
        Function *func = Head(p, Function, p);
        printf(GREEN("[====RUN====]")  RED_HL("%s\n"), func->str);
        haizei_test_info.total = 0, haizei_test_info.success = 0;
        func->func();
        double rate = 100.0 * haizei_test_info.success / haizei_test_info.total;
        printf(PURPLE("[  "));
        if (fabs(rate - 100 ) < 1e-7) {
            printf(GREEN_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(PURPLE("  ] ") GREEN_HL(" total : %d    success : %d\n") , 
               haizei_test_info.total, 
               haizei_test_info.success
         );
    }
    return 0;
}

void add_function(TestFuncT func, const char *str) {
    Function *temp = (Function *)calloc(1, sizeof(Function));
    temp->func = func;
    temp->str = strdup(str);
    func_tail->p.next = &(temp->p);
    func_tail = temp;
    return ;
}
