#define _CRT_SECURE_NO_WARNINGS
#include "element.h"
#include <stdio.h>
#include <string.h>

boolean isEqual(element e1, element e2) {
	return (e1 == e2);
}
boolean isLess(element e1, element e2) {
	return (e1<e2);
}
element getElement(void) {
	element el;
	scanf("%d", &el);
	return el;
}
void printElement(element el) {
	printf("%d", el);
}

boolean isNull(element e1) {
	if (e1 == 0) return 1;
	else return 0;
}

element sumElement(element e1, element e2) {
	return (e1 + e2);
}
