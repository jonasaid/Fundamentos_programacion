/*******************************************************************
Objetivo:
   Definir los errores más comunes para utilizar en otros programas.
   Junto con algunas macros sencillas.
Autor: Juan Jesús Gutiérrez García
Observaciones:
  Las constantes definidas son las más utilizadas  dentro de 
  los programas.
  
*******************************************************************/
#ifndef ERRORES_H
#define ERRORES_H

/*******************************************************************
*                       C O N S T A N T E S                        *
*******************************************************************/
#define OK              0    /*No hay errores*/
#define PAR_INV         1    /*Parametro invalido*/ 

/*******************************************************************
*                            M A C R O S                           *
*******************************************************************/
/*Calcula el máximo entre dos valores*/
#define MAX(a,b)      ((a)>(b)?(a):(b))

/*Calcula el minimo entre dos valores*/
#define MIN(a,b)      ((a)<(b)?(a):(b))

#endif