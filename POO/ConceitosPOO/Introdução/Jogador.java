package introdução;
/*
* Crie uma classe para representar um jogador de futebol, com os atributos nome, posição, data de nascimento, nacionalidade, altura e peso. 
* Crie um método para calcular a idade do jogador e outro método para mostrar quanto tempo falta para o jogador se aposentar. 
* Para isso, considere que os jogadores da posição de defesa (1) se aposentam em média aos 40 anos, os jogadores de meio-campo (2) aos 38 e os atacantes (3) aos 35. 
* Seu programa principal deve ser capaz de cadastrar um jogador lendo as informações do teclado.
*/

public class Jogador {
    final int ANO_ATUAL = 2025;
    final int MEDIA_IDADE_DEFESA = 40;
    final int MEDIA_IDADE_MEIO = 38;
    final int MEDIA_IDADE_ATACANTE = 35;

    String nome;
    int posicao;
    int dia, mes, ano;
    String nacionalidade;
    double altura;
    double peso;

    int calcularIdade(){
        return (ANO_ATUAL - this.ano);
    }

    int calcularTempoParaAposentar(){
        int tempo = 0;
        switch (this.posicao) {
            case 1:
                if(calcularIdade() < MEDIA_IDADE_DEFESA){
                    tempo = MEDIA_IDADE_DEFESA - calcularIdade();
                } else{
                    tempo = 0;
                }
            case 2:
                if(calcularIdade() < MEDIA_IDADE_MEIO){
                    tempo = MEDIA_IDADE_MEIO - calcularIdade();
                } else{
                    tempo = 0;
                }
            case 3:
                if(calcularIdade() < MEDIA_IDADE_ATACANTE){
                    tempo = MEDIA_IDADE_ATACANTE - calcularIdade();
                } else{
                    tempo = 0;
                }
            default:
                break;
        }

        return tempo;
    }

}
