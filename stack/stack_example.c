#include "stack.c"

int main()
{
    stack* s = create_stack(10);
    printf("%d\n",empty_stack(s));
    push_element(s,10);
    push_element(s,20);
    push_element(s,30);
    push_element(s,40);
    push_element(s,50);
    print_stack(s);
    pop_element(s);
    print_stack(s);
    int t = stack_top(s);
    printf("%d\n",t);
}