//faça um progama que leia e imprima uma string (conceitos de arrays)

#include <stdio.h>
    int main (void){
        char string[100];
        printf("Insira uma string:");
        fgets(string, 100, stdin);//fgets é uma função que lê uma string do teclado e armazena na variável string, com um limite de 100 caracteres
        printf("A string inserida foi: %s", string);
        return 0;
    }