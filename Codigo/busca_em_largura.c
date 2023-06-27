#include <stdio.h>
#include <stdlib.h>
#include "busca_em_largura.h"
#include "fila.h"

int buscaLargura(int vertice, int *caminho, int **grafo, int **fluxo) {
    int *visitado = (int*) calloc(vertice+1, sizeof(int));
    fila *f = criaFila();

    enfileirar(vertice, f, visitado);
    visitado[vertice] = 1;

    while (f->primeiro != NULL) {
        int verticeAtual = desenfileirar(f, visitado);
        caminho[verticeAtual] = 1;

        for (int i = 0; i <= vertice; i++) {
            if (grafo[verticeAtual][i] > fluxo[verticeAtual][i] && visitado[i] == 0) {
                enfileirar(i, f, visitado);
                visitado[i] = 1;
            }
        }
    }

    int encontrado = caminho[vertice];
    free(visitado);
    free(f);

    return encontrado;
}
