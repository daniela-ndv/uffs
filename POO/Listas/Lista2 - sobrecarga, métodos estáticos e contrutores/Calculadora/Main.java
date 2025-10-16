/** Implemente uma classe Calculadora com os seguintes métodos chamados soma:
* int soma(int a, int b)
* double soma(double a, double b)
Teste os dois métodos, chamando-os com diferentes parâmetros e imprimindo os resultados. */

public class Main{
    public static void main(String[] args) {
        Calculadora calc = new Calculadora();
        
        int a = 2;
        int b = 3;
        int c = 4;
        System.out.println(a+" + "+b+" = "+calc.soma(a, b));
        System.out.println(a+" + "+b+" + "+c+" = "+calc.soma(a, b, c));

        double v1 = 2.0;
        double v2 = 4.0;
        double v3 = 1.0;
        double v4 = 5.0;
        System.out.println(v1+" + "+v2+" = "+calc.soma(v1, v2));
        System.out.println(v1+" + "+v2+" + "+v3+" + "+v4+" = "+calc.soma(v1, v2, v3, v4));
    }
}