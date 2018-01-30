#include <stdlib.h>
#include "linkedlist.h"

typedef struct node node;

/* within this project I've made the following statements:
       1 - returns 0 if search can't find the key
       2 - only inserts if the key is not 0
       3 - returns 0 if the key isn't on the linkedlist */

//defines a linkedlist node
struct node
{
    int key;
    node *nxt;
    node *prev;
};

//defines a linkedlist
struct linkedlist
{
    node *left;
    node *right;
};

int lkdlstepty(linkedlist *lkdlst);

//dynamically create a new node
node *newnd(int key)
{
    node *nd = (node*)malloc(sizeof(node));
    if(key == 0 || nd == NULL)
        return NULL;
    nd->key = key;
    nd->nxt = NULL;
    nd->prev = NULL;
    return nd;
}

//free the dynamically created node
void freend(node *nd)
{
    if(nd != NULL)
        free(nd);
}

//dynamically create a new linkedlist
linkedlist *newlkdlst()
{
    linkedlist *lkdlst = (linkedlist*)malloc(sizeof(linkedlist));
    if(lkdlst == NULL)
        return NULL;
    lkdlst->left = NULL;
    lkdlst->right = NULL;
    return lkdlst;
}

//free the dynamically created linkedlist
void freelkdlst(linkedlist *lkdlst)
{
    if(lkdlst != NULL)
    {
        int key;
        while(lkdlstepty(lkdlst) != 1)
            key = remleftlkdlst(lkdlst);
        free(lkdlst);
        lkdlst = NULL;
    }
}

//add a key on the left of the linkedlist
void addleftlkdlst(linkedlist *lkdlst, int key)
{
    if(lkdlst != NULL && key != 0)
    {
        node *nd = newnd(key);
        if(nd != NULL)
        {
            if(lkdlstepty(lkdlst))
            {
                lkdlst->left = nd;
                lkdlst->right = nd;
            }
            else
            {
                nd->nxt = lkdlst->left;
                lkdlst->left->prev = nd;
                lkdlst->left = nd;
            }
        }
    }
}

//add a key on the right of the linkedlist
void addrightlkdlst(linkedlist *lkdlst, int key)
{
    if(lkdlst != NULL && key != 0)
    {
        node *nd = newnd(key);
        if(nd != NULL)
        {
            if(lkdlstepty(lkdlst))
            {
                lkdlst->left = nd;
                lkdlst->right = nd;
            }
            else
            {
                nd->prev = lkdlst->right;
                lkdlst->right->nxt = nd;
                lkdlst->right = nd;
            }
        }
    }
}

//remove a key from the left of the linkedlist
int remleftlkdlst(linkedlist *lkdlst)
{
    if(lkdlstepty(lkdlst))
        return 0;
    int key = lkdlst->left->key;
    node *nd = lkdlst->left;
    lkdlst->left = lkdlst->left->nxt;
    if(lkdlstepty(lkdlst))
        lkdlst->right = NULL;
    else
        lkdlst->left->prev = NULL;
    freend(nd);
    return key;
}

//remove a key from the right of the linkedlist
int remrightlkdlst(linkedlist *lkdlst)
{
    if(lkdlstepty(lkdlst))
        return 0;
    int key = lkdlst->right->key;
    node *nd = lkdlst->right;
    lkdlst->right = lkdlst->right->prev;
    if(lkdlstepty(lkdlst))
        lkdlst->left = NULL;
    else
        lkdlst->right->nxt = NULL;
    freend(nd);
    return key;
}

//remove a key passed as parameter from the linkedlist
int remlkdlst(linkedlist *lkdlst, int key)
{
    if(lkdlstepty(lkdlst) == 1 || key == 0)
        return 0;
    node *nd = lkdlst->left;
    while(nd != NULL && nd->key != key)
        nd = nd->nxt;
    if(nd != NULL)
    {
        int key = nd->key;
        if(nd->prev == NULL && nd->nxt == NULL)
        {
            lkdlst->left = NULL;
            lkdlst->right = NULL;
        }
        else
        {
            if(nd->prev != NULL)
                nd->prev->nxt = nd->nxt;
            else
            {
                nd->nxt->prev = NULL;
                lkdlst->left = nd->nxt;
            }
            if(nd->nxt != NULL)
                nd->nxt->prev = nd->prev;
            else
            {
                nd->prev->nxt = NULL;
                lkdlst->right = nd->prev;
            }
        }
        freend(nd);
        return key;
    }
    return 0;
}

//search if a key is on the linkedlist
int searchlkdlst(linkedlist *lkdlst, int key)
{
    if(lkdlstepty(lkdlst) == 1 || key == 0)
        return 0;
    node *nd = lkdlst->left;
    while(nd != NULL && nd->key != key)
        nd = nd->nxt;
    if(nd != NULL)
        return 1;
    return 0;
}

//checks if the linkedlist is empty
int lkdlstepty(linkedlist *lkdlst)
{
    if(lkdlst == NULL || lkdlst->left == NULL || lkdlst->right == NULL)
        return 1;
    return 0;
}
