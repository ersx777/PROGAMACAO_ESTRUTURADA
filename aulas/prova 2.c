#include <stdio.h>

int main() {

    float consumo[3][5];
    float somasetor;
    float menor;
    int setormenor, diamenor;
    int i, j;

    int opcao = 0;
    int preenchido = 0;

    while(opcao != 5) {

        printf("\n============ MENU ============\n");
        printf("1. Inserir consumo\n");
        printf("2. Mostrar a matriz de consumo\n");
        printf("3. Media de consumo por setor\n");
        printf("4. Setor mais eficiente\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // OPÇÃO 1
        if(opcao == 1) {

            for(i = 0; i < 3; i++) {

                for(j = 0; j < 5; j++) {

                    printf("Digite o consumo do setor %d no dia %d: ",
                           i + 1, j + 1);

                    scanf("%f", &consumo[i][j]);
                }
            }

            preenchido = 1;
        }

        // OPÇÃO 2
        else if(opcao == 2) {

            if(preenchido == 0) {

                printf("A matriz de consumo esta vazia.\n");
            }
            else {

                printf("\nMatriz de consumo:\n");

                for(i = 0; i < 3; i++) {

                    for(j = 0; j < 5; j++) {

                        printf("%.1f\t", consumo[i][j]);
                    }

                    printf("\n");
                }
            }
        }

        // OPÇÃO 3
        else if(opcao == 3) {

            if(preenchido == 0) {

                printf("Ainda nao foram atribuidos valores para obter a media.\n");
            }
            else {

                for(i = 0; i < 3; i++) {

                    somasetor = 0;

                    for(j = 0; j < 5; j++) {

                        somasetor += consumo[i][j];
                    }

                    printf("Media de consumo do setor %d: %.2f\n",
                           i + 1, somasetor / 5);
                }
            }
        }

        // OPÇÃO 4
        else if(opcao == 4) {

            if(preenchido == 0) {

                printf("Ainda nao foram atribuidos valores.\n");
            }
            else {

                // Inicialização correta
                menor = consumo[0][0];
                setormenor = 1;
                diamenor = 1;

                for(i = 0; i < 3; i++) {

                    for(j = 0; j < 5; j++) {

                        if(consumo[i][j] < menor) {

                            menor = consumo[i][j];
                            setormenor = i + 1;
                            diamenor = j + 1;
                        }
                    }
                }

                printf("O setor mais eficiente foi o setor %d\n",
                       setormenor);

                printf("Menor consumo: %.2f no dia %d\n",
                       menor, diamenor);
            }
        }

        // OPÇÃO INVÁLIDA
        else if(opcao != 5) {

            printf("Opcao invalida!\n");
        }
    }

    printf("Programa encerrado.\n");

    return 0;
}