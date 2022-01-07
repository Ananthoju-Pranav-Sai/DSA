typedef struct 
{
    int front;
    int back;
    unsigned int size;
    int *array;
} queue;

queue* create_queue(unsigned int size);
int empty_queue(queue *q);
int queue_full(queue *q);
int queue_front(queue *q);
int queue_back(queue *q);
void enqueue(queue *s,int element);
void dequeue(queue *s);
void print_queue(queue *s);
