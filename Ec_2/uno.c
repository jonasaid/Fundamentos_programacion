#include <stdio.h>
#include "ecu2.h"
#include "ecu2.c"

void uno(double a, double b, double c) {
    ecu2 ecuacion;
    int resultado;
    
    crea_ecu2(&ecuacion, a, b, c);
    resultado = raiztipo_ecu2(&ecuacion);

    if (resultado == RAIZ_COMPL) {
        printf("Tiene raices complejas \n");
    } else if (resultado == COEFA_CERO) {
        printf("No es una ecuacion cuadratica \n");
    } else {
        printf("Tiene raices reales \n");
    }
}


int main() {
    uno(-4, -2, 2); // reales
    uno(36, -216, 648); // complejas
    uno(0, 1, 1); // no cuadraticas
}