#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct tree {
    struct node* root;
};

// new node
struct node* new_node(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* new_tree() {
    struct tree* tree = (struct tree*)malloc(sizeof(struct tree));
    tree->root = NULL;
    return tree;
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
void insert_node(struct tree* tree, int data) {
    if(tree->root == NULL) {
        tree->root = new_node(data);
        return;
    }
    struct node* walker = tree->root;
    printf("%i\n", walker->data);
    printf("%p\n", walker);

    if(data < walker->data) {
        walker = walker->left;
        printf("%p\n", walker);
    }
    else if(data > walker->data) {
        walker = walker->right;
    }

    walker = new_node(data);
    printf("%p\n", walker);
    printf("%i\n", walker->data);
    return;
}

// search node
// size from node
// max node
// get tree height
// check balance

int main() {
    struct tree* tree = new_tree();
    insert_node(tree, 5);
    insert_node(tree, 4);
    printf("top: %p", tree->root->left);
    return 0;
}
