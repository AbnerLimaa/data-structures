#include <stdlib.h>
#include <stdio.h>
#include "rbtree.h"

#define RED 1
#define BLACK 0

typedef struct node node;

struct node
{
    int key;
    int color;
    node *dad;
    node *left;
    node *right;
};

struct rbtree
{
    node *root;
    node *nil;
    int size;
};

node *newnd()
{
    node *nd = (node*)malloc(sizeof(node));
    if(nd == NULL)
        return NULL;
    nd->color = BLACK;
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

rbtree *newrbtree()
{
    rbtree *rb = (rbtree*)malloc(sizeof(rbtree));
    if(rb == NULL)
        return NULL;
    rb->nil = newnd();
    rb->root = rb->nil;
    rb->size = 0;
    return rb;
}

void freerbtree(rbtree *rb)
{
    if(rb != NULL)
    {
        while(rb->root != rb->nil)
            rbdelete(rb, rb->root->key);
        freend(rb->nil);
        free(rb);
        rb = NULL;
    }
}

int treemin(rbtree *rb)
{
    if(rb == NULL || rb->root == rb->nil)
        return 0;
    node *nd = rb->root;
    while(nd->left != rb->nil)
        nd = nd->left;
    return nd->key;
}

int treemax(rbtree *rb)
{
    if(rb == NULL || rb->root == rb->nil)
        return 0;
    node *nd = rb->root;
    while(nd->right != rb->nil)
        nd = nd->right;
    return nd->key;
}

int *iotwalk(rbtree *rb)
{
    if(rb == NULL || rb->root == rb->nil)
        return NULL;
    int *array = (int*)malloc(rb->size*sizeof(int));
    if(array == NULL)
        return NULL;
    int min = treemin(rb);
    int i = 0;
    while(i < rb->size)
    {
        array[i] = min;
        min = sucessor(rb, min);
        i++;
    }
    return array;
}

int rbsearch(rbtree *rb, int key)
{
    if(rb == NULL || rb->root == rb->nil || key == 0)
        return 0;
    node *nd = rb->root;
    while(nd != rb->nil && key != nd->key)
        if(key < nd->key)
            nd = nd->left;
        else
            nd = nd->right;
    if(nd != rb->nil)
        return 1;
    return 0;
}

int sucessor(rbtree *rb, int key)
{
    if(rb == NULL || rb->root == rb->nil || key == 0)
        return 0;
    node *nd = rb->root;
    while(nd != rb->nil && key != nd->key)
        if(key < nd->key)
            nd = nd->left;
        else
            nd = nd->right;
    if(nd != rb->nil)
    {
        if(nd->right != rb->nil)
        { 
            nd = nd->right;
            while(nd->left != rb->nil)
                nd = nd->left;
            return nd->key;
        }
        node *aux = nd->dad;
        while(aux != rb->nil && nd == aux->right)
        {
            nd = aux;
            aux = aux->dad;
        }
        if(aux != rb->nil)
            return aux->key;
    }
    return 0;
}

int predecessor(rbtree *rb, int key)
{
    if(rb == NULL || rb->root == rb->nil || key == 0)
        return 0;
    node *nd = rb->root;
    while(nd != rb->nil && key != nd->key)
        if(key < nd->key)
            nd = nd->left;
        else
            nd = nd->right;
    if(nd != rb->nil)
    {
        if(nd->left != rb->nil)
        {
            nd = nd->left;
            while(nd->right != rb->nil)
                nd = nd->right;
            return nd->key;
        }
        node *aux = nd->dad;
        while(aux != rb->nil && nd == aux->left)
        {
            nd = aux;
            aux = aux->dad;
        }
        if(aux != rb->nil)
            return aux->key;
    }
    return 0;
}

void leftrotate(rbtree *rb, node *nd)
{
    if(rb != NULL && nd != rb->nil)
    {
        node *aux = nd->right;
        nd->right = aux->left;
        if(aux->left != rb->nil)
            aux->left->dad = nd;
        aux->dad = nd->dad;
        if(nd->dad == rb->nil)
            rb->root = aux;
        else if(nd == nd->dad->left)
            nd->dad->left = aux;
        else
            nd->dad->right = aux;
        aux->left = nd;
        nd->dad = aux;
    }
}

void rightrotate(rbtree *rb, node *nd)
{
    if(rb != NULL && nd != rb->nil)
    {
        node *aux = nd->left;
        nd->left = aux->right;
        if(aux->right != rb->nil)
            aux->right->dad = nd;
        aux->dad = nd->dad;
        if(nd->dad == rb->nil)
            rb->root = aux;
        else if(nd == nd->dad->left)
            nd->dad->left = aux;
        else
            nd->dad->right = aux;
        aux->right = nd;
        nd->dad = aux;
    }
}

void rbinsertfixup(rbtree *rb, node *nd)
{
    if(rb != NULL && nd != rb->nil)
    {
        node *aux;
        while(nd->dad->color == RED)
        {
            if(nd->dad == nd->dad->dad->left)
            {
                aux = nd->dad->dad->right;
                if(aux->color == RED)
                {
                    nd->dad->color = BLACK;
                    aux->color = BLACK;
                    nd->dad->dad->color = RED;
                    nd = nd->dad->dad;
                }
                else 
                {
                    if(nd == nd->dad->right)
                    {
                        nd = nd->dad;
                        leftrotate(rb, nd);
                    }
                    nd->dad->color = BLACK;
                    nd->dad->dad->color = RED;
                    rightrotate(rb, nd->dad->dad);
                }
            }
            else
            {
                aux = nd->dad->dad->left;
                if(aux->color == RED)
                {
                    nd->dad->color = BLACK;
                    aux->color = BLACK;
                    nd->dad->dad->color = RED;
                    nd = nd->dad->dad;
                }
                else 
                {
                    if(nd == nd->dad->left)
                    {
                        nd = nd->dad;
                        rightrotate(rb, nd);
                    }
                    nd->dad->color = BLACK;
                    nd->dad->dad->color = RED;
                    leftrotate(rb, nd->dad->dad);
                }
            }
        }
        rb->root->color = BLACK;
    }
}

void rbinsert(rbtree *rb, int key)
{
    if(rb != NULL && key != 0 && rbsearch(rb, key) == 0)
    {
        node *nd = newnd();
        nd->key = key;
        node *aux = rb->nil;
        node *ins = rb->root;
        while(ins != rb->nil)
        {
            aux = ins;
            if(key < ins->key)
                ins = ins->left;
            else
                ins = ins->right;
        }
        nd->dad = aux;
        if(aux == rb->nil)
            rb->root = nd;
        else if(key < aux->key)
            aux->left = nd;
        else
            aux->right = nd;
        nd->left = rb->nil;
        nd->right = rb->nil;
        nd->color = RED;
        rb->size++;
        rbinsertfixup(rb, nd);
    }
}

void transplant(rbtree *rb, node *u, node *v)
{
    if(rb != NULL && u != rb->nil)
    {   
        if(u->dad == rb->nil)
            rb->root = v;
        else if(u == u->dad->left)
            u->dad->left = v;
        else
            u->dad->right = v;
        v->dad = u->dad;
    }
}

void rbdeletefixup(rbtree *rb, node *nd)
{
    if(rb != NULL && nd != rb->nil)
    {
        node *aux;
        while(nd != rb->root && nd->color == BLACK)
        {
            if(nd == nd->dad->left)
            {
                aux = nd->dad->right;
                if(aux->color == RED)
                {
                    aux->color = BLACK;
                    nd->dad->color = RED;
                    leftrotate(rb, nd->dad);
                    aux = nd->dad->right;
                }
                if(aux->left->color == RED && aux->right->color == BLACK)
                {
                    aux->color = RED;
                    nd = nd->dad;
                }
                else
                {
                    if(aux->right->color == BLACK)
                    {
                        aux->left->color = BLACK;
                        aux->color = RED;
                        rightrotate(rb, aux);
                        aux = nd->dad->right;
                    }
                    aux->color = nd->dad->color;
                    nd->dad->color = BLACK;
                    aux->right->color = BLACK;
                    leftrotate(rb, nd->dad);
                    nd = rb->root;
                }
            }
            else
            {
                aux = nd->dad->left;
                if(aux->color == RED)
                {
                    aux->color = BLACK;
                    nd->dad->color = RED;
                    rightrotate(rb, nd->dad);
                    aux = nd->dad->left;
                }
                if(aux->right->color == RED && aux->left->color == BLACK)
                {
                    aux->color = RED;
                    nd = nd->dad;
                }
                else
                {
                    if(aux->left->color == BLACK)
                    {
                        aux->right->color = BLACK;
                        aux->color = RED;
                        leftrotate(rb, aux);
                        aux = nd->dad->left;
                    }
                    aux->color = nd->dad->color;
                    nd->dad->color = BLACK;
                    aux->left->color = BLACK;
                    rightrotate(rb, nd->dad);
                    nd = rb->root;
                }
            }
        }
    }
}

int rbdelete(rbtree *rb, int key)
{
    if(rb == NULL || rb->root == rb->nil || key == 0)
        return 0;
    node *nd = rb->root;
    while(nd != rb->nil && key != nd->key)
        if(key < nd->key)
            nd = nd->left;
        else
            nd = nd->right;
    if(nd != rb->nil)
    {
        node *start;
        node *orig = nd;
        int origcolor = nd->color;
        int k;
        if(nd->left == rb->nil)
        {
            k = nd->key;
            start = nd->right;
            transplant(rb, nd, nd->right);
        }
        else if(nd->right == rb->nil)
        {
            k = nd->key;
            start = nd->left;
            transplant(rb, nd, nd->left);
        }
        else
        {
            k = nd->key;
            orig = nd->right;
            while(orig->left != rb->nil)
                orig = orig->left;
            origcolor = orig->color;
            start = orig->right;
            if(orig->dad == nd)
                start->dad = orig;
            else
            {
                transplant(rb, orig, orig->right);
                orig->right = nd->right;
                orig->right->dad = orig;
            }
            transplant(rb, nd, orig);
            orig->left = nd->left;
            orig->left->dad = orig;
            orig->color = nd->color;
        }
        freend(nd);
        rb->size--;
        if(origcolor == BLACK)
            rbdeletefixup(rb, start);
        return k;
    }
    return 0;
}