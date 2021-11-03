/*  Universidad Autónoma de Aguascalientes
    Ingeniería en Computación Inteligente
	Centro de Ciencias Básicas
	Departamento de Ciencias de la Computación
	Programación Científica
	Montserrat Alejandra Ulloa Rivera
	Profesor de la materia: Dr en C. Luis Fernando Gutiérrez Marfileño
	Es programa implementa el método Gauss para resolver sistemas de ecuaciones lineales en forma exacta
*/

#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
	
float coef[10][11], coefElimin[10][10], x[10];
int main(){
	int n=0, dim, i, j, P;

	printf("Este programa implementa el metodo de Gauss para resolver sistemas de ecuaciones lineales en forma exacta \n");
	
		while(n!=2){
		printf("\t\nMenu\n");
		printf("1. Iniciar metodo\n");
		printf("2. Salir\n");
		scanf("%d", &n);
		
		//Reiniciar matrices
		for(i=0; i<10; i++){
			for(j=0; j<10; j++){
				coef[i][j] = 0;
				coefElimin[i][j] = 0;
			}
			x[i] = 0;
		}

		switch(n){
			case 1:	
				printf("\nProporcionar la dimension del sistema: ");
				scanf("%d", &dim);
				puts("");
				puts("Sitsema de ecuaciones recomendado:");
				puts("2x1 + x2 + 3x3 = 1");
				puts("2x1+ 6x2+ 8x3 = 3");
				puts("6x1 + 8x2 + 18x3 = 5");
				for(i=0; i<dim; i++){
					for(j=0; j<dim; j++){
						printf("Ingrese el coeficiente %d de la ecuacion %d: ", j+1, i+1);
						scanf("%f", &coef[i][j]);
					}
					printf("Ingrese el termino independiente de la ecuacion %d: ", i+1);
					scanf("%f", &coef[i][dim]);
					printf("\n");
				}
				
				//Eliminacion hacia adelante
				for(P=0; P<dim-1; P++){
					for(i=P+1; i<dim; i++){
						for(j=P; j<dim+1; j++){
							coefElimin[i][j] = (coef[i][P]/coef[P][P])*coef[P][j]; //Pivote
						}
						for(j=P; j<dim+1; j++){
							coef[i][j] = coef[i][j] - coefElimin[i][j]; //Diferencia
						}
					}
				}
				
				//Sustitucion
				for(i=dim-1; i>=0; i--){
					for(j=dim-1; j>i; j--){
						x[i] = x[i] + (x[j] * coef[i][j]);
					}
					x[i] = (coef[i][dim] - x[i])/coef[i][i];
				}
				
				//Resultados
				for(i=0; i<dim; i++){
					printf(" x%d = %f", i+1, x[i]);
					puts(" ");
				}
				
				system("pause");
            break;

			case 2:
				printf("\nHasta la proxima\n\n");
			break;

			default:
				printf("\nOpcion no valida :( \n");
            break;
		}
	}
	system("pause");
	return 0;
}

