/*
 * Title: hw5_1.java
 * Abstract: Display performance of two sorting algorithms
 * ID: 9753
 * Name: Mike Limpus
 * Date: 04/13/2022
 * Mergesort implemented from https://www.javatpoint.com/merge-sort
 * Quicksort implemented from https://www.javatpoint.com/quick-sort
 */
import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter input size: ");
        System.out.println();
        int n = in.nextInt();
        int data[] = generateData(n);
        int data2[] = data.clone();
        System.out.println("===================== Execution Time ====================");
        double start = System.nanoTime() / 1000000;
        mergeSort(data, 0, data.length-1);
        double end = System.nanoTime() / 1000000;
        double time = end - start;
        double start2 = System.nanoTime() / 1000000;
        quick(data2, 0, data.length-1);
        double end2 = System.nanoTime() / 1000000;
        double time2 = end2 - start2;
        System.out.println("Merge sort: " + time + " milliseconds");
        System.out.println("Quick sort: " + time2 + " milliseconds");
        System.out.println("=========================================================");
    }
    static int partition (int a[], int start, int end) {  
        int pivot = a[end]; // pivot element  
        int i = (start - 1);  
      
        for (int j = start; j <= end - 1; j++)  
        {  
            // If current element is smaller than the pivot  
            if (a[j] < pivot)  
            {  
                i++; // increment index of smaller element  
                int t = a[i];  
                a[i] = a[j];  
                a[j] = t;  
            }  
        }  
        int t = a[i+1];  
        a[i+1] = a[end];  
        a[end] = t;  
        return (i + 1);  
    }  
      
    /* function to implement quick sort */  
    static void quick(int a[], int start, int end) {  
        if (start < end)  
        {  
            int p = partition(a, start, end);  //p is partitioning index  
            quick(a, start, p - 1);  
            quick(a, p + 1, end);  
        }  
    }  
    public static void mergeSort(int data[], int beg, int end) {
        if (beg < end) {
            int mid = (beg+end)/2;
            mergeSort(data, beg, mid);
            mergeSort(data, mid + 1, end);
            merge(data, beg, mid, end);
        }
    }
    static void merge(int a[], int beg, int mid, int end) {    
        int i, j, k;  
        int n1 = mid - beg + 1;    
        int n2 = end - mid;    
        
        /* temporary Arrays */  
        int LeftArray[] = new int[n1];  
        int RightArray[] = new int[n2];  
        
        /* copy data to temp arrays */  
        for (i = 0; i < n1; i++)    
            LeftArray[i] = a[beg + i];    
        for (j = 0; j < n2; j++)    
            RightArray[j] = a[mid + 1 + j];    
        
        i = 0; /* initial index of first sub-array */  
        j = 0; /* initial index of second sub-array */   
        k = beg;  /* initial index of merged sub-array */  
        
        while (i < n1 && j < n2)    
        {    
            if(LeftArray[i] <= RightArray[j])    
            {    
                a[k] = LeftArray[i];    
                i++;    
            }    
            else    
            {    
                a[k] = RightArray[j];    
                j++;    
            }    
            k++;    
        }    
        while (i<n1)    
        {    
            a[k] = LeftArray[i];    
            i++;    
            k++;    
        }    

        while (j<n2)    
        {    
            a[k] = RightArray[j];    
            j++;    
            k++;    
        }    
    }    

/*     public static void mergeSort(int data[]) {
        int n = data.length;
        if (n > 1) {
            int b[] = new int[(int) Math.floor(n/2) - 1];
            int c[] = new int[(int) Math.ceil(n/2) - 1];
            for (int i = 0; i < b.length; ++i) {
                b[i] = data[i];
            }
            for (int i = (int) Math.floor(n/2); i < n-1; ++i) {
                c[i] = data[i];
            }
            mergeSort(b);
            mergeSort(c);
            merge(b, c, data);
        }
    }

    public static void merge(int b[], int c[], int a[]) {
        int i = 0, j = 0, k = 0, p = b.length, q = c.length;
        while(i < p && j < q) {
            if (b[i] <= c[j]) {
                a[k] = b[i];
                i++;
            }
            else {
                a[k] = c[j];
                j++;
            }
            k++;
            if (i == p) {
                for (int index = j; index < q; j++) {

                }
            }
        }
    } */

    public static int[] generateData(int size) {
        int data[] = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = (int) (Math.random() * 100000);
        }
        return data;
    }
}
