#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "fields.h"

int main()
{
	IS is;
	BTA *b;
	char key[ZKYLEN], data[ZKYLEN];

	is=new_inputstruct(NULL); // format cua file input: [ho va ten] [sdt]
	if (is==NULL)
		return -1;

	btinit();

	//printf("Dont load, Create\n");
	b=btcrt("BTREE_pn", 0, FALSE);
	if (b==NULL)
		perror("ERROR creating\n");

	int i;
	while (get_line(is) >= 0){
		strcpy(key, is->fields[0]);
		for (i=1; i<is->NF-1; i++){ // Ghep ten
			strcat(key, " ");
			strcat(key, is->fields[i]);
		}
		printf("%s\n", key);

		strcpy(data, is->fields[is->NF-1]);

		//if ((bfndky(b, key, 0) != 0))
		if (btins(b, key, data, sizeof(data)) == 0);
		else 
			perror("Insert ERROR\n");
	}

	btpos(b, ZSTART);
	int rsize;
	while (btseln(b, key, data, ZKYLEN, &rsize) == 0){
		printf("%s %s\n", key, data);
	}

	btcls(b);
	jettison_inputstruct(is);
	return 0;
}