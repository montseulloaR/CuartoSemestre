/*  Universidad Autónoma de Aguascalientes
    Ingeniería en Computación Inteligente
	Centro de Ciencias Básicas
	Departamento de Ciencias de la Computación
	Programación Científica
	Andrea de Santiago Legaspi
	Montserrat Alejandra Ulloa Rivera
	Profesor de la materia: Dr en C. Luis Fernando Gutiérrez Marfileño
	Este programa implementa el método de la Regla de Cramer para resolver sistemas de ecuaciones lineales en forma exacta
*/
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

float determinante(float c[][5]){
	int det, det1, det2, det3;
	det1= c[0][0]*((c[1][1]*c[2][2])-(c[1][2]*c[2][1]));
	det2= -c[0][1]*((c[1][0]*c[2][2])-(c[1][2]*c[2][0]));
	det3= c[0][2]*((c[1][0]*c[2][1])-(c[1][1]*c[2][0]));
	det= det1+det2+det3;
	return det;
}
float determinante2(float co[][5]){
	int deter= ((co[0][0]*co[1][1])-(co[0][1]*co[1][0]));
	return deter;
}
int main(){
	
	float coef[5][5], coef1[5][5], coef2[5][5], coef3[5][5], ind[5];
	int n=0, dim, i, j;
	float x,y,z, d, d1, d2, d3;

	printf("Este programa implementa el metodo de la Regla de Cramer para resolver sistemas de ecuaciones lineales en forma exacta \n");
	
		while(n!=2){
		printf("\t\nMenu\n");
		printf("1. Iniciar metodo\n");
		printf("2. Salir\n");
		scanf("%d", &n);

		switch(n){
			case 1:	
				printf("\nProporcionar la dimension del sistema: ");
				scanf("%d", &dim);
				
				for(i=0; i<dim; i++){
					for(j=0; j<dim; j++){
						printf("Ingrese el coeficiente %d de la ecuacion %d: ", j+1, i+1);
						scanf("%f", &coef[i][j]);
					}
					printf("Ingrese el termino independiente de la ecuacion %d: ", i+1);
					scanf("%f", &ind[i]);
					printf("\n");
				}
				
				printf("\nDeterminante del sistema: \n");
				for(i=0; i<dim; i++){
					for(j=0; j<dim; j++){
						printf("%.0f  ",coef[i][j]);
					}
					printf("\n");
				}
				
				switch(dim){
					case 2:
						//Función para calcular la determinante
						d= determinante2(coef);
						printf("\nValor de la determinante: %.0f", d);
						
						//Matriz auxiliar para reemplazar términos
						for(i=0; i<dim; i++){
							for(j=0; j<dim; j++){
								coef1[i][j]= coef[i][j];
							}
						}
						
						//Reemplazando términos independientes en la primera columna
						for(i=0; i<dim; i++){
							coef1[i][0]=ind[i];
						}
				
						printf("\n\nReemplazando terminos independientes en la primera columna \n");
						for(i=0; i<dim; i++){
							for(j=0; j<dim; j++){
								printf("%.0f  ",coef1[i][j]);
							}
							printf("\n");
						}
						d1=determinante2(coef1);
						printf("\nValor de la determinante 1: %.0f", d1);
				
						//Matriz auxiliar para reemplazar términos
						for(i=0; i<dim; i++){
							for(j=0; j<dim; j++){
								coef2[i][j]= coef[i][j];
							}
						}
				
						//Reemplazando términos independientes en la segunda columna
						for(i=0; i<dim; i++){
							coef2[i][1]=ind[i];
						}
				
						printf("\n\nReemplazando terminos independientes en la segunda columna \n");
						for(i=0; i<dim; i++){
							for(j=0; j<dim; j++){
								printf("%.0f  ",coef2[i][j]);
							}
							printf("\n");
						}
						d2=determinante2(coef2);
						printf("\nValor de la determinante 2: %.0f", d2);
						
						x= d1/d;
						y= d2/d;
				
						printf("\n\nSolucionn del sistema: ");
						printf("\nValor de x: %.1f", x);
						printf("\nValor de y: %.1f \n\n", y);
						
					break;
					case 3:

						//Función para calcular la determinante
						d= determinante(coef);
						printf("\nValor de la determinante: %.0f", d);
				
						//Matriz auxiliar para reemplazar términos
						for(i=0; i<dim; i++){
							for(j=0; j<dim; j++){
								coef1[i][j]= coef[i][j];
							}
						}
				
						//Reemplazando términos independientes en la primera columna
						for(i=0; i<dim; i++){
							coef1[i][0]=ind[i];
						}
				
						printf("\n\nReemplazando terminos independientes en la primera columna \n");
						for(i=0; i<dim; i++){
							for(j=0; j<dim; j++){
								printf("%.0f  ",coef1[i][j]);
							}
							printf("\n");
						}
						d1=determinante(coef1);
						printf("\nValor de la determinante 1: %.0f", d1);
				
						//Matriz auxiliar para reemplazar términos
						for(i=0; i<dim; i++){
							for(j=0; j<dim; j++){
								coef2[i][j]= coef[i][j];
							}
						}
				
						//Reemplazando términos independientes en la segunda columna
						for(i=0; i<dim; i++){
							coef2[i][1]=ind[i];
						}
				
						printf("\n\nReemplazando terminos independientes en la segunda columna \n");
						for(i=0; i<dim; i++){
							for(j=0; j<dim; j++){
								printf("%.0f  ",coef2[i][j]);
							}
							printf("\n");
						}
						d2=determinante(coef2);
						printf("\nValor de la determinante 2: %.0f", d2);
				
						//Matriz auxiliar para reemplazar términos
						for(i=0; i<dim; i++){
							for(j=0; j<dim; j++){
								coef3[i][j]= coef[i][j];
							}
						}
				
						//Reemplazando términos independientes en la tercera columna
						for(i=0; i<dim; i++){
							coef3[i][2]=ind[i];
						}
				
						printf("\n\nReemplazando terminos independientes en la tercera columna \n");
						for(i=0; i<dim; i++){
							for(j=0; j<dim; j++){
								printf("%.0f  ",coef3[i][j]);
							}
							printf("\n");
						}
						d3=determinante(coef3);
						printf("\nValor de la determinante 3: %.0f", d3);
				
						x= d1/d;
						y= d2/d;
						z=d3/d;
				
						printf("\n\nSolucionn del sistema: ");
						printf("\nValor de x: %.1f", x);
						printf("\nValor de y: %.1f", y);
						printf("\nValor de z: %.1f \n\n", z);
					break;
					
					default:
						printf("\n\nPor favor ingrese una dimension entre 2 y 3\n\n");
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
}

