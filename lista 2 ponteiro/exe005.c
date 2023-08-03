#include <stdio.h>

void primo(int m, int *pt1, int *pt2){
    int flag = 0;
    for (int i = 1; i < m; i++){
        flag = 0;
        for (int j = 1; j <= i; j++){
            if (i % j == 0){
                flag++;
            }
        }
        if (flag == 2){
            *pt1 = i;
        }
    }

    for (int i = m; i >= m; i++){
        flag = 0;
        for (int j = 1; j <= i; j++){
            if (i % j == 0){
                flag++;
            }
        }
        if (flag == 2){
            *pt2 = i;
            break;
        }
    }
    
}

int main(){
    int m, p1, p2;

    printf("Digite o valor de m: ");
    scanf("%i", &m);
    primo(m, &p1, &p2);

    printf("p1: %i\np2: %i", p1, p2);
}