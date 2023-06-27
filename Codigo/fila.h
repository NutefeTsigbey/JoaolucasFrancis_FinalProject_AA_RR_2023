#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct nodo {
    int vertice;
    struct nodo *prox;
    struct nodo *ant;
} nodo;

typedef struct fila {
    nodo *primeiro;
    nodo *ultimo;
} fila;

fila *criaFila();
int desenfileirar(fila *f, int *visitado);
void enfileirar(int vertice, fila *f, int *visitado);

#endif // FILA_H_INCLUDED
