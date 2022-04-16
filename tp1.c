//============================================================================
// Name        : TP.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int menu();
int kilometrosF(int* kFlag, int* kilometros );
int precioF (int* pFlag, int* aerolineas,int* latam);
int calcular(int* kilometros, int* aerolineas, int* latam, int* cFlag,  float* debitoAerolineas,float* debitoLatam,float* creditoAerolineas,float* creditoLatam,float* precioBitcoinAerolineas, float* precioBitcoinLatam, float* diferenciaPrecio, int* precioUnitarioA );
int cargaForzada(int* kFlag,int* cFlag,int* mFlag, int* pFlag, int* kilometros, int*latam, int*aerolineas,  float* debitoAerolineas,float* debitoLatam,float* creditoAerolineas,float* creditoLatam,float* precioBitcoinAerolineas, float* precioBitcoinLatam, float* diferenciaPrecio, int* precioUnitarioA  );
int mostrar(int* aerolineas, int* latam, int* mFlag,  float* debitoAerolineas,float* debitoLatam,float* creditoAerolineas,float* creditoLatam,float* precioBitcoinAerolineas, float* precioBitcoinLatam, float* diferenciaPrecio, float* precioUnitarioA );


int main() {
	setbuf(stdout, NULL);
	 char seguir = 's';
	    int latam= 0;
	    int aerolineas = 0;
	   int kFlag = 0;
	   int kilometros = 0;
	   int pFlag = 0;
	   int cFlag = 0;
	   int mFlag = 0;
	   float debitoAerolineas = 0;
	   float debitoLatam = 0;
	   float creditoAerolineas = 0;
	   float creditoLatam = 0;
	   float precioBitcoinAerolineas = 0;
	   float precioBitcoinLatam = 0;
	   float diferenciaPrecio =0;
	   int precioUnitarioA = 0;

	   int kFlagCargaForzada = 0;
	   int kilometroCargaForzada = 7090;
	 /*  int precioForzadoA = 162965;
	   int precioForzadoL = 159339;
	   float bitcoin = 4606954.55;*/







	    do{
	    	switch(menu())
	        {


	    case 1:
	       kilometrosF(&kFlag, &kilometros);
	        break;
	    case 2:
	       precioF(&pFlag, &latam, &aerolineas);
	        break;
	    case 3:
	    	calcular(&kilometros, &aerolineas, &latam, &cFlag, &debitoAerolineas, &debitoLatam, &creditoAerolineas, &creditoLatam, &precioBitcoinAerolineas, &precioBitcoinLatam, &diferenciaPrecio, &precioUnitarioA);
	    	break;
	    case 4:
	    	mostrar(&aerolineas, &latam, &mFlag, &debitoAerolineas, &debitoLatam, &creditoAerolineas, &creditoLatam, &precioBitcoinAerolineas, &precioBitcoinLatam, &diferenciaPrecio, &precioUnitarioA);
	    	break;
	    case 5:
	    	cargaForzada(&kFlagCargaForzada, &cFlag, &mFlag, &kilometroCargaForzada, &kilometros, &latam, &aerolineas, &debitoAerolineas, &debitoLatam, &creditoAerolineas, &creditoLatam, &precioBitcoinAerolineas, &precioBitcoinLatam, &diferenciaPrecio, &precioUnitarioA );
	    	break;
	    default:
	            printf("Opcion Invalida!!!");
	        }
	    printf("desea continuar? ");
		fflush(stdin);
		scanf("%c\n", &seguir);
	        }
	    while(seguir == 's');

	    return 0;
	}
	int menu(){
		setbuf(stdout, NULL);
	    int opcion;
	    int cant;
	        system("cls");
	        printf(" *** Menu de Opciones ***\n\n");
	        printf("1- Ingresar Kilómetros: ( km=x)\n");
	        printf("2- Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n");
	        printf("3- Calcular todos los costos:\n");
	        printf("4- Informar Resultados\n");
	        printf("5- Carga forzada de datos\n");
	        printf("Ingrese opcion: \n");
	        fflush(stdin);
	        cant =  scanf("%d", &opcion);
	        if(cant == 0){
	            opcion = 5;
	        }
	        return opcion;
}

	   int kilometrosF(int* kFlag, int* kilometros){
		   setbuf(stdout, NULL);
	     int todoOk = 0;

	     if(kFlag != NULL){
	      printf("ingrese km\n");
	      scanf("%d", &kilometros);
	      *kFlag = 1;
	      todoOk = 1;
	     }
	     return todoOk;
	    }

	int precioF (int* pFlag, int* aerolineas, int* latam){
		setbuf(stdout, NULL);

		int todoOk = 0;
	     if(pFlag != NULL){
	      printf("ingrese precio latam\n");
	      scanf("%d", &aerolineas);

	      printf("ingrese precio aereolineas \n ");
	      scanf("%d", &latam);
	      *pFlag = 1;

	     }
	     return todoOk;
	    }
	int calcular(int* kilometros, int* aerolineas, int* latam, int* cFlag,  float* debitoAerolineas,float* debitoLatam,float* creditoAerolineas,float* creditoLatam,float* precioBitcoinAerolineas, float* precioBitcoinLatam, float* diferenciaPrecio, int* precioUnitarioA ){
		setbuf(stdout, NULL);
		float bitcoin = 4606954.55;

	    	 int todoOk = 0;
	    		     if(cFlag != NULL){
	   *debitoAerolineas = (float) (*aerolineas * 0.9);
	   *debitoLatam = (float) (*latam * 0.9);
	   *creditoAerolineas = (float) (*aerolineas * 1.25);
	   *creditoLatam = (float) (*latam * 1.25);
	   *precioBitcoinAerolineas = (float) (*aerolineas / bitcoin);
	   *precioBitcoinLatam = (float) *latam / bitcoin;
	   *diferenciaPrecio = abs(*latam - *aerolineas);
	   *precioUnitarioA =(*aerolineas/ *kilometros);
	   *cFlag = 1;

	  	     }
	    		     return todoOk;
	  	    }
	int mostrar(int* aerolineas, int* latam, int* mFlag,  float* debitoAerolineas,float* debitoLatam,float* creditoAerolineas,float* creditoLatam,float* precioBitcoinAerolineas, float* precioBitcoinLatam, float* diferenciaPrecio, float* precioUnitarioA ){
		setbuf(stdout, NULL);
			    	 int todoOk = 0;

			    		     if(mFlag != NULL){
			    		    	printf(" a Precio con tarjeta de débito aerolineas: %.2f\n", *debitoAerolineas);
			    		    	printf(" a Precio con tarjeta de débito latam: %.2f\n", *debitoLatam);
			    		    	printf(" a Precio con tarjeta de credito aerolineas: %.2f\n", *creditoAerolineas);
			    		    	printf(" a Precio con tarjeta de credito latam: %.2f\n", *creditoLatam);
			    		    	printf(" a Precio con bitcoin aerolineas %.2f\n", *precioBitcoinAerolineas);
			    		    	printf(" a Precio con bitcoin latam %.2f\n", *precioBitcoinLatam);
			    		    	printf(" diferencia de precios %.2f\n", *diferenciaPrecio);
			    		    	printf(" precio por kilometros aerolineas %.2f\n", *precioUnitarioA);
			    		    	*mFlag = 1;
			  	                todoOk = 1;
			  	                }
			  	     return todoOk;
	}




	int cargaForzada(int* kFlag,int* cFlag,int* mFlag, int* pFlag, int* kilometros, int*latam, int*aerolineas,  float* debitoAerolineas,float* debitoLatam,float* creditoAerolineas,float* creditoLatam,float* precioBitcoinAerolineas, float* precioBitcoinLatam, float* diferenciaPrecio, int* precioUnitarioA  ){
		setbuf(stdout, NULL);
		int todoOk = 0;
		int kilometroCargaForzada = 7090;
		int precioForzadoA = 162965;
	    int precioForzadoL = 159339;
	    *kilometros = kilometroCargaForzada;
	    *latam = precioForzadoL;
	    *aerolineas = precioForzadoA;
	    calcular(&kilometros, &aerolineas, &latam, &cFlag, &debitoAerolineas, &debitoLatam, &creditoAerolineas, &creditoLatam, &precioBitcoinAerolineas, &precioBitcoinLatam, &diferenciaPrecio, &precioUnitarioA);
	    mostrar(&aerolineas, &latam, &mFlag, &debitoAerolineas,&debitoLatam,&creditoAerolineas,&creditoLatam,
	    	    		    				&precioBitcoinAerolineas, &precioBitcoinLatam, &diferenciaPrecio,&precioUnitarioA);

		return todoOk;
}
