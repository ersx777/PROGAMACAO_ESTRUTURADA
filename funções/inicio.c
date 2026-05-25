#include <stdio.h>

int soma(int a, int b){
    int result;
    result = a+b;
    return result;
}
int main(void){
    int a,b;
    printf("Insira o  valor de A: ");
    scanf("%d",&a);
    printf("Insira o valor de B: ");
    scanf("%d",&b);
    printf("A soma e: %d",soma(a,b));

    
}