/*
 * Title: hw3_1.cpp
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

int main(void) {
    int n; 
    cin >> n; 
    vector<int> input;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }
    // First, sort the input 
    sort(input.begin(), input.end());
    // Workaround to prevent out-of-bounds error
    input.push_back(-1);

    for (int i = 1; i < n; ++i) {
        // Check for valid input
        if (input.at(i) > -1) {
            // Copy the number at the current input, then increment t
            int temp = input.at(i-1);
            temp++;
            /* If the incremented number is equal to the next number, then they 
            are consecutive. If they are, continue the loop while and stop 
            printing until they are NOT consecutive */
            if (input.at(i) == temp) {
                cout << input.at(i-1);
                while(true) {
                    i++;
                    int temp2 = input.at(i-1);
                    temp2++;
                    if (input.at(i) != (temp2)) {
                        cout  << "-" << input.at(i-1) << " ";
                        break;
                    }
                }
            }
            else {
                cout << input.at(i-1) << " ";
            }
        }
    }
    cout << input.at(n-1) << endl;

    return 0;
}