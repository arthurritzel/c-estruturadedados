#include <stdio.h>
#include <stdlib.h>

int main(){
    int **mat, n, m, maior, maior2, flag = 0, mi, mj, m2i, m2j;
    printf("Digite o numero de linhas: ");
    scanf("%i", &n);
    printf("Digite o numero de colunas: ");
    scanf("%i", &m);

    mat = (int **)malloc(n * sizeof(int *));
    for (int i1 = 0; i1 < n; i1++){
        mat[i1] = (int *)malloc(m * sizeof(int));
    }

    for (int i1 = 0; i1 < n; i1++){
        for (int j1 = 0; j1 < m; j1++){
            printf("Digite o valor l %i d %i: ", i1, j1);
            scanf("%i", &mat[i1][j1]);
        }
    }

    for (int i1 = 0; i1 < n; i1++){
        if (i1 == 0){
            maior = mat[0][0];
            mi = 0;
            mj = 0;
        }
        for (int j1 = 0; j1 < m; j1++){
            if (mat[i1][j1] > maior){
                maior = mat[i1][j1];
                mi = i1;
                mj = j1;
            }
        }
    }

    for (int i1 = 0; i1 < n; i1++){
        if (i1 == 0 && mat[0][0] != maior){
            maior2 = mat[0][0];
            m2i = 0;
            m2j = 0;
            flag = 1;
        }
        if (i1 == 0 && mat[0][1] != maior && flag != 1){
            maior2 = mat[0][1];
            m2i = 0;
            m2j = 1;
        }

        for (int j1 = 0; j1 < m; j1++){
            if (mat[i1][j1] > maior2 && mat[i1][j1] != maior){
                maior2 = mat[i1][j1];
                m2i = i1;
                m2j = j1;
            }
        }
    }

    printf("Maior: %i, [%i][%i]\nSegundo maior: %i, [%i][%i]", maior, mi, mj, maior2, m2i, m2j);
    free(mat);
}