import exercicioAnimal.Animal;

public class Cachorro implements Animal {

    String nome;

    public Cachorro(String nome){
        this.nome = nome;
    }

    @Override
    public void fazerSom(){
        System.out.println("Au!");
    }

    @Override
    public void mover(){
        System.out.println("Movimento do cachorro.");
    }
    
    public void dormir(){
        System.out.println(this.nome + " está dormindo!");
    }
}
