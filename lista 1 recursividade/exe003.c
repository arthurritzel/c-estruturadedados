#include <stdio.h>
int soma(float vet[], int tam){
    if(tam == -1){
        return 0;
    }else{
        return(vet[tam] + soma(vet, tam - 1));
    }
}
int main(){
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%i", &tam);
    float vet[tam];
    for (int i = 0; i < tam; i++){
        printf("Digite o valor da posicao %i: ", i);
        scanf("%f", &vet[i]);
    }
    printf("A soma dos valores e %i", soma(vet, tam - 1));
}