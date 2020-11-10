
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
typedef enum { false, true } boolean;

typedef struct element {
	char nome[30];
}element;

typedef struct second_element {
	char nome[30];
	int valore;
}second_element;

typedef struct list_element {
	second_element value;
	struct list_element *next;
}item;
typedef item *list;

int funzione_A(element *parole, element *parole_due, int i, int k);
int funzione_B(list l, element parole);
void showList(list l);
list cons(second_element parole, list l, int val);
