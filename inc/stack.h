#ifndef STACK_H
#define STACK_H

#include "dllist.h"

#define MAX_STACK_ELEMENT 100000

typedef struct
{
	Dllist stack; //Stack
	int n;	//Number of Elements
} Stack;

Stack stack_init(void);
void stack_free(Stack aStack);
int stack_is_empty(Stack aStack);
int stack_is_full(Stack aStack);
Jval stack_pop(Stack aStack);
int stack_push(Stack aStack, Jval val);

#endif //STACK_H