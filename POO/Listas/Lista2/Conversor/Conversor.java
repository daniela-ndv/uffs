public class Conversor {
    
    static double celsiusParaFahrenheit(double c){
        return ((c * (9.0/5.0)) + 32);
    }

    static double fahrenheitParaCelsius(double f){
        return ((f - 32) * (5.0/9.0));
    }

}
