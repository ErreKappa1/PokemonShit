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
		statistics,
		exit
} mainMenu

mainMenu readCommand();//prompt to the user and read the command from stdin

#endif
