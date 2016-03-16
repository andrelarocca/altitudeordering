#include <stdio.h>
#include "graph.h"

int main (int argc, char *argv[]) {
	//Local variables
	int n=-1, //Number of vertices
		i, j, //Indexes
		aux,  //Auxiliar
		from_file = 0;

	//Initialize empty list of edges
	head = NULL;
	mst = NULL;
	n_edges = 0;
	n_v = 0;
	n_mst = 0;

	
	FILE *file;
	if (argc == 2) {
		file = fopen(argv[1], "r+");
		from_file = 1;
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

	//int max_edges = n*(n-1)/2;
	
	//Initialize empty binary tree
	bt = (BinaryTree*)malloc(sizeof(BinaryTree));
	bt->parents = (int*)malloc(n*sizeof(int));
	bt->size = 0;

	//for (i = 0; i < max_edges; i++) makeSet(i);

	for (i = 0; i < n; i++) {
		makeSet(i);
		for (j = i+1; j < n; j++) {
			if (from_file == 0) {
				fprintf(stdout, "\nType the weight of the edge between \'%c\' and \'%c\' (-1 for none): ", i+97, j+97);
				scanf("%d", &aux);
			} else {
				fscanf(file, "%d", &aux);
				//fprintf(stdout, "%d\n", aux);
			}			
					
			if (aux != -1) createEdge(aux, i+97, j+97, 0);
		}
	}

	//Order edge list
	orderEdges();
	printEdges(0);

	//Binary Tree Kruskal
	binaryTreeKruskal();
	printEdges(1);

	// free(bt->parents);
	// free(bt);
	// freeLists();
	if (from_file == 1) fclose(file);

	return 0;
}