#include <stdlib.h>
#include <stdio.h>
#include "bstree.h"

typedef struct node node;

struct node
{
    int key;
    node *dad;
    node *left;
    node *right;
};

struct bstree
{
    node *root;
    int size;
};

node *newnd()
{
    node *nd = (node*)malloc(sizeof(node));
    if(nd == NULL)
        return NULL;
    nd->dad = NULL;
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

void freend(node *nd)
{
    if(nd != NULL)
        free(nd);
}

bstree *newbstree()
{
    bstree *bs = (bstree*)malloc(sizeof(bstree));
    if(bs == NULL)
        return NULL;
    bs->root = NULL;
    bs->size = 0;
    return bs;
}

void freebstree(bstree *bs)
{
    if(bs != NULL)
    {
        while(bs->root != NULL)
            bsdelete(bs, bs->root->key);
        free(bs);
        bs = NULL;
    }
}

int treemin(bstree *bs)
{
    if(bs == NULL || bs->root == NULL)
        return 0;
    node *nd = bs->root;
    while(nd->left != NULL)
        nd = nd->left;
    return nd->key;
}

int treemax(bstree *bs)
{
    if(bs == NULL || bs->root == NULL)
        return 0;
    node *nd = bs->root;
    while(nd->right != NULL)
        nd = nd->right;
    return nd->key;
}

int *iotwalk(bstree *bs)
{
    if(bs == NULL || bs->root == NULL)
        return NULL;
    int *array = (int*)malloc(bs->size*sizeof(int));
    if(array == NULL)
        return NULL;
    int min = treemin(bs);
    int i = 0;
    while(i < bs->size)
    {
        array[i] = min;
        min = sucessor(bs, min);
        i++;
    }
    return array;
}

int bssearch(bstree *bs, int key)
{
    if(bs == NULL || bs->root == NULL || key == 0)
        return 0;
    node *nd = bs->root;
    while(nd != NULL && key != nd->key)
        if(key < nd->key)
            nd = nd->left;
        else
            nd = nd->right;
    if(nd != NULL)
        return 1;
    return 0;
}

int sucessor(bstree *bs, int key)
{
    if(bs == NULL || bs->root == NULL || key == 0)
        return 0;
    node *nd = bs->root;
    while(nd != NULL && key != nd->key)
        if(key < nd->key)  
            nd = nd->left;
        else
            nd = nd->right;
    if(nd != NULL)
    {
        if(nd->right != NULL)
        { 
            nd = nd->right;
            while(nd->left != NULL)
                nd = nd->left;
            return nd->key;
        }
        node *aux = nd->dad;
        while(aux != NULL && nd == aux->right)
        {
            nd = aux;
            aux = aux->dad;
        }
        if(aux != NULL)
            return aux->key;
    }
    return 0;
}

int predecessor(bstree *bs, int key)
{
    if(bs == NULL || bs->root == NULL || key == 0)
        return 0;
    node *nd = bs->root;
    while(nd != NULL && key != nd->key)
        if(key < nd->key)
            nd = nd->left;
        else
            nd = nd->right;
    if(nd != NULL)
    {
        if(nd->left != NULL)
        {
            nd = nd->left;
            while(nd->right != NULL)
                nd = nd->right;
            return nd->key;
        }
        node *aux = nd->dad;
        while(aux != NULL && nd == aux->left)
        {
            nd = aux;
            aux = aux->dad;
        }
        if(aux != NULL)
            return aux->key;
    }
    return 0;
}

void bsinsert(bstree *bs, int key)
{
    if(bs != NULL && key != 0 && bssearch(bs, key) == 0)
    {
        node *nd = newnd();
        nd->key = key;
        node *aux = NULL;
        node *ins = bs->root;
        while(ins != NULL)
        {
            aux = ins;
            if(key < ins->key)
                ins = ins->left;
            else
                ins = ins->right;
        }
        nd->dad = aux;
        if(aux == NULL)
            bs->root = nd;
        else if(key < aux->key)
            aux->left = nd;
        else
            aux->right = nd;
        bs->size++;
    }
}

void transplant(bstree *bs, node *u, node *v)
{
    if(bs != NULL && u != NULL)
    {   
        if(u->dad == NULL)
            bs->root = v;
        else if(u == u->dad->left)
            u->dad->left = v;
        else
            u->dad->right = v;
        if(v != NULL)
            v->dad = u->dad;
    }
}

int bsdelete(bstree *bs, int key)
{
    if(bs == NULL || bs->root == NULL || key == 0)
        return 0;
    node *nd = bs->root;
    while(nd != NULL && key != nd->key)
        if(key < nd->key)
            nd = nd->left;
        else
            nd = nd->right;
    if(nd != NULL)
    {
        int k;
        if(nd->left == NULL)
        {
            k = nd->key;
            transplant(bs, nd, nd->right);
        }
        else if(nd->right == NULL)
        {
            k = nd->key;
            transplant(bs, nd, nd->left);
        }
        else
        {
            k = nd->key;
            node *aux = nd->right;
            while(aux->left != NULL)
                aux = aux->left;
            if(aux->dad != nd)
            {
                transplant(bs, aux, aux->right);
                aux->right = nd->right;
                aux->right->dad = aux;
            }
            transplant(bs, nd, aux);
            aux->left = nd->left;
            aux->left->dad = aux;
        }
        freend(nd);
        bs->size--;
        return k;
    }
    return 0;
}