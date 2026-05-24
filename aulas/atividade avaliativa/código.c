//código do comsumo energetico
#include <stdio.h>
#include <stdlib.h>

int main(void){
    float consumo[3][5]={0};

    int setormaior=0,diamaior=0;
    int i, j;
    int opcao=0;
    char respostas[10]={0};

    while(opcao!=4){
        printf("\n===========RELATORIO DE CONSUMO ENERGETICO===========\n");
        printf("\n\nInsira uma opcao\n");
        printf("1.Inserir consumo\n");
        printf("2.Matriz de consumo\n");
        printf("3.Setor mais energetico\n");
        printf("4.Sair\n\n");

        opcao=0;
        while(opcao==0){
            fgets(respostas,sizeof(respostas),stdin);
            opcao=atoi(respostas);
            if(opcao<0||opcao==0||opcao>4){
                printf("Escolha uma opcao valida\n");
                opcao=0;
            }
        }
        printf("\n");

        switch(opcao){
            case 1:
                
                //aqui é onde o usuário irá inserir os dados de consumo energético
                for(i=0;i<3;i++){
                    printf("Digite o consumo do setor %d:\n", i+1);
                    for(j=0;j<5;j++){
                        printf("Digite o consumo do dia %d: ", j+1);
                        fgets(respostas,sizeof(respostas),stdin);
                        consumo[i][j]=atof(respostas);
                        // printf("%f",consumo[i][j]);
                    }
                }
                
                break;
            case 2:
            //matriz de consumo
                for(i=0;i<3;i++){
                    for(j=0;j<5;j++){
                        printf("%1.f\t", consumo[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");

                break;
            case 3:
            //setor mais energetico
            //somasetor/5 =mediasetor
                float media[3],somasetor=0;

                for(i=0;i<3;i++){
                    somasetor=0;

                    for(j=0;j<5;j++){
                        somasetor+=consumo[i][j];
                    }
                    media[i]=somasetor/5 //calculo da média
                    
                  
                }


        }

    }
    return 0;
}