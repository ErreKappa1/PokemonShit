#ifndef _kirlia_H_
#define _kirlia_H_

void globalAverageFn(Pokemon *db, int nr, Node_t **head, int debug);//compute global statistics per generation
void topPkmnPerGenByStatFn(Pokemon *db, int nr, Node_t **head, int debug);//take gen and stat as impunt and return the
	//maching pkmn
void subMenuWrapperStatsFn(Pokemon *db, int nr, Node_t **head, int debug);//function to manage statistics subenu

#endif
