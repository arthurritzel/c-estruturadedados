#include <stdio.h>

void converterHora(int tot_seg, int *hora, int *min, int *seg){
    *seg = tot_seg % 60;
    tot_seg = tot_seg / 60;
    *min = tot_seg % 60;
    *hora = tot_seg / 60;
}

int main(){
    int tot_seg, hora, min, seg;
    printf("Digite os segundos: ");
    scanf("%i", &tot_seg);
    converterHora(tot_seg, &hora, &min, &seg);
    printf("%i:%i:%i", hora, min, seg);
}