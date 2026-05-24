//código do comsumo energetico
#include <stdio.h>
int main(void){
    float consumo[3][5]={0};
    float mediasetor=0,totalgeral=0;

    int setormaior=0,diamaior=0;
    int i, j;
    int opcao=0;

    while(opcao!=4){
        printf("===========RELATORIO DE CONSUMO ENERGETICO===========");
        printf("\n\nInsira uma opcao\n");
        printf("1.Inserir consumo\n");
        printf("2.Matriz de consumo\n");
        printf("3.Setor mais energetico\n");
        printf("4.Sair\n\n");

        scanf("%d",&opcao);
        
    

        //aqui é onde o usuário irá inserir os dados de consumo energético
        for(i=0;i<3;i++){
            printf("Digite o consumo do setor %d:\n", i+1);
            for(j=0;j<5;j++){
                printf("Digite o consumo do dia %d: ", j+1);
                scanf("%f", &consumo[i][j]);
            }
        }
        //painel de resultados
        for(i=0;i<3;i++){
            for(j=0;j<5;j++){
                printf("%1.f\t", consumo[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}