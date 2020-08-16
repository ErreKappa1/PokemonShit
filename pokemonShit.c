#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "megaGardevoir.h"
#include "wrumple.h"
#include "gardevoir.h"
#include "kirlia.h"
#include "ralts.h"

#define debug 1//debug==1 yup


int main(void){

	Pokemon *db=NULL;//inizialising database
	int nr=0;//number of rows
	int stop=1;//flag to manage exit from main menu
	mainMenu command=0;//switch case flag
	char goalPkmn[40+1]={0};//pokemon that the program will find

	Node_t *head=NULL;

	nr=loadPkmnFn(&db, "pokemon_data.txt", debug);//load the file into the db
	if(debug){
		printf("\nNumber of lines %d", nr);
		system(sleep);
	}
	system(clear);
	while(stop){
		command=readCommandMain();
		printf("\n\n");
		switch(command){
			case printAll://Print the list of all available Pokemon
				system(clear);
				printDbFn(db, nr, debug);//read db and print everything to stdout
				printf("\n");
				system(sleep);
				system(clear);
				break;
			case selectPkmn://Select a pokemon (Only as a reference to the user)
				system(clear);
				printf("\nSelect the a Pokemon:\n");
				scanf("%s", goalPkmn);//scan for the pokemon name
				printf("\n%s Aquired", goalPkmn);
				printf("\n");
				system(sleep);
				system(clear);
				break;
			case printPkmn://Print the selected pokemon info (Still as a reference)
				system(clear);
				printf("\nPrint the selected pokemon info (Still as a reference)\n");
				printPkmnNameFn(db, nr, debug, goalPkmn);//print a single line of the db based on the first parameter
				printf("\n");
				system(sleep);
				system(clear);
				break;
			case statistics://open the statistic submenu
				system(clear);
				subMenuWrapperStatsFn(db, nr, &head, debug);//function to manage statistics subenu
				printf("\n");
				system(clear);
				break;
			case exitTheProgram://Exit the program
				system(clear);
				stop=0;
				break;
			default://any other value return an error
				system(clear);
				printf("\nIncorrect value; Returning to main menu\n");
				printf("\n");
				system(sleep);
				system(clear);
		}
	}
	free(db);
	printf("\nExit success\n");

	return 0;
}
