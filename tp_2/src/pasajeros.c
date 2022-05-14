/*
 * pasajeros.c
 *
 *  Created on: 13 may. 2022
 *      Author: USUARIO
 */
#include <stdio.h>
#include <stdlib.h>
#include "pasajeros.h"
#include <string.h>

#ifndef PASAJEROS_C_
#define PASAJEROS_C_



#endif /* PASAJEROS_C_ */



int promedioPrecios(Passenger vec[], int tam)
{
    int todoOk = 0;
    float acumPrecio = 0;
    int contPasajeros = 0;
    int contPasajeroMax = 0;
    float promedio = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {
                acumPrecio += vec[i].price;
                contPasajeros++;
            }
        }
        if(contPasajeros != 0)
        {
            promedio = acumPrecio / contPasajeros;
        }
        for(int i=0; i < tam; i++)
                {
                    if( !vec[i].isEmpty)
                    {
                      if(vec[i].price > promedio)
                        {
                         contPasajeroMax++;
                        }
                    }
                }


        system("cls");
        printf("     *** Promedio de Precios ***\n\n");

        printf("Cantidad de Pasajeros: %i \n\n", contPasajeros);
        printf("Promedio Precios: $ %.2f\n\n", promedio);
        printf("Cantidad de Pasajeros que superaron el promedio fue: %i \n\n", contPasajeroMax);
        todoOk = 1;
    }
    return todoOk;
}

int ePasajero_inicializar(Passenger lista[], int tam) {
	int rtn = -1;
	int i;

	if (lista != NULL) {
		if (tam >= 0) {
			for (i = 0; i < tam; i++) {
				//INICIALIZO ESTRUCTURA - LIBRE 0 - OCUPADO 1
				lista[i].isEmpty = 0;
				lista[i].id = 0;
				strcpy(lista[i].name ,"VACIA");
				strcpy(lista[i].lastName ,"VACIA");
				lista[i].price = 0;
				strcpy(lista[i].vuelo.flycode ,"VACIA");
				lista[i].vuelo.statusFlight  = 0;
				lista[i].typePassenger = 0;


			}
			rtn = 0;
		}
	}
	else{
		rtn = 1;
	}

	return rtn;
}


int buscarAsiento(Passenger lista[], int tam){
	int rtn = -1;
	int i;




	if (lista != NULL) {
		if (tam >= 0) {
			for (i = 0; i < tam; i++) {
				//BUSCA EL PRIMER ESPACIO LIBRE DE MI ARRAY
				if(lista[i].isEmpty == 0){
					rtn = i;

					break;
				}
			}
		}
	}

	return rtn;
}


void informarPasajeros(Passenger lista[], int tam){
    printf("                  id||   nombre|| apellido|| precio|| codigo de vuelo ||estado de vuelo|| tipo de pasajero \n\n");
    for (int i = 0; i < tam; i++) {
    	if(!lista[i].isEmpty){


        printf("%20d %8s %8s %11.2f %10s %20d %20d \n",  lista[i].id, lista[i].name, lista[i].lastName, lista[i].price, lista[i].vuelo.flycode, lista[i].vuelo.statusFlight, lista[i].typePassenger );

    }}
    printf("================================================================================================================\n");
    printf("TIPO DE PASAJERO: BAJA 2 || JUBILADO 6 || ADULTO 5 || MENOR 4\n");
    printf("ESTADO DE VUELO: NORMAL 7 || DEMORADO 8 || CANCELADO 9 \n");
    system("PAUSE");
    system("cls");
}


