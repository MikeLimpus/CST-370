/*
 * Title: hw4_2.cpp
 * Abstract: Using a divide-and-conquer technique, find the largest value in an 
 *           integer
 * ID: 9753
 * Name: Mike Limpus
 * Date: 04/05/2022
 */
#include <iostream>
using namespace std;

int find_max(int arr[], int i, int j);
int greatest(int x, int y);

int main(void) {
    int n; 
    cin >> n; 
    int input[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int maximum = find_max(input, 0, n-1);
    cout << maximum << endl;
    return 0;
}

int find_max(int arr[], int i, int j) {
    if (i == j) {
        return arr[i];
    }
    else {
        int x = find_max(arr, i, (i+j)/2);
        int y = find_max(arr, (i+j)/2+1, j);
        return greatest(x,y);
    }
}

// helper function to find the greater of two ints
int greatest(int x, int y) {
    if (x > y)
        return x;
    else if (x < y)
        return y; 
    else 
        return x;
}