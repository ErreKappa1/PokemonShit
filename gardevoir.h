#ifndef _gardevoir_H_
#define _gardevoir_H_

typedef enum{//mainMenu
	printAll,
	selectPkmn,
	printPkmn,
	statistics,
	exitTheProgram,
	error
} mainMenu;

typedef enum{//stats submenu
	printAvgs,
	goToMainMenu,
	errorError
} statsSubMenu;

typedef struct Node{//node to store into a list the pkmn stats
	Stats data;
	struct Node * next;
} NodePkmnStats;

mainMenu readCommandMain(int numOpt);//prompt to the user and read the command from stdin
statsSubMenu readCommandSub1(int numOpt);//prompt to the user and read the command from stdin

#endif
