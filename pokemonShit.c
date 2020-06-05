#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gardevoir.h"
#include "kirlia.h"
#include "ralts.h"

#define debug 1//debug==1 yup

int main(void){

	Pokemon *db=NULL;//inizialising database
	int nr=0;//number of rows
	int stop=1;//flag to manage exit from main menu
	int command=0;//switch case flag
	char goalPkmn[40+1]={0};

	nr=loadPkmnFn(&db, "pokemon_data.txt", debug);//load the file into the db
	if(debug){
		printf("\nNumber of lines %d", nr);
		system(sleep);
	}
	system(clear);
	while(stop){
		printf("\nInsert a command:\n1)\tPrint the list of all available Pokemon\n2)\tSelect a pokemon (Only as a reference to the user)\n3)\tPrint the selected pokemon info (Still as a reference)\n4)\tStatistics V\n0)\tExit\n--------------------------------------------------------------\n\n\n");//main menu output
		scanf("%d", &command);
		printf("\n\n");
		switch(command){
			case 1://Print the list of all available Pokemon
				system(clear);
				printDbFn(db, nr, debug);//read db and print everything to stdout
				printf("\n");
				system(sleep);
				system(clear);
			break;
			case 2://Select a pokemon (Only as a reference to the user)
				system(clear);
				printf("\nSelect the a Pokemon:\n");
				scanf("%s", goalPkmn);//scan for the pokemon name
				printf("\n%s Aquired", goalPkmn);
				printf("\n");
				system(sleep);
				system(clear);
			break;
			case 3://Print the selected pokemon info (Still as a reference)
				system(clear);
				printf("\nPrint the selected pokemon info (Still as a reference)\n");
				printPkmnNameFn(db, nr, debug, goalPkmn);//print a single line of the db based on the first parameter
				printf("\n");
				system(sleep);
				system(clear);
			break;
			case 4://open the statistic submenu
				system(clear);
				subMenuWrapperStatsFn(db, nr, debug);//TODO
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
	free(db);
	printf("\nExit success\n");

	return 0;
}
