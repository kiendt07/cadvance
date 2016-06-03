#ifndef QUEUE_H
#define QUEUE_H

#include "dllist.h"

#define MAX_ELEMENT 100000
	
typedef struct {
	Dllist q; //Queue list
	int n; // number of elements
} Queue;

Queue queue_make(void);
int queue_is_empty(Queue);
int queue_is_full(Queue);
int queue_en(Queue aQueue, Jval val);
Jval queue_de(Queue);
int queue_free(Queue);

#endif //QUEUE_H