//programa que lê dois números e os imprime em ordem inversa
#include<stdio.h>
int main(void){
    int num1,num2;
    printf("Digite o primeiro numero: ");
    scanf("%d",&num1);//leitura do primeiro numero, o & é necessário para passar o endereço da variável num1 para a função scanf, permitindo que ela armazene o valor digitado pelo usuário na variável num1.
    printf("Digite o segundo numero: ");
    scanf("%d",&num2);

    printf("Os numeros na ordem inversa sao: \n%d \n%d",num2,num1);
    return 0;
}