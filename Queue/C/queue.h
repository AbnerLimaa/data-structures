typedef struct queue queue;

queue *newque();

void freeque(queue *que);

void enqueue(queue *que, int key);

int dequeue(queue *que);