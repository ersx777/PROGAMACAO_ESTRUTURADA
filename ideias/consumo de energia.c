#include <stdio.h>

int main(void){
    char equipamento[20];
    float potencia, tempo, consumo;
    printf("Digite o nome do equipamento: \n");
    scanf("%s", equipamento);
    printf("Digite a potencia do equipamento (em watts): \n");
    scanf("%f", &potencia);
    printf("Insira o tempo de uso do equipamento por dia (em horas): \n");
    scanf("%f", &tempo);
    consumo= (potencia * tempo * 30) / 1000;
    printf("O consumo de energia do equipamento: %s e de %.2f kWh por mes.\n", equipamento, consumo);
    return 0;
}