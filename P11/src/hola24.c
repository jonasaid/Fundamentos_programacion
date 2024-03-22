#include <stdio.h>
#define MENSAJE1 "Hola %c %s\n"
#define MENSAJE2 "todos"

int main(){
  printf(MENSAJE1,'a',MENSAJE2);
  return 0;
}
