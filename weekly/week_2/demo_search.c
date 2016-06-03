#include "jval.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int int_compare(union UnionData *x, union UnionData *y)
{
	if ((*x).i == (*y).i)
		return 0;
	else
		return (*x).i<(*y).i?-1:1;
}

int main(void)
{
	union UnionData a[6];//(union UnionData*)	malloc(sizeof(union UnionData)*6);
	int i;
	for (i=0; i<6; i++){
		a[i].i=i;
	}
	Jval item; item=new_i(3);
	printf("Search item %d: %d\n", item.i, search_gen(a, 0, 5, &item, int_compare));
	return 0;
}