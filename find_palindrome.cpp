//
// Created by Mayank Parasar on 2020-03-28.
//
/*
Given a string, determine if there is a way to arrange the string such that the string is a palindrome.
If such arrangement exists, return a palindrome (There could be many arrangements). Otherwise return None.

Here's some starter code:

def find_palindrome(s):
  # Fill this in.

print(find_palindrome('momom'))
# momom
*/

#include <iostream>
#include <map>
#include <string>
#include <deque>

using namespace std;

string find_palindrome(string str) {
    map<char, int> mymap;
    for(auto i : str) {
        mymap[i]++;
    }
    // the nap is populated now...
    int counter = 0; // to count the uneven occurance of a character
    for(auto i : mymap) {
        if(i.second % 2 == 1) {
            counter++;
        }
    }

    deque<char> word;
    if(counter >= 2)
        return "None";
    else {
        // make a palindrome string here from the map
        // use a deque for this
        for(auto i : mymap) {
            if(i.second % 2 == 1) {
                word.push_back(i.first);
                mymap[i.first]--;
            }
        }

        for(auto i : mymap) {
            cout << i.first << ": ";
            cout << i.second << endl;
        }

        // now populate rest of the word
        for(auto i : mymap) {
            for(int kk = i.second; kk > 0; kk -= 2) {
                word.push_front(i.first);
                word.push_back(i.first);
            }
        }
    }
    // now here palindrome word is compelete in deque data structure
    // convert it into a string...

    std::string palindrome(word.begin(), word.end());

    return palindrome;
}

int main() {

    std::string str = "mayank";
    std::string str1 = "momom";
    std::string str2 = "geeksogeeks";
    std::string str3 = "mayank";
    std::string str4 = "mayank";

    cout << find_palindrome(str2);

    return 0;
}
