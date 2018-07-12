#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bstree.h"

int testnewbstree()
{
    int test;
    bstree *bs = newbstree();
    if(bs != NULL)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testtreeminvalinp()
{
    int test, min = 100, i = 0;
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            if(random < min)
                min = random;
            i++;
        }
    }
    int result = treemin(bs);
    if(result = min)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testtreeminnullinp()
{
    int test;
    bstree *bs = NULL;
    int result = treemin(bs);
    if(result == 0 && bs == NULL)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testtreemaxvalinp()
{
    int test, max = 1, i = 0;
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            if(random > max)
                max = random;
            i++;
        }
    }
    int result = treemax(bs);
    if(result = max)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testtreemaxnullinp()
{
    int test;
    bstree *bs = NULL;
    int result = treemin(bs);
    if(result == 0 && bs == NULL)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testiotwalkvalinp()
{
    int test, i = 0, j = 1;
    int array[10];
    int *result;
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            array[i] = random;
            i++;
        }
    }
    result = iotwalk(bs);
    i = 0;
    while(i < 9)
    {
        j = i + 1;
        while(j < 10)
        {
            if(array[j] < array[i])
            {
                int aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while(i < 10 && array[i] == result[i])
        i++;
    if(i == 10)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    free(result);
    return test;
}

int testiotwalknullinp()
{
    int *result = NULL;
    bstree *bs = NULL;
    result = iotwalk(bs);
    if(bs == NULL && result == NULL)
        return 1;
    return 0;
}

int testbssearchvalinp()
{
    int test, i = 0;
    int array[10];
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            array[i] = random;
            i++;
        }
    }
    i = 0;
    while(i < 10 && bssearch(bs, array[i]) == 1)
        i++;
    if(i == 10)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testbssearchinvalinp()
{
    int test, i = 0, random;
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(random != 0 && random > 10 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            i++;
        }
    }
    i = 0;
    while(i < 10)
    {
        random = rand() % 10;
        if(bssearch(bs, random) == 0)
            i++;
        else
            i = 11;
    }
    if(i == 10)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testbssearchnullinp()
{
    int random, i = 0;
    bstree *bs = NULL;
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(bssearch(bs, random) == 0)
            i++;
        else
            i = 11;
    }
    if(i == 10)
        return 1;
    return 0;
}

int testsucessorvalinp()
{
    int test, i = 0, j = 1, min;
    int array[10];
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            array[i] = random;
            i++;
        }
    }
    i = 0;
    while(i < 9)
    {
        j = i + 1;
        while(j < 10)
        {
            if(array[j] < array[i])
            {
                int aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
            j++;
        }
        i++;
    }
    i = 0;
    min = treemin(bs);
    while(i < 10 && array[i] == min)
    {
        min = sucessor(bs, min);
        i++;
    }
    if(i == 10 && sucessor(bs, min) == 0)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testsucessorinvalinp()
{
    int test, i = 0, random;
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(random != 0 && random > 10 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            i++;
        }
    }
    i = 0;
    while(i < 10)
    {
        random = rand() % 10;
        if(sucessor(bs, random) == 0)
            i++;
        else
            i = 11;
    }
    if(i == 10)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testsucessornullinp()
{
    int test, i = 0, random;
    bstree *bs = NULL;
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(random != 0 && sucessor(bs, random) == 0)
            i++;
        else if(random != 0)
            i = 11;
    }
    if(i == 10)
        return 1;
    return 0;
}

int testpredecessorvalinp()
{
    int test, i = 0, j = 1, max;
    int array[10];
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            array[i] = random;
            i++;
        }
    }
    i = 0;
    while(i < 9)
    {
        j = i + 1;
        while(j < 10)
        {
            if(array[j] > array[i])
            {
                int aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
            j++;
        }
        i++;
    }
    i = 0;
    max = treemax(bs);
    while(i < 10 && array[i] == max)
    {
        max = predecessor(bs, max);
        i++;
    }
    if(i == 10 && predecessor(bs, max) == 0)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testpredecessorinvalinp()
{
    int test, i = 0, random;
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(random != 0 && random > 10 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            i++;
        }
    }
    i = 0;
    while(i < 10)
    {
        random = rand() % 10;
        if(predecessor(bs, random) == 0)
            i++;
        else
            i = 11;
    }
    if(i == 10)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testpredecessornullinp()
{
    int test, i = 0, random;
    bstree *bs = NULL;
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(random != 0 && predecessor(bs, random) == 0)
            i++;
        else if(random != 0)
            i = 11;
    }
    if(i == 10)
        return 1;
    return 0;
}

