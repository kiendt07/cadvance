#include "jval.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search_gen(union UnionData *a, int l, int r,
				union UnionData *item, int (*compare)(union UnionData*, union UnionData*))
{
	if (l>r)
		return -1;
	int i=(l+r)/2;
	int res=compare(item, &a[i]);
	if (res==0)
		return i;
	else
		if (res<0)
			return search_gen(a, l, i-1, item, compare);
		else
			return search_gen(a, i+1, r, item, compare);		
}
