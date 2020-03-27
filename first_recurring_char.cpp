//
// Created by Mayank Parasar on 2020-03-26.
//
/*
Given a string, return the first recurring letter that appears. 
If there are no recurring letters, return None.

Example:
Input: qwertty
Output: t

Input: qwerty
Output: None
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

char first_recurring_char(string str) {
    vector<char> result;

    for(auto i : str) {
        for(auto k : result) {
            if( k == i) {
                return (k);
            }
        }
        result.push_back(i);
    }
    // if reached here.. then there is no repeating character
    return '\0'; // return null
}

int main() {

    string str = "qwertty";
// 	string str = "qwerty";
    char result_char = first_recurring_char(str);
    if(result_char != '\0')
        cout << result_char;
    else
        cout << "None";


    return 0;
}
