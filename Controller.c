#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{

    int todoOk = 0;
    FILE* file = NULL;

    if(pArrayListPassenger != NULL)
    {
        file = fopen(path, "r");

        if(file != NULL)
        {
            todoOk = parser_PassengerFromText(file, pArrayListPassenger);
        }
    }

    fclose(file);

    return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	 int todoOk = 0;

	    FILE* file = NULL;

	    if(pArrayListPassenger != NULL)
	    {
	        file = fopen(path, "rb");

	        if(file != NULL)
	        {
	            todoOk = parser_PassengerFromBinary(file, pArrayListPassenger);
	        }
	    }

	    return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    int id;
    char nombre[20];
    int tipoPasajero;
    float precio;

    Passenger* this;
    this = Passenger_newWithParameters(id, nombre, tipoPasajero);

    if(pArrayListPassenger != NULL)
    {
        id = Passenger_getId(this, id);
        menu_Passenger_newParametros(nombre, tipoPasajero);

    }todoOk = 1;

    return todoOk;
}
/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	    int id;
	    int max;
	    int index;
	    int lifeCycle;
	    int editMenu;
	    Passenger* beforeEdit = Passenger_new();
	    Passenger* afterEdit;

	    if(pArrayListPassenger != NULL && beforeEdit != NULL)
	    {
	        max = Passenger_getNextId(pArrayListPassenger) - 1;

	        if(max > 0 )
	        {   printf("ingrese nuevo id");
	             scanf("%d", &id);
	            index = Passenger_getNextId(pArrayListPassenger);

	            if(index != -1)
	            {
	                beforeEdit = (Passenger*)ll_get(pArrayListPassenger, index);

	                if(beforeEdit != NULL)
	                {
	                    afterEdit = Passenger_newWithParameters(&beforeEdit->id, beforeEdit->nombre, &beforeEdit->tipoPasajero);

	                    do
	                    {

	                        if(Passenger_print(afterEdit) == 0)
	                        {
	                            break;
	                        }

	                        lifeCycle = menu_main(&editMenu);

	                        switch(editMenu)
	                        {
	                        case 1: /**< Editar el Nombre. >*/

	                            printf("Ingrese nuevo Nombre: ");
	                            scanf("%s",afterEdit->nombre);
	                            Passenger_setNombre(afterEdit, afterEdit->nombre);


	                            break;
	                        case 2: /**< Editar tipo de pasajero. >*/

	                        	 printf("Ingrese nuevo tipo: ");
	                        	 scanf("%i",afterEdit->tipoPasajero);
	                        	 Passenger_settipoPasajero(afterEdit, afterEdit->tipoPasajero);

	                            break;
	                        case 3: /**< Editar el precio. >*/

	                        	printf("Ingrese nuevo precio: ");
	                        	scanf("%f",afterEdit->precio);
	                        	Passenger_setPrecio(afterEdit, afterEdit->precio);

	                            break;
	                        case 4: /**< Confirmar cambios y volver al menu principal. >*/
	                            printf("El siguiente Pasajero:\n");
	                            if(Passenger_print(beforeEdit))
	                            {
	                                printf("Sera modificado de la siguiente forma:\n");
	                                if(Passenger_print(afterEdit) && ll_set(pArrayListPassenger, index, (Passenger*)afterEdit) == 0)
	                                {
	                                    todoOk = 1;
	                                }
	                            }
	                            lifeCycle = 1;
	                            break;
	                        }
	                    }while(lifeCycle == 0);
	                }
	            }
	            else
	            {
	                printf("No se encontro el Pasajero ingresado.\n");
	            }
	        }
	    }

	    return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	  int todoOk = 0;
	    int id;
	    int index;

	    char ok;
	    Passenger* aux = Passenger_new();

	    if(pArrayListPassenger != NULL && aux != NULL)
	    {
	      printf("Ingrese el ID del pasajero que desea dar de baja: ");
	      scanf("%i",&id);
	        {
	            index = Passenger_getNextId(pArrayListPassenger);

	            if(index != -1)
	            {
	                aux = (Passenger*)ll_get(pArrayListPassenger, index);

	                if(aux != NULL)
	                {printf("Desea dar de baja el pasajero? [S] o [N]: ");
	                 scanf("%s", &ok);
	                    if( ok == 's')
	                    {
	                    	ll_remove(pArrayListPassenger, index);
	                        todoOk = 1;
	                        Passenger_delete(aux);
	                        aux = NULL;
	                    }
	                }
	            }
	            else
	            {
	                printf("No se encontro el pasajero ingresado.\n");
	            }
	        }
	    }

	    return todoOk;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	  int contadorr;
	    int multiplier = 0;
	    int PassengerQty;
	    int listMin = 0;
	    int listMax = 0;
	    Passenger* aux;
	    LinkedList* subList = ll_newLinkedList();

	    if(pArrayListPassenger != NULL && subList != NULL)
	    {
	        PassengerQty = ll_len(pArrayListPassenger);

	        while(listMin < PassengerQty)
	        {
               multiplier++;
              listMax = PassengerQty;


	            subList = ll_subList(pArrayListPassenger, listMin, listMax);

	            for(contadorr = listMin; contadorr < listMax; contadorr++)
	            {
	                if(contadorr == listMin)
	                {
	                    printf("+=======+======================+=======+============+\n");
	                    printf("|   ID  |        NOMBRE        | TIPO |   PRECIO  |\n");
	                    printf("+=======+======================+=======+============+\n");
	                }

	                aux = (Passenger*)ll_get(pArrayListPassenger, contadorr);

	                if(aux != NULL)
	                {
	                    printf("| %5d | %20s | %5d | %10f |\n",
	                           aux->id,aux->nombre,
	                           aux->tipoPasajero, aux->precio);
	                }
	            }

	            if(contadorr > 0 && contadorr == listMax
	               && ll_clear(subList) == 0)
	            {
	                printf("+-------+----------------------+-------+------------+\n");
	            }

	            listMin = contadorr;
  }

	        if(ll_len(subList) != 0
	           || ll_deleteLinkedList(subList) != 0)
	        {
	            listMax = 0;
	        }
	    }
	    return listMax;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	 int todoOk = 0;
	    int lifeCycle;
	    int sortMenu;
	    int sortOption;

	    if(pArrayListPassenger != NULL)
	    {
	        if(ll_len(pArrayListPassenger) > 0)
	        {
	            do
	            {
	                lifeCycle = menu_Passenger_newParametros(&sortMenu);

	                if(sortMenu >= 1 )
	                {   printf("Ingrese para ordenar: [1] Ascendente - [0] Descendente: ");
	                    scanf("%i",&sortOption);

	                    printf("Aguarde unos instantes...\n");

	                    switch(sortMenu)
	                    {
	                    case 1: /**< Ordenar por ID. >*/
	                        if(ll_sort(pArrayListPassenger, Passenger_compareByID, sortOption) == 0)
	                        {
	                            printf("Ordenado por ID finalizado.\n");
	                        }
	                        break;
	                    case 2: /**< Ordenar por Nombre. >*/
	                        if(ll_sort(pArrayListPassenger, Passenger_compareByNombre, sortOption) == 0)
	                        {
	                            printf("Ordenado por Nombre finalizado.\n");
	                        }
	                        break;
	                    case 3: /**< Ordenar por TIPO Trabajadas. >*/
	                        if(ll_sort(pArrayListPassenger, Passenger_compareBytipoPasajero, sortOption) == 0)
	                        {
	                            printf("Ordenado por TIPO Trabajadas finalizado.\n");
	                        }
	                        break;
	                    case 4: /**< Ordenar por PRECIO de forma Ascendente. >*/
	                        if(ll_sort(pArrayListPassenger, Passenger_compareByprecio, sortOption) == 0)
	                        {
	                            printf("Ordenado por PRECIO finalizado.\n");
	                        }
	                        break;
	                    }
	                }


	            }while(lifeCycle == 0);
	        }
	    }

	    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	 FILE* file = NULL;
	    int todoOk = 0;
	    int arrayLength;
	    int i;
	    Passenger* aux;

	    if(pArrayListPassenger != NULL)
	    {
	        arrayLength = ll_len(pArrayListPassenger);

	        file = fopen(path, "w");

	        if(file != NULL
	           && arrayLength > 0
	           && fprintf(file, "id,nombre,TIPOTrabajadas,sueldo\n") != -1)
	        {
	            for(i = 0; i < arrayLength; i++)
	            {
	                aux = (Passenger*)ll_get(pArrayListPassenger, i);

	                if(aux == NULL
	                   || fprintf(file, "%d,%s,%d,%f2\n", aux->id, aux->nombre, aux->tipoPasajero, aux->precio) == -1)
	                {
	                    break;
	                }
	            }
	        }

	        if(i > 0 && i == arrayLength)
	        {
	            todoOk = 1;
	        }
	    }

	    fclose(file);

	    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	 FILE* file = NULL;
	    int todoOk = 0;
	    int arrayLength;
	    int i;
	    Passenger* aux;

	    if(pArrayListPassenger != NULL)
	    {
	        arrayLength = ll_len(pArrayListPassenger);

	        file = fopen(path, "wb");

	        if(file != NULL && arrayLength > 0 )
	        {
	            for(i = 0; i < arrayLength; i++)
	            {
	                aux = (Passenger*)ll_get(pArrayListPassenger, i);

	                if(aux == NULL
	                   || fwrite((Passenger*)aux, sizeof(Passenger), 1, file) != 1)
	                {
	                    break;
	                }
	            }
	        }

	        if(i > 0 && i == arrayLength)
	        {
	            todoOk = 1;
	        }
	    }

	    fclose(file);

	    return todoOk;
}

