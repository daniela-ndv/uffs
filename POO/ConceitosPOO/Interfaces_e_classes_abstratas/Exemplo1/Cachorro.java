public class Cachorro extends Animal {

    public Cachorro(String nome){
        super(nome);
    }

    @Override
    public void fazerSom(){
        System.out.println("Au!");
    }
    
    public void dormir(){
        System.out.println(this.nome + " está dormindo!");
    }
}
