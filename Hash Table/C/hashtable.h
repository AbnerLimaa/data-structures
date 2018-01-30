typedef struct hashtable hashtable;

hashtable *newhshtbl(int size);

void freehshtbl(hashtable *hshtbl);

void addhshtbl(hashtable *hshtbl, int key);

int remhshtbl(hashtable *hshtbl, int key);

int searchhshtbl(hashtable *hshtbl, int key);
