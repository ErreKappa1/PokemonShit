#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "megaGardevoir.h"


void helloWorldFn(){
	printf("\n\nHelloWorld!\n\n");
}


void printPkmnFn(Pokemon var, int debug){

	if(debug)
		printf("\nBeginning printPkmnFn");
	printf( "\n|%d\t|%s\t|%s\t|%s"//id, name, types
			"\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d"//stats
			"\t|%d\t|%s\t|\tStill Elegible: %d|",//gen, legg, read 
			var.id, var.name, var.type1, var.type2, 
			var.stats.hp, var.stats.atk, var.stats.def, var.stats.spAtk, var.stats.spDef, var.stats.spd, 
			var.gen, var.legg, var.read);
}

void setPkmnToZeroFn(Pokemon *var, int debug){

	if(debug)
		printf("\nBeginning setPkmnToZeroFn");
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


void printPkmnStatsFn(Stats var, int debug){
	
	if(debug)
		printf("\nBeginning printPkmnStatsFn");
	printf("\n|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|", var.hp, var.atk, var.def, var.spAtk, var.spDef, var.spd);
}


void setPkmnStatsToZeroFn(Stats *var, int debug){
	
	if(debug)
		printf("\nBeginning setPkmnStatsToZeroFn");
	(*var).hp=0;
	(*var).atk=0;
	(*var).def=0;
	(*var).spAtk=0;
	(*var).spDef=0;
	(*var).spd=0;
}


Stats addPkmnStatsFn(Stats first, Stats second, int debug){

	Stats sum;

	if(debug)
		printf("\nBeginning addPkmnStatsFn");
	sum.hp=first.hp+second.hp;
	sum.atk=first.atk+second.atk;
	sum.def=first.def+second.def;
	sum.spAtk=first.spAtk+second.spAtk;
	sum.spDef=first.spDef+second.spDef;
	sum.spd=first.spd+second.spd;

	return sum;
}


Stats divPkmnStatsByNumFn(Stats first, int second, int debug){

	Stats div;

	if(debug)
		printf("Beginning divPkmnStatsByNumFn");
	div.hp=first.hp/second;
	div.atk=first.atk/second;
	div.def=first.def/second;
	div.spAtk=first.spAtk/second;
	div.spDef=first.spDef/second;
	div.spd=first.spd/second;

	return div;
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
