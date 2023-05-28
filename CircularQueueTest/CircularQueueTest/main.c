#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front, rear;
    int size;
    int* arr;
} Queue;

void init(Queue* q, int size) {
    q->front = 0;
    q->rear = 0;
    q->size = size;
    q->arr = (int*)malloc(sizeof(int) * size);
}

int is_empty(Queue* q) {
    return q->front == q->rear;
}

int is_full(Queue* q) {
    return (q->rear + 1) % q->size == q->front;
}


void enqueue(Queue* q, int data) {
    if (is_full(q)) {
        int* tmp = (int*)malloc(sizeof(int) * q->size * 2);
        int j = 0;
        for (int i = q->front; i < q->size; i++) {
            tmp[j] = q->arr[i];
            j++;
        }
        for (int i = 0; i < q->front; i++) {
            tmp[j] = q->arr[i];
            j++;
        }
        free(q->arr);
        q->arr = tmp;
        //free(tmp);
        q->front = 0;
        q->rear = q->size - 1;
        q->size *= 2;
    }
    q->arr[q->rear] = data;
    q->rear = (q->rear + 1) % q->size;
}

int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = q->arr[q->front];
    q->front = (q->front + 1) % q->size;
    return data;
}

void print_queue(Queue* q) {
    printf("Queue: ");
    for (int i = q->front; i != q->rear; i = (i + 1) % q->size) {
        printf("%d ", q->arr[i]);
    }
    printf("| size: %d | front: %d | rear: %d",q->size,q->front,q->rear);
    printf("\n");
}

int main() {
    Queue q;
    init(&q, 5);

    for (int i = 0; i < 5; ++i) {
        enqueue(&q, i);
    }
    print_queue(&q);
    
    for (int i = 5; i < 10; ++i) {
        enqueue(&q, i);
    }
    print_queue(&q);
    for (int i = 0; i < 5; ++i) {
        dequeue(&q);
    }
    print_queue(&q);
    for (int i = 0; i < 10; ++i) {
        enqueue(&q, i);
    }
    print_queue(&q);
    for (int i = 3; i < 6; ++i) {
        enqueue(&q, i);
    }
    print_queue(&q);

    return 0;
}
