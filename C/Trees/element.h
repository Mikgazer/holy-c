#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef enum { false, true } boolean;

boolean isLess(element, element); //controlla se un elemento è minore degli altri
boolean isEqual(element, element); //uguaglianza tra gli elementi
element getElement(void); //Input a tastiera di un elemento
boolean isNull(element); //controlla che l'elemento sia diverso da 0 
element sumElement(element, element); //somma di due element
void printElement(element); //stampa a video di un elemento
