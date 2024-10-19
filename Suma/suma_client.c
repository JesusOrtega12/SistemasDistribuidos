/*
 *Este codigo es la parte del cliente la cual recibe los parametros para
 *realizar una suma de dos numeros enteros los cuales son proporcionados
 *por consola. Ademas de consumir un servicio el cual se encuentra en un 
 *servidro remoto esto a traves del paso de la ip con la cual se establecera
 *la conexión
 */

#include "suma.h"
#include <stdio.h>

void
suma_prog_1(char *host, int a, int b) //función la cual se encarga de realizar todo lo necesario para la suma (conexion y consumo del servicio remoto)
{
//Variables
	CLIENT *clnt;
	int  *result_1;
	dupla_int  suma_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, SUMA_PROG, SUMA_VERS, "udp"); //Creacion de un objeto CLIENT con la configuracion la cual se utilizará para establecer la conexión con el servidor remoto
	if (clnt == NULL) {
		clnt_pcreateerror (host);//Muestra un mensaje en pantalla cuando ocurre un error al crear un cliente RPC de manera detallada 
		exit (1);
	}
#endif	/* DEBUG */
	suma_1_arg.a=a; //Insersión del valor en la primera variable de la estructura la cual se utilizara para realizar la suma
	suma_1_arg.b=b; //Insersión del valor en la segunda variable de la estructura la cual se utilizara para realizar la suma
	result_1 = suma_1(&suma_1_arg, clnt); //Consumo del servicio remoto pasando la estructura con los valores a sumar y el objeto cliente para poder crear la conexión 
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed"); //Muestra un mensaje de error cuando hay un error en llamadas RPC
	}else{
		printf("result=%d\n", *result_1); //Resultado de la suma mostrado en pantalla
	}
#ifndef	DEBUG
	clnt_destroy (clnt); //Finalización de la conexión 
#endif	 /* DEBUG */
}


/*
 *La función "main" es la funcion principal del programa a la cual se le pasaran 
 *los parametros por consola y llamara a la funcion que realizara la conexion y 
 *el consumo del servicio remoto
 */
int
main (int argc, char *argv[])
{   
	char *host;
	int a,b;
	//Validación de parametros
	if (argc != 4) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	if((a = atoi(argv[2])) == 0 && *argv[2] != '0'){
	fprintf(stderr, "invalid value: %s\n",argv[2]);
	exit(1);
	}
	if((b = atoi(argv[3])) == 0 && *argv[3] != '0'){
	fprintf(stderr, "invalid value: %s\n",argv[3]);
	exit(1);

	}
	suma_prog_1 (host, a, b); //Llamado a la función para realizar el consumo del servicio remoto y la conexion pasando como parámetros los la ip y los números a sumar
exit (0);
}
