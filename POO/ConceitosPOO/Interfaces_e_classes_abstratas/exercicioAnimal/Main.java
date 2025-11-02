public class Main {
    public static void main(String[] args) {
        Cachorro c = new Cachorro();
        Gato g = new Gato();
        Onca o = new Onca();
        Lobo l = new Lobo();
        Hipopotamo h = new Hipopotamo();

        c.emiteSom();
        c.movimentaEmMatilha();
        c.brinca();
        c.rola();

        g.emiteSom();
        g.movimentaSolo();
        g.brinca();
        g.rola();

        o.emiteSom();
        o.movimentaSolo();
        o.nada();

        l.emiteSom();
        l.movimentaEmMatilha();

        h.emiteSom();
        h.movimenta();
    }
}
