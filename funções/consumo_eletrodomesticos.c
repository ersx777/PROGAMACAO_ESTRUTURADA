//Cria um programa que:
/*
1)Solicite aos usuarios os eletro que possii e informe o comsumo em kw/h da entiqueta, ex: Ventilador 0.12 kw/h.
Somente 3.
2)Mostrar o consumo total do Mes,considerando todos os eletros informados funcionando: Todos os dias,todos os dias,sem desligar e durante o mes
3)Mostrar o valor da fatura, considerando 1 KW --> R$1.25.
*/
#include<stdio.h>

int main(void){
    int opcao=0;
    float consumo[3][3]={0};
    float consumototal;
    float valordafatura;
    while(opcao=!4){
        printf("\nEscolha uma opcao:\n");
        printf("1.Inserir consumo dos eletros\n");
        printf("2.Obter consumo total(mes)\n");
        printf("3.Valor total da fatura\n");
        print("4.Sair\n");
        scanf("%d",&opcao);
        if(opcao<0||opcao==0||opcao>4){
                printf("Escolha uma opcao valida\n");
                opcao=0;
            }
    
    }
    
}