#ifndef _gardevoir_H_
#define _gardevoir_H_

typedef enum{
	printAll,
	selectPkmn,
	printPkmn,
	statistics,
	exitPrg,
	error
} mainMenu;

typedef enum{
	printAvgs,
	findTopPokemon,
	goToMainMenu,
	errorError
} statsSubMenu;

mainMenu readCommandMain();//prompt to the user and read the command from stdin
statsSubMenu readCommandSub1();//prompt to the user and read the command from stdin

#endif
