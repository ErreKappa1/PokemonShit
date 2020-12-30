#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "megaGardevoir.h"
#include "wrumple.h"
#include "gardevoir.h"
#include "kirlia.h"


void globalAverageFn(Pokemon *db, int nr, Node_t **head, int debug){

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
			printPkmnStatsFn(currentAvg, debug);//print the actual avg
			pushEndFn(head, currentAvg);//push the value to the end of the list
			printf("\n");
			setPkmnStatsToZeroFn(&currentAvg, debug);//resetting every accumulator and counter
			currentGen++;//updating generatuion index
			numPkmnPerGen=0;//reset the number of pokemo per gen
		}
	}
	printf("\nTotal analyzed Pokemon: %d", i);
	if(debug)
		printListFn(*head);
}


void topPkmnPerGenByStatFn(Pokemon *db, int nr, Node_t **head, int debug){

	int gen=0;//stores the required generation
	char stat[5+1];//stores the required statistic
	char statList[6][5+1]={ "hp",//statistics list
							"atk",
							"def",
							"spAtk",
							"spDef",
							"spd"};
	int i=0;//cycle index
	int fineGen=0, fineStat=0;//checking flag
	
	//TODO

	if(debug)
		printf("Beginning of topPkmnPerGenByStatFn\n");
	do{
		printf("\nIn what generation are you searcing? From one to six:\t");
		scanf("%d", &gen);//require generation from user
		if(gen<6&&gen>1)//check the user input
			fineGen=1;
		if(debug)
			printf("\n\ngen input is fine: %d\n\n", gen);
		printf( "\nIn what statistic are you interested in? Choose one between:\n");
		for(i=0; i<6; i++)//print the statistics list
			printf("%s\n", statList[i]);
		printf("\n");
		scanf("%s", stat);//require stat from user
		for(i=0; i<6; i++)//check the user input
			if(strcmp(statList[i], stat)==0){
				fineStat=1;
				break;
			}else{
				fineStat=0;
			}
		if(debug)
			printf("\n\nstat input is fine: %d\n\n", stat);
		if(fineStat&&fineGen){//exit from the main cicle
			break;
		}else{//print the error if necessary
			printf("\n\nERROR: Must insert a gneration between 1 and 6, and a satistic between the listed ones");
			system(sleep);
			system(clear);
		}
	}while(1);
	if(debug)
		printf("\nInput:\n\tGen:\t%d\n\tStat:\t%s", gen, stat);
	for(i=0; i<nr; i++)//cycle on the whole db
		for(int j=0; j<6; j++)
			if(db[i].gen==gen)
				if(debug)
					printf("\nAnalyzing the %d generation", db[i].gen);
	//TODO work on the stat, dunno how to compare tha string and the actual member of the struct
}

/*
	char statList[6][5+1]={ "hp",//statistics list
							"atk",
							"def",
							"spAtk",
							"spDef",
							"spd"};
*/

void subMenuWrapperStatsFn(Pokemon *db, int nr, Node_t **head, int debug){

	int stop=1;//flag to manage exit from stats menu
	statsSubMenu command=0;//switch case flag

	if(debug)
		printf("Beginning of subMenuWrapperStatsFn\n");
	while(stop){
		command=readCommandSub1();
		printf("\n\n");
		switch(command){
			case printAvgs:
				system(clear);
				globalAverageFn(db, nr, head, debug);//compute global statistics per generation
				printf("\n");
				system(sleep);
				system(clear);
			break;
			case findPkmn:
				system(clear);
				topPkmnPerGenByStatFn(db, nr, head, debug);//take gen and stat as impunt and return the maching pkmn
				printf("\n");
				system(sleep);
				system(clear);
			break;
			case back://Exit the program
				system(clear);
				stop=0;
			break;
			default://any other value return an error
				system(clear);
				printf("\nIncorrect value; Returning to statistics subMenu\n");
				printf("\n");
				system(sleep);
				system(clear);
		}
	}
}

