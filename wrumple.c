#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "megaGardevoir.h"
#include "wrumple.h"

void printNode(Node_t *current){
	
	printf("\nID=%d\t", current->id);
	printf("Hp=%d\t", current->data.hp);
	printf("Atk=%d\t", current->data.atk);
	printf("Def=%d\t", current->data.def);
	printf("spAtk=%d\t", current->data.spAtk);
	printf("spDef=%d\t", current->data.spDef);
	printf("Spd=%d\t", current->data.spd);

}


void printList(Node_t *head){

	Node_t *current=head;

	while(current!=NULL){
		printNode(current);
		current=current->next;
	}
}


void pushBeg(Node_t **head, Stats date){

	Node_t *newHead;
	
	newHead=(Node_t *) malloc(sizeof(Node_t));
	newHead->id=0;
	newHead->data.hp=date.hp;
	newHead->data.atk=date.atk;
	newHead->data.spAtk=date.spAtk;
	newHead->data.def=date.def;
	newHead->data.spDef=date.spDef;
	newHead->data.spd=date.spd;
	newHead->next=*head;
	*head=newHead;
}


void pushEnd(Node_t *head, Stats date){

	Node_t *current=head;

	while(current->next!=NULL)
		current=current->next;
	current->next=(Node_t *) malloc(sizeof(Node_t));
	current->next->id=current->id;
	current->next->data.hp=date.hp;
	current->next->data.atk=date.atk;
	current->next->data.spAtk=date.spAtk;
	current->next->data.def=date.def;
	current->next->data.spDef=date.spDef;
	current->next->data.spd=date.spd;
	current->next->next=NULL;
}


void popBeg(Node_t **head){

	Node_t *newHead=NULL;

	newHead=(*head)->next;
	free(*head);
	*head=newHead;
}
	

void popEnd(Node_t **head){

	Node_t *current=*head;

	if(current->next==NULL)
		*head=NULL;

	while(current->next->next!=NULL)
		current=current->next;
	free(current->next);
	current->next=NULL;
}


void removeByID(Node_t **head, int delId){

	Node_t *temp=NULL;
	Node_t *current=*head;

	if(current->id==delId){
		popBeg(head);
		return;
	}

	while(current->next!=NULL)
		if(current->id==delId)
			current->next=temp;

	free(current->next);
	current->next=temp->next;
	free(temp);
}
