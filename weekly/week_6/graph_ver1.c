#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"

#define COMPARE int_compare

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

Graph createGraph(void) 
{
	Graph aGraph;
	aGraph.edges = make_jrb();
	aGraph.vertices = make_jrb();
	return aGraph;
}

int setEdge(Graph aGraph, Jval v1, Jval v2, Jval w) //noi 2 dinh v1, v2 bang canh co trong so w
{
	JRB aNode, aTree;
	aNode=jrb_find_gen(aGraph, v1, COMPARE);

	if (aNode == NULL){
		aTree=make_jrb(); 
		if (aNode == NULL) perror("Cannot create JRB");

		jrb_insert_gen(aGraph, v1, new_jval_v(aTree));
	}
	else{
		aTree=(Graph) jval_v(jrb_val(aNode));
	}

		//aNode=(Graph) jval_v(jrb_val(jrb_find_gen(aGraph, v1, COMPARE)));
	jrb_insert_gen(aTree, v2, w, COMPARE);
	//ir bb_insert_gen(aGraph, v1, new_jval_v((void *) aNode), COMPARE);
	return 0;
}

int isConnected(Graph aGraph, Jval v1, Jval v2)
{
	JRB aNode, aTree;
	aNode=jrb_find_gen(aGraph, v1, COMPARE)));

	if (aNode != NULL){
		aTree=(Graph) jval_v(jrb_val(aNode));
		if (jrb_find_gen(aTree, v2, COMPARE) != NULL)
			return 1;
		else 
			return 0;
	}
	else
		return 0;
}