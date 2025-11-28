public class PecaTeatral extends Evento {
    private double taxa;
    
    public PecaTeatral(String nome, int qtdVagas, double precoBase, double taxa){
        super(nome, qtdVagas, precoBase);

        if (taxa < 0){ System.out.println("Erro! A taxa da peça deve ser maior que zero."); }

        this.taxa = taxa;
    }

    @Override
    public double calculaPreco(){
        return getPrecoBase() + taxa;
    }

}
