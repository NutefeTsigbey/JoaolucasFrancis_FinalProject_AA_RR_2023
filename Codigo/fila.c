#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

fila *criaFila(){
    fila *f;
    f = (fila*) malloc (sizeof(fila));
    f->primeiro = NULL;
    f->ultimo = NULL;
    return f;
}

int desenfileirar(fila *f, int *visitado){
    if (f->primeiro == NULL){
        return -1;
    }

    nodo *q;
    q = f->primeiro;
    visitado[q->vertice] = 2;
    f->primeiro = f->primeiro->prox;
    int retorno = q->vertice;
    free (q);

    return retorno;
}

void enfileirar(int vertice, fila *f, int *visitado){
    nodo *q;
    q = (nodo*)malloc(sizeof(nodo));
    q->vertice = vertice;
    visitado[q->vertice] = 1;
    q->prox = NULL;
    q->ant = NULL;

    if (f->primeiro == NULL){
        f->primeiro = q;
        f->ultimo = q;
    } else {
        f->ultimo->prox = q;
        f->ultimo = q;
    }
}
