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
int get_front(struct queue* queue) {
    if(queue->size == 0) {
        return 1;
    }
    return queue->array[queue->front];
}

// get rear
int get_rear(struct queue* queue) {
    if(queue->size == 0) {
        return 1;
    }
    return queue->array[queue->rear];
}

// get size
int get_size(struct queue* queue) {
    return queue->size;
}

int main()
{
    struct queue* queue = queue_init(2);
    enqueue(queue, 1);
    enqueue(queue, 2);
    printf("front: %i, rear: %i, size: %i", get_front(queue), get_rear(queue), get_size(queue));
    return 0;
}
