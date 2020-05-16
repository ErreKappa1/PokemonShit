#ifndef _gardevoir_H_
#define _gardevoir_H_

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
	char name[40];
	char type1[10];
	char type2[10];
	Stats stats;
	int gen;
	char legg[5+1];
} Pokemon;

void helloWorldFn();
int loadFileFn(Pokemon **db, char fileName[], int debug);//load the content of the file into **db
void printDbFn(Pokemon *db, int nr, int debug);//read db and print everything to stdout

#endif
