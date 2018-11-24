#pragma once

struct AdjNode {
public:
	int destination;
	int weight;
	struct AdjNode* next;
};

struct AdjList {
public:
	struct AdjNode *head;
};

struct Graph {
	int v;
	struct AdjList* array;
};

struct AdjNode* newAdjNodeList(int dest, int weight);
struct Graph* createGraph(int verticies);
void addEdge(struct Graph* graph, int src, int dest, int weight);
