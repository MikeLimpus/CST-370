/*
 * Title: main_hw2_1.cpp
 * Abstract: input a set of chars, output all decimal numbers, 
 *           binary numbers, and subsets
 * ID: 9753
 * Name: Mike Limpus
 * Date: 03/15/2022
 */

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string dec_to_bin(int dec, int bin_digits);
string find_subset(string bin, string set[]);
int bin_digits(int n);

int main() {
    int n; 
    cin >> n;
    if (n > 9) {
        cout << "ERROR: Input must be less than 10" << endl;
        return 0;
    }
    string set[n];
    int count_subsets = (int) pow(2, n);
    int bin_dig = bin_digits(count_subsets);

    for(int i = 0; i < n; ++i) {
        cin >> set[i];
    }
    
    for (int i = 0; i < count_subsets; ++i) {
        string bin = dec_to_bin(i, bin_dig);
        string subset = find_subset(bin, set);
        cout << i << ":" << bin << ":" << subset << endl;
    }
}

// create a binary formatted string of less than 5 bits
string dec_to_bin(int dec, int bin_dig) {
    int temp = 0;
    bin_dig--;
    int bin_ints[bin_dig];
    string bin = "";
    if (bin_dig <= 0) {
        return "0";
    }
    if (dec == 0) {
        for (int i = 0; i < bin_dig; ++i) {
            bin.append("0");
        }
        return bin;
    }
    else {
        for(int j = 0; j < bin_dig; ++j) {
            bin_ints[j] = 0;
        }
        int i = 0;
        while(dec > 0) {
            temp = dec % 2;
            bin_ints[i] = temp;
            dec /= 2;
            ++i;
        }

        reverse(bin_ints, bin_ints+bin_dig);

        for (int j = 0; j < bin_dig; ++j) {
            bin.append(to_string(bin_ints[j]));
        }
        return bin;        
    }
}

string find_subset(string bin, string set[]) {
    bool not_zero = false;
    string subset = "";
    for (int i = 0; i < bin.length(); ++i) {
        if(bin.at(i) == '1') {
            subset.append(set[i]);
            subset.append(" ");
            not_zero = true;
        }
    }
    if(subset.length() > 0)
        subset.pop_back(); // Remove the trailing whitespace - lame way
    if(not_zero == false) 
        return "EMPTY";
    return subset;
}

int bin_digits(int n) {
    int count = 1;
    while(n > 1) {
        count++; 
        n = (int) floor(n/2);
    }
    return count;
}