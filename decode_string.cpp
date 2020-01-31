//
// Created by Mayank Parasar on 2020-01-26.
//

/*
 * Given a string with a certain rule: k[string] should be expanded to string k times.
 * So for example, 3[abc] should be expanded to abcabcabc. Nested expansions can happen,
 * so 2[a2[b]c] should be expanded to abbcabbc.
 * */

#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <stack>

using namespace std;


string decode_string(string str) {
    int repeat = 1;
    int indx = 0;
    int first_brace=0;
    int last_brace=0;
    stack<char> s;

    for(auto i : str) {
        if((isdigit(i)) && (s.size() == 0)) {
            repeat = isdigit(i) ? (i - '0') : repeat;
        }
        if(i == '[') {
            if(s.size() == 0)
                first_brace = indx;
            s.push('[');
        }
        else if(i == ']') {
            s.pop();
            if(s.size() == 0)
                last_brace = indx;
        }
        indx++;
    }



    // now you have index of first and last brace of the string.
    // extract the string and send it to this function again....
    int start = (first_brace+1);
    int len = last_brace - first_brace - 1;
    string str2;
    if (len > 0) {

        // get the left sub string and right substring if any,
        string left_substring = str.substr(0, (first_brace-1));
        string right_substring = str.substr(last_brace+1);

        string string_2 = decode_string(str.substr(start, len));
        // then do the concatination via for loop for 'repeat' times here
        // reconstruct the string here..
        // string string2;

        for (int ii = 0; ii < repeat; ii++) {
            str2 += string_2;
        }
        str2 = left_substring + str2 + right_substring;
        return (str2);
    }
    else {
        for (int ii = 0; ii < repeat; ii++) {
            str2 += str;
        }
        return (str2);
    }

}

int main() {

    string str = "2[a2[bd]c]";

    cout << decode_string(str);
    // cout << str+2;


    return 0;
}