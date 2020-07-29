#ifndef _gardevoir_H_
#define _gardevoir_H_

typedef enum{
	printAll,
	selectPkmn,
	printPkmn,
	statistics,
	exitTheProgram
} mainMenu;

typedef enum{
	printAvgs,
	goToMainMenu
} statsSubMenu;

mainMenu readCommandMain();//prompt to the user and read the command from stdin
statsSubMenu readCommandSub1();//prompt to the user and read the command from stdin

#endif
