#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int opcao = 0;
    int i = 0, j = 0, c = 0;
    float parede[4] = {0};
    float perimetro = 0;
    char comodo[10][20] = {0};
    int eh_cozinha = 0; // Nova variável para a pergunta de Sim ou Não

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
            
            while(1) {
                // Pergunta de SIM ou NÃO antes de tudo
                printf("\nO comodo a ser dimensionado e uma cozinha?\n");
                printf("1 - Sim\n");
                printf("2 - Nao\n");
                printf("0 - Voltar ao menu principal\n");
                scanf("%d", &eh_cozinha);

                // Condição de parada mudou para a opção 0 aqui
                if(eh_cozinha == 0) {
                    break;
                }

                // Agora pede o nome do cômodo normalmente
                printf("\nInsira o nome do comodo %d: \n", c + 1);
                scanf("%s", comodo[c]);

                perimetro = 0; 

                // Lê o tamanho das 4 paredes
                for (i = 0; i < 4; i++) {
                    printf("Digite o tamanho da parede %d: \n", i + 1);
                    scanf("%f", &parede[i]);
                }

                printf("\n");
                
                // Imprime os tamanhos e soma o perímetro
                for (j = 0; j < 4; j++) {
                    printf("O tamanho da parede %d e: %.2f \n", j + 1, parede[j]);
                    perimetro += parede[j]; 
                }

                printf("\nO perimetro total do comodo '%s' e: %.2f \n", comodo[c], perimetro);
                
                // VERIFICAÇÃO SIMPLES (Sim ou Não)
                if (eh_cozinha == 1) {
                    // O que será feito se SIM (for cozinha)
                    printf("-> Aqui entrara a logica para a COZINHA.\n");
                } 
                else {
                    // O que será feito se NÃO (outros cômodos)
                    printf("-> Aqui entrara a logica para os OUTROS COMODOS.\n");
                }
                
                c++; // Incrementa para o próximo cômodo
            }
        }
    }

    return 0;
}