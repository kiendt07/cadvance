#include "jval.h"
#include <string.h>
 
 Jval new_i(int data)
 {
 	Jval tmp;
 	tmp.i=data;
 	return tmp;
 }

 union UnionData new_f(float data)
 {
 	union UnionData tmp; 
 	tmp.f=data;
 	return tmp;
 }

 union UnionData new_s(char *data)
 {
 	union UnionData tmp;
 	strcpy(tmp.s, data);
 	return tmp;
 }

