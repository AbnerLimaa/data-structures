#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

typedef struct node node;
typedef struct linkedlist linkedlist;

struct node
{
    int key;
    node *nxt;
};

struct linkedlist
{
    node *head;
};

struct hashtable
{
    linkedlist **table;
    int size;
};

int lkdlstepty(linkedlist *lkdlst);

int hshfunc(int size, int key);

node *newnd(int key)
{
    node *nd = (node*)malloc(sizeof(node));
    if(key == 0 || nd == NULL)
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

linkedlist *newlkdlst()
{
    linkedlist *lkdlst = (linkedlist*)malloc(sizeof(linkedlist));
    if(lkdlst == NULL)
        return NULL;
    lkdlst->head = NULL;
    return lkdlst;
}

void freelkdlst(linkedlist *lkdlst)
{
    if(lkdlst != NULL)
    {
        while(lkdlstepty(lkdlst) != 1)
        {
            node *nd = lkdlst->head;
            lkdlst->head = nd->nxt;
            freend(nd);
        }
        free(lkdlst);
        lkdlst = NULL;
    }
}

void addlkdlst(linkedlist *lkdlst, int key)
{
    if(lkdlst != NULL && key != 0)
    {
        node *nd = newnd(key);
        if(nd != NULL)
        {
            if(lkdlstepty(lkdlst))
                lkdlst->head = nd;
            else
            {
                nd->nxt = lkdlst->head;
                lkdlst->head = nd;
            }
        }
    }
}

int remlkdlst(linkedlist *lkdlst, int key)
{
    if(lkdlstepty(lkdlst) == 1 || key == 0)
        return 0;
    node *nd = lkdlst->head;
    node *last = NULL;
    while(nd != NULL && nd->key != key)
    {
        last = nd;
        nd = nd->nxt;
    }
    if(nd != NULL)
    {
        int k = nd->key;
        if(nd->nxt == NULL && last == NULL)
            lkdlst->head = NULL;
        else if(last != NULL)
            last->nxt = nd->nxt;
        else
            lkdlst->head = nd->nxt;
        freend(nd);
        return k;
    }
    return 0;
}

int searchlkdlst(linkedlist *lkdlst, int key)
{
    if(lkdlstepty(lkdlst) == 1 || key == 0)
        return 0;
    node *nd = lkdlst->head;
    while(nd != NULL && nd->key != key)
        nd = nd->nxt;
    if(nd != NULL)
        return 1;
    return 0;
}

int lkdlstepty(linkedlist *lkdlst)
{
    if(lkdlst == NULL || lkdlst->head == NULL)
        return 1;
    return 0;
}

hashtable *newhshtbl(int size)
{
    hashtable *hshtbl = (hashtable*)malloc(sizeof(hashtable));
    if(hshtbl == NULL || size <= 0)
        return NULL;
    hshtbl->table = (linkedlist**)malloc(size*sizeof(linkedlist*));
    if(hshtbl->table == NULL)
        return NULL;
    for(int i = 0; i < size; i++)
        hshtbl->table[i] = newlkdlst();
    hshtbl->size = size;
    return hshtbl;
}

void freehshtbl(hashtable *hshtbl)
{
    if(hshtbl != NULL && hshtbl->table != NULL)
    {
        for(int i = 0; i < hshtbl->size; i++)
            freelkdlst(hshtbl->table[i]);
        free(hshtbl->table);
        free(hshtbl);
        hshtbl = NULL;
    }
}

void addhshtbl(hashtable *hshtbl, int key)
{
    if(hshtbl != NULL && hshtbl->table != NULL && key != 0)
        addlkdlst(hshtbl->table[hshfunc(hshtbl->size, key)], key);
}

int remhshtbl(hashtable *hshtbl, int key)
{
    if(hshtbl != NULL && hshtbl->table != NULL && key != 0)
        return remlkdlst(hshtbl->table[hshfunc(hshtbl->size, key)], key);
    return 0;
}

int searchhshtbl(hashtable *hshtbl, int key)
{
    if(hshtbl != NULL && hshtbl->table != NULL && key != 0)
        if(searchlkdlst(hshtbl->table[hshfunc(hshtbl->size, key)], key))
            return 1;
    return 0;
}

int hshfunc(int size, int key)
{
    return key % size;
}