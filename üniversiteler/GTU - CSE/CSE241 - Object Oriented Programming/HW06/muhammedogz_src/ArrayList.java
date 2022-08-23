/*
@Author : Muhammed Oguz
@Date : 20.01.2021

This class is a implementation class of List to prevent as ArrayList
*/


package muhammedogz_src;

import muhammedogz_interface.Collection;
import muhammedogz_interface.List;
import muhammedogz_interface.Iterator;


public class ArrayList<E> implements List<E>{

    private E[] arrayList;
    private int currentSize;

    public ArrayList()
    {
        currentSize = 0;
    }

    @Override
    public Iterator<E> iterator()
    {
        return new Itr<E>(arrayList, (ArrayList<E>)this);
    }

    @Override
    @SuppressWarnings("unchecked") // for unchecked type warning. 
    public boolean add(E e)
    {

        E[] foo = (E[]) new Object[++currentSize];
        for (int i = 0; i < currentSize - 1; i++)
            foo[i] = arrayList[i];

        foo[currentSize - 1] = e;
        arrayList = (E[]) new Object[currentSize];
        for (int i = 0; i < currentSize; i++)
            arrayList[i] = foo[i];

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
            arrayList = null;
            currentSize = 0;
        }
        else
        {
            System.err.println("This list clear already.");
            return;
        }
        
    }

    @Override
    public boolean contains(E e)
    {
        for (int i = 0; i < currentSize; i++)
        {
            if (arrayList[i] == e)
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
            System.err.println("This list has no elements. Could not remove anything.");
            return false;
        }
        else
        {
            // first, find the index. Which element will be removed.                 
            int i;
            for (i = 0; i < currentSize; i++)
            {
                if (arrayList[i] == e)
                    break;    
            }

            // quick remove algorithm.
            for (int j = i+1; j < currentSize; j++)
                arrayList[j - 1] = arrayList[j];
            arrayList[--currentSize] = null;

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
            if(!c.contains(arrayList[i]))
                remove(arrayList[i]);
        }

        return false;
    }

    @Override
    public int size()
    {
        return this.currentSize;
    }
    
    @Override
    public E get(int index) {
        if (index >= 0 && index < currentSize)
            return arrayList[index];
        else
        {
            System.err.println("Invalid index");
            return null;
        }        
    }

    @Override
    public String toString()
    {
        String r = new String();
        r += "List: ";
        for (int i = 0; i < currentSize; i++)
        {
            r += arrayList[i];
            r += " ";
        }
        if (r.length() == 6)
            r = "List is empty.";
        return r;
    }
}
