import java.io.FileNotFoundException;
import java.io.IOError;
import java.io.IOException;

public class Main {
    public static void main(String args[]) throws FileNotFoundException, IOException, ClassNotFoundException
    {
        ContaPalavra contaPalavra = new ContaPalavra("arquivo.txt");

        contaPalavra.criaMapa();
        
    }
}
