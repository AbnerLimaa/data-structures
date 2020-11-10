typedef struct stack stack;

stack *newstk();

void freestk(stack *stk);

int stkepty(stack *stk);

void push(stack *stk, double key);

double pop(stack *stk);

double top(stack *stk);
