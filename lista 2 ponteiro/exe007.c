#include <stdio.h>
#include <math.h>

void calc_esfera(float r, float *area, float *volume){
    *area = 4 * 3.14 * pow(r, 2);
    *volume = 4.0/3.0 * 3.14 * pow(r, 3);  
}

int main(){
    float r, area = 0, volume = 0;
    printf("Digite o raio da esfera: ");
    scanf("%f", &r);

    calc_esfera(r, &area, &volume);

    printf("Area: %.2f\nVolume: %.2f", area, volume);

}