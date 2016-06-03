#include <stdio.h>
#include <stdlib.h>
#include "jrb.h"
#include <string.h>

void ss()
{
    while(getchar() != '\n');
}

void readfile(JRB tree)
{
    FILE* f;
    f = fopen("phonebook.txt", "r");
    char num[100];
    char name[100];
    int i=0;
    while (!feof(f)) {
        fscanf(f, "%[^\t]\t", name);
        fscanf(f, "%[^\n]\n", num);
        jrb_insert_str(tree,strdup(name),new_jval_s(strdup(num)));
    }
    fclose(f);
}

void search_phone(const JRB tree, char* name)
{
    JRB find_node = jrb_find_str(tree,name);
    if (!find_node) {
        printf("khong co ten nay trong danh ba\n");
        return 0;
    }
    printf("Sdt: %s\n", jval_s(find_node->val));
    return;
}

void add_phone(JRB tree, char* name, char* num)
{
	JRB find_node = jrb_find_str(tree,name);
	if (find_node != NULL) {
		printf("ten nay da co trong danh ba, ko the them\n");
		return;
	}
	jrb_insert_str(tree,strdup(name),new_jval_s(strdup(num)));
}

void delete_phone(JRB tree, char* name)
{
    JRB del_node = jrb_find_str(tree, name);
    if (!del_node) return;
    jrb_delete_node(del_node);
}

void modify_phone(JRB tree, char* name)
{
    char n[100];
    JRB mod_node = jrb_find_str(tree, name);
    if (!mod_node) {
        printf("khong co ten nay trong danh ba\n");
        return;
    }
    printf("Sdt cu: %s\n", jval_s(mod_node->val));
    printf("Nhap sdt moi:");
    scanf("%[^\n]s", n);
    ss();
    strcpy(jval_s(mod_node->val), n);
}

void SavePhone(const JRB tree)
{
    FILE* f = fopen("phonebook.txt", "w");
    JRB ptr = NULL;
    jrb_traverse(ptr,tree)
        fprintf(f, "%s\t%s\n", jval_s(ptr->key), jval_s(ptr->val));
    fclose(f);
}

main()
{
    JRB tree = make_jrb();
    readfile(tree);
    char name[100];
    char num[100];
    int cn;
    do {
        printf("0.In\n1.Them\n2.Xoa\n3.Tim\n4.Sua\n5.Luu\nLua chon:");
        scanf("%d", &cn);
        ss();
        if (cn == 0) {
            JRB ptr = NULL;
            jrb_traverse(ptr, tree)
                printf("%s\t%s\n", jval_s(ptr->key),jval_s(ptr->val));
        }
        if (cn == 1) {
            printf("Nhap ten: "); scanf("%[^\n]s", name); ss();
            printf("Nhap sdt: "); scanf("%[^\n]s", num); ss();
            add_phone(tree,name, num);
        }
        if (cn == 2) {
            printf("Nhap ten: "); scanf("%[^\n]s", name); ss();
				delete_phone(tree, name);
        }
        if (cn == 3) {
            printf("Nhap ten: "); scanf("%[^\n]s", name); ss();
            search_phone(tree, name);
        }
        if (cn == 4) {
            printf("Nhap ten: "); scanf("%[^\n]s", name); ss();
            modify_phone(tree, name);
        }
        if (cn == 5) {
            SavePhone(tree);
        }
        printf("\n");
    } while (-1 < cn && cn < 6);
    jrb_free_tree(tree);
}
