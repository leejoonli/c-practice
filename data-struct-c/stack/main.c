#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack {
    int top;
    unsigned capacity;
    int* array;
};

// create stack
struct stack* stack_init(unsigned capacity) {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// push
void push(struct stack* stack, int data) {
    if(stack->top == stack->capacity-1) {
        printf("Stack is full\n");
        return;
    }

    stack->top++;
    stack->array[stack->top] = data;
    return;
}

// pop
struct stack* stack(struct stack* stack) {

}

// is empty
int check_empty(struct stack* stack) {

}

// size
int check_size(struct stack* stack) {

}

int main() {
    struct stack* stack = stack_init(10);
    push(stack, 1);
    push(stack, 2);
    printf("%i, %i", stack->array[0], stack->array[1]);
    return 0;
}
