//
// Created by Mayank Parasar on 2020-03-08.
//
/*
Given a non-empty list of words, return the k most frequent words. The output should be sorted from highest to lowest frequency, and if two words have the same frequency, the word with lower alphabetical order comes first. Input will contain only lower-case letters.

Example:
Input: ["daily", "interview", "pro", "pro",
"for", "daily", "pro", "problems"], k = 2
Output: ["pro", "daily"]
*/

#include<iostream>
#include<vector>
#include<string>
#include<map>


using namespace std;

struct compare {
    bool operator()(const string a, const string b) {
        return a < b;
    }
}

int main() {

    map<string, int, compare> mymap;

    mymap["hello"]++;
    mymap["mayank"]++;
    mymap["apple"]++;

    for(auto i : mymap)
        cout << i.first << "\t" << i.second << endl;

    return 0;
}