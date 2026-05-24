#include <stdio.h>
 
int main(void){
    int idade;
    printf("Insira sua idade: ");
    scanf("%d", &idade);

        if(idade>120){
        printf("Idade invalida");
    } else{
    if (idade<12){
        printf("voce e uma crianca");
    } else if (idade<18){
        printf("Voce e um adolescente");
    } else if(idade<60){
        printf("Voce e um adulto");
    }else {
        printf("Voce e um idoso");
    }

} return 0;

    }