#include <stdlib.h>
#include "queue.h"

typedef struct node node;

struct node
{
    int key;
    node *nxt;
};

struct queue
{
    node *head;
    node *tail;
};

int queepty(queue *que);

node *newnd(int key)
{
    if(key == 0)
        return NULL;
    node *nd = (node*)malloc(sizeof(node));
    if(nd == NULL)
        return NULL;
    nd->key = key;
    nd->nxt = NULL;
    return nd;
}

void freend(node *nd)
{
    if(nd != NULL)
        free(nd);
}

queue *newque()
{
    queue *que = (queue*)malloc(sizeof(queue));
    if(que == NULL)
        return NULL;
    que->head = NULL;
    que->tail = NULL;
    return que;
}

void freeque(queue *que)
{
    if(que != NULL)
    {
        int key;
        while(queepty(que) != 1)
            key = dequeue(que);
        free(que);
        que = NULL;
    }
}

void enqueue(queue *que, int key)
{
    if(que != NULL)
    {
        node *nd = newnd(key);
        if(nd != NULL)
        {
            if(queepty(que))
            {
                que->head = nd;
                que->tail = nd;
            }
            else
            {
                que->tail->nxt = nd;
                que->tail = nd;
            }
        }
    }
}

int dequeue(queue *que)
{
    if(queepty(que))
        return 0;
    int key = que->head->key;
    node *nd = que->head;
    que->head = que->head->nxt;
    if(queepty(que))
        que->tail = NULL;
    freend(nd);
    return key;
}

int queepty(queue *que)
{
    if(que == NULL || que->head == NULL || que->tail == NULL)
        return 1;
    return 0;
}