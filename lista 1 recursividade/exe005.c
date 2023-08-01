#include <stdio.h>
int comb(int n, int k){
    if (k == 1){
        return n;
    }else if(k == n){
        return 1;
    }else if((1 < k) && (k < n)){
        return comb(n - 1, k - 1) + comb(n - 1, k);
    }else{
         return 0;
    }
    
}
int main(){
    int k, n;
    printf("Digite o valor de n: ");
    scanf("%i", &n);
    printf("Digite o valor de k: ");
    scanf("%i", &k);
    printf("%i", comb(n, k));
}