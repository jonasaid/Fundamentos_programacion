#include <stdio.h>
#define ALTURA -51

int main(){
  int var=ALTURA;
  float var1, var2, var3;
  printf("Este mensaje se imprime\n");
  printf("%d \n", var);
  scanf("%f", &var1);
  printf("%f \n", var1);
  scanf(" %f %f", &var2, &var3);
  printf("%f %f", var2,var3);
  return 0; 
 
}