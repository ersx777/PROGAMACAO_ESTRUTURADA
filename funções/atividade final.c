#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int opcao = 100;
    int i = 0, j = 0, c = 0;
    float parede[4] = {0};
    float perimetro[10] = {0};
    char comodo[10][20] = {0};

    while (opcao != 0) {
        system("cls || clear"); // Limpa a tela para cada parede
        printf("\n==============================\n");
        printf("1. Dimensionar tomadas\n");
        printf("2. Mostrar dimensionamentos\n");
        printf("0. Sair\n\n");

        if (opcao != 2){
            scanf("%d", &opcao);
        }

        if (opcao < 0 || opcao > 2) {
            printf("Opcao invalida, digite uma opcao valida!\n");
        }

        if (opcao == 1) {
            opcao = 100;
            // 1. Recebe os dados das 4 paredes
            while(1) {
                system("cls || clear"); // Limpa a tela para cada parede
                printf("\nInsira o nome do comodo %d (ou digite 0 para encerrar): \n", c + 1);
                scanf("%s", comodo[c]);

                // Condição de parada
                if(comodo[c][0] == '0') {
                    if(c == 0) {
                        break;
                    }
                    else if(c > 0) {
                        opcao = 2;
                        break;
                    }
                }

                // Zera o perímetro ANTES de começar a somar as paredes deste cômodo
                perimetro[c] = 0; 

                // Lê o tamanho das 4 paredes
                for (i = 0; i < 4; i++) {
                    system("cls || clear"); // Limpa a tela para cada parede
                    printf("Comodo: %s\n", comodo[c]);
                    printf("Digite o tamanho da parede %d (digite '0' para voltar ao 'comodo'): \n", i + 1);
                    scanf("%f", &parede[i]);
                    if (parede[i] < 0) {
                        printf("Tamanho invalido, digite um valor positivo!\n");
                        i--; // Decrementa para repetir a leitura desta parede
                    }
                    else if (parede[i] == 0) {
                        break; // Se o usuário digitar 0, encerra a leitura das paredes para este cômodo
                    }
                }

                printf("\n");
                
                if (parede[i]!=0){
                // 2. Imprime os tamanhos e soma o perímetro
                for (j = 0; j < 4; j++) {
                    printf("O tamanho da parede %d e: %.2f \n", j + 1, parede[j]);
                    perimetro[c] += parede[j]; // Vai somando cada parede ao total do cômodo atual
                }

                // 3. Imprime o resultado final do cômodo atual se houver paredes dimensionadas
                    printf("\nO perimetro total do comodo '%s' e: %.2f \n", comodo[c], perimetro[c]);
                    c++; // Incrementa para o próximo cômodo
                    printf("\npressione enter para continuar.\n");
                    getchar(); // Limpa o buffer do teclado
                    getchar(); // Espera o usuário pressionar enter
                    
                }
            }
        }
        
        else if (opcao == 2) {
            opcao = 100;
            if (c == 0) {
                printf("\nNenhum comodo dimensionado ainda!\n\npressione enter para voltar ao menu.\n");
                getchar(); // Limpa o buffer do teclado
                getchar(); // Espera o usuário pressionar enter
            } 
            else if (c > 0) {
                system("cls || clear"); // Limpa a tela para cada parede
                printf("\nComodos dimensionados:\n");
                for (i = 0; i < c; i++) {
                    printf("\n%d. %s\n", i + 1, comodo[i]);
                    printf("   Perimetro: %.2f\n", perimetro[i]);
                    if (perimetro[i] < 5) {
                        printf("   minimo de tomadas: 1\n");
                    }
                    else {
                        printf("   minimo de tomadas: %d\n", (int)(perimetro[i] / 5)); // 1 tomada a cada 5 metros de perímetro
                    }
                    
                }
                printf("\npressione enter para voltar ao menu.\n");
                getchar(); // Limpa o buffer do teclado
                getchar(); // Espera o usuário pressionar enter
            }
        }
    }

    return 0;
}