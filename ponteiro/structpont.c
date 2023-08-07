#include <stdio.h>

struct dados{
        int n1;
        float n2;
    };


void func(struct dados *ptr){
    ptr[0].n1 = 1;
    ptr[1].n1 = 2;

    printf("%i\n", ptr[0].n1);
    printf("%i\n\n", ptr[1].n1);

}


int main(){
    struct dados cadastro[2];
    func(cadastro);
    
    printf("%i\n", cadastro[0].n1);
    printf("%i", cadastro[1].n1);
   

}