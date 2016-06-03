#include "graph.h"
#include "queue.h"
#include "jval.h"
#include <stdlib.h>
#include <stdio.h>

void BFS(Graph g, Jval start, Jval stop, void (*func)(Jval))
{
	Queue aQueue;
	Jval u, v;
	JRB visited_;
	JRB node, tree;

	aQueue=queue_make();
	queue_en(aQueue, start);
	visited_=make_jrb();
	
	while (! queue_is_empty(aQueue)){
		u = queue_de(aQueue);
		if (jrb_find_gen(visited_, u, COMPARE) == NULL){ // Chua visit v (ko co v trong JRB visited_)
			func(u); 
			jrb_insert_gen(visited_, u, new_jval_i(1), COMPARE); // Danh dau visited u

			if (COMPARE(u, stop) == 0)
				return;
			
			node = jrb_find_gen(g.edges, u, COMPARE);
			if (node != NULL){
				tree = (JRB) jval_v(jrb_val(node));
				jrb_traverse(node, tree){
					v=node->key;
					if (jrb_find_gen(visited_, v, COMPARE) == NULL) // Chua visit v
						queue_en(aQueue, v);
				}
			}
		}

	}
}