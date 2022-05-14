/*
 * imput.c
 *
 *  Created on: 13 may. 2022
 *      Author: USUARIO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imput.h"


int validarString(char palabra[]){
	int todoOk =1 ;
	int i;

	for(i=0 ; i<strlen(palabra); i++){
		if(!((palabra[i]>=65 && palabra[i]<=90) || (palabra[i]>=97 && palabra[i]<=122)))
		{
			printf("ingrese letras validas nuevamente\n");

			todoOk =0;
		}
	}
  return todoOk;

}

