#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gardevoir.h"

#define nTypes 18//number of different pokemon types

int loadPkmnFn(Pokemon **db, char fileName[], int debug){

	//loading Types:
	FILE *fp0;//pointer to types
	int index0=0;//index to acquire the list of available pokemon types
	char types[nTypes][8+1];//array that will contain every possible pokemon type

	//loading Pokemon_data:
	FILE *fp1;//pointer to pokemon data
	int nr=0;//number of rows
	int index1=0;//data acquiring mechanism main for index
	char temp[30+1];//buffer to manage the multi-string names
	int flag0=1;//data acquiring mechanism main while
	int i=0;//data acquiring mechanism second for
	int flag1=0;//data acquiring mechanism first if
	int tempPostConv;//same buffer after a conversion using atoi

	if(debug)
		printf("\nBeginning loadFileFn");
	fp0=fopen("types.txt", "r");//opening the types file
	if(fp0==NULL){//check if the file actually exist
		printf("\nThe file does not exist");
		return -1;
	}
	if(debug)
		printf("\nNumber of detected rows: %d", nTypes);
	while(fscanf(fp0, "%s", types[index0])!=EOF){//scanning for pokemon types
		index0++;
	}
	if(debug)
		printf("\nAquired %d lines from types.txt", index0);//end of types loading
	fp1=fopen(fileName, "r");//opening the pokemon_data file____________________________________________________________
	if(fp1==NULL){//check if the file actually exist
		printf("\nThe file does not exist");
		return -1;
	}
	fscanf(fp1, "%d", &nr);//scanning for the number of total rows of the file
	if(debug)
		printf("\nNumber of detected rows: %d", nr);
	*db=calloc(nr, sizeof(Pokemon));//dynamic memory allocation
	if(debug)
		printf("\nMemory allocation fine");
	strcpy(temp, "");//reset temp buffer to 0
	for(index1=0; index1<nr; index1++){//repear every on every row
		fscanf(fp1, "%d\t%s\t", &(*db)[index1].id, (*db)[index1].name);//scan the first section of the row
		while(flag0){
			fscanf(fp1, "%s\t", temp);//aquire a string to test if it's a type or a part of the name
			for(i=0; i<nTypes; i++)
				if(strcmp(types[i], temp)!=0){//if this string is a type the name is only one string long, else is >2
					flag1=0;//types!=tmp
				}else{
					flag1=1;//types=tmp
					break;
				}
			if(flag1){
				strcpy((*db)[index1].type1, temp);//types=tmp
				flag0=0;
			}else{
				strcat((*db)[index1].name, " ");
				strcat((*db)[index1].name, temp);//types!=tmp
				flag1=0;
			}
			strcpy(temp, "");//reset temp buffer to 0
		}
		flag0=1;
		flag1=0;
		fscanf(fp1, "%s\t", temp);
		tempPostConv=atoi(temp);
		if(tempPostConv){//return 0 if the conversion is not possible
			strcpy((*db)[index1].type2, "Null");
			(*db)[index1].stats.hp=tempPostConv;
			fscanf(fp1, "%d\t%d\t%d\t%d\t%d\t%d\t%s", &(*db)[index1].stats.atk, &(*db)[index1].stats.def, &(*db)[index1].stats.spAtk, &(*db)[index1].stats.spDef, &(*db)[index1].stats.spd, &(*db)[index1].gen, (*db)[index1].legg);//scan the last part of the row
		}else{//string
			strcpy((*db)[index1].type2, temp);
			fscanf(fp1, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s", &(*db)[index1].stats.hp, &(*db)[index1].stats.atk, &(*db)[index1].stats.def, &(*db)[index1].stats.spAtk, &(*db)[index1].stats.spDef, &(*db)[index1].stats.spd, &(*db)[index1].gen, (*db)[index1].legg);//scan the last part of the row
		}
		if(debug)
			printf("\n|%d\t|%s\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%s\t|", (*db)[index1].id, (*db)[index1].name, (*db)[index1].type1, (*db)[index1].type2, (*db)[index1].stats.hp, (*db)[index1].stats.atk, (*db)[index1].stats.def, (*db)[index1].stats.spAtk, (*db)[index1].stats.spDef, (*db)[index1].stats.spd, (*db)[index1].gen, (*db)[index1].legg);
	}
	if(debug)
		printf("\nPopulation done, %d rows completed", index1);

	return nr;
}
