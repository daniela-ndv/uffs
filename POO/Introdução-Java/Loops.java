public class Loops {
    public static void main (String[] args){
        int cont = 0;

        System.out.println("Crescente");
        for(int i = 0; i < 5; i++){
            System.out.println(i);
            cont++;
        }

        System.out.println("\nDecrescente");
        while(cont > 0){
            cont--;
            System.out.println(cont);
        }

        System.out.println("\nDo while");
        do{
            System.out.println(cont);
            cont++;
        } while(cont < 5);
    }
}
