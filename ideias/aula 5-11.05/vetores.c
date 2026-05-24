#include <stdio.h>
#include <windows.h>
#include <string.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char nome[2][50];
    int idade[2];
    int i;

    
    for(i = 0; i < 2; i++) {
        printf("\n--- Cadastro %d ---\n", i + 1);
        
        printf("Digite seu nome completo: ");
        fgets(nome[i], sizeof(nome[i]), stdin);
        
        nome[i][strcspn(nome[i], "\n")] = '\0';
        //strcspn() é usada para encontrar a posição do caractere de nova linha ('\n') e substituí-lo por um caractere nulo ('\0'), removendo assim a nova linha do final da string.

        printf("Digite sua idade: ");
        scanf("%d", &idade[i]);

        while (getchar() != '\n'); 
        //getchar() é usado para limpar o buffer de entrada, garantindo que a próxima leitura de string funcione corretamente.
    }

    printf("\n================================================================\n");
    printf("\nDados 1:\nNome: %s\nIdade: %d anos", nome[0], idade[0]);
    printf("\n\nDados 2:\nNome: %s\nIdade: %d anos", nome[1], idade[1]);
    printf("\n================================================================\n");
    printf("%d pessoas cadastradas", i);

    return 0;
}