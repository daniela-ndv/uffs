public class Gato extends Felino implements Pet{
    
    @Override
    public void emiteSom(){
        System.out.println("Miau!");
    }

    @Override
    public void movimentaSolo(){
        System.out.println("Movimentação do gato");
    }

    @Override
    public void brinca(){
        System.out.println("Brincando com o arranhador");
    }

    @Override
    public void rola(){
        System.out.println("Gato rolando");
    }
}
