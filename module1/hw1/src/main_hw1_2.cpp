/*
 * Title: main_hw1_2.cpp
 * Abstract: Read input numbers and display the most frequently inputted number
 * ID: 9753
 * Name: Mike Limpus    
 * Date: 02/08/2022
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n = 0, frequency = 1, highest = 0; 
    vector<int> results;
    map<int, int> result_map; 
    map<int, int>::iterator itr;
    // you can assume that there will be less than 500 input integer numbers.
    for(int i = 0; i < 500; ++i) {
        result_map.insert(pair<int,int>(i,0));
    }
    // Handle Input
    cin >> n;
    int input[n];
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    for (int i = 0; i < n; ++i) {
        itr = result_map.find(input[i]);
        itr->second++;
        if (itr->second > highest) {
            highest = itr->second;
        }
    }

    for (auto &it : result_map) {
        if(it.second == highest) {
            results.push_back(it.first);
        }
    }

    reverse(results.begin(), results.end());

    // Output 
    cout << "Frequency:" << highest << endl;
    cout << "Number:";
    for (int i = 0; i < results.size() - 1; ++i) {
        cout << results.at(i) << " ";
    }
    cout << results.back() << endl;

    return 0;
}