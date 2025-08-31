
// locale

public class Introducao  {
    public static void main(String[] args){
        System.out.println("Olá!");

        double soma, a, b;
        a = 9.0;
        b = 13.0;
        soma = a + b;
        
        String str1 = "Uma string";
        char c = 'A';
        
        System.out.println("Soma: " + soma);
        System.out.println("Double com formato: " + String.format("%.2f", soma) + "\n");

        System.out.println("Caractere: " + c);
        System.out.println("Texto: " + str1 + "\n");

        boolean bl = (a == b);
        System.out.println(a + " == " + b + " ? " + bl);

        if(bl){
            System.out.println("Iguais!");
        } else {
            System.out.println("Diferentes!");
        }
        
        int dia = 7;

        switch (dia) {
            case 1:
                System.out.println("Domingo");
                break;
            case 2:
                System.out.println("Segunda");
                break;
            case 3:
                System.out.println("Terça");
                break;
            case 4:
                System.out.println("Quinta");
                break;
            case 6:
                System.out.println("Sexta");
                break;
            case 7:
                System.out.println("Sábado");
                break;
            default:
                System.out.println("Dia inválido");
                break;
        }

    }
}
