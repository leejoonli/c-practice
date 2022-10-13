#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;

void print_list() {
    struct node *walker = head;
    printf("\n[ ");

    while(walker != NULL) {
        printf("(%d, %d) ", walker->key, walker->data);
        walker = walker->next;
    }

    printf(" ]");
    return;
}

void insert_last(int key, int data) {
    struct node *link = (struct node*) malloc(sizeof(struct node));

    link->key = key;
    link->data = data;

    if(head == NULL) {
        head = link;
        return;
    }

    struct node *walker = *head;
    while(walker != NULL) {
        walker = walker->next;
    }
    walker = link;
    return;
}

int main() {
    insert_last(1,10);
    insert_last(2,20);
    print_list();
    return 0;
}
