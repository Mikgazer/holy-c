typedef struct list_element {
	int value;
	struct list_element *next;
} item;
typedef item *list;

//Funzioni iterative
#ifndef RECURSIVE
list cons(int e, list l); //aggiunta di elementi ad una lista 
list cons_tail(int e, list l); //aggiunta di elementi ad una lista in fondo
//list sublist(int e, list l, list sub_l); //estrapolazione di una sotto lista
void showList(list l); //stampa di una lista
int member(int e, list l); //ricerca di un elemento in una lista
int lenght(list l); //calcolo della lunghezza di una lista
int sumlist(list l); //somma degli elementi di una lista
#endif



//Funzioni ricorsive
#ifdef RECURSIVE
int member_r(int e, list l) 
void showListr(list l)
#endif
