/*
9. ⊘ Fazer um programa que simule um campeonato com 4 times (A, B, C e D). Sera pedido o nome do primeiro time com os gols marcados e o nome do segundo time 
com os gols marcados. Este processo se repetirá até que seja informado um valor diferente de A, B, C ou D para o primeiro time. Ao final deverá ser apresentado 
o número de pontos de cada time e o campeão. Caso houver empate na primeira colocação informar que não houve campeão. 

Cálculo dos pontos: vitória 3 pontos, empate 1 ponto e derrota 0 ponto. Exemplo: 
Time: A 
Gols: 2 
Time: B 
Gols: 1 
Time: C 
Gols: 2 
Time: A 
Gols: 4 
Time: X ← valor diferente de A, B, C ou D, então finaliza 
Campeão: A 
A: 6 pontos 
B: 0 pontos 
C: 0 pontos 
D: 0 pontos 
*/

#include <stdio.h>

void verificarPontos(int, int, char, char, int*);
char verificaVencedor(int*);

int main(void)
{
    int pontos[4] = {0, 0, 0, 0}, cont = 1;
    char vencedor;

    while(1){
        char time1, time2;
        int gols1 = 0, gols2 = 0;

        printf("\n###### Partida %d ######\n", cont);
        printf("Time 1: ");
        scanf(" %c", &time1);

        if(time1 != 'A' && time1 != 'B' && time1 != 'C' && time1 != 'D'){
            break;
        }
        printf("Gols 1: ");
        scanf("%d", &gols1);

        printf("Time 2: ");
        scanf(" %c", &time2);
        printf("Gols 2: ");
        scanf("%d", &gols2);

        verificarPontos(gols1, gols2, time1, time2, pontos);
        cont++;
    }

    vencedor = verificaVencedor(pontos);

    if(vencedor == ' '){
        printf("\n🏆🥇 Empate! Não houve campeão");
    } else{
        printf("\n🏆🥇 Campeão: %c", vencedor);
    }

    printf("\nA: %d pontos\n", pontos[0]); 
    printf("B: %d pontos\n", pontos[1]);
    printf("C: %d pontos\n", pontos[2]);
    printf("D: %d pontos\n", pontos[3]);
    
    return 0;
}

void verificarPontos(int golsTime1, int golsTime2, char time1, char time2, int *pontos) {
    int pontos1 = 0, pontos2 = 0;

    if (golsTime1 > golsTime2) {
        pontos1 += 3;  
    }
    else if (golsTime2 > golsTime1) {
        pontos2 += 3;  
    }
    else {
        pontos1 += 1;  
        pontos2 += 1;
    }

    if(time1 == 'A'){
        pontos[0] += pontos1;
    } else if(time1 == 'B'){
        pontos[1] += pontos1;
    } else if(time1 == 'C'){
        pontos[2] += pontos1;
    } else if(time1 == 'D'){
        pontos[3] += pontos1;
    }

    if(time2 == 'A'){
        pontos[0] += pontos2;
    } else if(time2 == 'B'){
        pontos[1] += pontos2;
    } else if(time2 == 'C'){
        pontos[2] += pontos2;
    } else if(time2 == 'D'){
        pontos[3] += pontos2;
    }
}

char verificaVencedor(int *pontos){
    char vencedor = ' ';
    int maiorPontuacao = 0;

    for(int i = 0; i < 4; i++){
        if(pontos[i] > maiorPontuacao) {
            maiorPontuacao = pontos[i];
            vencedor = 'A' + i;
        } else if(pontos[i] == maiorPontuacao) {
            vencedor = ' ';
        }
    }

    return vencedor;
}