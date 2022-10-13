#include <stdio.h>
#include <stdlib.h>

// data object
struct node {
    int key;
    int data;
    struct node *next;
};

// global variable for convenience
struct node *head = NULL;

// print current list
void print_list() {
   struct node *walker = head;
   printf("\n[ ");

   // may have to change this later
   while(walker != NULL) {
      printf("(%d,%d) ",walker->key,walker->data);
      walker = walker->next;
   }

   printf(" ]");
}

// insert node at beginning of list
void insert_first(int key, int data) {
    // create new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    // set node data
    new_node->key = key;
    new_node->data = data;

    // add node to beginning of list and move head to next
    new_node->next = head;
    head = new_node;
}

// insert node at end of list
void insert_last(int key, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    new_node->key = key;
    new_node->data = data;

    if(head == NULL) {
        head = new_node;
        return;
    }

    // fix this infinite loop
    struct node *walker = head;
    while(walker != NULL) {
        printf("hello world");
        walker = walker->next;
    }
    return;
}

int main() {
    insert_last(1, 10);
    insert_last(2, 20);
    return 0;
}
