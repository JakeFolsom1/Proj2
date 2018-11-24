#include "graph.h"
#include <memory>
#include <iostream>
#include <stdlib.h>

AdjNode* newAdjNodeList(int dest, int weight) {
	struct AdjNode* newNode = (struct AdjNode*)malloc(sizeof(struct AdjNode));
	newNode->destination = dest;
	newNode->weight = weight;
	newNode->next = NULL; 
	return newNode;
}

struct Graph* createGraph(int V) {
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->v = V;
	graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
	for (int i = 0; i <= V; i++) {
		graph->array[i].head = NULL;
	}
	return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {

	AdjNode* newNode = newAdjNodeList(dest, weight);
	if (!graph->array[src].head) {
		graph->array[src].head = newNode;
	}
	else {
		AdjNode* append = graph->array[src].head;
		while (append->next)
			append = append->next;
		append->next = newNode;
	}
}