int testbsinsertvalinp()
{
    int test, i = 0;
    int array[10];
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            array[i] = random;
            i++;
        }
    }
    i = 0;
    while(i < 10 && bssearch(bs, array[i]) == 1)
        i++;
    if(i == 10)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testbsinsertinvalinp()
{
    int test;
    bstree *bs = newbstree();
    bsinsert(bs, 0);
    if(bssearch(bs, 0) == 0)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testbsinsertnullinp()
{
    int i = 0;
    bstree *bs = NULL;
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            i++;
        }
    }
    if(bs == NULL)
        return 1;
    return 0;
}

int testbsdeletevalinp()
{
    int test, i = 0;
    int array[10];
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            array[i] = random;
            i++;
        }
    }
    i = 0;
    while(i < 10)
    {
        int n = bsdelete(bs, array[i]);
        if(n == array[i])
            i += 2;
        else
        {
            freebstree(bs);
            return 0;
        }
    }
    i = 0;
    while(i < 10 && bssearch(bs, array[i]) == 0)
        i += 2;
    if(i == 10)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testbsdeleteinvalinp()
{
    int test, i = 0, random;
    int array[10];
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(random != 0 && random > 10 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            array[i] = random;
            i++;
        }
    }
    i = 0;
    while(i < 10)
    {
        random = rand() % 10;
        if(bsdelete(bs, random) == 0)
            i++;
        else
        {
            freebstree(bs);
            return 0;
        }
    }
    i = 0;
    while(i < 10 && bssearch(bs, array[i]) == 1)
        i++;
    if(i == 10)
        test = 1;
    else
        test = 0;
    freebstree(bs);
    return test;
}

int testbsdeletenullinp()
{
    int test, i = 0, random;
    bstree *bs = NULL;
    while(i < 10)
    {
        random = rand() % 100;
        if(bsdelete(bs, random) == 0)
            i++;
        else
            i = 11;
    }
    if(i == 10)
        return 1;
    return 0;
}

int testfreebstreevalinp()
{
    int i = 0;
    bstree *bs = newbstree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && bssearch(bs, random) == 0)
        {
            bsinsert(bs, random);
            i++;
        }
    }
    freebstree(bs);
    if(bs == NULL)
        return 1;
    return 0;
}

int testfreebstreenullinp()
{
    int i = 0;
    bstree *bs = NULL;
    freebstree(bs);
    if(bs == NULL)
        return 1;
    return 0;
}

int main(void)
{
    printf("Test of Binary Search Tree.\n");
    //Test newbstree();
    if(testnewbstree())
        printf("newbstree(): OK.\n");
    else   
        printf("newbstree(): NO.\n");

    //Test treemin(bstree *bs);
    printf("treemin(bstree *bs):\n");
    if(testtreeminvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testtreeminnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test treemax(bstree *bs);
    printf("treemax(bstree *bs):\n");
    if(testtreemaxvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testtreemaxnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test iotwalk(bstree *bs);
    printf("iotwalk(bstree *bs):\n");
    if(testiotwalkvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testiotwalknullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test bssearch(bstree *bs, int key);
    printf("bssearch(bstree *bs, int key):\n");
    if(testbssearchvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testbssearchinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tInvalid input: NO.\n");
    if(testbssearchnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test sucessor(bstree *bs, int key);
    printf("sucessor(bstree *bs, int key):\n");
    if(testsucessorvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testsucessorinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tInvalid input: NO.\n");
    if(testsucessornullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test predecessor(bstree *bs, int key);
    printf("predecessor(bstree *bs, int key):\n");
    if(testpredecessorvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testpredecessorinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tInvalid input: NO.\n");
    if(testpredecessornullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test bsinsert(bstree *bs, int key);
    printf("bsinsert(bstree *bs, int key):\n");
    if(testbsinsertvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testbsinsertinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tInvalid input: NO.\n");
    if(testbsinsertnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test bsdelete(bstree *bs, int key);
    printf("bsdelete(bstree *bs, int key):\n");
    if(testbsdeletevalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testbsdeleteinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tInvalid input: NO.\n");
    if(testbsdeletenullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test freebstree(bstree *bs);
    printf("freebstree(bstree *bs):\n");
    if(testfreebstreevalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testfreebstreenullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");
    return 0;
}