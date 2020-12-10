#ifndef _megaGardevoir_H_
#define _megaGardevoir_H_

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
	char name[30+1];
	char type1[8+1];
	char type2[8+1];
	Stats stats;
	int gen;
	char legg[5+1];
	int read;
} Pokemon;

void helloWorldFn();

void printPkmnFn(Pokemon var, int debug);//read a pokemon variable and print it to stdout
void setPkmnToZeroFn(Pokemon *var, int debug);//set to zero a generic Pokemon variable 
Pokemon addPkmnValuesFn(Pokemon first, Pokemon second, int debug);//add the stats of the first Pokemon to the second one

void printPkmnStatsFn(Stats var, int debug);//read a Stats var and print it to stdout
void setPkmnStatsToZeroFn(Stats *var, int debug);//set to zero a generic Pokemon variable 
Stats addPkmnStatsFn(Stats first, Stats second, int debug);//add the stats of the first Pokemon to the second one
Stats divPkmnStatsByNumFn(Stats first, int second, int debug);//divide the given Stats var by the given Int

//function set from findPkmn opt in stats subMenu

void printDbFn(Pokemon *db, int nr, int debug);//read db and print everything to stdout
void printPkmnNameFn(Pokemon *db, int nr, int debug, char goalPkmn[]);//print a single line of the db based on the lastt parameter

#endif
