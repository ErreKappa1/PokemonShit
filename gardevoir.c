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


void setPkmnToZeroFn(Pokemon *var, int debug){

	if(debug)
		printf("\nBeginning setToZeroPkmnFn");
	(*var).id=0;
	strcpy((*var).name, "");
	strcpy((*var).type1, "");
	strcpy((*var).type2, "");
	(*var).stats.hp=0;
	(*var).stats.atk=0;
	(*var).stats.def=0;
	(*var).stats.spAtk=0;
	(*var).stats.spDef=0;
	(*var).stats.spd=0;
	(*var).gen=0;
	strcpy((*var).legg, "");
	(*var).read=0;
}


Pokemon addPkmnValuesFn(Pokemon first, Pokemon second, int debug){

	Pokemon sum;

	if(debug)
		printf("\nBeginning addPkmnValuesFn");
	sum.stats.hp=first.stats.hp+second.stats.hp;
	sum.stats.atk=first.stats.atk+second.stats.atk;
	sum.stats.def=first.stats.def+second.stats.def;
	sum.stats.spAtk=first.stats.spAtk+second.stats.spAtk;
	sum.stats.spDef=first.stats.spDef+second.stats.spDef;
	sum.stats.spd=first.stats.spd+second.stats.spd;

	return sum;
}
