public class Contato {
    private boolean ehTelegram;
    private boolean ehWhatsapp;
    private String numero;
    static int qtdTotalContatos;

    Contato(boolean ehTelegram, boolean ehWhatsapp, String numero){
        this.ehTelegram = ehTelegram;
        this.ehWhatsapp = ehWhatsapp;
        this.numero = numero;
        qtdTotalContatos++;
    }

    boolean getEhTelegram(){
        return this.ehTelegram;
    }

    void setEhTelegram(boolean t){
        this.ehTelegram = t;
    }

    boolean getEhWhatsapp(){
        return this.ehWhatsapp;
    }

    void setEhWhatsapp(boolean w){
        this.ehWhatsapp = w;
    }

    String getNumero(){
        return this.numero;
    }

    void setNumero(String n){
        this.numero = n;
    }

    static void imprimeQtdContatos(){
        System.out.println("Quantidade total de contatos: "+ qtdTotalContatos);
    }

    void imprime(){
        System.out.print("\t=> " + this.numero);

        if(this.ehTelegram){ 
            System.out.print(" | Telegram");
        } 
        if(this.ehWhatsapp){ 
            System.out.print(" | WhatsApp"); 
        }
        System.out.print("\n"); 
    }
}
