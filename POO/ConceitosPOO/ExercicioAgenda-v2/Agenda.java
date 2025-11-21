public class Agenda {
    private final int TAM_PESSOAS = 15;
    private Pessoa[] pessoas = new Pessoa[TAM_PESSOAS];
    private int contPessoas = 0;

    Agenda(){
        
    }

    Pessoa[] getPessoas(){
        return this.pessoas;
    }

    void setPessoas(Pessoa[] p){
        this.pessoas = p;
    }

    void cadastraPessoa(Pessoa p){
        if(contPessoas < TAM_PESSOAS){
            this.pessoas[contPessoas] = p;
            contPessoas ++;
        } else {
            System.out.println("Limite atingido! Já foram cadastrados " + TAM_PESSOAS + " pessoas.");
        }
    }

    void listaTodas(){
        if(contPessoas == 0){
            System.out.println("Não há pessoas cadastradas na agenda.");
        } else{
            for(int i = 0; i < contPessoas; i++){
                System.out.println("\n Pessoa " + (i+1) + ":");
                this.pessoas[i].imprime();
            }
        }
    }

    Pessoa buscaPessoa(String nome){
        Pessoa p = null;
        for(int i = 0; i < contPessoas; i++){
            if(this.pessoas[i].getNome().equals(nome)){
                p = pessoas[i];
            } 
        }
        return p;
    }
}
