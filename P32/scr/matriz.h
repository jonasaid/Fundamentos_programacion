#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define VALIDA(a)    ((a)!=NULL)
#define VALMAT(m)    (VALIDA(m))&&(VALIDA(m->datos))
#define VAL(m,i,j)   (*( (m)->datos + ((j)*(m)->ren) + (i) ))
#define MIS_REN(a,b) ((a)->ren == (b)->ren)
#define MIS_COL(a,b) ((a)->col == (b)->col)
#define MUL_POS(a,b) ((a)->col == (b)->ren)
#define DIM_IG(a,b)  ( MIS_REN(a,b)&&MIS_COL(a,b) )
#define OK          0
#define NOMEM       1
#define PARA_INV    2
#define DIM_INV     3

typedef struct{
  double *datos;
  int col;
  int ren;
} matriz;

int crea_mat(matriz*,int,int);
int elim_mat(matriz*);
int inic_mat(matriz*,double);

int suma_mat(matriz*,const matriz*,const matriz*);
int mult_mat(matriz* r,const matriz* a,const matriz* b);
char* acad_mat(char*,const matriz*);

int mult_ren(matriz*,int,double);
int suma_ren(matriz*,int,int);

int frostr_mat(matriz* m, const char* ent);

#endif