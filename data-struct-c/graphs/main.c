#include <stdio.h>
#include <stdlib.h>

// struct for adjacency list node
struct adj_list_node {
    int dest;
    struct adj_list_node* next;
};

// struct for adjacency list
struct adj_list {
    struct adj_list_node* head;
};

// struct for graph
struct graph {
    int i;
    struct adj_list* array;
};

// function to create graph with i vertices
struct graph* create_graph(int i) {
    // create new graph pointer variable
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    // set the amount of vertices for the newly created graph
    graph->i = i;
    // set array variable to an array of adjacency lists
    graph->array = (struct adj_list*)malloc(i * sizeof(struct adj_list));

    // initialize each adjacency list as NULL
    for(int k = 0; k < i; k++) {
        graph->array[k].head = NULL;
    }
    return graph;
}

// function to create new adjacency list node

// function to add edge to graph

int main() {
    int i = 5;
    struct graph* graph = create_graph(i);
    printf("%p", graph);
    return 0;
}
