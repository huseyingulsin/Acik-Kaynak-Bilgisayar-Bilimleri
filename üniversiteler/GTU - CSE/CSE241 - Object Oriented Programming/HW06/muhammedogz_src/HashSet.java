/*
@Author : Muhammed Oguz
@Date : 20.01.2021

This class is a implementation class of Set to prevent as HashSet
*/

package muhammedogz_src;

import muhammedogz_interface.Collection;
import muhammedogz_interface.Set;
import muhammedogz_interface.Iterator;

public class HashSet<E> implements Set<E>{
    
    private E[] hash;
    private int currentSize;

    public HashSet()
    {
        currentSize = 0;
    }

    @Override
    public Iterator<E> iterator()
    {
        return new Itr<E>(hash, (HashSet<E>)this);
    }

    @Override
    @SuppressWarnings("unchecked") // for unchecked type warning. 
    public boolean add(E e)
    {
        if (contains(e))
        {
            System.err.println("Duplicate item.");
            return false;
        }

        E[] foo = (E[]) new Object[++currentSize];
        for (int i = 0; i < currentSize - 1; i++)
            foo[i] = hash[i];

        foo[currentSize - 1] = e;
        hash = (E[]) new Object[currentSize];
        for (int i = 0; i < currentSize; i++)
            hash[i] = foo[i];

        return true;
    }

    @Override
    public boolean addAll(Collection<E> c)
    {
        Iterator<E> it = c.iterator();

        while(it.hasNext())
            add(it.next());

        return false;
    }

    @Override
    public void clear()
    {
        if (currentSize != 0)
        {
            hash = null;
            currentSize = 0;
        }
        else
        {
            System.err.println("This set clear already.");
            return;
        }
        
    }

    @Override
    public boolean contains(E e)
    {
        for (int i = 0; i < currentSize; i++)
        {
            if (hash[i] == e)
                return true;
        }
        return false;
    }

    @Override
    public boolean containsAll(Collection<E> c)
    {
        Iterator<E> it = c.iterator();
        while(it.hasNext())
        {
            if (contains(it.next()) == false)
                return false;
        }
        return true;
    }

    @Override
    public boolean isEmpty()
    {
        return currentSize == 0;
    }

    @Override
    public boolean remove(E e) 
    {
        // if this element is not in array. return false.
        if (!contains(e))
        {
            System.err.println("This item not in the set.");
            return false;
        }
        else if (currentSize < 0)
        {
            System.err.println("This set has no elements on it. Could not remove");
            return false;
        }
        else
        {
            // first, find the index. Which element will be removed.                 
            int i;
            for (i = 0; i < currentSize; i++)
            {
                if (hash[i] == e)
                    break;    
            }

            // quick remove algorithm.
            for (int j = i+1; j < currentSize; j++)
                hash[j - 1] = hash[j];
            hash[--currentSize] = null;

            return true;
        }
    }

    @Override
    public boolean removeAll(Collection<E> c) 
    {
        // first check, if all values inside this object.
        // If not, return false.
        if(!containsAll(c)) 
        {
            System.err.println("Some elements is not in the set.");
            return false;
        }
        Iterator<E> it = c.iterator();
        while(it.hasNext())
            remove(it.next());
        
        return true;
    }

    @Override
    public boolean retainAll(Collection<E> c) 
    {
        // first check, if all values inside this object.
        // If not, return false.
        if(!containsAll(c))
        {
            System.err.println("Some elements not in the set.");
            return false;
        } 

        for (int i = 0; i < currentSize; i++)
        {
            // if a element is not same for both collection, remove it.
            if(!c.contains(hash[i]))
                remove(hash[i]);
        }

        return false;
    }

    @Override
    public int size()
    {
        return this.currentSize;
    }

    @Override
    public String toString()
    {
        String r = new String();
        r += "Set: "; 
        for (int i = 0; i < currentSize; i++)
        {
            r += hash[i];
            r += " ";
        }
        if (r.length() == 5)
            r = "Set is empty.";
        return r;
    }
    public static void main(String[] args) {
        HashSet<Integer> a = new HashSet<>();
        a.clear();
    }
}
