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
Edge *mst;
int n_edges, n_v, n_mst;

typedef struct BinaryTree {
	int size;
	int *parents;
} BinaryTree;

BinaryTree *bt;

void createEdge (int weight, char v1, char v2, int is_mst);
void insertEdge (Edge *e, int is_mst);
void orderEdges();
void makeSet (int q, int inc);
int  findCanonical (int q);
int  makeUnion (int cx, int cy);
void binaryTreeKruskal();
void printEdges (int is_mst);
void printParents();
void freeLists();

#endif
