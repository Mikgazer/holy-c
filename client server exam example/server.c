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
const char *servizio = "50000"; /* port */

void handler(int signal){
	int status;
	while(waitpid(-1, &status, WNOHANG)>0) /* WNOHANG specifica il ritorno immediato se i child non sono usciti. */
		continue;
}
int main(void){
		
	int cc, err, on ,sd;
	struct addrinfo hints, *res;
	struct sigaction sa;
	
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=SA_RESTART;
	sa.sa_handler = handler;

	if(sigaction(SIGCHLD, &sa,NULL) == -1){
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	/* Costruzione dell indirizzo */
	memset(&hints,0,sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if((err = getaddrinfo(NULL, servizio, &hints, &res)) < 0){
		fprintf(stderr, "Errore gai: %s.\n", gai_strerror(err));
		exit(EXIT_FAILURE);;
	}

	if((sd = socket(res->ai_family,res->ai_socktype,res->ai_protocol)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	on = 1;
	if(setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0){
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}

	if((cc = bind(sd,res->ai_addr,res->ai_addrlen)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);;
	}

	if((cc = listen(sd, SOMAXCONN)) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}

	/* PADRE */
	for(;;){
			
			int pid, ns;
			ns = accept(sd, NULL, NULL);
			
			if(ns < 0){
				if(errno == EINTR)
					continue;
				perror("accept");
				exit(EXIT_FAILURE);
			}

			pid = fork();
			if(pid < 0){
				perror("fork");
				exit(EXIT_FAILURE);
			}
			
			/* FIGLIO */
			else if(pid == 0){
				
				char corso[BUFSIZE];
				char insegnamento[BUFSIZE];
				char nrecensioni[BUFSIZE];
				const char *ack="ack\n";
				
				int pid_n1, pid_n2;
				int pipe_n1n2[2],pipe_n2f[2];
				 
				/* molto importante */
				close(sd);
			
				/* Corso */
				memset(corso,0,sizeof(corso));
				if((cc = read(ns,corso, sizeof(corso))) < 0){
					perror("read corso server side\n");
					exit(EXIT_FAILURE);
				}
				if((cc = write(ns ,ack, strlen(ack))) < 0){
					perror("write ack corso server side\n");
					exit(EXIT_FAILURE);
				}

				/* Insegnamento */
				memset(insegnamento, 0, sizeof(insegnamento));
				if((cc = read(ns, insegnamento, sizeof(insegnamento))) < 0){
					perror("read insegnamento server side\n");
					exit(EXIT_FAILURE);
				}
				if((cc = write(ns,ack,strlen(ack))) < 0){
					perror("write ack insegnamento server side\n");
					exit(EXIT_FAILURE);
				}
			
				/* Nrecensioni */
				memset(nrecensioni, 0, sizeof(nrecensioni));
				if((cc = read(ns, nrecensioni, sizeof(nrecensioni))) < 0){
					perror("read nrecensioni server side\n");
					exit(EXIT_FAILURE);
				}
				printf("%s: %s: %s\n", corso, insegnamento, nrecensioni);
				printf("Invio informazioni al client.\n");

				/* Fork e pipe */
				cc = pipe(pipe_n1n2);
				if(cc < 0){
					perror("pipe pipe_n1n2\n");
					exit(EXIT_FAILURE);
				}
				pid_n1 = fork();
				if(pid_n1 < 0){
					perror("fork nipote 1");
					exit(EXIT_FAILURE);
				}
	
				/* NIPOTE 1 */
				else if(pid_n1 == 0){
					char db_file[BUFSIZE];
					
					close(ns);
					close(pipe_n1n2[0]);
					close(1);
					dup(pipe_n1n2[1]);
					close(pipe_n1n2[0]);
				
					snprintf(db_file, sizeof(db_file), "/home/carlo/Desktop/Client_Server/Esame_Prova/var/local/degree_course/%s.txt", corso);
					execlp("grep", "grep", insegnamento, db_file, NULL);
					perror("execlp");
					exit(EXIT_FAILURE);
				}
				
				cc = pipe(pipe_n2f);
				if(cc < 0){
					perror("pipe pipe_n2f\n");
					exit(EXIT_FAILURE);
				}
				pid_n2 = fork();
				if(pid_n2 < 0){
					perror("fork nipote 2");
					exit(EXIT_FAILURE);
				}
	
				/* NIPOTE 2 */
				else if(pid_n2 == 0){
					close(ns);
					
					close(pipe_n1n2[1]);
					close(0);
					dup(pipe_n1n2[0]);
					close(pipe_n1n2[0]);
			
					close(pipe_n2f[0]);
					close(1);
					dup(pipe_n2f[1]);
					close(pipe_n2f[1]);
					
					execlp("sort", "sort", "-n", "-r", NULL);
					perror("execlp");
					exit(EXIT_FAILURE);
				}
			
				/* FIGLIO */
				close(pipe_n1n2[0]);
				close(pipe_n1n2[1]);
			
				close(pipe_n2f[1]);
				close(0);
				dup(pipe_n2f[0]);
				close(pipe_n2f[0]);
			
				close(1);
				dup(ns);
				close(ns);
				
				execlp("head", "head", "-n", nrecensioni, NULL);
				perror("execlp");
				exit(EXIT_FAILURE);
			
				
			}
	
			/* PADRE */
			close(ns);
		
	}
	close(sd);
		
	return 0;
	

}
