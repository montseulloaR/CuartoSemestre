#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double fx( double x){
    return ((pow(x,10))-1); //Funcion
}

double CalcXM( double Xu, double Xl){
    return (Xu-((fx(Xu)*(Xl-Xu))/(fx(Xl)-fx(Xu)))); //Ecuación
}

int main(int argc, const char * argv[]) {
    int a=0, i=1;
    int Maxite;
    double Xs, Xi, FXL, FXU, XA, FXA, ea, errorpermitido, comparacion, XN, res;
    printf("\tMetodo de Falsa Posicion\n");
    printf("Maximo de iteracciones: ");
    scanf("%d",&Maxite);
    
    printf("Limite inferior: ");
    scanf("%lf",&Xi);
    
    printf("Limite superior: ");
    scanf("%lf",&Xs);

    printf("Error permitido: ");
	scanf("%lf",&errorpermitido);
    
    printf("\ni \t Xl\t\tXu \t\tf(Xl) \t\tf(Xu) \t\tXa \t\tf(Xa) \t\tea");
    
    printf("\n%d\t %.5lf\t %.5lf\t %.5lf\t %.5lf\t %.5lf\t %.5lf\t 100\t\n",i,Xi,Xs,fx(Xi),fx(Xs),CalcXM(Xs, Xi),fx(CalcXM(Xs, Xi)));
    
    do {
        i=i+1;
        comparacion = fx(Xs)*fx(CalcXM(Xs, Xi));
        
        if (comparacion==0) {
            printf("La raiz es: %.5lf", Xi);
        }else if (comparacion<0){
            Xi=CalcXM(Xs, Xi);
        }else{
            Xs=CalcXM(Xs, Xi);
        }
        
        XN = CalcXM(Xs, Xi);
        
        ea = ((XN-CalcXM(Xs, Xi))/XN)*100;
        ea=fabs(Xs-Xi);
        res=CalcXM(Xs, Xi);
      printf("\n%d\t %.5lf\t %.5lf\t %.5lf\t %.5lf\t %.5lf\t %.5lf\t %.5lf\t ",i,Xi,Xs,fx(Xi),fx(Xs),CalcXM(Xs, Xi),fx(CalcXM(Xs, Xi)),ea);
        
        
        
        if (i>=Maxite) {
            a=1;
        }
    } while (a==0 || ea<errorpermitido);
    
    printf("\nRaiz Calculada es %f\n\n", res);
    
    
    
    return 0;
}
