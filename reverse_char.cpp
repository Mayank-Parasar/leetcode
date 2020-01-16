//
// Created by Mayank Parasar on 2020-01-15.
//

/*
 * Given a string, you need to reverse the order of characters in each word within a sentence while still
 * preserving whitespace and initial word order.
 *

Example 1:
Input: "The cat in the hat"
Output: "ehT tac ni eht tah"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse_char(vector<char> orig) {

    vector<char> word;
    vector<char> sentence; // flush the word into sentence on a space

    for(int ii=0; ii < orig.size(); ii++) {

        if(orig[ii] != ' ') {
            word.push_back(orig[ii]);
        }
        else if(orig[ii] == ' ') {
            // flush the word into sentence
            // and reset the word
            for(int kk = word.size()-1; kk>= 0; kk--) {
                sentence.push_back(word[kk]);
            }
            sentence.push_back(' ');
            word.resize(0);

//            for(auto i : sentence)
//                cout << i;
        }
    }
    // convert the sentence into a sting
    string reverse_sentence(sentence.begin(), sentence.end());

    return reverse_sentence;

}

int main() {

    string str = "The cat in the hat";
    string ans;
    vector<char>v(str.begin(), str.end());

//    for(auto i : v)
//        cout << i << " ";

    ans = reverse_char(v);

    cout << "Original string: " << str;
    cout << endl;


    cout << "Reverse string: " << ans;

    return  0;
}