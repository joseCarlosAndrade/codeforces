// package poo.java.ex1;

public class Random {
    private long p = 2147483648L;
    private long m = 843314861;
    private long a = 453816693;

    // semente:
    private long xi = 1023;

    public Random(int k)
    {
        xi = k;
    }

    public Random() // outro construtor para caso nao seja passado nenhum parametro, use o valor padrao
    {

    }

    public double getRand()
    {
        // fazer calculos
        xi = (a + m +xi) % p;
        double d = xi;
        return d/p;
    }

    public int getIntRand(int max)
    {
        double d = getRand() * max;
        return (int) d;
    }

    public void setSemente(int semente)
    {
        xi = semente;
    }

    public void getSemente()
    {
        System.out.println(xi);
    }

    // public void get

}


