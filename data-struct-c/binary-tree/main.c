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
struct node* insert_node(struct node* root, int data) {
    if(root == NULL) {
        root = new_node(data);
        return;
    }

    // https://data-flair.training/blogs/binary-tree-in-c/#:~:text=Binary%20Tree%20in%20C%20is,in%20the%20C%20programming%20language.
    if(data < root->data) {
        root->left = insert_node(root->left, data);
    }
    else if(data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

// find
int find(struct node* node, int data, int* ptr_found) {
    if(node) {
        if(node->data == data) {
            *ptr_found = 0;
            return ptr_found;
        }
        find(node->left, data, ptr_found);
        find(node->right, data, ptr_found);
    }
    return ptr_found;
}

// search node
int search(struct node* root, int data) {
    int found = 1;
    int* ptr_found = &found;
    if(root == NULL) {
        return found;
    }
    find(root, data, ptr_found);
    return *ptr_found;
}

// count nodes
int count_nodes(struct node* node, int* ptr_count) {
    if(node) {
        *ptr_count += 1;
        count_nodes(node->left, ptr_count);
        count_nodes(node->right, ptr_count);
    }
    return *ptr_count;
}

// size from node
int size_from(struct node* node) {
    int count = 0;
    int* ptr_count = &count;
    if(node == NULL) {
        return 0;
    }
    count_nodes(node, ptr_count);
    return *ptr_count;
}

// max node
// get tree height
// check balance

int main() {
    struct node* root = new_node(5);
    insert_node(root, 4);
    insert_node(root, 3);
    insert_node(root, 6);
    /*printf("left: %i, right: %i\n", root->left->data, root->right->data);
    printf("left-left: %i", root->left->left->data);*/
    int test = search(root, 6);
    /*printf("%i", test);*/
    int count = size_from(root);
    printf("%i", count);
    return 0;
}
