//
// Created by Mayank Parasar on 2020-01-31.
//

/*
 * Two words can be 'chained' if the last character of the first word is the same as
 * the first character of the second word.

Given a list of words, determine if there is a way to 'chain' all the words in a circle.

Example:
Input: ['eggs', 'karat', 'apple', 'snack', 'tuna']
Output: True*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//struct node {
//    string str;
//    bool visited;
//
//    node* next;
//
//    node(string str_) : str(str_), visited(false)
//    {}
//};


void check_chained(vector<string>& array, vector<bool>& visited, int idx) { // this function will populate this vector

    string word  = array[idx];
    char c = word[word.length()-1];
    // scan the whole vector to find the word whoes first letter is 'c'
    int ii;
    for(ii=0; ii < array.size(); ii++) {
        if(array[ii][0] == c) {
            if(visited[ii] == false) {
                visited[ii] = true;
            }
            else {
                return;
            }

            break;
        }
    }

    if(ii < array.size()) {
        check_chained(array, visited, ii);
        return;
    }
    return;
}

int main() {

    vector<string> array = {"eggs", "karat", "apple", "snack", "tuna"};
    vector<bool> visited(array.size(), false);

    check_chained(array, visited, 0);  // starting with first element
    int ii;
    for(ii = 0; ii < visited.size(); ii++) {
        if(visited[ii])
            continue;
        else
            break;
    }

    if(ii == visited.size())
        cout << "word list is chained";
    else
        cout << "word list is not chained";

    return 0;
}