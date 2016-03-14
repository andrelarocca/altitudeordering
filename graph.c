#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void createEdge (int weight, char v1, char v2) {
	Edge *e;
	e = (Edge*)malloc(sizeof(Edge));

	e->weight = weight;
	e->v1 = v1;
	e->v2 = v2;

	insertEdge(e);
}

void insertEdge (Edge *e) {
	if (head == NULL) { //Empty list
		head = e;
	} else { //Non empty list
		Edge *last;
		last = head;
		while (last->prox != NULL) {
			last = last->prox;
		}
		last->prox = e;
	}
}

void printEdges () {
	Edge *e;
	e = head;

	fprintf(stdout, "\n-------------------------");
	while (e != NULL) {
		fprintf(stdout, "\nEdge between \'%c\' and \'%c\', weight: %d", e->v1, e->v2, e->weight);
	}
	fprintf(stdout, "\n-------------------------");
}