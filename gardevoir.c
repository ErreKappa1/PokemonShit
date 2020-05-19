#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gardevoir.h"


void helloWorldFn(){
	printf("\nHelloWorld!\n");
}


int loadFileFn(Pokemon **db, char fileName[], int debug){

	FILE *fp;//pointer to file
	int nr=0;//number of rows
	int index;//itteration index, permit the scanning of every row

	if(debug)
		printf("\nBeginning loadFileFn");
	fp=fopen(fileName, "r");//file opening
	if(fp==NULL){//check if the file actually exist
		printf("\nThe file does not exist");
		return -1;
	}else if(debug){
		printf("\nLocated file");
	}
	fscanf(fp,  "%d", &nr);//scanning for the number of total rows of the file
	if(debug)
		printf("\nNumber of detected rows: %d", nr);
	*db=calloc(nr, sizeof(Pokemon));//dynamic memory allocation
	if(debug)//debug
		printf("\nMemory allocation fine");
	while(fscanf(fp, "%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s", &(*db)[index].id, (*db)[index].name, (*db)[index].type1, (*db)[index].type2, &(*db)[index].stats.hp, &(*db)[index].stats.atk, &(*db)[index].stats.def, &(*db)[index].stats.spAtk, &(*db)[index].stats.spDef, &(*db)[index].stats.spd, &(*db)[index].gen, (*db)[index].legg)!=EOF || index==nr-1){//data scanning mechanism
		index++;
		if(debug)
			printf("\nRow:%d Values: %d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s", index, (*db)[index].id, (*db)[index].name, (*db)[index].type1, (*db)[index].type2, (*db)[index].stats.hp, (*db)[index].stats.atk, (*db)[index].stats.def, (*db)[index].stats.spAtk, (*db)[index].stats.spDef, (*db)[index].stats.spd, (*db)[index].gen, (*db)[index].legg);
	}
	if(debug)
		printf("\nPopulation done, %d rows completed", index);

	return nr;
}


/*
void printDbFn(Pokemon *db, int nr, int debug){

	int i;

	if(debug)
		printf("\nBeginning printDbFn");
	for(i=0; i<nr; i++)
			printf("\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s", &(*db)[index].id, (*db)[index].name, (*db)[index].type1, (*db)[index].type2, &(*db)[index].stats.hp, &(*db)[index].stats.atk, &(*db)[index].stats.def, &(*db)[index].stats.spAtk, &(*db)[index].stats.spDef, &(*db)[index].stats.spd, &(*db)[index].gen, (*db)[index].legg);
}
*/
