#ifndef LIST_C_FILE
#define LIST_C_FILE
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List * newList(){
	List * list = malloc(sizeof(List));
	list->head = list->tail = NULL;
	list->insert = insertList;
	list->read = readData;
	list->delete = deleteList;
	list->remove = removeData;
	return list;
}

void insertList(List * list, int index, Data value){
	Node * new_node = malloc(sizeof(Node));
	new_node->data = value;
	new_node->next = new_node->prev =NULL;

	if(list->head == NULL)
	{	
		list->head = new_node;
		list->tail = list->head;
	}
	else
	{
		list->tail->next = new_node;
		new_node->data =value;
		new_node->prev=list->tail;
		new_node->next=NULL;
		list->tail=list->tail->next;
	}
}

Data * readData(List * list, int index){
	if(list->head==NULL) {
        return NULL;
    }

	Node * temp = list->head;
	int count = 0;
	while(temp->next != NULL){
		if(count == index){
			return &temp->data;
		}
		count++;
		temp = temp->next;
	}

	return NULL;
}

void removeData(List * list, int index){
	Node * head_node = list->head;
	Node * delete_node = list->head;
	int count = 0;

	if(list->head == NULL) {
        return;
    }

    if(list->head == list->tail){
		free(head_node);
		list->head = list->tail = NULL;
		return;
	}

	if(head_node == delete_node){
		head_node = delete_node->next;
		list->head = head_node;
		return;
	}

	while(delete_node != NULL){

		if(count == index){

			if(delete_node->next == NULL){
				list->tail = delete_node->prev; 
			}

			if(delete_node->next != NULL){
				delete_node->next->prev = delete_node->prev;
			}

			if(delete_node->prev != NULL){
				delete_node->prev->next = delete_node->next;
			}

			free(delete_node);
			break;

		}
		count++;
		delete_node = delete_node->next;
	}
}

void deleteList(List * list){
	free(list);
	list = NULL;
}

#endif