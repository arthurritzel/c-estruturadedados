#include <stdio.h>
#include <stdlib.h>

int veryValor(int **mat, int i, int j){
    int n;
    printf("Digite o valor de n: ");
    scanf("%i", &n);

    for (int i1 = 0; i1 < i; i1++){
        for (int j1 = 0; j1 < j; j1++){
            printf("%i\n", mat[i1][j1]);
            if (mat[i1][j1] == n){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int **mat, j, i;
    printf("Digite o numero de linhas: ");
    scanf("%i", &i);
    printf("Digite o numero de colunas: ");
    scanf("%i", &j);

    mat = (int **)malloc(i * sizeof(int *));
    for (int i1 = 0; i1 < i; i1++){
        mat[i1] = (int *)malloc(j * sizeof(int));
    }

    for (int i1 = 0; i1 < i; i1++){
        for (int j1 = 0; j1 < j; j1++){
            printf("Digite o valor l %i d %i: ", i1, j1);
            scanf("%i", &mat[i1][j1]);
        }
    }
    
    
    
    if (veryValor(mat, i, j) == 1) {
        printf("Valor encontrado na matriz.\n");
    } else {
        printf("Valor não encontrado na matriz.\n");
    }

    
    free(mat);
    
    return 0;
}
