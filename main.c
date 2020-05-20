#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gardevoir.h"

int main(void){

	Pokemon *db=NULL;//inizialising database
	int nr=0;//number of rows
	int debug=1;//debug==1 yup

	nr=loadFileFn(&db, "pokemon_data_2.txt", debug);//load the file into the db
	if(debug)
		printf("\nNumber of lines %d", nr);
	//printDbFn(db, nr, debug);

	helloWorldFn();//check inf the other file are detected

	return 0;
}
