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
#define dim 10

const char *servizio = "50000";
const char *ack = "ack";
const int result = 0;
void handler(int signal){
	int status;
	while(waitpid(-1, &status,WNOHANG)>0);	//eseguo wait non bloccanti
}

void handler_2(int signal){
	printf("\nRicevuto interrupt da tastiera. Termino..\n");
	exit(-1);
}

int main(void){
	
	int err, on , cc, socket_descriptor, ns, nread, z = 0;
	int pid;
	int pipe_pf[2];
	char readpipe[BUFSIZE];
	memset(&readpipe,0,BUFSIZE);
	
	/* err valore di ritorno della getaddrinfo */
	/* socket descriptor è il descrittore della socket */
	/* cc valore di ritorno */
	/* on per le opzioni della setsockopt */
	
	signal(SIGINT, handler_2);

	struct addrinfo hints, *res;
	struct sigaction sa;
	uint8_t buffer[BUFSIZE];
	memset(buffer, 0 ,BUFSIZE);
	
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handler;
	if(sigaction(SIGCHLD, &sa, NULL) == -1){
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	err = getaddrinfo(NULL, servizio, &hints, &res);
	if(err!=0){
		fprintf(stderr, "Errore gai: %s\n", gai_strerror(err));
		exit(EXIT_FAILURE);
	}

	socket_descriptor = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if(socket_descriptor<0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	on = 1;
	if(setsockopt(socket_descriptor, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))<0){
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}

	cc = bind(socket_descriptor,res->ai_addr, res->ai_addrlen);
	if(cc<0){
		perror("bind");
		exit(EXIT_FAILURE);
	}

	cc=listen(socket_descriptor,SOMAXCONN);
	if(cc<0){
		perror("listen");
		exit(EXIT_FAILURE);
	}

		for(;;){
			
			struct sockaddr_storage client_address;
			socklen_t fromlen;
            		fromlen = sizeof(client_address);

			memset(&buffer,0,sizeof(buffer));
			ns=accept(socket_descriptor, NULL, NULL);
			if(ns<0){
				if(errno=EINTR){	
					perror("accept");	
					exit(EXIT_FAILURE);
				}
			}
			printf("Connessione al client riuscita.\n");

			/* creazione pipe e chiamata fork */
			cc=pipe(pipe_pf);
			pid = fork();	
			if(pid<0){
				perror("fork");
				exit(1);
			}
			
			else if(pid==0){ //FIGLIO
				close(1);
				dup(pipe_pf[1]);
				close(pipe_pf[1]);
				close(pipe_pf[0]);
				
				execlp("echo","echo","Hello World!",NULL);
				perror("execlp");
				exit(1);
			}
			
			//PADRE
			close(pipe_pf[1]);
			nread=read(pipe_pf[0],readpipe,BUFSIZE);
			close(pipe_pf[0]);
			if(nread<0){
				perror("read");
				exit(1);
			}
			printf("Il figlio ha scritto %s\n",readpipe);
		
			if(nread=read(ns,buffer,sizeof(buffer))<0){
				perror("read");
				exit(EXIT_FAILURE);
			}
			
			printf("Ricevuto messaggio dal client.\n");
			if(strstr(buffer,"fine")){
				printf("Ricevuto messaggio di exit. Termino.\n");
				close(ns);
				close(socket_descriptor);
				exit(1);
			}	
			
			/* 
			for(z=0;z<4;z++){
				printf("%s-",&buffer[z]);
			} 
			*/
				
			if(write(ns,ack,strlen(ack))<0){
				perror("write");
				exit(EXIT_FAILURE);
			}
		}



	close(ns);
	/* chiudo socket_descriptor */
	close(socket_descriptor);

	return 0;

}
