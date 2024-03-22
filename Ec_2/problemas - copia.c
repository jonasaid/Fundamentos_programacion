#include <stdio.h>
#include "ecu2.h"

void uno(double a, double b, double c) {
    ecu2 ecuacion;
    int resultado, ok;
    char salida[100];
    
    ok = crea_ecu2(&ecuacion, a, b, c);
    if (ok == COEFA_CERO) {
        printf("No es una ecuacion cuadratica\n");
        return;
    }
    
    printf("La ecuacion es %s\n", tostr_ecu2(salida, &ecuacion));
    resultado = raiztipo_ecu2(&ecuacion);
    if (resultado == RAIZ_COMPL) {
        printf("Tiene raices complejas\n");
    } else {
        printf("Tiene raices reales\n");
    }
    printf("\n");
}

void dos(double a1, double b1, double c1, double a2, double b2, double c2){
    ecu2 ecuacion1, ecuacion2;
    int ok1, ok2, resultado1, resultado2;

    ok1 = crea_ecu2(&ecuacion1, a1, b1, c1);
    if (ok1 == COEFA_CERO) {
        printf("No es una ecuacion cuadratica\n");
        return;
    }
    ok2 = crea_ecu2(&ecuacion2, a2, b2, c2);
    if (ok2 == COEFA_CERO) {
        printf("No es una ecuacion cuadratica\n");
        return;
    }
    resultado1 = raiztipo_ecu2(&ecuacion1);    
    resultado2 = raiztipo_ecu2(&ecuacion2);
    if (resultado1 == RAIZ_DOBLE && resultado2 == RAIZ_DOBLE) {
        double raiz1,raiz2,raizNueva1,raizNueva2;
        double nueva_a=1;
        int ok3;
        raizpos_ecu2(&raiz1,&ecuacion1);
        raizpos_ecu2(&raiz2,&ecuacion2);
        ecu2 ecuacion3;
        ok3 = crea_ecu2(&ecuacion3, nueva_a, -raiz1*-raiz2, raiz1*raiz2);
        raizneg_ecu2(&raizNueva1,&ecuacion3);
        raizpos_ecu2(&raizNueva2,&ecuacion3);
        printf(" %f\n", raizNueva1);
        printf(" %f\n", raizNueva2);
    } else {
        printf(" Las raices introducidas no son raices complejas\n");
    }
}

void tres(double a1, double b1, double c1, double a2, double b2, double c2){
    ecu2 ecuacion3;
    int ok3,resultado;
    ok3=crea_ecu2(&ecuacion3, a1+a2, b1+b2, c1+c2);
    if (ok3 == COEFA_CERO) {
        printf("No es una ecuacion cuadratica\n");
        return;
    }
    resultado = raiztipo_ecu2(&ecuacion3);
    if (resultado == RAIZ_COMPL) {
        printf("Tiene raices complejas\n");
        double raiz;
        raizreal_ecu2(&raiz,&ecuacion3);
        printf(" %f\n", raiz);
        return ;
    }
    if (resultado == RAIZ_DIFER) {
        printf("Tiene raices diferentes y reales\n");
        double raiz1, raiz2;
        raizneg_ecu2(&raiz1,&ecuacion3);
        raizpos_ecu2(&raiz2,&ecuacion3);
        printf(" %f\n", raiz1);
        printf(" %f\n", raiz2);
        return ;
    }
    if (resultado == RAIZ_DOBLE) {
        printf("Tiene una sola raiz doble\n");
        double raiz;
        raizpos_ecu2(&raiz,&ecuacion3);
        printf(" %f\n", raiz);
    }
}

void cuatro(double a, double b, double c){
    ecu2 ecuacion;
    int ok,resultado;
    ok=crea_ecu2(&ecuacion, a, b, c);  
    if (ok == COEFA_CERO) {
        printf("No es una ecuacion cuadratica\n");
        return;
    }   
    if (resultado == RAIZ_DOBLE) {
        printf("La ecuacion solo tiene una solucion\n");
        double raiz;
        raizpos_ecu2(&raiz,&ecuacion);
        printf(" %f\n", raiz);
    } else {
        printf("Las raices eran complejas o reales, pero distintas, se trabajo con ella, y ahora, solo tiene una raiz\n");
        double nueva_c = (b*b)/(4*a);
        double raiz2;
        ecu2 ecuacion2;
        ok=crea_ecu2(&ecuacion2, a, b, nueva_c);
        raizpos_ecu2(&raiz2,&ecuacion2);
        printf(" %f\n", raiz2);

    }

}

