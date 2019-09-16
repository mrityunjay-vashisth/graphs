#ifndef GRAPH_H
#define GRAPH_H


typedef struct AdjListNode {
	int dst;
	struct AdjListNode* next;
}adj_list_node_t;

typedef struct AdjList {
	struct AdjListNode* head;
}adj_list_t;

typedef struct Graph {
	int V;
	struct AdjList* arr;
}graph_t;


graph_t* create_graph(int V);
adj_list_node_t* create_list_node(int dst);
void add_edge(graph_t* g, int src, int dst, int directed);
void print_graph(graph_t* g);

#endif