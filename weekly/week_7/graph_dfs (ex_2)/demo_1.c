#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "dfs.h"
#include "stack.h"
#include "fields.h"
//Graph voi id vertex la int


void PrintThePath(Jval u, Jval w)
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

	DFS(g, new_jval_i(1), new_jval_i(4), PrintThePath);
	return 0;
}