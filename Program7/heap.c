#ifndef HEAP_C_FILE
#define HEAP_C_FILE

#include"heap.h"
#include<stdio.h>
#include<stdlib.h>

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2

Heap * initHeap(Data * d){
	Heap * heap = malloc(sizeof(Heap));
	heap->data = d;
	heap->current_size = 1000;
	heap->maximum_capacity = 1000;
	heapify(heap);
	return heap;
}

void * heapify(Heap * h){
	for(int i = ((h->current_size) / 2 ) - 1; i >= 0; i--)
		siftDown(h,i);
}

void swap(Data *n1, Data *n2) {
    Data temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp ;
}

void siftDown(Heap * hp, int i){
	int smallest = (LCHILD(i) < hp->current_size && hp->data[LCHILD(i)].value < hp->data[i].value) ? LCHILD(i) : i ;
	if(RCHILD(i) < hp->current_size && hp->data[RCHILD(i)].value < hp->data[smallest].value) {
        smallest = RCHILD(i) ;
    }
    if(smallest != i) {
        swap(&(hp->data[i]), &(hp->data[smallest])) ;
        siftDown(hp, smallest) ;
    }
}

Data removePriority(Heap * h){
	Data temp = h->data[0];
	h->data[0] = h->data[h->current_size - 1];
	h->data[h->current_size - 1] = temp;

	h->current_size = h->current_size - 1;
	siftDown(h, 0);

	return h->data[h->current_size];
}

void deleteHeap(Heap * heap){
	free(heap);
	heap = NULL;
}

#endif