public class Gerente extends Funcionario{
    public double bonus;

    @Override
    public double calcRem(){
        return super.calcRem() + this.bonus;
    }
}