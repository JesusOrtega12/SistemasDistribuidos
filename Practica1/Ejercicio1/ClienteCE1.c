#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <IP> <puerto>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    int puerto = atoi(argv[2]);
    
    int sock;
    struct sockaddr_in servidor;
    char mensaje[256];
    char respuesta[256];

    // Crear el socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("No se pudo crear el socket");
        return 1;
    }

    // Configurar la estructura sockaddr_in
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(puerto);
    inet_pton(AF_INET, ip, &servidor.sin_addr);

    // Conectar al servidor
    if (connect(sock, (struct sockaddr *)&servidor, sizeof(servidor)) == -1) {
        perror("Error al conectar con el servidor");
        close(sock);
        return 1;
    }

    // Enviar mensaje al servidor
    printf("Ingrese un mensaje para el servidor: ");
    fgets(mensaje, sizeof(mensaje), stdin);
    send(sock, mensaje, strlen(mensaje), 0);

    // Recibir respuesta del servidor
    recv(sock, respuesta, sizeof(respuesta), 0);
    printf("Respuesta del servidor: %s\n", respuesta);

    // Cerrar el socket
    close(sock);
    return 0;
}
