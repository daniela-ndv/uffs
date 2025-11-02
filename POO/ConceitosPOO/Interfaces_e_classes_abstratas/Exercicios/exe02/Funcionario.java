public class Funcionario extends Pessoa {
    
    public Funcionario(String nome){
        super(nome, "Funcionário");
    }

    public void imprimeNome(){
        System.out.println("O nome do funcionário é " + this.nome);
    }

    public void imprimeOcupacao(){
        System.out.println("Funcionário");
    }
}
