#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
}

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

// check queue full
// check queue empty
// enqueue
// dequeue
// get front
// get rear
// get size

int main()
{
    printf("Hello world!\n");
    return 0;
}
