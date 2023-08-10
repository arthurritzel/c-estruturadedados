#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vet, aux, i;

    printf("Digite valores a serem armazendos em um vetor, digite um numero negativo para sair\n");
    for (i = 0; i != -1; i++){
        printf("->");
        scanf("%i", &aux);
        if (aux < 0){
            break;
        }else{
            if (i == 0){
                vet = (int *)malloc(sizeof(float));
                if(vet == NULL){
                    printf("Erro na criacao do arquivp");
                    return 0;
                }
                vet[0] = aux;
            }else{
                vet = (int *)realloc(vet, i * sizeof(float));
                vet[i] = aux;
            }
        }
    }

    if(vet == NULL){
        printf("Nenhum valor armazenado!");
    }else{
        for(int j = 0; j < i; j++){
            printf("%i\n", vet[j]);
        }
    }
    printf("%i", sizeof(vet));
    free(vet);
}