void cinco(double a, double b, double c){
    ecu2 ecuacion;
    int ok,resultado;
    ok=crea_ecu2(&ecuacion, a, b, c);
    if (ok == COEFA_CERO) {
        printf("No es una ecuacion cuadratica\n");
        return;
    }
    resultado = raiztipo_ecu2(&ecuacion); 
    if (resultado == RAIZ_DIFER) {
        printf("Raiz diferente\n");
        double raiz1, raiz2;
        raizneg_ecu2(&raiz1,&ecuacion);
        raizpos_ecu2(&raiz2,&ecuacion);
        printf(" %f\n",raiz1);
        printf(" %f\n",raiz2);
    }else {
        printf("La raiz era compleja o era  una raiz igual, hemos hecho algunos cambios, y ahora, tiene 2 raices reales\n");
        double nueva_c=0;
        ecu2 ecuacion2;
        double raiz1,raiz2;
        ok=crea_ecu2(&ecuacion2, a, b, nueva_c);
        raizneg_ecu2(&raiz1,&ecuacion2);
        raizpos_ecu2(&raiz2,&ecuacion2);
        printf(" %f\n",raiz1);
        printf(" %f\n",raiz2);
    }
}

void seis(double a, double b, double c){
    ecu2 ecuacion;
    int ok,resultado;
    ok=crea_ecu2(&ecuacion, a, b, c);
    if (ok == COEFA_CERO) {
        printf("No es una ecuacion cuadratica\n");
        return;
    }
    resultado = raiztipo_ecu2(&ecuacion);
    if (resultado == RAIZ_COMPL) {
        printf("El polinomio tenia raiz compleja, se ha trabajado sobre ella, y ahora, tiene 2 raices reales\n");
        double raiz1,raiz2;
        double nueva_b=(4*a*c);
        ecu2 ecuacion2;
        ok=crea_ecu2(&ecuacion2, a, nueva_b, c);
        raizneg_ecu2(&raiz1,&ecuacion2);
        raizpos_ecu2(&raiz2,&ecuacion2);
        printf(" %f\n", raiz1);
        printf(" %f\n", raiz2);
        return ;
    }
    if (resultado == RAIZ_DOBLE) {
        printf("El polinomio tenia una sola raiz, se ha trabajado sobre ella, y ahora, tiene 2 raices reales\n");
        double raiz1,raiz2;
        double nueva_b=(4*a*c);
        ecu2 ecuacion2;
        ok=crea_ecu2(&ecuacion2, a, nueva_b, c);
        raizneg_ecu2(&raiz1,&ecuacion2);
        raizpos_ecu2(&raiz2,&ecuacion2);
        printf(" %f\n", raiz1);
        printf(" %f\n", raiz2);
        return ;
    }
    if (resultado == RAIZ_DIFER) {
        printf("El polinomio tiene 2 raices reales\n");
        double raiz1,raiz2;
        ok=crea_ecu2(&ecuacion, a, b, c);
        raizneg_ecu2(&raiz1,&ecuacion);
        raizpos_ecu2(&raiz2,&ecuacion);
        printf(" %f\n", raiz1);
        printf(" %f\n", raiz2);
        return ;
    }
}


void nueve(double a, double b, double c){
    ecu2 ecuacion;
    int ok,resultado;
    ok=crea_ecu2(&ecuacion, a, b, c);  
    if (ok == COEFA_CERO) {
        printf("No es una ecuacion cuadratica\n");
        return;
    }   
    resultado = raiztipo_ecu2(&ecuacion);
    if (resultado == RAIZ_DIFER) {
        
        double raiz1, raiz2, puntoMedio;
        raizneg_ecu2(&raiz1,&ecuacion);
        raizpos_ecu2(&raiz2,&ecuacion);
        puntoMedio=(raiz1+raiz2)/2;
        printf(" %f\n", puntoMedio);
    }
    if (resultado == RAIZ_DOBLE) {
        double raiz;
        raizpos_ecu2(&raiz,&ecuacion);
        printf(" %f\n", raiz);
    }
    if (resultado == RAIZ_COMPL) {
        double raiz;
        raizreal_ecu2(&raiz,&ecuacion);
        printf(" %f\n", raiz);
        return ;
    }
}



