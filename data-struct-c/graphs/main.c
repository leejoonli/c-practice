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
struct adj_list* create_adj_list_node(int i) {
    // allocate memory for node
    struct adj_list_node* adj_list_node = (struct adj_list_node*)malloc(sizeof(adj_list_node));
    // set struct variables
    adj_list_node->dest = i;
    adj_list_node->next = NULL;
    return adj_list_node;
}

// function to add edge to UNDIRECTED graph
void add_edge(struct graph* graph, int k, int i) {
    struct adj_list_node* walker = NULL;
    struct adj_list_node* new_node = create_adj_list_node(i);

    // set head node to new list node if head node is NULL
    if(graph->array[k].head == NULL) {
        graph->array[k].head = new_node;
    } else {
        // use walker to traverse until a NULL spot is reached
        walker = graph->array[k].head;
        while(walker->next != NULL) {
            walker = walker->next;
        }
        walker->next = new_node;
    }

    new_node = create_adj_list_node(k);

    if(graph->array[i].head == NULL) {
        graph->array[i].head = new_node;
    } else {
        walker = graph->array[i].head;
        while(walker->next != NULL) {
            walker = walker->next;
        }
        walker->next = new_node;
    }
}

int main() {
    int i = 5;
    struct graph* graph = create_graph(i);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 1);
    add_edge(graph, 1, 2);
    printf("%i\n", graph->array[0].head->dest);
    printf("%i\n", graph->array[0].head->next->dest);
    printf("%i\n", graph->array[1].head->dest);
    printf("%i\n", graph->array[1].head->next->next->dest);
    printf("%i\n", graph->array[1].head->next->next->next->dest);
    return 0;
}
