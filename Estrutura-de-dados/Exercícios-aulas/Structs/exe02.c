/*
Declare um tipo Fraction que consista em uma struct contendo dois membros, numerador e denominador, do tipo int, e faça o seguinte:
Escreva uma função setFraction que recebe dois argumentos do tipo int (o numerador e o denominador), e retorna os valores em um tipo Fraction.
Escreva uma função multFraction que recebe dois argumentos do tipo Fraction, multiplica, armazena o resultado em uma outra variável do tipo Fraction e retorna esta variável. 
*/

#include <stdio.h>

typedef struct fraction{
    int numerador;
    int denominador;
} Fraction;

Fraction setFraction(int num, int den){
    Fraction fraction;
    fraction.numerador = num;
    fraction.denominador = den;

    return fraction;
}

Fraction multFraction(Fraction f1, Fraction f2){
    Fraction produto = {(f1.numerador * f2.numerador), (f1.denominador * f2.denominador)};

    return produto;
}

int calcularMDC(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction simplificarFacao(int numerador, int denominador) {

    Fraction fraction;

    int mdc = calcularMDC(numerador, denominador);

    fraction.numerador = numerador / mdc;
    fraction.denominador = denominador / mdc;

    return fraction;
}

int main(void){

    int num, den; 
    Fraction f1, f2, resultado, resulSimplificado;

    printf("Informe a fração 1 (X/Y): ");
    scanf("%d/%d", &num, &den);

    f1 = setFraction(num, den);

    num = 0;
    den = 0;

    printf("Informe a fração 2 (X/Y): ");
    scanf("%d/%d", &num, &den);

    f2 = setFraction(num, den);

    resultado = multFraction(f1, f2);
    resulSimplificado = simplificarFacao(resultado.numerador, resultado.denominador);

    printf("\nProduto das frações: %d/%d = %d/%d\n", resultado.numerador, resultado.denominador, resulSimplificado.numerador, resulSimplificado.denominador);

    return 0;
}