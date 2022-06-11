/*
 * menu.c
 *
 *  Created on: 9 jun. 2022
 *      Author: USUARIO
 */


#include "menu.h"
#include <stdio.h>

int menu_main(int option)
{
    int todoOk= -1;



    printf(" |                                NOMINA DE PASAJEROS                                |\n");
    printf(" +===================================================================================+\n");
    printf(" |  [1] Cargar los datos de los PASAJEROs desde el archivo data.csv (modo texto).    |\n");
    printf(" |  [2] Cargar los datos de los PASAJEROs desde el archivo data.bin (modo binario).  |\n");
    printf(" |  [3] Alta de PASAJERO.                                                            |\n");
    printf(" |  [4] Modificar datos de PASAJERO.                                                 |\n");
    printf(" |  [5] Baja de PASAJERO.                                                            |\n");
    printf(" |  [6] Listar PASAJEROs.                                                            |\n");
    printf(" |  [7] Ordenar PASAJEROs.                                                           |\n");
    printf(" |  [8] Guardar los datos de los PASAJEROs en el archivo data.csv (modo texto).      |\n");
    printf(" |  [9] Guardar los datos de los PASAJEROs en el archivo data.bin (modo binario).    |\n");
    printf(" | [10] Salir del programa                                                           |\n");
    printf(" +-----------------------------------------------------------------------------------+\n\n");
	printf("          seleccione la opcion deseada: \n");
	scanf("%i", &todoOk);



    return todoOk;
}
int menu_Passenger_newParametros(nombre, tipoPasajero){
	int todoOk = 0;
	 printf("1.ingrese Nombre\n");
	 scanf("%s", nombre);
	 printf("2. Ingrese Tipo de pasajero 4 niño 5 adulto 6 jubilado \n");
	 scanf("%d", tipoPasajero);

	return todoOk;
}
