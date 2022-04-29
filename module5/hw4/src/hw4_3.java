/*
 * Title: hw4_3.java
 * Abstract: Implement Kahn Algorithm for topological sorting 
 * ID: 9753
 * Name: Mike Limpus
 * Date: 04/05/2022
 */
import java.util.*;
public class hw4_3 {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int vertices, edges;
        vertices = in.nextInt();
        edges = in.nextInt();
        ArrayList<ArrayList<Integer> > input = new ArrayList<ArrayList<Integer> >();

        for (int i = 0; i < edges; ++i) {
            int foo, bar; 
            foo = in.nextInt();
            bar = in.nextInt();
            input.add(new ArrayList<>());
            input.get(i).add(foo);
            input.get(i).add(bar);
        }

        kahn(input, vertices, edges);
    }

    static void kahn(ArrayList<ArrayList<Integer> > input, int vertices, int edges) {
        int visited = 0;
        Queue<Integer> zeroIn = new LinkedList<Integer>();
        ArrayList<Integer> inDegree = new ArrayList<Integer>();
        ArrayList<Integer> results = new ArrayList<Integer>();
        calcInDegree(inDegree, input, vertices, edges);
        for (int i = 0; i < vertices; i++) {
            if(inDegree.get(i) == 0) {
                zeroIn.add(i);
            }
        }
        while(zeroIn.size() > 0) {
            int popped = zeroIn.poll();
            results.add(popped);
            for (int n : input.get(popped)) {
                if(inDegree.get(n) - 1 == 0) {
                    zeroIn.add(n);
                }
            }
            visited++;
        }

        // Handle output
        for (int i = 0; i < vertices; ++i) 
            System.out.println("In-degree[" + i + "]:" + inDegree.get(i));
        if (visited != vertices) {
            System.out.println("No Order:");
            return;
        }
        System.out.print("Order:");
        for (int i = 0; i < results.size(); ++i) {
            System.out.print(results.get(i));
            if (i != results.size() - 1) {
                System.out.print("->");
            }
            else {
                System.out.println();
            }
        }
        
    }

    static void calcInDegree(ArrayList<Integer> inDegree,  
        ArrayList<ArrayList<Integer> > input, int vertices, int edges) {
        for (int i = 0; i < vertices; ++i) {
            inDegree.add(0);
        }
        for (int i = 0; i < edges; ++i) {
            Integer foo = input.get(i).get(1);
            inDegree.set(foo, inDegree.get(foo)+1);
        }
    }
}