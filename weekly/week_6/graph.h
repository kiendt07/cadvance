#ifndef GRAPH_H
#define GRAPH_H

#include "jrb.h"
#include "jval.h"

typedef struct 
{
	JRB edges;
	JRB vertices;
	int (*compare)(Jval, Jval);
} Graph;

int int_compare(Jval, Jval);
int str_compare(Jval, Jval);

Graph createGraph(void);

int addVertex(Graph g, Jval id, Jval data);
Jval getVertex(Graph g, Jval id);
int addEdge(Graph g, Jval v1, Jval v2, Jval w);
int hasEdge(Graph g, Jval v1, Jval v2);

int adj_traverse(Graph g, Jval u, void (*func)(JRB )); // ham func nhan vao 1 nut JRB (Jval v, w) trong cay JRB cac dinh ke cua u

/*#ifndef adj_traverse // (Graph g, Jval u, Jval v)
#define adj_traverse(g, u, v) \
	JRB node, tree;
	tree = (JRB) jval_v(jrb_val(jrb_find_gen(g.edges, u, int_compare))); 
	for (node = jrb_first(tree); node != jrb_nil(tree);  
		{v=jval_i(jrb_val(node)); 
		node = jrb_next(node)}) 

#endif //adj_traverse*/
#endif //GRAPH_H