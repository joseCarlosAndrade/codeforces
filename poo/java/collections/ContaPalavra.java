import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.HashMap;
import java.util.Map;

class ContaPalavra
{
    private String arquiveName;
    private FileInputStream fis;
    private ObjectInputStream ois;  
    private String texto;

    private Map<String, Integer> mapa;

    /**
     * Construtor que recebe o nome do arquivo
     * @param archive
     */    
    public ContaPalavra(String archive) throws FileNotFoundException
    {   
        arquiveName = archive;
        
        fis = new FileInputStream(arquiveName);
    }

    public void criaMapa() throws IOException, ClassNotFoundException
    {   
        mapa = new HashMap<>();

        // mapa.put(key, value); <- exemplo de inserçao 
        ois = new ObjectInputStream(fis);
        texto = (String) ois.readObject();
        ois.close();
        
        System.out.println(texto);
    }

    // public void mostraMapa()
    // {

    // }

}