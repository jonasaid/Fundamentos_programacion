//Funciones pila//
#include <stdio.h>
 
typedef struct nodo{
   int valor;
   struct nodo *sig;
}Nodo;
 
typedef struct pila{
   int size;
   Nodo *tope;
}Pila;
 
void initialize (Pila *p){
   p->size=0;
   p->tope=NULL;
}
 
void push (Pila *p, Nodo e){
   e.sig=p->tope;
   p->tope=&e;
   p->size++;
}
 
 
int isEmpty(Pila *p){
   int vacio=0;
   if (p->tope==NULL)
   {
       vacio=1;
   }
   return vacio;
}
 
Nodo* pop (Pila *p){
   if(isEmpty(p)==1){
       return NULL;
   }
   Nodo *anterior_tope=p->tope;
   p->tope=anterior_tope->sig;
   anterior_tope->sig=NULL;
   p->size--;
   return anterior_tope;
}
 
Nodo* top(Pila *p){
   return p->tope;
}
 
int size(Pila *p){
   return p->size;
}

int main (){
   char *operacion;
   printf("Introduce la operación:");
   fgets(operacion, 256, stdin);
}