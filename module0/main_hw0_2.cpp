/*
 * INSTRUCTION:
 *     This is a C++ staring code for hw0_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw0_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw0_2.cpp
 * Abstract: Read five integers and display the min max and median
 * ID: 9753
 * Name: Mike Limpus
 * Date: 03/01/2022
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int foo[5];

    for (int i = 0; i < 5; ++i) {
        cin >> foo[i];
    }

    sort(foo, foo+5);

    cout << "MIN:" << foo[0] << endl;
    cout << "MAX:" << foo[4] << endl;
    cout << "MEDIAN:" << foo[2] << endl;
    return 0;
}

