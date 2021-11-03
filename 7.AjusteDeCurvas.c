/*  Universidad Autónoma de Aguascalientes
    Ingeniería en Computación Inteligente
	Centro de Ciencias Básicas
	Departamento de Ciencias de la Computación
	Programación Científica
	Andrea de Santiago Legaspi
	Montserrat Alejandra Ulloa Rivera
	Profesor de la materia: Dr en C. Luis Fernando Gutiérrez Marfileño
	Este programa implementa el método de regresión lineal, el polinomio de interpolación único, de Lagrange y de Newton
*/
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	
	float datosx[10], datosy[10], a[10], matriz[10][10], coefElimin[10][10], pol, sol, coef[10], res[10];
	float suma_x, suma_y, sumaxy, sumax2, a0, a1, sup=1, inf=1;
	int m=0, num,n, x, P, i, j, k;

	printf("Este programa implementa el metodo de regresion lineal, el polinomio de interpolacion unico, de Lagrange y de Newton \n");
	
		while(m!=5){
		printf("\n\t\tMenu\n");
		printf("\t1. Regresion lineal\n");
		printf("\t2. Polinomo de interpolacion unico\n");
		printf("\t3. Polinomio de interpolacion de Lagrange\n");
		printf("\t4. Polinomio de interpolacion de Newton\n");
		printf("\t5. Salir\n");
		scanf("%d", &m);
		
		//Reiniciar valores
		for(i=0; i<10; i++){
			for(j=0; j<10; j++){
				matriz[i][j] = 0;
				coefElimin[i][j] = 0;
			}
			datosx[i]=0;
			datosy[i]=0;
			a[i] = 0;
		}
		x=0; suma_x=0; suma_y=0; sumaxy=0; sumax2=0; a0=0; a1=0; pol=0; sol=0;
		
		switch(m){
			case 1:		//Regresión Lineal
				printf("\tRegresion Lineal");
				n=0;
				printf("\nProporcionar el numero de ninos: ");
				scanf("%d", &num);
				printf("\n");
				for(i=0; i<num; i++){
					printf("Ingresa la edad del nino %d: ", i+1);
					scanf("%f", &matriz[i][0]);
					printf("Ingresa el peso del nino %d: ", i+1);
					scanf("%f", &matriz[i][1]);
					printf("\n");
					suma_x+= matriz[i][0];
					suma_y+= matriz[i][1];
				}
				printf("Ingresa la edad cuyo peso hay que encontrar: ");
				scanf("%d", &x);
				
				for(i=0;i<num;i++){
					matriz[i][2]= matriz[i][0]*matriz[i][1];
					matriz[i][3]= pow(matriz[i][0],2);
					sumaxy+= matriz[i][2];
					sumax2+= matriz[i][3];
				}
				
				a1= ((num*sumaxy)-(suma_x*suma_y))/((num*sumax2)-(pow(suma_x,2)));
				a0= (suma_y-(a1*suma_x))/num;
				printf("\nEcuacion de la recta de regresion:");
				printf("\ny= %f + %f(x)", a0, a1);
				sol= a0 + (a1*x);
				printf("\n\nPeso aproximado de un nino de edad %d: %f\n\n", x, sol);
					
				system("pause");
            break;
            
            case 2:	//Polinomio único
            	sol=0;
            	printf("\tPolinomio de interpolacion unico");
				n=0;
				printf("\nProporcionar el numero de datos: ");
				scanf("%d", &num);
				printf("\n");
				for(i=0; i<num; i++){
					printf("Ingresa primer valor del punto %d: ", i+1);
					scanf("%f", &datosx[i]);
					printf("Ingresa el segundo valor del punto %d: ",i+1);
					scanf("%f", &datosy[i]);
					matriz[i][num]=datosy[i];
					printf("\n");
				}
				
				printf("Ingresa el valor a interpolar: ");
				scanf("%d", &x);
				
				for(i=0; i<num;i++){
					matriz[i][0]=1;		//Llenar la primera columna de la matriz de 1's
				}
				for(i=0; i<=num; i++){
					matriz[i][1]= datosx[i];		//Llenar la segunda columna de la matriz con los datos en x
				}
				
				while(n<=num){
					for(i=0; i<num;i++){
						for(j=2; j<num; j++){
							matriz[i][j]= pow(datosx[i],j); 	//Apartir de aquí llenar las n columnas de la matriz con los datos elevados a la n potencia
						}
					}
					n++;
				}
				printf("\n");
				
				//Resolver sistema de ecuaciones por Método de Gauss
				
				//Eliminacion hacia adelante
				for(P=0; P<num-1; P++){
					for(i=P+1; i<num; i++){
						for(j=P; j<num+1; j++){
							coefElimin[i][j] = (matriz[i][P]/matriz[P][P])*matriz[P][j]; //Pivote
						}
						for(j=P; j<num+1; j++){
							matriz[i][j] = matriz[i][j] - coefElimin[i][j]; //Diferencia
						}
					}
				}
				
				//Sustitución
				for(i=num-1; i>=0; i--){
					for(j=num-1; j>i; j--){
						a[i] = a[i] + (a[j] * matriz[i][j]);
					}
					a[i] = (matriz[i][num] - a[i])/matriz[i][i];
				}
				
				//Valores del vector a
				for(i=0; i<num; i++){
					printf(" a%d = %f", i+1, a[i]);
				}

				n=0; i=0;
				while(n<num){
					pol=a[i]*pow(x,i);
					sol= sol+pol;
					i++;
					n++;
				}
				printf("\n\nSolucion del polinomio:\n");
				printf("P(%d)= %f\n\n", x,sol);
				
				system("pause");
            break;
            
            case 3:
            	sol=0;
            	i=0;
            	//Interpolación de Lagrange	
            	printf("\tPolinomio de interpolacion de Lagrange");
				n=0;
				printf("\nProporcionar el numero de datos: ");
				scanf("%d", &num);
				printf("\n");
				for(i=0; i<num; i++){
					printf("Ingresa primer valor del punto %d: ", i+1);
					scanf("%f", &datosx[i]);
					printf("Ingresa el segundo valor del punto %d: ",i+1);
					scanf("%f", &datosy[i]);
					printf("\n");
				}
				
				printf("Ingresa el valor a interpolar: ");
				scanf("%d", &x);
				
				for(i=0; i<num; i++){
            		sup=1;
            		inf=1;
            		
		            for(j=0; j<num; j++){ 
		                if(j!=i)
		                {	
		                    sup=sup*(x-datosx[j]);
		                    //printf("(%f x - %f x / ", x, datosx[j]);
		                    inf=inf*(datosx[i]-datosx[j]);
		                    //printf("%f x - %f x) + \n", datosx[i], datosx[j]);
		                }
		            }
		            sol=sol+((sup/inf)*datosy[i]); 
		        }
		        printf("\n\nSolucion del polinomio:\n");
				printf("P(%d)= %f\n\n", x,sol);
				system("pause");
            break;
            
            case 4:
            	//Interpolación de Newton
            	printf("\tPolinomio de interpolacion de Newton");
				n=0;
				printf("\nProporcionar el numero de datos: ");
				scanf("%d", &num);
				printf("\n");
				for(i=0; i<num; i++){
					printf("Ingresa primer valor del punto %d: ", i+1);
					scanf("%f", &datosx[i]);
					printf("Ingresa el segundo valor del punto %d: ",i+1);
					scanf("%f", &datosy[i]);
					printf("\n");
				}
				
				for(i = 0; i < num; i++){
 					res[i] = datosy[i];
 				}
				
				coef[0] = datosy[0];
				
				 //Tabla de Coeficientes
				for(j = 1; j < num; j++){
 					for(i = 0; i < num - j; i++){
 						res[i] = (res[i+1] - res[i])/(datosx[i+j] - datosx[i]);
 						if(i==0){
 							printf("%f\n",(res[i+1] - res[i])/(datosx[i+j] - datosx[i]));
						 }
 					}
 					coef[j] = res[0];
 				}
 				
 				printf("f(x) = ");
 				for(i = 0; i < num; i++){
 					printf("%f",coef[i]);
 					for(j = 0; j < i; j++){
 					printf("(x - %f )", datosx[j]);
 					}
 					
 					if(i < (num - 1)){printf(" + ");}
 				}
 				
 				system("pause");
			break;
			
			case 5:
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

