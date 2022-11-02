#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct item {
    int key;
    int data;
};

int hash(int key) {
    return key % SIZE;
}

void insert(struct item* hash_table[], int key, int data) {
    struct item* item = (struct item*)malloc(sizeof(struct item));
    item->key = key;
    item->data = data;

    int hash_index = hash(key);

    hash_table[hash_index] = item;
    printf("%i, %i\n", hash_table[hash_index]->key, hash_table[hash_index]->data);
    return;
}

int main()
{
    struct item* hash_table[SIZE];
    struct item* dummy_item = (struct item*)malloc(sizeof(struct item));
    dummy_item->key = NULL;
    dummy_item->data = NULL;
    insert(hash_table, 1, 20);
    printf("%i, %i", hash_table[1]->key, hash_table[1]->data);
    return 0;
}
