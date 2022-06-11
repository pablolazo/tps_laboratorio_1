#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{ int id;
char nombre[50];
char apellido[50];

int tipoPasajero;


int todoOk = 0;
char buffer[5][20000];
Passenger* aux;

if(pFile != NULL
   && pArrayListPassenger != NULL)
{
    while(!feof(pFile))
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]) == 4
           && scanf(buffer[0], &id) && buffer[1] != NULL
           && scanf(buffer[2], &apellido)
           && scanf(buffer[3], &tipoPasajero))
        {
            aux = Passenger_newWithParameters(id, nombre, tipoPasajero);

            if(aux != NULL && ll_add(pArrayListPassenger, (Passenger*)aux) == 0)
            {
                todoOk = 1;
            }
        }
    }
}

return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int todoOk = 0;
	    Passenger auxStatic;
	    Passenger* auxDinamic = NULL;
	    int id;
	    char nombre;
	    int tipoPasajero;


	    if(pFile != NULL && pArrayListPassenger != NULL)
	    {
	        while(!feof(pFile))
	        {
	            if(fread((Passenger*)&auxStatic, sizeof(Passenger), 1, pFile) == 1)
	            {
	                auxDinamic = Passenger_newWithParameters(id, nombre, tipoPasajero);

	                if(auxDinamic != NULL && ll_add(pArrayListPassenger, (Passenger*)auxDinamic) == 0)
	                {
	                    todoOk = 1;
	                }
	            }
	        }
	    }

	    return todoOk;
}
