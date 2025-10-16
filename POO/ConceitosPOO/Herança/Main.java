public class Main{
    public static void main(String[] args){
        Gerente g = new Gerente();

        g.setSalario(1500);
        g.bonus = 500;

        System.out.println("Total: " + g.calcRem());
    }
}