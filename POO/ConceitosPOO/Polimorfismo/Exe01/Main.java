package Exe01;

public class Main {
    public static void main(String[] args) {
        A a = new A();
        B b = new B();
        C c = new C();
        A a2 = new C();

        System.out.println("Saída 1:");
        b.m1(); // m1 de B,
        c.m2(); // m2 de A, 
        a.m3(); // m3 de A,

        System.out.println("\nSaída 2:");
        c.m1(); // m1 de B,
        c.m2(); // m2 de A,
        c.m3(); // m3 de C, ” + (i + 6)

        System.out.println("\nSaída 3:");
        a.m1(); // m1 de A,
        b.m2(); // m2 de A,
        c.m3(); // m3 de C, ” + (i + 6) 

        System.out.println("\nSaída 4:");
        a2.m1(); // m1 de B, 
        a2.m2(); // m2 de A, 
        a2.m3(); // m3 de C, ” + (i + 6))
    }
}
