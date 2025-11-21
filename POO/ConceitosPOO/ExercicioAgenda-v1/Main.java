/* Implemente um sistema de Agenda de Contatos que contenha as classes Data (com dia, mês e ano), Contato (indicando se é Whatsapp ou Telegram e
* armazenando um número em string) e Pessoa (com nome, data de nascimento e até quatro contatos), incluindo métodos para cadastrar e listar
* contatos. Crie ainda a classe Agenda, capaz de armazenar até quinze pessoas, permitindo cadastrar, listar todas e buscar uma pessoa pelo nome.
* No programa principal, instancie a agenda, cadastre 15 pessoas com seus dados e contatos, liste todas as cadastradas e possibilite a pesquisa por
* nome para exibir as informações completas da pessoa encontrada. */

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        Agenda agenda = new Agenda(); 

        /*
         * Instanciando datas
         */
        Data d1 = new Data(); d1.dia = 6; d1.mes = 7; d1.ano = 2004;
        Data d2 = new Data(); d2.dia = 10; d2.mes = 10; d2.ano = 2010;
        Data d3 = new Data(); d3.dia = 15; d3.mes = 15; d3.ano = 2015;
        Data d4 = new Data(); d4.dia = 2; d4.mes = 4; d4.ano = 2004;
        Data d5 = new Data(); d5.dia = 31; d5.mes = 01; d5.ano = 1980;
        Data d6 = new Data(); d6.dia = 12; d6.mes = 5; d6.ano = 1995;
        Data d7 = new Data(); d7.dia = 23; d7.mes = 8; d7.ano = 2001;
        Data d8 = new Data(); d8.dia = 7;  d8.mes = 11; d8.ano = 1988;
        Data d9 = new Data(); d9.dia = 1;  d9.mes = 1;  d9.ano = 1970;
        Data d10 = new Data(); d10.dia = 30; d10.mes = 6; d10.ano = 2003;
        Data d11 = new Data(); d11.dia = 17; d11.mes = 3; d11.ano = 1999;
        Data d12 = new Data(); d12.dia = 25; d12.mes = 12; d12.ano = 2012;
        Data d13 = new Data(); d13.dia = 9;  d13.mes = 9;  d13.ano = 1990;
        Data d14 = new Data(); d14.dia = 14; d14.mes = 2; d14.ano = 1985;
        Data d15 = new Data(); d15.dia = 21; d15.mes = 7; d15.ano = 2007;

        /*
         * Instanciando contatos
         */
        Contato c1 = new Contato(); c1.ehTelegram = true; c1.ehWhatsapp = true; c1.numero = "12900000000";
        Contato c2 = new Contato(); c2.ehTelegram = true; c2.ehWhatsapp = false; c2.numero = "109123456789";
        Contato c3 = new Contato(); c3.ehTelegram = false; c3.ehWhatsapp = true; c3.numero = "49999999999";
        Contato c4 = new Contato(); c4.ehTelegram = false; c4.ehWhatsapp = false; c4.numero = "0000000000";
        Contato c5 = new Contato(); c5.ehTelegram = true; c5.ehWhatsapp = true; c5.numero = "23111111111";
        Contato c6 = new Contato(); c6.ehTelegram = true; c6.ehWhatsapp = false; c6.numero = "1122222222";
        Contato c7 = new Contato();  c7.ehTelegram = true;  c7.ehWhatsapp = true;  c7.numero = "11911111111";
        Contato c8 = new Contato();  c8.ehTelegram = false; c8.ehWhatsapp = true;  c8.numero = "21922222222";
        Contato c9 = new Contato();  c9.ehTelegram = true;  c9.ehWhatsapp = false; c9.numero = "31933333333";
        Contato c10 = new Contato(); c10.ehTelegram = false; c10.ehWhatsapp = true;  c10.numero = "41944444444";
        Contato c11 = new Contato(); c11.ehTelegram = true;  c11.ehWhatsapp = true;  c11.numero = "51955555555";
        Contato c12 = new Contato(); c12.ehTelegram = false; c12.ehWhatsapp = false; c12.numero = "61966666666";
        Contato c13 = new Contato(); c13.ehTelegram = true;  c13.ehWhatsapp = true;  c13.numero = "71977777777";
        Contato c14 = new Contato(); c14.ehTelegram = false; c14.ehWhatsapp = true;  c14.numero = "81988888888";
        Contato c15 = new Contato(); c15.ehTelegram = true;  c15.ehWhatsapp = false; c15.numero = "91999999999";
        Contato c16 = new Contato(); c16.ehTelegram = true;  c16.ehWhatsapp = true;  c16.numero = "10100000000";

        /*
         * Instanciando pessoas
         */
        Pessoa p1 = new Pessoa(); p1.nome = "Fulano de Tal"; p1.data = d1;
        Pessoa p2 = new Pessoa(); p2.nome = "Beltrano"; p2.data = d2;
        Pessoa p3 = new Pessoa(); p3.nome = "Fulana"; p3.data = d2;
        Pessoa p4 = new Pessoa(); p4.nome = "Ciclano da Silva"; p4.data = d2;
        Pessoa p5 = new Pessoa(); p5.nome = "Pessoa"; p5.data = d2;
        Pessoa p6 = new Pessoa();  p6.nome = "Maria Souza";        p6.data = d6;
        Pessoa p7 = new Pessoa();  p7.nome = "João Pereira";       p7.data = d7;
        Pessoa p8 = new Pessoa();  p8.nome = "Ana Clara";          p8.data = d8;
        Pessoa p9 = new Pessoa();  p9.nome = "Carlos Eduardo";     p9.data = d9;
        Pessoa p10 = new Pessoa(); p10.nome = "Mariana Oliveira";  p10.data = d10;
        Pessoa p11 = new Pessoa(); p11.nome = "Pedro Henrique";    p11.data = d11;
        Pessoa p12 = new Pessoa(); p12.nome = "Fernanda Lima";     p12.data = d12;
        Pessoa p13 = new Pessoa(); p13.nome = "Ricardo Gomes";     p13.data = d13;
        Pessoa p14 = new Pessoa(); p14.nome = "Patrícia Mendes";   p14.data = d14;
        Pessoa p15 = new Pessoa(); p15.nome = "Lucas Silva";       p15.data = d15;

        /*
         * Cadastrando contatos 
         */
        p1.cadastraContato(c1);
        p1.cadastraContato(c2);
        p2.cadastraContato(c3);
        p3.cadastraContato(c4);
        p3.cadastraContato(c5);
        p4.cadastraContato(c6);
        p6.cadastraContato(c7);
        p7.cadastraContato(c8);
        p8.cadastraContato(c9);
        p9.cadastraContato(c10);
        p10.cadastraContato(c11);
        p12.cadastraContato(c13);
        p13.cadastraContato(c14);
        p14.cadastraContato(c15);
        p15.cadastraContato(c16);

        /*
         * Cadastrando pessoas
         */
        agenda.cadastraPessoa(p1);
        agenda.cadastraPessoa(p2);
        agenda.cadastraPessoa(p3);
        agenda.cadastraPessoa(p4);
        agenda.cadastraPessoa(p5);
        agenda.cadastraPessoa(p6);
        agenda.cadastraPessoa(p7);
        agenda.cadastraPessoa(p8);
        agenda.cadastraPessoa(p9);
        agenda.cadastraPessoa(p10);
        agenda.cadastraPessoa(p11);
        agenda.cadastraPessoa(p12);
        agenda.cadastraPessoa(p13);
        agenda.cadastraPessoa(p14);
        agenda.cadastraPessoa(p15);

        
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
