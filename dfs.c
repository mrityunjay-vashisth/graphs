#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "graph.h"


int* dfs(graph_t* g, int start) {
	cstack_t* s = create_stack(g->V);
	int* visited = (int*) calloc(g->V, sizeof(int));
	int* result = (int*) calloc(g->V, sizeof(int));
	int idx = 0;

	push(s, start);
	visited[start] = 1;

	while(!stack_empty(s)) {
		result[idx] = pop(s);
		adj_list_node_t* tmp = g->arr[result[idx]].head;
		
		while (tmp) {
			if (!visited[tmp->dst]) {
				push(s, tmp->dst);
				visited[tmp->dst] = 1;
			}
			tmp = tmp->next;
		}
		idx++;
	}
	
	free(visited);
	free(s);

	return result;
}


int main(int argc, char const *argv[])
{
	/*
			SRC : [0]->3->2->1
			SRC : [1]->4->0
			SRC : [2]->5->4->0
			SRC : [3]->5->0
			SRC : [4]->6->2->1
			SRC : [5]->6->3->2
			SRC : [6]->5->4
	*/
	
	graph_t* g = create_graph(7); 
    add_edge(g, 0, 1, 0); 
    add_edge(g, 0, 2, 0); 
    add_edge(g, 0, 3, 0); 
    add_edge(g, 1, 4, 0); 
    add_edge(g, 2, 4, 0); 
    add_edge(g, 2, 5, 0);
    add_edge(g, 3, 5, 0); 
    add_edge(g, 4, 6, 0); 
    add_edge(g, 5, 6, 0); 
    print_graph(g);

    /*graph_t* g = create_graph(4); 
    add_edge(g, 0, 1, 0); 
    add_edge(g, 0, 2, 0); 
    add_edge(g, 1, 2, 0); 
    add_edge(g, 2, 0, 0); 
    add_edge(g, 2, 3, 0); 
    add_edge(g, 3, 3, 0);
    print_graph(g);*/

    int* dfs_traverse = dfs(g, 0);
	

	for (int i = 0; i < g->V; i++)
    	printf("%d ", dfs_traverse[i]);
    printf("\n");
    
    free(dfs_traverse);
    free(g);
	return 0;
}