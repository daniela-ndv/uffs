import java.util.Scanner;

public class Entrada {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num;

        System.out.println("Digite um número: ");
        num = scanner.nextInt();

        System.out.println("Número: " + num);

        scanner.close();
    }
}
