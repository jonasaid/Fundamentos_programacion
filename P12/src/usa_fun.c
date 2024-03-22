#include "fun.h"
#include <stdio.h>

int main(){
  char a,b,c,d,e;
  a = 'A'; b = 'B'; c = 'C'; d = 'D'; e = 'E';
  printf("%c %c %c %c %c\n",a,b,c,d,e);
  /*Coloca de aquí el código que te permita obtener la 
  configuración que te corresponde*/
  swap5(&a,&b,&c,&d,&e);
  /*hasta aquí*/
  printf("%c %c %c %c %c\n",a,b,c,d,e);
  return 0;
}


