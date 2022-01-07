#include "queue.c"

int main()
{
    queue* s = create_queue(10);
    printf("%d\n",empty_queue(s));
    enqueue(s,10);
    enqueue(s,20);
    enqueue(s,30);
    enqueue(s,40);
    enqueue(s,50);
    print_queue(s);
    dequeue(s);
    print_queue(s);
    int f = queue_front(s);
    int b = queue_back(s);
    printf("%d\n",f);
    printf("%d\n",b);
}