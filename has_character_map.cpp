//
// Created by Mayank Parasar on 2020-03-21.
//

/*
Given two strings, find if there is a one-to-one mapping of characters between the two strings.

Example
Input: abc, def
Output: True # a -> d, b -> e, c -> f

Input: aab, def
Ouput: False # a can't map to d and e
Here's some starter code:

def has_character_map(str1, str2):
  # Fill this in.

print(has_character_map('abc', 'def'))
# True
print(has_character_map('aac', 'def'))
# False
*/

#include<iostream>
#include<string>
#include<map>

using namespace std;


map<char, char> mymap;

bool has_character_map(string str1, string str2) {

    if(str1.length() != str2.length())
        return false;
    else {
        for(int ii=0, jj = 0; ii<str1.length(), jj<str2.length(); ii++, jj++) {
            cout << str1[ii] << " " << str2[jj] << endl;
            if(mymap.find(str1[ii]) == mymap.end()){
                mymap[str1[ii]] = str2[jj];
            }
            else {
                return false;
            }
        }
    }

    return true;
}

int main() {

    string str1 = "abc";
    string str2 = "def";

    string str3 = "aac";
    string str4 = "def";

    cout << boolalpha;
    cout << has_character_map(str1, str2);
    cout << endl;
    cout << has_character_map(str3, str4);
    cout << endl;

    return 0;
}