#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    struct Node *prox;
};
typedef struct Node node;
typedef node *lista;

lista* criarlistta(){
    lista *inicio = (lista*) malloc(sizeof(lista));
    if (inicio != NULL){
        *inicio = NULL;
    }else{
        printf("Erro na alocaçãooo");
    }
    return inicio;
}

int inserenoinicio(lista *inicio){
    node *novo = (node*) malloc(sizeof(node));
    if(novo == NULL){
        printf("Erro na alocação");
        return 0;
    }else{
        printf("Digite o valor: ");
        scanf("%i", &novo->num);
        novo->prox = (*inicio);
        *inicio = novo;

    }
}

void exibelista(lista*inicio){
    
    if(*inicio == NULL){
        printf("Lista vazia");
    }else{
        node *temp;
        temp = (*inicio);

        while (temp != NULL){
            printf("%i\n", temp->num);
            temp = temp->prox;
        }
    }
}

int contaPrimos(lista*inicio){
    int flag = 0, primos = 0;
    if(*inicio == NULL){
        printf("Lista vazia");
    }else{
        node *temp;
        temp = (*inicio);

        while (temp != NULL){
            flag = 0;
            for (int i = 1; i <= temp->num; i++){
                if (temp->num % i == 0){
                    flag++;
                }
            }
            if (flag == 2){
                primos++;
            }
            temp = temp->prox;
        }
        return primos;
    }
}




void liberar(lista* inicio){
    if ((*inicio) == NULL){
        printf("Lista vazia");
    }else{
        node *temp;
        while ((*inicio) == NULL){
            temp = *inicio;
            *inicio = (*inicio)->prox;
            free(temp);
        }
    }
    
}

int main(){
    lista* inicio = criarlistta();
    int esc;
    do{
        printf("\nDefina sua acao\n1- adicionar elemento\n2-Contar primos\n3-sair\n->");
        scanf("%i", &esc);

        switch (esc)
        {
        case 1:
            inserenoinicio(inicio);
            exibelista(inicio);
            break;
        case 2:
            printf("exixstem %i numeros primos", contaPrimos(inicio));
            
            break;
        default:
            break;
        }
    }while(esc != 3);
    liberar(inicio);
}

