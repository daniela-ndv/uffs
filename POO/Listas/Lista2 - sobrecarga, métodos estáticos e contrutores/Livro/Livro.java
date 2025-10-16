
public class Livro {
    String titulo;
    String autor;
    int anoPublicacao;

    Livro(){
        this.titulo = "Sem título";
        this.autor = "Desconhecido";
        this. anoPublicacao = 0;
    }

    Livro(String titulo, String autor, int anoPublicacao){
        this.titulo = titulo;
        this.autor = autor; 
        this.anoPublicacao = anoPublicacao;
    }
}
