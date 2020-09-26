#ifndef LIST_H_FILE
#define LIST_H_FILE
#include "data.h"
/*typedef struct Data{
	int value;
}Data;*/

typedef struct Node{
	Data data;
	struct Node * next, * prev;
}Node;

typedef struct List{
	Node * head, * tail;
	void (*insert)(struct List *, int , Data );
	Data *(*read)(struct List *, int );
	void (*remove)(struct List *, int );
	void (*delete)(struct List *);
}List;

List * newList();
void insertList(List * , int , Data );
void deleteList(List * );
Data * readData(List * , int );
void removeData(List * , int );

#endif