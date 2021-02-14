/* https://man7.org/linux/man-pages/man3/getaddrinfo.3.html */
/* https://www.tutorialspoint.com/unix_sockets/socket_structures.htm */

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
