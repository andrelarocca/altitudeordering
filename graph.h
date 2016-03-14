#include <stdio.h>
#include <stdlib.h>

#ifndef GRAPH_H
#define GRAPH_H

typedef struct Edge {
	int weight;
	char v1, v2;
	struct Edge *prox;
} Edge;

Edge *head;

void createEdge (int weight, char v1, char v2);
void insertEdge (Edge *e);
void printEdges ();

#endif
