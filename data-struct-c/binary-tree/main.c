#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// new node
struct node* new_node(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// add left
void insert_left(struct node* node, int data) {
    node->left = new_node(data);
    return;
}

// add right
void insert_right(struct node* node, int data) {
    node->right = new_node(data);
    return;
}

int main()
{
    struct node* test = new_node(1);
    insert_left(test, 2);
    insert_right(test, 3);
    printf("top: %i, left: %i, right: %i", test->data, test->left->data, test->right->data);
    return 0;
}
