/* Faça um programa em Java que percorre um vetor de doubles e apresenta a média e a mediana dos valores do vetor. */

import java.util.Arrays;

public class Exercicio2 {
    public static void main(String[] args) {
        double[] vet = new double[10];
        double soma = 0.0, media = 0.0, mediana = 0.0;

        for(int i = 0; i < vet.length; i++){
            System.out.println(i+1 + "° = " + i);
            vet[i] = i;
        }

        for(int j = 0; j < vet.length; j++){
            soma += vet[j];
        }

        media = soma / vet.length;

        Arrays.sort(vet);

        if(vet.length % 2 != 0){
            int posicao = vet.length / 2;
            mediana = vet[posicao];
        } else{
            int posicao = vet.length / 2;
            mediana = (vet[posicao] + vet[posicao - 1]) / 2; 
        }

        System.out.println("Soma: " + soma);
        System.out.println("Média: " + media);
        System.out.println("Mediana: " + mediana);
    }
}
