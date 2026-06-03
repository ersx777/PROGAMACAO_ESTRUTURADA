#include <stdio.h>
/*

Criar um programa em C que realize as seguintes tarefas:

1. **Entrada de Dados:** Solicitar ao usuário o nome dos eletrodomésticos que possui e o consumo em kWh da etiqueta (ex: Ventilador 0.12 kWh). Limite de **somente 3** eletrodomésticos.
2. **Processamento (Consumo Mensal):** Mostrar o consumo total do mês, considerando que todos os eletrodomésticos informados ficam funcionando todos os dias, sem desligar, durante o mês inteiro (24h por dia, 30 dias).
3. **Saída (Fatura Financeira):** Mostrar o valor total da fatura, considerando que o custo de 1 kWh é de **R$ 1,25**.

*/

int main(void){
    int i;
    float consumo[3]={0};
    float consumototal=0;//consumo mensal
    char tipodeeletro[3][20];
    int opcao = 0;

    while (opcao != 4){
        printf("===============CONSUMO ENERGETICO===============\n");
        printf("Escolha um opcao: \n");
        printf("1.Inserir consumo\n");
        printf("2.Consumo mensal\n");
        printf("3. Emitir fatura\n");
        printf("4.Sair \n");
        scanf("%d", &opcao);
        if (opcao == 0 || opcao < 0 || opcao > 4){
            printf("DIgite um opcao valida!\n");
        }
        switch(opcao){
            case 1:
                for(i=0;i<3;i++){
                    printf("Insira o tipo de eletrodomestico: \n");
                    scanf("%s",tipodeeletro[i]);
                    printf("Insira o consumo do eletrodomestico: \n");
                    scanf("%f",&consumo[i]);
                }
            break;
            case 2:
                consumototal=0;
                for(i=0;i<3;i++){
                    consumototal=consumo[i]+consumototal;
                }
                printf("O valor do consumo total e: %f\n",consumototal);
            break;
        }
    }
}