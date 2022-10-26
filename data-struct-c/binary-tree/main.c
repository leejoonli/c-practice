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

// insert node
void insert_node(struct node* root, int data) {
    if(root == NULL) {
        root = new_node(data);
        return;
    }
    struct node* walker = root;
    printf("%p\n", walker);
    printf("%p\n", root);

    if(data < walker->data) {
        walker = walker->left;
        printf("%p\n", walker);
    }
    else if(data > walker->data) {
        walker = walker->right;
    }

    walker = new_node(data);
    printf("%p\n", walker);
    printf("%p\n", root->left);
    return;
}

// search node
// size from node
// max node
// get tree height
// check balance

int main() {
    struct node* root = new_node(5);
    insert_node(root, 4);
    printf("left: %p", root->left);
    return 0;
}
