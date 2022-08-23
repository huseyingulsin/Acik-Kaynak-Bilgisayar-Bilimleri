/*
@Author : Muhammed Oguz
@Date : 18.01.2021

This class represents a super class for ArrayList and LinkedList.
*/

package muhammedogz_interface;


public interface List<E> extends Collection<E>{
    
    // List methods have access to items with get.
    E get(int index);
}
