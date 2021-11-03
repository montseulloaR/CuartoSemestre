/* Universidad Autónoma de Aguascalientes
   Centro de Ciencias Básicas
   Departamento de Ciencias de la Computación
   Montserrat Alejandra Ulloa Rivera
   Profesor de la materia: Dr. en C. Luis Fernando Gutiérrez Marfileño
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double fx(double x){
    return ((x*(sin(x)))-1);
}

double CalcXm( double Xs, double Xi){
    return (Xs-((fx(Xs)*(Xi-Xs))/(fx(Xi)-fx(Xs))));
}

int main() {
    int a=0, i=1;
    int Maxite;
    double Xs, Xi, FXi, FXs, Xm, FXm, ea, error, comparacion, XN, res;
    printf("\tMetodo de Falsa Posicion\n");
    printf("Este programa encuentra una raiz de la funcion f(x)= xsen(x)-1 por el metodo de la falsa posicion\n");
    printf("Maximo de iteraciones: ");
    scanf("%d",&Maxite);
    
    printf("Limite inferior: ");
    scanf("%lf",&Xi);
    
    printf("Limite superior: ");
    scanf("%lf",&Xs);

    printf("Error permitido: ");
    scanf("%lf",&error);
    
    do {
        i=i+1;
        comparacion = fx(Xs)*fx(CalcXm(Xs, Xi));
        
        if (comparacion==0) {
            printf("La raiz es: %.5lf", Xi);
        }else if (comparacion<0){
            Xi=CalcXm(Xs, Xi);
        }else{
            Xs=CalcXm(Xs, Xi);
        }
        
        res=CalcXm(Xs, Xi);
        
        
        
        if (i>=Maxite) {
            a=1;
        }
    } while ((fabs(fx(CalcXm(Xs, Xi)))>error)&&a==0);
    
    printf("\nRaiz Calculada es %f en %d iteraciones \n\n", res, i);
    
    
    
    return 0;
}
