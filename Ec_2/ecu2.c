#include "ecu2.h"
/*******************************************************************
*              F U N C I O N E S    A U X I L I A R E S            *
*******************************************************************/
/*Calcula el termino del radical*/
int cal_discr(ecu2* ec){
  /*b*b - 4ac*/
  ec->discr = ec->coefb*ec->coefb -
              4*ec->coefa*ec->coefc;
  return OK;
}
/*******************************************************************
*           F U N C I O N E S    P A R A    O P E R A R            *
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
int crea_ecu2(ecu2* ec, double a, double b, double c){
  if(!NO_CERO(a))
    return COEFA_CERO;
  ec->coefa = a;
  ec->coefb = b;
  ec->coefc = c;
  /*Calcula el termino dentro del radical*/
  cal_discr(ec);
  return OK;
}

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
int raiztipo_ecu2(const ecu2* ec){
  int tipo;
  if (!EC2_VAL(ec))
    tipo=COEFA_CERO;
  else if(ec->discr<0)
    tipo=RAIZ_COMPL;
  else if(ec->discr==0)
    tipo=RAIZ_DOBLE;
  else
    tipo=RAIZ_DIFER;
  return tipo;
}

/*
Calcula la raíz positiva, si la tiene.
Recibe:
  Ecuación de segundo grado
  Apuntador a la raíz de la ecuación
Regresa:
  Ok en caso de éxito o código de error en caso
  de no tener raíz real.
*/
int raizpos_ecu2(double* r,const ecu2* ec){
  if (!EC2_VAL(ec))
    return COEFA_CERO;
  if(!(ec->discr>=0))
    return RAIZ_COMPL;
  *r = (-ec->coefb + sqrt(ec->discr))/(2*ec->coefa);
  return OK;
}

/*
Calcula la raíz negativa, si la tiene.
Recibe:
  Ecuación de segundo grado
  Apuntador a la raíz de la ecuación
Regresa:
  Ok en caso de éxito o código de error en caso
  de no tener raíz real.
*/
int raizneg_ecu2(double* r,const ecu2* ec){
  if (!EC2_VAL(ec))
    return COEFA_CERO;
  if(!(ec->discr>=0))
    return RAIZ_COMPL;
  *r = (-ec->coefb - sqrt(ec->discr))/(2*ec->coefa);
  return OK;
}

/*
Calcula la raíz parte real de la raiz compleja.
Recibe:
  Ecuación de segundo grado
  Apuntador a la parte real de la raíz de la ecuación
Regresa:
  Ok en caso de éxito o código de error en caso
  de no tener raíz compleja.
*/
int raizreal_ecu2(double* r,const ecu2* ec){
  if (!EC2_VAL(ec))
    return COEFA_CERO;
  if(!(ec->discr<0))
    return RAIZ_REAL;
  *r = -ec->coefb/(2*ec->coefa);
  return OK;
}

/*
Convierte la ecuación en una cadena.
Recibe:
  - La cadena que debe tener espacio suficiente
  - La ecuación a ser convertida
Regresa:
  La cadena con la conversión.
Nota:
  Se utiliza una cadena temporal de tamaño TAMCAD
*/
char* tostr_ecu2(char* s, const ecu2* ec){
  char aux[TAMCAD];
  strcpy(s,"");
  strcpy(aux,"");
  /*Coeficiente de x cuadrada*/
  if(ec->coefa!=1.0)
    if(ec->coefa!=-1.0)
      sprintf(aux,FORCONV,ec->coefa);  
    else
      strcat(aux,"-");
  strcat(s,aux);
  strcat(s,"x^2");
  /*Coeficiente de x */
  if(NO_CERO(ec->coefb)){
	if(fabs(ec->coefb)!=1){
	  sprintf(aux,FORCONVS,ec->coefb);
	  strcat(s,aux);
	} else 
      strcat(s,SIGNO(ec->coefb));
	strcat(s,"x");
  }
  /*Coeficiente constante*/
  if(NO_CERO(ec->coefc)){
	sprintf(aux,FORCONVS,ec->coefc);
	strcat(s,aux);
  }
  strcat(s,"=0");
  return s;
}
