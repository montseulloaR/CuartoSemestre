/* Universidad Autónoma de Aguascalientes
   Centro de Ciencias Básicas
   Departamento de Ciencias de la Computación
   Montserrat Alejandra Ulloa Rivera
   Profesor de la materia: Dr. en C. Luis Fernando Gutiérrez Marfileño
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float funcion (float x){
	return ((x*(sin(x)))-1);
}

int main(){
	float err, x, y, xm, x1, y1;
	int n=1;
	
	printf("\tMetodo de Biseccion\n");
	printf("Este programa encuentra una raiz de la funcion f(x)= xsen(x)-1 por el metodo de bisecciones sucesivas\n");
	printf("\nIntroduzca el valor x del intervalo: ");
	scanf("%f", &x);
	x1=x;
	printf("Introduzca el valor y del intervalo: ");
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
	return 0;
}
