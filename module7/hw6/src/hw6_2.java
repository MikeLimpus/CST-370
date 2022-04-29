/*
 * Title: hw6_2.java
 * Abstract: Program to conduct Floyd's algorithm operations
 * ID: 9753
 * Name: Mike Limpus
 * Date: 04/19/2022
 */
import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int adjMatrix[][] = new int[n][n];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int temp = in.nextInt();
                if (temp > -1)
                    adjMatrix[i][j] = temp;
                else 
                    // Floyd's alg only works with positive input, so we sent a 
                    // sentinel value instead
                    adjMatrix[i][j] = 1000000;
            }
        }
        int floydMatrix[][] = floyd(adjMatrix);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (floydMatrix[i][j] == 1000000)
                    // Account for sentinel value
                    System.out.print("-1");
                else 
                    System.out.print(floydMatrix[i][j]);
                if (j != n - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
        in.close();
    }

    public static int[][] floyd(int[][] adjMatrix) {
        int n = adjMatrix.length;
        int floydMatrix[][] = adjMatrix;
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(floydMatrix[i][j] > (floydMatrix[i][k] + floydMatrix[k][j]))
                        floydMatrix[i][j] = (floydMatrix[i][k] + floydMatrix[k][j]);
                }
            }
        }
        return floydMatrix;
    }

}
