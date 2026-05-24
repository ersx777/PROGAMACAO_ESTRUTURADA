#include <stdio.h>
#include <windows.h>
#include <string.h>

int main(void){
    SetConsoleOutputCP(CP_UTF8);
    
    char nome[3][35];
    int matricula[3];
    char situacao[3][20]; // Evitar usar 'ç' ou '~' em nomes de variáveis
    int i;

    for(i=0; i<3; i++){
        printf("\n------------------- Cadastro %d -------------------\n", i+1);
        
        printf("Digite seu nome completo: ");
        fgets(nome[i], sizeof(nome[i]), stdin);
        nome[i][strcspn(nome[i], "\n")] = '\0';

        printf("Digite sua matricula: ");
        scanf("%d", &matricula[i]);
        
        // --- LIMPEZA DE BUFFER OBRIGATÓRIA AQUI ---
        while (getchar() != '\n'); 

        printf("Digite a situação do aluno: ");
        fgets(situacao[i], sizeof(situacao[i]), stdin);
        situacao[i][strcspn(situacao[i], "\n")] = '\0';
    }

    printf("\n==========================================================\n");
    printf("Dados 1:\nNome: %s\nMatricula: %d\nSituação: %s", nome[0], matricula[0], situacao[0]);
    printf("\n\nDados 2:\nNome: %s\nMatricula: %d\nSituação: %s", nome[1], matricula[1], situacao[1]);
    printf("\n\nDados 3:\nNome: %s\nMatricula: %d\nSituação: %s", nome[2], matricula[2], situacao[2]);
    printf("\n==========================================================\n");

    return 0;
}