#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gardevoir.h"

void helloWorldFn(){
	printf("\nHelloWorld!\n");
}

/*
int loadFileFn(Pokemon **db, char fileName[], int debug){

	FILE *fp;//pointer to file
	int nr=0;//number of rows
	int index;//itteration index, permit the scanning of every row
	char temp[5+1] = {0};//stores temporanely the string TRUE/FALSE to convert it into bool

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
	*db=calloc(nr, sizeof(Pokemon));//dynamic memory allocation
	if(debug)//debug
		printf("\nMemory allocation into file load fn is fine");
	while(fscanf(fp, "%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s", &(*db)[index].id, (*db)[index].name, (*db)[index].type1, (*db)[index].type2, &(*db)[index].stats.hp, &(*db)[index].stats.atk, &(*db)[index].stats.def, &(*db)[index].stats.spAtk, &(*db)[index].stats.spDef, &(*db)[index].stats.spd, &(*db)[index].gen, (*db)[index].legg)!=EOF){//data scanning mechanism
		index++;
		if(debug)
			printf("\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d", (*db)[index].id, (*db)[index].name, (*db)[index].type1, (*db)[index].type2, (*db)[index].stats.hp, (*db)[index].stats.atk, (*db)[index].stats.def, (*db)[index].stats.spAtk, (*db)[index].stats.spDef, (*db)[index].stats.spd, (*db)[index].gen, (*db)[index].legg);
	}
	if(debug)
		printf("\nPopulation done");

	return nr;
}
*/

int loadFileFn(Pokemon **db, char fileName[], int debug){

	FILE *fp;//pointer to file
	int nr=0;//number of rows
	int index;//itteration index, permit the scanning of every row
	Pokemon *dex=NULL;

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
		printf("\nNumber of rows: %d", nr);
	dex=calloc(nr, sizeof(Pokemon));//dynamic memory allocation
	if(debug)//debug
		printf("\nMemory allocation into file load fn is fine");
	while(fscanf(fp, "%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s", &dex[index].id, dex[index].name, dex[index].type1, dex[index].type2, &dex[index].stats.hp, &dex[index].stats.atk, &dex[index].stats.def, &dex[index].stats.spAtk, &dex[index].stats.spDef, &dex[index].stats.spd, &dex[index].gen, dex[index].legg)!=EOF){//data scanning mechanism
		index++;
		if(debug)
			printf("\n%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t\tIndex:%d", dex[index].id, dex[index].name, dex[index].type1, dex[index].type2, dex[index].stats.hp, dex[index].stats.atk, dex[index].stats.def, dex[index].stats.spAtk, dex[index].stats.spDef, dex[index].stats.spd, dex[index].gen, dex[index].legg);
	}
	if(debug)
		printf("\nPopulation done");

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
