// Dado um código que classifica a idade de uma pessoa,
// modifique-o para que ele continue solicitando a idade até que seja inserida uma idade válida (entre 0 e 120). 
// Além disso, adicione um menu para o usuário escolher entre classificar a idade ou sair do programa.
#include <stdio.h>
int main(void){
    int opcao=0;

    while(opcao!=5){
        printf("\n====MENU====\n");
        printf("1.Dizer Ola \n");
        printf("2.Calcular \n");
        printf("3.sair \n");
        printf("Escolha uma opcao: ");
        scanf("%d",&opcao);

        if(opcao==1){
            printf("Ola, turma!\n");
        }
        else if(opcao==2){
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
            
        }
        else if(opcao==3){
            printf("\nDeseja relamente sair? (1-Sim, 2-Nao): ");
            int confirmacao;
            scanf("%d", &confirmacao);
            if(confirmacao==1){
            printf("Encerrando...\n");
        }
        else{
            printf("Opcao invalida, tente novamente.\n");
        }
    }
    
    return 0;
}       
}