#include <stdio.h>
#include "ecu2.h"

void uno(double a, double b, double c) {
    ecu2 polinomio;
    int verificar, res;
    char salida[100];
    
    res = crea_ecu2(&polinomio, a, b, c);
    if (res == COEFA_CERO) {
        printf("No es un polinomio cuadratico\n");
        return;
    }
    
    printf("El polinomio es %s\n", tostr_ecu2(salida, &polinomio));
    verificar = raiztipo_ecu2(&polinomio);
    if (verificar == RAIZ_COMPL) {
        printf("Tiene raices complejas\n");
    } else {
        printf("Tiene raices reales\n");
    }
    printf("\n");
}

void dos(double a1, double b1, double c1, double a2, double b2, double c2){
    ecu2 polinomio1, polinomio2;
    int res1, res2, verificar1, verificar2;

    res1 = crea_ecu2(&polinomio1, a1, b1, c1);
    if (res1 == COEFA_CERO) {
        printf("No es un polinomio cuadratico\n");
        return;
    }
    res2 = crea_ecu2(&polinomio2, a2, b2, c2);
    if (res2 == COEFA_CERO) {
        printf("No es un polinomio cuadratico\n");
        return;
    }
    verificar1 = raiztipo_ecu2(&polinomio1);    
    verificar2 = raiztipo_ecu2(&polinomio2);
    if (verificar1 == RAIZ_DOBLE && verificar2 == RAIZ_DOBLE) {
        double raiz1,raiz2,raizNueva1,raizNueva2;
        double nueva_a=1;
        int res3;
        raizpos_ecu2(&raiz1,&polinomio1);
        raizpos_ecu2(&raiz2,&polinomio2);
        ecu2 polinomio3;
        res3 = crea_ecu2(&polinomio3, nueva_a, raiz1+raiz2, raiz1*raiz2);
        raizneg_ecu2(&raizNueva1,&polinomio3);
        raizpos_ecu2(&raizNueva2,&polinomio3);
        printf(" %f\n", raizNueva1);
        printf(" %f\n", raizNueva2);
    } else {
        printf(" Las raices introducidas no son raices dobles\n");
    }
}

void tres(double a1, double b1, double c1, double a2, double b2, double c2){
    ecu2 polinomio3;
    int res3,verificar;
    res3=crea_ecu2(&polinomio3, a1+a2, b1+b2, c1+c2);
    if (res3 == COEFA_CERO) {
        printf("No es un polinomio cuadratico\n");
        return;
    }
    verificar = raiztipo_ecu2(&polinomio3);
    if (verificar == RAIZ_COMPL) {
        double raiz;
        raizreal_ecu2(&raiz,&polinomio3);
        printf(" %f\n", raiz);
        return ;
    }
    if (verificar == RAIZ_DIFER) {
        double raiz1, raiz2;
        raizneg_ecu2(&raiz1,&polinomio3);
        raizpos_ecu2(&raiz2,&polinomio3);
        printf(" %f\n", raiz1);
        printf(" %f\n", raiz2);
        return ;
    }
    if (verificar == RAIZ_DOBLE) {
        double raiz;
        raizpos_ecu2(&raiz,&polinomio3);
        printf(" %f\n", raiz);
    }
}

void cuatro(double a, double b, double c){
    ecu2 polinomio;
    int res,verificar;
    res=crea_ecu2(&polinomio, a, b, c);  
    if (res == COEFA_CERO) {
        printf("No es un polinomio cuadratico\n");
        return;
    }   
    if (verificar == RAIZ_DOBLE) {
        printf("El polinomio solo tiene un solucion\n");
        double raiz;
        raizpos_ecu2(&raiz,&polinomio);
        printf(" %f\n", raiz);
    } else {
        double nueva_c = (b*b)/(4*a);
        double raiz2;
        ecu2 polinomio2;
        res=crea_ecu2(&polinomio2, a, b, nueva_c);
        raizpos_ecu2(&raiz2,&polinomio2);
        printf(" %f\n", raiz2);

    }

}

