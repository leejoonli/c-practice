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

    while(hash_table[hash_index] != NULL && hash_table[hash_index]->key != -1) {
        hash_index++;
        hash_index %= SIZE;
    }

    hash_table[hash_index] = item;
    return;
}

struct item* search(struct item* hash_table[], int key) {
    int hash_index = hash(key);

    while(hash_table[hash_index] != NULL) {
        if(hash_table[hash_index]->key == key) {
            return hash_table[hash_index];
        }
        hash_index++;
        hash_index %= SIZE;
    }
    return NULL;
}

void delete(struct item* hash_table[], struct item* dummy_item, int key) {
    struct item* item = search(hash_table, key);
    int hash_index = hash(key);

    while(hash_table[hash_index] != NULL) {
        if(hash_table[hash_index]->key == item->key) {
            struct item* temp = hash_table[hash_index];
            hash_table[hash_index] = dummy_item;
            return temp;
        }
        hash_index++;
        hash_index %= SIZE;
    }
    return NULL;
}

int main()
{
    struct item* hash_table[SIZE];
    struct item* dummy_item = (struct item*)malloc(sizeof(struct item));
    dummy_item->key = NULL;
    dummy_item->data = NULL;
    insert(hash_table, 1, 20);
    delete(hash_table, dummy_item, 1);
    return 0;
}
