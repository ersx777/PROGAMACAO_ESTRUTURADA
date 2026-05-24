#include <stdio.h>

int main(void){
    float N1, N2, Resultado;
    int operacao;
    int continuar; // Variável para guardar a escolha do usuário

    // O 'do' marca o INÍCIO do bloco que vai se repetir
    do {
        printf("\n--- NOVA CONTA ---\n");
        printf("Insira o valor do primeiro numero: ");
        scanf("%f", &N1);
        printf("Insira o valor do segundo numero: ");
        scanf("%f", &N2);

        printf("Digite 1 para adicao, 2 para subtracao, 3 para multiplicacao e 4 para divisao: ");
        scanf("%d", &operacao);

        switch(operacao){
            case 1:
                Resultado = N1 + N2;
                printf("O resultado da adicao e: %.2f\n", Resultado);
                break;
            case 2:
                Resultado = N1 - N2;
                printf("O resultado da subtracao e: %.2f\n", Resultado);
                break;
            case 3:
                Resultado = N1 * N2;
                printf("O resultado da multiplicacao e: %.2f\n", Resultado);
                break;
            case 4:
                if(N2 != 0){
                    Resultado = N1 / N2;
                    printf("O resultado da divisao e: %.2f\n", Resultado);
                } else {
                    printf("Erro: Divisao por zero nao e permitida.\n");
                }
                break;
            default:
                printf("Erro: Operacao invalida.\n");
                break;
        }

        // Agora perguntamos se o usuário quer repetir
        printf("\nDeseja realizar outra operacao? (1 para sim, 0 para nao): ");
        scanf("%d", &continuar);

    // O 'while' avalia a resposta. Se for 1, ele volta para a linha do 'do'. Se for 0, ele sai do laço.
    } while (continuar == 1); 

    // Esta linha fica de fora e só vai rodar quando o laço terminar de vez
    printf("Obrigado por usar a calculadora!\n");

    return 0;
}