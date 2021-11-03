/*  Universidad Aut�noma de Aguascalientes
    Ingenier�a en Computaci�n Inteligente
	Centro de Ciencias B�sicas
	Departamento de Ciencias de la Computaci�n
	Programaci�n Cient�fica
	Andrea de Santiago Legaspi
	Montserrat Alejandra Ulloa Rivera
	Profesor de la materia: Dr en C. Luis Fernando Guti�rrez Marfile�o
	Este programa implementa el m�todo de aproximaciones de Newton Raphson
*/
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

int main(){

	int n=0, it, itP;
	float x, xP, err, errP=10000, funcion, derivada;

	printf("Este programa implementa el m�todo de aproximaciones de Newton Raphson \n");

	while(n!=2){
		printf("\n\tMenu\n");
		printf("\t1. Seleccionar valor de x, valor del error y el numero de iteraciones\n");
		printf("\t2. Salir\n");
		scanf("%d", &n);

		switch(n){
			case 1:	
				itP=0; //Reiniciar iteraciones
				printf("\nIntroduzca el valor de x: ");
				scanf("%f",&x); 
				fflush(stdin);
				printf("\nIntroduzca el valor del error: ");
				scanf("%f",&err); 
				printf("\nIntroduzca el numero de iteraciones: ");
				scanf("%d",&it); 
				fflush(stdin);
				puts("Valor \t\t\tFuncion \t\tDerivada \tError");
				
				x = x * (3.1416/180); //Grados a radianes
				while((errP>err)&&(itP<it)){
					funcion = cos(x)-x;
					derivada = (-sin(x))-1;
					xP = x - (funcion/derivada);
					errP = fabs(xP - x);
					x = xP;
					printf("x: %.9f\t  %.9f\t \t%.9f\t \t%.9f\n", x, funcion, derivada, errP);
					itP++;
				}

				printf("\nLa raiz es: %.9f\n", xP);
				printf("Encontrado en %d iteraciones \n", itP);
				printf("\n\n");
				system("pause");
            break;

			case 2:
				printf("\nHasta la pr�xima\n\n");
			break;

			default:
				printf("\nOpci�n no v�ilda :( \n");
            break;
		}

	}
	system("pause");
	return 0;
}
