typedef struct bstree bstree;

bstree *newbstree();

void freebstree(bstree *bs);

int treemin(bstree *bs);

int treemax(bstree *bs);

int *iotwalk(bstree *bs);

int bssearch(bstree *bs, int key);

int sucessor(bstree *bs, int key);

int predecessor(bstree *bs, int key);

void bsinsert(bstree *bs, int key);

int bsdelete(bstree *bs, int key);