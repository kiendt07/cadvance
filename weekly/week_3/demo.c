#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "quick_sort.h"

int int_compare(void *x, void *y)
{
	int t1=*((int *)x);
	int t2=*((int *)y);
	if (t1==t2)
		return 0;
	else
		if (t1<t2)
			return -1;
	return 1;
}

int Entry_compare(void *x, void *y)
{
    Entry t1=*((Entry *)x);
    Entry t2=*((Entry *)y);
    if (t1.key == t2.key)
        return 0;
    else if (t1.key < t2.key)
        return -1;
    return 1;
}

int main()
{
	int i;
	SymbolTable *aSymbolTable = createSymbolTable(createEntry, int_compare);
	//SAI O DAY
	for (i=0; i<3; i++){
		addEntry(&i, strdup("abc"), aSymbolTable);
	}
        int n=2;
        char *s=(char *)((getEntry(&n, aSymbolTable))->value);       
        
        QuickSort(aSymbolTable->entry, 0, 2, sizeof(Entry), Entry_compare);
        
}