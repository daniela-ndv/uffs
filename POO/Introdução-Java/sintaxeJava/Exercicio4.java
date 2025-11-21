/* 5. Faça um programa em Java que peça ao usuário uma string e retorne o número de vogais que existem nesta string.
Dica: Utilize os métodos length e charAt da string */
/*
String myStr = "Hello";
char result = myStr.charAt(0);
System.out.println(result);
 */

import java.util.Scanner;

public class Exercicio4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Informe uma string: ");
        String str = scanner.nextLine();

        int vogais = 0;
        char[] array = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < str.length(); i++) {
            char caractere = str.charAt(i);

            char caractereMinusculo = Character.toLowerCase(caractere);

            for(char el : array){
                if (el == caractereMinusculo){
                    vogais++; 
                    break;
                }
            }
        }

        System.out.println("\nString: " + str);
        System.out.println("Quantidade de vogais: " + vogais);

        scanner.close();
    }
}
