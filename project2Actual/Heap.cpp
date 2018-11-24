#include <iostream>
#include "heap.h"
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

using namespace std;
struct minNode*	newNode(int v, int dist) {
	struct minNode* minNode = (struct minNode*)malloc(sizeof(struct minNode));
	minNode->vertex = v;
	minNode->distance = dist;
	return minNode;
}
struct minHeap* createMinHeap(int capacity) {
	struct minHeap* minHeap = (struct minHeap*)malloc(sizeof(struct minHeap));
	minHeap->position = (int*)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct minNode**) malloc(capacity * sizeof(struct minNode*));
	return minHeap;
}
void swap(struct minNode** a, struct minNode** b) {
	struct minNode* m = *a;
	*a = *b;
	*b = m;
}
void minHeapify(struct minHeap* minHeap, int idx) {
	int smallest = idx;
	int l = LEFT(idx);
	int r = RIGHT(idx);
	if (l < minHeap->size && minHeap->array[l]->distance < minHeap->array[smallest]->distance) {
		smallest = l;
	}
	if (r < minHeap->size && minHeap->array[r]->distance < minHeap->array[smallest]->distance)
	{
		smallest = r;
	}
	if (smallest != idx)
	{
		minNode *smallestNode = minHeap->array[smallest];
		minNode *idxNode = minHeap->array[idx];
		minHeap->position[smallestNode->vertex] = idx;
		minHeap->position[idxNode->vertex] = smallest;
		swap(&minHeap->array[smallest], &minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}
struct minNode* extractMin(struct minHeap* minHeap) {
	if (minHeap->size == 0)
	{
		return NULL;
	}
	struct minNode* root = minHeap->array[0];
	struct minNode* lastNode = minHeap->array[minHeap->size-1];
	minHeap->array[0] = lastNode;
	minHeap->position[root->vertex] = minHeap->size - 1;
	minHeap->position[lastNode->vertex] = 0;
	minHeap->size--;
	minHeapify(minHeap, 0);
	return root;
}
void decreaseKey(struct minHeap* minHeap, int v, int dist) {
	int i = minHeap->position[v];
	minHeap->array[i]->distance = dist;
	while (minHeap->array[i]->distance < minHeap->array[PARENT(i)]->distance) {
		minHeap->position[minHeap->array[i]->vertex] = PARENT(i);
		minHeap->position[minHeap->array[PARENT(i)]->vertex] = i;
		swap(&minHeap->array[i], &minHeap->array[PARENT(i)]);
		i = PARENT(i);
	}
}








