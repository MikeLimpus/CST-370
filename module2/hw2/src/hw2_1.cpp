/*
 * Title: main_hw2_1.cpp
 * Abstract: Display the difference between two timestamps in HH:MM:SS format
 * ID: 9753
 * Name: Mike Limpus
 * Date: 03/15/2022
 */

#include <iostream>
#include <string>
#define TIMESTAMP_SIZE 8
#define TIMESTAMP_ACCURACY 3
#define SECONDS_IN_HOUR 3600
using namespace std;

int main() {
    int parsed_stamp1[TIMESTAMP_ACCURACY], 
        parsed_stamp2[TIMESTAMP_ACCURACY], 
        result[TIMESTAMP_ACCURACY],
        seconds1,
        seconds2,
        diff_seconds;
    string stamp1, stamp2;
    cin >> stamp1;
    cin >> stamp2;

    // Probably not an issue in these test cases, but some simple input validation
    if (stamp1.length() != TIMESTAMP_SIZE || stamp2.length() != TIMESTAMP_SIZE) {
        cout << "INVALID INPUT" << endl;
        return 0;
    }

    // The timestamps follow a universal format, so parsing is straightforward
    // However, they are parsed "Backwards" to follow the flow of the math
    parsed_stamp1[0] = stoi(stamp1.substr(6,7));
    parsed_stamp2[0] = stoi(stamp2.substr(6,7));
    parsed_stamp1[1] = stoi(stamp1.substr(3,5));
    parsed_stamp2[1] = stoi(stamp2.substr(3,5));
    parsed_stamp1[2] = stoi(stamp1.substr(0,2));
    parsed_stamp2[2] = stoi(stamp2.substr(0,2));

    // Main logic
    seconds1 = parsed_stamp1[0] + (parsed_stamp1[1] * 60) + (parsed_stamp1[2] * SECONDS_IN_HOUR);
    seconds2 = parsed_stamp2[0] + (parsed_stamp2[1] * 60) + (parsed_stamp2[2] * SECONDS_IN_HOUR); 
    // Account for case when the first event happens a day before the second
    if (seconds1 > seconds2) {
        diff_seconds = seconds2 - seconds1;
        diff_seconds += (24 * SECONDS_IN_HOUR);
    }
    else
        diff_seconds = seconds2 - seconds1;

    result[0] = diff_seconds / SECONDS_IN_HOUR;
    diff_seconds -= result[0] * SECONDS_IN_HOUR;

    result[1] = diff_seconds / 60;
    diff_seconds -= result[1] * 60;

    result[2] = diff_seconds;

    // need to use printf here for formatting
    printf("%.2d:%.2d:%.2d\n", result[0], result[1], result[2]);

    return 0;
}

