public abstract class Evento {
    private String nome;
    private int qtdVagas;
    private double precoBase;

    public Evento(String nome, int qtdVagas, double precoBase){
        if(precoBase < 0) { System.out.println("Erro! O preço base do evento deve ser maior ou igual a zero."); }
        
        if (qtdVagas <= 0) { System.out.println("Erro! A quantidade de vagas disponíveis do evento deve ser maior que zero."); }

        this.nome = nome;
        this.qtdVagas = qtdVagas;
        this.precoBase = precoBase;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getQtdVagas() {
        return qtdVagas;
    }

    public void setQtdVagas(int qtdVagas) {
        this.qtdVagas = qtdVagas;
    }

    public double getPrecoBase() {
        return precoBase;
    }

    public void setPrecoBase(double precoBase) {
        this.precoBase = precoBase;
    }

    protected abstract double calculaPreco();

}
