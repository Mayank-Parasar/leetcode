//
// Created by Mayank Parasar on 2020-03-24.
//

/*
Given a list of words, for each word find the shortest unique prefix.
You can assume a word will not be a substring of another word (ie play
and playing won't be in the same words list)

Example
Input: ['joma', 'john', 'jack', 'techlead']
Output: ['jom', 'joh', 'ja', 't']
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool find_substring(string substr, string str) {
    for(int ii = 0; ii < substr.length(); ii++) {
        if(substr[ii] == str[ii]) {
            continue;
        }
        else{
            return false;
        }
    }

    return true;
}


vector<string> unique_prefix(vector<string> vec) {

    vector<string> result;
    for(vector<string>::iterator it = vec.begin();
        it != vec.end(); it++) {
        string tmp;
        int k = 1;
        for(vector<string>::iterator itr = vec.begin();
            itr != vec.end(); itr++) {
            // repeat for all the entities in the vector except current one.
            /*******************/
            if(itr == it)
                continue;

            redo:
            tmp = it->substr(0,k);
            if(find_substring(tmp, *itr)) {
                k++;
                goto redo;
            }
            /*******************/
        }
        result.push_back(tmp);
    }

    return result;
}

int main () {

    vector<string> vec1 = { "joma", "john", "jack", "techlead" };
    // vector<string> vec2 = { "jom", "joh", "ja", "t" };
    vector<string>result = unique_prefix(vec1);

    // cout << endl;
    for(auto i : result)
        cout << i << " ";

    return 0;
}