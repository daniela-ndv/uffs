import java.time.LocalDate;

public class Data {
    private int dia;
    private int mes;
    private int ano;

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

    int getDia(){
        return this.dia;
    }

    void setDia(int d){
        this.dia = d;
    }

    int getMes(){
        return this.mes;
    }

    void setMes(int m){
        this.mes = m;
    }

    int getAno(){
        return this.ano;
    }

    void setAno(int a){
        this.ano = a;
    }

    void imprime(){
        System.out.println(this.dia + "/" + this.mes + "/" + this.ano);
    }
}
