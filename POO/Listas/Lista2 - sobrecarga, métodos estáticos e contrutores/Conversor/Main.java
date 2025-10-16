/** Crie uma classe Conversor com dois métodos estáticos para conversões:
* double celsiusParaFahrenheit(double c)
* double fahrenheitParaCelsius(double f)
Utilize os métodos sem instanciar a classe para fazer as seguintes conversões:
* 25°C para Fahrenheit
* 100°F para Celsius 
 */

public class Main{
    public static void main(String[] args) {

        System.out.printf("25,0°C = %.1f°F\n", Conversor.celsiusParaFahrenheit(25.0));
        System.out.printf("100,0°F = %.1f°C\n", Conversor.fahrenheitParaCelsius(100.0));
    }
}