#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int opcao = 0;
    int i = 0, j = 0, c = 0;
    float parede[4] = {0};
    float perimetro = 0;
    char comodo[10][20] = {0};

    while (opcao != 2) {
        printf("\n==============================\n");
        printf("1. Dimensionar tomadas\n");
        printf("2. Sair\n");
        scanf("%d", &opcao);

        if (opcao <= 0 || opcao > 2) {
            printf("Opcao invalida, digite uma opcao valida!\n");
        }

        if (opcao == 1) {
            opcao = 0;
            // 1. Recebe os dados das 4 paredes
            while(1) {
                printf("\nInsira o nome do comodo %d (ou digite 0 para voltar): \n", c + 1);
                scanf("%s", comodo[c]);

                // Condição de parada
                if(comodo[c][0] == '0') {
                    break;
                }

                // Zera o perímetro ANTES de começar a somar as paredes deste cômodo
                perimetro = 0; 

                // Lê o tamanho das 4 paredes
                for (i = 0; i < 4; i++) {
                    printf("Digite o tamanho da parede %d: \n", i + 1);
                    scanf("%f", &parede[i]);
                }

                printf("\n");
                
                // 2. Imprime os tamanhos e soma o perímetro
                for (j = 0; j < 4; j++) {
                    printf("O tamanho da parede %d e: %.2f \n", j + 1, parede[j]);
                    perimetro += parede[j]; // Vai somando cada parede ao total do cômodo atual
                }

                // 3. Imprime o resultado final do cômodo atual
                printf("\nO perimetro total do comodo '%s' e: %.2f \n", comodo[c], perimetro);
                
                c++; // Incrementa para o próximo cômodo
            }
        }
    }

    return 0;
}