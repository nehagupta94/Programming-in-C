#ifndef BST_H_FILE
#define BST_H_FILE

typedef struct data{
	int value;
}Data;


typedef struct node{
	Data data;
	struct node *left;
	struct node *right;
	struct node *parent;
}Node;


typedef struct tree{
	
	Node *root;
	
	Data *(*insert)(struct tree *, Data);
	Data *(*search)(struct tree *, Data);
	struct tree *(*clone)(struct tree *);
	void (*sort)(struct tree *, Data *);
	void (*removeData)(struct tree *, Data);
	void (*delete)(struct tree*);
	int (*compare)(struct tree *, struct tree *);
	
}Tree;


Node *newNode(Data , Node *);
Data *searchNode(Node *, Data);
Node *rightMin(Node *);

Tree *newTree();
Tree *clone(Tree *);

Data *insert(Tree *, Data);
Data *search(Tree *, Data);
Data * insertNode(Node * n, Data d);

void cloneTree(Node *, Tree *);
void shortCircuit(Node *);
void sort(Tree *, Data *);
int inOrderTransversal(Node *, Data *,int);
void promotion(Node *);
void removeLeafNode(Node *);
void removeTree(Tree *, Data);
void deleteNode(Node *);
void deleteTree(Tree *);
void deleteNodes(Node *);
void freeNode(Node * );

int sortTree(Node *, Data *, int);
int compare(Tree *, Tree*);
int compareTwoTree(Node *, Node *);


#endif