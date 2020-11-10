#include <stdlib.h>
#include <math.h>
#include "stack.h"

typedef struct node node;

/* within this project I've made the following statement:
       1 - returns -INFINITY by pop if the stack is empty */

//defines an stack node
struct node
{
    double key;
    node *nxt;
};

//defines an stack
struct stack
{
    node *top;
};

int stkepty(stack *stk);

//dynamically create a new node
node *newnd(double key)
{
    node *nd = (node*)calloc(1, sizeof(node));
    if(nd == NULL)
        return NULL;
    nd->key = key;
    nd->nxt = NULL;
    return nd;
}

//free the dynamically created node
void freend(node *nd)
{
    if(nd != NULL)
        free(nd);
}

//dynamically create a new stack
stack *newstk()
{
    stack *stk = (stack*)calloc(1, sizeof(stack));
    if(stk == NULL)
        return NULL;
    stk->top = NULL;
    return stk;
}

//free the dynamically created stack
void freestk(stack *stk)
{
    if(stk != NULL)
    {
        while(stkepty(stk) != 1)
            pop(stk);
        free(stk);
        stk = NULL;
    }
}

//add a key to the stack
void push(stack *stk, double key)
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

//remove a key from the stack
double pop(stack *stk)
{
    if(stkepty(stk))
        return -INFINITY;
    double key = stk->top->key;
    node *top = stk->top;
    stk->top = top->nxt;
    freend(top);
    return key;
}

//checks if the stack is empty
int stkepty(stack *stk)
{
    if(stk == NULL || stk->top == NULL)
        return 1;
    return 0;
}

//returns the top of the stack
double top(stack *stk)
{
    if(stkepty(stk) == 0)
        return stk->top->key;
    return -INFINITY;
}