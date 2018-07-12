#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"

int testnewlkdlst()
{
    int test;
    linkedlist *lkdlst = newlkdlst();
    if(lkdlst != NULL)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testaddleftlkdlstvalinp()
{
    int test, r;
    srand(time(NULL));
    linkedlist *lkdlst = newlkdlst();
    for(int i = 0; i < 10; i++)
    {
        r = rand() % 100;
        addleftlkdlst(lkdlst, r);
    }
    if(remleftlkdlst(lkdlst) == r)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testaddleftlkdlstinvalinp()
{
    int test;
    linkedlist *lkdlst = newlkdlst();
    addleftlkdlst(lkdlst, 0);
    if(searchlkdlst(lkdlst, 0) == 0)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testaddleftlkdlstnullinp()
{
    int test;
    linkedlist *lkdlst = NULL;
    addleftlkdlst(lkdlst, 1);
    if(searchlkdlst(lkdlst, 1) == 0)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testaddrightlkdlstvalinp()
{
    int test, r;
    srand(time(NULL));
    linkedlist *lkdlst = newlkdlst();
    for(int i = 0; i < 10; i++)
    {
        r = rand() % 100;
        addrightlkdlst(lkdlst, r);
    }
    if(remrightlkdlst(lkdlst) == r)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testaddrightlkdlstinvalinp()
{
    int test;
    linkedlist *lkdlst = newlkdlst();
    addrightlkdlst(lkdlst, 0);
    if(searchlkdlst(lkdlst, 0) == 0)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testaddrightlkdlstnullinp()
{
    int test;
    linkedlist *lkdlst = NULL;
    addrightlkdlst(lkdlst, 1);
    if(searchlkdlst(lkdlst, 1) == 0)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testremleftlkdlstvalinp()
{
    int test, r;
    srand(time(NULL));
    linkedlist *lkdlst = newlkdlst();
    for(int i = 0; i < 10; i++)
    {
        r = rand() % 100;
        addleftlkdlst(lkdlst, r);
    }
    if(remleftlkdlst(lkdlst) == r)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testremleftlkdlstnullinp()
{
    int test;
    linkedlist *lkdlst = NULL;
    if(remleftlkdlst(lkdlst) == 0)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testremrightlkdlstvalinp()
{
    int test, r;
    srand(time(NULL));
    linkedlist *lkdlst = newlkdlst();
    for(int i = 0; i < 10; i++)
    {
        r = rand() % 100;
        addrightlkdlst(lkdlst, r);
    }
    if(remrightlkdlst(lkdlst) == r)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testremrightlkdlstnullinp()
{
    int test;
    linkedlist *lkdlst = NULL;
    if(remrightlkdlst(lkdlst) == 0)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testremlkdlstvalinp()
{
    int test;
    linkedlist *lkdlst = newlkdlst();
    for(int i = 1; i < 10; i++)
        addrightlkdlst(lkdlst, i);
    if(remlkdlst(lkdlst, 7) == 7 && remlkdlst(lkdlst, 1) == 1 && remlkdlst(lkdlst, 9) == 9)
        if(searchlkdlst(lkdlst, 7) == 0 && searchlkdlst(lkdlst, 1) == 0 && searchlkdlst(lkdlst, 9) == 0)
            test = 1;
        else
            test = 0;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testremlkdlstinvalinp()
{
    int test, r;
    srand(time(NULL));
    linkedlist *lkdlst = newlkdlst();
    for(int i = 0; i < 10; i++)
    {
        r = rand() % 100;
        addrightlkdlst(lkdlst, r);
    }
    if(remlkdlst(lkdlst, 150) == 0)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testremlkdlstnullinp()
{
    int test;
    linkedlist *lkdlst = NULL;
    if(remlkdlst(lkdlst, 150) == 0)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testsearchlkdlstvalinp()
{
    int test;
    linkedlist *lkdlst = newlkdlst();
    for(int i = 1; i < 10; i++)
        addrightlkdlst(lkdlst, i);
    if(searchlkdlst(lkdlst, 5) == 1)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testsearchlkdlstinvalinp()
{
    int test;
    linkedlist *lkdlst = newlkdlst();
    for(int i = 0; i < 10; i++)
        addrightlkdlst(lkdlst, i);
    if(searchlkdlst(lkdlst, 20) == 0)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testsearchlkdlstnullinp()
{
    int test;
    linkedlist *lkdlst = NULL;
    if(searchlkdlst(lkdlst, 20) == 0)
        test = 1;
    else
        test = 0;
    freelkdlst(lkdlst);
    return test;
}

int testfreelkdlstvalinp()
{
    int test, r;
    linkedlist *lkdlst = newlkdlst();
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        r = rand() % 100;
        addrightlkdlst(lkdlst, r);
    }
    freelkdlst(lkdlst);
    if(lkdlst == NULL)
        test = 1;
    else
        test = 0;
    return test;
}

int testfreelkdlstnullinp()
{
    int test;
    linkedlist *lkdlst = NULL;
    freelkdlst(lkdlst);
    if(lkdlst == NULL)
        test = 1;
    else
        test = 0;
    return test;
}

int main(void)
{
    printf("Test of ADT linkedlist.\n");
    //Test newlkdlst();
    if(testnewlkdlst())
        printf("newlkdlst(): OK.\n");
    else   
        printf("newlkdlst(): NO.\n");

    //Test addleftlkdlst(linkedlist *lkdlst, int key);
    printf("addleftlkdlst(linkedlist *lkdlst, int key):\n");
    if(testaddleftlkdlstvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testaddleftlkdlstinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tINvalid input: NO.\n");
    if(testaddleftlkdlstnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test addrightlkdlst(linkedlist *lkdlst, int key);
    printf("addrightlkdlst(linkedlist *lkdlst, int key):\n");
    if(testaddrightlkdlstvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testaddrightlkdlstinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tINvalid input: NO.\n");
    if(testaddrightlkdlstnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test remleftlkdlst(linkedlist *lkdlst);
    printf("remleftlkdlst(linkedlist *lkdlst):\n");
    if(testremleftlkdlstvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testremleftlkdlstnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");
    
    //Test remrightlkdlst(linkedlist *lkdlst);
    printf("remrightlkdlst(linkedlist *lkdlst):\n");
    if(testremrightlkdlstvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testremrightlkdlstnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test remlkdlst(linkedlist *lkdlst, int key);
    printf("remlkdlst(linkedlist *lkdlst, int key):\n");
    if(testremlkdlstvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testremlkdlstinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tINvalid input: NO.\n");
    if(testremlkdlstnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test searchlkdlst(linkedlist *lkdlst, int key);
    printf("searchlkdlst(linkedlist *lkdlst, int key):\n");
    if(testsearchlkdlstvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testsearchlkdlstinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tINvalid input: NO.\n");
    if(testsearchlkdlstnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test freelkdlst(linkedlist *lkdlst);
    printf("freelkdlst(linkedlist *lkdlst):\n");
    if(testfreelkdlstvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testfreelkdlstnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");
    return 0;
}