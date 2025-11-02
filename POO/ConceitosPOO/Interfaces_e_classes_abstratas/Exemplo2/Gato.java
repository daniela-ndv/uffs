import exercicioAnimal.Animal;

public class Gato implements Animal{
    
    String nome; 

    public Gato(String nome){
        this.nome = nome; 
    }

    @Override
    public void fazerSom(){
        System.out.println("Miau!");
    }

    @Override
    public void mover(){
        System.out.println("Movimento do gato.");
    }

    public void dormir(){
        System.out.println(this.nome + " está dormindo!");
    }
}
