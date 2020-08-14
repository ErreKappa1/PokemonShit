#ifndef _wrumple_H_
#define _wrumple_H_

typedef struct Node{
	Stats data;
	int id;
	struct Node *next;
} Node_t;

void printNodeFn(Node_t *current);//print a single node of the list
void printListFn(Node_t *head);//print the all list using the printNode func
void pushBegFn(Node_t **head, Stats date);//push a newNode to the beginning of the list
void pushEndFn(Node_t **head, Stats date);//push a newNode to the end of the list
void popBegFn(Node_t **head);//pop a node from the beginning of the lista, and set the new head to the second node
void popEndFn(Node_t **head);//pop a node from the endo of the list, manage lists of oly one element
void removeByIDFn(Node_t **head, int delId);//pop a node, based on his id

#endif
