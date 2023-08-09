#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, pares = 0, impares = 0, *vet;
    printf("Digite a quantidade de posicoes do vetor: ");
    scanf("%i", &x);

    vet = (int *)malloc(x * sizeof(int));
    if(vet == NULL){
        printf("Erro na alocacao");
        return 0;
    }
    
    for (int i = 0; i < x; i++){
        printf("Digite o %i valor: ", i);
        scanf("%i", &vet[i]);
        if (vet[i] % 2 == 0){
            pares += 1;
        }else{
            impares += 1;
        }
    }

    printf("Voce digitou %i numeros pares e %i impares", pares, impares);
    free(vet);
}