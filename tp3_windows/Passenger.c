/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"

#ifndef NULL
#define NULL   ((void *) 0)
#endif
#include "Passenger.h"

Passenger* Passenger_new()
{
    Passenger* aux;

    aux = (Passenger*)malloc(sizeof(Passenger));

    return aux;
}

int Passenger_getId(Passenger* this, int* id)
{
    int todoOk = 0;

    if(this != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;
}

int Passenger_setId(Passenger* this, int id)
{
    int todoOk = 0;

    if(this != NULL
       )
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}

int Passenger_getnombre(Passenger* this, char nombre[])
{
    int todoOk = 0;

    if(this != NULL
       && this->nombre !=NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int Passenger_setNombre(Passenger* this, char nombre[])
{
    int todoOk = 0;

    if(this != NULL
       && this->nombre !=NULL
       && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}

int Passenger_getApellido(Passenger* this, char* apellido)
{
    int todoOk = 0;

    if(this != NULL)
    {
        *apellido = this->apellido;
        todoOk = 1;
    }

    return todoOk;
}
int Passenger_gettipoPasajero(Passenger* this, int tipoPasajero){
	 int todoOk = 0;

	    if(this != NULL)
	    {
	        tipoPasajero = this->tipoPasajero;
	        todoOk = 1;
	    }

	    return todoOk;
}

int Passenger_settipoPasajero(Passenger* this, int* tipoPasajero)
{
    int todoOk = 0;

    if(this != NULL
       && tipoPasajero >= 0)
    {
        this->tipoPasajero = *tipoPasajero;
        todoOk = 1;
    }

    return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
    int todoOk = 0;

    if(this != NULL)
    {
        *precio = this->precio;
        todoOk = 1;
    }

    return todoOk;
}

int Passenger_setPrecio(Passenger* this, float precio)
{
    int todoOk = 0;

    if(this != NULL
       && precio >= 0)
    {
        this->precio = precio;
        todoOk = 1;
    }

    return todoOk;
}

Passenger* Passenger_newWithParameters(int* id, char* nombre, int* tipoPasajero)
{
    Passenger* aux = Passenger_new();

    if(aux != NULL
       && (!Passenger_setId(aux, id)
       || !Passenger_setNombre(aux, nombre)
       || !Passenger_settipoPasajero(aux, tipoPasajero)
))
    {
        Passenger_delete(aux);
        aux = NULL;
    }

    return aux;
}

void Passenger_delete(Passenger* this)
{
    free(this);
}

int Passenger_print(Passenger* this)
{
    int todoOk = -1;
    int id;
    char nombre[20];
    int tipoPasajero;
    int precio;

    if(this != NULL
       && Passenger_getId(this, &id)
       && Passenger_getnombre(this, nombre)
       && Passenger_gettipoPasajero(this, tipoPasajero)
       && Passenger_getPrecio(this, &precio))
    {
        printf("+=======+======================+=======+============+\n");
        printf("|   ID  |        NOMBRE        | TIPO |   PRECIO  |\n");
        printf("+=======+======================+=======+============+\n");
        printf("| %5d | %20s | %5d | %10d |\n",
               id, nombre, tipoPasajero, precio);
        printf("+-------+----------------------+-------+------------+\n");

        todoOk = 1;
    }

    return todoOk;
}

int Passenger_getNextId(LinkedList* ArrayListPassenger)
{
    int maxValue = -1;
    int arrayLength = 0;
    int i;
    int contador = 0;
    Passenger* aux;

    if(ArrayListPassenger != NULL)
    {
        arrayLength = ll_len(ArrayListPassenger);

        if(arrayLength > 0)
        {
            for(i = 0; i < arrayLength; i++)
            {
                aux = (Passenger*)ll_get(ArrayListPassenger, i);

                if(aux != NULL)
                {
                    if(contador == 0)
                    {
                        maxValue = aux->id;
                    }
                    else
                    {
                        if(aux->id > maxValue)
                        {
                            maxValue = aux->id;
                        }
                    }

                    contador++;
                }
            }
        }

        if(contador > 0)
        {
            maxValue++;
        }
        else
        {
            maxValue = 1;
        }
    }

    return maxValue;
}

int Passenger_compareByID(void* pElement1, void* pElement2)
{
    int todoOk;
    int result;
    Passenger* aux1 = (Passenger*)pElement1;
    Passenger* aux2 = (Passenger*)pElement2;

    if(aux1 != NULL && aux2 != NULL)
    {
        result = aux1->id - aux2->id;

        if(result > 0)
        {
            todoOk = 1;
        }
        else
        {
            if(result < 0)
            {
                todoOk = -1;
            }
            else
            {
                todoOk = 0;
            }
        }
    }

    return todoOk;
}

int Passenger_compareByNombre(void* pElement1, void* pElement2)
{
    int todoOk;
    Passenger* aux1 = (Passenger*)pElement1;
    Passenger* aux2 = (Passenger*)pElement2;

    if(aux1 != NULL && aux2 != NULL)
    {
        todoOk = strcmp(aux1->nombre,aux2->nombre);
    }

    return todoOk;
}

int Passenger_compareBytipoPasajero(void* pElement1, void* pElement2)
{
    int todoOk;
    int result;
    Passenger* aux1 = (Passenger*)pElement1;
    Passenger* aux2 = (Passenger*)pElement2;

    if(aux1 != NULL && aux2 != NULL)
    {
        result = aux1->tipoPasajero - aux2->tipoPasajero;

        if(result > 0)
        {
            todoOk = 1;
        }
        else
        {
            if(result < 0)
            {
                todoOk = -1;
            }
            else
            {
                todoOk = 0;
            }
        }
    }

    return todoOk;
}

int Passenger_compareByprecio(void* pElement1, void* pElement2)
{
    int todoOk;
    int result;
    Passenger* aux1 = (Passenger*)pElement1;
    Passenger* aux2 = (Passenger*)pElement2;

    if(aux1 != NULL && aux2 != NULL)
    {
        result = aux1->precio- aux2->precio;

        if(result > 0)
        {
            todoOk = 1;
        }
        else
        {
            if(result < 0)
            {
                todoOk = -1;
            }
            else
            {
                todoOk = 0;
            }
        }
    }

    return todoOk;
}

