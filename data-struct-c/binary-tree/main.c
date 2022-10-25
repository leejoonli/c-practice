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

struct node* new_tree(int data) {
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
    struct node* node = new_node(data);
    if(tree->root == NULL) {
        tree->root = node;
    }
    struct node* walker = tree->root;

}

// search node
// size from node
// max node
// get tree height
// check balance

int main()
{
    struct node* tree = new_tree(5);
    insert_node(tree, 4);
    insert_node(tree, 6);
    return 0;
}
