/*
 * Title: main_hw1_1.cpp
 * Abstract: Read input numbers and display closest distance between among the 
 *           inputs
 * ID: 9753
 * Name: Mike Limpus
 * Date: 03/08/2022
 */

#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> resultL, resultR;
    // First result should be arbitrarily large for comparison
    int resultD = __INT_MAX__; 
    int n; 
    
    // Handle input
    cin >> n;
    int input[n];
    for (int i = 0; i < (n - 1); ++i) {
        cin >> input[i];
    }

    /*
     * The array needs to be sorted for this algorithm to work. 
     * For simplicity I will use insertion sort (textbook, sec. 4.1)
     */

    for (int i = 1; i < (n - 1); ++i) {
        int temp = input[i];
        int j = i - 1;
        while (j >= 0 && input[j] > temp) {
            input[j + 1] = input[j];
            j--;
        }
        input[j + 1] = temp; 
    }

    // Main logic (Sliding window)
    for (int i = 1; i < (n - 1); ++i) {
        int distance = abs(input[i] - input[i-1]);
        if (distance < resultD) {
            resultL.clear();
            resultR.clear();
            resultL.push_back(input[i-1]);
            resultR.push_back(input[i]);
            resultD = distance;
        }
        else if(distance == resultD) {
            resultL.push_back(input[i-1]);
            resultR.push_back(input[i]);
        }

    }

    int x = resultL.size();
    // Print result
    cout << "Min Distance:" << resultD << endl;
    for (int i = 0; i < x; ++i) {
        cout << "Pair:" << resultL.front() << " " << resultR.front() << endl;
        resultL.pop_front();
        resultR.pop_front();
    }
    

    return 0;
}