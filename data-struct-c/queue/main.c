#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// create queue
struct queue* queue_init(unsigned capacity) {
    struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = queue->size;

    queue->rear = capacity -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// enqueue
void enqueue(struct queue* queue, int data) {
    // check if queue is full
    if(queue->size == queue->capacity) {
        return;
    }
    // formula to sequentially add data
    queue->rear = (queue->rear + 1) % queue->capacity;
    // set data
    queue->array[queue->rear] = data;
    // increase size of queue
    queue->size = queue->size + 1;
    return;
}

// dequeue
int dequeue(struct queue* queue) {
    if(queue->size == 0) {
        return;
    }
    int data = queue->array[queue->front];
    queue->front = (queue->front + 1)% queue->capacity;
    queue->size = queue->size -1;
    return data;
}
// get front
// get rear
// get size

int main()
{
    struct queue* queue = queue_init(2);
    enqueue(queue, 1);
    enqueue(queue, 2);
    int temp = dequeue(queue);
    printf("1: %i, 2: %i, 3: %i", queue->array[0], queue->array[1], temp);
    return 0;
}
