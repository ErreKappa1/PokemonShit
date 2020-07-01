#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gardevoir.h"


void globalAverageFn(Pokemon *db, int nr, int debug){

	Pokemon currentAvg;//average value of pokemon in the current generation
	int pokemonPerGeneration=0;//number of pokemon in the current generation
	int i=0;//cycle index
	int currentGen=1;//current generation during processing
	int numPkmnPerGen=0;//number of pokemon in the current generation

	if(debug){
		printf("Beginning of globalAverageFn\n");
		printf("\nPrint before\n");
		printPkmnFn(currentAvg, debug);
	}
	setPkmnToZeroFn(&currentAvg, debug);//set currentAvg to 0
	if(debug){
		printf("\nPrint after\n");
		printPkmnFn(currentAvg, debug);
	}
	currentAvg.read=0;//set to zero the last value of the Pokemon type
	if(debug)
		printPkmnFn(currentAvg, debug);
	for(i=0; i<nr; i++){//cycle on every given pokemon
		currentAvg=addPkmnValuesFn(currentAvg, db[i], debug);//act as an accumulator of every stat, used to evaluate AVGs
		numPkmnPerGen++;//count the number of pokemon per generation
		if(db[i].gen==currentGen+1 ){//print condition, once per gen

			printf("\nNumber of pokemon prensent in the %d generation:\t%d", currentGen, numPkmnPerGen);
			setPkmnToZeroFn(&currentAvg, debug);//resetting every accumulator and counter
			currentGen++;
			numPkmnPerGen=0;
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

