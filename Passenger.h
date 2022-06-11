/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef Passenger_H_
#define Passenger_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int isEmpty;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newWithParameters(int* id, char* nombre, int* tipoPasajero);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_gettipoPasajero(Passenger* this, int tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_compareByprecio(void* pElement1, void* pElement2);
int Passenger_compareBytipoPasajero(void* pElement1, void* pElement2);

int Passenger_compareByNombre(void* pElement1, void* pElement2);
int Passenger_compareByID(void* pElement1, void* pElement2);

int Passenger_getNextId(LinkedList* ArrayListPassenger);

int Passenger_print(Passenger* this);

void Passenger_delete(Passenger* this);



#endif /* Passenger_H_ */
