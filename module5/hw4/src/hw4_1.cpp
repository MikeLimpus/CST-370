/*
 * Title: hw4_1.cpp
 * Abstract: Partition an array of integers depending on if they are negative
 * ID: 9753
 * Name: Mike Limpus
 * Date: 04/05/2022
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> partition_v1(vector<int> input, int i, int j);
vector<int> partition_v2(vector<int> input, int i, int j);
void swap(vector<int> foo, int x, int y);

int main(void) {
    int n;
    vector<int> input;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }
    vector<int> v1 = partition_v1(input, 0, n-1);
    vector<int> v2 = partition_v2(input, 0, 0);
    for(int i = 0; i < v1.size(); ++i) {
        cout << v1[i];
        if (i == v1.size() - 1) 
            cout << endl;
        else 
            cout << " ";
    }
    for(int i = 0; i < v2.size(); ++i) {
        cout << v2[i];
        if (i == v2.size() - 1) 
            cout << endl;
        else 
            cout << " ";
    }
    return 0;
}

vector<int> partition_v1(vector<int> input, int i, int j) {
    while(i <= j) {
        if (input[i] >= 0) {
            if(input[j] >= 0) 
                j--;
            else 
                std::swap(input[i], input[j]);
        }
        else {
            i++;
        }
    }
    return input;
}

vector<int> partition_v2(vector<int> input, int i, int j) {
    while (j < input.size() - 1) {
        if (input.at(j) >= 0) {
            j++; 
        }
        else {
            std::swap(input[i], input[j]);
            j++;
            i++;
        }
    }
    return input;
}
void swap(vector<int> foo, int x, int y) {
    int temp = foo.at(y);
    foo[y] = foo.at(x); 
    foo[x] = temp;
}