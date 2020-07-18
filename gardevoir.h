#ifndef _gardevoir_H_
#define _gardevoir_H_

/* list function and structure
struct{
	Stats data;
	int key;
	struct Node *next;
} Node;

struct Node *head=NULL;

struct Node *current=NULL;

void printList();//display the list
*/

typedef enum{
		printAll,
		selectPkmn,
		printPkmnm,
		statistics
} mainMenu

mainMenu readCommand();//read the command from stdin

#endif
