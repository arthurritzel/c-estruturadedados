#include <stdio.h>
#include <stdlib.h>

struct Node{
    float info;
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
        scanf("%f", &novo->info);
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
            printf("%f\n", temp->info);
            temp = temp->prox;
        }
    }
}

void removeinicio(lista* inicio){
    if ((*inicio) != NULL){
        node *temp;
        temp = (*inicio);
        *inicio = temp -> prox;
        free(temp);
    }else{
        printf("Lista vazia");
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
    int esc, qtn_nos = 1, remove_nos;

    
    do{
        printf("\nDefina sua acao\n1- adicionar elemento\n2-Remover quantidade de elementos\n3-sair\n->");
        scanf("%i", &esc);

        switch (esc)
        {
        case 1:
            inserenoinicio(inicio);
            exibelista(inicio);
            qtn_nos++;
            break;
        case 2:
            printf("Digite a quanitdade de nos que quer remover: ");
            scanf("%i", &remove_nos);

            if(remove_nos < qtn_nos){
                for (int i = 0; i < remove_nos; i++){
                    removeinicio(inicio);
                    qtn_nos--;
                }
            }else{
                for (int j = 0; j <= qtn_nos; j++){
                    removeinicio(inicio);
                    qtn_nos--;
                }
            }
            exibelista(inicio);
            break;
        default:
            break;
        }
    }while(esc != 3);
    liberar(inicio);
}