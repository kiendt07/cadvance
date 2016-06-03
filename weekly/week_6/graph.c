#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "jrb.h"

//#define COMPARE int_compare

Graph createGraph(void) 
{
	Graph aGraph;
	aGraph.edges = make_jrb();
	aGraph.vertices = make_jrb();
	aGraph.compare=str_compare;
	return aGraph;
}

int addVertex(Graph g, Jval id, Jval data)
{
	JRB node = jrb_find_gen(g.vertices, id, int_compare);
	if (node==NULL){ // only add new vertex
		jrb_insert_gen(g.vertices, id, data, int_compare);
	}
	return 0;
}

Jval getVertex(Graph g, Jval id)
{
	JRB node = jrb_find_gen(g.vertices, id, int_compare);
	if (node == NULL)
		return new_jval_v(NULL);
	else
		return (jrb_val(node));
}

int addEdge(Graph g, Jval v1, Jval v2, Jval w)
{
	JRB aNode, aTree;

	if (!hasEdge(g, v1, v2)){
		aNode=jrb_find_gen(g.edges, v1, int_compare);

		if (aNode == NULL){
			aTree=make_jrb(); 
			jrb_insert_gen(g.edges, v1, new_jval_v(aTree), int_compare);
		}
		else{
			aTree=(JRB) jval_v(jrb_val(aNode));
		}
		jrb_insert_gen(aTree, v2, w, int_compare);
		return 0;
	}
}

int hasEdge(Graph g, Jval v1, Jval v2)
{
	JRB aNode, aTree;

	aNode = jrb_find_gen(g.edges, v1, int_compare);
	if (aNode == NULL)
		return 0;
	aTree=(JRB) jval_v(jrb_val(aNode));
	if (jrb_find_gen(aTree, v2, int_compare) == NULL)
		return 0;
	else
		return 1;
}

int adj_traverse(Graph g, Jval u, void (*func)(JRB))
{
	JRB node, tree;

	node=jrb_find_gen(g.edges, u, int_compare);
	if (node != NULL){
		tree=(JRB) jval_v(jrb_val(node));
		jrb_traverse(node, tree){
			func(node);
		}
	}
}


int int_compare(Jval x, Jval y)
{
	int ix, iy;

	ix=jval_i(x);
	iy=jval_i(y);

	if (ix < iy)
		return -1;
	if (ix == iy)
		return 0;
	return 1;
}

int str_compare(Jval x, Jval y)
{
	char *s_x, *s_y;
	s_x=jval_s(x); s_y=jval_s(y);
	return (strcmp(s_x, s_y));
}