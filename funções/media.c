#include <stdio.h>


float mediaf(float a,float b, float c,float d,float e){
    float media;
    media=(a+b+c)/3;
    return media;
}

int main(void){
    float n1,n2,n3,n4,n5;
    char alunos[5][50];
    float notas[5][3];
    int a,n;//a representa os alunos e n as notas

    for(a=0;a<5;a++){
        printf("\n Insira o nome do aluno %d: ",a+1);
        scanf("%s",&alunos[a]);

        for(n=0;n<3;n++){
            printf("\nInsira a nota %d: ",n+1);
            scanf("%f",&notas[a][n]);
        }

        
        
    }

    //printf("\nA media das notas e: %f", mediaf(n1,n2,n3));

    return 0;
}
/*criar um programa,para calcular a média das notas de 5 alunoos.

Deve-se: 
1)Usar vetor para armazenar os nome de alunos e suas notas
2)A media das notas deve ser calculada por função
3)Ao final deve ser mostrado:
- quem foi aprovado;
- quem ficou de prova final;
- quem reprovou;






*/