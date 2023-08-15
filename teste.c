#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, M;

    // Lê os números N e M
    printf("Digite o numero de linhas (N): ");
    scanf("%d", &N);
    printf("Digite o numero de colunas (M): ");
    scanf("%d", &M);

    // Aloca dinamicamente a matriz de inteiros N x M
    int **matriz = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matriz[i] = (int *)malloc(M * sizeof(int));
    }

    // Lê os elementos da matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("Digite o elemento da posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Inicializa os ponteiros para inteiros com NULL
    int *maior1 = NULL, *maior2 = NULL;

    // Encontra os dois maiores números na matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maior1 == NULL || matriz[i][j] > *maior1) {
                maior2 = maior1;
                maior1 = &matriz[i][j];
            } else if ((maior2 == NULL || matriz[i][j] > *maior2) && &matriz[i][j] != maior1) {
                maior2 = &matriz[i][j];
            }
        }
    }

    // Mostra as informações dos dois maiores números
    printf("Os dois maiores numeros na matriz sao:\n");
    printf("Maior 1: %d\n", *maior1);
    printf("Maior 2: %d\n", *maior2);

    // Libera a memória alocada para a matriz
    for (int i = 0; i < N; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}