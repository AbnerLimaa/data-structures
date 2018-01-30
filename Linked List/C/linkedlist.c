#include <stdlib.h>
#include "linkedlist.h"

typedef struct node node;

struct node
{
    int key;
    node *nxt;
    node *prev;
};

struct linkedlist
{
    node *left;
    node *right;
};

int lkdlstepty(linkedlist *lkdlst);

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

void freend(node *nd)
{
    if(nd != NULL)
        free(nd);
}

linkedlist *newlkdlst()
{
    linkedlist *lkdlst = (linkedlist*)malloc(sizeof(linkedlist));
    if(lkdlst == NULL)
        return NULL;
    lkdlst->left = NULL;
    lkdlst->right = NULL;
    return lkdlst;
}

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

int lkdlstepty(linkedlist *lkdlst)
{
    if(lkdlst == NULL || lkdlst->left == NULL || lkdlst->right == NULL)
        return 1;
    return 0;
}