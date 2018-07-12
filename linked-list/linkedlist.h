typedef struct linkedlist linkedlist;

linkedlist *newlkdlst();

void freelkdlst(linkedlist *lkdlst);

void addleftlkdlst(linkedlist *lkdlst, int key);

void addrightlkdlst(linkedlist *lkdlst, int key);

int remleftlkdlst(linkedlist *lkdlst);

int remrightlkdlst(linkedlist *lkdlst);

int remlkdlst(linkedlist *lkdlst, int key);

int searchlkdlst(linkedlist *lkdlst, int key);