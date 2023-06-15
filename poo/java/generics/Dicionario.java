public class Dicionario<K, V> {

    K keys[];
    V values[];
    int next = 0;

    /**
     * Constructor. Suppress unchecked warnings.
     */
    @SuppressWarnings("unchecked")
    public Dicionario()
    {
        keys = (K[]) new Object[100];
        values = (V[]) new Object[100];
    }

    /**
     * Add element of type <V> with key of type <K> to the dictionary.
     * @param key Key to refer to the value.
     * @param value Value to add.
     */
    public void add(K key, V value)
    {
        keys[next] = key;
        values[next++] = value;
    }

    /**
     * Returns the value of the element of key passed as argument.
     * @param key Key associated to the elements value.
     * @return V of 
     */
    public V get(K key) throws Exception
    {
        int index = 0;
        for (K key_curr : keys)
        {
            if (key.equals(key_curr)) return values[index];
            index ++;
            
        }

        throw new Exception("Key not found on dictionary");

    }

    /**
     * Method that checks wether the dict contains an element by its key.
     * @param key Key to be searched.
     * @return True or false, depending on the element existence.
     */
    boolean contains(K key)
    {
        for (K cur_key : keys) if(key.equals(cur_key)) return true;
        return false;
    }

    /**
     * Method that checks wether the dictionary contains an element by its value.
     * @param value Value to be searched.
     * @return True or false, depending on the element existence.
     */
    boolean containsValue(V value)
    {
        for (V cur_value : values) if(value.equals(cur_value)) return true;
        return false;
    }

}
