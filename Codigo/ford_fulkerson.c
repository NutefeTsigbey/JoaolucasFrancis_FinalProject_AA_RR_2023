#include <stdio.h>
#include <stdlib.h>
#include "ford_fulkerson.h"
#include "busca_em_largura.h"

int fordFulkerson(int vertice, int **grafo) {
    int **fluxo = (int**) malloc((vertice + 1) * sizeof(int*));
    for (int i = 0; i <= vertice; i++) {
        fluxo[i] = (int*) malloc((vertice + 1) * sizeof(int));
        for (int j = 0; j <= vertice; j++) {
            fluxo[i][j] = 0;
        }
    }

    int *caminho = (int*) calloc(vertice + 1, sizeof(int));
    int maxFluxo = 0;

    while (buscaLargura(0, caminho, grafo, fluxo)) {
        int minCapacidade = INT_MAX;

        for (int i = 1; i <= vertice; i++) {
            if (caminho[i] && grafo[0][i] > fluxo[0][i]) {
                if (grafo[0][i] - fluxo[0][i] < minCapacidade) {
                    minCapacidade = grafo[0][i] - fluxo[0][i];
                }
            }
        }

        for (int i = 1; i <= vertice; i++) {
            if (caminho[i] && grafo[0][i] > fluxo[0][i]) {
                fluxo[0][i] += minCapacidade;
                fluxo[i][0] -= minCapacidade;
            }
        }

        maxFluxo += minCapacidade;

        for (int i = 1; i <= vertice; i++) {
            if (caminho[i]) {
                for (int j = 1; j <= vertice; j++) {
                    if (grafo[i][j] > 0 && fluxo[i][j] < grafo[i][j]) {
                        int capacidadeRestante = grafo[i][j] - fluxo[i][j];
                        if (minCapacidade < capacidadeRestante) {
                            capacidadeRestante = minCapacidade;
                        }
                        fluxo[i][j] += capacidadeRestante;
                        fluxo[j][i] -= capacidadeRestante;
                    }
                }
            }
        }

        for (int i = 0; i <= vertice; i++) {
            caminho[i] = 0;
        }
    }

    for (int i = 0; i <= vertice; i++) {
        free(fluxo[i]);
    }
    free(fluxo);
    free(caminho);

    return maxFluxo;
}
