#include <stdio.h> /*fgets, sscanf */
#include <stdlib.h> /*malloc, free*/
#include <string.h> /*strlen*/
#include <stdbool.h> /*Para poder declarar variables de tipo booleano
                         y asignales un valor de verdadero o falso*/

/*Función imprimirMenu, no regresa nada, no recibe parámetros.
Esta función simplemente imprime en pantalla el menú que se 
especifica en la práctica.*/
void imprimirMenu()
{
    printf("\n\t\t:::Menu:::");
    printf("\n1. Introducir una nueva cadena");
    printf("\n2. Imprimir la cadena");
    printf("\n3. Invertir la cadena");
    printf("\n4. Concatenar consigo misma");
    printf("\n5. Salir");
}

/*introducirNuevaCadena, no regresa nada, recibe como parametro un apuntador a caracter.
Pide al usuario introducir una cadena y luego lee esa cadena introducida*/
void introducirNuevaCadena(char *vectorC)
{
    printf("Introduce una cadena: ");
    fgets(vectorC, 256, stdin);
}

/*imprimirCadena, no regresa nada, recibe como parametro un apuntador a caracter.
Hace la impresion en la consola o pantalla de una cadena*/
void imprimirCadena(char *vectorC)
{
    printf("%s", vectorC);
}

/*inicializarNuevaCadena regresa un apuntador a caracter, recibe como parametro un apuntador a caracter.
Recibe un apuntador a caracter, despues reserva espacio en la memoria a traves de la funcion malloc donde 
multiplica el tamaño del apuntador por el tamaño de un caracter, lo asigna a una variable y m regresa dicha
variable.*/
char *inicializarNuevaCadena(char *vectorC)
{
    char *cadena;
    cadena = (char *)malloc(sizeof(char) * (strlen(vectorC)));
    return cadena;
}

/*invertirCadena, recibe un apuntador a caracter, regresa un apuntador a caracter
Esta funcion nos permite cambiar la cadena, haciendo que quede de manera opuesta, 
es decir, invertir la cadena; primero reservamos espacio en la memoria y lo almacenamos
en un apuntador a caracter, luego, a traves de recorrer las posiciones del 
parametro y las de otro apuntador a caracter y asignando valores, se logra  invertir la cadena,
finaliza el ciclo e imprime la cadena invertida y la funcion me regresa esa cadena*/
char *invertirCadena(char *vectorC)
{
    char *cadena;
    cadena = inicializarNuevaCadena(vectorC);
    for (int i = strlen(vectorC) - 2, k = 0; i >= 0; i--, k++)
    {
        cadena[k] = vectorC[i];
    }
    cadena[strlen(vectorC) - 1] = '\0';
    imprimirCadena(cadena);
    return cadena;
}

/*concatenarCadena, recibe un entero y un apuntador a carcter y regresa un apuntador a caracter
Primero se lee el numero de veces que se va a repetir la cadena, luego a traves de if's, analizamos
en que diferente caso es en el que se encuentra, ejecuta el codigo correspondiente, por ultimo
imprime la cadena y la funcion me regresa dicha cadena.*/
char *concatenarCadena(int numeroVeces, char *vectorC)
{
    printf("\nNumero de veces: ");
    char numeroVecesCadena[5];
    fgets(numeroVecesCadena, 6, stdin);
    sscanf(numeroVecesCadena, "%d", &numeroVeces);
    if (numeroVeces == 0)
    {
        printf("");
        return 0;
    }
    bool eraPositivo = true;
    if (numeroVeces < 0)
    {
        eraPositivo = false;
        numeroVeces *= -1;
    }
    char *cadena;
    cadena = (char *)malloc(sizeof(char) * (strlen(vectorC) - 1) * numeroVeces + sizeof(char));
    for (int i = 0; i < numeroVeces; i++)
    {
        if (eraPositivo)
        {
            for (int j = 0; j < strlen(vectorC) - 1; j++)
            {
                cadena[j + ((strlen(vectorC) - 1) * i)] = vectorC[j];
            }
        }
        else
        {
            for (int j = strlen(vectorC) - 2, k = 0; j >= 0; j--, k++)
            {
                cadena[k + ((strlen(vectorC) - 1) * i)] = vectorC[j];
            }
        }
    }
    cadena[(strlen(vectorC) - 1) * numeroVeces] = '\0';
    imprimirCadena(cadena);
    return cadena;
}

int main()
{
    char valorUsuario[255];
    int seleccionNum;
    char seleccion;
    char *nuevaCadena;

    introducirNuevaCadena(valorUsuario);

    do
    {
        imprimirMenu();

        printf("\nOpcion seleccionada: ");
        fgets(&seleccion, 3, stdin);
        sscanf(&seleccion, "%d", &seleccionNum);

        switch (seleccionNum)
        {
        case 1:
            printf("\nTu seleccion fue introducir una nueva cadena: \n");
            introducirNuevaCadena(valorUsuario);
            break;
        case 2:
            printf("\nTu seleccion fue imprimir la cadena: \n");
            imprimirCadena(valorUsuario);
            break;
        case 3:
            printf("\nTu seleccion fue invertir cadena: \n");
            nuevaCadena = invertirCadena(valorUsuario);
            free(nuevaCadena);
            break;
        case 4:
            printf("\nTu seleccion fue concatenar cadena");
            int numeroVeces;
            nuevaCadena = concatenarCadena(numeroVeces, valorUsuario);
            free(nuevaCadena);
            break;
        case 5:
            printf("\nTu seleccion fue salir \nAdios.");
            return 0;
        default:
            printf("\nPon atencion");
        }
    } while (true);
}
