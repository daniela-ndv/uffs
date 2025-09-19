public class Contato {
    boolean ehTelegram;
    boolean ehWhatsapp;
    String numero;

    void imprimeContato(){
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
