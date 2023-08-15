#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, n, *vet;
    printf("Digite a quantidade de posicoes do vetor: ");
    scanf("%i", &n);

    vet = (int *)malloc(n * sizeof(int));
    if(vet == NULL){
        printf("Erro na alocacao");
        return 0;
    }
    
    for (int i = 0; i < n; i++){
        printf("Digite o %i valor: ", i);
        scanf("%i", &vet[i]);
    }

    printf("Digite um numero para verificar seus multiplos: ");
    scanf("%i", &x);

    for (int i = 0; i < n; i++){
        if(vet[i] % x == 0){
            printf("%i é multiplo\n", vet[i]);
        }
    }

    
    free(vet);
}