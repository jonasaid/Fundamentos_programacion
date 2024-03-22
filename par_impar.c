#include <stdio.h>

int main(){
  int numero;
  printf("Ingresa un numero \n");
  scanf("%d", &numero);
  numero= numero%2;
  if(numero== 0){
  printf("El numero es par");
  }
  else{
	printf("El numero es impar");	
  }	
  return 0;
}

