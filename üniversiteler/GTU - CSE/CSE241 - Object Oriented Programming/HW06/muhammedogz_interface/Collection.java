/*
@Author : Muhammed Oguz
@Date : 18.01.2021

This class represents a super class for some data classes.
*/

package muhammedogz_interface;

public interface Collection<E> {  

    // Return an iterator over the collection
    Iterator<E> iterator();

    // return true if addition is successful
    // return false if, Object is already there.
    boolean add(E e); 

    // Add Specified Collection. Return true if addition is successful
    // return false otherwise
    boolean addAll(Collection<E> c);

    // // Remove all elements from Collection
    void clear(); 

    // Return true if collection contains specified element.
    boolean contains(E e);

    // Returns true if Collection contains all elements of sended collection
    boolean containsAll(Collection<E> c);

    // Return true if collection is empty (Does not have any element on it)
    boolean isEmpty();

    // Remove specified element from collection. Return true if removing is successful.
    boolean remove(E e);

    // Remove sended collection from this collection. Return true if removing successful.
    boolean removeAll(Collection<E> c);

    // Remove all elements except sended Collection. Return true if successful.
    boolean retainAll(Collection<E> c);

    // Return the number of elements in Collection.
    int size();
}