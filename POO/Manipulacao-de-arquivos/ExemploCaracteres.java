import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ExemploCaracteres {
    public static void main(String[] args) throws IOException {

        // gravando arquivo
        System.out.println("Gravando...");
        FileWriter arqGravacao = new FileWriter("teste.txt");
        for(int i = 65 ; i < 91; i++){
            arqGravacao.write((char)i);
        }
        arqGravacao.close();
        System.out.println("Gravação concluída!");
        
        //lendo arquivo
        System.out.println("************************************");
        System.out.println("Lendo:");
        FileReader arqLeitura = new FileReader("teste.txt");
        int byteLido = 0;
        while(arqLeitura.ready()){
            byteLido = arqLeitura.read();
            System.out.println((char)byteLido);
        }
        arqLeitura.close();
    }
}