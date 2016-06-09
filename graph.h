#include <stdio.h>
#include <stdlib.h>

#ifndef GRAPH_H
#define GRAPH_H

int verbose;

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
  int *rank;
} BinaryTree;

BinaryTree *bt;

void createEdge (int weight, char v1, char v2, int is_mst);
void insertEdge (Edge *e, int is_mst);
void orderEdges();
//Binary Partition Tree
void qbt_makeSet (int q, int inc);
int  qbt_findCanonical (int q);
int  qbt_makeUnion (int cx, int cy);
//Tarjan Union-Find
void qt_makeSet (int q, int inc);
int  qt_findCanonical (int q);
int  qt_makeUnion (int cx, int cy);
void binaryTreeKruskal (int i);
void printEdges (int is_mst);
void printParents();
void freeLists();

#endif
