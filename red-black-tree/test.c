#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rbtree.h"

int testnewrbtree()
{
    int test;
    rbtree *rb = newrbtree();
    if(rb != NULL)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testtreeminvalinp()
{
    int test, min = 100, i = 0;
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
            if(random < min)
                min = random;
            i++;
        }
    }
    int result = treemin(rb);
    if(result = min)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testtreeminnullinp()
{
    int test;
    rbtree *rb = NULL;
    int result = treemin(rb);
    if(result == 0 && rb == NULL)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testtreemaxvalinp()
{
    int test, max = 1, i = 0;
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
            if(random > max)
                max = random;
            i++;
        }
    }
    int result = treemax(rb);
    if(result = max)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testtreemaxnullinp()
{
    int test;
    rbtree *rb = NULL;
    int result = treemin(rb);
    if(result == 0 && rb == NULL)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testiotwalkvalinp()
{
    int test, i = 0, j = 1;
    int array[10];
    int *result;
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
            array[i] = random;
            i++;
        }
    }
    result = iotwalk(rb);
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
    freerbtree(rb);
    free(result);
    return test;
}

int testiotwalknullinp()
{
    int *result = NULL;
    rbtree *rb = NULL;
    result = iotwalk(rb);
    if(rb == NULL && result == NULL)
        return 1;
    return 0;
}

int testrbsearchvalinp()
{
    int test, i = 0;
    int array[10];
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
            array[i] = random;
            i++;
        }
    }
    i = 0;
    while(i < 10 && rbsearch(rb, array[i]) == 1)
        i++;
    if(i == 10)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testrbsearchinvalinp()
{
    int test, i = 0, random;
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(random != 0 && random > 10 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
            i++;
        }
    }
    i = 0;
    while(i < 10)
    {
        random = rand() % 10;
        if(rbsearch(rb, random) == 0)
            i++;
        else
            i = 11;
    }
    if(i == 10)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testrbsearchnullinp()
{
    int random, i = 0;
    rbtree *rb = NULL;
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(rbsearch(rb, random) == 0)
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
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
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
    min = treemin(rb);
    while(i < 10 && array[i] == min)
    {
        min = sucessor(rb, min);
        i++;
    }
    if(i == 10 && sucessor(rb, min) == 0)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testsucessorinvalinp()
{
    int test, i = 0, random;
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(random != 0 && random > 10 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
            i++;
        }
    }
    i = 0;
    while(i < 10)
    {
        random = rand() % 10;
        if(sucessor(rb, random) == 0)
            i++;
        else
            i = 11;
    }
    if(i == 10)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testsucessornullinp()
{
    int test, i = 0, random;
    rbtree *rb = NULL;
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(random != 0 && sucessor(rb, random) == 0)
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
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
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
    max = treemax(rb);
    while(i < 10 && array[i] == max)
    {
        max = predecessor(rb, max);
        i++;
    }
    if(i == 10 && predecessor(rb, max) == 0)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testpredecessorinvalinp()
{
    int test, i = 0, random;
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(random != 0 && random > 10 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
            i++;
        }
    }
    i = 0;
    while(i < 10)
    {
        random = rand() % 10;
        if(predecessor(rb, random) == 0)
            i++;
        else
            i = 11;
    }
    if(i == 10)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testpredecessornullinp()
{
    int test, i = 0, random;
    rbtree *rb = NULL;
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(random != 0 && predecessor(rb, random) == 0)
            i++;
        else if(random != 0)
            i = 11;
    }
    if(i == 10)
        return 1;
    return 0;
}

int testrbinsertvalinp()
{
    int test, i = 0;
    int array[10];
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
            array[i] = random;
            i++;
        }
    }
    i = 0;
    while(i < 10 && rbsearch(rb, array[i]) == 1)
        i++;
    if(i == 10)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testrbinsertinvalinp()
{
    int test;
    rbtree *rb = newrbtree();
    rbinsert(rb, 0);
    if(rbsearch(rb, 0) == 0)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testrbinsertnullinp()
{
    int i = 0;
    rbtree *rb = NULL;
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
            i++;
        }
    }
    if(rb == NULL)
        return 1;
    return 0;
}

