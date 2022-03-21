/*
 * Title: main_hw3_1.cpp
 * Abstract: Sort and display inputted numbers in ascending order, 
 *           and shorten consecutive numbers
 * ID: 9753
 * Name: Mike Limpus
 * Date: 03/22/2022
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void quicksort(int array[], int start, int end);
int partition(int array[], int start, int end);

int main(void) {
    int n; 
    cin >> n; 
    int input[n]; 
    vector<string> output;
    string temp_low, temp_high;

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    // First, sort the input 
    sort(input, input + n);
    for (size_t i = 0; i < n; i++)
    {
       cout << input[i] << " ";
    }
    cout << endl;
    
/*     for (int i = 1; i < n; ++i) {
        if (input[i] == (input[i-1] - 1)) {
            temp_low = to_string(input[i-1]);
            int j = i;
            bool foo = true;
            while(foo == true) {
                j++;
                if (input[j] != (input[j-1] - 1)) {
                    temp_high = to_string(input[j - 1]);
                    foo = false; 
                }
            }
            output[i - 1] = temp_low + "-" + temp_high;
            i = j;
        }
        else {
            output[i - 1] = to_string(input[i - 1]);
        }
    } */

    for (int i = 0; i < n; ++i) {
        int temp = input[i+1]++;
        if (input[i] == (temp)) {
            temp_low = to_string(input[i]);
            while(true) {
                i++;
                if (input[i] != (input[i+1] + 1)) {
                    temp_high = to_string(input[i]);
                    output.push_back(temp_low + "-" + temp_high);
                    break;
                }
            }
        }
        else {
            output.push_back(to_string(input[i]));
        }
    }
    

    cout << temp_low << " " << temp_high << endl;
    for (int i = 0; i < n; ++i) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}

// Quicksort adapted from 
// https://textbooks.cs.ksu.edu/cc310/7-searching-and-sorting/19-quicksort-pseudocode/

// void quicksort(int array[], int start, int end) {
//     if (start >= end) {
//         return;
//     }
//     int pivot_index = partition(array, start, end);
//     quicksort(array, start, pivot_index - 1);
//     quicksort(array, pivot_index + 1, end);
// }

// int partition(int array[], int start, int end) {
//     int pivot_value = array[end];
//     int i = start;
//     int j = start;
//     int pivot_index = start;
//     while(i <= end) {
//         if (array[i] > pivot_value) {
//             i++;
//         }
//         else {
//             int temp = array[i];
//             array[i] = array[pivot_index];
//             array[pivot_index] = temp;
//             i++;
//             j++;
//         }
//     }
//     return j - 1;
// }