public class TestFile {
    public static void main(String args[]) throws Exception
    {
        Dicionario<Integer, String> dict = new Dicionario<Integer, String>();
        
        dict.add(0, "Jose");
        dict.add(10, "ola");

        System.out.println(dict.get(0));
        System.out.println(dict.contains(0));
        System.out.println(dict.containsValue("ola"));

        System.out.println(dict.contains(12));

        // Tenta executar, lança exception (chave nao existe)
        try{
            System.out.println(dict.get(100));
        } catch (Exception err) {
            System.out.println("Error getting the value: " + err);
        }
    }
    
}
