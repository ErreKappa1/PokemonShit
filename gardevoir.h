#ifndef _gardevoir_H_
#define _gardevoir_H_

//a bunch of OS-specific instruction, they will work with anything unix like, but windows is DOS based soooo...
#define clear "clear"
#define pwd "pwd"
#define sleep "read -p 'Press any key to continue...'"

typedef struct{
	int hp;
	int atk;
	int def;
	int spAtk;
	int spDef;
	int spd;
} Stats;

typedef struct{
	int id;
	char name[40+1];
	char type1[10+1];
	char type2[10+1];
	Stats stats;
	int gen;
	char legg[5+1];
	int read;
} Pokemon;

void helloWorldFn();
void printDbFn(Pokemon *db, int nr, int debug);//read db and print everything to stdout
void printPkmnNameFn(Pokemon *db, int nr, int debug, char goalPkmn[]);//print a single line of the db based on the first parameter

#endif
