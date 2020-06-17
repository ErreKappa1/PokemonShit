#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gardevoir.h"


void helloWorldFn(){
	printf("\n\nHelloWorld!\n\n");
}


void printPkmnFn(Pokemon var, int debug){

	if(debug)
		printf("\nBeginning printPkmnFn");
	printf("\n|%d\t|%s\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%s\t|\tStill Elegible: %d|", var.id, var.name, var.type1, var.type2, var.stats.hp, var.stats.atk, var.stats.def, var.stats.spAtk, var.stats.spDef, var.stats.spd, var.gen, var.legg, var.read);
}


void printDbFn(Pokemon *db, int nr, int debug){

	int i;//random index name
	Pokemon var;

	if(debug)
		printf("\nBeginning printDbFn");
	for(i=0; i<nr; i++){
		var=db[i];
		printPkmnFn(var, debug);
	}
}


void printPkmnNameFn(Pokemon *db, int nr, int debug, char goalPkmn[]){

	int i;//random index name

	if(debug)
		printf("\nBeginning printPkmnName");
	for(i=0; i<nr; i++)
		if(strcmp(db[i].name, goalPkmn)==0){
			printPkmnFn(db[i], debug);		
			break;
		}
}


void setToZeroPkmnFn(Pokemon *var, int debug){
	&(*var).id=0;
	strcpy((*var).name, "");
}
