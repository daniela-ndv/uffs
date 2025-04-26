/*
Crie uma estrutura representando os alunos de um determinado curso. 
A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.
Permita ao usuário entrar com os dados de 5 alunos.
Encontre o aluno com maior nota da primeira prova.
Encontre o aluno com maior média geral.
Encontre o aluno com menor média geral.
Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação.
*/

#include <stdio.h>
#include <string.h>
#define QTD_ALUNOS 5
#define QTD_NOTAS 3

typedef struct aluno{
    int matricula;
    char nome[41];
    float notas[QTD_NOTAS];
} Aluno;

void verificaAprov(Aluno, int);
void maiorNotaP1(Aluno [], int, int);
void maiorEMenorMedias(Aluno [], int, int);

int main(void){

    Aluno turma[QTD_ALUNOS];

    for(int i = 0; i < QTD_ALUNOS; i++){
        printf("\nAluno %d: \n", i+1);

        printf("Matrícula: ");
        scanf("%d", &turma[i].matricula);
        getchar();

        printf("Nome: ");
        fgets(turma[i].nome, 41, stdin);
        turma[i].nome[strcspn(turma[i].nome, "\n")] = 0; // Limpar o enter
        
        for(int j = 0; j < QTD_NOTAS; j++){
            while(1){
                printf("Nota %d: ", j+1);
                scanf("%f", &turma[i].notas[j]);
            
                if(turma[i].notas[j] > 10 || turma[i].notas[j] < 0){
                    printf("Nota inválida! Informe uma nota de 0 a 10.\n");
                    continue;
                } else {
                    break;
                }
            }
        }   

        verificaAprov(turma[i], QTD_NOTAS);
    }

    maiorNotaP1(turma, QTD_ALUNOS, QTD_NOTAS);
    maiorEMenorMedias(turma, QTD_ALUNOS, QTD_NOTAS);

    return 0;
}

void verificaAprov(Aluno aluno, int qtdNotas){
    float somaNotas = 0, media;

    for(int i = 0; i < qtdNotas; i++){
        somaNotas += aluno.notas[i];
    }

    media = somaNotas / qtdNotas;

    if(media >= 6){
        printf("Aluno aprovado!\n");
    } else {
        printf("Aluno reprovado.\n");
    }
}

void maiorNotaP1(Aluno alunos[], int qtdAlunos, int qtdNotas){
    float maiorNota = alunos[0].notas[0];
    Aluno alunoComMaiorNota = alunos[0]; 

    for(int i = 1; i < qtdAlunos; i++){
        for(int j = 0; j < qtdNotas; j++){
            if(alunos[i].notas[j] > maiorNota){
                maiorNota = alunos[i].notas[j];
                alunoComMaiorNota = alunos[i];
            }
        }
    }

    printf("\nMaior nota: %.2f => Aluno: %s | Matrícula: %d \n", maiorNota, alunoComMaiorNota.nome, alunoComMaiorNota.matricula);
}

void maiorEMenorMedias(Aluno alunos[], int qtdAlunos, int qtdNotas){
    float maiorMedia = 0, menorMedia = 999;
    Aluno alunoComMaiorMedia = alunos[0], alunoComMenorMedia = alunos[0]; 

    printf("\nMédias dos alunos:\n");

    for(int i = 0; i < qtdAlunos; i++){
        float media = 0, somaNotas = 0;

        for(int j = 0; j < qtdNotas; j++){
            somaNotas += alunos[i].notas[j];
        }

        media = somaNotas / qtdNotas;
        printf("- %s: %.2f\n", alunos[i].nome, media);

        if(media > maiorMedia){
            maiorMedia = media;
            alunoComMaiorMedia = alunos[i];
        }

        if(media < menorMedia){
            menorMedia = media;
            alunoComMenorMedia = alunos[i];
        }
    }

    printf("\nAluno com maior média: %s => Matrícula: %d\n", alunoComMaiorMedia.nome, alunoComMaiorMedia.matricula);
    printf("\nAluno com menor média: %s => Matrícula: %d\n", alunoComMenorMedia.nome, alunoComMenorMedia.matricula);
}