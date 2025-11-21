/* Faça um programa em Java que funciona como a seguir. O programa sorteia um número aleatório entre 1 e 100. O usuário tenta adivinhar o número sorteado. 
O programa informa se o palpite é maior ou menor que o número sorteado. Este processo é repetido até que o usuário acerte o número sorteado */

import java.util.Random;
import java.util.Scanner;

public class Exercicio6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random r = new Random();

        int num = r.nextInt(100);
        boolean acertou = false;

        System.out.println("Num: "+num);

        while(acertou == false){
            System.out.printf("Informe o número: ");
            int nTeste = scanner.nextInt();

            if(nTeste == num){ 
                acertou = true;
            }

            if(acertou){
                System.out.println("Acertou!");
            } else {
                if(nTeste > num){ 
                    System.out.println("O palpite é maior que o valor! Digite novamente.");
                } else {
                    System.out.println("O palpite é menor que o valor! Digite novamente.");   
                }
            }
        }
    
        scanner.close();
    }
}
