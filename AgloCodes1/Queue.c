#include<stdio.h>
#include<stdlib.h>
typedef struct Queue
{
    int data[10];
    int head;
    int tail;
} Queue;

void enqueue(Queue *q, int x)
{
    q->data[q->tail] = x;
    q->tail = ((q->tail+1)%10);
}

int dequeue(Queue *q)
{
    int x = q->data[q->head];
    q->head = ((q->head + 1)%10);
    return x;
}

int main()
{
    Queue* q;
    q = (Queue*)malloc(sizeof(Queue));
    q->head = 0;
    q->tail = 0;
    enqueue(q, 1);
    enqueue(q, 3);
    enqueue(q, 5);
    enqueue(q, 6);
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    enqueue(q, 23);
    enqueue(q, 12);
    enqueue(q, 54);
    enqueue(q, 16);
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    enqueue(q, 325);
    enqueue(q, 3132);
    enqueue(q, 132);
    enqueue(q, 432);
    enqueue(q, 8686);
    enqueue(q, 675);
    enqueue(q, 587);
    enqueue(q, 5643);
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    return 0;
}
