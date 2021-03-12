/*

Il programma deve visualizzare un menu con diverse opzioni. 
Prende quindi in input un carattere che corrisponde ad uno dei seguenti comandi.
Esegue il comando e ritorna al menu per una nuova operazione.
'r' → Generare un nuovo albero -
- il programma deve prendere in input i numeri da inserire all'interno dell'albero, usando getElement
- e chiedendo, dopo ogni inserimento, se si vuole continuare o tornare al menu.

'<' → Eseguire stampa preorder.
'>' → Eseguire stampa postorder.
'i' → Eseguire stampa inorder.
'/' → Ricerca di un elemento.
'h' → Calcolare l'altezza dell'albero.
's' → Calcolare la somma degli elementi dell'albero.
'n' → Calcolare il numero di nodi.
'b' → Calcolare il bilanciamento dell'albero.
'e' → Uscire dal programma

*/

#define _CRT_SECURE_NO_DEPRECATE
#include "tree.h"

int main(){

	char scelta = ' ';
	char s_scelta=' ';
	int altezza = 0;
	int el = 0;
	int somma = 0;
	int nodi = 0;
	tree t1;
	t1 = NULL;
	
	char temp[BUFSIZ];

	do
	{
		system("cls");
		printf("\n (1) 'r': Genera un nuovo albero. ");
		printf("\n (2) '<': Esegue stampa preorder. ");
		printf("\n (3) '>': Esegue stampa postorder. ");
		printf("\n (4) 'i': Esegue stampa inorder. ");
		printf("\n (5) '/': Ricerca di un elemento. ");
		printf("\n (6) 'h': Calcola l'altezza dell'albero. ");
		printf("\n (7) 's': Calcola la somma degli elementi dell'albero. ");
		printf("\n (8) 'n': Calcola il numero di nodi. ");
		printf("\n (9) 'b': Calcolare il bilanciamento dell'albero. ");
		printf("\n (10) 'e': Uscire dal programma \n");
		scanf_s("\n%c", &scelta);

		switch (scelta) {

			case 'r': 
				t1 = emptytree();
				do {
					printf("\n Inserire l'elemento da inserire nel nuovo albero \n");
					el = getElement;
					t1 = ord_ins(el, t1);
					printf("Si vuole continuare? s/n");
					scanf_s("%c", &s_scelta);

				} while (s_scelta = 's');
				break;

			case '<': preorder(t1); break;
			case '>': postorder(t1); break;
			case 'i': inorder(t1); break;
			case '/': 
				printf("\nInserire l'elemento da cercare nell'albero\n");
				el = getElement;
				boolean ricerca=false;
				ricerca = member(el, t1);
				break;
			case 'h': 
				altezza = height(t1);
				printf("\n L'altezza dell'albero e' %d", altezza);
				break;
			case 's': 
				/* somma = sum(t1); */
				printf("\n La somma degli elementi dell'albero e' %d", somma);
				break;
			case 'n': 
				nodi = nnodi(t1);
				printf("\n Il numero di nodi dell'albero e' %d", nodi);
				break;
			/* case 'b' bilanciamento */
			case 'e': exit(-1); break;
			
			default: {
				printf("\n Errore. Inserire un carattere valido. \n");
			}

		}

	} while (scelta != 'r' || scelta != '<' || scelta != '>' || scelta != 'i' || scelta != '/' || scelta != 'h' || scelta != 's' || scelta != 'n' || scelta != 'b' || scelta != 'e');

	
	printf("\n");
	printf("\nStampa in ordine \n");
	inorder(t1);
	scanf_s("%s", temp, BUFSIZ);
	system("\n");
	system("cls");
	
	return 0;
}
