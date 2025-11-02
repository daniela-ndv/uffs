public abstract class Animal {
    String categoria;

    public Animal(String categoria){
        this.categoria = categoria;
    }

    public abstract void emiteSom();
}