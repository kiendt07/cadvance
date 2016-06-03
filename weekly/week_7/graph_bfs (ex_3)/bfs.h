#ifndef BFS_H
#define BFS_H

#include "graph.h"
#define MAX_VERTEX 100000

void BFS(Graph g, Jval start, Jval stop, void (*func)(Jval)); // BFS tren g, bat dau tu start, cho den khi gap stop


#endif //BFS_H