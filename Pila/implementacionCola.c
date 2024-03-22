//Funciones cola//

/*GRUPO: 2CV11
ALUMNO: JONATHAN SAID GÓMEZ MARBÁN */

#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc 

//Estructura de un nodo
typedef struct nodo{
   char valor;
   struct nodo *sig;
}Nodo;
 
//Estructura de la cola 
typedef struct cola{
   int size;
   Nodo *frente;
   Nodo *final;
}Cola;
 
//Incializa una pila con tamaño 0 y los apuntadores frente y final a nulo  
void initialize (Cola *c){
   c->size=0;
   c->frente=NULL;
   c->final=NULL;
}
 
//Si la cola esta vacía regresa el valor 1 sino regresa un 0 
int isEmpty(Cola *c){
   int vacio=0;
   if (c->frente==NULL)
   {
       vacio=1;
   }
   return vacio;
}

//Agrega un elemento al final de la cola 
void queue (Cola *c, Nodo e){
    Nodo *queue = (Nodo *) malloc(sizeof(Nodo));
    queue->valor = e.valor;
    queue->sig = NULL;
    if (isEmpty(c))
    {
        c->frente=queue;
        c->final=queue;
    }else{
        c->final->sig = queue;
        c->final=queue;
    }
    c->size++;
}
 
//Elimina el elemento de frente 
Nodo* dequeue (Cola *c){
   if(isEmpty(c)==1){
       return NULL;
   }
   Nodo *nodoObtenido = c->frente;
   c->frente = nodoObtenido->sig;
    nodoObtenido->sig = NULL;
   c->size--;
   return nodoObtenido;
}
 
//Indica el nodo de en frente de la cola 
Nodo* front(Cola *c){
   return c->frente;
}
 
//Indica el nodo final de la cola
Nodo* final(Cola *c){
   return c->final;
}

//indica cual es el valor del nodo que se indica a partir de un numero
char element (Cola *c, int indice){
    /*se valida que el numero de elemento que se busca
    sea menor al de la cola*/
    if (indice>c->size)
    {
        return '0';
    }
    //se va iterando sobre los nodos hasta llegar al que se busca
    Nodo* iterador = c->frente;
    for (int i = 1; i < indice; i++)
    {
        iterador = iterador->sig;
    }
    return iterador->valor;
}

//Libera la cola completamente
void destroy(Cola *c){
    while (isEmpty(c) == 0)
    {
        dequeue(c);
    }
    free(c);
}

//Da el tamaño de la cola
int size(Cola* c){
    return c->size;
}

int main(){

    //La implementacion funciona correctamente, puse algunas pruebas dentro del main para corroborarlo 
    Cola cola;
    initialize(&cola);
    Nodo nodo;
    nodo.valor='a';
    queue(&cola, nodo);
    nodo.valor='b';
    queue(&cola, nodo);
    nodo.valor='c';
    queue(&cola, nodo);
    nodo.valor='d';
    queue(&cola, nodo);
    nodo.valor='e';
    queue(&cola, nodo);
    printf("Esta vacia: %d \n",isEmpty(&cola));
    printf("El tamanio es: %d \n",size(&cola));
    printf("El valor al hacer el dequeue es: %c \n", dequeue(&cola)->valor);
    printf("El valor al hacer el dequeue es: %c \n", dequeue(&cola)->valor);
    printf("El valor al hacer el dequeue es: %c \n", dequeue(&cola)->valor);
    printf("El valor al hacer el dequeue es: %c \n", dequeue(&cola)->valor);
    printf("El valor al hacer el dequeue es: %c \n", dequeue(&cola)->valor);
    printf("Esta vacia: %d \n",isEmpty(&cola));
    nodo.valor='y';
    queue(&cola, nodo);
    nodo.valor='z';
    queue(&cola, nodo);
    printf("Esto es el elemento en la posicion 2: %c \n", element(&cola, 2));
    printf("Esto es el elemento en la posicion 3: %c \n", element(&cola, 3));
    return 0;
}
