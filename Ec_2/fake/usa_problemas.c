#include "ecu8.h"
#include "problemas.h"
#include <stdio.h>

int main() {
	uno(-136, -8, 8); // reales
    uno(18, -825, 1361); // complejas
    uno(0, 1, 1); // no cuadraticas 

   	cuatro(8,136,25);  
    cuatro(3,36,6);  
    cuatro(8,18,36);  
    cuatro(0,1,8); 
	
	nueve(8,136,25);  
    nueve(36,36,36);  
    nueve(8,18,36);  
    nueve(0,1,8);
}