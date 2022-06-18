#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int optionMenu = 0;
    char salir;
    int contadorPasajeros = 0; /**< Cantidad de Pasajeros cargados en el arreglo. >*/
    LinkedList* listaPasajeros = ll_newLinkedList();
  // char Path[] = "data.csv"; /**< Path del archivo de texto a trabajar. >*/
 //   char binaryPath[] = "data.bin"; /**< Path del archivo binario a trabajar. >*/
    do{

    	optionMenu = menu_main(optionMenu);


    	            if(ll_clear(listaPasajeros) == 0
    	               && ll_len(listaPasajeros) == 0
    	               && ll_deleteLinkedList(listaPasajeros) == 0)
    	            {

    	                exit(EXIT_SUCCESS);
    	            }
    	            else
    	            {
    	            	printf("Error al limpiar la memoria del sistema.");
    	                exit(EXIT_FAILURE);
    	            }


    	         contadorPasajeros = ll_len(listaPasajeros);

    	        switch(optionMenu)
    	        {
    	        case 1: /**< Cargar los datos de los Pasajeros desde el archivo data.csv (modo texto). >*/
    	             contadorPasajeros = controller_loadFromText("data.csv", listaPasajeros);

    	            if( contadorPasajeros > 0)
    	            {
    	                printf("Se cargaron %d Pasajeros desde el archivo de texto.\n",  contadorPasajeros);
    	            }
    	            else
    	            {
    	                printf("No se puede cargar Pasajeros.\n");
    	            }
    	            break;
    	        case 2: /**< Cargar los datos de los Pasajeros desde el archivo data.bin (modo binario). >*/
    	             contadorPasajeros = controller_loadFromBinary("data.bin", listaPasajeros);

    	            if( contadorPasajeros > 0)
    	            {
    	                printf("Se cargaron %d Pasajeros desde el archivo binario.\n",  contadorPasajeros);
    	            }
    	            else
    	            {
    	                printf("No se puede cargar Pasajeros.\n");
    	            }
    	            break;
    	        case 3: /**< Alta de Pasajero. >*/


    	            if(controller_addPassenger(listaPasajeros))
    	            {
    	                printf("Pasajero agregado con exito.\n");
    	            }
    	            else
    	            {
    	                printf("Error de carga del Pasajero.\n");
    	            }
    	            break;
    	        case 4: /**< Modificar datos de Pasajero. >*/
    	            if( contadorPasajeros == 0)
    	            {
    	                printf("No hay Pasajeros cargados en el sistema.\n");
    	            }
    	            else
    	            {
    	                if(controller_editPassenger(listaPasajeros))
    	                {
    	                    printf("Pasajero modificado con exito.\n");
    	                }
    	                else
    	                {
    	                    printf("Se cancelo la edicion.\n");
    	                }
    	            }
    	            break;
    	        case 5: /**< Baja de Pasajero. >*/
    	            if( contadorPasajeros == 0)
    	            {
    	                printf("No hay Pasajeros cargados en el sistema.\n");
    	            }
    	            else
    	            {
    	                if(controller_removePassenger(listaPasajeros))
    	                {
    	                    printf("Pasajero dado de baja con exito.\n");
    	                }
    	                else
    	                {
    	                    printf("No se dio de baja ningun Pasajero.\n");
    	                }
    	            }
    	            break;
    	        case 6: /**< Listar Pasajeros. >*/
    	            if( contadorPasajeros == 0)
    	            {
    	                printf("No hay Pasajeros cargados en el sistema.\n");
    	            }
    	            else
    	            {
    	                 contadorPasajeros = controller_ListPassenger(listaPasajeros);
    	                if( contadorPasajeros > 0)
    	                {
    	                    printf("Se listaron %d Pasajeros cargados en el sistema.\n",  contadorPasajeros);
    	                }
    	            }
    	            break;
    	        case 7: /**< Ordenar Pasajeros. >*/
    	            if( contadorPasajeros == 0)
    	            {
    	                printf("No hay Pasajeros cargados en el sistema.\n");
    	            }
    	            else
    	            {
    	                if(!controller_sortPassenger(listaPasajeros))
    	                {
    	                    printf("Error al efectuar el ordenamiento.\n");
    	                }
    	            }
    	            break;
    	        case 8: /**< Guardar los datos de los Pasajeros en el archivo data.csv (modo texto). >*/
    	            if(!controller_saveAsText("data.csv", listaPasajeros))
    	            {
    	                printf("No se pudo guardar el archivo de texto.\n");
    	            }
    	            else
    	            {
    	                printf("Archivo de texto guardado correctamente.\n");
    	            }
    	            break;
    	        case 9: /**< Guardar los datos de los Pasajeros en el archivo data.bin (modo binario). >*/
    	            if(!controller_saveAsBinary("data.csv", listaPasajeros))
    	            {
    	                printf("No se pudo guardar el archivo binario.\n");
    	            }
    	            else
    	            {
    	                printf("Archivo binario guardado correctamente.\n");
    	            }
    	            break;
    			default:
    						printf("opcion invalida. ingrese un numero de la lista: \n");
    				}
    				fflush(stdin);
    			  }while(salir!='s');

    			printf("gracias!");
    			return 0;
    		}


