/*
 * INSTRUCTION:
 *     This is a C++ staring code for hw0_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw0_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw0_1.cpp
 * Abstract: Print the sum and difference between two integers
 * ID: 9753
 * Name: Mike Limpus
 * Date: 03/01/2022
 */

#include <iostream>
using namespace std;

int main()
{
    int foo, bar;
    cin >> foo;
    cin >> bar;
    cout << "SUM:" << (foo + bar) << endl;
    cout << "DIFF:" << abs((foo - bar)) << endl;

    return 0;
}