int testrbdeletevalinp()
{
    int test, i = 0;
    int array[10];
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
            array[i] = random;
            i++;
        }
    }
    i = 0;
    while(i < 10)
    {
        int n = rbdelete(rb, array[i]);
        if(n == array[i])
            i += 2;
        else
        {
            freerbtree(rb);
            return 0;
        }
    }
    i = 0;
    while(i < 10 && rbsearch(rb, array[i]) == 0)
        i += 2;
    if(i == 10)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testrbdeleteinvalinp()
{
    int test, i = 0, random;
    int array[10];
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        random = rand() % 100;
        if(random != 0 && random > 10 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
            array[i] = random;
            i++;
        }
    }
    i = 0;
    while(i < 10)
    {
        random = rand() % 10;
        if(rbdelete(rb, random) == 0)
            i++;
        else
        {
            freerbtree(rb);
            return 0;
        }
    }
    i = 0;
    while(i < 10 && rbsearch(rb, array[i]) == 1)
        i++;
    if(i == 10)
        test = 1;
    else
        test = 0;
    freerbtree(rb);
    return test;
}

int testrbdeletenullinp()
{
    int test, i = 0, random;
    rbtree *rb = NULL;
    while(i < 10)
    {
        random = rand() % 100;
        if(rbdelete(rb, random) == 0)
            i++;
        else
            i = 11;
    }
    if(i == 10)
        return 1;
    return 0;
}

int testfreerbtreevalinp()
{
    int i = 0;
    rbtree *rb = newrbtree();
    srand(time(NULL));
    while(i < 10)
    {
        int random = rand() % 100;
        if(random != 0 && rbsearch(rb, random) == 0)
        {
            rbinsert(rb, random);
            i++;
        }
    }
    freerbtree(rb);
    if(rb == NULL)
        return 1;
    return 0;
}

int testfreerbtreenullinp()
{
    int i = 0;
    rbtree *rb = NULL;
    freerbtree(rb);
    if(rb == NULL)
        return 1;
    return 0;
}

int main(void)
{
    printf("Test of Binary Search Tree.\n");
    //Test newrbtree();
    if(testnewrbtree())
        printf("newrbtree(): OK.\n");
    else   
        printf("newrbtree(): NO.\n");

    //Test treemin(rbtree *rb);
    printf("treemin(rbtree *rb):\n");
    if(testtreeminvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testtreeminnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test treemax(rbtree *rb);
    printf("treemax(rbtree *rb):\n");
    if(testtreemaxvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testtreemaxnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test iotwalk(rbtree *rb);
    printf("iotwalk(rbtree *rb):\n");
    if(testiotwalkvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testiotwalknullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test rbsearch(rbtree *rb, int key);
    printf("rbsearch(rbtree *rb, int key):\n");
    if(testrbsearchvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testrbsearchinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tInvalid input: NO.\n");
    if(testrbsearchnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test sucessor(rbtree *rb, int key);
    printf("sucessor(rbtree *rb, int key):\n");
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

    //Test predecessor(rbtree *rb, int key);
    printf("predecessor(rbtree *rb, int key):\n");
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

    //Test rbinsert(rbtree *rb, int key);
    printf("rbinsert(rbtree *rb, int key):\n");
    if(testrbinsertvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testrbinsertinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tInvalid input: NO.\n");
    if(testrbinsertnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test rbdelete(rbtree *rb, int key);
    printf("rbdelete(rbtree *rb, int key):\n");
    if(testrbdeletevalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testrbdeleteinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tInvalid input: NO.\n");
    if(testrbdeletenullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test freerbtree(rbtree *rb);
    printf("freerbtree(rbtree *rb):\n");
    if(testfreerbtreevalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testfreerbtreenullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");
    return 0;
}