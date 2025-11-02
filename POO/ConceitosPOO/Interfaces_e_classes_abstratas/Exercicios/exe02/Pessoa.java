public abstract class Pessoa {
    
    String nome;
    String ocupacao;

    public Pessoa(String nome, String ocupacao){
        this.nome = nome;
        this.ocupacao = ocupacao;
    }

    public abstract void imprimeNome();
    public abstract void imprimeOcupacao();
}
