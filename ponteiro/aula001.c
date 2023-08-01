#include <stdio.h>

int main(){
    int x = 27;
    int *ptr;
    ptr = &x;

    printf("%i\n", x);
    printf("%x\n", &x);
    printf("%x\n", ptr);
    printf("%i", *ptr);
}