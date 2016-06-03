#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

Entry createEntry(void *aKey, void *aValue)
{
	Entry res; //SAI
	res.key=malloc(SIZE_OF_KEY);
	memcpy(res.key, aKey, SIZE_OF_KEY);
	res.value=malloc(SIZE_OF_VALUE);
	memcpy(res.value, aValue, SIZE_OF_VALUE);
	return res;
}

SymbolTable * createSymbolTable(Entry (*makeNode)(void *, void *), 
								int (*compare)(void *, void *))
{
	SymbolTable *aSymbolTable=(SymbolTable *)malloc(sizeof(SymbolTable));
	aSymbolTable->entry=(Entry *)malloc(sizeof(Entry) * INTIAL_SIZE);
	aSymbolTable->total=-1;     //Chua co Entry nao
        aSymbolTable->size=INTIAL_SIZE;
	aSymbolTable->makeNode=makeNode;
	aSymbolTable->compare=compare;
	return (aSymbolTable);
}

void dropSymbolTable(SymbolTable *aSymbolTable)
{
	int i;
	for (i=0; i<aSymbolTable->total; i++){
		free(aSymbolTable->entry[i].key);
		free(aSymbolTable->entry[i].value);
	}
	free(aSymbolTable->entry);
	free(aSymbolTable);
}

int addEntry(void *key, void *value, SymbolTable *aSymbolTable)
{
	if (aSymbolTable->total >= aSymbolTable->size)
		return -1;
	int *total=&(aSymbolTable->total);
	(*total)++;
	aSymbolTable->entry[*total].key=malloc(SIZE_OF_KEY);
	memcpy(aSymbolTable->entry[*total].key, key, SIZE_OF_KEY);
	aSymbolTable->entry[*total].value=malloc(SIZE_OF_VALUE);
	memcpy(aSymbolTable->entry[*total].value, value, SIZE_OF_VALUE);
	return *total;
}

Entry * getEntry(void *key, const SymbolTable *aSymbolTable)
{
	int i;
	for (i=0; i<=aSymbolTable->total; i++){
		if (aSymbolTable->compare(aSymbolTable->entry[i].key, key) == 0)
			return &(aSymbolTable->entry[i]);
	}
	return NULL;
}