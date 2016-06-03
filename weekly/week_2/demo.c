#include "quick_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int int_compare(void* x, void* y)
{
	return (*(int *)x < *(int *)y);
}

typedef struct{
	char name[30];
	int number;
} Student;

int stud_compare(void *x, void *y)
{
	return (((Student *)x)->number < ((Student *)y)->number);
}

int main()
{
	int a[6]={1, 3, 2, 7, 6, 4};
	int i;
	Student stud[6];
	for (i=0; i<6; i++){
		strcpy(stud[i].name, "abc");
		stud[i].number=i;
	}
	QuickSort(a, 0, 5, sizeof(int), int_compare);
	QuickSort(stud, 0, 5, sizeof(Student), stud_compare);
	for (i=0; i<6; i++)	
		printf("%d ", a[i]);
	for (i=0; i<6; i++)
		printf("%d ", stud[i].number);
	return 0;
}
