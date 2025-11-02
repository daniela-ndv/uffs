/**
 * Na aplicação, devemos representar funcionários e estudantes. Todos devem ter um nome 
 * cadastrado. Deve ser possível obter uma descrição dos participantes, que deve conter 
 * o seu curso de graduação ou o cargo em que ocupa na empresa.
 */

public class Main {
    public static void main(String[] args) {
        Estudante e = new Estudante("Fulano de Tal");
        Funcionario f = new Funcionario("Ciclano da Silva");

        e.imprimeNome();
        e.imprimeOcupacao();

        f.imprimeNome();
        f.imprimeOcupacao();
    }
}