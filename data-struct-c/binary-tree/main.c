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
// add right

int main()
{
    struct node* test = new_node(1);
    printf("%i", test->data);
    return 0;
}
