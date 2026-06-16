#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int opcao = 100;
    int i = 0, j = 0, c = 0, quantidade=0, cozinha=0;
    // As cozinhas ficam nos primeiros índices dos comodos
    
    float parede[5] = {0}; 
    float perimetro[10] = {0};
    char comodo[10][20] = {0};
    
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

            system("cls || clear"); // Limpa a tela
            
            // VERIFICA O TIPO DE COMODO
            printf("\nquantos comodos serao adicionados?\n");
            scanf("%d",&quantidade);
            printf("quantos desses comodos sao cozinhas?\n");
            scanf("%d",&cozinha);
            printf("0 - Encerrar / Voltar\n");

            
            // Dados das 4 paredes
            int qnt_cozinha = cozinha;
            while(c < quantidade) {
               
                // -------------------------------------------------
                if (qnt_cozinha!=0){
                    system("cls || clear");
                    
                    sprintf(comodo[c], "cozinha %d", c+1); //sprintf armazena na primeira posição do vetor
                   
                    qnt_cozinha--;
                }
                else {
                    system("cls || clear");
                    printf("\nInsira o nome do comodo %d (ou digite 0 para encerrar): \n", c + 1);
                    scanf("%s", comodo[c]);
                    
                    // CONDICAO DE PARADA
                    if(comodo[c][0] == '0') {
                        if(c == 0) {
                            break;
                        }
                        else if(c > 0) {
                            opcao = 2;
                            break;
                        }
                    }
                }
    
                // Zera o perimetro ANTES de comecar a somar as paredes deste comodo
                perimetro[c] = 0;
                
                for (i = 0; i < 4; i++) {
                    system("cls || clear"); 
                    printf("Comodo: %s\n", comodo[c]);
                    printf("Digite o tamanho da parede %d (digite '0' para voltar ao 'comodo'\n Para editar o nome do comodo, digite o novo nome ): \n", i + 1);
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
                    
                    for (j = 0; j < 4; j++) {
                        printf("O tamanho da parede %d e: %.2f \n", j + 1, parede[j]);
                        perimetro[c] += parede[j]; // Vai somando cada parede ao total do comodo atual(SOMA DO PERIMETRO P/ COMODO)
                    }
                    
                    // PERIMETRO
                    printf("\nO perimetro total do comodo '%s' e: %.2f \n", comodo[c], perimetro[c]);
                    c++; // Incrementa para o proximo comodo
                    printf("\npressione enter para continuar.\n");
                    getchar(); // Limpa o buffer do teclado
                    getchar(); // Espera o usuario pressionar enter
                }
            }

            if(c > 0) {
                opcao = 2;
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
                    
                    //CÁLCULO DE TOMADAS
                    int tomadas_calculadas = 0;
                    
                    // verifica se a posição do vetor contem uma cozinha
                    if (i<cozinha) {
                        tomadas_calculadas = (int)(perimetro[i] / 3.5);
                    } 
                   //calculo para comodos normais
                    else {
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
                
                // printf("Eu quero sorvete de flocos.");
                printf("\npressione enter para voltar ao menu.\n");
                getchar(); // Limpa o buffer do teclado
                getchar(); // Espera o usuario pressionar enter
            }
        }
    }
    return 0;
}