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

void removeElemento(lista* inicio){
    int num, flag = 0, cont = 1;
    node *ant, *temp;
    if ((*inicio) == NULL){
        printf("\nLista vazia\n");
    }else {
        printf("Digite a posicao: ");
        scanf("%i", &num);
        if(num == 1){
            temp = (*inicio);
            *inicio = (*inicio)->prox;
            free(temp);
            flag = 1;
        }else{
            temp = (*inicio);
            ant = temp;
            while (temp != NULL){
                if (num == cont){
                    ant->prox = temp->prox;
                    free(temp);
                    flag = 1;
                    break;
                }
                ant = temp;
                temp = temp->prox;
                cont++;
            }
        }
        if (flag == 0){
            printf("\nNó nao encontrado na lista\n");
        }
        
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
        printf("\nDefina sua acao\n1- adicionar elemento\n2-Remover elemento\n3-exibir lista\n4-sair\n->");
        scanf("%i", &esc);
        system("clear");
        switch (esc)
        {
        case 1:
            inserenoinicio(inicio);
            break;
        case 2:
            removeElemento(inicio);
            break;
        case 3:
            exibelista(inicio);
            break;
        default:
            break;
        }
    }while(esc != 4);
    liberar(inicio);
}