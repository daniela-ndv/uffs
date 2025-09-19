public class Pessoa {
    final int TAM_CONTATOS = 4;
    String nome;
    Data data;
    Contato[] contatos = new Contato[TAM_CONTATOS];
    int contContatos = 0;

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
                this.contatos[i].imprimeContato(); 
            }
        }
    }

    void imprimePessoa(){
        System.out.println("\tNome: " + this.nome);
        System.out.print("\tData: ");
        this.data.imprimeData();
        this.listaContatos();
    }
}

