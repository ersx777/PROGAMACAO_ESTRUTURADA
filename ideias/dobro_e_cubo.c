#include <stdio.h>


int calcularDobro(int numero) {
    return numero * 2;
}

int calcularCubo(int numero) {
    return numero * numero * numero;
}

int main(void) {
    int opcao;
    int valor;

    do {
        // Exibição do Menu
        printf("\n--- Escolha uma opcao ---\n");
        printf("1. Dobro de um numero\n");
        printf("2. Cubo de um numero\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        // Validação da Opção
        if (opcao < 1 || opcao > 3) {
            printf("\nOpcao invalida, digite uma opcao valida.\n");
            continue; // Pula o resto do código e volta para o início do laço
        }

        // Execução baseada na escolha
        switch(opcao) {
            case 1:
                printf("Insira o valor que sera dobrado: ");
                scanf("%d", &valor);
                printf("O dobro de %d eh: %d\n", valor, calcularDobro(valor));
                break; // O break impede que o código "vaze" para o case 2

            case 2:
                printf("Insira o valor que sera elevado ao cubo: ");
                scanf("%d", &valor);
                printf("O cubo de %d eh: %d\n", valor, calcularCubo(valor));
                break;

            case 3:
                printf("\nSaindo do programa...\n");
                break;
        }

    } while (opcao != 3); // O laço se repete até o usuário digitar 3

    return 0;
}