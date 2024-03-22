//Funciones pila//
#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc 

//Estructura de un nodo
typedef struct nodo{
   char valor;
   struct nodo *sig;
}Nodo;
 
//Estructura de la pila 
typedef struct pila{
   int size;
   Nodo *tope;
}Pila;
 
//Incializa una pila con valores  y NULL 
void initialize (Pila *p){
   p->size=0;
   p->tope=NULL;
}
 
//Si la pila esta vacía regresa el valor 1 sino regresa un 0 
int isEmpty(Pila *p){
   int vacio=0;
   if (p->tope==NULL)
   {
       vacio=1;
   }
   return vacio;
}

//Agrega un elemento a la pila y lo coloca en el tope de la misma
void push (Pila *p, Nodo e){
   Nodo *pushing = (Nodo *) malloc(sizeof(Nodo));
   pushing->sig = p->tope;
   pushing->valor = e.valor;
   p->tope=pushing;
   p->size++;
}
 
//Elimina el elemento que se encuentre en el tope
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
 
//Indica el tope de la pila 
Nodo* top(Pila *p){
   return p->tope;
}
 
//Indica el tamaño de la pila  
int size(Pila *p){
   return p->size;
}

/*Analiza un caracter y dependiendo de este regresa un numero, siendo el 
simbolo de potencia el que tiene  valor mas alto, luego division y multiplicacion }
y por ultimo, resta y suma*/ 
int obtenerPrecedencia(char operador){
    if (operador == '^'){
        return 3;
    }else if (operador == '/' || operador == '*'){
        return 2;
    }else{
        return 1;
    }
}

int main (){
   char operacion[255];
   char postfija[255];
   Pila pila; 
   int contador=0; 
   initialize(&pila);
   printf("Introduce la operacion: \n");
   fgets(operacion, 256, stdin);
   for (int i = 0; i < strlen(operacion)-1; i++){
        if(operacion[i] == '+' || operacion[i] == '-' || operacion[i] == '*' || operacion[i] == '/' ||operacion[i] == '^'){
            if (isEmpty(&pila)){
                Nodo nodo1;
                nodo1.valor=operacion[i];
                push(&pila,nodo1);
            }else if (operacion[i] == pila.tope->valor)
            {
                postfija[contador]=operacion[i];
                contador++;    
            }else if (obtenerPrecedencia(operacion[i])>obtenerPrecedencia(pila.tope->valor))
            {
                Nodo nodo2;
                nodo2.valor=operacion[i];
                push(&pila,nodo2);
            }else
            {
                Nodo *de_la_pila=pop(&pila);
                postfija[contador]=de_la_pila->valor;
                contador++;
                free(de_la_pila);

                Nodo nodo3;
                nodo3.valor=operacion[i];
                push(&pila,nodo3);
            }
        }else
        {
            postfija[contador]=operacion[i];
            contador++; 
        }
           
    }
    while (isEmpty(&pila) == 0){
        Nodo *de_la_pila;
        de_la_pila=pop(&pila);
        postfija[contador]=de_la_pila->valor;
        contador++;
        free(de_la_pila);
    }
    printf("%s",postfija);
}