#include <stdio.h>
#include <stdlib.h>

#ifndef GRAPH_H
#define GRAPH_H

typedef struct Edge {
	int weight;
	char v1, v2;
	struct Edge *next;
} Edge;

Edge *head;
int n_edges;

void createEdge (int weight, char v1, char v2);
void insertEdge (Edge *e);
void orderEdges();
void printEdges ();

#endif
