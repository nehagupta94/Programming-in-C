#ifndef VECTOR_H_FILE
#define VECTOR_H_FILE
#include "data.h"


typedef struct Vector{
	int current_size;
	int max_size;
	Data * data;
	void (*insert) (struct Vector * v, int index, Data d);
	Data * (*read) (struct Vector * v, int index);
	void (* remove) (struct Vector * v, int index);
	void (* delete) (struct Vector * v);
}Vector;

Vector * newVector();
void insertVector(struct Vector * v,int index, Data d);
Data * readVector(struct Vector * v, int index);
void removeVector(struct Vector * v, int index);
void deleteVector(struct Vector * v);

#endif