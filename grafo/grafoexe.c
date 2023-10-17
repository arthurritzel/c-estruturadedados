#include <stdio.h>

int main(){
    int mat[7][7];
    int menor = 0, flag = 0, soma = 0, flag2 = 0, achou = 0;
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 7; j++){
            mat[i][j] = 0;
        }  
    }
    mat[0][1] = 50;
    mat[0][2] = 30;
    mat[1][2] = 25;
    mat[1][3] = 70;
    mat[2][4] = 40;
    mat[3][4] = 60;
    mat[3][5] = 45;
    mat[4][5] = 55;
    mat[4][6] = 70;
    mat[5][6] = 35;
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 7; j++){
            printf("%i ", mat[i][j]);
        }  
        printf("\n");
    }

    for (int i = 0; i != 6;){
            menor = 10000;
            for (int j = 0; j < 7; j++){
                if (mat[i][j] != 0){
                    if (j == 6){
                        menor = mat[i][j];
                        achou = 1;
                    }
                    
                    if (flag == 0){
                        menor = mat[i][j];
                        flag = 1;
                    }

                    if (menor >= mat[i][j]){
                        menor = mat[i][j];
                        printf("numero: %i\n", mat[i][j]);
                        flag2 = j;
                        if (flag2 == 6){
                            achou = 1;
                            break;
                        }
                    }
                    
                }

            } 
            soma += menor;
            
            if (achou == 1){
                break;  
             }
            i = flag2;
            printf("soma: %i\n", soma);
    }
    printf("%i",soma);

}