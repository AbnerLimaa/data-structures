#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashtable.h"

int testnewhshtbl()
{
    int test;
    hashtable *hshtbl = newhshtbl(10);
    if(hshtbl != NULL)
        test = 1;
    else
        test = 0;
    freehshtbl(hshtbl);
    return test;
}

int testaddhshtblvalinp()
{
    int test, j = 0;
    int numbers[50];
    hashtable *hshtbl = newhshtbl(10);
    srand(time(NULL));
    while(j < 50)
    {
        int r = rand() % 100;
        if(r != 0)
        {   
            numbers[j] = r;
            addhshtbl(hshtbl, r);
            j++;
        }
    }
    j = 0;
    while(j < 50 && searchhshtbl(hshtbl, numbers[j]) == 1)
        j++;       
    if(j == 50)
        test = 1;
    else
        test = 0;
    freehshtbl(hshtbl);
    return test;
}

int testaddhshtblinvalinp()
{
    int test;
    hashtable *hshtbl = newhshtbl(10);
    addhshtbl(hshtbl, 0);
    if(searchhshtbl(hshtbl, 0) == 0)
        test = 1;
    else
        test = 0;
    freehshtbl(hshtbl);
    return test;
}

int testaddhshtblnullinp()
{
    int test, j = 0;
    int numbers[50];
    hashtable *hshtbl = NULL;
    srand(time(NULL));
    while(j < 50)
    {
        int r = rand() % 100;
        if(r != 0)
        {   
            numbers[j] = r;
            addhshtbl(hshtbl, r);
            j++;
        }
    }
    j = 0;
    while(j < 50 && searchhshtbl(hshtbl, numbers[j]) == 1)
        j++; 
    if(j == 0)
        test = 1;
    else
        test = 0;
    freehshtbl(hshtbl);
    return test;
}

int testremhshtblvalinp()
{
    int test, j = 0;
    int numbers[50];
    hashtable *hshtbl = newhshtbl(10);
    srand(time(NULL));
    while(j < 50)
    {
        int r = rand() % 100;
        if(r != 0)
        {   
            numbers[j] = r;
            addhshtbl(hshtbl, r);
            j++;
        }
    }
    j = 0;
    while(j < 50 && remhshtbl(hshtbl, numbers[j]) == numbers[j])
        j++;
    if(j == 50)
    {
        j = 0;
        while(j < 50 && searchhshtbl(hshtbl, numbers[j]) == 0)
            j++; 
        if(j == 50)
            test = 1;
        else
            test = 0;
    }
    else
        test = 0;
    freehshtbl(hshtbl);
    return test;
}

int testremhshtblinvalinp()
{
    int test, j = 0;
    int numbers[50];
    hashtable *hshtbl = newhshtbl(10);
    srand(time(NULL));
    while(j < 50)
    {
        int r = rand() % 100;
        if(r != 0)
        {   
            numbers[j] = r;
            addhshtbl(hshtbl, r);
            j++;
        }
    }
    j = 0;
    while(j < 50 && remhshtbl(hshtbl, 0) == 0)
        j++;
    if(j == 50)
    {
        j = 0;
        while(j < 50 && searchhshtbl(hshtbl, numbers[j]) == 1)
            j++; 
        if(j == 50)
            test = 1;
        else
            test = 0;
    }
    else
        test = 0;
    freehshtbl(hshtbl);
    return test;
}

int testremhshtblnullinp()
{
    int test, j = 0;
    int numbers[50];
    hashtable *hshtbl = NULL;
    srand(time(NULL));
    while(j < 50)
    {
        int r = rand() % 100;
        if(r != 0)
        {   
            numbers[j] = r;
            j++;
        }
    }
    j = 0;
    while(j < 50 && remhshtbl(hshtbl, numbers[j]) == 0)
        j++;
    if(j == 50)
        test = 1;
    else
        test = 0;
    freehshtbl(hshtbl);
    return test;
}

int testsearchhshtblvalinp()
{
    int test, j = 0;
    int numbers[50];
    hashtable *hshtbl = newhshtbl(10);
    srand(time(NULL));
    while(j < 50)
    {
        int r = rand() % 100;
        if(r != 0)
        {   
            numbers[j] = r;
            addhshtbl(hshtbl, r);
            j++;
        }
    }
    j = 0;
    while(j < 50 && searchhshtbl(hshtbl, numbers[j]) == 1)
        j++;       
    if(j == 50)
        test = 1;
    else
        test = 0;
    freehshtbl(hshtbl);
    return test;
}

int testsearchhshtblinvalinp()
{
    int test, j = 0;
    int numbers[50];
    hashtable *hshtbl = newhshtbl(10);
    srand(time(NULL));
    while(j < 50)
    {
        int r = rand() % 100;
        if(r != 0)
        {   
            numbers[j] = r;
            addhshtbl(hshtbl, r);
            j++;
        }
    }
    j = 0;
    while(j < 50 && searchhshtbl(hshtbl, 0) == 0)
        j++;       
    if(j == 50)
        test = 1;
    else
        test = 0;
    freehshtbl(hshtbl);
    return test;
}

int testsearchhshtblnullinp()
{
    int test, j = 0;
    int numbers[50];
    hashtable *hshtbl = NULL;
    srand(time(NULL));
    while(j < 50)
    {
        int r = rand() % 100;
        if(r != 0)
        {   
            numbers[j] = r;
            j++;
        }
    }
    j = 0;
    while(j < 50 && searchhshtbl(hshtbl, numbers[j]) == 0)
        j++;       
    if(j == 50)
        test = 1;
    else
        test = 0;
    freehshtbl(hshtbl);
    return test;
}

int testfreehshtblvalinp()
{
    int j = 0;
    int numbers[50];
    hashtable *hshtbl = newhshtbl(10);
    srand(time(NULL));
    while(j < 50)
    {
        int r = rand() % 100;
        if(r != 0)
        {   
            numbers[j] = r;
            addhshtbl(hshtbl, r);
            j++;
        }
    }
    freehshtbl(hshtbl);
    if(hshtbl == NULL)
        return 1;
    return 0;
}

int testfreehshtblnullinp()
{
    hashtable *hshtbl = NULL;
    freehshtbl(hshtbl);
    if(hshtbl == NULL)
        return 1;
    return 0;
}

int main(void)
{
    printf("Test of ADT hashtable.\n");
    //Test newhshtbl();
    if(testnewhshtbl())
        printf("newhshtbl(): OK.\n");
    else   
        printf("newhshtbl(): NO.\n");

    //Test addhshtbl(hashtabl *hshtbl, int key);
    printf("addhshtbl(hashtable *hshtbl, int key):\n");
    if(testaddhshtblvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testaddhshtblinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tInvalid input: NO.\n");
    if(testaddhshtblnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test remhshtbl(hashtable *hshtbl, int key);
    printf("remhshtbl(hashtable *hshtbl, int key):\n");
    if(testremhshtblvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testremhshtblinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tInvalid input: NO.\n");
    if(testremhshtblnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test searchhshtbl(hashtable *hshtbl, int key);
    printf("searchhshtbl(hashtable *hshtbl, int key):\n");
    if(testsearchhshtblvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testsearchhshtblinvalinp())
        printf("\tInvalid input: OK.\n");
    else
        printf("\tInvalid input: NO.\n");
    if(testsearchhshtblnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test freelhshtbl(hashtable *hshtbl);
    printf("freelhshtbl(hashtable *hshtbl):\n");
    if(testfreehshtblvalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testfreehshtblnullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");
    return 0;
}