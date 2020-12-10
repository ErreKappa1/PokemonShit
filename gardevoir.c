#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "megaGardevoir.h"
#include "gardevoir.h"

#define numOpt0 5
#define numOpt1 3


mainMenu readCommandMain(){

	//const int numOpt=5;
	int j=0;//index used to cycle on the options table
	char string[14+1];//store the command submitted by the user
	char optTable[numOpt0][14+1]={	"printAll",//contains every possible option that the user can submit
									"selectPkmn",
									"printPkmn",
									"stats",
									"exitPrg",};
	mainMenu index;//index used to cycle on the menu

	printf("\nInsert a command:");
	printf("\n1)\tPrint the list of all available Pokemon");
	printf("\n2)\tSelect a pokemon (Only as a reference to the user)");
	printf("\n3)\tPrint the selected pokemon info (Still as a reference");
	printf("\n4)\tStatistics V");
	printf("\n0)\tExit\n--------------------------------------------------------------\n\n\n");//main menu output
	printf("\nCommand list:");
	for(j=0; j<numOpt0; j++)//output the command list
		printf("\n%d) %s", j+1, optTable[j]);
	printf("\nCommand: ");
	scanf("%s", string);//scan the command
	for(index=printAll, j=0; index<error && j<numOpt0 && strcasecmp(string, optTable[j])!=0; index++, j++);//cycle 
	//trought the table and stops when the string and the option are equals

	return index;
}


statsSubMenu readCommandSub1(){

	//const int numOpt=3;
	int j=0;//index used to cycle on the options table
	char string[20+1];//store the command submitted by the user
	char optTable[numOpt1][20+1]={	"printAvgs",//contains every possible option that the user can submit
									"findPkmn",
									"back",};
	statsSubMenu index;//index used to cycle on the menu

	printf("\nInsert a command:");
	printf("\n1)\tAverage statistics per generation");
	printf("\n2)\tBest pokemon given a generation and a particular statistic");
	printf("\n0)\tReturn to main menu\n--------------------------------------------------------------\n\n\n");//main menu output
	printf("\nCommand list:");
	for(j=0; j<numOpt1; j++)//output the command list
		printf("\n%d) %s", j+1, optTable[j]);
	printf("\nCommand: ");
	scanf("%s", string);//scan the command
	for(index=printAvgs, j=0; index<errorError && j<numOpt1 && strcasecmp(string, optTable[j])!=0; index++, j++);//cycle 
	//trought the table and stops when the string and the option are equals

	return index;
}
