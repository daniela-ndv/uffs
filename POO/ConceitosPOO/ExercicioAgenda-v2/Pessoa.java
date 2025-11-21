public class Pessoa {
    private final int TAM_CONTATOS = 4;
    private int contContatos = 0;

    private String nome;
    private Data data;
    private Contato[] contatos = new Contato[TAM_CONTATOS];
    
    Pessoa(String nome, Data data){
        this.nome = nome;
        this.data = data;
    }

    String getNome(){
        return this.nome;
    }

    void setNome(String n){
        this.nome = n;
    }

    Data getData(){
        return this.data;
    }

    void setData(Data d){
        this.data = d;
    }

    Contato[] getContatos(){
        return this.contatos;
    }

    void setContatos(Contato[] c){
        this.contatos = c;
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

