#pragma once
#include "utils.h"
#include "heap.h"
#include "graph.h"
#include "utils.h"

void dijsktra(struct Graph* graph, int src, int dest, int flag)
{
	int max = graph->v + 1;
	int* distance = new int[max];
	int* path = new int[max];
	struct minHeap* minHeap = createMinHeap(max);
	for (int j = 0; j <= max; j++) {
		path[j] = -1;
		distance[j] = INT_MAX;	
		minHeap->array[j] = newNode(j, distance[j]);
		minHeap->position[j] = j;
	}
	minHeap->array[src] = newNode(src, distance[src]);
	minHeap->position[src] = src;
	distance[src] = 0;
	path[0] = src;
	bool srcIsDest = false;
	if (src == dest)
	{
		srcIsDest= true;
	}
	decreaseKey(minHeap, src, distance[src]);
	minHeap->size = max;
	bool pathFinished = false;
	while (!(minHeap->size == 0)) {
		struct minNode* minHeapNode = extractMin(minHeap);
		int u = minHeapNode->vertex;
		struct AdjNode* relaxCheck = graph->array[u].head;
		while (relaxCheck != NULL) {
			int searchPos = relaxCheck->destination;
			if (minHeap->position[searchPos] < minHeap->size && distance[u] != INT_MAX && relaxCheck->weight + distance[u] < distance[searchPos])
			{
				distance[searchPos] = distance[u] + relaxCheck->weight;
				if (searchPos == dest && srcIsDest == false) {
					pathFinished = true;
					path[u] = searchPos;
				}
				else if (pathFinished == false && srcIsDest == false)
				{
					path[u] = searchPos;
				}
				decreaseKey(minHeap, searchPos, distance[searchPos]);
			}
				relaxCheck = relaxCheck->next;
		}
	}
	if (distance[dest] == INT_MAX)
	{
		printf("Sorry, node %d is not reachable from node %d\n", dest, src);
		return;
	}
	if (flag == 1)
	{
		cout << "PATH: ";
		cout << path[0];
		for (int i = 1; i < sizeof(path); i++) {
			if (path[i] != -1)
			{	
				cout << ", ";
				cout << path[i];
			}
		}	
		cout << endl;
		return;
	}
	processResult(distance, src, dest);
}