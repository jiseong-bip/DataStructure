//
//  main.c
//  CircularQueue
//
//  Created by 전지성 on 2023/03/19.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error (char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_Queue(QueueType *q)
{
    q->rear = q->front = 0;
}

int is_full(QueueType *q)
{
    return ((q->rear +1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

void queue_print(QueueType *q)
{
    printf("QUEUE (front =%d rear = %d) = ", q->front, q->rear);
    if(!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1)%(MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if(i == q->rear) break;
        } while(i != q->front);
    }
    printf("\n");
}


void enqueue(QueueType *q, element item)
{
    if (is_full(q)) {
        error("큐가 포화상태입니다");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[(q->rear)] = item;
}

element dequeue(QueueType *q)
{
    if(is_empty(q))
    {
        error("큐가 공백상태입니다");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q)
{
    if(is_empty(q)) error("큐가 공백상태입니다");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(int argc, const char * argv[]) {
    
    QueueType q;
    int element;
    
    init_Queue(&q);
    while (!is_full(&q)) {
        printf("정수를 입력하세요: ");
        scanf("%d", &element);
        enqueue(&q, element);
        queue_print(&q);
    }
    
    while(!is_empty(&q))
    {
        element = dequeue(&q);
        printf("꺼내진 정수 : %d", element);
        queue_print(&q);
    }
    return 0;
}
