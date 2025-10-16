package introdução;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Jogador jogador = new Jogador();

        System.out.print("Nome: ");
        jogador.nome = scanner.nextLine();
        System.out.print("Posição \n[1] defesa \n[2] meio-campo \n[3] atacante \n=> ");
        jogador.posicao = scanner.nextInt();
        System.out.print("Dia: ");
        jogador.dia = scanner.nextInt();
        System.out.print("Mês: ");
        jogador.mes = scanner.nextInt();
        System.out.print("Ano: ");
        jogador.ano = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Nacionalidade: ");
        jogador.nacionalidade = scanner.nextLine();
        System.out.print("Altura: ");
        jogador.altura = scanner.nextDouble();
        System.out.print("Peso: ");
        jogador.peso = scanner.nextDouble();
        
        int tempo = jogador.calcularTempoParaAposentar();

        if(tempo == -1){
            System.out.println("\nO jogador " + jogador.nome + " tem " + jogador.calcularIdade() + " anos e já pode se aposentar.");
        } else{
            System.out.println("\nO jogador " + jogador.nome + " tem " + jogador.calcularIdade() + " anos e ainda falta(m) " + tempo + " para o jogador se aposentar.");
        }

        scanner.close();
    }
}
