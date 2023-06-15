import java.util.Vector;

/**
 * MyVector
 */
public class MyVector<E> extends Vector<E> {

    @Override
    public boolean add (E element)
    {
        if (element instanceof Integer)
        {
            int k = (Integer) element;
            if (k > 100) return false;
        }
        return super.add(element);
    }
}