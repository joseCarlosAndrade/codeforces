import java.util.Arrays;
import java.util.Collection;
import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;


public class CollectionTest {
    public static void main(String args[])
    {
        String[] colors = {"AZUL", "VERMELHO", "AMARELO", "ROXO"};
        List <String> lista= new ArrayList<String>(); // Arraylist -> lista de arrays (strings)

        for (String color : colors)
        {
            lista.add(color);
        }

        // Printar lista:
        printList(lista);

        addColors(lista, "verde");

        printList(lista);

        String [] removeColors = {"AMARELO", "verde", "ROXO"};
        List<String> listaRemove = new ArrayList<String>();

        for (String color : removeColors)
        {
            listaRemove.add(color);
        }
        printList(listaRemove);

        removerElementos(lista, listaRemove);

        printList(lista);
    }

    /**
     * Passado por referencia, nao cria uma copia da collection.
     * @param lista
     * @param color
     */
    public static void addColors(List <String> lista, String color)
    {
        lista.add(color);
    }

    public static void printList(List<String> lista)
    {
        for (int i = 0 ; i < lista.size() ; i++)
        {
            System.out.printf("%s ", lista.get(i));
        }
        System.out.println();
    }

    /**
     * Remove os elementos da lista <String> que também estão contidos em listaRemover<String>
     * @param lista
     * @param listaRemover
     */
    public static void removerElementos(Collection<String> lista, Collection <String> listaRemover)
    {
        Iterator <String> iterator = lista.iterator(); // Cria um iterator do tipo string

        while(iterator.hasNext()) // Enquanto ainda houver elementos no iterator. Retorna true se iterator.next() retornar de fato um elemento e nao uma excessao
        {
            if (listaRemover.contains(iterator.next())) // Verifica se o elemento do iterator esta contido em listaRemover
            {
                iterator.remove(); // Caso sim, remove-o
            }
        }
    }
}
