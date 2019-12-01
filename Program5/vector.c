#ifndef VECTOR_C_FILE
#define VECTOR_C_FILE
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector * newVector(){
	Vector * vector = malloc(sizeof(Vector)+1);
	vector->current_size = vector->max_size = 0;
	vector->data = NULL;
	vector->insert = insertVector;
	vector->read = readVector;
	vector->remove = removeVector;
	vector->delete = deleteVector;
	return vector;
}

void insertVector(struct Vector * vector,int index, Data value){
	if(index >= vector->max_size){
		vector->max_size = index * 2+1;
		Data * new = malloc(sizeof(Data) * vector->max_size);
		memset(new, -1, sizeof(Data)*vector->max_size);
		memcpy(new,vector->data, (sizeof(Data) * vector->current_size));
		free(vector->data); 
		vector->data = NULL;
		vector->data = new;
	}
	vector->data[index] = value;
	if(index >= vector->current_size){
		vector->current_size = index+1;
	}
	
}

Data * readVector(struct Vector * vector, int index){	
	if(index < vector->current_size){
		for(int i=0,count=0; i<vector->current_size;i++,count++){ 
			if(count == index){
				return &(vector->data[i]);
			}
		}
	}
	else
		return NULL;

	return NULL;
}

void removeVector(struct Vector * vector, int index){
    if(index < vector->current_size){
        Data * temp = malloc(sizeof(Data)*vector->max_size);
        memcpy(temp,vector->data,sizeof(Data)*index);
        memcpy(temp+index,vector->data+index+1,sizeof(Data)*(vector->current_size-index));
        free(vector->data);
        vector->data=NULL;
        vector->data=temp;
        vector->current_size = vector->current_size - 1;
    }
 
}

void deleteVector(struct Vector * vector){
	free(vector->data);
	vector->data=NULL;
	free(vector);
	vector=NULL;
}

#endif