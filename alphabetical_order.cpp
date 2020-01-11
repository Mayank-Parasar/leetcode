//
// Created by Mayank Parasar on 2020-01-11.
//

/*
 * Given a list of words, and an arbitrary alphabetical order,
 * verify that the words are in order of the alphabetical order.
 *

Example:
Input:
words = ["abcd", "efgh"], order="zyxwvutsrqponmlkjihgfedcba"

Output: False
Explanation: 'e' comes before 'a' so 'efgh' should come before 'abcd'

Example 2:
Input:
words = ["zyx", "zyxw", "zyxwy"],
order="zyxwvutsrqponmlkjihgfedcba"

Output: True
Explanation: The words are in increasing alphabetical order
*/

#include <iostream>
#include <string>
#include <vector>
#include<assert.h>

using namespace std;

int find_index(const char chr, const string order) {
    int index = 0;
    for(auto i : order) {
        if(chr == i)
            return index;
        index++;
    }
    assert(0);

    return index; // this is to keep compiler happy to avoid [-Wreturn-type] error code.
}

bool is_sorted(const string word1, const string word2, const string order) {
    bool result = true;

    if(word2.length() < word1.length())
        return false;
    int ii = 0; //index for word1
    while(ii < word1.length()) {

        if(find_index(word1[ii], order) > find_index(word2[ii], order))
            return false;

        ii++;
    }

    return result;
}

bool is_alphabetical_order(vector<string>& word_list, const string& order) {

    // start with 1,2 then compare 2, 3
    // transitive property will hold here.. that is if word[1], word[2] is sorted and word[2], word[3] is sorted
    // then word[1], word[3] are also sorted.
    bool result = true;
    for(int ii = 0; ii < word_list.size() - 1; ii++) {
        if(is_sorted(word_list[ii], word_list[ii+1], order) == false)
            return false;
    }

    return result;
}

int main() {

    vector<string> word_list1 = {"abcd", "efgh"};
    vector<string> word_list2 = {"zyx", "zyxw", "zyxwy"};
    string order = "zyxwvutsrqponmlkjihgfedcba";

    cout << boolalpha;
    cout << is_alphabetical_order(word_list1, order);
    cout << endl;
    cout << is_alphabetical_order(word_list2, order);


    return 0;
}