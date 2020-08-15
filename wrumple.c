#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "megaGardevoir.h"
#include "wrumple.h"

void printNodeFn(Node_t *current){
	
	printf("\nID=%d\t", current->id);
	printf("Hp=%d\t", current->data.hp);
	printf("Atk=%d\t", current->data.atk);
	printf("Def=%d\t", current->data.def);
	printf("spAtk=%d\t", current->data.spAtk);
	printf("spDef=%d\t", current->data.spDef);
	printf("Spd=%d\t", current->data.spd);

}


void printListFn(Node_t *head){

	Node_t *current=head;

	while(current!=NULL){//itterate on the list until the current node reach the end
		printNodeFn(current);
		current=current->next;
	}
}


void pushBegFn(Node_t **head, Stats date){

	Node_t *newHead;
	
	newHead=(Node_t *) malloc(sizeof(Node_t));//newNode allocation
	newHead->id=0;//set the id of the first node to 0, then populate the node using the second parameter
	newHead->data.hp=date.hp;
	newHead->data.atk=date.atk;
	newHead->data.spAtk=date.spAtk;
	newHead->data.def=date.def;
	newHead->data.spDef=date.spDef;
	newHead->data.spd=date.spd;
	newHead->next=*head;
	*head=newHead;//assign the head to newHead->next, so it becomes the second node of the list
}


void pushEndFn(Node_t **head, Stats date){

	Node_t *current=*head;
	int flag=1;

	if(current==NULL){//if the list is empty, it call pushBegFn to create the first node of the list
		pushBegFn(head, date);
		flag=0;
	}

	if(flag){
		while(current->next!=NULL)//reach the end of the list
			current=current->next;
		current->next=(Node_t *) malloc(sizeof(Node_t));//allocate the new node
		current->next->id=current->id+1;//set the id to id of the last element of the list + 1, and populate 
		current->next->data.hp=date.hp;//the list using the second parameter of the function
		current->next->data.atk=date.atk;
		current->next->data.spAtk=date.spAtk;
		current->next->data.def=date.def;
		current->next->data.spDef=date.spDef;
		current->next->data.spd=date.spd;
		current->next->next=NULL;//set newNode->next to null to close the list
	}
}


void popBegFn(Node_t **head){

	Node_t *newHead=NULL;

	newHead=(*head)->next;//save the pointer to the secon node
	free(*head);//free the first node
	*head=newHead;//set the head to the second node
}
	

void popEndFn(Node_t **head){

	Node_t *current=*head;

	if(current->next==NULL)//check if the lisst contains just one elment, in that case it free the head
		*head=NULL;

	while(current->next->next!=NULL)//cycle through the list reaching the element before the last
		current=current->next;
	free(current->next);//free the last element
	current->next=NULL;//set the end of the list
}


void removeByIDFn(Node_t **head, int delId){

	Node_t *temp=NULL;
	Node_t *current=*head;

	if(current->id==delId){//check if the head is the selected item
		popBegFn(head);
		return;
	}

	while(current->next!=NULL)//cycle trought the list. until the end
		if(current->id==delId){//check if the current node id is equal to the selected one 
			current->next=temp;
			break;
		}

	free(current->next);
	current->next=temp->next;
	free(temp);
}
