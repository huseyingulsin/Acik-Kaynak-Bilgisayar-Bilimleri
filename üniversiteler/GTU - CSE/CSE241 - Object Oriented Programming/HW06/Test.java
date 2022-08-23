/*
@Author : Muhammed Oguz
@Date : 20.01.2021

This class test all functions of LinkedList, ArrayList and HashSet.
*/

import java.util.Scanner;


// import all class from muhammed_src file
import muhammedogz_interface.Collection;
import muhammedogz_src.*;


public class Test {
    
    public static boolean testMenu()
    {
        Scanner input = new Scanner(System.in);
        System.out.println("MENU");
        System.out.println("1) Test HashSet<Integer>");
        System.out.println("2) Test HashSet<String>");
        System.out.println("3) Test ArrayList<Integer>");
        System.out.println("4) Test ArrayList<String>");
        System.out.println("5) Test LinkedList<Integer>");
        System.out.println("6) Test LinkedList<String>");
        System.out.println("7) Quit");
        System.out.print("Enter Command: ");
        Integer command = input.nextInt();
        System.out.println();
        if (command == 1)
        {
            HashSet<Integer> hashInt = new HashSet<>();
            testMethodsInteger(hashInt);
        }
        else if (command == 2)
        {
            HashSet<String> hashStr = new HashSet<>();
            testMethodsString(hashStr);  
        }
        if (command == 3)
        {
            ArrayList<Integer> arrayInt = new ArrayList<>();
            testMethodsInteger(arrayInt);
            System.out.print("get(0) -> "); System.out.println(arrayInt.get(0));
        }
        else if (command == 4)
        {
            ArrayList<String> arrayStr = new ArrayList<>();
            testMethodsString(arrayStr);  
            System.out.print("get(0) -> "); System.out.println(arrayStr.get(0));
        }
        if (command == 5)
        {
            LinkedList<Integer> linkedInt = new LinkedList<>();
            testMethodsInteger(linkedInt);
            System.out.print("get(2) -> "); System.out.println(linkedInt.get(2));
            System.out.print("element() -> "); System.out.println(linkedInt.element());
            System.out.println("offer(999)"); linkedInt.offer(999);
            System.out.print("poll() -> "); System.out.println(linkedInt.poll());
            System.out.println(linkedInt.toString());
        }
        else if (command == 6)
        {
            LinkedList<String> linkedStr = new LinkedList<>();
            testMethodsString(linkedStr);  
            System.out.print("get(2) -> "); System.out.println(linkedStr.get(2));
            System.out.print("element() -> "); System.out.println(linkedStr.element());
            System.out.println("offer(\"GTU <3\")"); linkedStr.offer("GTU <3");
            System.out.print("poll() -> "); System.out.println(linkedStr.poll());
            System.out.println(linkedStr.toString());
        }
        else if (command == 7)
        {
            System.out.println("Goodbye My friend <3<3<3");
            input.close();
            return false;
        }
            

        System.out.println("\n\nTest Over!!! I hope Everything went well :)\n");


        return true;
                

        
    }

    public static void testMethodsInteger(Collection<Integer> c) {
        // create a temp object, it created as a HashSet, But does not matter.
        Collection<Integer> temp =  new HashSet<>();

        temp.add(11);
        temp.add(12);

        System.out.println("Test function starting. After Some Functions, List/Set will shown\nAfter this symbol \"->\" return values will shown.\n");
        System.out.print("add(5) (returns true if successful) -> ");
        System.out.println(c.add(5));
        System.out.println(c.toString());
        System.out.print("add(5) (returns false if HashSet used) -> ");
        System.out.println(c.add(5));
        System.out.println(c.toString());
        System.out.print("add(6) (returns true if successful) -> ");
        System.out.println(c.add(6));
        System.out.println(c.toString());
        System.out.println("addAll(temp), (temp = {11,12}) ");
        c.addAll(temp);
        System.out.println(c.toString());
        System.out.print("contains(5) ->");
        System.out.println(c.contains(5));
        System.out.print("containsAll(temp) (temp = {11,12}) ->");
        System.out.println(c.containsAll(temp));
        System.out.println("remove(5) ");
        c.remove(5);
        System.out.println(c.toString());
        System.out.print("isEmpty() -> ");
        System.out.println(c.isEmpty());
        System.out.println("retainAll(temp) (temp = {11,12})");
        c.retainAll(temp);
        System.out.println(c.toString());
        System.out.println("size() -> " + c.size());
        System.out.println("clear()");
        c.clear();
        System.out.println("Call clear(); again");
        c.clear();
        System.out.println("addAll(temp), (temp = {11,12}) ");
        c.addAll(temp);
        System.out.println(c.toString());
        System.out.println("removeAll(temp)");
        c.removeAll(temp);
        System.out.println(c.toString());
        System.out.println("size() -> " + c.size());
        System.out.println("add(500) add(600) add(700) add(800) add(900) add(1000)");
        c.add(500); c.add(600); c.add(700); c.add(800); c.add(900); c.add(1000);
        System.out.println(c.toString());
        System.out.println("size() -> " + c.size());
        

    }

    public static void testMethodsString(Collection<String> c)
    {
        // create a temp object, it created as a HashSet, But does not matter.
        Collection<String> temp =  new HashSet<>();

        temp.add("Hello");
        temp.add("Temp");

        System.out.println("Test function starting. After Some Functions, List/Set will shown\nAfter this symbol \"->\" return values will shown.\n");
        System.out.print("add(\"One\") (returns true if successful) -> ");
        System.out.println(c.add("One"));
        System.out.println(c.toString());
        System.out.print("add(\"One\") (returns false if HashSet used) -> ");
        System.out.println(c.add("One"));
        System.out.println(c.toString());
        System.out.print("add(\"Two\") (returns true if successful) -> ");
        System.out.println(c.add("Two"));
        System.out.println(c.toString());
        System.out.println("addAll(temp), (temp = {\"Hello\",\"Temp\"}) ");
        c.addAll(temp);
        System.out.println(c.toString());
        System.out.print("contains(\"One\") ->");
        System.out.println(c.contains("One"));
        System.out.print("containsAll(temp) (temp = {\"Hello\",\"Temp\"}) ->");
        System.out.println(c.containsAll(temp));
        System.out.println("remove(\"One\") ");
        c.remove("One");
        System.out.println(c.toString());
        System.out.print("isEmpty() -> ");
        System.out.println(c.isEmpty());
        System.out.println("retainAll(temp) (temp = {\"Hello\",\"Temp\"})");
        c.retainAll(temp);
        System.out.println(c.toString());
        System.out.println("size() -> " + c.size());
        System.out.println("clear()");
        c.clear();
        System.out.println("Call clear(); again");
        c.clear();
        System.out.println("addAll(temp), (temp = {\"Hello\",\"Temp\"}) ");
        c.addAll(temp);
        System.out.println(c.toString());
        System.out.println("removeAll(temp)");
        c.removeAll(temp);
        System.out.println(c.toString());
        System.out.println("size() -> " + c.size());
        System.out.println("add(\"Best Teachers <3\") add(\"YSA\") add(\"Aytutuldu\") add(\"Ilhan\") add(\"Burak\") add(\"Koca\")");
        c.add("Best Teachers <3"); c.add("YSA"); c.add("Aytutuldu"); c.add("Ilhan"); c.add("Burak"); c.add("Koca");
        System.out.println(c.toString());
        System.out.println("size() -> " + c.size());

        
    }

    public static void main(String[] args) {
        System.out.println(" -->>>  Welcome to Perfect Collection Implementer Test Class!!!! <<<---");
        while(testMenu());
    }
}
