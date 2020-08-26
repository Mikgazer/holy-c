
#include "funzioni.h"
/*QUESTA FUNZIONE CONTROLLA SE, IL NOME DELLA STRUTTURA 1 E' PRESENTE NELLA STRUTTURA 2*/
/*FA IL CICLO CONTROLLANDO OGNI ELEMENTO DELLA STRUTTURA 1 CON OGNUNO DELLA SECONDA*/
/*SE TROVA UNO UGUALE, AUMENTA DI 1 LA VARIABILE TROVATO*/
/*CON LA SECONDA FUNZIONE POI VIENE INSERITO NELLA LISTA*/
/*TROVATO INDICA IL NUMERO DI VOLTE CHE COMPARE*/
int funzione_A(element *parole, element *parole_due, int i, int k) {

	int c = 0;
	int j = 0;
	int trovato = 0;

	for (c = 0; c < i; c++) {
		for (j = 0; j < k; j++) {
			if (strcmp(parole[c].nome, parole_due[k].nome) > 0) {
				trovato++;
			}
		}
	}
	return trovato;
}

/*INSERIMENTO LISTA*/
list cons(second_element parole, list l) {
	list t;
	t = (list)malloc(sizeof(item));
	t->value = parole;
	t->next = l; 
	return t;
}

/*INSERISCE LA STRUTTURA NELLA LISTA, SFRUTTANDO CONS*/
list funzione_B(list l, second_element parole) {

	cons(parole, l);
	return l;

}

/*STAMPA LISTA*/
void showList(list l) {

	if (l != NULL) exit(-1);
	else {
		printf("\n%s ; %d", l->value.nome, l->value.valore);
		showList(l->next);
	}
}
