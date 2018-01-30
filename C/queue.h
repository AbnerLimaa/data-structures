//this .h file is to be used as it is, none of the other functions and fields that are not here should be here
typedef struct queue queue;

queue *newque();

void freeque(queue *que);

void enqueue(queue *que, int key);

int dequeue(queue *que);
