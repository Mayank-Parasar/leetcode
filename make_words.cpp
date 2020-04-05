//
// Created by Mayank Parasar on 2020-04-04.
//

/*
 * Given a phone number, return all valid words that can be created using that phone number.

For instance, given the phone number 364
we can construct the words ['dog', 'fog'].

Here's a starting point:

lettersMaps = {
    1: [],
    2: ['a', 'b', 'c'],
    3: ['d', 'e', 'f'],
    4: ['g', 'h', 'i'],
    5: ['j', 'k', 'l'],
    6: ['m', 'n', 'o'],
    7: ['p', 'q', 'r', 's'],
    8: ['t', 'u', 'v'],
    9: ['w', 'x', 'y', 'z'],
    0: []
}

validWords = ['dog', 'fish', 'cat', 'fog']

def makeWords(phone):
  #Fill this in

print(makeWords('364'))
# ['dog', 'fog']
 * */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<int, vector<char>> lettersMaps;
vector<string> validWords = {"dog", "fish", "cat", "fog"};

vector<int> int_to_vec(int num) {
    vector<int> result;
    while (num > 0) {
        result.push_back(num % 10);
        num = num / 10;
    }
    // reverse the vector
    reverse(result.begin(), result.end());
    return result;
}

vector<string> make_words(int num) {
    // convert the num into a vector;
    vector<int>numbers = int_to_vec(num);


    // create a map of string and bool..
    // bool would mark the words which are still valid...
    map<string, bool> word_map;
    // mark all the words as valid to begin with
    // then progressively make them invalid.
    for(auto word : validWords) {
        word_map[word] = false;
    }

    for(int ii = 0; ii < numbers.size(); ii++) {
        vector<char> availChar = lettersMaps[numbers[ii]];

        for(auto word : word_map) {
            // only check the words which are true..
            bool match = false;
            if(ii == 0 || (word.second == true && ii > 0)) {
                for (auto ch : availChar) {
                    match = false;
                    if (word.first[ii] == ch) {
                        // word.second = true; // this does not set the value of map correctly
                        word_map[word.first] = true;  // always use [] operator to set the value of map
                        match = true;
                        break;
                    }
                }
            }
            if (!match) {
                word.second = false;
            }
        }
        // print map
//        cout << boolalpha;
//        for(auto i : word_map) {
//            cout << i.first << ": ";
//            cout << i.second << " ";
//
//            cout << endl;
//        }
    }

    // now also make any other entry false whose length is
    // not same as number vector
    for(auto word : word_map) {
        if((word.second) &&
            ((int)word.first.length() != (int) numbers.size())) {
            word_map[word.first] = false;
        }
    }
    // extract the result from the map...
    vector<string> result;
    for(auto word : word_map) {
        if(word.second == true)
            result.push_back(word.first);
    }

    return result;
}

int main() {

    // populate the map here...
    lettersMaps[1] = {};
    lettersMaps[2] = {'a', 'b', 'c'};
    lettersMaps[3] = {'d', 'e', 'f'};
    lettersMaps[4] = {'g', 'h', 'i'};
    lettersMaps[5] = {'j', 'k', 'l'};
    lettersMaps[6] = {'m', 'n', 'o'};
    lettersMaps[7] = {'p', 'q', 'r', 's'};
    lettersMaps[8] = {'t', 'u', 'v'};
    lettersMaps[9] = {'w', 'x', 'y', 'z'};
    lettersMaps[0] = {};


    // print map
//    for(auto i : lettersMaps) {
//        cout << i.first << ": ";
//        for(auto k : i.second) {
//            cout << k << " ";
//        }
//        cout << endl;
//    }

    int num = 364;

    vector<string> result = make_words(num);
    cout << "words that can be formed with given number are: " << endl;
    for(auto word : result)
        cout << word << ", ";

    return 0;
}