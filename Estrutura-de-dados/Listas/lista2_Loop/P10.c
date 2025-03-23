/*
10. ⊘ Um professor gostaria de ter um programa para calcular a média final de seus alunos. 
Para isso, ele informa a matrícula e as 5 notas que o alunos teve durante o semestre. 
Após informar as 5 notas, o programa imprime a matrícula do aluno e a média que obteve (média aritmética simples). 
Quando o professor digitar 0 o programa finaliza e apresenta a média geral da turma. Proibido colocar 5 scanf para pedir as notas. 

Exemplo: 
Matrícula: 22010 
Nota 1: 4 
Nota 2: 6 
Nota 3: 6 
Nota 4: 6 
Nota 5: 8 
Aluno: 22010  Média: 6.0
Matrícula: 0 
Média geral da turma: 6.0
*/

#include <stdio.h>

float calcularMedia(int);

int main(void){

    float sumNotas = 0;
    int contAlunos = 0;

    while(1){
        int matricula;
        float sumNotasAluno = 0, mediaAluno = 0;
        
        printf("\nMatrícula: ");
        scanf("%d", &matricula);

        if(matricula == 0){
            break;
        }

        for(int i = 1; i <=5; i++){
            float nota = 0;

            printf("Nota %d: ", i);
            scanf("%f", &nota);

            sumNotasAluno += nota;
        }

        mediaAluno = sumNotasAluno/5;
        printf("Aluno: %d Média: %.1f", matricula, mediaAluno);

        sumNotas += mediaAluno;
        contAlunos += 1;
    }

    printf("Média geral da turma: %.1f\n", ((float)sumNotas/contAlunos));

    return 0;
}