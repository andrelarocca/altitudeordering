#include <stdio.h>
#include <string.h>
#include "graph.h"

int main (int argc, char *argv[]) {
	//Local variables
	int n=-1, //Number of vertices
		i, j, //Indexes
		aux,  //Auxiliar
    mode = 0, //Defines which algorithm to execute
		from_file = 0;

	//Initialize empty list of edges
	head = NULL;
	mst = NULL;
	n_edges = 0;
	n_v = 0;
	n_mst = 0;
	verbose = 0;

  //0 para BinaryTree, 1 para Tarjan
  if (strcmp(argv[1], "qbt") == 0) mode = 0;
  else if (strcmp(argv[1], "qt") == 0) mode = 1;
	
	FILE *file;
	if (argc > 2) {
		file = fopen(argv[2], "r+");
		from_file = 1;
	}

	if (argc == 4) {
		if (strcmp(argv[3], "verbose") == 0) verbose = 1;
	}

	//Get graph data
	if (from_file == 0) {
		while ((n < 2) || (n > 26)) {
			fprintf(stdout, "\nType the number of vertices: ");
			scanf("%d", &n);
		}
	} else {
		fscanf(file, "%d", &n);
	}	
	n_v = n;

	int max_edges = n*(n-1)/2;
	
	//Initialize empty binary tree
	bt = (BinaryTree*)malloc(sizeof(BinaryTree));
	bt->parents = (int*)malloc(max_edges*sizeof(int));
	bt->rank    = (int*)malloc(max_edges*sizeof(int));
	bt->size = 0;

	for (i = 0; i < n; i++) {
		if (mode == 0) bt->size += 1;

		for (j = i+1; j < n; j++) {
			if (from_file == 0) {
				fprintf(stdout, "\nType the weight of the edge between \'%c\' and \'%c\' (-1 for none): ", i+97, j+97);
				scanf("%d", &aux);
			} else {
				fscanf(file, "%d", &aux);
			}			
					
			if (aux != -1) createEdge(aux, i+97, j+97, 0);
		}
	}

	//Order edge list
	if (verbose) printEdges(0);
	orderEdges();
	if (verbose) printEdges(0);

	for (i = 0; i < max_edges; i++) {
    switch(mode) {
      case 0: qbt_makeSet(i, 0);
              break;
      case 1: qt_makeSet(i, 1);
              break;
    }
  }

	//Binary Tree Kruskal
	binaryTreeKruskal(mode);
	printEdges(1);

	free(bt->parents);
	free(bt->rank);
	free(bt);
	freeLists();
	if (from_file == 1) fclose(file);

	return 0;
}
