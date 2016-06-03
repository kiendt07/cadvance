#include <stdio.h>
#include <stdlib.h>
#include "dfs.h"
#include "stack.h"

void DFS(Graph g, Jval start, Jval stop, void (*func)(Jval, Jval))
{
	JRB visited_;
	visited_=make_jrb();

	Stack aStack;
	aStack=stack_init();

	stack_push(aStack, start);

	Jval u, v;
	Jval adj[100];
	int i, n;
	while (!stack_is_empty(aStack)){
		u = stack_pop(aStack);
		if (jrb_find_gen(visited_, u, COMPARE) == NULL){ //Not visited
			func(u, getVertex(g, u));
			getchar();
			jrb_insert_gen(visited_, u, new_jval_v(NULL), COMPARE); //Visited
			n=adj_traverse(g, u, adj);
			for (i=0; i<=n; i++){
				v=((JRB) jval_v(adj[i]))->key;
				if (jrb_find_gen(visited_, v, COMPARE) == NULL)
					stack_push(aStack, v);
			}
		}
	}
}
