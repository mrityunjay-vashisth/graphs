#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


graph_t* create_graph(int V) {
	graph_t* g = (graph_t*) malloc(sizeof(graph_t));
	g->V = V;
	g->arr = (adj_list_t *) malloc(V * sizeof(adj_list_t));

	for (int i = 0; i < V; i++)
		g->arr[i].head = NULL;
	return g;
}


adj_list_node_t* create_list_node(int dst) {
	adj_list_node_t* node = (adj_list_node_t*) malloc(sizeof(adj_list_node_t));
	node->dst = dst;
	node->next = NULL;
	return node;
}


void add_edge(graph_t* g, int src, int dst, int directed) {
	adj_list_node_t* nd = create_list_node(dst);
	nd->next = g->arr[src].head;
	g->arr[src].head = nd;

	if (!directed) {
		nd =  create_list_node(src);
		nd->next = g->arr[dst].head;
		g->arr[dst].head = nd;
	} 

}


void print_graph(graph_t* g) {
	for (int i = 0; i < g->V; i++) {
		adj_list_node_t* h = g->arr[i].head;
		printf("SRC : [%d]", i);
		
		while (h) {
			printf("->%d", h->dst);
			h = h->next;
		}
		printf("\n");
	}
}

