typedef struct stack stack;

stack *newstk();

void freestk(stack *stk);

void push(stack *stk, int key);

int pop(stack *stk);