typedef struct {
    unsigned int size;
    int top;
    int* array;
} stack;

stack* create_stack(unsigned int size);
int stack_full(stack* s);
int empty_stack(stack* s);
int stack_top(stack *s);
void push_element(stack* s,int element);
void pop_element(stack* s);
void print_stack(stack* s);
