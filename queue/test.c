#include <stdio.h>
#include "queue.h"

int testnewque()
{
    int test;
    queue *que = newque();
    if(que != NULL)
        test = 1;
    else
        test = 0;
    freeque(que);
    return test;
}

int testenqueuevalinp()
{
    int test;
    queue *que = newque();
    enqueue(que, 1);
    enqueue(que, 2);
    enqueue(que, 3);
    if(dequeue(que) == 1)
        test = 1;
    else
        test = 0;
    freeque(que);
    return test;
}

int testenqueuenullinp()
{
    int test;
    queue *que = NULL;
    enqueue(que, 1);
    if(dequeue(que) == 0)
        test = 1;
    else
        test = 0;
    return test;
}

int testdequeuevalinp()
{
    int test;
    queue *que = newque();
    enqueue(que, 1);
    enqueue(que, 2);
    enqueue(que, 3);
    if(dequeue(que) == 1)
        test = 1;
    else
        test = 0;
    freeque(que);
    return test;
}

int testdequeuenullinp()
{
    int test;
    if(dequeue(NULL) == 0)
        test = 1;
    else
        test = 0;
    return test;
}

int testfreequevalinp()
{
    queue *que = newque();
    enqueue(que, 1);
    enqueue(que, 2);
    enqueue(que, 3);
    freeque(que);
    if(que == NULL)
        return 1;
    return 0;
}

int testfreequenullinp()
{
    queue *que = NULL;
    freeque(que);
    if(que == NULL)
        return 1;
    return 0;
}

int main(void)
{
    printf("Test of ADT queue.\n");
    //Test newque();
    if(testnewque())
        printf("newque(): OK.\n");
    else   
        printf("newque(): NO.\n");

    //Test enqueue(queue *que, int key);
    printf("enqueue(queue *que, int key):\n");
    if(testenqueuevalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testenqueuenullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test dequeue(queue *que);
    printf("dequeue(queue *que):\n");
    if(testdequeuevalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testdequeuenullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");

    //Test freeque(queue *que);
    printf("freeque(queue *que):\n");
    if(testfreequevalinp())
        printf("\tValid input: OK.\n");
    else   
        printf("\tValid input: NO.\n");
    if(testfreequenullinp())
        printf("\tNull input: OK.\n");
    else
        printf("\tNull input: NO.\n");
    return 0;
}