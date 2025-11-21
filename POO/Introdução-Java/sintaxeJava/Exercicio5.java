/* Faça um programa em Java que leia um valor inteiro e calcule o menor número de notas necessárias para representar esse valor usando notas de 100, 50, 20, 10, 5, 2 e 1. */

import java.util.Scanner;

public class Exercicio5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Informe um valor inteiro: ");
        int valor = scanner.nextInt();

        int notas100, notas50, notas20, notas10, notas5, notas2, notas1;

        notas100 = valor / 100; valor = valor % 100;
        notas50 = valor / 50; valor = valor % 50;
        notas20 = valor / 20; valor = valor % 20;
        notas10 = valor / 10; valor = valor % 10;
        notas5 = valor / 5; valor = valor % 5;
        notas2 = valor / 2;
        notas1 = valor % 2;

        System.out.println("Notas 100: " + notas100);
        System.out.println("Notas 50: " + notas50);
        System.out.println("Notas 20: " + notas20);
        System.out.println("Notas 10: " + notas10);
        System.out.println("Notas 5: " + notas5);
        System.out.println("Notas 2: " + notas2);
        System.out.println("Notas 1: " + notas1);

        scanner.close();
    }
}