int altaPasajero(Passenger lista[], int tam, int* pNextId)
{
    int todoOk = 0;
    int indice;
    int validacion;
   // char validacionTipo;

    Passenger nuevoPasajero;


 if( lista != NULL && pNextId != NULL && tam > 0)
    {
        system("cls");
        printf("    *** Alta Pasajero ***\n\n");

        buscarAsiento(lista, 1000);
        indice = buscarAsiento(lista, tam);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
        	                        nuevoPasajero.id = *pNextId;

        	                        do{
        	    	    	         printf("Ingrese nombre: ");
        	    	    	         fflush(stdin);
        	    	    	         gets(nuevoPasajero.name);
                                     validacion=validarString(nuevoPasajero.name);
                                    }while(validacion==0);

                                     do{
        	    	    	         printf("Ingrese apellido: ");
        	    	    	         fflush(stdin);
        	    	    	         gets(nuevoPasajero.lastName);
        	    	    	         validacion=validarString(nuevoPasajero.lastName);
                                     }while(validacion==0);


        	    	    	         printf("Ingrese precio: ");
        	    	    	         fflush(stdin);
        	    	    	         scanf("%f", &nuevoPasajero.price);

        	    	    	         printf("Ingrese codigo de vuelo: ");
        	    	    	         fflush(stdin);
        	    	    	         gets(nuevoPasajero.vuelo.flycode);

        	    	    	         printf("Ingrese estado de vuelo 7 normal 8 demorado 9 cancelado : ");
        	    	    	         scanf("%i", &nuevoPasajero.vuelo.statusFlight);


        	    	    	         printf("Ingrese Tipo de pasajero 4 niño 5 adulto 6 jubilado : ");
        	    	    	         scanf("%i", &nuevoPasajero.typePassenger);


        	    	    	         nuevoPasajero.isEmpty = 1;

        	    	    	         lista[indice] = nuevoPasajero;


                                      todoOk = 1;
        }
    }
   (*pNextId)++;
    return todoOk;
}

int modificacionDePasajero(Passenger lista[], int tam, int* pNextId){
	int todoOk =0 ;
	int id;
	int indice;
    char auxiliarNombre[100];
    char auxiliarApellido[100];
    float precio;
    int tipoPasajero;
    int estadoVuelo;
    char auxiliarCodigoVuelo[100];




           informarPasajeros(lista, tam);
	        printf("Ingrese id: ");
	        scanf("%d", &id);

	indice = buscarPasajero(lista, tam, id, &indice);

	 mostrarPasajero(lista[indice]);

	 switch(menuModificarPasajero())
	                 {

	                 case 1:
	                     printf("Ingrese nuevo nombre: ");
	                     fflush(stdin);
	                     gets(auxiliarNombre);

	                     strcpy(lista[indice].name, auxiliarNombre);
	                     printf("Nombre modificado!");
	                     break;
	                 case 2:
	                	 printf("Ingrese nuevo apellido: ");
	                     fflush(stdin);
	                	 gets(auxiliarApellido);

	                     strcpy(lista[indice].lastName, auxiliarApellido);
	                     printf("apellido modificado!");
	                     break;
	                 case 3:
	                	 printf("Ingrese nuevo codigo de vuelo: ");
	                     fflush(stdin);
	                     gets(auxiliarCodigoVuelo);

	                     strcpy(lista[indice].vuelo.flycode, auxiliarCodigoVuelo);
	                	 printf("codigo modificado!");
	                     break;
	                 case 4:
	                     printf("Ingrese nuevo precio: ");
	                     scanf("%f", &precio);

	                     lista[indice].price = precio;
	                     printf("precio modificado!");
	                     break;
	                 case 5:
	                     printf("Ingrese Tipo de pasajero 4 niño 5 adulto 6 jubilado ");
	                     scanf("%i", &tipoPasajero);

	                     lista[indice].typePassenger = tipoPasajero;
	                     printf("Tipo modificado!");
	                     break;
	                 case 6:
	                	 printf("Ingrese estado de vuelo 7 normal 8 demorado 9 cancelado : ");
	                	 scanf("%i", &estadoVuelo);
	                	 lista[indice].vuelo.statusFlight = estadoVuelo;
	                	 printf("estado modificado!");
	                	 break;
	                 default:
	                 					printf("opcion invalida. ingrese un numero de la lista: \n");
	                 }



return todoOk;
}

