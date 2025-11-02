public class Estudante extends Pessoa{
    
    public Estudante(String nome){
        super(nome, "Estudante");
    }

    public void imprimeNome(){
        System.out.println("O nome do estudante é " + this.nome);
    }

    public void imprimeOcupacao(){
        System.out.println("Estudante");
    }
}
