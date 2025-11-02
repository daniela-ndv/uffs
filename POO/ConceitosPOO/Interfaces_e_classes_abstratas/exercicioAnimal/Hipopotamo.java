public class Hipopotamo extends Animal {

    public Hipopotamo(){
        super("Artiodátilo");
    }
    
    @Override
    public void emiteSom(){
        System.out.println("roonn roonn!");
    }

    public void movimenta(){
        System.out.println("Movimentação do hipopótamo");
    }
}