int buscarPasajero(Passenger lista[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( lista != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !lista[i].isEmpty  && lista[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

void mostrarPasajero(Passenger pasajero)
{

    printf("Nombre: %s\n", pasajero.name);
    printf("apellido: %s\n", pasajero.lastName);
    printf("precio: %.2f\n", pasajero.price);
    printf("tipo de pasajero: %d\n", pasajero.typePassenger);
    printf("codigo de vuelo: %s\n", pasajero.vuelo.flycode);
    printf("estado de vuelo: %d\n", pasajero.vuelo.statusFlight);


}

int bajaPasajero(Passenger lista[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if( lista != NULL && tam > 0 )
    {
    	informarPasajeros(lista, tam);
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarPasajero(lista, tam, id, &indice);


            if(indice == -1)
            {
                printf("No existe un Pasajero con id: %d en el sistema\n", id);
            }
            else
            {

            	mostrarPasajero(lista[indice]);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {

                	lista[indice].isEmpty = 2;
                    strcpy(lista[indice].name ,"BAJA");
                	strcpy(lista[indice].lastName ,"BAJA");
                	lista[indice].price = 0;
                	strcpy(lista[indice].vuelo.flycode ,"0");
                	lista[indice].vuelo.statusFlight = 0;
                	lista[indice].typePassenger = 0;
                    printf("Baja exitosa!!!\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }



            todoOk = 1;
        }
    }
    return todoOk;
}

int hardcodearPasajeros(Passenger lista[], int tam, int cant, int* pNextId)
{
    int todoOk = 0;
  Passenger Pasajeros[10] =
     {
        { 0 ,"Juan", "Lazo", 3441, {"fes324",94},4},
        { 0 ,"Miguel", "Martinez",1451, {"fehg78",8},4},
        { 0 ,"Juana", "Gonzales", 2412, {"fe1401",9},5},
        { 0 ,"Andrea", "Sotomayor", 4543, {"fe3078",8},6},
        { 0 ,"Karen", "Alvarez", 244, {"fe1045",7},5},
		{ 0 ,"Martin", "Palazo", 3448, {"fes324",9},4},
		{ 0 ,"Yasmin", "Martinez",1459, {"fehg78",8},4},
		{ 0 ,"Jorge", "Zuliban", 2416, {"fe1401",9},5},
		{ 0 ,"Alberto", "Sotomayor", 4544, {"fe3078",8},6},
	    { 0 ,"Zulibet", "Rodrigues", 2445, {"fe1045",7},5}

    };

    if( lista != NULL && pNextId != NULL && tam > 0 && tam <= 10 && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
            lista[i] = Pasajeros[i];
            Pasajeros[i].id = *pNextId;
            (*pNextId)++;
        }
        todoOk = 1;
    }
    return todoOk;

}


int ordenarPasajerosTipoPasaApellido(Passenger vec[], int tam)
{
    int todoOk = 0;
    Passenger auxPasajero;

    if( vec != NULL && tam >= 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if((vec[i].typePassenger == vec[j].typePassenger && strcmp(vec[i].lastName,vec[j].lastName) > 0)
                        ||(vec[i].typePassenger != vec[j].typePassenger && (vec[i].typePassenger > vec[j].typePassenger)))
                {
                    auxPasajero = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajero;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int ordenarPasajerosEstadoVueloCodigoaAscendente(Passenger vec[], int tam)
{
    int todoOk = 0;
    Passenger auxPasajero;

    if( vec != NULL && tam >= 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if((vec[i].vuelo.statusFlight == vec[j].vuelo.statusFlight && (vec[i].vuelo.flycode > vec[j].vuelo.flycode))
                        ||(vec[i].vuelo.statusFlight != vec[j].vuelo.statusFlight && (vec[i].vuelo.statusFlight > vec[j].vuelo.statusFlight)))
                {
                    auxPasajero = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajero;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int ordenarPasajerosEstadoVueloCodigoaDescendente(Passenger vec[], int tam)
{
    int todoOk = 0;
    Passenger auxPasajero;

    if( vec != NULL && tam >= 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if((vec[i].vuelo.statusFlight == vec[j].vuelo.statusFlight && (vec[i].vuelo.flycode < vec[j].vuelo.flycode))
                        ||(vec[i].vuelo.statusFlight != vec[j].vuelo.statusFlight && (vec[i].vuelo.statusFlight < vec[j].vuelo.statusFlight)))
                {
                    auxPasajero = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajero;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

