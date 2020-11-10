#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define BUFSIZE 2048

int main(int argc, char *argv[]){
		
	int err;
	struct addrinfo hints, *res;
	char *host_remoto, *servizio_remoto;
	char corso[BUFSIZE];
	char insegnamento[BUFSIZE];
	char nrecensioni[BUFSIZE];
	
	if(argc<3){
		fprintf(stderr,"Uso: ./nome file <server> <porta>\n");
	}
	
	memset(&hints,0,sizeof(hints));
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_STREAM;

	host_remoto=argv[1];
	servizio_remoto=argv[2];

	if((err=getaddrinfo(host_remoto,servizio_remoto,&hints,&res))!=0){
		fprintf(stderr,"Errore risoluzione nome: %s\n", gai_strerror(err));
		exit(1);
	}
	printf("Inserisci il corso di Laurea: \n");
	scanf("%s",corso);
	
	do {	
		
		int sd, cc, i=0;
		struct addrinfo *ptr;
		uint8_t buffer[BUFSIZE];
	
		printf("Inserisci l'insegnamento di Laurea: \n");
		scanf("%s",insegnamento);

		printf("Inserisci il numero di recensioni: \n");
		scanf("%s",nrecensioni);

		//Connessione con fallback
		for(ptr=res;ptr!=NULL;ptr=ptr->ai_next){
			//Se socket fallisce salto direttamente alla prossima iterazione
			if((sd=socket(ptr->ai_family,ptr->ai_socktype,ptr->ai_protocol))<0){
				fprintf(stderr,"Errore creazione socket. \n");
				continue;
			}
			//Se connect funziona esco dal ciclo
			if(connect(sd,ptr->ai_addr,ptr->ai_addrlen)==0){
				printf("Connect riuscita al tentativo %d.\n",i);
				break;
			}
			i++;
			close(sd);
		}
		
		//Verifica sul risultato restituito da getaddrinfo
		if(ptr==NULL){
			fprintf(stderr,"Errore risoluzione nome, errore connessione!\n");
			exit(EXIT_FAILURE);
		}
		printf("Connesso al server all'indirizzo ip %s alla porta %s.\n",host_remoto,servizio_remoto);
		printf("Invio dati al Server...\n");

		//Scambio dati con il server
		if(write(sd,corso,strlen(corso))<0){
			perror("write corso");
			exit(EXIT_FAILURE);
		}
		if(read(sd,buffer,sizeof(buffer))<0){
			perror("read ack corso");
			exit(EXIT_FAILURE);
		}
		if(write(sd,insegnamento,strlen(insegnamento))<0){
			perror("write insegnamento");
			exit(EXIT_FAILURE);
		}
		if(read(sd,buffer,sizeof(buffer))<0){
			perror("read ack insegnamento");
			exit(EXIT_FAILURE);
		}
		if(write(sd,nrecensioni,strlen(nrecensioni))<0){
			perror("write nrecensioni");
			exit(EXIT_FAILURE);
		}

		memset(buffer,0,sizeof(buffer));
		printf("Ricevo informazioni dal server sul file %s.txt:\n",corso);
		while((cc=read(sd,buffer,sizeof(buffer)))>0){
			write(1,buffer,cc);
		}
		if(cc<0){
			perror("read risultato da server");
		}
		
		//Dimenticarsi di chiudere la socket è un errore molto grave
		close(sd);
		
		printf("Inserire il corso di laurea, o fine per terminare \n");
		scanf("%s",corso);
		

	}while(strcmp(corso,"fine")!=0);

	freeaddrinfo(res);
	printf("\nTermino...\n");
	
	return 0;

}
