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

mainMenu readCommandMain();//prompt to the user and read the command from stdin
statsSubMenu readCommandSub1();//prompt to the user and read the command from stdin

#endif
