#ifndef _wrumple_H_
#define _wrumple_H_

typedef struct Node{
	Stats data;
	int id;
	struct Node *next;
} Node_t;

void printNode(Node_t *current);
void printList(Node_t *head);
void pushBeg(Node_t **head);
void pushEnd(Node_t *head, Stats date);
void popBeg(Node_t **head);
void popEnd(Node_t **head);
void removeByID(Node_t **head, int delId);

#endif
