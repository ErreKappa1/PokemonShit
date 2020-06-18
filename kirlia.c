#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gardevoir.h"


void globalAverageFn(Pokemon *db, int nr, int debug){

	Pokemon currentAvg;//average value of pokemon in the current generation
	int pokemonPerGeneration=0;//number of pokemon in the current generation
	int i=0;//cycle index
	int currentGen=1;//current generation during processing

	if(debug){
		printf("Beginning of globalAverage\n");
		printf("\nPrint before");
		printPkmnFn(currentAvg, debug);
	}
	setToZeroPkmnFn(&currentAvg, debug);
	if(debug)
		printPkmnFn(currentAvg, debug);
	numGenerations=db[nr].gen;
	for(i=0; i<nr; i++){
		
		if(db[i].gen=currentGen+1){
			printf("\nNumber of pokemon prensent in the %d generation:\t%d", currentGen
			setToZeroPkmnFn(&currentAvg, debug);
		}
}


void subMenuWrapperStatsFn(Pokemon *db, int nr, int debug){

	int stop=1;//flag to manage exit from stats menu
	int command=0;//switch case flag

	if(debug)
		printf("Beginning of subMenuWrapperStatsFn\n");
	while(stop){
		printf("\nInsert a command:\n1)\tAverage statistics per generation\n0)\tReturn to main menu\n--------------------------------------------------------------\n\n\n");
		scanf("%d", &command);
		printf("\n\n");
		switch(command){
			case 1:
				system(clear);
				globalAverageFn(db, nr, debug);//compute global statistics per generation
				printf("\n");
				system(sleep);
				system(clear);
			break;
			case 0://Exit the program
				system(clear);
				stop=0;
			break;
		}
	}
}

