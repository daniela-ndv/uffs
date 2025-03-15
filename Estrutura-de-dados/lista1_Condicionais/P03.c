/*
3. Faça um programa que calcule a duração de um evento qualquer. Para tal, o programa pede a hora de início e hora de fim (sem os minutos), as horas serão informadas de 0 a 23. 
Perceba que um evento pode começar em um dia e acabar em outro. Os eventos nunca terão duração de mais de 24 horas. 

Exemplos de execução:
    Início: 12			    Início: 10			    Início: 21
    Fim: 4			        Fim: 15			        Fim: 6
    Duração: 16 horas		Duração: 5 horas		Duração: 9 horas
*/

#include <stdio.h>

int calcularDuracao(int inicio, int fim){

    int tempoTotal;

    if(fim < inicio){
        tempoTotal = (24 - inicio) + fim;
    } else {
        tempoTotal = fim - inicio;
    }

    return tempoTotal;
}

int main(void){

    int horaInicio;
    int horaFim;
    int duracao;

    printf("Início: ");
    scanf("%d", &horaInicio);
    printf("Fim: ");
    scanf("%d", &horaFim);

    duracao = calcularDuracao(horaInicio, horaFim);

    printf("Duração: %d horas\n", duracao);

    return 0;
}