//
// Created by Mayank Parasar on 2020-05-13.
//
/*
 * Given a string, we want to remove 2 adjacent characters that are the same,
 * and repeat the process with the new string until we can no longer perform the operation.

Here's an example and some starter code:

def remove_adjacent_dup(s):
  # Fill this in.

print(remove_adjacent_dup("cabba"))
# Start with cabba
# After remove bb: caa
# After remove aa: c
# print c
 */
#include <iostream>
#include <string>

using namespace std;

string remove_adjacent_dup(string& str) {
    // cout << str << endl;
    for(int ii = 0; ii < str.length()-1; ii++) {
        if(str[ii] == str[ii + 1]) {
            str.erase(ii,2);
            // call the function again
            remove_adjacent_dup(str);
        }
    }

    return str;
}

int main() {
    string str = "cabba";
    // string str1 = "Mayaank";
    cout <<  remove_adjacent_dup(str);
    return 0;
}