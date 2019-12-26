//
// Created by Mayank Parasar on 2019-12-26.
//

/*
 * Given two strings A and B of lowercase letters, return true
 * if and only if we can swap two letters in A so that the result equals B.

Example 1:
Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:
Input: A = "aa", B = "aa"
Output: true
Example 4:
Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:
Input: A = "", B = "aa"
Output: false
 */

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

string& swap_char(string& str, int indx1, int indx2) {
    char tmp_char;
    tmp_char = str[indx1];
    str[indx1] = str[indx2];
    str[indx2] = tmp_char;
    return (str);
}

bool buddy_string(string& str1, string& str2) {
    if(str1.length() != str2.length())
        return false;
    // string tmp;
    for(int ii=0; ii < str1.size(); ++ii) {
        for (int kk =ii+1; kk < str1.size(); ++kk) {
            // swap character str1[ii] with str1[jj] and
            // compare with string str2,
            if (swap_char(str1, ii, kk) == str2)
                return true;
            else {
                // swap back
                swap_char(str1, kk, ii);
            }
        }
    }

    // bool result = false;


    return (false);
}

int main() {

//    string str1 = "aaaaaaabc";
//    string str2 = "aaaaaaacb";
//    string str1 = "ab";
//    string str2 = "ab";
    string str1 = "aa";
    string str2 = "aa";
    // cout << "length of str1: " << str1.length() << endl;

    cout << (buddy_string(str1, str2) ? "True" : "False");

    return 0;
}