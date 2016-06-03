#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "fields.h"
#include <string.h>

/*Nhan to hop Ctrl + D -> EOF de thoat nhap du lieu, dong thoi thoat chuong trinh*/

int int_compare(Jval x, Jval y);
int str_compare(Jval x, Jval y);
int split_id(char *source);
void Input_(Graph g, JRB id, const char *input_file);
void Query_(Graph g, JRB id_query);

int main(int argc, char **argv)
{
	Graph g = createGraph();
	JRB id = make_jrb();

	Input_(g, id, argv[1]);
	Query_(g, id);

	jrb_free_tree(g.vertices);
	jrb_free_tree(g.edges);
	jrb_free_tree(id);
}

int split_id(char *source)
{
	return atoi(++source);
}

void Input_(Graph g, JRB id, const char *input_file)
{
	IS is;
	char *v, *v_name;
	int v_int;

	is=new_inputstruct(input_file);

	get_line(is); // Skip the first line;
	while (get_line(is) >= 0){
		if (strstr(is->text1, "[LINES]") != NULL)
			break; //Dung vong lap khi gap dong "[LINE]", skip luon 

		v=strtok(is->text1, "="); //Tach Id va Ten
		v_name=strtok(NULL, "="); //Tach ten
		v_name[strlen(v_name) - 1]='\0'; //Xoa /n o cuoi xau 
		v_int=split_id(v);

		jrb_insert_str(id, strdup(v_name), new_jval_i(v_int));

		if ((v == NULL) || (v_name == NULL))
			perror("Cannot read");
		else
			addVertex(g, new_jval_i(v_int), new_jval_s(strdup(v_name)));
	}

	char *prev;
	while (get_line(is) >= 0){
		v=strtok(is->text1, "=");
		v=strtok(NULL, "="); 
		if (v[strlen(v) - 1] == '\n') v[strlen(v) - 1] = '\0';
		v=strtok(v, " "); 

		while (v != NULL){
			prev = v;
			v=strtok(NULL, " "); 
			if (v== NULL)
				break;

			addEdge(g, new_jval_i(split_id(strdup(prev))), new_jval_i(split_id(strdup(v))), new_jval_i(0));
			addEdge(g, new_jval_i(split_id(strdup(v))), new_jval_i(split_id(strdup(prev))), new_jval_i(0));
		}
	}

	jettison_inputstruct(is);
}


void Query_(Graph g, JRB id_query)
{
	int id; 
	char *name;
	IS is_etr;
	JRB tree, aNode;

	is_etr=new_inputstruct(NULL);

	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	puts("\n\nEnter a station name: ");
	while (get_line(is_etr) >= 0){
		name=strdup(is_etr->text1);
		name[strlen(name) - 1] = '\0';

		if (jrb_find_str(id_query, strdup(name)) == NULL){
			//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("Wrong name!!! Please enter again...\n");
		}
		else{
			id=jval_i(jrb_val(jrb_find_str(id_query, strdup(name))));
			//printf("%d\n", id);

			tree=(JRB) jval_v(jrb_val(jrb_find_int(g.edges, id)));
			if (tree != NULL){
				printf("\n\nStations nearby %s: ", name);
				jrb_traverse(aNode, tree){
					printf(" %s", jval_s(jrb_val(jrb_find_int(g.vertices, jval_i(aNode->key)))));
				}
				printf("\n");
			}
			else {
				//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("Wrong name!!! Please enter again...\n");
			}
			//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			puts("\n\nEnter a station name: ");
		}
	}
}

