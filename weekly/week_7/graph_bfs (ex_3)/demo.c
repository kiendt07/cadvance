#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "bfs.h"
#include "fields.h"
#include <string.h>
#include "queue.h"

void PrintThePath(Jval u)
{
	printf("%d ", jval_i(u));
}

int main(int argc, char **argv)
{
	IS is;
	Graph g;
	int u, v;

	is=new_inputstruct(argv[1]);
	g=createGraph();

	while (get_line(is) >= 0){
		u=atoi(is->fields[0]);
		v=atoi(is->fields[1]);

		addVertex(g, new_jval_i(u), new_jval_v(NULL)); addVertex(g, new_jval_i(v), new_jval_v(NULL));
		addEdge(g, new_jval_i(u), new_jval_i(v), new_jval_i(0));
	}

	BFS(g, new_jval_i(1), new_jval_i(-1), PrintThePath);
	return 0;
}