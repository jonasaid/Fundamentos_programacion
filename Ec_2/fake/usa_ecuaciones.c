#include "ecu0.h"
#include "problemas.h"
#include <stdio.h>

int main() {
    uno(-0, -0, 0); 		// reales
    uno(0, -0, 0); 			// dobles
    uno(0, -0, 0); 			// complejas
    uno(0, 0, 0); 			// no cuadraticas 

    dos(0,-0,0,0,-0,0);  	//reales
    dos(0,0,0,0,0,0);  		//dobles
    dos(0,0,0,0,0,0);  		//complejas
    dos(0,0,0,0,0,0);  		//no cuadratica

    tres(0,0,0,0,0,0);  	//reales
    tres(0,0,0,0,0,0);  	//dobles
    tres(0,0,0,0,0,0);  	//complejas
    tres(0,0,0,0,0,0);  	//no cuadratica 

    cuatro(0,0,0);  
    cuatro(0,0,0);  
    cuatro(0,00,0);  
    cuatro(0,0,0);
    
    cinco(0,0,0);   
    cinco(0,0,0); 
    cinco(0,00,0);  
    cinco(0,0,0);

    seis(0,0,0);   
    seis(0,0,0); 
    seis(0,0,0);  
    seis(0,0,0); 

    ocho(0,-0,0);  
    ocho(0,0,0);  
    ocho(-0,0,0);  
    ocho(0,0,0); 

    nueve(0,0,0);  
    nueve(0,0,0);  
    nueve(0,0,0);  
    nueve(0,0,0);

    diez(0,0,0,0);  
    diez(0,0,0,0);  
    diez(0,-0,0,-0);  
    diez(0,-0,0,-0);
    diez(0,0,-0,-0);


    
}