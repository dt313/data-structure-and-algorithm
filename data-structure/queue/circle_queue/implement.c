#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct queue_type {
    int front, rear;
    element data[MAX_QUEUE_SIZE];
} queue_type;

int is_empty(queue_type *q) {
    return q->front == q->rear;
}

int is_full(queue_type *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int size(queue_type *q)
{
    return ((q->rear % MAX_QUEUE_SIZE) - ((q->front) % MAX_QUEUE_SIZE));
}

void enqueue(queue_type *q, element item)
{
    if(is_full(q)) {
        printf("queue is full\n");
    }else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

element dequeue(queue_type *q)
{
    if (is_empty(q))
    {
        printf("queue is empty\n");
        exit(0);
    }
    else
    {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;

        return q->data[q->front];
    }
}

void print_queue(queue_type *q)
{
    printf("F -- ");
    
    if(!is_empty(q)) {
        int i = q->front;
        do {
            i = (i+1) % MAX_QUEUE_SIZE;
            printf("%d ", q->data[i]);
            if (i == q->rear)
                break;

        } while (i != q->front);
    }
    printf(" -- R\n\n");
}

queue_type init()
{
    queue_type temp;
    temp.front = temp.rear = 0;
    return temp;
}

int main() {
    queue_type queue = init();
    printf("after enqueue 1,2,3\n");
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    print_queue(&queue);

    printf("after enqueue 4,5\n");
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    print_queue(&queue);

    printf("SIZE %d\n", size(&queue));

    printf("after dequeue\n");
    dequeue(&queue);
    print_queue(&queue);
    printf("after dequeue\n");
    dequeue(&queue);
    print_queue(&queue);

    printf("after enqueue 5, 6\n");
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    print_queue(&queue);

    printf("FRONT %d , REAR : %d\n", queue.front, queue.rear);
}