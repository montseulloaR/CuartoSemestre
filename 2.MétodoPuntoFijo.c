/*  Universidad Aut�noma de Aguascalientes
    Ingenier�a en Computaci�n Inteligente
	Centro de Ciencias B�sicas
	Departamento de Ciencias de la Computaci�n
	Programaci�n Cient�fica
	Andrea de Santiago Legaspi
	Montserrat Alejandra Ulloa Rivera
	Profesor de la materia: Dr en C. Luis Fernando Guti�rrez Marfile�o
	Este programa implementa el m�todo de aproximaciones de punto fijo
*/
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

int main(){

	setlocale(LC_ALL,"");

	int n=0;
	float x, xP, err, errP=10000;

	printf("Este programa implementa el m�todo de aproximaciones de punto fijo\n");

	while(n!=2){
		printf("\t\nMen�\n");
		printf("1. Seleccionar valor de x y valor del error\n");
		printf("2. Salir\n");
		scanf("%d", &n);

		switch(n){
			case 1:
				printf("\nIntroduzca el valor de x: ");
				scanf("%f",&x); 
				fflush(stdin);
				printf("\nIntroduzca el valor del error: ");
				scanf("%.9f",&err); 
				printf("\n%.9f",err);
				fflush(stdin);
				puts("Valor \t\t Error");
				
				while(errP>err){
					xP = pow(2.718281828, (-x));
					errP = xP - x;
					if(errP>err){
						x = xP;
						printf("x: %.9f\t %.9f", x, errP);
						printf("\n%.9f",err);
					}
				}
				
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
}
