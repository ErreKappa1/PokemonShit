#ifndef _gardevoir_H_
#define _gardevoir_H_

typedef enum{
		printAll,
		selectPkmn,
		printPkmn,
		statistics,
		exitTheProgram
} mainMenu;

mainMenu readCommand();//prompt to the user and read the command from stdin

#endif
