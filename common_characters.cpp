//
// Created by Mayank Parasar on 2020-05-12.
//
/*
 * Given a list of strings, find the list of characters that appear in all strings.

Here's an example and some starter code:

def common_characters(strs):
  # Fill this in.

print(common_characters(['google', 'facebook', 'youtube']))
# ['e', 'o']*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<char>
common_characters(vector<string> word_list) {
    vector<char> result;
    map<char, int> word_map;

    for(int ii=0; ii < word_list.size(); ii++) {

        // remove all the repeting characters in this word
        map<char, int> word;
        for(auto i : word_list[ii])
            word[i] = 1;
        // now make a string our of this map
        string word_;
        for(auto i : word) {
            word_ += i.first;
        }
        // cout << word_ << endl;

        for(auto k : word_) {
            word_map[k]++;
        }
    }

    // whichever letter has frequency same as
    // word_list.size() put that into the result
    // vector
    for(auto k : word_map){
        if(k.second == word_list.size())
            result.push_back(k.first);
    }

    return result;
}

int main() {
    string str1 = "google";
    string str2 = "facebook";
    string str3 = "youtube";

    vector<string> string_list;

    // push strings into the 'string-list'
    string_list.push_back(str1);
    string_list.push_back(str2);
    string_list.push_back(str3);


    vector<char> result;
    result = common_characters(string_list);

    for(auto i : result)
        cout << i << " ";

    return 0;
}