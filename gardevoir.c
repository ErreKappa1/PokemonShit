#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gardevoir.h"


void helloWorldFn(){
	printf("\n\nHelloWorld!\n\n");
}


int loadFileFn(Pokemon **db, char fileName[], int debug){

	FILE *fp;//pointer to file
	int nr=0;//number of rows
	int index;//itteration index, permit the scanning of every row

	if(debug)
		printf("\nBeginning loadFileFn, %s as fileName", filename);
	fp=fopen(fileName, "r");//file opening
	if(fp==NULL){//check if the file actually exist
		printf("\nThe file does not exist");
		return -1;
	}
	fscanf(fp,  "%d", &nr);//scanning for the number of total rows of the file
	if(debug)
		printf("\nNumber of detected rows: %d", nr);
	*db=malloc(nr*sizeof(Pokemon));//dynamic memory allocation
	if(debug)//debug
		printf("\nMemory allocation fine");
	while(fscanf(fp, "%d %s %s %s %d %d %d %d %d %d %d %s", &(*db)[index].id, (*db)[index].name, (*db)[index].type1, (*db)[index].type2, &(*db)[index].stats.hp, &(*db)[index].stats.atk, &(*db)[index].stats.def, &(*db)[index].stats.spAtk, &(*db)[index].stats.spDef, &(*db)[index].stats.spd, &(*db)[index].gen, (*db)[index].legg)!=EOF){//data scanning mechanism
		index++;
	}
	if(debug)
		printf("\nPopulation done, %d rows completed", index);

	return nr;
}



void printDbFn(Pokemon *db, int nr, int debug){

	int i;//random index name

	if(debug)
		printf("\nBeginning printDbFn");
	for(i=0; i<nr; i++)
			printf("\nRow:%d |%d\t|%s\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%s\t|", i, db[i].id, db[i].name, db[i].type1, db[i].type2, db[i].stats.hp, db[i].stats.atk, db[i].stats.def, db[i].stats.spAtk, db[i].stats.spDef, db[i].stats.spd, db[i].gen, db[i].legg);

}



void printPkmnName(Pokemon *db, int nr, int debug, char goalPkmn[]){

	int i;//random index name

	if(debug)
		printf("\nBeginning printPkmnName");
	for(i=0; i<nr; i++)
		if(strcmp(db[i].name, goalPkmn)==0)
			printf("\n|%d\t|%s\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%s\t|", db[i].id, db[i].name, db[i].type1, db[i].type2, db[i].stats.hp, db[i].stats.atk, db[i].stats.def, db[i].stats.spAtk, db[i].stats.spDef, db[i].stats.spd, db[i].gen, db[i].legg);
}
