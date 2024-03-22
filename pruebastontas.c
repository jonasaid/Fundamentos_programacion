#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>



char* inicializarNuevaCadena (char* vectorC){
    char *cadena;
    cadena = (char *) malloc(sizeof(char) * (strlen(vectorC)));
    return cadena;
}

char* convertirCadenaMinuscula(char* cadena){
	for (int i = 0; cadena[i] != '\0'; i++){
		cadena[i] = tolower(cadena[i]);
	}
	return cadena;
}

void crearArregloManual(int* numeros){
    int numeroAGuardar;  
    for (int i = 0; i < 20; i++)
    {
        printf("Introduce el numero, solo faltan %d: ", 20-i);
        scanf("%d",&numeroAGuardar);
        numeros[i]=numeroAGuardar;   
    }
}

void imprimirArreglo(int* numeros){
    printf("Estos son los numeros del arreglo: \n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d \n",numeros[i]);
    }
}

void crearArregloAleatorios (int* numeros){
    for (int i = 0; i < 20; i++)
    {
        int numero;
        int n=1000; 
        numero = rand() % (n+1);
        numeros[i]=numero;  
    }
}

int main(){
    int arreglo[20];
    crearArregloManual(arreglo);
    crearArregloAleatorios(arreglo);
    imprimirArreglo(arreglo);

    return 0;
}