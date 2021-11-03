/* Universidad Autónoma de Aguascalientes
   Ingeniería en Computación Inteligente
   Centro de Ciencias Básicas
   Departamento de Ciencias de la Computación
   Programación Científica
   Andrea de Santiago Legaspi
   Montserrat Alejandra Ulloa Rivera
   Profesor de la materia: Dr. en C. Luis Fernando Gutiérrez Marfileño
   Este programa encuentra las raíces de la función f(x)= xsen(x)-1 por el método de bisecciones sucesivas 
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

float funcion (float x){
	return ((x*(sin(x)))-1);
}

int main(){
	float err, x, y, xm, x1, y1;
	int n=1;
	
	printf("Este programa encuentra las raices de la funcion f(x)= xsen(x)-1 por el metodo de bisecciones sucesivas\n");
	
	while(n!=2){
		printf("\n\tMenu\n");
		printf("1. Seleccionar valor de x y tolerancia de error\n");
		printf("2. Salir\n");
		scanf("%d", &n);
		
		switch(n){
			case 1: {
				printf("\nIntroduzca el valor inicial de x: ");
				scanf("%f", &x);
				x1=x;
				printf("Introduzca el valor inicial de y: ");
				scanf("%f", &y);
				y1=y;
				printf("Introduzca el valor del error: ");
				scanf("%f", &err);
				
			do{
				xm=(x+y)/2;
				if((funcion(x)*funcion(xm))<0){
					y=xm;
				}
				if((funcion(x)*funcion(xm))>0){
					x=xm;
				}
				if((funcion(xm))==0){
					break;
				}
				xm=(x+y)/2;	
			}while((y-xm)>err);
				
				printf("\n\nEl intervalo inicial es (%.9f , %.9f)\n",x1,y1);
				printf("El margen de error es %.9f\n",err);
				printf("La raiz es %.9f \n\n",xm);
				system("pause");
				break;
			}
			case 2: {
				printf("\n Hasta la proxima :)\n\n");
				break;
			}
			default: {
				printf("\n Opcion no valida\n");
				break;
			}
		}
	}
	system("pause");
}
