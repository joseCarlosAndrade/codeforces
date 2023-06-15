package poo.java.generics;

public class Generic <T> {
    
    T []vetor;

    /*
     * Implementação da pilha
     */
    public Generic()
    {
        // vetor = (T[]) new T[100];
        vetor = (T[]) new Object[100];
        // T[] names = new T[100];
    }
}
