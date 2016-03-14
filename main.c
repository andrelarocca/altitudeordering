#include <stdio.h>

int main (int argc, char *argv[]) {
	//Local variables
	int n=-1, //Number of vertices
		i, j, //Indexes
		aux;  //Auxiliar

	//Initialize empty list of edges
	head = NULL;

	//Get number of vertices
	while ((n < 0) || (n > 26)) {
		fprintf(stdout, "\nType the number of vertices: ");
		scanf("%d", &n);
	}
	
	//Get edge weights
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			fprintf(stdout, "\nType the weight of the edge between \'%c\' and \'%c\': ", i+97, j+97);
			scanf("%d", &aux);
					
			createEdge(aux, i+97, j+97);
		}
	}

	return 0;
}