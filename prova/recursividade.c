#include <stdio.h>


int fat(int num){
    if (num == 1){
        return 1;
    }else{
        return (num * fat(num-1));
    }
}

int main(){
    int num;
    printf("Dgitie um numero para calcular seu fatorial: ");
    scanf("%i", &num);

    printf("o fatorial é %i", fat(num));
}