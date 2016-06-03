#ifndef JVAL_H
#define JVAL_H

union UnionData
{
	int i; 
	float f;
	char *s;
} data;

typedef union UnionData Jval;

union UnionData new_i(int);
union UnionData new_f(float);
union UnionData new_s(char *);

#endif