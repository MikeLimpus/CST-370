/*
 * Title: hw5_1.java
 * Abstract: Program to conduct heap operations
 * ID: 9753
 * Name: Mike Limpus
 * Date: 04/13/2022
 */
import java.util.*;
public class Main {
    public static void main(String args[]) throws Exception {
        Scanner in = new Scanner(System.in);
        Vector<Integer> input = new Vector<Integer>();
        Queue<String> commands = new LinkedList<String>();
        int sentinel = Integer.MAX_VALUE;
        int n = in.nextInt();
        input.add(sentinel);
        for (int i = 0; i < n; ++i) {
            input.add(in.nextInt());
        }
        int c = in.nextInt();
        for (int i = 0; i < c + 1; ++i) {
            commands.add(in.nextLine());
        }
        commands.poll(); // Workaround for weird bug
        //System.out.println();
        Boolean isHeap = heapify(input);
        if(isHeap)
            System.out.println("This is a heap.");
        else 
            System.out.println("This is NOT a heap.");
        parseCommands(commands, input);
        in.close();
    }
    // Adapted from textbook algorithm HeapBottomUp
    public static Boolean heapify(Vector<Integer> input) {
        int n = input.size()-1;
        Boolean heap = false;
        for (int i = (int) Math.floor(n/2); i >= 1; --i) {
            int k = i; 
            int v = input.get(k);
            heap = false;
            while (!heap && 2*k <= n) {
                int j = 2 * k;
                if (j < n) {
                    if (input.get(j) < input.get(j + 1))
                        j++;
                }
                if (v >= input.get(j))
                    heap = true;
                else {
                    input.set(k, input.get(j));
                    k = j;
                }
            }
            input.set(k, v);
        }
        return heap;
    }

    public static void parseCommands(Queue<String> commands,
        Vector<Integer> heap) throws Exception {
        while(!commands.isEmpty()) {
            String command = commands.poll();
            if (command.equals("displayMax"))
                displayMax(heap);
            else if (command.equals("deleteMax"))
                deleteMax(heap);
            else if (command.equals("display"))
                display(heap);
            else if (command.contains("insert")) {
                String parsed = command.substring(7);
                int value = Integer.parseInt(parsed);
                insert(heap, value);
            }
            else
                throw new Exception("Invalid Command \"" + command + "\"");
        }
    }

    public static void displayMax(Vector<Integer> heap) {
        System.out.println(heap.get(1));
    }

    public static void deleteMax(Vector<Integer> heap) {
        swap(heap, 1, heap.size()-1);
        heap.remove(heap.size()-1);
        heapify(heap);
    }

    public static void display(Vector<Integer> heap) {
        for(int i = 1; i < heap.size(); ++i) {
            System.out.print(heap.get(i));
            if (i != heap.size() - 1) {
                System.out.print(" ");
            }
            else {
                System.out.println();
            }
        }
    }

    public static void insert(Vector<Integer> heap, int value) {
        heap.add(value);
        heapify(heap);
    }

    public static void swap(Vector<Integer> heap, int i, int j) {
        int temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }
}