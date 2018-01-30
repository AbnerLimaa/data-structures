typedef struct rbtree rbtree;

rbtree *newrbtree();

void freerbtree(rbtree *rb);

int treemin(rbtree *rb);

int treemax(rbtree *rb);

int *iotwalk(rbtree *rb);

int rbsearch(rbtree *rb, int key);

int sucessor(rbtree *rb, int key);

int predecessor(rbtree *rb, int key);

void rbinsert(rbtree *rb, int key);

int rbdelete(rbtree *rb, int key);