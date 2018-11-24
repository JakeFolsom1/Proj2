#pragma once
#include <math.h>
#include <limits.h>

using namespace std;
static int LEFT(int n) {
	return 2 * n + 1;
}
static int RIGHT(int n) {
	return 2 * n + 2;
}
static int PARENT(int n) {
	return (n - 1) / 2;
}
struct minNode {
public:
	int vertex;
	int distance;
};
struct minHeap {
public:
	int size;
	int capacity;
	int *position;
	struct minNode **array;
};

struct minNode* newNode(int v, int dest);
struct minHeap* createMinHeap(int capacity);
void swap(struct minNode** a, struct minNode** b);
void minHeapify(struct minHeap* minHeap, int index);
struct minNode* extractMin(struct minHeap* minHeap);
void decreaseKey(struct minHeap* minHeap, int v, int dest);
