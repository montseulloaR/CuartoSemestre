/*  Universidad Autónoma de Aguascalientes
    Ingeniería en Computación Inteligente
	Centro de Ciencias Básicas
	Departamento de Ciencias de la Computación
	Programación Científica
	Andrea de Santiago Legaspi
	Montserrat Alejandra Ulloa Rivera
	Profesor de la materia: Dr en C. Luis Fernando Gutiérrez Marfileño
	Este programa implementa el método de aproximaciones de punto fijo
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

	printf("Este programa implementa el método de aproximaciones de punto fijo\n");

	while(n!=2){
		printf("\t\nMenú\n");
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
				printf("\nHasta la próxima\n\n");
			break;

			default:
				printf("\nOpción no váilda :( \n");
            break;
		}

	}
	system("pause");
}