void cinco(double a, double b, double c){
    ecu2 polinomio;
    int res,verificar;
    res=crea_ecu2(&polinomio, a, b, c);
    if (res == COEFA_CERO) {
        printf("No es un polinomio cuadratico\n");
        return;
    }
    verificar = raiztipo_ecu2(&polinomio); 
    if (verificar == RAIZ_DIFER) {
        printf("Raiz diferente\n");
        double raiz1, raiz2;
        raizneg_ecu2(&raiz1,&polinomio);
        raizpos_ecu2(&raiz2,&polinomio);
        printf(" %f\n",raiz1);
        printf(" %f\n",raiz2);
    }else {
        double nueva_c=0;
        ecu2 polinomio2;
        double raiz1,raiz2;
        res=crea_ecu2(&polinomio2, a, b, nueva_c);
        raizneg_ecu2(&raiz1,&polinomio2);
        raizpos_ecu2(&raiz2,&polinomio2);
        printf(" %f\n",raiz1);
        printf(" %f\n",raiz2);
    }
}

void seis(double a, double b, double c){
    ecu2 polinomio;
    int res,verificar;
    res=crea_ecu2(&polinomio, a, b, c);
    if (res == COEFA_CERO) {
        printf("No es un polinomio cuadratico\n");
        return;
    }
    verificar = raiztipo_ecu2(&polinomio);
    if (verificar == RAIZ_COMPL) {
        double raiz1,raiz2;
        double nueva_b=(4*a*c);
        ecu2 polinomio2;
        res=crea_ecu2(&polinomio2, a, nueva_b, c);
        raizneg_ecu2(&raiz1,&polinomio2);
        raizpos_ecu2(&raiz2,&polinomio2);
        printf(" %f\n", raiz1);
        printf(" %f\n", raiz2);
        return ;
    }
    if (verificar == RAIZ_DOBLE) {
        double raiz1,raiz2;
        double nueva_b=(4*a*c);
        ecu2 polinomio2;
        res=crea_ecu2(&polinomio2, a, nueva_b, c);
        raizneg_ecu2(&raiz1,&polinomio2);
        raizpos_ecu2(&raiz2,&polinomio2);
        printf(" %f\n", raiz1);
        printf(" %f\n", raiz2);
        return ;
    }
    if (verificar == RAIZ_DIFER) {
        double raiz1,raiz2;
        res=crea_ecu2(&polinomio, a, b, c);
        raizneg_ecu2(&raiz1,&polinomio);
        raizpos_ecu2(&raiz2,&polinomio);
        printf(" %f\n", raiz1);
        printf(" %f\n", raiz2);
        return ;
    }
}

void ocho(double a, double b, double c){
    ecu2 polinomio;
    int res,verificar;
    res=crea_ecu2(&polinomio, a, b, c);  
    if (res == COEFA_CERO) {
        printf("No es un polinomio cuadratico\n");
        return;
    } 
    double valormin_max=(4*a*c-b*b)/(4*a);
    if(a>0) {
        printf("El valor minimo es: %f\n", valormin_max);    
    }else {
        printf("El valor maximo es: %f\n", valormin_max);
    }
}


void nueve(double a, double b, double c){
    ecu2 polinomio;
    int res,verificar;
    res=crea_ecu2(&polinomio, a, b, c);  
    if (res == COEFA_CERO) {
        printf("No es un polinomio cuadratico\n");
        return;
    }   
    verificar = raiztipo_ecu2(&polinomio);
    if (verificar == RAIZ_DIFER) {    
        double raiz1, raiz2, puntoMedio;
        raizneg_ecu2(&raiz1,&polinomio);
        raizpos_ecu2(&raiz2,&polinomio);
        puntoMedio=(raiz1+raiz2)/2;
        printf(" %f\n", puntoMedio);
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

void diez(double a, double b, double c, double alfa){
    ecu2 polinomio;
    int res,verificar;
    res=crea_ecu2(&polinomio, a, b, c);  
    if (res == COEFA_CERO) {
        printf("No es un polinomio cuadratico\n");
        return;
    } 
    verificar = raiztipo_ecu2(&polinomio);
    if (verificar == RAIZ_DOBLE) {
        double raizoriginal;
        raizpos_ecu2(&raizoriginal,&polinomio);
        printf("La raiz original: %f\n", raizoriginal);
        double raiz1;
        res=crea_ecu2(&polinomio, a, (2*alfa*a)+b, (alfa*alfa*a)+(b*alfa)+c);
        raizneg_ecu2(&raiz1,&polinomio);
        printf("La nueva raiz es: %f\n", raiz1);
        return ;
    }    
}



