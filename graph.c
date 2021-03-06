#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void createEdge (int weight, char v1, char v2, int is_mst) {
	Edge *e;
	e = (Edge*)malloc(sizeof(Edge));

	// if (is_mst == 1)
	// fprintf(stdout, "weight = %d\n", weight);

	e->weight = weight;
	e->v1 = v1;
	e->v2 = v2;
	e->next = NULL;

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

/********************************************/
/* Binary Partition Tree                    */
/********************************************/
void qbt_makeSet (int q, int inc) {
	if (verbose) fprintf(stdout, "\n-- QBT MAKE SET (%d)\n", q);
	bt->parents[q] = -1;
	if (verbose) fprintf(stdout, "bt->parents[%d] = %d\n", q, bt->parents[q]);
	if (inc == 1) bt->size += 1;
	if (verbose) fprintf(stdout, "bt->size = %d\n", bt->size);
}

int qbt_findCanonical (int q) {
	if (verbose) fprintf(stdout, "\n-- QBT FIND CANONICAL (%d)\n", q);
	if (verbose) fprintf(stdout, "bt->parents[%d] = %d\n", q, bt->parents[q]);
	while (bt->parents[q] >= 0) {
		q = bt->parents[q];
		if (verbose) fprintf(stdout, "bt->parents[%d] = %d\n", q, bt->parents[q]);
	}
	if (verbose) fprintf(stdout, "return q = %d\n", q);
	return q;
}

int qbt_makeUnion (int cx, int cy) {
	if (verbose) fprintf(stdout, "\n-- QBT MAKE UNION (%d, %d)\n", cx, cy);
	bt->parents[cx] = bt->size;
	if (verbose) fprintf(stdout, "bt->parents[%d] = %d (bt->size)\n", cx, bt->parents[cx]);
	bt->parents[cy] = bt->size;
	if (verbose) fprintf(stdout, "bt->parents[%d] = %d (bt->size)\n", cy, bt->parents[cy]);
	qbt_makeSet(bt->size, 1);
	if (verbose) fprintf(stdout, "return bt->size - 1 = %d\n", bt->size-1);
	return bt->size-1;
}

/********************************************/
/* Tarjan Union-Find                        */
/********************************************/
void qt_makeSet (int q, int inc) {
	if (verbose) fprintf(stdout, "\n-- QT MAKE SET (%d)\n", q);
  bt->parents[bt->size] = -1;
	if (verbose) fprintf(stdout, "bt->parents[%d] = %d\n", bt->size, bt->parents[bt->size]);
  bt->rank[bt->size] = 0;
	if (verbose) fprintf(stdout, "bt->rank[%d] = %d\n", bt->size, bt->rank[bt->size]);
  if (inc == 1) bt->size += 1;
	if (verbose) fprintf(stdout, "bt->size = %d\n", bt->size);
}

int qt_findCanonical (int q) {
	if (verbose) fprintf(stdout, "\n-- QT FIND CANONICAL (%d)\n", q);
  int tmp, r = q;

	if (verbose) fprintf(stdout, "bt->parents[%d] = %d\n", r, bt->parents[r]);
  while (bt->parents[r] >= 0) {
    r = bt->parents[r];
		if (verbose) fprintf(stdout, "bt->parents[%d] = %d\n", r, bt->parents[r]);
  }

	if (verbose) fprintf(stdout, "bt->parents[%d] = %d\n", q, bt->parents[q]);
  while (bt->parents[q] >= 0) {
    tmp = q;
    q = bt->parents[q];
    bt->parents[tmp] = r;
		if (verbose) fprintf(stdout, "bt->parents[%d] = %d\n", tmp, bt->parents[tmp]);
  }

	if (verbose) fprintf(stdout, "return r = %d\n", r);
  return r;
}

int qt_makeUnion (int cx, int cy) {
	if (verbose) fprintf(stdout, "\n-- QT MAKE UNION (%d, %d)\n", cx, cy);
  int tmp;

	if (verbose) fprintf(stdout, "bt->rank[%d] = %d\n", cx, bt->rank[cx]);
	if (verbose) fprintf(stdout, "bt->rank[%d] = %d\n", cy, bt->rank[cy]);
  if (bt->rank[cx] > bt->rank[cy]) {
    tmp = cy;
    cy = cx;
    cx = tmp;
  }

  if (bt->rank[cx] == bt->rank[cy]) bt->rank[cy] += 1;
  bt->rank[cx] = cy;

	if (verbose) fprintf(stdout, "bt->rank[%d] = %d\n", cx, bt->rank[cx]);
	if (verbose) fprintf(stdout, "bt->rank[%d] = %d\n", cy, bt->rank[cy]);

	if (verbose) fprintf(stdout, "return cy = %d\n", cy);
  return cy;
}

void binaryTreeKruskal (int mode) {
	int cx, cy;
	Edge *e;
	e = head;
	while (e != NULL) {
		if (verbose) fprintf(stdout, "\n\n-- ARESTA %c -> %c, peso = %d\n", e->v1, e->v2, e->weight);

    switch (mode) {
      case 0: cx = qbt_findCanonical(e->v1-97);
              cy = qbt_findCanonical(e->v2-97);
              break;
      case 1: cx = qt_findCanonical(e->v1-97);
              cy = qt_findCanonical(e->v2-97);
              break;
    }

		if (cx != cy) {
			if (verbose) fprintf(stdout, "weight=%d, v1=%c, v2=%c\n", e->weight, e->v1, e->v2);
      switch (mode) {
        case 0:	qbt_makeUnion(cx, cy);
                break;
        case 1: qt_makeUnion(cx, cy);
                break;
      }
			if (verbose) fprintf(stdout, "weight=%d, v1=%c(%d), v2=%c(%d)\n", e->weight, e->v1, e->v1-97, e->v2, e->v2-97);
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

void freeLists() {
	Edge *a, *pre_a;
	
	pre_a = head;
	a = head->next;
	

	while (pre_a != NULL) {
		free(pre_a);
		pre_a = a;
		if (a != NULL) a = a->next;
	}

	pre_a = mst;
	a = mst->next;

	while (pre_a != NULL) {
		free(pre_a);
		pre_a = a;
		if (a != NULL) a = a->next;
	}
}
