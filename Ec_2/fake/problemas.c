#include <stdio.h>
#include "ecu2.h"

void uno(double a, double b, double c) {
    ecu2 polinomio;
    int verificar, res;
    char salida[100];
    
    res = crea_ecu2(&polinomio, a, b, c);
    if (res == COEFA_CERO) {
        printf("No es una polinomio cuadratica\n");
        return;
    }
    
    printf("La polinomio es %s\n", tostr_ecu2(salida, &polinomio));
    verificar = raiztipo_ecu2(&polinomio);
    if (verificar == RAIZ_COMPL) {
        printf("Tiene raices complejas\n");
    } else {
        printf("Tiene raices reales\n");
    }
    printf("\n");
}

void cuatro(double a, double b, double c){
    ecu2 polinomio;
    int res,verificar;
    res=crea_ecu2(&polinomio, a, b, c);  
    if (res == COEFA_CERO) {
        printf("No es una polinomio cuadratica\n");
        return;
    }   
    if (verificar == RAIZ_DOBLE) {
        double raiz;
        raizpos_ecu2(&raiz,&polinomio);
        printf(" %f\n", raiz);
    } else {
        double otra_c = (b*b)/(4*a);
        double raiz2;
        ecu2 polinomio2;
        res=crea_ecu2(&polinomio2, a, b, otra_c);
        raizpos_ecu2(&raiz2,&polinomio2);
        printf(" %f\n", raiz2);

    }

}


void nueve(double a, double b, double c){
    ecu2 polinomio;
    int res,verificar;
    res=crea_ecu2(&polinomio, a, b, c);  
    if (res == COEFA_CERO) {
        printf("No es una ecuacion cuadratica\n");
        return;
    }   
    verificar = raiztipo_ecu2(&polinomio);
    if (verificar == RAIZ_DIFER) {
        
        double raiz1, raiz2, puntoM;
        raizneg_ecu2(&raiz1,&polinomio);
        raizpos_ecu2(&raiz2,&polinomio);
        puntoM=(raiz1+raiz2)/2;
        printf(" %f\n", puntoM);
    }
    if (verificar == RAIZ_DOBLE) {
        double raiz;
        raizpos_ecu2(&raiz,&polinomio);
        printf(" %f\n", raiz);
    }
    if (verificar == RAIZ_COMPL) {
        double raiz;
        raizreal_ecu2(&raiz,&polinomio);
        printf(" %f\n", raiz);
        return ;
    }
}




