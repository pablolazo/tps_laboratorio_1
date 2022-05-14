/*
 ============================================================================
 Name        : tp_Dos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#include "menu.h"
#include "pasajeros.h"
#include "imput.h"
#include "vuelo.h"



#define TAM 1000
#define LIBRE 1
#define OCUPADO 0
#define BAJA 2
#define JUBILADO 6
#define ADULTO 5
#define MENOR 4
#define NORMAL 7
#define DEMORADO 8
#define CANCELADO 9








int main () {
	setbuf(stdout, NULL);
	int entradaAMenu = 0;


	int opcion ;
	char exit;
	int proximoId = 1000;

    int cargadoConExito;
	int contadorPasajeros = 0;
	int ordenamientoDos;



    Passenger lista[TAM];


ePasajero_inicializar( lista,TAM );
	do{
			opcion= Menu(entradaAMenu);
			switch(opcion){
				case 1:



					cargadoConExito = altaPasajero(lista, TAM, &proximoId);
					if(cargadoConExito == 1){
						printf("cargado con exito");
						contadorPasajeros++;
					}



				break;
				case 2:
                  if(contadorPasajeros==0)
                  {
                	  printf("no hay pasajeros cargados ingrese opcion 1 \n");
                  }
                  else{
				modificacionDePasajero(lista, TAM, &proximoId);
                  }


				break;
				case 3:

		       if(contadorPasajeros==0)
		       {
			     printf("no hay pasajeros cargados ingrese opcion 1 \n");
				}
			   else{
					bajaPasajero(lista, TAM);}

				break;
				case 4:
					if(contadorPasajeros==0)
				 {  printf("no hay pasajeros cargados ingrese opcion 1 \n");
			     }
				 else{

					informarPasajeros(lista,TAM);}
				break;
				case 5:

					cargadoConExito = hardcodearPasajeros(lista, TAM, 10, &proximoId);
					if(cargadoConExito == 1){
					printf("cargado con exito");
					contadorPasajeros++;
					}
					informarPasajeros(lista,TAM);
				break;
				case 6:
					if(contadorPasajeros==0)
					{  printf("no hay pasajeros cargados ingrese opcion 1 \n");
					}
					else{
					ordenarPasajerosTipoPasaApellido(lista,TAM);
			        informarPasajeros(lista,TAM);}

					break;
				case 7:
					if(contadorPasajeros==0)
					{  printf("no hay pasajeros cargados ingrese opcion 1 \n");
					}
					else{
					printf("descendente o ascendente? 1 DESCENDENTE || 2 ASCENDENTE \n");
					scanf("%i",&ordenamientoDos);
					if(ordenamientoDos != 1 || ordenamientoDos != 2){
				    printf("opcion invalida!! descendente o ascendente? 1 DESCENDENTE || 2 ASCENDENTE \n");
					}
					else{
					if(ordenamientoDos==1){
					ordenarPasajerosEstadoVueloCodigoaDescendente(lista,TAM);
			        informarPasajeros(lista,TAM);}
					else{
						ordenarPasajerosEstadoVueloCodigoaAscendente(lista, TAM);
						informarPasajeros(lista, TAM);
					}
					}}
					break;
				case 8:
					if(contadorPasajeros==0)
				 {  printf("no hay pasajeros cargados ingrese opcion 1 \n");
				}
					else{
					   promedioPrecios(lista, TAM);}
					break;


				case 9:
					exit='s';
					break;

				default:
					printf("opcion invalida. ingrese un numero de la lista: \n");
			}
			fflush(stdin);
		  }while(exit!='s');

		printf("gracias!");
		return 0;
	}












