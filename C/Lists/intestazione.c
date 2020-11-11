#include <stdlib.h>
#include <stdio.h>
typedef struct list_element{
	int value;
	struct list_element *next;
} item;
typedef item *list;

void showList(list l) {
	while (l != NULL){
		printf("\t");
		printf("%d;", l->value);
		l = l->next;
	}
	printf("\n");
}

int member(int e, list l) {
	int trovato = 0;
	while ((l != NULL) && !trovato)
		if (l->value == e) trovato = 1;
		else l = l->next;
	return trovato;
}

int lenght(list l) {

	int i = 0;
	while (l != NULL) {
		l = l->next;
		i++;
	}
	return i;
}


int sumlist(list l) {
	int i = 0;
	while (l != NULL) {
		i = i + l->value;
		l = l->next;
	}
	return i;
}

list cons_tail(int e, list l) {
	list prec, aux;
	prec = NULL;
	list patt = l;
	aux = (list)malloc(sizeof(item)); // ALLOCA NODO
	aux->value = e;
	aux->next = NULL;
	if (l == NULL) return aux; // INSERISCE IN LISTA VUOTA
	else
	{
		while (patt != NULL) // NON FINE LISTA
		{
			prec = patt;
			patt = patt->next;
		}
		prec->next = aux; // AGGIUNGE IN FONDO
		return l; // RESTITUISCE RADICE l
	}
}

list cons(int e, list l) {
	list t;
	t = (list)malloc(sizeof(item));
	t->value = e; 
	t->next = l;
	return t;
}


list sublist(int e, list l, list sub_l) {

	int i = 0;
	for (i = 0; i < e; i++) {
		sub_l->value = l->value;
		l->value = l->next;
		sub_l->next = NULL;
	}
	
}
