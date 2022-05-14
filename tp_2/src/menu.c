
#include "menu.h"
#include <stdio.h>


int Menu(int opcion){
	int a;

	printf("=======================================================\n");
	printf("                CARGA DE PASAJEROS\n");
	printf("=======================================================\n");
	printf("         1- Alta \n ");
	printf("         2- Modificar \n");
	printf("         3- Baja \n");
	printf("         4- Informar  \n");
	printf("         5- Informar hardcodeados \n");
	printf("         6- informar por apellido y tipo de pasajero  \n");
	printf("         7- informar por codigo vuelo y estado de vuelo  \n");
	printf("         8- informar promedios de precio  \n");
	printf("         9- Salir  \n");
	printf("=======================================================\n");
	printf("          seleccione la opcion deseada: \n");
	scanf("%d", &a);

	return a;
}

int menuModificacion(int option)
{
	int a;

    printf("=======================================================\n");
    printf("                MODIFICAR PASAJERO\n");
    printf("=======================================================\n");
	printf("         1- Alta \n ");
	printf("         2- Modificar \n");
	printf("         3- Baja \n");
	printf("         4- Informar  \n");
	printf("         5- Hardcodear \n");
	printf("         6- Informar por tipo de pasajero y apellido \n");
	printf("         7- Salir \n");
	printf("=======================================================\n");
	printf("          seleccione la opcion deseada: \n");
	scanf("%d", &a);

	return a;
}


int menuModificarPasajero()
{
    int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. codigo de vuelo\n");
    printf("4. precio \n");
    printf("5. Ingrese Tipo de pasajero 4 niño 5 adulto 6 jubilado \n");
    printf("6. estado de vuelo\n");
    printf("7. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
/*
 * menu.c
 *
 *  Created on: 5 may. 2022
 *      Author: USUARIO
 */


