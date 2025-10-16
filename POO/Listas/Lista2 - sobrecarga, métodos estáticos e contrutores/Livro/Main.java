/** Implemente uma classe Livro que contenha os atributos titulo (String), autor (String) e anoPublicacao (int). Crie os seguintes construtores para esta classe:
* Um construtor padrão que inicializa o livro com valores genéricos (por exemplo, “Sem título”, “Desconhecido”, 0).
* Um construtor que receba valores para os três atributos como parâmetros.
Instancie dois objetos da classe Livro: um utilizando o construtor padrão e outro utilizando o construtor com parâmetros. Imprima os dados dos dois livros.
 */

public class Main{
    public static void main(String[] args) {
        Livro livroDefault = new Livro();

        System.out.println("Livro padrão: ");
        System.out.println("\tTítulo: " + livroDefault.titulo);
        System.out.println("\tAutor: " + livroDefault.autor);
        System.out.println("\tAno: " + livroDefault.anoPublicacao);

        Livro livro = new Livro("A Hora da Estrela", "Clarice Lispector", 1977);

        System.out.println("Livro: ");
        System.out.println("\tTítulo: " + livro.titulo);
        System.out.println("\tAutor: " + livro.autor);
        System.out.println("\tAno: " + livro.anoPublicacao);
    }
}