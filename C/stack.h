//this .h file is to be used as it is, none of the other functions and fields that are not here should be here
typedef struct stack stack;

stack *newstk();

void freestk(stack *stk);

void push(stack *stk, int key);

int pop(stack *stk);
