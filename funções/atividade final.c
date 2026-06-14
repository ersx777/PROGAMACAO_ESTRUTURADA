#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int opcao = 100;
    int i = 0, j = 0, c = 0;
    
    // Aumentei o array para 5 para evitar um pequeno bug na linha do "if(parede[i]!=0)"
    // quando o laço terminar as 4 paredes e o 'i' valer 4.
    float parede[5] = {0}; 
    float perimetro[10] = {0};
    char comodo[10][20] = {0};
    
    // NOVO ARRAY: Guarda a resposta se é cozinha (1) ou não (2) para cada cômodo 'c'
    int eh_cozinha[10] = {0}; 

    while (opcao != 0) {
        system("cls || clear"); // Limpa a tela para cada parede
        printf("\n=========CALCULO DE TOMADAS=========\n");
        printf("1. Dimensionar tomadas\n");
        printf("2. Mostrar dimensionamentos\n");
        printf("0. Sair\n\n");

        if (opcao != 2) {
            scanf("%d", &opcao);
        }

        if (opcao < 0 || opcao > 2) {
            printf("Opcao invalida, digite uma opcao valida!\n");
        }

        if (opcao == 1) {
            opcao = 100;
            // 1. Recebe os dados das 4 paredes
            while(1) {
                system("cls || clear"); // Limpa a tela
                
                // --- NOVA PERGUNTA INSERIDA AQUI ANTES DO NOME ---
                printf("\nO comodo %d a ser dimensionado e uma cozinha?\n", c + 1);
                printf("1 - Sim\n");
                printf("2 - Nao\n");
                printf("0 - Encerrar / Voltar\n");
                scanf("%d", &eh_cozinha[c]);

                // Mesma lógica de parada que você criou
                if (eh_cozinha[c] == 0) {
                    if (c == 0) {
                        break;
                    } else if (c > 0) {
                        opcao = 2;
                        break;
                    }
                }
                // -------------------------------------------------

                system("cls || clear");
                printf("\nInsira o nome do comodo %d (ou digite 0 para encerrar): \n", c + 1);
                scanf("%s", comodo[c]);

                // Condicao de parada
                if(comodo[c][0] == '0') {
                    if(c == 0) {
                        break;
                    }
                    else if(c > 0) {
                        opcao = 2;
                        break;
                    }
                }

                // Zera o perimetro ANTES de comecar a somar as paredes deste comodo
                perimetro[c] = 0;

                // Le o tamanho das 4 paredes
                for (i = 0; i < 4; i++) {
                    system("cls || clear"); 
                    printf("Comodo: %s\n", comodo[c]);
                    printf("Digite o tamanho da parede %d (digite '0' para voltar ao 'comodo'): \n", i + 1);
                    scanf("%f", &parede[i]);
                    
                    if (parede[i] < 0) {
                        printf("Tamanho invalido, digite um valor positivo!\n");
                        i--; // Decrementa para repetir a leitura desta parede
                    }
                    else if (parede[i] == 0) {
                        break; // Se o usuario digitar 0, encerra a leitura das paredes para este comodo
                    }
                }

                printf("\n");

                if (i == 4 || parede[i] != 0) {
                    // 2. Imprime os tamanhos e soma o perimetro
                    for (j = 0; j < 4; j++) {
                        printf("O tamanho da parede %d e: %.2f \n", j + 1, parede[j]);
                        perimetro[c] += parede[j]; // Vai somando cada parede ao total do comodo atual
                    }

                    // 3. Imprime o resultado final do comodo atual se houver paredes dimensionadas
                    printf("\nO perimetro total do comodo '%s' e: %.2f \n", comodo[c], perimetro[c]);
                    c++; // Incrementa para o proximo comodo
                    printf("\npressione enter para continuar.\n");
                    getchar(); // Limpa o buffer do teclado
                    getchar(); // Espera o usuario pressionar enter
                }
            }
        }
        else if (opcao == 2) {
            opcao = 100;
            if (c == 0) {
                printf("\nNenhum comodo dimensionado ainda!\n\npressione enter para voltar ao menu.\n");
                getchar(); // Limpa o buffer do teclado
                getchar(); // Espera o usuario pressionar enter
            }
            else if (c > 0) {
                system("cls || clear"); 
                printf("\nComodos dimensionados:\n");
                for (i = 0; i < c; i++) {
                    printf("\n%d. %s\n", i + 1, comodo[i]);
                    printf("   Perimetro: %.2f\n", perimetro[i]);
                    
                    // --- CÁLCULO DE TOMADAS ATUALIZADO COM IF/ELSE ---
                    int tomadas_calculadas = 0;
                    
                    // Verifica no novo array se a resposta foi 1 (Sim, é cozinha)
                    if (eh_cozinha[i] == 1) {
                        tomadas_calculadas = (int)(perimetro[i] / 3.5);
                    } else {
                        tomadas_calculadas = (int)(perimetro[i] / 5.0);
                    }
                    
                    // Garante o mínimo de 1 tomada independente do cômodo
                    if (tomadas_calculadas == 0) {
                        printf("   minimo de tomadas: 1\n");
                    } else {
                        printf("   minimo de tomadas: %d\n", tomadas_calculadas);
                    }
                    // -------------------------------------------------
                }
                
                printf("\npressione enter para voltar ao menu.\n");
                getchar(); // Limpa o buffer do teclado
                getchar(); // Espera o usuario pressionar enter
            }
        }
    }

    return 0;
}