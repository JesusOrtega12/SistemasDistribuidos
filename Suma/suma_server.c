/*
 *Este código es la parte del servidor la cual se utilizara cada que un cliente
 *quiera consumir el servicio que este servidor proporciona (realizar una suma) 
 */

#include "suma.h"

int *
suma_1_svc(dupla_int *argp, struct svc_req *rqstp)//Servicio que proporciona este servidor a los clientes que lo soliciten
{
	static int  result;//Variable estática de tipo entero, que almacena el resultado de la suma

	printf("Server response to client...\n");
	//Al ser una estructura lo que se pasa por parámetro se accede a cada una de sus atributos con la funcion flecha "->" 
	printf("parameters: %d, %d\n", argp->a,argp->b); 
	result = argp->a + argp->b; //Suma los dos números enteros 
	printf("returning: %d\n",result);
	return &result;//Devuelve la dirección de memoria de la suma al cliente a través de la conexión RPC

}
