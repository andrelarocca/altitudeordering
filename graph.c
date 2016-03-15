#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void createEdge (int weight, char v1, char v2, int is_mst) {
	Edge *e;
	e = (Edge*)malloc(sizeof(Edge));

	e->weight = weight;
	e->v1 = v1;
	e->v2 = v2;

	insertEdge(e, is_mst);
}

void insertEdge (Edge *e, int is_mst) {
	if (is_mst == 0) {
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
	} else {
		if (mst == NULL) { //Empty list
		mst = e;
		} else { //Non empty list
			Edge *last;
			last = mst;
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = e;
		}
		n_mst++;
	}
	
}

void orderEdges() {
	Edge *i, *j, *min, *pre_i, *pre_j, *pre_min;
	i = head;
	
	while (i != NULL) {
		min = i;
		pre_j = i;
		j = i->next;
		while (j != NULL) {
			if (j->weight < min->weight) {
				min = j;
				pre_min = pre_j;
			}
			pre_j = j;
			j = j->next;			
		}
		if (min != i) { //Changes if not first
			pre_min->next = min->next;
			if (i == head) { //Changes to first position
				head = min;
				head->next = i;
			} else { //Changes to other position
				pre_i->next = min;
				min->next = i;
			}			
		}
		pre_i = min;
		i = min->next;
	}
}

void makeSet (int q) {
	bt->parents[q] = -1;
	bt->size += 1;
}

int findCanonical (int q) {
	while (bt->parents[q] >= 0) q = bt->parents[q];
	return q;
}

int union_ (int cx, int cy) {
	bt->parents[cx] = bt->size;
	bt->parents[cy] = bt->size;
	makeSet(bt->size);
	return bt->size-1;
}

void binaryTreeKruskal() {
	int cx, cy;
	Edge *e;
	e = head;
	while (e != NULL) {
		cx = findCanonical(e->v1-97);
		cy = findCanonical(e->v2-97);

		if (cx != cy) {
			fprintf(stdout, "cx=%d, cy=%d, e(w)=%d, e(v1)=%c|%d, e(v2)=%c|%d\n", cx, cy, e->weight, e->v1, e->v1-97, e->v2, e->v2-97);
			union_(cx, cy);
			createEdge(e->weight, e->v1, e->v2, 1);
		}

		e = e->next;
	}
}

void printEdges (int is_mst) {
	Edge *e;

	if (is_mst == 0) e = head;
	else e = mst;

	fprintf(stdout, "\n-------------------------");
	while (e != NULL) {
		fprintf(stdout, "\nEdge between \'%c\'%d and \'%c\'%d, weight: %d", e->v1, e->v1-97, e->v2, e->v2-97, e->weight);
		e = e->next;
	}
	fprintf(stdout, "\n-------------------------\n");
}

void printParents() {
	int i;
	for (i = 0; i < n_v; i++) {
		fprintf(stdout, "Parent[%c|%d] = %d\n", i+97, i, bt->parents[i]);
	}
	fprintf(stdout, "Size = %d\n", bt->size);
}