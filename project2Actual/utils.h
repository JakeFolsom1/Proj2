#pragma once

struct Element {
public:
	int key;
};

struct Heap {
public:
	int capacity;
	int size;
	Element* H;
};
void processResult(int dist[], int n, int dest);
bool isInHeap(struct minHeap *minHeap, int v);
