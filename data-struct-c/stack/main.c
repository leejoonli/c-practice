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
int pop(struct stack* stack) {
    int i;
    if(stack->top == -1) {
        printf("Stack is empty");
        return;
    }

    i = stack->array[stack->top];
    stack->array[stack->top] == NULL;
    stack->top--;
    return i;
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
    int i = pop(stack);
    return 0;
}
