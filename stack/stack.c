#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
stack* create_stack(unsigned int size)
{
    stack* s = (stack *)malloc(sizeof(stack));
    s->size = size;
    s->top=-1;
    s->array=(int*)malloc(size*sizeof(int));
    return s;
}
int stack_full(stack* s)
{
    return(s->top==s->size-1);
}
int empty_stack(stack* s)
{
    return(s->top==-1);
}
int stack_top(stack* s)
{
    if(!empty_stack(s))
        return(s->array[s->top]);
}
void push_element(stack* s,int element)
{
    if(s->top==s->size-1)
    {
        return;
    }
    else
    {
        s->top++;
        s->array[s->top]=element;
    }
}
void pop_element(stack* s)
{
    if(!empty_stack(s))
    {
        s->top--;
    }
}
void print_stack(stack* s)
{
    for(int i=0;i<=s->top;i++)
    {
        printf("%d ",s->array[i]);
    }
    printf("\n");
}