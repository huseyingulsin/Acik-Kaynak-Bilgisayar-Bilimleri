/*
@Author : Muhammed Oguz
@Date : 20.01.2021

This class is a implementation class of List and Queue to prevent as LinkedList
*/


package muhammedogz_src;

import muhammedogz_interface.Collection;
import muhammedogz_interface.List;
import muhammedogz_interface.Queue;
import muhammedogz_interface.Iterator;


public class LinkedList<E> implements List<E>, Queue<E>{

    private E[] linkedList;
    private int currentSize;

    public LinkedList()
    {
        currentSize = 0;
    }

    @Override
    public Iterator<E> iterator()
    {
        return new Itr<E>(linkedList, (LinkedList<E>)this);
    }

    @Override
    @SuppressWarnings("unchecked") // for unchecked type warning. 
    public boolean add(E e)
    {

        E[] foo = (E[]) new Object[++currentSize];
        for (int i = 0; i < currentSize - 1; i++)
            foo[i] = linkedList[i];

        foo[currentSize - 1] = e;
        linkedList = (E[]) new Object[currentSize];
        for (int i = 0; i < currentSize; i++)
            linkedList[i] = foo[i];

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
            linkedList = null;
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
            if (linkedList[i] == e)
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
                if (linkedList[i] == e)
                    break;    
            }

            // quick remove algorithm.
            for (int j = i+1; j < currentSize; j++)
                linkedList[j - 1] = linkedList[j];
            linkedList[--currentSize] = null;

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
            if(!c.contains(linkedList[i]))
                remove(linkedList[i]);
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
            return linkedList[index];
        else
        {
            System.err.println("Invalid index");
            return null;
        }        
    }

    @Override
    public E element() 
    {
        if (currentSize > 0)
            return linkedList[0];
        else
        {
            System.err.println("List is empty.");
            return null;
        }
    }

    @Override
    public boolean offer(E e) 
    {
        return add(e);
    }

    @Override
    public E poll() 
    {
        if (currentSize > 0)
        {
            E temp = linkedList[0];
            remove(linkedList[0]);
            return temp;
        }
        else
        {
            System.err.println("List is empty.");
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
            r += linkedList[i];
            r += " ";
        }
        if (r.length() == 6)
            r = "List is empty.";
        return r;
    }
}
