#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
queue* create_queue(unsigned int size)
{
    queue* q = (queue *)malloc(sizeof(queue));
    q->size = size;
    q->front=-1;
    q->back=-1;
    q->array=(int*)malloc(size*sizeof(int));
    return q;
}
int queue_full(queue* q)
{
    return(q->back==q->size-1);
}
int empty_queue(queue* q)
{
    return(q->front==-1);
}
int queue_front(queue* q)
{
    if(!empty_queue(q))
        return(q->array[q->front]);
}
int queue_back(queue* q)
{
    if(!empty_queue(q))
        return(q->array[q->back]);
}
void enqueue(queue* q,int element)
{
    if(q->back==q->size-1)
    {
        return;
    }
    else
    {
        q->front=0;
        q->back++;
        q->array[q->back]=element;
    }
}
void dequeue(queue* q)
{
    if(!empty_queue(q))
    {
        q->front++;
    }
}
void print_queue(queue* q)
{
    for(int i=q->front;i<=q->back;i++)
    {
        printf("%d ",q->array[i]);
    }
    printf("\n");
}