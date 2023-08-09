#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *str, vog[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int tam, flag;

    printf("Digite o tamanho da string: ");
    scanf("%i", &tam);

    str = (char *)malloc(tam * sizeof(char));
    if(str == NULL){
        printf("Erro na alocacao");
        return 0;
    }

    printf("Digite a string: ");
    fflush(stdin);
    gets(str);

    for (int i = 0; i < strlen(str); i++){
        flag = 0;
        for (int j = 0; j < strlen(vog); j++){
            if (str[i] == vog[j]){
                flag = 1;
                break;
            }
        }
        
        if (flag != 1){
            printf("%c", str[i]);
        }
    }
    free(str);
}