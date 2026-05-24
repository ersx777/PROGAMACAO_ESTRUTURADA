#include <stdio.h>
// Programa para contar quantos numeros pares existem entre 1 e 100
int main(void){

    int i, contador=0;
    for(i=1;i<=100;i++){
        if(i%2==0){   // == é o operador de comparação, % é o operador de resto da divisão, se fosse = seria uma atribuição, ou seja, contador receberia o valor de 0, o que não é o objetivo do programa
            contador++;
        }
    }
    printf("Existem %d numeros pares entre 1 e 100.\n", contador);
}