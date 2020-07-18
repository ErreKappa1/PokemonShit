#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "megaGardevoir.h"
#include "gardevoir.h"

/*
void printList(){

   struct Node *ptr=head;
   printf("\n[ ");
	
   while(ptr!=NULL){//start from the beginning
      printf("(%d,%d) ", ptr->key, ptr->data);
      ptr=ptr->next;
   }
   printf(" ]");
}
*/

mainMenu readCommand(){//TODO write dat function

	char string[10+1];//store the command submitted by the user
	char optionsTable[5][10+1];//contains every possible option that the user can submit

	
