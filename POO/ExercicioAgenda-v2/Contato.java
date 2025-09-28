public class Contato {
    boolean ehTelegram;
    boolean ehWhatsapp;
    String numero;
    static int qtdTotalContatos;

    Contato(boolean ehTelegram, boolean ehWhatsapp, String numero){
        this.ehTelegram = ehTelegram;
        this.ehWhatsapp = ehWhatsapp;
        this.numero = numero;
        qtdTotalContatos++;
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
