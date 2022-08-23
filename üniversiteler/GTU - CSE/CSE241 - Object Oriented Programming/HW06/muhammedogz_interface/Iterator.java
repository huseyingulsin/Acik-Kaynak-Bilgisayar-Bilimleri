/*
@Author : Muhammed Oguz
@Date : 18.01.2021

This class represents a super class for Collections to being iterator.
*/

package muhammedogz_interface;

public interface Iterator<E> {

    // Returns true if the iteration has more elements.
    boolean hasNext();


    // Returns the next element in the iteration.
    E next();

    // Removes from the underlying collection the last element returned
    // by this iterator. This method does not work for Queues, it throws
    // an exception
    void remove();
}
