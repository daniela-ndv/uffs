/**
 * Classe que implementa métodos de soma de inteiros e pontos flutuantes usando sobrecarga.
 * Além disso, são usados argumentos variáveis (varargs) para aceitar uma quantidade dinâmica de argumentos)
 */
public class Calculadora {

    int soma(int... numeros){
        int resultado = 0;
        for(int n : numeros){
            resultado += n;
        }

        return resultado;
    }

    double soma(double... numeros){
        double resultado = 0.0;
        for(double n : numeros){
            resultado += n;
        }

        return resultado;
    }

}
