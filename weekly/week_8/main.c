/*DEMO TopoLogicalSort*/

#include "graph.h"
#include "fields.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int agrc, char **argv)
{
	IS is;
	Graph g;
	Jval trace[100], u, v;

	g = createGraph();
	is=new_inputstruct(argv[1]);

	while (get_line(is) >= 0){
		if (strcmp(is->fields[0], "CLASS") == 0){
			u = new_jval_s(strdup(is->fields[1]));
			addVertex(g, u, new_jval_i(1));
		}
		else {
			if (strcmp(is->fields[0], "PREREQ") == 0){
				v = new_jval_s(strdup(is->fields[1]));
				addVertex(g, v, new_jval_i(1));
				addEdge(g, v, u, new_jval_i(1));
			}
		}
	}

	if (!DAG(g)){
		printf("cannot do the topoLogicalSort\n");
		return -1;
	}


	int i, n;

	topoLogicalSort(g, trace, &n);
	for (i=0; i<n; i++){
		printf("%s\t", jval_s(trace[i]));
	}
	printf("\n");
	graph_free(g);
	return 0;
}