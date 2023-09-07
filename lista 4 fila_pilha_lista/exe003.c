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

int inserenofinal(lista *inicio){
    node *novo = (node*)malloc(sizeof(node));
    if(novo == NULL){
        printf("Erro na alocacao");
        return 0;
    }else{
        if((*inicio) == NULL){
            *inicio = novo;
        }else{
            node *temp;
            temp = (*inicio);
            while (temp->prox != NULL){
                temp = temp->prox;
            }
            temp->prox = novo;
            novo->prox = NULL;
        }
        printf("Digite o valor: ");
        scanf("%i", &novo->num);
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

void removeFinal(lista* inicio){
    node *antTemp, *temp;
    temp = (*inicio);
    if (((*inicio) != NULL) && (temp -> prox) == NULL){
        *inicio = NULL;
        free(temp);
    }else if((*inicio) != NULL){
        while (temp->prox != NULL){
            antTemp = temp;
            temp = temp->prox;
        }
        antTemp->prox = NULL;
        free(temp);
        printf("Elemento removido\n");
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
    int esc;
    do{
        printf("\nDefina sua acao\n1- adicionar elemento\n2-Remover elemento\n3-sair\n->");
        scanf("%i", &esc);

        switch (esc)
        {
        case 1:
            inserenofinal(inicio);
            exibelista(inicio);
            break;
        case 2:
            removeFinal(inicio);
            exibelista(inicio);
            break;
        default:
            break;
        }
    }while(esc != 3);
    liberar(inicio);
}