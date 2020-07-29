#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "megaGardevoir.h"
#include "gardevoir.h"

#define numOpt 5


mainMenu readCommandMain(){

	//static int numOpt=5;
	int j=0;//index used to cycle on the options table
	char string[14+1];//store the command submitted by the user
	char optTable[numOpt][14+1]={	"printAll",//contains every possible option that the user can submit
									"selectPkmn",
									"printPkmn",
									"statistics",
									"exitTheProgram",};
	mainMenu index;//index used to cycle on the menu

	printf("\nInsert a command:");
	printf("\n1)\tPrint the list of all available Pokemon");
	printf("\n2)\tSelect a pokemon (Only as a reference to the user)");
	printf("\n3)\tPrint the selected pokemon info (Still as a reference");
	printf("\n4)\tStatistics V");
	printf("\n0)\tExit\n--------------------------------------------------------------\n\n\n");//main menu output
	printf("\nCommand list:");
	for(j=0; j<numOpt; j++)//output the command list
		printf("\n%d) %s", j+1, optTable[j]);
	printf("\nCommand: ");
	scanf("%s", string);//scan the command
	for(index=printAll, j=0; index<exitTheProgram && j<numOpt && strcasecmp(string, optTable[j])!=0; index++, j++);//cycle 
	//trought the table and stops when the string and the option are equals

	return index;
}


statsSubMenu readCommandSub1(){

	//static int numOpt=5;
	int j=0;//index used to cycle on the options table
	char string[14+1];//store the command submitted by the user
	char optTable[numOpt][14+1]={	"printAvgs",//contains every possible option that the user can submit
									"goToMainMenu",};
	statsSubMenu index;//index used to cycle on the menu

	printf("\nInsert a command:");
	printf("\n1)\tAverage statistics per generation");
	printf("0)\tReturn to main menu\n--------------------------------------------------------------\n\n\n");//main menu output
	printf("\nCommand list:");
	for(j=0; j<numOpt; j++)//output the command list
		printf("\n%d) %s", j+1, optTable[j]);
	printf("\nCommand: ");
	scanf("%s", string);//scan the command
	for(index=printAll, j=0; index<exitTheProgram && j<numOpt && strcasecmp(string, optTable[j])!=0; index++, j++);//cycle 
	//trought the table and stops when the string and the option are equals

	return index;
}
