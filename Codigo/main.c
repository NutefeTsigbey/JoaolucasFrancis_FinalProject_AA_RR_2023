#include <stdio.h>
#include <stdlib.h>
#include "ford_fulkerson.h"

int main() {
    int numVertices, numArestas, numTarefas, numFuncionarios;
    printf("Entre com a quantidade de vértices, de arestas, de tarefas e de funcionários: ");
    scanf("%d %d %d %d", &numVertices, &numArestas, &numTarefas, &numFuncionarios);

    int **grafo = (int**) malloc((numVertices + 1) * sizeof(int*));
    for (int i = 0; i <= numVertices; i++) {
        grafo[i] = (int*) malloc((numVertices + 1) * sizeof(int));
        for (int j = 0; j <= numVertices; j++) {
            grafo[i][j] = 0;
        }
    }

    for (int i = 0; i < numArestas; i++) {
        int origem, destino, fluxoMaximo;
        printf("Entre com a origem, destino e fluxo máximo da aresta %d: ", i + 1);
        scanf("%d %d %d", &origem, &destino, &fluxoMaximo);
        grafo[origem][destino] = fluxoMaximo;
    }

    int *tarefas = (int*) malloc(numTarefas * sizeof(int));
    for (int i = 0; i < numTarefas; i++) {
        printf("Identifique um vértice que será uma tarefa: ");
        scanf("%d", &tarefas[i]);
    }

    int *funcionarios = (int*) malloc(numFuncionarios * sizeof(int));
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Identifique um vértice que será um funcionário: ");
        scanf("%d", &funcionarios[i]);
    }

    printf("\n---Resultados---\n\n");

    int maxFluxo = fordFulkerson(numVertices, grafo);

    printf("Fluxo Máximo: %d\n\n", maxFluxo);

    // Liberar memória
    for (int i = 0; i <= numVertices; i++) {
        free(grafo[i]);
    }
    free(grafo);
    free(tarefas);
    free(funcionarios);

    return 0;
}
