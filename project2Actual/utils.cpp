#include "heap.h"
#include <iostream>
#include <limits.h>
void processResult(int dist[], int n, int dest) {
	if (dist[dest] == INT_MAX) {
		printf("Sorry, node %d is not reachable from node %d\n", dest, n);
	}
	else
	{
		printf("LENGTH: %d\n", dist[dest]);
	}
}
bool isInHeap(struct minHeap* minHeap, int v) {
	if (minHeap->position[v] < minHeap->size) {
		return true;
	}
	return false;
}