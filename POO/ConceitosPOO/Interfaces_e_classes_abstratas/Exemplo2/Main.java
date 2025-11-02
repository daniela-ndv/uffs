import exercicioAnimal.Cachorro;
import exercicioAnimal.Gato;

public class Main {
    public static void main(String[] args) {
        Cachorro cao = new Cachorro("Caramelo");
        Gato gato = new Gato("Rex");

        cao.fazerSom();
        cao.mover();
        cao.dormir();

        gato.fazerSom();
        gato.mover();
        gato.dormir();
    }
}
