#ifndef GRAPH_H
#define GRAPH_H

#include "jrb.h"
#include "jval.h"
#include "stack.h"

#define COMPARE str_compare

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

int adj_traverse(Graph g, Jval u, Jval *adj); // ham func nhan vao 1 nut JRB (Jval v, w) trong cay JRB cac dinh ke cua u
int indegree (Graph g, Jval v, Jval *output);
int outdegree (Graph g, Jval v, Jval *output);
int DAG(Graph g);
void topoLogicalSort(Graph g, Jval *trace, int *n_trace);
void graph_free(Graph g);


#endif //GRAPH_H