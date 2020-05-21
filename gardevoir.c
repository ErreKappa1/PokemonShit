#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gardevoir.h"


void helloWorldFn(){
	printf("\n\nHelloWorld!\n\n");
}


void printDbFn(Pokemon *db, int nr, int debug){

	int i;//random index name

	if(debug)
		printf("\nBeginning printDbFn");
	for(i=0; i<nr; i++)
			printf("\nRow:%d |%d\t|%s\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%s\t|\tStill Elegible: %d|", i, db[i].id, db[i].name, db[i].type1, db[i].type2, db[i].stats.hp, db[i].stats.atk, db[i].stats.def, db[i].stats.spAtk, db[i].stats.spDef, db[i].stats.spd, db[i].gen, db[i].legg, db[i].read);

}


void printPkmnNameFn(Pokemon *db, int nr, int debug, char goalPkmn[]){

	int i;//random index name

	if(debug)
		printf("\nBeginning printPkmnName");
	for(i=0; i<nr; i++)
		if(strcmp(db[i].name, goalPkmn)==0)
			printf("\n|%d\t|%s\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%s\t|", db[i].id, db[i].name, db[i].type1, db[i].type2, db[i].stats.hp, db[i].stats.atk, db[i].stats.def, db[i].stats.spAtk, db[i].stats.spDef, db[i].stats.spd, db[i].gen, db[i].legg);
}
