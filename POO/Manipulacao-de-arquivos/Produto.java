public class Produto {
    private String nome;
    private double preco;
    private int quantidade;

    Produto(String nome, double preco, int quantidade){
        this.nome = nome;
        this.preco = preco;
        this.quantidade = quantidade;
    }

    public String getNome(){
        return this.nome;
    }
    public void setNome(String nome){
        this.nome = nome;
    }
    public double getPreco(){
        return this.preco;
    }
    public void setPreco(double preco){
        this.preco = preco;
    }
    public int getQuantidade(){
        return this.quantidade;
    }
    public void setQuantidade(int qtd){
        this.quantidade = qtd;
    }

}
