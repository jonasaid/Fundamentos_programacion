//Funciones pila//

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
 
//Estructura de la pila 
typedef struct pila{
   int size;
   Nodo *tope;
}Pila;
 
//Incializa una pila con tamaño 0 y el apuntador tope a nulo  
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

/*Recibe un caracter y me indica si es un operador o no, en caso de que lo sea regresa 0 sino entonces regresa 1*/
int esOperador(char operador){
    int valor = 1;
        if(operador == '+' || operador == '-' || operador == '*' || operador == '/' || operador == '^'){
            valor = 0;
        }
    return valor;
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

//Crea un nodo, modifica su valor y luego lo agrega a la pila
void agregarValorNuevo(Pila* p, char operador){
    Nodo e;
    e.valor = operador;
    push(p,e);
}

/*Se extraen los valores del nodo del tope, se elimina el nodo y agrega el valor del
nodo eliminado a la cadena que se recibe como parametro en la posicion indicada*/
void llevaPostfija (Pila *p, char* operador, int indice){
    Nodo *e= pop(p);
    operador[indice]=e->valor;
    free(e);
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

       //Aquí sabemos si es un operador o no
        if(esOperador(operacion[i]) == 0){

            //Si la pila esta vacía
            if (isEmpty(&pila)){
                agregarValorNuevo(&pila, operacion[i]);

            //Si el operador que se compara es igual al que se encuentra en la pila
            }else if (operacion[i] == pila.tope->valor)
            {
                postfija[contador]=operacion[i];
                contador++;    

            //Si el operador que se quiere agregar es de mayor precedencia al que esta en la pila
            }else if (obtenerPrecedencia(operacion[i]) > obtenerPrecedencia(pila.tope->valor))
            {
                agregarValorNuevo(&pila, operacion[i]);

            //Si el operador que se quiere agregar es de menor o igual precedencia al que esta en la pila
            }else
            {      
                while (isEmpty(&pila) == 0 && obtenerPrecedencia(operacion[i]) <=  obtenerPrecedencia(pila.tope->valor)) 
                {
                    llevaPostfija(&pila, postfija, contador);
                    contador++;
                }
                    
                    
                agregarValorNuevo(&pila, operacion[i]);
            }

        //Si no es un operador se agrega a la cadena postfijo directamente    
        }else
        {
            postfija[contador]=operacion[i];
            contador++; 
        }
           
    }

    //Aqui vaciaremos lo que quede en la pila a postfija mientras no este vacía la pila
    while (isEmpty(&pila) == 0){
        llevaPostfija(&pila, postfija, contador);
        contador++;
    }
    printf("%s \n",postfija);
}