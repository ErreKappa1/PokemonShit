#ifndef _gardevoir_H_
#define _gardevoir_H_

struct{
	Stats data;
	int key;
	struct Node *next;
} Node;

struct Node *head=NULL;

struct Node *current=NULL;

void printList();//display the list

#endif
