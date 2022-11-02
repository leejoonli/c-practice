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

// insert node
struct node* insert_node(struct node* root, int data) {
    if(root == NULL) {
        root = new_node(data);
        return root;
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
            return *ptr_found;
        }
        find(node->left, data, ptr_found);
        find(node->right, data, ptr_found);
    }
    return *ptr_found;
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

int find_max(struct node* node, int* ptr_max) {
    if(node) {
        if(node->data > *ptr_max) {
            *ptr_max = node->data;
        }
        find_max(node->left, ptr_max);
        find_max(node->right, ptr_max);
    }
    return *ptr_max;
}

// max node
int get_max(struct node* root)  {
    if(root == NULL) {
        return 0;
    }
    int max = root->data;
    int* ptr_max = &max;
    find_max(root, ptr_max);
    return *ptr_max;
}

// find height
int find_height(struct node* node, int* ptr_height) {
    if(node) {
        *ptr_height += 1;
        find_height(node->left, ptr_height);
        find_height(node->right, ptr_height);
    }
    return *ptr_height;
}

// get tree height
int height(struct node* root) {
    if(root == NULL) {
        return 0;
    }
    int height = 0;
    int* ptr_height = &height;
    find_height(root, ptr_height);
    return *ptr_height;
}

// track balance
int track_balance(struct node* node, int* ptr_balance) {
    int height_left = height(node->left);
    int height_right = height(node->right);
    if(abs(height_left - height_right) <= 1) {
        *ptr_balance = 0;
        return *ptr_balance;
    } else if(abs(height_left - height_right) > 1) {
        *ptr_balance = 1;
        return *ptr_balance;
    }
}

// traverse tree
int traverse_tree(struct node* node, int* ptr_balance) {
    if(node) {
        if(track_balance(node, ptr_balance) == 1) {
            *ptr_balance = 1;
            return *ptr_balance;
        }
        traverse_tree(node->left, ptr_balance);
        traverse_tree(node->right, ptr_balance);
    }
    return *ptr_balance;
}

// check balance
int check_balance(struct node* root) {
    int balance = 0;
    int* ptr_balance = &balance;
    if(root == NULL) {
        balance = 1;
        return balance;
    }
    traverse_tree(root, ptr_balance);
    return balance;
}

int main() {
    struct node* root = new_node(5);
    insert_node(root, 6);
    insert_node(root, 3);
    insert_node(root, 2);
    insert_node(root, 1);
    /*printf("left: %i, right: %i\n", root->left->data, root->right->data);
    printf("left-left: %i", root->left->left->data);
    int test = search(root, 6);
    printf("%i", test);
    int count = size_from(root);
    printf("%i", count);
    int max = get_max(root);
    printf("%i", max);
    int ht = height(root);
    printf("%i", ht);*/
    int balanced = check_balance(root);
    printf("%i", balanced);
    return 0;
}
