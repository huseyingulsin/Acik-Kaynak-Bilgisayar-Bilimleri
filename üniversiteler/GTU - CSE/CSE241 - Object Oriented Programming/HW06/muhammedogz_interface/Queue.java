/*
@Author : Muhammed Oguz
@Date : 18.01.2021

This class represents a super class for  LinkedList.
*/

package muhammedogz_interface;


public interface Queue<E> extends Collection<E>{
    
    // Add specified element to queue. Return true if successful
    boolean add(E e);

    // Retrieves the head of queue. But does not remove
    E element();

    // Same as add Function. 
    boolean offer(E e); 

    // Retrieves and removes the head of this queue, or returns null if this queue is empty.
    E poll();
}
