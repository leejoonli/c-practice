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

// function to check if list is empty
int check_list() {
    if(head != NULL) {
        return 0;
    }
    else {
        return 1;
    }
}

// function to check how many items in list
int list_length() {
    int count = 0;
    struct node *walker = head;
    while(walker != NULL) {
        count++;
        walker = walker->next;
    }
    return count;
}

// insert node at beginning of list
void insert_first(int key, int data) {
    // create new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    // set node data
    new_node->key = key;
    new_node->data = data;
    new_node->next = NULL;

    // add node to head and move head to next
    new_node->next = head;
    head = new_node;
}

// insert node at end of list
void insert_last(int key, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    new_node->key = key;
    new_node->data = data;
    new_node->next = NULL;

    if(head == NULL) {
        head = new_node;
        return;
    }

    // traverse to end of list
    struct node *walker = head;
    while(walker->next != NULL) {
        walker = walker->next;
    }

    // insert new node at end of list
    walker->next = new_node;
    return;
}

struct node* delete_first() {
    // create temp node to return
    struct node* temp = head;
    // set head node to head->next
    head = head->next;
    return temp;
}

struct node* delete_at(int key) {
    struct node* walker = head;
    struct node* temp = NULL;

    if(head == NULL) {
        return NULL;
    }

    while(walker->key != key) {
        if(walker->next == NULL) {
            return NULL;
        }
        else {
            temp = walker;
            walker = walker->next;
        }
    }

    if(walker == head) {
        head = head->next;
    }
    else {
        temp->next = walker->next;
    }
    return walker;
}

struct node* find(int key) {
    struct node* walker = head;

    if(head == NULL) {
        return NULL;
    }

    while(walker->key != key) {
        if(walker->key == NULL) {
            return NULL;
        } else {
            walker = walker->next;
        }
    }

    return walker;
}

int main() {
    insert_last(1, 10);
    insert_last(2, 20);
    insert_last(3, 30);
    insert_last(4, 40);
    struct node* test = delete_at(3);
    struct node* temp = find(2);
    printf("%d", temp->key);
    print_list();
    return 0;
}
