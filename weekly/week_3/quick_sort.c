#include "quick_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void QuickSort(void *buf, int l, int h, int size, int (*compare)(void *, void *))
{
	if (h-l<=0)
		return;
	int i=l, j=h, k=rand()%(h-l+1) + l;
	char *temp=(char *)malloc(size);
	do
	{
		while (compare((char *)buf+size*i, (char *)buf+size*k)) i++;
		while (!compare((char *)buf+size*j, (char *)buf+size*k)) j--;
		if (i<=j){
			memcpy(temp, (char *)buf+size*i, size);
			memcpy((char *)buf+size*i, (char *)buf+size*j,size);
			memcpy((char *)buf+size*j, temp, size);
			i++; j--;
		}
	} while (i<=j);
	QuickSort(buf, l, j, size, compare); 
	QuickSort(buf, i, h, size, compare);
}

