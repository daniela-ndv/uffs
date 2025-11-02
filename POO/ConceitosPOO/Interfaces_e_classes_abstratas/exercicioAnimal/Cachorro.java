public class Cachorro extends Canino implements Pet{
    
    @Override
    public void emiteSom(){
        System.out.println("Au!");
    }

    @Override
    public void movimentaEmMatilha(){
        System.out.println("Movimentação do cachorro");
    }

    @Override
    public void brinca(){
        System.out.println("Brincando com a bolinha");
    }

    @Override
    public void rola(){
        System.out.println("Cachorro rolando");
    }
}
