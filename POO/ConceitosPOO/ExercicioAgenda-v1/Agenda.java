public class Agenda {
    final int TAM_PESSOAS = 15;
    Pessoa[] pessoas = new Pessoa[TAM_PESSOAS];
    int contPessoas = 0;

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
            if(this.pessoas[i].nome.equals(nome)){
                p = pessoas[i];
            } 
        }
        return p;
    }
}
