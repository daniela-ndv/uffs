public class Show extends Evento {
    protected int qtdIntegrantes;

    public Show(String nome, int qtdVagas, double precoBase, int qtdIntegrantes){
        super(nome, qtdVagas, precoBase);

        if (qtdIntegrantes <= 0){ System.out.println("Erro! A quantidade de integrantes do show deve ser maior que zero."); }

        this.qtdIntegrantes = qtdIntegrantes;
    }

    public int getQtdIntegrantes() {
        return qtdIntegrantes;
    }

    public void setQtdIntegrantesa(int qtdIntegrantes) {
        this.qtdIntegrantes = qtdIntegrantes;
    }

    @Override
    public double calculaPreco(){
        return getPrecoBase();
    }
}
