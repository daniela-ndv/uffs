/* Exercício de cadastro de agenda utilizando construtores, getters e setters*/

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        Agenda agenda = new Agenda(); 

        Data d1 = new Data(6, 7, 2004);
        Data d2 = new Data(10, 10, 2010); 
        Data d3 = new Data(); 
        Data d4 = new Data(2, 4, 2004); 
        Data d5 = new Data(); 
        d1.imprime();
        d2.imprime();
        d3.imprime();
        d4.imprime();
        d5.imprime();

        Contato c1 = new Contato(true, false, "12900000000");
        Contato c2 = new Contato(true, false, "109123456789"); 
        Contato c3 = new Contato(false, true, "49999999999"); 
        Contato c4 = new Contato(false, false, "0000000000"); 
        Contato c5 = new Contato(true, true, "23111111111"); 
        Contato c6 = new Contato(true, false, "1122222222"); 
        Contato c7 = new Contato(true, true, "11911111111"); 

        Pessoa p1 = new Pessoa("Fulano de Tal", d1); 
        Pessoa p2 = new Pessoa("Beltrano", d2); 
        Pessoa p3 = new Pessoa("Fulana", d3);
        Pessoa p4 = new Pessoa("Ciclano da Silva", d4); 
        Pessoa p5 = new Pessoa("Pessoa", d5); 

        p1.cadastraContato(c1);
        p1.cadastraContato(c2);
        p2.cadastraContato(c3);
        p3.cadastraContato(c4);
        p3.cadastraContato(c5);
        p4.cadastraContato(c6);
        p5.cadastraContato(c7);

        agenda.cadastraPessoa(p1);
        agenda.cadastraPessoa(p2);
        agenda.cadastraPessoa(p3);
        agenda.cadastraPessoa(p4);
        agenda.cadastraPessoa(p5);

        System.out.println("\nNome: " + p5.getNome());
        System.out.println("Dia: " + p5.getData().getDia() + "/" + p5.getData().getMes() + "/" + p5.getData().getAno() + "\n");
        
        System.out.println("##### Pessoas cadastradas na agenda #####");
        System.out.println("\n*****************************************");
        agenda.listaTodas();
        System.out.println("\n*****************************************");
        
        System.out.println("\n##### Buscar pessoa #####");
        while(true){
            System.out.println("Digite o nome que deseja buscar ou digite 0 para encerrar: ");
            String nome = scanner.nextLine();

            if(nome.equals("0")){
                System.out.println("Encerrando ...");
                break;
            }

            Pessoa pessoa = agenda.buscaPessoa(nome);

            if(pessoa == null){
                System.out.println("\n=> Pessoa não encontrada na agenda!\n");
            } else {
                System.out.println("\n=> Pessoa encontrada!");
                pessoa.imprime();
                System.out.print("\n");
            }
        }


        scanner.close();        
    }
}
