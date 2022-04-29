/*
 * Title: hw5_1.java
 * Abstract: Program to conduct linear probing
 * ID: 9753
 * Name: Mike Limpus
 * Date: 04/13/2022
 */
import java.util.*;
public class Main {
    public static void main(String args[]) throws Exception {
        Scanner in = new Scanner(System.in);
        Queue<String> commands = new LinkedList<String>();
        int n = in.nextInt();
        HashTable ht = new HashTable(n);
        int commandCount = in.nextInt();
        for (int i = 0; i < commandCount + 1; ++i) {
            commands.add(in.nextLine());
        }
        commands.poll();
        parseCommands(commands, ht);
    }

    public static void parseCommands(Queue<String> commands,
        HashTable ht) throws Exception {
        while(!commands.isEmpty()) {
            String command = commands.poll();
            if (command.contains("displayStatus")) {
                String parsed = command.substring(14);
                int value = Integer.parseInt(parsed);
                int num = ht.displayStatus(value);
                if (num != -1) {
                    System.out.println(num);
                }
                else {
                    System.out.println("Empty");
                }
            }
            else if (command.contains("tableSize"))
                System.out.println(ht.getSize());
            else if (command.contains("search")) {
                String parsed = command.substring(7);
                int value = Integer.parseInt(parsed);
                int num = ht.search(value);
                
                if (num != -1) {
                    System.out.println(value + " Found");
                }
                else {
                    System.out.println(value + " Not found");
                }
            }
            else if (command.contains("insert")) {
                String parsed = command.substring(7);
                int value = Integer.parseInt(parsed);
                ht.insert(value);
            }
            else
                throw new Exception("Invalid Command \"" + command + "\"");
        }
    }
}

class HashTable {
    Vector<Integer> table;
    int load = 0;
    /**
     * Create a HashTable and initialize it to be full of value -1
     * need to insert, delete, search, resize, calculate load factor
     * @param size
     * @throws Exception
     */
    HashTable(int size) throws Exception {
        if(isPrime(size)) {
            table = new Vector<Integer>();
        }
        else 
            throw new Exception("Initial size must be prime");
        for(int i = 0; i < size; ++i) {
            table.add(-1);
        }
    }

    public void insert(int value) {
        load++;
        // then check load factor
        double loadF = (double) load / (double) table.size();
        if (loadF >= 0.5) {
            resize();
        }
        if (table.get(hash(value)) == -1) 
            table.set(hash(value), value);
        // else do linear probing
        else {
            int i = hash(value) + 1;
            while(true) {
                if (table.get(i) == -1) {
                    table.set(i, value);
                    break;
                }
                else 
                    ++i;
            }
        }
    }

    public void delete(int value) {
        table.set(hash(value), -1);
    }

    public int search(int value) {
        if (table.get(hash(value)) == value)
            return table.get(hash(value));
        else {
            for (int i = hash(value); i < table.size(); ++i){
                if (table.get(i) == value) {
                    return table.get(i);
                }
            }
        }
        return -1;
    }

    public int displayStatus(int index) {
        return table.get(index);
    }

    public int getSize() {
        return table.size();
    }

    /**
     * The table should become the nearest prime after the current size * 2
     */
    private void resize() {
        int newSize = nextPrime(table.size() * 2);
/*         for(int i = table.size(); i <= newSize; ++i) {
            table.add(-1);
        } */
        Vector<Integer> newTable = new Vector<Integer>();
        for(int i = 0; i < newSize; ++i) {
            newTable.add(-1);
        }
        for(int i = 0; i < table.size(); ++i) {
            if (table.get(i) != -1)
                newTable.set(table.get(i) % newTable.size(), table.get(i));
        } 
        table.clear();
        table = new Vector<Integer>(newTable);
    }

    // https://www.geeksforgeeks.org/java-program-to-check-if-a-number-is-prime-or-not/
    private boolean isPrime(int n) {
        // Corner case
        if (n <= 1)
            return false;
    
        // Check from 2 to n-1
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
    
        return true;
    }

    // https://www.tutorialspoint.com/java-program-to-check-for-prime-and-find-next-prime-in-java
    private int nextPrime(int num) {
        num++; 
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                num++;
                i = 2;
            }
        }
        return num;
    }

    private int hash(int num) {
        return num % table.size();
    }


}
