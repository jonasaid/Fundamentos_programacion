#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

 
int main()
{
  char valorUsuario[255];
  int seleccionNum;
  char seleccion;

  printf("Introduce una cadena: ");
  fgets(valorUsuario, 256, stdin);

  printf("\nLa cadena introducida es: %s", valorUsuario);
  printf("\nLa cantidad de caracteres es: %lu", strlen(valorUsuario) - 1);
  printf("\n\t\t:::Menu:::");
  printf("\n1. Introducir una nueva cadena");
  printf("\n2. Imprimir la cadena");
  printf("\n3. Invertir la cadena");
  printf("\n4. Concatenar consigo misma");
  printf("\n5. Salir");

  printf("\nOpcion seleccionada: ");
  fgets(&seleccion, 3, stdin);
  sscanf(&seleccion, "%d", &seleccionNum);

  switch (seleccionNum)
  {
  case 1:
    printf("\nTu seleccion fue introducir una nueva cadena: \n");
    printf("Introduce una nueva cadena: ");
    fgets(valorUsuario, 256, stdin);
    
    break;
  case 2:
    printf("\nTu seleccion fue imprimir la cadena: \n"); 
    printf("%s", valorUsuario);
    break;
  case 3:
    printf("\nTu seleccion fue invertir cadena: \n");
    char *nuevaCadena;
    nuevaCadena = (char *) malloc(sizeof(char) * (strlen(valorUsuario)));

    for (int i = strlen(valorUsuario) - 2, k=0; i >= 0; i--, k++)
    {
	   //printf("anadiendo %c\n",valorUsuario[i]); 
       nuevaCadena[k]=valorUsuario[i];
    }
    nuevaCadena[strlen(valorUsuario)-1]='\0';

    printf("%s", nuevaCadena);
    free(nuevaCadena);
    break;
  case 4:
    printf("\nTu seleccion fue concatenar cadena");
    int numeroVeces;
    printf("\nNumero de veces: ");
    scanf("%d", &numeroVeces);

    //char *nuevaCadena;
    bool eraPositivo = true;

    if (numeroVeces < 0)
    {
      eraPositivo = false;
      numeroVeces *= -1;
    }
    nuevaCadena = (char *) malloc(sizeof(char) * (strlen(valorUsuario) - 1) * numeroVeces + sizeof(char));

    for (int i = 0; i < numeroVeces; i++)
    {
      if (eraPositivo)
      {
        for (int j = 0; j < strlen(valorUsuario) - 1; j++)
        {
		  printf("anadiendo %c\n", valorUsuario[j]);
          nuevaCadena[j + ((strlen(valorUsuario) - 1) * i)] = valorUsuario[j];
        }
      } else {
        for (int j = strlen(valorUsuario) - 2, k = 0; j >= 0; j--, k++)
        {
          nuevaCadena[k + ((strlen(valorUsuario) - 1) * i)] = valorUsuario[j];
        }
      }
    }

    nuevaCadena[(strlen  (valorUsuario)-1) * numeroVeces] = '\0';

    printf("%s", nuevaCadena);
    free(nuevaCadena);

    break;
  case 5:
    return 0;   
  default:
    printf("\nPon atencion");
    return 0;
  }
}
