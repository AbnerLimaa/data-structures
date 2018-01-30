#include <stdlib.h>
#include "stack.h"

typedef struct node node;

struct node
{
    int key;
    node *nxt;
};

struct stack
{
    node *top;
};

int stkepty(stack *stk);

node *newnd(int key)
{
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

stack *newstk()
{
    stack *stk = (stack*)malloc(sizeof(stack));
    if(stk == NULL)
        return NULL;
    stk->top = NULL;
    return stk;
}

void freestk(stack *stk)
{
    if(stk != NULL)
    {
        int key;
        while(stkepty(stk) != 1)
            key = pop(stk);
        free(stk);
        stk = NULL;
    }
}

void push(stack *stk, int key)
{
    if(stk != NULL)
    {
        node *nd = newnd(key);
        if(nd != NULL)
        {
            if(stkepty(stk))
                stk->top = nd;
            else
            {
                nd->nxt = stk->top;
                stk->top = nd;
            }
        }
    }
}

int pop(stack *stk)
{
    if(stkepty(stk))
        return 0;
    int key = stk->top->key;
    node *top = stk->top;
    stk->top = top->nxt;
    freend(top);
    return key;
}

int stkepty(stack *stk)
{
    if(stk == NULL || stk->top == NULL)
        return 1;
    return 0;
}