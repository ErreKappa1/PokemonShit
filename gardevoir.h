#ifndef _gardevoir_H_
#define _gardevoir_H_

typedef enum{
	printAll,
	selectPkmn,
	printPkmn,
	stats,
	exitPrg,
	error
} mainMenu;

typedef enum{
	printAvgs,
	findPkmn,
	back,
	errorError
} statsSubMenu;

mainMenu readCommandMain();//prompt to the user and read the command from stdin
statsSubMenu readCommandSub1();//prompt to the user and read the command from stdin

#endif
