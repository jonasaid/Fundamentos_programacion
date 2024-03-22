#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

int main(int argc, char *argv[])
{
  char salida[100000];
  char aux[100];
  matriz a[10];
  int i,j,ren,col,nummat;
  double dato;
  scanf("%d",&nummat);
  for(i=0;i<nummat;i++){
	/*Leer tamaño de la matriz*/
	scanf("%d%d",&ren,&col);
	sprintf(salida,"%d %d ",ren,col);
	for(j=0;j<ren*col;j++){
	  scanf("%lf",&dato);
	  sprintf(aux,",%lf",dato);
	  strcat(salida,aux);
	}
	frostr_mat(&a[i],salida);
	printf("La matriz %d es:\n%s",i,acad_mat(salida,&a[i]));
  }
  return 0;
}