#include <stdio.h>
#include "graph.h"

int main (int argc, char *argv[]) {
	//Local variables
	int n=-1, //Number of vertices
		i, j, //Indexes
		aux;  //Auxiliar

	//Initialize empty list of edges
	head = NULL;
	mst = NULL;
	n_edges = 0;
	n_v = 0;
	n_mst = 0;

	//Get number of vertices
	while ((n < 2) || (n > 26)) {
		fprintf(stdout, "\nType the number of vertices: ");
		scanf("%d", &n);
	}
	n_v = n;

	//Initialize empty binary tree
	bt = (BinaryTree*)malloc(sizeof(BinaryTree));
	bt->parents = (int*)malloc(n*sizeof(int));
	bt->size = 0;

	//Get edge weights
	for (i = 0; i < n; i++) {
		makeSet(i); //Initialize parents
		for (j = i+1; j < n; j++) {
			fprintf(stdout, "\nType the weight of the edge between \'%c\' and \'%c\' (-1 for none): ", i+97, j+97);
			scanf("%d", &aux);
					
			if (aux != -1) createEdge(aux, i+97, j+97, 0);
		}
	}

	//Order edge list
	orderEdges();

	//Binary Tree Kruskal
	binaryTreeKruskal();

	printParents();
	printEdges(1);

	return 0;
}