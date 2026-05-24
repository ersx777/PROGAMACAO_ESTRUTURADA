//faça um vetor para lista de compras,onde o usuário deve inserir 5 itens e depois imprimi-los
#include <stdio.h>
#include <string.h>

int main(void){
    char lista[5][50];
    int i; //vetor de 5 strings, cada string pode ter até 50 caracteres
    for(i=0;i<5;i++){
        printf("Insira o item da lista de compras: %d \n", i+1);
        fgets(lista[i], sizeof(lista[i]), stdin); //lê uma string do teclado e armazena na posição i do vetor lista
        //revisar f
    }
    for (int i=0;i<5;i++){
        printf("Item %d: %s\n", i+1, lista[i]); //imprime o item da lista de compras, usando %s para imprimir a string e i+1 para mostrar o número do item
    }

        return 0;
    }
