#include <stdio.h>

int main(void) {
    int opcao = 0;
    int i;
    float consumo[3] = {0};      // Potência em Watts
    float horasUso[3] = {0};     // Horas de uso por dia
    char tipodeeletro[3][20];
    float consumototal = 0;
    float valordafatura = 0;
    int status_leitura;
    int dados_inseridos = 0;

    while (opcao != 4) {
        printf("\nEscolha uma opcao:\n");
        printf("1. Inserir consumo dos eletrodomesticos\n");
        printf("2. Obter consumo total (mes)\n");
        printf("3. Valor total da fatura\n");
        printf("4. Sair\n");
        scanf(" %d", &opcao);

        if (opcao <= 0 || opcao > 4) {
            printf("Escolha uma opcao valida\n");
            opcao = 0;
            continue;
        }

        switch (opcao) {
            case 1:
                for (i = 0; i < 3; i++) {
                    printf("Digite o tipo de eletrodomestico %d: \n", i + 1);
                    scanf(" %s", tipodeeletro[i]);

                    do {
                        printf("Digite a potencia do eletrodomestico %d (em Watts, ex: 100): \n", i + 1);
                        status_leitura = scanf("%f", &consumo[i]);
                        while (getchar() != '\n');
                        if (status_leitura != 1 || consumo[i] <= 0)
                            printf("Valor invalido! Digite um numero positivo.\n");
                    } while (status_leitura != 1 || consumo[i] <= 0);

                    do {
                        printf("Quantas horas por dia o aparelho %d fica ligado? \n", i + 1);
                        status_leitura = scanf("%f", &horasUso[i]);
                        while (getchar() != '\n');
                        if (status_leitura != 1 || horasUso[i] <= 0 || horasUso[i] > 24)
                            printf("Valor invalido! Digite entre 0 e 24.\n");
                    } while (status_leitura != 1 || horasUso[i] <= 0 || horasUso[i] > 24);
                }
                dados_inseridos = 1;
                printf("Dados inseridos com sucesso!\n");
                break;

            case 2:
                if (dados_inseridos == 0) {
                    printf("\nErro: Voce precisa inserir os consumos na opcao 1 primeiro!\n");
                } else {
                    consumototal = 0;
                    for (i = 0; i < 3; i++) {
                        // Fórmula correta: (W / 1000) * horas/dia * 30 dias
                        consumototal += (consumo[i] / 1000.0) * horasUso[i] * 30;
                    }
                    printf("\n--- Consumo por aparelho ---\n");
                    for (i = 0; i < 3; i++) {
                        printf("%s: %.2f kWh/mes\n", tipodeeletro[i],
                               (consumo[i] / 1000.0) * horasUso[i] * 30);
                    }
                    printf("O consumo total do mes e: %.2f kWh\n", consumototal);
                }
                break;

            case 3:
                if (dados_inseridos == 0) {
                    printf("\nErro: Voce precisa inserir os consumos na opcao 1 primeiro!\n");
                } else {
                    float tarifa;
                    printf("Digite a tarifa de energia (R$/kWh): ");
                    scanf("%f", &tarifa);

                    consumototal = 0;
                    for (i = 0; i < 3; i++) {
                        // Fórmula correta: (W / 1000) * horas/dia * 30 dias
                        consumototal += (consumo[i] / 1000.0) * horasUso[i] * 30;
                    }

                    valordafatura = consumototal * tarifa;

                    printf("\n--- Consumo por aparelho ---\n");
                    for (i = 0; i < 3; i++) {
                        float consumo_individual = (consumo[i] / 1000.0) * horasUso[i] * 30;
                        printf("%s: %.2f kWh/mes -> R$ %.2f\n", tipodeeletro[i],
                               consumo_individual, consumo_individual * tarifa);
                    }
                    printf("\nConsumo total do mes: %.2f kWh\n", consumototal);
                    printf("Valor total da fatura: R$ %.2f\n", valordafatura);
                }
                break;

            case 4:
                printf("Encerrando o programa...\n");
                break;
        }
    }

    return 0;
}