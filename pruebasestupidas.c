#include <stdio.h> 

int main(){ 
    float promedio = 0, calificacion; 
    for (int i = 1; i < 11; i++)
    {
        printf("Dame la calificacion numero %d: ", i);
        scanf("%f", &calificacion);
        if (calificacion > 10)
        {
            printf("No puedes sacar mas de 10");
            return 0;
        }else{
            promedio = calificacion + promedio;    
        }
    }
    promedio = promedio/10;
    printf("Tu promedio es: %f", promedio);
}