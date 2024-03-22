#include "matriz.h"

int crea_mat(matriz* m,int ren ,int col){
  if(!VALIDA(m)) {
      printf("error nomem\n");
      return NOMEM;
  }
  if(!(ren>0 && col>0)) {
      printf("error para_inv\n");
      return PARA_INV;
  }

  m->datos = (double*) malloc (sizeof(double)*ren*col);
  if(!VALIDA(m->datos)) {
      printf("error nomem2\n");
      return NOMEM;
  }
  m->ren = ren;
  m->col = col;
  inic_mat(m,0.0);
  return OK;
}

int elim_mat(matriz* m){
  if(!VALIDA(m))
    return NOMEM;
  free(m->datos);
  m->datos = NULL;
  m->ren = 0;
  m->col = 0;
  return 0;
}

char* acad_mat(char* sal, const matriz* m){
  char aux[100];
  int i,j;

  if(!VALIDA(sal))
    return sal;
  if(!VALIDA(m))
    strcpy(sal,"null");
  else{
    strcpy(sal,"");
    for(i=0;i<m->ren;i++){
      strcat(sal,"| ");
      for(j=0;j<m->col;j++){
        sprintf(aux," %006.2f ",VAL(m,i,j));
        strcat(sal,aux);
      }
      strcat(sal,"|\n");
    }
  }
  return sal;
}

int inic_mat(matriz* m,double v){
  int i;
  if(!VALMAT(m))
    return NOMEM;
  for(i=0;i<m->ren*m->col;i++)
    m->datos[i] = v;
  return OK;
}

int suma_mat(matriz* r,const matriz* a,const matriz* b){
  int i,err;
  if(!VALIDA(r))
    return NOMEM;

  if(!(VALMAT(a)&&VALMAT(b)))
    return NOMEM;
  if (!DIM_IG(a,b))
    return DIM_INV;
  elim_mat(r);
  err=crea_mat(r,a->ren,a->col);
  if (!(err==OK))
    return err;
  for(i=0;i<a->ren*a->col;i++)
    r->datos[i] = a->datos[i]+b->datos[i];
  return OK;
}


int mult_mat(matriz* r,const matriz* a,const matriz* b){
  int err,i,j,k;
  double acum;
  if(!VALIDA(r))
    return NOMEM;

  if(!(VALMAT(a)&&VALMAT(b)))
    return NOMEM;
  if (!MUL_POS(a,b))
    return DIM_INV;
  elim_mat(r);
  err=crea_mat(r,a->ren,b->col);
  if (!(err==OK))
    return err;

  for(i=0;i<a->ren;i++)
    for(j=0;j<b->col;j++){
      acum = 0;
      for(k=0;k<a->col;k++)
        acum += VAL(a,i,k)*VAL(b,k,j);
      VAL(r,i,j) = acum;
    }
  return OK;
}

int mult_ren(matriz* m,int ren ,double c){
  int i;
  char salida[900];
  if(!VALIDA(m))
    return NOMEM;
  if( !(ren>=0 && ren<m->ren))
    return PARA_INV;

  for(i=0;i<m->col;i++)
    VAL(m,ren,i) = VAL(m,ren,i) * c;
  return OK;
}

int suma_ren(matriz*m ,int ori,int des){
  int i;
  double valor;
  if(!VALIDA(m))
    return NOMEM;
  if( !(ori>=0 && ori<m->ren))
    return PARA_INV;
  if( !(des>=0 && des<m->ren))
    return PARA_INV;
  valor = -VAL(m,des,ori);
  for(i=0;i<m->col;i++)
    VAL(m,des,i) = VAL(m,des,i) + valor* VAL(m,ori,i);
  return OK;
}

int frostr_mat(matriz* m, const char* ent){
  int i,j,res;
  int numren,numcol;
  const char* aux = ent;
  double dato;
  sscanf(ent,"%d%d",&numren,&numcol);
  res = crea_mat(m,numren,numcol);
  if (res==OK){
  /*Datos de la matriz*/
  for(i=0;i<numren;i++)
	for(j=0;j<numcol;j++){
	  while(*aux!=',') aux++;
	  aux++;
	  sscanf(aux,"%lf",&dato);
	  VAL(m,i,j) = dato;
	}
  }
  return res;
}
