#include<stdio.h>
#include<stdlib.h>
#define  MAX_QUEUE_SIZE 10
typedef int element;
typedef struct queue_type
{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} queue_type;

int size(queue_type *q) {
    return q->rear - (q->front);
}

int is_empty(queue_type *q) {
    return q->front == q->rear;
}

int is_full(queue_type *q) {
    return q->rear == MAX_QUEUE_SIZE;
}

void enqueue(queue_type *q, element item)
{
    if(is_full(q) == 1) {
        printf("queue is full\n");
    }else {
        q->data[++(q->rear)] = item;
    }
}

element dequeue(queue_type *q) {
    if(is_empty(q) == 1) {
        printf("queue is empty\n");
        exit(0);
    }
    else
    {
        return q->data[++(q->front)];
    }
}

element peek(queue_type *q) {
    if (is_full(q) == 1)
    {
        printf("queue is full\n");
        exit(0);
    }
    else
    {
        return q->data[(q->front) + 1];
    }
}

queue_type init_queue() {
    queue_type temp;
    temp.front = -1;
    temp.rear = -1;
    return temp;
}

void print_queue(queue_type *q) {
    printf("F -- ");
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->data[i]);
    }
    printf(" -- R\n\n");
}

int main() {
    queue_type queue = init_queue();
    printf("after enqueue 1\n");
    enqueue(&queue, 1);
    print_queue(&queue);
    printf("after enqueue 2\n");
    enqueue(&queue, 2);
    print_queue(&queue);
    printf("after enqueue 3\n");
    enqueue(&queue, 3);
    print_queue(&queue);
    printf("SIZE %d\n\n", size(&queue));
    int len = size(&queue);
    for (int i = 0; i <= len; i++)
    {
        printf("after dequeue\n");
        dequeue(&queue);
        print_queue(&queue);
    }
}