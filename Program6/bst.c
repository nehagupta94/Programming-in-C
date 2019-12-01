#ifndef BST_C_FILE
#define BST_C_FILE
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *newNode(Data data, Node * parent)
{
	Node *node = malloc(sizeof(Node));
	node -> left = NULL;
	node -> right = NULL;
	node -> parent = parent;
	node -> data = data;
	return node;
}

Tree *newTree()
{
	Tree *tree = malloc(sizeof(Tree));
	tree -> root = NULL;
	tree -> insert = insert;
	tree -> search = search;
	tree -> sort = sort;
	tree -> clone = clone;
	tree -> compare = compare;
	tree -> delete = deleteTree;
	tree -> removeData = removeTree;
	return tree;
}

Data * insert(Tree * tree, Data data){
	if(tree->root == NULL){
		tree->root = newNode(data,NULL);
		return &(tree->root->data);
	}
	else{
		Data * temp = insertNode(tree->root,data);
		return temp;
	}
}

Data * insertNode(Node * n, Data d){
	if(d.value < n->data.value){
		if(n->left == NULL){
			n->left = newNode(d,n);
			return &(n->left->data);
		}
		else{
			insertNode(n->left,d);
		}
	}
	else if(d.value > n->data.value){
		if(n->right == NULL){
			n->right = newNode(d,n);
			return &(n->right->data);
		}
		else{
			insertNode(n->right,d);
		}
	}
	else if(d.value == n->data.value){
		return NULL;
	}
}

void sort(Tree *tree, Data *data)
{
	int index = 0;
	if(tree -> root != NULL)
		index = inOrderTransversal(tree -> root, data, index);
}

int inOrderTransversal(Node *node, Data *data, int index)
{
	if(node != NULL)
	{
		index = inOrderTransversal(node -> left, data,index);
		data[index] = node -> data;
		index++;
		index = inOrderTransversal(node -> right, data,index);
	}
	return index;
}

Data *search(Tree *tree, Data data)
{
	if(tree->root == NULL)
		return NULL;
	else
		return searchNode(tree->root, data);
}

Data *searchNode(Node *node, Data d)
{
	if(node -> data.value == d.value)
		return &(node->data);
	if(node == NULL)
		return &(node->data);
	if(node -> data.value < d.value)
	{
		if(node->right == NULL)
      		return NULL;
		return searchNode(node -> right, d);
	}
	else
	{
		if(node->left == NULL)
      		return NULL;
		return searchNode(node -> left, d);
	}
}

Tree *clone(Tree *tree)
{
	if(tree -> root == NULL)
		return NULL;
	else{
		Tree *clonedTree = newTree();
		cloneTree(tree -> root, clonedTree);
		return clonedTree;
	}
}

void cloneTree(Node *node, Tree *tree)
{
	if(node != NULL)
	{
		insert(tree, node -> data);
		cloneTree(node -> left, tree);
		cloneTree(node -> right, tree);
	}
}

int compare(Tree *originalTree, Tree *compareTree)
{
	if(originalTree == NULL && compareTree == NULL)
		return 1;
	if(originalTree == NULL || compareTree == NULL)
		return 0;
	if(originalTree != NULL && compareTree == NULL) 
        return 0; 
    if (originalTree == NULL && compareTree != NULL) 
        return 0; 
	else
		return compareTwoTree(originalTree -> root, compareTree -> root);
}

int compareTwoTree(Node *first, Node *second)
{
	if (first == NULL && second == NULL) 
        return 1;
    else{
    	if (first->data.value == second->data.value && compareTwoTree(first->left, second->left) 
            && compareTwoTree(first->right, second->right)) 
			return 1;
		else
			return 0;
    }
}

void deleteTree(Tree *tree)
{
	if(tree -> root == NULL){
		free(tree->root);
		free(tree);
	}
	else
		deleteNodes(tree -> root);
}

void deleteNodes(Node *node)
{
	if(node == NULL)
		return;
	deleteNodes(node->left);  
    deleteNodes(node->right);
    removeLeafNode(node);
}

void removeTree(Tree *tree, Data data)
{
	Node *toDelete= search(tree, data);
	
	if(toDelete != NULL){
		if(toDelete -> left == NULL && toDelete -> right == NULL){
			if(toDelete == tree -> root){
				free(tree -> root);
				tree -> root = NULL;
			}
			else
				removeLeafNode(toDelete);
		}
		else if(toDelete -> left == NULL || toDelete -> right == NULL){
			if(toDelete == tree -> root){
				if(toDelete -> left == NULL){
					tree -> root = toDelete -> right;
					toDelete -> right = NULL;
				}
				else if(toDelete -> right == NULL){
					tree -> root = toDelete -> left;
					toDelete -> left = NULL;
				}
				freeNode(toDelete);
			}
			else
				shortCircuit(toDelete);
		}
		else
			promotion(toDelete);
	}
}

void removeLeafNode(Node *node)
{
	if(node -> parent == NULL)
		freeNode(node);
	else
	{
		if(node == node -> parent -> left)
			node -> parent -> left = NULL;
		else
			node -> parent -> right = NULL;
		freeNode(node);
	}
}

void promotion(Node *node)
{
	Node *nr = rightMin(node);
	node -> data = nr -> data;
	if(nr -> right == NULL)
		removeLeafNode(nr);
	else
		shortCircuit(nr);
}

void freeNode(Node * node){

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  
  free(node->left);
  free(node->right);
  free(node->parent);
  free(node);
}

void shortCircuit(Node *node)
{
	if(node -> parent == NULL){
		if(node -> left == NULL)
			node -> right = NULL;
		else if(node -> right == NULL)
			node -> left = NULL;
		freeNode(node);
	}
	else
	{
		if(node == node -> parent -> left){
			if(node -> right == NULL){
				node -> parent -> left = node -> left;
				node -> left -> parent = node -> parent;
			}
			else if(node -> left == NULL){
				node -> parent -> left = node -> right;
				node -> right -> parent = node -> parent;
			}
		}
		else if(node == node -> parent -> right){
			if(node -> left == NULL){
				node -> parent -> right = node -> right;
				node -> right -> parent = node -> parent;
			}
			else if(node -> right == NULL){
				node -> parent -> right = node -> left;
				node -> left -> parent = node -> parent;
			}
		}
		freeNode(node);
	}
}

Node *rightMin(Node *node)
{
	node = node -> right;
	while(node -> left != NULL){
		node = node -> left;
	}
	return node;
}

#endif