/** Escreva o código pedido na Questão 6 da Prova 1 fazendo o seguinte:
 * - Na classe CentroCultural, armazene os eventos cadastros através de um vetor de objetos da classe Evento
 * - No método que lista os eventos cadastrados no centro cultural, faça o seguinte para cada evento:
 * -- Usando o operador instanceof, teste se o evento é uma peça teatral e, em caso positivo, imprima o texto “Peça teatral” 
 * seguido das informações do evento
 * -- Usando o operador instanceof, teste se o evento é um show musical e, em caso positivo, imprima o texto “Show Musical” 
 * seguido das informações do evento
 * 
 * 
 * Um centro cultural está criando um sistema para venda de ingressos de diferentes tipos de eventos. 
 * Na implementação deste sistema, será utilizada um classe Centro Cultural, que deve conter métodos para:
 * - cadastrar um evento
 * - listar os eventos cadastrados 
 * - comprar um ingresso.
 * Os tipos de evento são os seguintes: peça teatral e show musical. 
 * Cada evento tem um nome, uma quantidade de vagas disponíveis e um preço base de ingresso. 
 * Para uma peça teatral, o preço do ingresso é dado pelo preço base do ingresso acrescido de uma taxa de palco. 
 * Já para o show musical, o preço do ingresso é dado simplesmente pelo seu preço base.
 */

import java.util.List;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        
        List<Evento> eventos = new ArrayList<>();

        PecaTeatral p1 = new PecaTeatral("Central do Brasil", 100, 20.0, 5.0);
        PecaTeatral p2 = new PecaTeatral("As Bruxas de Salem", 80, 25.0, 5.0);
        Show s1 = new Show("Djavan: turnê de 50 anos", 1000, 300.00, 6);
        CentroCultural c = new CentroCultural(eventos);

        c.cadastrarEvento(p1);
        c.cadastrarEvento(p2);
        c.cadastrarEvento(s1);

        c.listarEventos();

        boolean ingressoComprado = c.comprarIngresso(s1, 10);

        if(ingressoComprado){
            System.out.println("Ingresso(s) comprado(s) com sucesso!\n");
        }

        c.listarEventos();
        
    }
}
