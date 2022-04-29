/*
 * Title: main_hw3_1.java
 * Abstract: Sort and display inputted numbers in ascending order, 
 *           and shorten consecutive numbers
 * ID: 9753
 * Name: Mike Limpus
 * Date: 03/22/2022
 */

import java.util.*;

public class Main {
    public static void main(String[] args) {
        int n; 
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        int input[] = new int[n];
        ArrayList<String> output = new ArrayList<String>();
        String tempLow, tempHigh; 

        for(int i = 0; i < n; i++) {
            input[i] = in.nextInt();
        }

        Arrays.sort(input);

/*         for(int i = 0; i < n; i++) {
            System.out.print(input[i] + " ");
        } */

        for (int i = 1; i < n; ++i) {
            int temp = input[i - 1];
            temp++;
            if(input[i] == temp) {
                System.out.print(input);
                while(true) {
                    i++;
                    int temp2 = input[i-1];
                    temp2++;
                    if(input[i] != temp2) {
                        // tempHigh = Integer.toString(input[i]);
                        //output.add((tempLow + "-" + tempHigh));
                        System.out.print("-" + input[i-1] + " ");
                        break;
                    }
                }
            }
            else {
                //output.add(Integer.toString(input[i]));
                System.out.print(input[i-1]);
            }
        }
        System.out.println(input[n-1]);

/*         for(int i = 0; i < output.size(); ++i) {
            System.out.print(output.get(i) + " ");
        }
        System.out.println(); */
        in.close();
    }
}