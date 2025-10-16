package introdução.exemplos;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
    
        Circulo circulo = new Circulo();
        Triangulo triangulo = new Triangulo();
        Quadrado quadrado = new Quadrado();

        double areaCirculo, areaTriangulo, areaQuadrado;

        /*System.out.println("Imprimindo atributos antes: ");
        System.out.println("-> Raio do círculo: " + circulo.raio);
        System.out.println("-> Base do triângulo: " + triangulo.base);
        System.out.println("-> Altura do triângulo: " + triangulo.altura);
        System.out.println("-> Lado do quadrado: " + quadrado.lado);*/

        System.out.println("\n****** Informe as medidas ******");

        System.out.print("Raio: ");
        circulo.raio = scanner.nextDouble();
       
        System.out.print("Base: ");
        triangulo.base = scanner.nextDouble();

        System.out.print("Altura: ");
        triangulo.altura = scanner.nextDouble();

        System.out.print("Lado: ");
        quadrado.lado = scanner.nextDouble();

        areaCirculo = circulo.calcularArea();
        areaTriangulo = triangulo.calcularArea();
        areaQuadrado = quadrado.calcularArea();

        /*System.out.println("\nImprimindo atributos depois da atribuição: ");
        System.out.println("-> Raio do círculo: " + circulo.raio);
        System.out.println("-> Base do triângulo: " + triangulo.base);
        System.out.println("-> Altura do triângulo: " + triangulo.altura);
        System.out.println("-> Lado do quadrado: " + quadrado.lado);*/

        System.out.println("\n****** Áreas das figuras ****** ");
        System.out.println("Área do círculo: " + areaCirculo);
        System.out.println("Área do triângulo: " + areaTriangulo);
        System.out.println("Área do quadrado: " + areaQuadrado); 

        scanner.close();
    }
}
