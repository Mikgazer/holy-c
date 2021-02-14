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

/* https://man7.org/linux/man-pages/man3/getaddrinfo.3.html */
/* https://www.tutorialspoint.com/unix_sockets/socket_structures.htm */


/* 

Given node and service, which identify an Internet host and a service, getaddrinfo() returns one or more addrinfo structures,
       - each of which contains an Internet address that can be specified in a call to bind(2) or connect(2).  
The getaddrinfo() function combines the functionality provided by the gethostbyname(3) and getservbyname(3) functions into a single interface, 
       - but unlike the latter functions, getaddrinfo() is reentrant and allows programs to eliminate IPv4-versus-IPv6 dependencies.

The addrinfo structure used by getaddrinfo() contains the
following fields:

   struct addrinfo {
       int              ai_flags;
       int              ai_family;
       int              ai_socktype;
       int              ai_protocol;
       socklen_t        ai_addrlen;
       struct sockaddr *ai_addr;
       char            *ai_canonname;
       struct addrinfo *ai_next;
   }; 

Various structures are used in Unix Socket Programming to hold information about the address and port and other information. 
Most socket functions require a pointer to a socket address structure as an argument. 
Structures defined in this chapter are related to Internet Protocol Family.

sockaddr
The first structure is sockaddr that holds the socket information:
	struct sockaddr {
	   unsigned short   sa_family;
	   char             sa_data[14];
	};
This is a generic socket address structure, which will be passed most of the socket function calls.

sockaddr in
The second structure that helps you to reference to the socket's elements is as follows:
	struct sockaddr_in {
	   short int            sin_family;
	   unsigned short int   sin_port;
	   struct in_addr       sin_addr;
	   unsigned char        sin_zero[8];
	};

*/



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
