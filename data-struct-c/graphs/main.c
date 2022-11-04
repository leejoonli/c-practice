#include <stdio.h>
#include <stdlib.h>

struct adj_list_node {
    int dest;
    struct adj_list_node* next;
};

struct adj_list {
    struct adj_list_node* head;
};

struct graph {
    int i;
    struct adj_list* array;
};

int main()
{
    printf("Hello world!\n");
    return 0;
}
