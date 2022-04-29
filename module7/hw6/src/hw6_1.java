/*
 * Title: hw6_1.java
 * Abstract: Program to conduct heap operations
 * ID: 9753
 * Name: Mike Limpus
 * Date: 04/19/2022
 */
import java.util.*;
public class hw6_1 {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), 
            m = in.nextInt();
        int board[][] = new int[n][m];
        // Populate the board
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                board[i][j] = in.nextInt();
            }
        }
        int result[][] = coinCollection(board, n, m);
        String path = backtrack(result);
        int coins = result[n-1][m-1];
        System.out.println("Max coins:" + coins);
        System.out.println("Path:" + path);
        in.close(); 
    }

    public static int[][] coinCollection(int board[][], int n, int m) {
        int result[][] = new int[n][m];
        result[0][0] = board[0][0];
        int foo;
        for(int j = 1; j < m; j++) {
            result[0][j] = result[0][j-1] + board[0][j]; 
        }
        for(int i = 1; i < n; i++) {
            result[i][0] = result[i-1][0] + board[i][0];
            for(int j = 1; j < m; j++) {
                // For whatver reason, java Math.max was not working
                if (result[i-1][j] > result[i][j-1])
                    foo = result[i-1][j];
                else 
                    foo = result[i][j-1];
                result[i][j] = foo + board[i][j];
            }
        }
        return result;
    }

    public static String backtrack(int result[][]) {
        String path = "";
        int n = result.length, m = result[0].length;
        path += "(" + (n) + "," + (m) + ")->";
        while (true) {
           if (n >= 2 && m >= 2) {
                if(result[n-1][m-2] == result[n-2][m-1] ||
                    result[n-1][m-2] > result[n-2][m-1]) { // Both equal, left path
                    m--;
                    path = "(" + (n) + "," + (m) + ")->" + path;
                }
                else if (result[n-1][m-2] < result[n-2][m-1]) { // top path
                    n--; 
                    path = "(" + (n) + "," + (m) + ")->" + path;
                }
            }
            else {
                if (n == 1 && m != 1) {
                    m--;
                    path = "(" + (n) + "," + (m) + ")->" + path;
                }
                else if (m == 1 && n != 1) {
                    n--; 
                    path = "(" + (n) + "," + (m) + ")->" + path;
                } 
                else if(n == 1 && m == 1) {
                    break;
                }
            }
        }
        
        path = path.substring(0, path.length()-2);
        return path;
    }
}