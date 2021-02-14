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

#define _CRT_SECURE_NO_DEPRECATE
#define BUFSIZE 4096
const char *ack = "ack";

void handler(int signal){
	printf("\nRicevuto interrupt da tastiera. Termino..\n");
	exit(-1);
}

int main(int argc, char **argv){
	
	int err, on ,cc, socket_descriptor, nread;
	int i=0,z=0;
	char msg[BUFSIZE];
	uint8_t buffer[BUFSIZE]; /* unsigned integer of length 8 bits */

	signal(SIGINT,handler);
	
	char *host_remoto, *servizio_remoto;
	struct addrinfo hints, *res;
	struct addrinfo *ptr;
	
	if(argc < 3){
		fprintf(stderr, "Uso: ./nomefile <server> <porta>.\n");
		exit(1);
	}
	//costruzione dell'indirizzo
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	host_remoto = argv[1];
	servizio_remoto = argv[2];

	err = getaddrinfo(host_remoto, servizio_remoto, &hints, &res);
	if(err!=0){
		fprintf(stderr, "Errore gai: %s\n", gai_strerror(err));
		exit(EXIT_FAILURE);
	}

	
	printf("Connessione al Server a all'ip %s alla porta %s riuscita.\n",host_remoto,servizio_remoto);
	
	do
	{
		for(ptr=res; ptr != NULL; ptr = ptr->ai_next){
			if((socket_descriptor= socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol))<0){
				fprintf(stderr, "Creazione socket fallita al tentativo %d.\n",i);
				continue;
			}
			if(connect(socket_descriptor,ptr->ai_addr, ptr->ai_addrlen)==0){
				printf("Connect riuscita al tentativo %d , connesso per l'%d esima volta.\n", i,z);
				break;
			}
			i++;
			close(socket_descriptor);
			
		}
		
		if(ptr==NULL){
			printf("Errore di connessione!\n");
			exit(3);
		}	
		//Scambio dati con il Server
		printf("Inserire il messaggio che si vuole inviare al server, fine per terminare.\n");
		scanf("%s",msg);
		if(write(socket_descriptor,msg,strlen(msg))<0){
			perror("write");
			exit(1);
		}
		
		if(read(socket_descriptor,buffer,sizeof(buffer))>=0) printf("Ricevuto ack del messaggio inviato.\n");
		else if(read(socket_descriptor,buffer,sizeof(buffer))<0){
			perror("read ack");
			exit(1);
		}
		/*
		if(nread=read(socket_descriptor,buffer,sizeof(buffer))<0){
			perror("read");
			exit(EXIT_FAILURE);
		}

		printf("Sono stati scritti %d byte\n",nread);
		*/
		
	}
	while(strcmp(msg,"fine")!=0);
	
	/* a questo punto, posso liberare la memoria allocata da getaddrinfo */
    	freeaddrinfo(res);
	close(socket_descriptor);

	return 0;

}
