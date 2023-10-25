#include <stdio.h>
#include <stdlib.h>
struct No{
    int num;
    struct No *esq;
    struct No *dir;
};
typedef struct No no;
typedef no *ArvBin;

ArvBin* criaArvore(){
    ArvBin *raiz = (ArvBin*) malloc (sizeof(ArvBin));
    if (raiz != NULL){
        *raiz = NULL;
    }else{
        printf("Erro na alocacao");
        return 0;
    };
    return raiz;
}

int insere_raiz(ArvBin *raiz){
    no *novo = (no*) malloc(sizeof(no));
    if (novo == NULL){
        printf("erro na alocaco");
        return 0;
    }else{
        printf("Digite o novo elemento: ");
        scanf("%i", &novo->num);
        novo->esq = NULL;
        novo->dir = NULL;
        if(*raiz == NULL){
            *raiz = novo;
            return 1;
        }else{
            no *atual = *raiz;
            no *ant = NULL;
            while (atual != NULL){
            ant = atual;
                if (atual->num == novo->num){
                    printf("Elemento ja existe");
                    free(novo);
                    return 0;
                }
                if(novo->num > atual->num){
                    atual = atual->dir;
                }else{
                    atual = atual->esq;
                }
            }
            if(novo->num > ant->num){
                ant->dir = novo;
            }else{
                ant->esq = novo;
            }
            
        }
        
    }
}

void libera_no(no *no_liberar){
    if(no_liberar == NULL){
        return;
    }else{
        libera_no(no_liberar->esq);
        libera_no(no_liberar->dir);
        free(no_liberar);
    }
}

int libera_arvore(ArvBin * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        libera_no(*raiz);
    }
    free(raiz);
}

void imprime_no_PreOrd(no *no_print){
    if(no_print == NULL){
        return;
    }else{
        printf("%i\n", no_print->num);
        imprime_no_PreOrd(no_print->esq);
        imprime_no_PreOrd(no_print->dir);
    }
}

int imprime_PreOrd(ArvBin * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        imprime_no_PreOrd(*raiz);
    }
   
}

void imprime_no_InOrd(no *no_print){
    if(no_print == NULL){
        return;
    }else{
        imprime_no_InOrd(no_print->esq);
        printf("%i\n", no_print->num);
        imprime_no_InOrd(no_print->dir);
    }
}

int imprime_InOrd(ArvBin * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        imprime_no_InOrd(*raiz);
    }
}

void imprime_no_PosOrd(no *no_print){
    if(no_print == NULL){
        return;
    }else{
        imprime_no_PosOrd(no_print->esq);
        imprime_no_PosOrd(no_print->dir);
        printf("%i\n", no_print->num);
    }
}

int imprime_PosOrd(ArvBin * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        imprime_no_PosOrd(*raiz);
    }
}

#include <stdio.h>
#include <stdlib.h>

remover_folha(no *no_print, no *ant){
    if(ant->num > no_print->num){
        ant->esq = NULL;
        free(no_print);
    }else{
        ant->dir = NULL;
        free(no_print);
    }
}

remover_umFilho(no *no_print, no *ant){
    if(ant->num > no_print->num){
        if(no_print->dir != NULL){
            ant->esq = no_print->dir;
            free(no_print);
        }else{
            ant->esq = no_print->esq;
            free(no_print);
        }
    }else{
        if(no_print->dir != NULL){
            ant->dir = no_print->dir;
            free(no_print);
        }else{
            ant->dir = no_print->esq;
            free(no_print);
        }   
    }
}

void remover_interno(no *no_print, no *ant){
    no *atual2 = (no*) malloc(sizeof(no));
    no *anterior2 = (no*) malloc(sizeof(no));

    atual2 = no_print->esq;
    anterior2 = no_print->esq;
    while(atual2->dir != NULL){
        anterior2 = atual2;
        atual2 = atual2->dir;
    }
    anterior2->dir = NULL;
    atual2->dir = no_print->dir;
    atual2->esq = no_print->esq;
    if(ant->num > no_print->num){
         ant->esq = atual2;
    }else{
        ant->dir = atual2;
    }
    free(no_print);
    return;
}

void acha_no(no *no_print, int remove, no *ant){
    if(no_print == NULL){
        return;
    }else{
        acha_no(no_print->esq, remove, no_print);
        acha_no(no_print->dir, remove, no_print);
        if(no_print->num == remove){
            if(no_print->esq == NULL && no_print->dir == NULL){
                remover_folha(no_print, ant);
                return;
            }else if((no_print->esq == NULL && no_print->dir != NULL) || (no_print->esq != NULL && no_print->dir == NULL)){
                remover_umFilho(no_print, ant);
                return;
            }else{
                remover_interno(no_print, ant);
                return;
            }
        }
    }
}

int remove_no(ArvBin *raiz){
    if(raiz == NULL){
        return 0;
    }else{
        int remove;
        printf("Digite o no a ser removido ");
        scanf("%i", &remove);
        acha_no(*raiz, remove, *raiz);
    }

}
// Definições das estruturas e funções aqui...

int main() {
    ArvBin *raiz = criaArvore();
    int opc;

    do {
        printf("\nMenu de Operações:\n");
        printf("1 - Inserir elemento na árvore\n");
        printf("2 - Imprimir árvore em Pré-Ordem\n");
        printf("3 - Imprimir árvore em Ordem\n");
        printf("4 - Imprimir árvore em Pós-Ordem\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        fflush(stdin);
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                insere_raiz(raiz);
                break;
            case 2:
                printf("Árvore em Pré-Ordem:\n");
                imprime_PreOrd(raiz);
                break;
            case 3:
                printf("Árvore em Ordem:\n");
                imprime_InOrd(raiz);
                break;
            case 4:
                printf("Árvore em Pós-Ordem:\n");
                imprime_PosOrd(raiz);
                break;
            case 5:
                printf("Remover...\n");
                remove_no(raiz);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opc != 6);

    // Libera a memória antes de encerrar o programa
    libera_arvore(raiz);

    return 0;
}
