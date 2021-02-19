/*

Si vogliono trovare gli elementi in comune a due file testo di parole (UNO.TXT e DUE.TXT), ordinarle in senso lessicografico e stamparle in un file di uscita insieme al numero totale di volte in cui compaiono nel secondo file.
Il contenuto del file UNO.TXT è ordinato e le parole sono in copia unica nel file, quello del file DUE.TXT non è ordinato e la stessa parola può comparire più volte nel file.
Ogni parola sia al massimo di 30 char.

*/


/*

a) Nel main, per ciascuna parola letta dal primo file:
1. la si mostri a video
2. si cerchi la parola nel secondo file, contando il totale di volte in cui compare nel secondo file


Si svolga il punto a2 tramite la funzione funzioneA; 
Essa riceve la parola da cercare (letta dal primo file, nel main) il puntatore al secondo file, più altri parametri a scelta e restituisce un intero (il totale di volte in cui compare nel secondo file);

b) Se il totale di volte è maggiore di 0, chiamando una seconda funzioneB, inserisca parola e totale in una lista L, ordinata sul campo parola. 
La funzioneB ha come parametri il puntatore alla lista, l’elemento da inserire (parola e totale) più altri parametri a scelta, e restituisce la nuova lista ottenuta dopo l’inserimento;

c) Si stampi il contenuto della lista L su un file di uscita, OUTPUT.TXT, con la stampa di parola e totale suogni linea, e restituisca il numero totale di parole (la lunghezza della lista); 
Tale funzioneC ha come parametri il puntatore alla lista L, il puntatore al file più eventuali altri a scelta) e restituisce un intero che viene poi stampato dal main;

*/

#include "funzioni.h"
int main() {

	FILE *file_uno;
	FILE *file_due;
	element parole_uno[N];
	element parole_due[N];
	second_element parole_tre[N];

	list l;
	l = (list)malloc(sizeof(item));

	int i = 0;
	int k = 0;
	int j = 0;
	int ris = 0;

	/* Apertura secondo file (è il secondo file ma va aperto prima */
	file_due = fopen("due.txt", "r");
	if (file_due = NULL) {
		printf("\n Apertura file due.txt non riuscita \n");
		exit(-1);
	}
	while (!feof(file_due)) {
		fscanf(file_due, "%s", parole_due[k].nome);
		//printf("\n%s", parole_due[k].nome);
		k++;
	}
	fclose(file_due);
	/* Chiusura file */

	/* Apertura prima file */
	file_uno = fopen("uno.txt", "r");
	if (file_uno = NULL) {
		printf("\n Apertura file uno.txt non riuscita \n");
		exit(-1);
	}
	

	/* Fino alla fine del file, */
	/* - controlla con la funzione a se e' presente anche nel secondo file(seconda struttura). */
	/* Se e' presente viene inserito nella lista, il numero di volte che compare e' ris */
	/* ...ovvero la variabile trovato in funzione_a */
	while (!feof(file_uno)) {
		fscanf(file_uno, "%s", parole_uno[i].nome);
		printf("\n%s", &parole_uno[i].nome);
		ris = funzione_A(parole_uno, parole_due, i, k);

		if (ris > 0) {
			/* Se è presente nella struttura 2 */
			/* Copia il nome nella struttura 3 */
			/* Il numero di volte che è presente nella seconda struttura è ris */
			strcpy(parole_tre[j].nome, parole_uno[i].nome);
			parole_tre[j].valore = ris;
			j++;
			funzione_B(parole_tre, l);
		}
		printf("\n La parole %s compare nel secondo file %d volte", parole_uno[i].nome, &ris);
		i++;
	}
	fclose(file_uno);
	/* Chiusura file */

	system("PAUSE");
	return 0;
}
