#include <stdio.h>
#include <stdlib.h>

int main(){
    int lot[6], esc[6], *vet, cont = 1;
    printf("Digite os numeros sorteados\n");
    for (int i = 0; i < 6; i++){
        printf("-> ");
        scanf("%i", &lot[i]);
    }
    
    printf("Digite os numeros escolhidos por vc\n");
    for (int i = 0; i < 6; i++){
        printf("-> ");
        scanf("%i", &esc[i]);
    }

    for (int i = 0; i < 6; i++){
      for (int j = 0; j < 6; j++){
        if (lot[i] == esc[j]){
            if(cont == 1){
                vet = (int *)malloc(1 * sizeof(int));
                if(vet == NULL){
                    printf("Erro na alocacao");
                    return 0;
                }   
            }else{
                vet = (int *)realloc(vet, cont * sizeof(int));
            }
            vet[cont-1] = esc[j];
            cont++;
            break;
        }
      }
        
    }
    if (vet == NULL){
        printf("Zero acertos");
    }else{
        printf("\nAcerto(s)");
        for (int i = 0; i < (cont-1); i++){
            printf("\n->%i\n", vet[i]);
        }
    }
    
    printf("%i", sizeof(vet));

    free(vet);
}