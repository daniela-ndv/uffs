import java.time.LocalDate;

public class Data {
    int dia;
    int mes;
    int ano;

    Data(){
        this.dia = LocalDate.now().getDayOfMonth();
        this.mes = LocalDate.now().getMonthValue();
        this.ano = LocalDate.now().getYear();
    }

    Data(int dia, int mes, int ano){
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    void imprime(){
        System.out.println(this.dia + "/" + this.mes + "/" + this.ano);
    }
}
