#ifndef DFS_H
#define DFS_H

#include "jrb.h"
#include "jval.h"
#include "stack.h"
#include "graph.h"

void DFS(Graph g, Jval start, Jval stop, void (*func)(Jval, Jval));


#endif //DFS_H