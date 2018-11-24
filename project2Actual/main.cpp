#include<iostream>
#include "main.h"
#include "heap.h"
#include "graph.h"
#include "utils.h"
#include <fstream>
#include <climits>
#include <string>
#include <stdlib.h>

Graph* fileRead(Graph* graph) {
	ifstream file;
	ifstream countingLines;
	string line;
	int numEdges = 0;
	file.open("Ginput.txt");
	countingLines.open("Ginput.txt");
	if (file.is_open())
	{
		int verticies = 0;
		int edges = 0;
		int src;
		int dest; 
		int weight;
		file >> verticies;
		file >> edges;
		while (getline(countingLines, line))
		{
			numEdges++;
		}
		if (numEdges-1 < edges)
		{
			cout << "Error: The number of edges is less than as specified in the beginning of the file" << endl;
			return graph;
		}
		graph = createGraph(verticies);
		for (int j = 0; j < edges; j++) {
			file >> src;
			file >> dest;
			file >> weight;
			addEdge(graph, src, dest, weight);
			numEdges++;
		}
		return graph;
	}
	else 
	{
		cout << "There was a problem opening file Ginput.txt for reading." << endl;
		return graph;
	}
	file.close();
	countingLines.close();
}
void print(Graph* graph) {
	if (graph == NULL)
	{
		cout << "Error: There is no graph to print." << endl;
		return;
	}
	int numEdges = 0;
	int v = graph->v;
	for (int i = 1; i <= v; i++)
	{
		AdjNode* traverseGraph = graph->array[i].head;
		while (traverseGraph)
		{
			numEdges++;
			traverseGraph = traverseGraph->next;
		}
	}
	cout << graph->v << " " << numEdges << endl;
	for (int i = 1; i <= v; i++)
	{
		AdjNode* traverseGraph = graph->array[i].head;
		cout << i << " :";
		while (traverseGraph)
		{
				cout << " (" << traverseGraph->destination << ", " << traverseGraph->weight << ");";
				traverseGraph = traverseGraph->next;
		}
		cout << "\n";
	}
}

int main() {
	using namespace std;
	int n = 0;
	char c = 'x';
	int src = 0;
	int dest = 0;
	int flag = 0;
	struct Graph* graph = NULL;
	cout << "On reading 'S', the program will stop" << endl;
	cout << "On reading 'R' the program will reads in an edge weighted directed graph from file Ginput.txt, builds the adjacency list, and waits for the next command." << endl;
	cout << "On reading 'W' the program will write the graph information to the screen and waits for the next command." << endl;
	cout << "On reading 'P s t 0' the program will run Dijkstra's shortest path algorithm to compute the shortest path to the screen and waits for the next command. The information printed to the screen should be of the format LENGTH: l where l is the path length" << endl;
	cout << "On reading 'P s t 1' the program will run Dijkstra's shortest path algorithm to compute the shortest s-t path and prints out the path of this shortest path to the screen and waits for the next command. The information printed to the screen should be of the format: PATH: s,v,v1,v2 .... t where the verticies listed gives out the path computed." << endl;
	while (1) {
		cin >> c;
		c = toupper(c);
		switch (c) {
		case 'S':
			cout << "COMMAND: " << c << endl;
			exit(0);
			break;
		case 'R':
			cout << "COMMAND: " << c << endl;
			graph = fileRead(graph);
			break;
		case 'W':
			cout << "COMMAND: " << c << endl;
			print(graph);
			break;
		case 'P':
			if (graph != NULL)
			{
				cin >> src;
				cin >> dest;
				cin >> flag;
				cout << "COMMAND " << c << " " << src << " " << dest << " " << flag << endl;
				int numEdges = 0;
				for (int i = 1; i <= graph->v; i++)
				{
					AdjNode* traverseGraph = graph->array[i].head;
					while (traverseGraph)
					{
						numEdges++;
						traverseGraph = traverseGraph->next;
					}
				}
				if (src > graph->v || src > numEdges || dest > numEdges)
				{
					cout << "Error: One or more of the nodes is invalid." << endl;
				}
				if (flag == 1 || flag == 0)
				{
					dijsktra(graph, src, dest, flag);
				}
				else
				{
					cout << "Error: Invalid flag value" << endl;
				}
			}
			else
			{
				cout << "There is no graph to run Dijkstra's algorithm on" << endl;
			}
			break;
		default:
			break;
		}
	}
}
