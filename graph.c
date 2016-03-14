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
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = e;
	}
	n_edges++;
}

void orderEdges() {
	Edge *i, *j, *min, *pre_i;
	min = head;
	i = head;
	pre_i = head;

	while (i != NULL) {
		j = i->next;
		while (j != NULL) {
			if (j->weight < min->weight) min = j;
			j = j->next;
		}
		i = i->next;
		if (i != head) {
			pre_i = pre_i->next;
		}
	}
}

void printEdges () {
	Edge *e;
	e = head;

	fprintf(stdout, "\n-------------------------");
	while (e != NULL) {
		fprintf(stdout, "\nEdge between \'%c\' and \'%c\', weight: %d", e->v1, e->v2, e->weight);
		e = e->next;
	}
	fprintf(stdout, "\n-------------------------\n");
}