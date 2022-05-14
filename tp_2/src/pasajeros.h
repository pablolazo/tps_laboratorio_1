/*
 * pasajeros.h
 *
 *  Created on: 13 may. 2022
 *      Author: USUARIO
 */
#include "imput.h"
#include "vuelo.h"
#include "menu.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PASAJEROS_H_
#define PASAJEROS_H_

typedef struct
{
int id;
char name[51];
char lastName[51];
float price;
estadoDeVuelo vuelo;
int typePassenger;
int isEmpty;
}Passenger;




#endif /* PASAJEROS_H_ */
int ePasajero_inicializar(Passenger lista[], int tam);
void informarPasajeros(Passenger lista[], int tam);
int buscarAsiento(Passenger lista[], int tam);
int altaPasajero(Passenger lista[], int tam, int* pNextId);
int modificacionDePasajero(Passenger lista[], int tam, int* pNextId);
int buscarPasajero(Passenger lista[], int tam, int id, int* pIndex);
void mostrarPasajero(Passenger pasajero);
int bajaPasajero(Passenger lista[], int tam);
int hardcodearPasajeros(Passenger lista[], int tam, int cant, int* pNextId);
int ordenarPasajerosTipoPasaApellido(Passenger vec[], int tam);
int ordenarPasajerosEstadoVueloCodigoaDescendente(Passenger vec[], int tam);
int ordenarPasajerosEstadoVueloCodigoaAscendente(Passenger vec[], int tam);
int promedioPrecios(Passenger vec[], int tam);
