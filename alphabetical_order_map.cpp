//
// Created by Mayank Parasar on 2020-03-08.
//
/*
Given a non-empty list of words, return the k most frequent words.
 The output should be sorted from highest to lowest frequency, and if two words have the same frequency,
 the word with lower alphabetical order comes first. Input will contain only lower-case letters.

Example:
Input: ["daily", "interview", "pro", "pro",
"for", "daily", "pro", "problems"], k = 2
Output: ["pro", "daily"]
*/

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>


using namespace std;

bool sortByVal(const pair<string, int>& a,
               const pair<string, int> b) {
    return a.second > b.second;
}

int main() {

    map<string, int> mymap;

    vector<string> vec = {"daily", "interview", "pro", "pro",
                          "for", "daily", "pro", "problems"};
    int k = 3;

    for(auto i : vec) {
        mymap[i]++;
    }
//
//    cout << "Populated map is as follows: " << endl;
//    for(auto i : mymap)
//        cout << i.first << "\t" << i.second << endl;

    vector<pair<string, int>> myvec;

    // copy key-value pairs from map to the myvector
    map<string, int>::iterator it;
    for(it=mymap.begin(); it!=mymap.end(); it++)
        myvec.push_back(make_pair(it->first, it->second));

    // Sort the myvector by decreasing order
    sort(myvec.begin(), myvec.end(), sortByVal);

    cout << k <<"-most frequently repeated words are:" << endl;

    for(int i = 0; i < k; i++) {
        cout << myvec[i].first << "  ";
    }

    return 0;
}