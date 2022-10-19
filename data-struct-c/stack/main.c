#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack {
    int top;
    unsigned capacity;
    int* array;
};

struct stack* stack_init(unsigned capacity) {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int main() {
    struct stack* stack = stack_init(10);
    printf("%p", stack);
    return 0;
}
