/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct{

	int id;
	char nombre[20];
	char sexo;
	int edad;
}ePasajero;

void listarPasajero(ePasajero* pasajero);
void ListarPasajeros(LinkedList* lista);
int filterHombres(void* pElement);
int filterMenor(void* pElement);

int filterID(void* pElement, int index);

int main(void)
{ setbuf(stdout, NULL);


    LinkedList* lista = ll_newLinkedList();


    ePasajero p1 = {1277, "Martin", 'f', 16};
    ePasajero p2 = {1255, "Alberto", 'm', 19};
    ePasajero p3 = {1245, "Fabian", 'm', 20};
    ePasajero p4 = {1211, "Zulema", 'm', 21};
    ePasajero p5 = {1231, "Belen", 'f', 22};
    ePasajero p6 = {1232, "Julia", 'f', 15};

    ll_add(lista, &p1);
    ll_add(lista, &p2);
    ll_add(lista, &p3);
    ll_add(lista, &p4);
    ll_add(lista, &p5);
    ll_add(lista, &p6);

    ListarPasajeros(lista);

    LinkedList* hombres = ll_filter(lista, filterHombres);
    printf("HOMBRES\n");
    ListarPasajeros(hombres);

    LinkedList* menores = ll_filter(lista, filterMenor);
    printf("MENORES\n");
    ListarPasajeros(menores);


	/*startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
 	startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort*/

   return 0;
}

void listarPasajero(ePasajero* pasajero){
if(pasajero != NULL){

	printf("%d %10s %c %d\n", pasajero->id, pasajero->nombre,
			pasajero->sexo,pasajero->edad);
}

}
void ListarPasajeros(LinkedList* lista){
	int tam;
	if(lista != NULL){
		tam = ll_len(lista);
		printf("id      Nombre Sexo Edad\n");
		for (int i = 0; i < tam; i++){
			listarPasajero((ePasajero*)ll_get(lista, i));
		}
		printf("\n\n");

	}

}
int filterHombres(void* pElement){

	return ((ePasajero*)pElement)->sexo == 'm';


}
int filterMenor(void* pElement){


	return ((ePasajero*)pElement)->edad < 18;
}

int filterID(void* pElement, int index){


	return ((ePasajero*)pElement)->id == index;
}



























