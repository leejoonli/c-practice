#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int data;
    struct node *next;
};

struct node *head = NULL;

void print_list() {
   struct node *walker = head;
   printf("\n[ ");

   while(walker != NULL) {
      printf("(%d,%d) ",walker->key,walker->data);
      walker = walker->next;
   }

   printf(" ]");
}

void insert_first(int key, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    new_node->key = key;
    new_node->data = data;

    new_node->next = head;
    head = new_node;
}

int main() {
    insert_first(2, 10);
    insert_first(1, 10);
    print_list();
    return 0;
}
