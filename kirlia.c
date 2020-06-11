#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gardevoir.h"

void subMenuWrapperStatsFn(Pokemon *db, int nr, int debug){

	int stop=1;//flag to manage exit from stats menu

	if(debug)
		printf("\nBeginning of subMenuWrapperStatsFn");
	printf("\nInsert a command:\n1)\tAverage statistics per generation\n0)\tReturn to main menu\n--------------------------------------------------------------\n\n\n");
	scanf('%d'
}
