import java.util.List;
import java.util.ArrayList;

public class CentroCultural {
    private List<Evento> eventos = new ArrayList<>();
    // private Evento[] eventos;

    public CentroCultural(List<Evento> eventos){
        this.eventos = eventos;
    }

    public void cadastrarEvento(Evento evento){
        this.eventos.add(evento);
        //this.eventos[0] = evento;
    }

    public void listarEventos(){
    
        for(int i = 0; i < eventos.size(); i++){
            Evento e = eventos.get(i);

            if(e instanceof PecaTeatral){
                System.out.println("**************** Peça teatral ****************");
                System.out.println("=> Preço: R$ " + e.calculaPreco());
            }

            if(e instanceof Show){
                System.out.println("**************** Show ****************");
                System.out.println("=> Preço: R$ " + e.calculaPreco());
            }

            System.out.println("=> Nome: " + e.getNome());
            System.out.println("=> Vagas disponíveis: " + e.getQtdVagas());

            System.out.print("\n");
        }

        /*for(int i = 0; i < eventos.length; i++){
            System.out.println("Evento " + (i + 1) + ": ");
            System.out.println("Nome: " + eventos[i].getNome());
            System.out.println("Vagas disponíveis: " + eventos[i].getQtdVagas());
        }*/

    }

    public boolean comprarIngresso(Evento evento, int quantidade){
        if(evento.getQtdVagas() < quantidade){ 
            System.out.println("Não há vagas disponíveis no evento.");
            return false; 
        }

        int quantidadeAposVenda = evento.getQtdVagas() - quantidade;
        evento.setQtdVagas(quantidadeAposVenda);
        return true;
    }
}
