/*
 * Title: main_hw2_1.cpp
 * Abstract: Return true if input string is palindrone, false otherwise
 * ID: 9753
 * Name: Mike Limpus
 * Date: 03/15/2022
 */

#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string input, int i, int j);

int main() {
    string input; 
    string parsed;
    getline(cin, input); 
    // Remove all non-alphanumeric chars (ascii values)
    for (int i = 0; i < input.length(); ++i) {
        // Check for numbers
        if (input.at(i) >= 48 && input.at(i) <= 57) 
            parsed += input.at(i);
        // Check for Upper case
        else if (input.at(i) >= 65 && input.at(i) <= 90)
            parsed += (input.at(i) + 32); 
        // Check for lower case 
        else if (input.at(i) >= 97 && input.at(i) <= 122) 
            parsed += input.at(i);
    }

    bool is_it = is_palindrome(parsed, 0, parsed.length() - 1);
    if(is_it) 
        cout << "TRUE" << endl;
    else 
        cout << "FALSE" << endl;
}

// Start with an index on either side of string, if they are the same, keep going
// If not, return false
bool is_palindrome(string input, int i, int j) {
    if(i == j)
        return true;
    else if(input.at(i) != input.at(j)) 
        return false;
    else 
        return is_palindrome(input, ++i, --j);
}