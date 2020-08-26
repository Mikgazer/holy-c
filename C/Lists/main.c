/*
 1) Creare una funzione per l’inserimento di elementi in testa ad una
lista: funzione cons.
 2) Creare una funzione per l’inserimento di elementi in coda ad una
lista: funzione cons_tail.
 3) Creare una funzione per la stampa di una lista: funzione showlist.
 4) Creare una funzione per la ricerca di un elemento n nella lista:
funzione member.
 5) Creare una funzione per il calcolo della lunghezza della lista:
funzione length.
 6) Creare una funzione per il calcolo della somma degli interi
contenuti nella lista: funzione sumlist.
 7) Creare una funzione per l’estrapolazione di una sotto-lista, dalla
posizione k alla fine: funzione sublist
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <stdio.h>
#include "Intestazione.h"

int main() {

	int scelta=0;
	int e=0;
	int i=0;
	int trovato=0;
	int lunghezza=0;
	int somma = 0;

	list L; 
	list root = NULL;
	list sub_l;
	list root = NULL;
	

	do {
		printf("Introdurre valore: ");
		scanf("%d", &i);

		L = (list)malloc(sizeof(item));
		L->value = i;
		L->next = root;
		root = L;
	} while (i != 0);
	
	do{
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
		printf("Selezionare la funzione che si vuole eseguire sulla lista, 0 per terminare. \n");
		printf("\n");
		printf("\t (1) Funzione cons, inserimento di un elemento in testa. \n");
		printf("\t (2) Funzione cons_tail, inserimento di un elemento in coda. \n");
		printf("\t (3) Funzione che visualizza la lista. \n");
		printf("\t (4) Funzione che ricerca un elemento nella lista. \n");
		printf("\t (5) Funzione che calcola la lunghezza della lista. \n");
		printf("\t (6) Funzione che calcola la somma degli elementi di una lista \n");
		printf("\t (7) Funzione che estrapola una sotto lista. \n");
		printf("\t Inserire la propria scelta \t");
		scanf("%d", &scelta);

		switch (scelta) {
		case 1: printf("\t Inserire l'elemento che si vuole inserire in testa alla lista. \n");
			scanf("%d", &e);
			L = cons(e, L);
			break;

		case 2: printf("\t Inserire l'elemento che si vuole inserire in coda alla lista. \n");
			scanf("%d", &e);
			cons_tail(e, L);
			break;

		case 3: showList(L);
			printf("\n");
			break;

		case 4: printf("\t Inserire l'elemento che si vuole cercare nella lista. \n");
			scanf("%d", &e);
			trovato = member(e, L);
			if (trovato) printf("\t L'elemento e' presente nella lista. \n");
			else printf("\t L'elemento non e' presente nella lista. \n");
			printf("\n");
			break;

		case 5: lunghezza = lenght(L);
			printf("\t Lunghezza della lista = %d \n", lunghezza);
			printf("\n");
			break;

		case 6: somma = sumlist(L);
			printf("\t Somma degli elementi della lista = %d \n", somma);
			printf("\n");
			break;

		/*
		case 7: printf("\t Inserire la lunghezza della sottolista che si vuole estrapolare \n");
			lunghezza = lenght(L);
			scanf("%d", &e);
			if (e > lunghezza) {
				sub_l = sublist(e, L, sub_l);
				showlist(sub_l);
				break;
			}
			else break;
			printf("\n");
		}
		*/

	} while (scelta > 0 || scelta<7);

	return 0;
}
