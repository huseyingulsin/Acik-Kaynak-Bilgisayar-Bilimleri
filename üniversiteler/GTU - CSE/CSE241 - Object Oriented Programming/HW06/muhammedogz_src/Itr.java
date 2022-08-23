/*
@Author : Muhammed Oguz
@Date : 20.01.2021

This class implements of Iterator class.
*/

package muhammedogz_src;


import java.util.NoSuchElementException;

import muhammedogz_interface.Collection;
import muhammedogz_interface.Iterator;
import muhammedogz_interface.Queue;

public class Itr<E> implements Iterator<E>{
    private E[] data;
    private Collection<E> col;
    private int currentIndex = -1;
    private int currentSize;

    public Itr(E[] e, Collection<E> c)
    {
        currentIndex = 0;
        this.data = e;
        this.currentSize = c.size();
        this.col = c;
    }

    @Override
    public boolean hasNext()
    {
        return currentIndex < currentSize && data[currentIndex] != null;
    }

    @Override
    public E next()
    {
        if (hasNext())
            return data[currentIndex++];
        throw new NoSuchElementException(); 
    }

    @Override
    public void remove()
    {
        if (!(col instanceof Queue))
            if (col.size() != 0)
                col.remove(data[currentIndex]);
            else
                System.err.println("List/Set/Queue empty. Can not remove.");
        else
            throw new UnsupportedOperationException("Queue object can not remove element with iterator.");
    }
}
