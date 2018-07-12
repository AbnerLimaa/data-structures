#include <stdio.h>
#include "stack.h"

int testnewstk()
{
    int test;
    stack *stk = newstk();
    if(stk != NULL)
        test = 1;
    else
        test = 0;
    freestk(stk);
    return test;
}

int testpushvalinp()
{
    int test;
    stack *stk = newstk();
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);
    if(pop(stk) == 3)
        test = 1;
    else
        test = 0;
    freestk(stk);
    return test;
}

int testpushnullinp()
{
    int test;
    stack *stk = NULL;
    push(stk, 1);
    if(pop(stk) == 0)
        test = 1;
    else
        test = 0;
    return test;
}

int testpopvalinp()
{
    int test;
    stack *stk = newstk();
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);
    if(pop(stk) == 3)
        test = 1;
    else
        test = 0;
    freestk(stk);
    return test;
}

int testpopnullinp()
{
    int test;
    if(pop(NULL) == 0)
        test = 1;
    else
        test = 0;
    return test;
}

int testfreestkvalinp()
{
    stack *stk = newstk();
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);
    freestk(stk);
    if(stk == NULL)
        return 1;
    return 0;
}

int testfreestknullinp()
{
    stack *stk = NULL;
    freestk(stk);
    if(stk == NULL)
        return 1;
    return 0;
}

int main(void)
{
    printf("Test of ADT stack.\n");
    //Test newstk();
    if(testnewstk())
        printf("newstk(): OK.\n");
    else   
        printf("newstk(): NO.\n");

    //Test push(stack *stk, int key);
    printf("push(stack *stk, int key):\n");
    if(testpushvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testpushnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test pop(stack *stk);
    printf("pop(stack *stk):\n");
    if(testpopvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testpopnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test freestk(stack *stk);
    printf("freestk(stack *stk):\n");
    if(testfreestkvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testfreestknullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");
    return 0;
}