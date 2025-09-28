public class Pessoa {
    final int TAM_CONTATOS = 4;
    int contContatos = 0;

    String nome;
    Data data;
    Contato[] contatos = new Contato[TAM_CONTATOS];
    
    Pessoa(String nome, Data data){
        this.nome = nome;
        this.data = data;
    }

    void cadastraContato(Contato c){
        if(contContatos < TAM_CONTATOS){
            contatos[contContatos] = c;      
            contContatos++;
        } else {
            System.out.println("Limite atingido! Já foram cadastrados " + TAM_CONTATOS + " contatos.");
        }
    }

    void listaContatos(){
        if(contContatos == 0){
            System.out.println("\tNão há contatos cadastrados");
        } else {
            for(int i = 0; i < contContatos; i++){
                System.out.println("\tContato " + (1+i) + ":");
                this.contatos[i].imprime(); 
            }
        }
    }

    void imprime(){
        System.out.println("\tNome: " + this.nome);
        System.out.print("\tData: ");
        this.data.imprime();
        this.listaContatos();
    }
}

