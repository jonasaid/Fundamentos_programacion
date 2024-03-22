#include "matriz.h"
#include <stdlib.h>
#include <time.h>

int num_aleatorio(int num) {
    srand(time(0));
    return (rand() % num);
}

void dos(matriz *m) {
    matriz nueva;
    char salida[100000];
    int renglon = num_aleatorio(m->ren);

    crea_mat(&nueva, 1, m->col);
    for (int i = 0; i < m->col; i++) {
        VAL(&nueva, 0, i) = VAL(m, renglon, i);
    }
    printf("La matriz es:\n%s", acad_mat(salida, &nueva));
}

void tres(matriz *m) {
    matriz nueva;
    char salida[100000];
    int columna = num_aleatorio(m->col);

    crea_mat(&nueva, m->ren, 1);
    for (int i = 0; i < m->ren; i++) {
        VAL(&nueva, i, 0) = VAL(m, i, columna);
    }
    printf("La nueva matriz es:\n%s", acad_mat(salida, &nueva));
}

void cuatro(matriz *m) {
    matriz nueva;
    char salida[100000];
    int minimo = m->datos[0];
    int maximo = m->datos[0];

    for (int i = 0; i < m->ren * m->col; i++) {
        if (m->datos[i] > maximo) {
            maximo = m->datos[i];
        } else if (m->datos[i] < minimo) {
            minimo = m->datos[i];
        }
    }

    crea_mat(&nueva, 1, 2);
    (&nueva)->datos[0] = minimo;
    (&nueva)->datos[1] = maximo;
    printf("La nueva matriz es:\n%s", acad_mat(salida, &nueva));
}

void cinco(matriz *m) {
    matriz nueva;
    char salida[100000];
    crea_mat(&nueva, m->ren, 1);
    for (int i = 0; i < m->ren; i++) {
        int minimo = VAL(m, i, 0);
        for (int j = 0; j < m->col; j++) {
            int valor = VAL(m, i, j);
            if (valor < minimo) {
                minimo = valor;
            }
        }
        VAL(&nueva, i, 0) = minimo;
    }

    printf("La nueva matriz es:\n%s", acad_mat(salida, &nueva));
}

void seis(matriz *m, int renglon, int columna) {
    matriz nueva;
    char salida[100000];

    int renglones;
    if (renglon == columna)
    {
        renglones = m->ren;
    }
    else if (renglon > columna)
    {
        renglones = m->ren - renglon + columna;
    }
    else
    {
        renglones = m->col - columna + renglon;
    }

    crea_mat(&nueva, renglones, 1);
    int posicion_nueva_matriz = 0;
    while (columna != 0 && renglon != 0)
    {
        columna--;
        renglon--;
    }

    while (posicion_nueva_matriz < renglones)
    {
        VAL(&nueva, posicion_nueva_matriz, 0) = VAL(m, renglon, columna);
        posicion_nueva_matriz++;
        renglon++;
        columna++;
    }
    printf("La nueva matriz es:\n%s\ns", acad_mat(salida, &nueva));
}

void siete(matriz *m, int renglon1, int columna1, int renglon2, int columna2) {
    matriz nueva;
    char salida[100000];

    int renglon_inicial = renglon1;
    int renglon_final = renglon2;
    if (renglon2 < renglon1)
    {
        renglon_inicial = renglon2;
        renglon_final = renglon1;
    }

    int columna_inicial = columna1;
    int columna_final = columna2;
    if (columna2 < columna1)
    {
        columna_inicial = columna2;
        columna_final = columna1;
    }

    crea_mat(&nueva, renglon_final - renglon_inicial + 1, columna_final - columna_inicial + 1);
    for (int i = 0; i < renglon_final - renglon_inicial + 1; i++)
    {
        for (int j = 0; j < columna_final - columna_inicial + 1; j++)
        {
            VAL(&nueva, i, j) = VAL(m, i + renglon_inicial, j + columna_inicial);
        }
    }
    printf("La nueva matriz es:\n%s\ns", acad_mat(salida, &nueva));
}

void ocho(matriz *m, int renglon, int columna)
{
    matriz nueva;
    char salida[100000];
    crea_mat(&nueva, m->ren - 1, m->col - 1);
    int nueva_i = 0;
    int nueva_j;
    for (int i = 0; i < m->ren; i++)
    {
        if (renglon == i)
        {
            continue;
        }
        nueva_j = 0;
        for (int j = 0; j < m->col; j++)
        {
            if (columna == j)
            {
                continue;
            }
            VAL(&nueva, nueva_i, nueva_j) = VAL(m, i, j);
            nueva_j++;
        }
        nueva_i++;
    }
    printf("La nueva matriz es:\n%s\ns", acad_mat(salida, &nueva));
}

void nueve(matriz *m)
{
    matriz nueva;
    char salida[100000];
    crea_mat(&nueva, m->col, m->ren);
    for (int i = 0; i < m->ren; i++)
    {
        for (int j = 0; j < m->col; j++)
        {
            VAL(&nueva, j, i) = VAL(m, i, j);
        }
    }

    printf("La nueva matriz es:\n%s\ns", acad_mat(salida, &nueva));
}

void diez(matriz *m, int renglon, int columna)
{
    matriz nueva;
    char salida[100000];
    crea_mat(&nueva, m->ren, 1);
    int i = 1;
    VAL(&nueva, 0, 0) = VAL(m, renglon, columna);
    while (i < m->ren)
    {
        renglon += 2;
        if (renglon >= m->ren)
        {
            renglon = renglon % m->ren;
        }
        columna++;
        if (columna >= m->col)
        {
            columna = columna % m->col;
        }
        VAL(&nueva, i, 0) = VAL(m, renglon, columna);
        i++;
    }
    printf("La nueva matriz es:\n%s\ns", acad_mat(salida, &nueva));
}

