#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct item {
    int data;
    int key;
};

int hash(int key) {
    return key % SIZE;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
