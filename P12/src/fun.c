#include "fun.h"

void swap2 (char* x,char* y){
  char aux;
  aux = *x;
  *x = *y;
  *y = aux;
  return;
}

void swap3 (char* a,char* b,char* c){
  swap2(a,b);
  swap2(b,c);
  return;
}

 /*Este es el ejercicio que me fue asignado para realizar
   el día de la práctica, es el número 41.*/
   
void swap5 (char* a,char* b,char* c,char* d,char* e){
  char aux;
  aux = *a;
  *a = *b;
  *b = *d;
  *d = aux;
  aux = *c;
  *c = *e;
  *e = aux;
  return;
}

/*En las lineas de código de abajo he realizado las 
  definiciones de las funciones todos los ejercicios 
  de la práctica invocando la función swap2 y/o swap3 
  dentro de las demás funciones.*/
   
void swap28 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,b);
  swap2(e,d);
  swap2(e,c);
  return;
}

void swap28_ver2 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,b);
  swap3(c,d,e);
  return;
}

void swap29 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,b);
  swap2(c,d);
  swap2(c,e);
  return;  
}

void swap29_ver2 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,b);
  swap3(e,d,c);
  return;  
}

void swap34 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,e);
  swap2(a,d);
  swap2(a,c);
  swap2(a,b);
  return;    
}            
			 
void swap35 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,d);
  swap2(a,e);
  swap2(a,c);
  swap2(a,b);
  return;    
}            
			 
void swap41 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,d);
  swap2(a,b);
  swap2(c,e);
  return;  
}

void swap41_ver2 (char* a,char* b,char* c,char* d,char* e){
  swap2(c,e);
  swap3(d,a,b);
  return;  
}

void swap42 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,e);
  swap2(a,c);
  swap2(a,d);
  swap2(a,b);
  return;  
}

void swap43 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,c);
  swap2(a,d);
  swap2(a,e);
  swap2(a,b);
  return;  
}

void swap52 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,b);
  swap2(a,e);
  swap2(a,d);
  swap2(a,c);
  return;  
}

void swap53 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,b);
  swap2(a,d);
  swap2(a,e);
  swap2(a,c);
  return;  
}

void swap62 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,c);
  swap2(b,e);
  swap2(b,d);
  return;  
}

void swap62_ver2 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,c);
  swap3(d,e,b);
  return;  
}

void swap64 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,e);
  swap2(a,d);
  swap2(a,b);
  swap2(a,c);
  return;  
}

void swap65 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,d);
  swap2(a,b);
  swap2(a,e);
  swap2(a,c);
  return;  
}

void swap66 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,e);
  swap2(a,c);
  swap2(d,b);
  return;  
}

void swap67 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,c);
  swap2(b,d);
  swap2(b,e);
  return;  
}

void swap71 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,d);
  swap2(a,c);
  swap2(b,e);
  return;  
}

void swap72 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,e);
  swap2(a,b);
  swap2(a,d);
  swap2(a,c);
  return;  
}

void swap77 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,b);
  swap2(a,d);
  swap2(c,e);
  return;  
}

void swap78 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,b);
  swap2(a,e);
  swap2(a,c);
  swap2(a,d);
  return;  
}

void swap88 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,e);
  swap2(a,d);
  swap2(b,c);
  return;  
}

void swap89 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,d);
  swap2(b,e);
  swap2(b,c);
  return;  
}

void swap90 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,e);
  swap2(a,c);
  swap2(a,b);
  swap2(a,d);
  return;  
}

void swap91 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,c);
  swap2(a,e);
  swap2(a,b);
  swap2(a,d);
  return;  
}

void swap92 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,c);
  swap2(a,d);
  swap2(b,e);
  return;  
}

void swap93 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,d);
  swap2(b,c);
  swap2(b,e);
  return;  
}

void swap94 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,e);
  swap2(a,b);
  swap2(a,c);
  swap2(a,d);
  return;  
}

void swap97 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,b);
  swap2(a,c);
  swap2(a,d);
  swap2(a,e);
  return;  
}

void swap101 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,b);
  swap2(a,d);
  swap2(a,c);
  swap2(a,e);
  return;  
}

void swap102 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,b);
  swap2(a,e);
  swap2(c,d);
  return;  
}

void swap109 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,c);
  swap2(a,b);
  swap2(a,d);
  swap2(a,e);
  return;  
}

void swap111 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,d);
  swap2(a,e);
  swap2(b,c);
  return;  
}

void swap113 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,d);
  swap2(a,c);
  swap2(a,b);
  swap2(a,e);
  return;  
}

void swap114 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,e);
  swap2(b,d);
  swap2(b,c);
  return;  
}

void swap115 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,c);
  swap2(a,e);
  swap2(b,d);
  return;  
}

void swap116 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,c);
  swap2(a,d);
  swap2(a,b);
  swap2(a,e);
  return;  
}		

void swap117 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,d);
  swap2(a,b);
  swap2(a,c);
  swap2(a,e);
  return;  
}

void swap118 (char* a,char* b,char* c,char* d,char* e){
  swap2(a,e);
  swap2(b,c);
  swap2(b,d);
  return;  
}