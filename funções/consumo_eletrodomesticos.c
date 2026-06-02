//Cria um programa que:
/*
1)Solicite aos usuarios os eletro que possii e informe o comsumo em kw/h da entiqueta, ex: Ventilador 0.12 kw/h.
Somente 3.
2)Mostrar o consumo total do Mes,considerando todos os eletros informados funcionando: Todos os dias,todos os dias,sem desligar e durante o mes
3)Mostrar o valor da fatura, considerando 1 KW --> R$1.25.
*/
#include<stdio.h>

int main(void){
    int opcao=0;
    int i,j;
    float consumo[3]={0};
    char tipodeeletro[3][20];
    float consumototal=0;
    float valordafatura=0;
    int status_leitura;
    while(opcao!=4){
        printf("\nEscolha uma opcao:\n");
        printf("1.Inserir consumo dos eletros\n");
        printf("2.Obter consumo total(mes)\n");
        printf("3.Valor total da fatura\n");
        printf("4.Sair\n");
        scanf(" %d",&opcao);
        if(opcao<0||opcao==0||opcao>4){
                printf("Escolha uma opcao valida\n");
                opcao=0;
            }
      switch(opcao){
        case 1:
        for(i=0; i<3; i++){
            // Pede o NOME do eletrodoméstico normalmente
            printf("Digite o tipo de eletrodomestico %d: \n", i+1);
            scanf(" %s", tipodeeletro[i]);

            do {
                printf("Digite o consumo do eletrodomestico em kWh %d: \n", i+1);
                status_leitura = scanf("%f", &consumo[i]);
                
                // Limpa o teclado para evitar o loop infinito se o usuario digitar letra
                while(getchar() != '\n'); 

                if(status_leitura != 1 || consumo[i] < 0){
                    printf("Valor invalido! Digite um numero que seja positivo.\n");
                }
            } while(status_leitura != 1 || consumo[i] < 0);
        }
        break; 

    case 2:
        // Aqui vai entrar a sua lógica de soma!
        break;
        }            
    }   
}