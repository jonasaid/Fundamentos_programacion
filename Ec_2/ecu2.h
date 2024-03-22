/*******************************************************************
Objetivo:
   Implementar las operaciones básicas para resolver ecuaciones 
   de segundo grado.
Autor: Juan Jesús Gutiérrez García
Observaciones:
  - Se define una estructura que contiene los coeficientes de la
    ecuación de segundo grado
	               ax^2 + bx + c = 0
  - Se mantiene una variable llamada discriminante que permite 
    verificar cómo son las raices de la ecuación.
  
*******************************************************************/
#ifndef ECU2_H
#define ECU2_H
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "errores.h"
/*******************************************************************
*                      C O N S T A N T E S                         *
*******************************************************************/
/*                 E R R O R E S               */
/* No es una ecuación de segundo grado */
#define COEFA_CERO      10
/*Tipos de Raices*/
#define RAIZ_COMPL      11  /* complejas*/
#define RAIZ_DOBLE      12  /* Dos raices iguales*/
#define RAIZ_DIFER      13  /* Dos raices reales*/
#define RAIZ_REAL       14  /* No son complejas las raices*/

    
/*Cualquier valor menor a VAL_MIN se considera
  Cero*/
#define VAL_MIN   1e-15
/*Tamaño máximo de cadena temporal*/      
#define TAMCAD    15   
/*Formato de conversión de doubel a cadena*/
#define FORCONV   "%5.2f"
#define FORCONVS  "%+5.2f"
/*******************************************************************
*                             M A C R O S                          *
*******************************************************************/
/*Valida que sea aecuación de segundo grado*/
#define EC2_VAL(ec)    ((ec)->coefa!=0)
/*Cualquier valor menor a VAL_MIN se considera
  Cero*/
#define ES_CERO(a)     fabs(a)<VAL_MIN
#define NO_CERO(a)     fabs(a)>VAL_MIN
/*Signo para concatenar*/
#define SIGNO(x)       (x)>0?"+":"-"
/*******************************************************************
*                       T I P O    E C U  2                        *
*******************************************************************/
typedef struct{
  double coefa;
  double coefb;
  double coefc;
  double discr;
} ecu2;
/*******************************************************************
*                    C O N S T R U C T O R A S                     *
*******************************************************************/
/*
Inicializa los coeficientes de la función.
Recibe:
  Tres coeficientes dobules, se verifica que el
  primero de ellos, el coeficiente de la variable
  al cuadrado no sea cero.
  También calcula el discriminante de la función
Regresa:
  Ok en caso de éxito o código de error,
*/
int crea_ecu2(ecu2*, double a, double b, double c);
/*******************************************************************
*                    O B S E R V A D O R A S                       *
*******************************************************************/
/*
Regresa un entero dependiendo del tipo de raiz.
Recibe:
  Ecuación de segundo grado
Regresa:
  - COEFA_CERO: No es ecuación de segundo grado
  - RAIZ_COMPL: Raices son complejas
  - RAIZ_DOBLE: La raíz es doble
  - RAIZ_DIFER: Dos raices reales diferentes
*/
int raiztipo_ecu2(const ecu2*);
/*
Calcula la raíz positiva, si la tiene.
Recibe:
  Ecuación de segundo grado
  Apuntador a la raíz de la ecuación
Regresa:
  Ok en caso de éxito o código de error en caso
  de no tener raíz real.
*/
int raizpos_ecu2(double* r,const ecu2*);
/*
Calcula la raíz negativa, si la tiene.
Recibe:
  Ecuación de segundo grado
  Apuntador a la raíz de la ecuación
Regresa:
  Ok en caso de éxito o código de error en caso
  de no tener raíz real.
*/
int raizneg_ecu2(double* r,const ecu2* ec);
/*
Calcula la raíz parte real de la raiz compleja.
Recibe:
  Ecuación de segundo grado
  Apuntador a la parte real de la raíz de la ecuación
Regresa:
  Ok en caso de éxito o código de error en caso
  de no tener raíz compleja.
*/
int raizreal_ecu2(double* r,const ecu2* ec);
/*
Calcula la raíz parte imaginaria de la raiz compleja.
Recibe:
  Ecuación de segundo grado
  Apuntador a la parte imaginaria de la raíz de la ecuación
Regresa:
  Ok en caso de éxito o código de error en caso
  de no tener raíz compleja.
*/
int raizimag_ecu2(double* r,const ecu2* ec);
/*******************************************************************
*                           S A L I D A                            *
*******************************************************************/
/*
Convierte la ecuación en una cadena.
Recibe:
  - La cadena que debe tener espacio suficiente
  - La ecuación a ser convertida
Regresa:
  La cadena con la conversión.
*/
char* tostr_ecu2(char* s, const ecu2* ec);
#endif	