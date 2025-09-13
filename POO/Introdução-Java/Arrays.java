
public class Arrays {

    public static final int TAM = 10;
    public static void main(String[] args){
        
        int[] vetor = new int[TAM];

        for(int i = 0; i < TAM; i++){
            vetor[i] = i;
        } 

        for(int i = 0; i < vetor.length; i++){
            if(i == (vetor.length - 1)){
                System.out.println(vetor[i]);
            } else {
                System.out.print(vetor[i] + ", " );
            }
        }
    }
}
