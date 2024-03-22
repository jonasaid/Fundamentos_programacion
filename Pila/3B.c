//Funciones pila//
#include <stdio.h>
#include <string.h> 
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

int esOperador(char operador){
    int valor = 1;
        if(operador == '+' || operador == '-' || operador == '*' || operador == '/' || operador == '^' || operador == '(' || operador == ')'){
            valor = 0;
        }
    return valor;
}

/*Analiza un caracter y dependiendo de este regresa un numero, siendo el 
simbolo de potencia el que tiene  valor mas alto, luego division y multiplicacion 
depues, resta y suma y por ultimo, sino es nada de lo anterior regresa un 0*/ 
int obtenerPrecedencia(char operador){
    if (operador == '^'){
        return 3;
    }else if (operador == '/' || operador == '*'){
        return 2;
    }else if (operador == '+' || operador == '-'){
        return 1;
    }else{
        return 0;
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
void* llevaPostfija (Pila *p, char* operador, int indice){
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
        //Verificamos si es un operador
        if(esOperador(operacion[i]) == 0){

            //Si la pila esta vacía, se agrega a la pila
            if (isEmpty(&pila)){
                agregarValorNuevo(&pila, operacion[i]);

            //Si el operador es un parentesis de apertura, se agrega a la pila     
            }else if (operacion[i] == '('){
                    agregarValorNuevo(&pila, operacion[i]); 

            //Si el operador es un parentesis de cierre, se hace pop hasta encontar parentesis de apertura         
            }else if (operacion[i] == ')'){
                while (pila.tope->valor != '('){
                    llevaPostfija(&pila, postfija, contador);
                    contador++;
                }
                pop(&pila);

            //Si el operador de la cadena es igual al que esta en el tope de la pila, se agrega directo a la cadena postfija    
            }else if (operacion[i] == pila.tope->valor){
                postfija[contador]=operacion[i];
                contador++;    

            //Si el operador de la cadena es de mayor precedencia al que esta en la pila, se agrega a la pila    
            }else if (obtenerPrecedencia(operacion[i])>obtenerPrecedencia(pila.tope->valor)){
                agregarValorNuevo(&pila, operacion[i]);

            //Si el operador de la cadena es de menor precedencia al que esta en la pila, se hace pop hasta que las condiciones se cumplan para poder agregar dicho elemento        
            }else{
                while (isEmpty(&pila) == 0 && obtenerPrecedencia(operacion[i]) <= obtenerPrecedencia(pila.tope->valor)){        
                    llevaPostfija(&pila, postfija, contador);
                    contador++;
                }
                agregarValorNuevo(&pila, operacion[i]);
            }

        //Si no es un operador, se pasa directo a postfija    
        }else{
            postfija[contador]=operacion[i];
            contador++;      
        }

    }
    /*Se vacía la pila (todos los elementos), se detecta si hay mas parentesis de apertura y se indica del fallo, en
    caso de que hubiera mas de cierre, entonces el programa no imprime nada debido a la validacion que se tiene en pop*/
    while(isEmpty(&pila) == 0){
        Nodo *de_la_pila=pop(&pila);
        if (de_la_pila->valor == '('){
            printf("Has puesto mas parentesis de apertura que de cierre");
            return 0;
        }else{        
            postfija[contador]=de_la_pila->valor;
            contador++;
            free(de_la_pila);
        }
    }
    printf("%s \n",postfija);
}