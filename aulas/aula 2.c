#include <stdio.h>

int main(void){

    printf("---------VERIFICADOR DE IDADE---------\n");

    int idade;

    printf("Insira sua idade: ");
    scanf("%d", &idade);

    while(idade<0 || idade>120){
        if(idade<0){
            printf("Idade negativa,insira uma idade valida\n");
        }else if(idade>120){
            printf("Idade muito alta,e necessario um prova de vida\n");
        } 
        
        printf("Idade invalida\n");
        printf("Insira sua idade: ");
        scanf("%d", &idade);
    }
    
    if (idade<12){
        printf("voce e uma crianca");
    } else if (idade<18){
        printf("Voce e um adolescente");
    } else if(idade<60){
        printf("Voce e um adulto");
    } else {
        printf("Voce e um idoso");
    }
    return 0;
}
