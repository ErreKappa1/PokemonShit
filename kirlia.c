#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "megaGardevoir.h"
#include "gardevoir.h"


void globalAverageFn(Pokemon *db, int nr, int debug){

	Stats currentAvg;//average value of pokemon in the current generation
	int i=0;//cycle index
	int currentGen=1;//current generation during processing
	int numPkmnPerGen=0;//number of pokemon in the current generation

	if(debug){
		printf("Beginning of globalAverageFn\n");
		printf("\nPrint before\n");
		printPkmnStatsFn(currentAvg, debug);
	}
	setPkmnStatsToZeroFn(&currentAvg, debug);//set currentAvg to 0
	if(debug){
		printf("\nPrint after\n");
		printPkmnStatsFn(currentAvg, debug);
	}
	if(debug)
		printPkmnStatsFn(currentAvg, debug);
	for(i=0; i<nr; i++){//cycle on every given pokemon
		currentAvg=addPkmnStatsFn(currentAvg, db[i].stats, debug);//act as an accumulator of every stat, evaluate AVGs
		numPkmnPerGen++;//count the number of pokemon per generation
		if(db[i].gen==currentGen+1 || i==(nr-1)){//print condition, once per gen
			currentAvg=divPkmnStatsByNumFn(currentAvg, numPkmnPerGen, debug);//update the current avg before printing
			printf("\nNumber of pokemon prensent in the %d generation:\t%d", currentGen, numPkmnPerGen);
			printf("\nAvg values:");
			printPkmnStatsFn(currentAvg, debug);
			printf("\n");
			setPkmnStatsToZeroFn(&currentAvg, debug);//resetting every accumulator and counter
			currentGen++;//updating generatuion index
			numPkmnPerGen=0;//reset the number of pokemo per gen
		}
	}
	printf("\nTotal analyzed Pokemon: %d", i);
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

