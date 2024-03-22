#include "ecu2.h"
#include "problemas.h"
#include <stdio.h>

int main() {
    printf("Problema 1: \n");
    uno(-4, -2, 2); // reales
    uno(36, -216, 648); // complejas
    uno(0, 1, 1); // no cuadraticas 
    printf("\n");

    printf("Problema 2: \n");
    dos(1,-6,9,1,-10,25);  //dobles
    dos(1,4,5,1,8,1);  //2,12,6
    dos(1,4,2,2,2,1);  //3,6,3
    dos(0,1,2,0,2,1);  //0,3,3
    printf("\n");

    printf("Problema 3: \n");
    tres(2,4,5,1,8,9);  //3,12,14, compleja
    tres(1,4,5,1,8,1);  //2,12,6
    tres(1,4,2,2,2,1);  //3,6,3
    tres(0,1,2,0,2,1);  //0,3,3
    printf("\n");

    printf("Problema 4: \n");
    cuatro(2,4,5);  
    cuatro(3,6,3);  
    cuatro(2,12,6);  
    cuatro(0,1,2);
    printf("\n");
    
    printf("Problema 5: \n");    
    cinco(2,4,5);   
    cinco(3,6,3); 
    cinco(2,12,6);  
    cinco(0,1,2);
    printf("\n");

    printf("Problema 6: \n");
    seis(2,4,5);   
    seis(3,6,3); 
    seis(2,12,6);  
    seis(0,1,2); 
    printf("\n");

    printf("Problema 8: \n");
    ocho(1,-3,2);  
    ocho(3,6,3);  
    ocho(-2,12,6);  
    ocho(0,1,2); 
    printf("\n");

    printf("Problema 9: \n");
    nueve(2,4,5);  
    nueve(3,6,3);  
    nueve(2,12,6);  
    nueve(0,1,2);
    printf("\n");

    printf("Problema 10: \n");
    diez(2,4,2,1);  
    diez(3,6,3,2);  
    diez(1,-6,9,-1);  
    diez(1,-10,25,-2);
    diez(0,25,-2,-2);
    printf("\n");
    
}