#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define INTIAL_SIZE 10
#define INCREMENTAL_SIZE 10
#define SIZE_OF_KEY sizeof(int)
#define SIZE_OF_VALUE 30

typedef struct {
	void *key;
	void *value;
} Entry;
typedef struct {
	Entry *entry;
	int total;
	int size;
	Entry (*makeNode)(void *, void *);
	int (*compare)(void *, void *);
} SymbolTable;


Entry createEntry(void *, void *); //Tao mot Entry tu du lieu vao

//Khoi tao mot Symbol Table
SymbolTable * createSymbolTable(Entry (*)(void *, void *), int (*)(void *, void *));

//Xoa mot Symbol Table
void dropSymbolTable(SymbolTable *);

//Them mot Entry vao Symbol Table
int addEntry(void *, void *, SymbolTable *);

Entry * getEntry(void *key, const SymbolTable *aSymbolTable); //return Entry

#endif