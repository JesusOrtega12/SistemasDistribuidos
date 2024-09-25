#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>

int main( )
{
    int sockfd, clisockfd, portno;
    char * start = "Hola";
    char * end = "Adios";
    socklen_t clilen;
    char buffer[256];
    char contentBuffer[255];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;
    

    /* Primera llamada a la función socket()  */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR al abrir el socket")
        return(1);
    }

    /* Inicializa la estructura socket */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5000;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);


    if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    {
        perror("ERROR  en el enlace");
        return(1);
    }

    listen(sockfd,5);
    clilen = (socklen_t) sizeof(cli_addr);

    clisockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    if (clisockfd < 0)
    {
        perror("ERROR al aceptar");
        return(1);
    }

    while (strcmp(end, contentBuffer) !=0)
    {
        bzero(buffer,256);
        bzero(contentBuffer,255);
        
        n = read( clisockfd,buffer,255 );
        if (n < 0)
        {
            perror("ERROR al leer del socket ");
            return(1);
        }

        strncpy(contentBuffer,buffer,strlen(buffer) - 1);
        if (strcmp(start, contentBuffer) ==0)
        {
            printf("command: %s\n",buffer);
            n = write(clisockfd,"entendido",11);
            if (n < 0)
            {
                perror("ERROR escribir al escribir en el socket");
                return(1);
            }
        }
        else
        {
            printf("Comando Desconocido: %s\n",buffer);
            n = write(clisockfd,"ERRCmd",7);
            if (n < 0)
            {
                perror("ERROR al escribir en el socket");
                return(1);
            }
        }
    }
    close(sockfd);
    return 0;


}


